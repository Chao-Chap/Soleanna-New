#include "pch.h"
#include "mod.h"
#include "hub.h"
#include "o_skybox.h"
//	Animated Textures:



void ANIM_Water()
{
	TEXLIST_CastleTown.textures[295].texaddr = TEXLIST_CastleTown_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_CastleTown_Water))].texaddr; // Water Animation

}


//	Level Task:

void RD_CastleTown(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{		


		
		SETVIEWDATA_CastleTown();

		twp->mode++;
	}




}


//	Init LevelTask:

void INIT_LevelTask()
{

	RoundMasterList[LevelIDs_E] = RD_CastleTown; // Level Task.
	ScrollMasterList[LevelIDs_E] = BG_CastleTown; // Skybox Task.

}