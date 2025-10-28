#include "pch.h"
#include "sadx-utils.h"
#include "object-utils.h"
#include "objects.h"
void WeSittinSonicNow(taskwk* twp, playerwk* pwp)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];

		if (ptwp) // check if the player exists
		{
			twp->mode = 45;
			pwp->mj.reqaction = 65;
		}
	}

}
void WeSittinMilesNow(taskwk* twp, playerwk* pwp)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];

		if (ptwp) // check if the player exists
		{
			twp->mode = 43;
			pwp->mj.reqaction = 89;
		}
	}

}
void WeSittinKnuxNow(taskwk* twp, playerwk* pwp)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];

		if (ptwp) // check if the player exists
		{
			twp->mode = 52;
			pwp->mj.reqaction = 36;
		}
	}

}
void WeSittinAmyNow(taskwk* twp, playerwk* pwp)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];

		if (ptwp) // check if the player exists
		{
			twp->mode = 48;
			pwp->mj.reqaction = 76;
		}
	}

}
void WeSittinGammaNow(taskwk* twp, playerwk* pwp)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];

		if (ptwp) // check if the player exists
		{
			twp->mode = 53;
			pwp->mj.reqaction = 72;
		}
	}

}
void WeSittinBigNow(taskwk* twp, playerwk* pwp)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];

		if (ptwp) // check if the player exists
		{
			twp->mode = 55;
			pwp->mj.reqaction = 96;
		}
	}

}
ModelInfo* BENCHMDL = nullptr;
CCL_INFO BENCHCOL = { 0, CI_FORM_SPHERE, 0xF0, 0, 0, {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };

void DISPLAY_Bench(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_BENCH);

    njPushMatrix(0);

    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);

    dsDrawObject(BENCHMDL->getmodel());

    njPopMatrix(1u);
}
void BENCHExec(task* tp)
{
	tp->disp = DISPLAY_Bench;
	auto twp = tp->twp;
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table
	{
		auto ptwp = playertwp[i];


	if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

			if (playerpwp) {
				if (Controllers[i].PressedButtons & Buttons_Y)
				{


					switch (playertwp[i]->counter.b[1])
					{
					case Characters_Sonic:
						WeSittinSonicNow(playertwp[i], playerpwp[i]);
						playertwp[i]->pos = twp->pos;
						playertwp[i]->ang.y = twp->ang.y + 0x4000;
						playertwp[i]->ang.y = 0x8000 - playertwp[i]->ang.y;
						playertwp[i]->ang.x = twp->ang.x;
						playertwp[i]->ang.z = twp->ang.z;

						break;
					case Characters_Tails:

						WeSittinMilesNow(playertwp[i], playerpwp[i]);
						playertwp[i]->pos.y = twp->pos.y + 1;
						playertwp[i]->pos.x = twp->pos.x;
						playertwp[i]->pos.z = twp->pos.z;
						playertwp[i]->ang.y = twp->ang.y + 0x4000;
						playertwp[i]->ang.y = 0x8000 - playertwp[i]->ang.y;
						playertwp[i]->ang.x = twp->ang.x;
						playertwp[i]->ang.z = twp->ang.z;
						break;

					case Characters_Knuckles:

						WeSittinKnuxNow(playertwp[i], playerpwp[i]);
						playertwp[i]->pos.y = twp->pos.y + 1;
						playertwp[i]->pos.x = twp->pos.x;
						playertwp[i]->pos.z = twp->pos.z;
						playertwp[i]->ang.y = twp->ang.y + 0x4000;
						playertwp[i]->ang.y = 0x8000 - playertwp[i]->ang.y;
						playertwp[i]->ang.x = twp->ang.x;
						playertwp[i]->ang.z = twp->ang.z;
						break;

					case Characters_Amy:

						WeSittinAmyNow(playertwp[i], playerpwp[i]);
						playertwp[i]->pos.y = twp->pos.y + 1;
						playertwp[i]->pos.x = twp->pos.x;
						playertwp[i]->pos.z = twp->pos.z;
						playertwp[i]->ang.y = twp->ang.y + 0x4000;
						playertwp[i]->ang.y = 0x8000 - playertwp[i]->ang.y;
						playertwp[i]->ang.x = twp->ang.x;
						playertwp[i]->ang.z = twp->ang.z;
						break;
					case Characters_Gamma:

						WeSittinGammaNow(playertwp[i], playerpwp[i]);
						playertwp[i]->pos.y = twp->pos.y - 3;
						playertwp[i]->pos.x = twp->pos.x;
						playertwp[i]->pos.z = twp->pos.z;
						playertwp[i]->ang.y = twp->ang.y + 0x4000;
						playertwp[i]->ang.y = 0x8000 - playertwp[i]->ang.y;
						playertwp[i]->ang.x = twp->ang.x;
						playertwp[i]->ang.z = twp->ang.z;
						break;
					case Characters_Big:

						WeSittinBigNow(playertwp[i], playerpwp[i]);
						playertwp[i]->pos.y = twp->pos.y + 1;
						playertwp[i]->pos.x = twp->pos.x;
						playertwp[i]->pos.z = twp->pos.z;
						playertwp[i]->ang.y = twp->ang.y + 0x4000;
						playertwp[i]->ang.y = 0x8000 - playertwp[i]->ang.y;
						playertwp[i]->ang.x = twp->ang.x;
						playertwp[i]->ang.z = twp->ang.z;

						break;
					}

				}
				if (Controllers[i].PressedButtons & Buttons_A)
				{
					playertwp[i]->mode = 1;
				}
			}
		}
	}
	tp->disp(tp);

}
void LOAD_Bench()
{
	BENCHMDL = LoadBasicModel("BENCHHYPE");
}