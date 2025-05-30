#include "pch.h"
#include "ModelInfo.h"
#include "paths.h"
#include "daeth.h"
#include "memaccess.h"
#include "SADXEnums.h"
//	Custom FogData, DrawDistance and SkyboxDrawDistance values:

___stcFog FOGDATA_CastleTown[] = {
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 }
};

___stcClip DRAWDISTANCE_CastleTown[] = {
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f }
};

___stcClip SKYBOXDRAWDISTANCE_CastleTown[] = {
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f }
};

void SETVIEWDATA_CastleTown()
{
	gFog = FOGDATA_CastleTown[ssActNumber];
	gClipMap = DRAWDISTANCE_CastleTown[ClipLevel];
	gClipSky = SKYBOXDRAWDISTANCE_CastleTown[ClipLevel];
}


//	Load Landtable:

LandTableInfo* LAND_CastleTown00 = nullptr;

void LANDTABLE_CastleTown()
{

LoadLandTable(&LAND_CastleTown00, "CastleTown_Landtable", &TEXLIST_CastleTown);

objLandTable[LevelIDs_E][0] = (_OBJ_LANDTABLE*)LAND_CastleTown00->getlandtable();


	
	
}
PL_KILLCOLLI* Castle_deathzones[] = {
  Castlee1_deathzones
};

//	Load Deathzones:

void DEATHZONES_CastleTown()
{
	KillingCollisionModelsListList[LevelIDs_E] = Castle_deathzones;

}


//	Start Positions:

StartPosition STARTPOS_CastleTown00 = { LevelIDs_E, 0, { 173.22f, 25.0f, 1458.9f }, 0xC000 };
StartPosition STARTPOS_CastleTown01 = { LevelIDs_E, 1, { 173.22f, 25.0f, 1458.9f }, 0xC000 };
StartPosition STARTPOS_CastleTown02 = { LevelIDs_E, 2, { 173.22f, 25.0f, 1458.9f }, 0xC000 };

void STARTPOSITIONS_CastleTown()
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_CastleTown00);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_CastleTown01);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_CastleTown02);
	}
}






//	Level Init:
void initCTmusic()
{ PlayMusic((MusicIDs)MusicID_CastleTown); 

}

void CastleTown_Init()
{
	
	DEATHZONES_CastleTown();
	ReplaceBIN("SETSS04S", "SET_CastleTown-S");
	ReplaceBIN("SETSS04M", "SET_CastleTown-S");
	ReplaceBIN("SETSS04E", "SET_CastleTown-S");
	ReplaceBIN("SETSS04B", "SET_CastleTown-S");
	ReplaceBIN("SETSS04A", "SET_CastleTown-S");
	ReplaceBIN("SETSS04K", "SET_CastleTown-S");
	ReplaceBIN("SETSS04L", "SET_CastleTown-S");
	LoadCamFile(0, "SS04");
	LoadSetFile(0, "SS04");
	LANDTABLE_CastleTown();

}

void LoadingFunctionProxy()
{

	if (CurrentLevel == LevelIDs_E)
	{
		STARTPOSITIONS_CastleTown();
		SETVIEWDATA_CastleTown();
		CastleTown_Init();
	
		CurrentLevel = LevelIDs_StationSquare;
		LoadLevelObjTextures();
		CurrentLevel = LevelIDs_E;

		


	



		//LoadLevelTextures(LevelAndActIDs_StationSquare4);
		LoadLevelObjTextures();


	}

}
