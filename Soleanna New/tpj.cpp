#include "sadx-utils.h"
#include "pch.h"
#include "SADXModLoader.h"
#include "Header.h"
#include <vector>
#include "paths.h"
#include "daeth.h"

std::vector<NJS_MATERIAL*> tpj_watermats;
#define tpj_waterfirst (80)
#define tpj_waterlast (90)
int tpj_watercur = tpj_waterfirst;
#define tpj_waterdelay (2)
int tpj_waterframe = 0;


static int MusicIDs_Tropical1 = MusicIDs_redmntn1;
static int MusicIDs_Tropical2 = MusicIDs_redmntn2;

MusicInfo Music_Tropical1 = { "tropical1", true };
MusicInfo Music_Tropical2 = { "tropical2", true };


NJS_TEXNAME Tropical_TexNames[8];
NJS_TEXLIST Tropical_TexList = { arrayptrandlength(Tropical_TexNames) };

LandTableInfo* TropicalLands[3] = { nullptr };
void LoadObjectFiles()
{
	LoadSetFile(0, "TPJ00");
	LoadSetFile(1, "TPJ01");
	LoadSetFile(2, "TPJ02");
	LoadSetFile(3, "TPJ03"); // custom act

	LoadCamFile(0, "HT00");
	LoadCamFile(1, "HT01");
	LoadCamFile(2, "HT02");
	LoadCamFile(3, "HT03"); // custom act
}
StartPosition StartPoses[] = {
	{ LevelIDs_RedMountain, 0, { -96.0f, 162.0f, 2348.0f }, 0x8000 }, // Sonic Act 1
	{ LevelIDs_RedMountain, 1, { -1018.0f, -50.0f, -1235.0f }, 0 }, // Sonic Act 2
	{ LevelIDs_RedMountain, 1, { 15.0f, 700.0f, 225.0f }, 0 }, // Gamma Act 2
	{ LevelIDs_RedMountain, 2, { 895.0f, 295.0f, 515.0f }, 0 },  // Knuckles Act 3
	{ LevelIDs_RedMountain, 3, { 0.0f, -20.0f, 0.0f }, 0 }  // Sonic Act 4 (boss)
};

___stcFog TropicalFogData[] = {
	{ 167.0f, 6000.0f, 0x80FFFFFF, 1 },
	{ 167.0f, 6000.0f, 0x80FFFFFF, 1 },
	{ 167.0f, 6000.0f, 0x80FFFFFF, 1 },
	{ 167.0f, 6000.0f, 0x80FFFFFF, 1 }
};

___stcClip TropicalSkyDrawDist[] = {
	{ -1.0f, -9500.0f },
	{ -1.0f, -5000.0f },
	{ -1.0f, -2000.0f }
};

___stcClip TropicalDrawDists[] = {
	{ -1.0f, -2500.0f },
	{ -1.0f, -1600.0f },
	{ -1.0f, -1000.0f }
};

static const NJS_POINT3 ACT0TRIGGER_POS = { -1297.62073f, 299.966679f, -1127.5488f };
static const NJS_POINT3 ACT1TRIGGER_POS = { 450.62073f, -21.966679f, -2481.5488f };
static const NJS_POINT3 ACT1END_POS = { -480.0f, 935.0f, 3030.0f };

void Tropical_SetViewData()
{
	gClipSky = TropicalSkyDrawDist[ClipLevel];
	gClipMap = TropicalDrawDists[ClipLevel];
	gFog = TropicalFogData[ssActNumber];
}

#pragma region Level Handler
void LoadCurrentActMusic()
{
	auto musictp = CreateElementalTask(IM_TWK, LEV_1, mt_gdcontrol);
	musictp->twp->mode = ssActNumber == 1 ? MusicIDs_Tropical2 : MusicIDs_Tropical1; // music id
	musictp->twp->wtimer = 3; // wait time
}

void __cdecl TropicalZoneExec(task* tp)
{
	if (ssActNumber == 0)
	{
		// Act 1-2 swap
		if (CheckCollisionP((NJS_POINT3*)&ACT0TRIGGER_POS, 100.0f))
		{
			ADX_Close();
			LandChangeStage(1);
			AddSetStage(1);
			AddCameraStage(1);
			AdvanceAct(1);
			for (auto& ptwp : playertwp)
			{
				if (ptwp)
				{
					SetPlayerInitialPosition(ptwp);
					SetInputP(TASKWK_PLAYERID(ptwp), PL_OP_LETITGO);
				}
			}
			Tropical_SetViewData();
			LoadCurrentActMusic();
		}
	}
}


void __cdecl TropicalZone_Init(task* tp)
{
	Tropical_SetViewData(); // Set fog, view distance, etc.


	// If current act is Eggman boss, load that instead
	{
		// This initializes the music once events are done
		LoadCurrentActMusic();

		// Main level function ran every frame, used mostly for act swaps.
		tp->exec = TropicalZoneExec;
	}
}
#pragma endregion

// Fix RM skybox draw order
void SetScrollTask_r()
{
	___njSetBackColor(BackColorList[ssStageNumber].c1, BackColorList[ssStageNumber].c2, BackColorList[ssStageNumber].c3);

	if (ScrollMasterList[ssStageNumber])
	{
		if (ssStageNumber == LevelIDs_RedMountain)
		{
			CreateElementalTask(IM_TWK, LEV_2, ScrollMasterList[ssStageNumber]); // Put this in object index 2 to fix transparency issues
		}
		else
		{
			CreateElementalTask(IM_TWK, LEV_1, ScrollMasterList[ssStageNumber]);
		}
	}
}

