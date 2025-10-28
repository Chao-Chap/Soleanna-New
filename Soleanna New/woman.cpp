#include "pch.h"
#include "weights.h"
#include "sadx-utils.h"
AnimationFile* DEFAULTFIDLE = nullptr;
ModelInfo* NPC_Woman1MDL = nullptr;


void DISPLAY_Woman1(task* tp)
{

	auto twp = tp->twp;

	njSetTexture(&TEXLIST_NPC_WOMAN1);

	njPushMatrix(0);

	njTranslateV(0, &twp->pos);
	njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
	x += 1;

	HelperFunctionsGlobal.Weights->Init(NPC_Woman1MDL->getweightinfo(), NPC_Woman1MDL->getmodel());
	NJS_ACTION act = { NPC_Woman1MDL->getmodel(), DEFAULTFIDLE->getmotion() };
	HelperFunctionsGlobal.Weights->Apply(NPC_Woman1MDL->getweightinfo(), &act, x);
	njAction(&act, x);
	njPopMatrix(1u);

	Shadow(twp, .5f);
}




const char* Woman1_Dialogue[3] = {
	{ "\aWhat if you wanted to go \nto heaven but Solaris said"},
	{"'Not enough rings!'"},
	 { nullptr },
};
const char* Woman2_Dialogue[3] = {
	{ "\aPretty weird to have a monarchy\nwhile also taxing our butts off!"},
	{"I think we should skin the \nprincess alive. "},
	 { nullptr },
};
const char* Woman3_Dialogue[4] = {
	{ "\aI used to pray to Solaris, but then I realized religion \nwas a tool of opression."},
	{"It's all bullshit."},
	{"I have a podcast, if you're interested."},
	 { nullptr },
};
const char* Woman4_Dialogue[3] = {
	{ "\aWhy do we have teleport gates AND\ntrains, like, surely the gates are better?"},
	{"\amaybe we need more gates? \nwho puts them here anyway? Is it the government?"},
	 { nullptr },
};
const char* Womancity1_Dialogue[2] = {
	{ "\aIt's been a hard day's work of... standing here."},
	 { nullptr },
};
void NPC_Woman1_Event(task* tp)
{
	tp->disp = DISPLAY_Woman1;
	auto twp = tp->twp;

		for (int i = 0; i < 4; ++i) 		if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(Woman1_Dialogue, 120);
		}

	}

	tp->disp(tp);
}

void NPC_Woman2_Event(task* tp)
{
	tp->disp = DISPLAY_Woman1;
	auto twp = tp->twp;

		for (int i = 0; i < 4; ++i) 		if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWJ");


			DisplayHintText(Woman2_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_Woman3_Event(task* tp)
{
	tp->disp = DISPLAY_Woman1;
	auto twp = tp->twp;

		for (int i = 0; i < 4; ++i) 		if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWWWW");


			DisplayHintText(Woman3_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_WomanCity1_Event(task* tp)
{
	tp->disp = DISPLAY_Woman1;
	auto twp = tp->twp;

		for (int i = 0; i < 4; ++i) 		if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWWWW");


			DisplayHintText(Woman4_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_WomanCity2_Event(task* tp)
{
	tp->disp = DISPLAY_Woman1;
	auto twp = tp->twp;

		for (int i = 0; i < 4; ++i) 		if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWWWW");


			DisplayHintText(Womancity1_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void Load_NPC_Woman1()
{
	NPC_Woman1MDL = LoadBasicModel("NPC_Woman1");
	DEFAULTFIDLE = LoadAnim("NPCF_WAIT");



}