#include "pch.h"
#include "mod.h"
#include "hub.h"
#include "o_skybox.h"
//	Animated Textures:



void ANIM_Water()
{
	TEXLIST_CastleTown.textures[295].texaddr = TEXLIST_CastleTown_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_CastleTown_Water))].texaddr; // Water Animation
	TEXLIST_FOREST.textures[84].texaddr = TEXLIST_CastleTown_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_CastleTown_Water))].texaddr; // Water Animation
	TEXLIST_City.textures[625].texaddr = TEXLIST_CastleTown_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_CastleTown_Water))].texaddr; // Water Animation
}


//	Level Task:

void RD_CastleTown(task* tp)
{
	auto twp = tp->twp;

	if (twp->mode != CurrentAct + 1)
	{

		if (CurrentAct == 0) {

			initCTmusic();
			twp->mode = 1;
			
		}
	
	
		if (CurrentAct == 1) {
	
			initForestmusic();
			
			twp->mode = 2;
		
		}

		if (CurrentAct == 2) {

			initCitymusic();
			twp->mode = 3;
		}

	}
		SETVIEWDATA_CastleTown();
	}



//	Init LevelTask:

void INIT_LevelTask()
{
	STARTPOSITIONS_CastleTown();


	RoundMasterList[LevelIDs_Soleanna_Hub] = RD_CastleTown; // Level Task.
	ScrollMasterList[LevelIDs_Soleanna_Hub] = BG_CastleTown; // Skybox Task.

}