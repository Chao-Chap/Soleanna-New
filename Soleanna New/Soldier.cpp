#include "pch.h"
#include "weights.h"
int soldierpos;
AnimationFile* SOLDIERIDLE = nullptr;
ModelInfo* NPC_SOLDIERMDL = nullptr;
void DISPLAY_SOLDIER(task* tp)
{

	auto twp = tp->twp;

	njSetTexture(&TEXLIST_NPC_SOLDIER);

	njPushMatrix(0);

	njTranslateV(0, &twp->pos);
	njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
	soldierpos += 1;

	HelperFunctionsGlobal.Weights->Init(NPC_SOLDIERMDL->getweightinfo(), NPC_SOLDIERMDL->getmodel());
	NJS_ACTION soldieract = { NPC_SOLDIERMDL->getmodel(), SOLDIERIDLE->getmotion() };
	HelperFunctionsGlobal.Weights->Apply(NPC_SOLDIERMDL->getweightinfo(), &soldieract, soldierpos);
	njAction(&soldieract, soldierpos);
	njPopMatrix(1u);
}





const char* Soldier1Dialogue[2] = {
	{ "\aDon't be causing any mischief! \n I have my eye on you!"},
	 { nullptr },
};
const char* Soldier2Dialogue[2] = {
	{ "\aNot much happening today.\n Have you seen the captain?"},
	 { nullptr },
};

const char* Soldier3Dialogue[2] = {
	{ "\aWhy did i become a guard? I mostly like \ngetting paid to stand around most days."},
	 { nullptr },
};
const char* Soldier4Dialogue[2] = {
	{ "\aI'm 'getting down with the youth' as they say! \nThe miltary is so gigachad and glory-pilled!"},
	 { nullptr },
};
const char* Soldier5Dialogue[3] = {
	{ "\aContrary to popular belief, 'Soldier Boy'\nis not actually a part of the miltary!"},
	{"\a or so they say, anyway. I'm keeping \nmy eyes open, though."},
	 { nullptr },
};
const char* SoldierForest1Dialogue[4] = {
	{ "\aKids often roll on by \n screaming loudly!"},
	{"\aThey never say phrases! \nThey just scream!"},
	{"\aThey're all like 'HA! YAH! HUT!'\nI don't understand the youth anymore!"},
	 { nullptr },
};
const char* SoldierForest2Dialogue[3] = {
	{ "\aI founded my own forest nation here\nit was very peaceful!"},
	{"\aAt least until the civil war..."},
	 { nullptr },
};
const char* SoldierForest3Dialogue[3] = {
	{ "\aI was assiagned to post here. \nNothing ever happens."},
	{"\aWhat am I guarding? Nothing is here."},
	 { nullptr },
};

void NPC_SOLDIER_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(Soldier1Dialogue, 120);
		}


	}
	tp->disp(tp);
}

void Load_NPC_SOLDIER()
{
	NPC_SOLDIERMDL = LoadBasicModel("NPC_SOLDIER");
	SOLDIERIDLE = LoadAnim("SOLDIER_Wait");



}

void NPC_SOLDIER2_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;

	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(Soldier2Dialogue, 120);
		}


	}
	tp->disp(tp);
}

void NPC_SOLDIER3_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(Soldier3Dialogue, 120);
		}


	}
	tp->disp(tp);
}

void NPC_SOLDIER4_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(Soldier4Dialogue, 120);
		}


	}
	tp->disp(tp);
}

void NPC_SOLDIER5_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(Soldier5Dialogue, 120);
		}


	}
	tp->disp(tp);
}

void NPC_SOLDIER6_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(SoldierForest1Dialogue, 120);
		}


	}
	tp->disp(tp);
}void NPC_SOLDIER7_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(SoldierForest2Dialogue, 120);
		}


	}
	tp->disp(tp);
}

void NPC_SOLDIER8_Event(task* tp)
{
	tp->disp = DISPLAY_SOLDIER;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{


		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWW");


			DisplayHintText(SoldierForest3Dialogue, 120);
		}


	}
	tp->disp(tp);
}