// Replace landtables
void LoadTropicalLandTables()
{
	LoadLandTableFile(&TropicalLands[0], "system\\Tropicalzone0.sa1lvl", &Tropical_TexList);
	LoadLandTableFile(&TropicalLands[1], "system\\Tropicalzone1.sa1lvl", &Tropical_TexList);
	LoadLandTableFile(&TropicalLands[2], "system\\Tropicalzone3.sa1lvl", &Tropical_TexList);

	objLandTable[STAGE_MOUNTAIN][0] = (_OBJ_LANDTABLE*)TropicalLands[0]->getlandtable();
	objLandTable[STAGE_MOUNTAIN][1] = (_OBJ_LANDTABLE*)TropicalLands[1]->getlandtable();
	objLandTable[STAGE_MOUNTAIN][2] = (_OBJ_LANDTABLE*)TropicalLands[0]->getlandtable();
	objLandTable[STAGE_MOUNTAIN][3] = (_OBJ_LANDTABLE*)TropicalLands[2]->getlandtable();
}

void FreeTropicalLandTables()
{
	FreeFileInfo(&TropicalLands[0]);
	FreeFileInfo(&TropicalLands[1]);
	FreeFileInfo(&TropicalLands[2]);
}

void __cdecl UnloadTropicalFiles()
{
	FreeTropicalLandTables();
	tpj_watermats.clear();
}

void __cdecl LoadTropicalFiles()
{

	PrintDebug("[Hill Top] Loading level files...\n");
	LoadTropicalLandTables();
	LoadObjectFiles();
	LandTable* land = TropicalLands[0]->getlandtable();

	for (int i = 0; i < land->COLCount; ++i)
	{
		NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
		if (mdl && mdl->mats)
			for (int j = 0; j < mdl->nbMat; ++j)
				if (mdl->mats[j].attr_texId == tpj_waterfirst)
					tpj_watermats.push_back(&mdl->mats[j]);
	}

	

	___epilogfunc = UnloadTropicalFiles;
}



__declspec(naked) void HookLoadLevelFilesRM()
{
	__asm
	{
		call LoadTropicalFiles
		push 004237B3h
		ret
	}
}

void __cdecl ReleaseModule_r(int mode)
{
	if (mode != 5 && ___epilogfunc != LevelDestructor_MissionMode)
	{
		if (mode == 0)
		{
			ReleaseSetFile();
			ReleaseCamFile();
		}

		if (___epilogfunc)
		{
			___epilogfunc();
			___epilogfunc = nullptr;
		}
	}
}

void Level_Init(const HelperFunctions& helperFunctions)
{
	// Replace the Red Mountain switch case from LoadLevelFiles to use our own set/cam/level files
	// This effectively removes what Dreamcast Conversion does in it
	WriteJump((void*)0x422D0A, HookLoadLevelFilesRM);

	// Fix an obvious error in ReleaseModule (OR instead of AND)
	// Vanilla levels don't use the level destructor in SADX PC since it doesn't load levels externally so it doesn't crash.
	WriteJump(ReleaseModule, ReleaseModule_r);

	// Paths
	helperFunctions.RegisterPathList(Tropical0_pathdata);
	helperFunctions.RegisterPathList(Tropical1_pathdata);
	helperFunctions.RegisterPathList(Tropical2_pathdata);

	// Start 
	// 
	// 
	// itions
	helperFunctions.RegisterStartPosition(Characters_Sonic, StartPoses[0]);
	helperFunctions.RegisterStartPosition(Characters_Sonic, StartPoses[1]);
	helperFunctions.RegisterStartPosition(Characters_Gamma, StartPoses[2]);
	helperFunctions.RegisterStartPosition(Characters_Knuckles, StartPoses[3]);
	helperFunctions.RegisterStartPosition(Characters_Sonic, StartPoses[4]);

	// Level Handler
	RoundMasterList[LevelIDs_RedMountain] = TropicalZone_Init;

	// Deathzones
	KillingCollisionModelsListList[LevelIDs_RedMountain][0] = Tropicale0_deathzones;
	KillingCollisionModelsListList[LevelIDs_RedMountain][1] = Tropicale1_deathzones;
	KillingCollisionModelsListList[LevelIDs_RedMountain][2] = Tropicale2_deathzones;
	KillingCollisionModelsListList[LevelIDs_RedMountain][3] = Tropicale0_deathzones;


	// Music
	if (helperFunctions.Version >= 9)
	{
		MusicIDs_Tropical1 = helperFunctions.RegisterMusicFile(Music_Tropical1);
		MusicIDs_Tropical2 = helperFunctions.RegisterMusicFile(Music_Tropical2);
	}
	else
	{
		MusicList[MusicIDs_redmntn1] = Music_Tropical1;
		MusicList[MusicIDs_redmntn2] = Music_Tropical2;
	}

	// Sky color
	BackColorList[LevelIDs_RedMountain] = { 0xFF1844FF, 0xFF2149FF, 0xFF002EFF };


	// Fix skybox transparency
	WriteJump(SetScrollTask, SetScrollTask_r);
}
