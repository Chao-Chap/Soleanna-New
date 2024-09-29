#include "pch.h"
#include "SADXModLoader.h"
#include "Header.h"
#include <vector>

// water
std::vector<NJS_MATERIAL*> castletown_watermats;
#define castletown_waterfirst (295)
#define castletown_waterlast (305)
int castletown_watercur = castletown_waterfirst;
#define castletown_waterdelay (2)
int castletown_waterframe = 0;
#include <vector>
std::vector<NJS_MATERIAL*> waveocean_watermats;
#define waveocean_waterfirst (149)
#define waveocean_waterlast (159)
int waveocean_watercur = waveocean_waterfirst;
#define waveocean_waterdelay (2)
int waveocean_waterframe = 0;

std::vector<NJS_MATERIAL*> newcity_watermats;
#define newcity_waterfirst (625)
#define newcity_waterlast (635)
int newcity_watercur = newcity_waterfirst;
#define newcity_waterdelay (2)
int newcity_waterframe = 0;

std::vector<NJS_MATERIAL*> ruin_watermats;
#define ruin_waterfirst (84)
#define ruin_waterlast (94)
int ruin_watercur = ruin_waterfirst;
#define ruin_waterdelay (2)
int ruin_waterframe = 0;

std::vector<NJS_MATERIAL*> aqua_watermats;
#define aqua_waterfirst (218)
#define aqua_waterlast (228)
int aqua_watercur = aqua_waterfirst;
#define aqua_waterdelay (2)
int aqua_waterframe = 0;

std::vector<NJS_MATERIAL*> dusty1_watermats;
#define dusty1_waterfirst (170)
#define dusty1_waterlast (180)
int dusty1_watercur = dusty1_waterfirst;
#define dusty1_waterdelay (2)
int dusty1_waterframe = 0;

std::vector<NJS_MATERIAL*> dusty2_watermats;
#define dusty2_waterfirst (513)
#define dusty2_waterlast (523)
int dusty2_watercur = dusty2_waterfirst;
#define dusty2_waterdelay (2)
int dusty2_waterframe = 0;

std::vector<NJS_MATERIAL*> kdv_watermats;
#define kdv_waterfirst (137)
#define kdv_waterlast (147)
int kdv_watercur = kdv_waterfirst;
#define kdv_waterdelay (2)
int kdv_waterframe = 0;

NJS_VECTOR IceCap1Trans = { 12610, -8905, -358 };


ObjectMaster* snowboard;

ObjectMaster* LoadSnowboardObject(LoadObj flags, char index, ObjectFuncPtr loadSub)
{
	return snowboard = LoadObject(flags, index, loadSub);
}



