#include "pch.h"
#include "multi.h"
const char* mdlformatstrings[] = {
	"basic",
	"chunk"
};

std::string mdlformatfiletypes[] = {
	".sa1mdl",
	".sa2mdl"
};



NJS_POINT3 LerpPoints(NJS_POINT3* v1, NJS_POINT3* v2, float dist)
{
	NJS_VECTOR result;
	result.x = (v2->x - v1->x) * dist + v1->x;
	result.y = (v2->y - v1->y) * dist + v1->y;
	result.z = (v2->z - v1->z) * dist + v1->z;
	return result;
}

float GetDistance(NJS_POINT3* v1, NJS_POINT3* v2)
{
	return sqrtf((v1->x - v2->x) * (v1->x - v2->x) + (v1->y - v2->y) * (v1->y - v2->y) + (v1->z - v2->z) * (v1->z - v2->z));
}

// True if equal, false if not
bool ComparePoints(NJS_POINT3* v1, NJS_POINT3* v2)
{
	return v1->x == v2->x && v1->y == v2->y && v1->z == v2->z;
}

bool CheckCollisionPointSphere(NJS_POINT3* center, NJS_POINT3* pos, float radius)
{
	return GetDistance(center, pos) <= radius;
}

bool CheckCollisionP_num(NJS_POINT3* center, float radius, int player)
{
	return playertwp[player] ? CheckCollisionPointSphere(center, &playertwp[player]->pos, radius) : false;
}



void ForEveryCollidingPlayer(task* tp, void(__cdecl* function)(task*, taskwk*))
{
	auto cwp = tp->twp->cwp;

	for (int i = 0; i < 16; ++i)
	{
		auto hit = &cwp->hit_info[i];

		if (hit->hit_num == -1) break;

		if (hit->hit_twp->cwp->id == 0)
		{
			function(tp, hit->hit_twp);
		}
	}
}

void ForcePlayerPos(int id, float x, float y, float z)
{
	playertwp[id]->pos = { x, y, z };
}

void ForcePlayerPos(int id, NJS_POINT3* pos)
{
	ForcePlayerPos(id, pos->x, pos->y, pos->z);
}


int GetUVCount(NJS_MESHSET_SADX* meshset)
{
	switch (meshset->type_matId)
	{
	case NJD_MESHSET_3:
		return meshset->nbMesh * 3;
	case NJD_MESHSET_4:
		return meshset->nbMesh * 4;
	case NJD_MESHSET_N:
	case NJD_MESHSET_TRIMESH:
		int indices = 0;
		int currentindex = 0;
		int currentmesh = 0;

		while (currentmesh < meshset->nbMesh) {
			int numvrt = meshset->meshes[currentindex] & 0x7FFF;
			indices += numvrt;
			currentindex += numvrt + 1;
			currentmesh++;
		}

		return indices;
	}

	return 0;
}

int IsPlayerOnGeoCol(task* tp, int pnum)
{
	auto pwp = playerpwp[pnum];
	return pwp && pwp->ttp == tp;
}

// Move collision and players that are on it using forcewk
void MoveGeoCollision(task* tp, NJS_OBJECT* object, NJS_POINT3* pos)
{
	NJS_POINT3 diff = *(NJS_POINT3*)&object->pos;

	object->pos[0] = pos->x;
	object->pos[1] = pos->y;
	object->pos[2] = pos->z;

	forcewk* fwp = tp->fwp;
	if (fwp)
	{
		diff.x = pos->x - diff.x;
		diff.y = pos->y - diff.y;
		diff.z = pos->z - diff.z;

		for (int i = 0; i < (IsMultiplayerActive() ? 4 : 2); ++i)
		{
			fwp[i].pos_spd = diff;
		}
	}
}

void RotYGeoCollision(task* tp, NJS_OBJECT* object, Angle y)
{
	Angle diff = object->ang[1];

	object->ang[1] = y;

	forcewk* fwp = tp->fwp;
	if (fwp)
	{
		diff = SubAngle(diff, y);

		for (int i = 0; i < (IsMultiplayerActive() ? 4 : 2); ++i)
		{
			fwp[i].ang_spd.y = diff;
		}
	}
}

void StopGeoCollision(task* tp)
{
	forcewk* fwp = tp->fwp;
	if (fwp)
	{
		int count = IsMultiplayerActive() ? 4 : 2;
		memset(fwp, 0, sizeof(forcewk) * count);
	}
}

void SetLevelTexture()
{
	njSetTexture(CurrentLandTable->TexList);
}

void SetSecondObjectTexture()
{
	njSetTexture(LevelObjTexlists[1]);
}