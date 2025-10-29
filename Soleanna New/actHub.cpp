#include "pch.h"
#include "ModelInfo.h"
#include "paths.h"
#include "daeth.h"
#include "memaccess.h"
#include "hub.h"
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
LandTableInfo* LAND_FOREST00 = nullptr;
LandTableInfo* LAND_CITY00 = nullptr;
void LANDTABLE_CastleTown()
{

LoadLandTable(&LAND_CastleTown00, "CastleTown_Landtable", &TEXLIST_CastleTown);

objLandTable[LevelIDs_Soleanna_Hub][0] = (_OBJ_LANDTABLE*)LAND_CastleTown00->getlandtable();
LoadLandTable(&LAND_FOREST00, "Forest_Landtable", &TEXLIST_FOREST);

objLandTable[LevelIDs_Soleanna_Hub][1] = (_OBJ_LANDTABLE*)LAND_FOREST00->getlandtable();

LoadLandTable(&LAND_CITY00, "City_Landtable", &TEXLIST_City);

objLandTable[LevelIDs_Soleanna_Hub][2] = (_OBJ_LANDTABLE*)LAND_CITY00->getlandtable();
	
}
PL_KILLCOLLI* Castle_deathzones[] = {
  Castlee1_deathzones,
	Forest_deathzones,
	Death_City
};

//	Load Deathzones:

void DEATHZONES_CastleTown()
{
	KillingCollisionModelsListList[LevelIDs_Soleanna_Hub] = Castle_deathzones;



}


//	Start Positions:

StartPosition STARTPOS_CastleTown00 = { LevelIDs_Soleanna_Hub, 0, { 173.22f, 25.0f, 1458.9f }, 0xC000 };
StartPosition STARTPOS_CastleTown01 = { LevelIDs_Soleanna_Hub, 1, { 1900.22f, 108.0f, -19.9f }, 0xC000 };
StartPosition STARTPOS_CastleTown02 = { LevelIDs_Soleanna_Hub, 2, { -555.0f, 700.0f, 0.9f }, 0xC000 };

void STARTPOSITIONS_CastleTown()
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_CastleTown00);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_CastleTown01);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_CastleTown02);
	}
}
void newtitlecard(){
	*(const char**)0x91C47C = "T_CASTLETOWN";
	*(const char**)0x91C30C = "T_CASTLETOWN";
}



void initCitymusic()
{

	PlayMusic((MusicIDs)MusicID_City);
	
}

//	Level Init:
void initCTmusic()
{ 

	PlayMusic((MusicIDs)MusicID_CastleTown); 


}

void CastleTown_Init()
{

	DEATHZONES_CastleTown();
	LoadCamFile(0, "SS04");
	LoadSetFile(0, "_CastleTown-");
	LoadCamFile(1, "SS04");
	LoadSetFile(1, "_FOREST-");
	LoadCamFile(2, "SS04");
	LoadSetFile(2, "_CITY-");
	LANDTABLE_CastleTown();



}

void LoadingFunctionProxy()
{

	if (CurrentLevel == LevelIDs_Soleanna_Hub)
	{
		STARTPOSITIONS_CastleTown();
		SETVIEWDATA_CastleTown();
		CastleTown_Init();

		CurrentLevel = LevelIDs_StationSquare;
		LoadLevelObjTextures();
		CurrentLevel = LevelIDs_Soleanna_Hub;

		


	



		//LoadLevelTextures(LevelAndActIDs_StationSquare4);
		LoadLevelObjTextures();


	}
	if (CurrentLevel == LevelIDs_Soleanna_Levels1)
	{
		STARTPOSITIONS_wvo();
		SETVIEWDATA_wvo();
		wvo_Init();
		CurrentLevel = LevelIDs_StationSquare;
		LoadLevelObjTextures();
		CurrentLevel = LevelIDs_Soleanna_Levels1;








		//LoadLevelTextures(LevelAndActIDs_StationSquare4);
		LoadLevelObjTextures();


	}
}