// or #include "stdafx.h" for previous Visual Studio versions

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		WriteData((float**)0x4E927E, &IceCap1Trans.x);
		WriteData((float**)0x4E9275, &IceCap1Trans.y);
		WriteData((float**)0x4E9262, &IceCap1Trans.z);
		WriteData((char*)0x719292, (char)3);
		WriteData((char*)0x71928B, (char)3);
		WriteData(reinterpret_cast<LoopHead***>(0x91A864), static_cast<LoopHead**>(untitled2_list));
		WriteData(reinterpret_cast<LoopHead***>(0x91A874), static_cast<LoopHead**>(dtdspline_list));
		WriteData(reinterpret_cast<LoopHead***>(0x91A884), static_cast<LoopHead**>(trainspline_list));
		WriteData(reinterpret_cast<LoopHead***>(0x91A8AC), static_cast<LoopHead**>(splinekdv_list));
		ECoast1_Actchg = { 4265.338, 55, 6954.677 };
		
	
		
		*(float*)0x7E9624 = -10000;


		WriteCall((void*)0x4E9423, LoadSnowboardObject);
		WriteCall((void*)0x4E967E, LoadSnowboardObject);
		WriteCall((void*)0x4E9698, LoadSnowboardObject);
		WriteCall((void*)0x597B34, LoadSnowboardObject);
		WriteCall((void*)0x597B46, LoadSnowboardObject);

	// more water
		HMODULE hmod = GetModuleHandle(L"ADV00MODELS");
		LandTable** landarr = (LandTable**)GetProcAddress(hmod, "___LANDTABLESS");
		LandTable* land = landarr[3];

		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == castletown_waterfirst)
						castletown_watermats.push_back(&mdl->mats[j]);

		}
		land = GeoLists[LevelIDs_EmeraldCoast * 8 + 0];
		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == waveocean_waterfirst)
						waveocean_watermats.push_back(&mdl->mats[j]);
		}

		hmod = GetModuleHandle(L"ADV01MODELS");
		landarr = (LandTable**)GetProcAddress(hmod, "___LANDTABLEEC");
		land = landarr[0];

		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == newcity_waterfirst)
						newcity_watermats.push_back(&mdl->mats[j]);

		}
		land = GeoLists[LevelIDs_FinalEgg * 8 + 1];
		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == aqua_waterfirst)
						aqua_watermats.push_back(&mdl->mats[j]);
		}

		land = GeoLists[LevelIDs_WindyValley * 8 + 0];
		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == dusty1_waterfirst)
						dusty1_watermats.push_back(&mdl->mats[j]);
		}
		land = GeoLists[LevelIDs_WindyValley * 8 + 2];
		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == dusty2_waterfirst)
						dusty2_watermats.push_back(&mdl->mats[j]);
		}
		land = GeoLists[LevelIDs_SkyDeck * 8 + 2];
		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == kdv_waterfirst)
						kdv_watermats.push_back(&mdl->mats[j]);
		}
		

		hmod = GetModuleHandle(L"ADV02MODELS");
		landarr = (LandTable**)GetProcAddress(hmod, "___LANDTABLEMR");
		land = landarr[0];

		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == ruin_waterfirst)
						ruin_watermats.push_back(&mdl->mats[j]);


		}
	}
	__declspec(dllexport) void __cdecl OnFrame()
	{

		WriteJump((void*)0x62EC19, (void*)0x62EC5A);

		{


			if (GameMode == GameModes_Menu || CurrentLevel == LevelIDs_SkyChase1 || CurrentLevel == LevelIDs_SkyChase2 || !GetCharacterObject(0))
				return;
			ObjectMaster* obj = GetCharacterObject(0);
			if (ControllerPointers[0]->PressedButtons & Buttons_Z)
				if (CurrentStageAndAct == LevelAndActIDs_IceCap1)
					switch (obj->Data1->CharID)
					{
					case Characters_Sonic:
						if (obj->Data1->Action >= 62 && obj->Data1->Action <= 68)
							ForcePlayerAction(0, 24);
						else
						{
							ForcePlayerAction(0, 44);
							if (!snowboard)
								snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Sonic_Load);
						}
						break;
					case Characters_Tails:
						if (obj->Data1->Action >= 48 && obj->Data1->Action <= 54)
						{
							ForcePlayerAction(0, 24);
							// fix a bug where Tails' physics data doesn't get reset to normal
							((EntityData2*)obj->Data2)->CharacterData->PhysicsData.CollisionSize = PhysicsArray[Characters_Tails].CollisionSize;
							((EntityData2*)obj->Data2)->CharacterData->PhysicsData.YOff = PhysicsArray[Characters_Tails].YOff;
							((EntityData2*)obj->Data2)->CharacterData->PhysicsData.JumpSpeed = PhysicsArray[Characters_Tails].JumpSpeed;
						}
						else
						{
							ForcePlayerAction(0, 44);
							if (!snowboard)
								snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Tails_Load);
						}
						break;
					}
				else if (!snowboard)
					switch (obj->Data1->CharID)
					{
					case Characters_Sonic:
						if (obj->Data1->Action >= 62 && obj->Data1->Action <= 68)
							snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Sonic_Load);
						break;
					case Characters_Tails:
						if (obj->Data1->Action >= 48 && obj->Data1->Action <= 54)
							snowboard = LoadObject((LoadObj)(LoadObj_Data1 | LoadObj_Data2), 2, Snowboard_Tails_Load);
						break;
					}
		}

		// even more water
		if (castletown_waterframe == castletown_waterdelay)
		{
			castletown_waterframe = 0;
			if (castletown_watercur == castletown_waterlast)
				castletown_watercur = castletown_waterfirst;
			else
				++castletown_watercur;
			for (auto mat : castletown_watermats)
				mat->attr_texId = castletown_watercur;
		}
		else
			++castletown_waterframe;

		if (waveocean_waterframe == waveocean_waterdelay)
		{
			waveocean_waterframe = 0;
			if (waveocean_watercur == waveocean_waterlast)
				waveocean_watercur = waveocean_waterfirst;
			else
				++waveocean_watercur;
			for (auto mat : waveocean_watermats)
				mat->attr_texId = waveocean_watercur;
		}
		else
			++waveocean_waterframe;


		if (newcity_waterframe == newcity_waterdelay)
		{
			newcity_waterframe = 0;
			if (newcity_watercur == newcity_waterlast)
				newcity_watercur = newcity_waterfirst;
			else
				++newcity_watercur;
			for (auto mat : newcity_watermats)
				mat->attr_texId = newcity_watercur;
		}
		else
			++newcity_waterframe;

		if (ruin_waterframe == ruin_waterdelay)
		{
			ruin_waterframe = 0;
			if (ruin_watercur == ruin_waterlast)
				ruin_watercur = ruin_waterfirst;
			else
				++ruin_watercur;
			for (auto mat : ruin_watermats)
				mat->attr_texId = ruin_watercur;
		}
		else
			++ruin_waterframe;


		if (aqua_waterframe == aqua_waterdelay)
		{
			aqua_waterframe = 0;
			if (aqua_watercur == aqua_waterlast)
				aqua_watercur = aqua_waterfirst;
			else
				++aqua_watercur;
			for (auto mat : aqua_watermats)
				mat->attr_texId = aqua_watercur;
		}
		else


			++aqua_waterframe;
		if (dusty1_waterframe == dusty1_waterdelay)
		{
			dusty1_waterframe = 0;
			if (dusty1_watercur == dusty1_waterlast)
				dusty1_watercur = dusty1_waterfirst;
			else
				++dusty1_watercur;
			for (auto mat : dusty1_watermats)
				mat->attr_texId = dusty1_watercur;
		}
		else
			++dusty1_waterframe;


		if (dusty2_waterframe == dusty1_waterdelay)
		{
			dusty2_waterframe = 0;
			if (dusty2_watercur == dusty2_waterlast)
				dusty2_watercur = dusty2_waterfirst;
			else
				++dusty2_watercur;
			for (auto mat : dusty2_watermats)
				mat->attr_texId = dusty2_watercur;
		}
		else
			++dusty2_waterframe;


					if (kdv_waterframe == kdv_waterdelay)
					{
						kdv_waterframe = 0;
						if (kdv_watercur == kdv_waterlast)
							kdv_watercur = kdv_waterfirst;
						else
							++kdv_watercur;
						for (auto mat : kdv_watermats)
							mat->attr_texId = kdv_watercur;
					}
					else
						++kdv_waterframe;
			}
		

	
	
	
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

}
//450.62073, -21.966679, -2481.5488