#include "pch.h"
#include "ModelInfo.h"
#include "paths.h"
#include "daeth.h"
#include "memaccess.h"

#include "SADXEnums.h"
#include "hub.h"
//	Custom FogData, DrawDistance and SkyboxDrawDistance values:

___stcFog FOGDATA_FOREST[] = {
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 }
};

___stcClip DRAWDISTANCE_FOREST[] = {
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f }
};

___stcClip SKYBOXDRAWDISTANCE_FOREST[] = {
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f }
};

void SETVIEWDATA_FOREST()
{
	gFog = FOGDATA_FOREST[ssActNumber];
	gClipMap = DRAWDISTANCE_FOREST[ClipLevel];
	gClipSky = SKYBOXDRAWDISTANCE_FOREST[ClipLevel];
}


//	Load Landtable:





//	Load Deathzones:








//	Level Init:
void initForestmusic()
{
	PlayMusic((MusicIDs)MusicID_FOREST);

}



