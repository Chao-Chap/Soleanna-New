#include "pch.h"
#include "ModelInfo.h"
#include "paths.h"
#include "daeth.h"
#include "memaccess.h"
#include "hub.h"
#include "SADXEnums.h"
//	Custom FogData, DrawDistance and SkyboxDrawDistance values:

___stcFog FOGDATA_wvo[] = {
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 }
};

___stcClip DRAWDISTANCE_wvo[] = {
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f }
};

___stcClip SKYBOXDRAWDISTANCE_wvo[] = {
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f }
};

void SETVIEWDATA_wvo()
{
	gFog = FOGDATA_wvo[ssActNumber];
	gClipMap = DRAWDISTANCE_wvo[ClipLevel];
	gClipSky = SKYBOXDRAWDISTANCE_wvo[ClipLevel];
}


//	Load Landtable:

LandTableInfo* LAND_wvo00 = nullptr;
;
void LANDTABLE_wvo()
{

	LoadLandTable(&LAND_wvo00, "wvo_Landtable", &TEXLIST_wvo);

	objLandTable[LevelIDs_Soleanna_Levels1][0] = (_OBJ_LANDTABLE*)LAND_wvo00->getlandtable();


}


//	Load Deathzones:

void DEATHZONES_wvo()
{
	KillingCollisionModelsListList[LevelIDs_Soleanna_Levels1] = Castle_deathzones;



}

void PATHS_wvo()
{
HelperFunctionsGlobal.RegisterPathList(PATHDATA_BEACH00);
}

//	Start Positions:

StartPosition STARTPOS_wvo00 = { LevelIDs_Soleanna_Levels1, 0, { 183.22f, 934.0f, -723.9f }, 0xC000 };
StartPosition STARTPOS_wvo01 = { LevelIDs_Soleanna_Levels1, 1, { 1900.22f, 108.0f, -19.9f }, 0xC000 };
StartPosition STARTPOS_wvo02 = { LevelIDs_Soleanna_Levels1, 2, { -555.0f, 700.0f, 0.9f }, 0xC000 };

void STARTPOSITIONS_wvo()
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_wvo00);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_wvo01);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_wvo02);
	}
}




//	Level Init:
void initwvomusic()
{

	PlayMusic((MusicIDs)MusicID_wvo);


}

void wvo_Init()
{
	
	DEATHZONES_wvo();
	LoadCamFile(0, "SS04");
	LoadSetFile(0, "_wvo-");
	LoadCamFile(1, "SS04");
	LoadSetFile(1, "_FOREST-");
	LoadCamFile(2, "SS04");
	LoadSetFile(2, "_CITY-");
	LANDTABLE_wvo();



}

void LoadingFunctionProxy2()
{

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
