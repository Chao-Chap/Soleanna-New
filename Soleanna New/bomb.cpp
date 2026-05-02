#include "pch.h"
#include "bomb.h"
TaskHook Tails_Exec_t(MilesTalesPrower);
ModelInfo* RINGBOXMDL = nullptr;
NJS_TEXNAME TEX_RINGBOMB[18];
NJS_TEXLIST  TEXLIST_RINGBOMB = { arrayptrandlengthT(TEX_RINGBOMB, Uint32) };
PVMEntry RingbombTex = { "RINGBOMB", &TEXLIST_RINGBOMB };

void DISPLAY_Bomb(task* tp)
{
	if (MissedFrames)
		return;
	auto twp = tp->twp;

	njPushMatrix(0);

	njTranslateV(0, &twp->pos);
	njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
	dsDrawObject(RINGBOXMDL->getmodel());


	njPopMatrix(1u);
}
void BombCustomDisplay(task* tp)
{
	if (MissedFrames)
		return;
	auto twp = tp->twp;

	njPushMatrix(0);

	njTranslateV(0, &twp->pos);
	njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
	dsDrawObject(RINGBOXMDL->getmodel());
}

void EXEC_Bomb(task* tp)
{
	auto twp = tp->twp;
	EntryColliList(twp);
	tp->disp = DISPLAY_Bomb;
	
	tp->disp(tp);


	
}void BombManager(task* tp)
{
    if (tp->twp->flag & 0xC00)
    {

        FreeTask(tp);

    }
    else
    {

        LoopTaskC(tp);

    }

}
static void Tails_SolActions(EntityData1* data, motionwk2* mwp, CharObj2* co2)
{
	if (CheckControl(data->CharIndex) && PressedButtons[data->CharIndex] & Buttons_C)
	{

		if (co2) {
			TaskFunc(SaruBombA, 0x4AC920);
			TaskFunc(BombDisplayHook, 0x4AB200);
			task* obj = CreateElementalTask(0x2, 2, BombManager);
			task* bomb = CreateChildTask(2u, SaruBombA, obj);
			bomb->disp = BombCustomDisplay;
			bomb->twp->pos = data->Position;
		
	}
	}
}

static void Tails_Exec_r(task* tsk)
{
	auto data = (EntityData1*)tsk->twp; // main task containing position, rotation, scale
	auto mwp = (motionwk2*)tsk->mwp; // task containing movement information
	auto co2 = (CharObj2*)mwp->work.ptr; // physics, animation info, and countless other things

	Tails_SolActions(data, mwp, co2);

	Tails_Exec_t.Original(tsk);
}

void Tails_Sol_Init(const HelperFunctions& helperFunctions)
{
	Tails_Exec_t.Hook(Tails_Exec_r);
	HelperFunctionsGlobal.RegisterCharacterPVM(Characters_Tails, {"E_BOMB", (TexList*)0x96B464});



}
void LOAD_Ringbomb()
{
	RINGBOXMDL = LoadBasicModel("itemboxair_boxbody.nja");
}