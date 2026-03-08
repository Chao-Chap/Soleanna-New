#include "pch.h"
#include "braclet.h"
int BounceDownSpeed = -10;
float bounces = 0.0f;
int BounceUpSpeed = 2;

int bouncing = false
#define TaskHook FunctionHook<void, task*>
;
TaskHook Sonic_Exec_t(SonicTheHedgehog);

DataPointer(bool*, pInputStatusForEachPlayer, 0x40F30C); // we get a pointer to `ucInputStatusForEachPlayer` since the input mod replaces the array

bool CheckControl(int id)
{
	auto co2 = CharObj2Ptrs[id];

	if (co2)
	{
		if (co2->NoControlTime != 0)
		{
			return false;
		}
	}

	return !EV_MainThread_ptr && ucInputStatus == TRUE && (pInputStatusForEachPlayer[id] == 1);
}
static void Sonic_SoleannaActions(EntityData1* data, motionwk2* mwp, CharObj2* co2)
{
	for (int i = 0; i < 4; ++i) // or playertwp.size() to loop for the whole player table

		if (co2) {


			if (CheckControl(data->CharIndex) && PressedButtons[data->CharIndex] & Buttons_X && (!(data->Status & Status_Ground)))


			{
				data->Action = MD_SONIC_FALL;
				data->Status |= Status_Ball;
				co2->Speed.y += BounceDownSpeed;
				bouncing = true;
				data->Status |= Status_Attack;

			}



			if (bouncing == true && (data->Action == MD_SONIC_STND or data->Action == MD_SONIC_WALK))
			{
				co2->Speed.y = BounceUpSpeed + bounces;
				data->Status |= Status_Ball;
				data->Status |= Status_Attack;
				data->Action = MD_SONIC_JUMP;
				co2->AnimationThing.Index = 14;

				if (bounces < 1.5f)

				{
					bounces += .5f;
				}
				data->Status &= ~Status_Ground;
				bouncing = false;
			}


			if (bouncing == false && (data->Action == MD_SONIC_STND or data->Action == MD_SONIC_WALK))
			{

				bounces = 0;
				data->Status &= ~Status_Ball;
			}

		}


}

	void Sonic_Exec_r(task * tsk)
	{
		auto data = (EntityData1*)tsk->twp; // main task containing position, rotation, scale
		auto mwp = (motionwk2*)tsk->mwp; // task containing movement information
		auto co2 = (CharObj2*)mwp->work.ptr; // physics, animation info, and countless other things

		Sonic_SoleannaActions(data, mwp, co2);
		Sonic_Exec_t.Original(tsk);



	}
	void Sonic_Sol_Init(const HelperFunctions& helperFunctions)
	{
		Sonic_Exec_t.Hook(Sonic_Exec_r);

	}