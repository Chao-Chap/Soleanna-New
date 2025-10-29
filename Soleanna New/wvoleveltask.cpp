#include "pch.h"
#include "mod.h"
#include "hub.h"
#include "o_skybox.h"
//	Animated Textures:



//	Level Task:

void RD_WVO(task* tp)
{
	auto twp = tp->twp;

	if (twp->mode != CurrentAct + 1)
	{

		if (CurrentAct == 0) {

			initwvomusic();
			twp->mode = 1;

		}


	}
	SETVIEWDATA_wvo();
}



//	Init LevelTask:

void INIT_LevelTaskWvo()
{
	STARTPOSITIONS_wvo();


	RoundMasterList[LevelIDs_Soleanna_Levels1] = RD_WVO; // Level Task.
	ScrollMasterList[LevelIDs_Soleanna_Levels1] = BG_CastleTown; // Skybox Task.

}