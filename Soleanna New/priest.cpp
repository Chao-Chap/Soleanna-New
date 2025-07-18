#include "pch.h"
#include "weights.h"
#include "sadx-utils.h"
AnimationFile* DEFAULTIDLE = nullptr;
ModelInfo* NPC_PriestMDL = nullptr;
int x;

void DISPLAY_Priest(task* tp)
{


	auto twp = tp->twp;

	njSetTexture(&TEXLIST_NPC_PRIEST);

	njPushMatrix(0);

	njTranslateV(0, &twp->pos);
	njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
	x += 1;

	HelperFunctionsGlobal.Weights->Init(NPC_PriestMDL->getweightinfo(), NPC_PriestMDL->getmodel());
	NJS_ACTION act = { NPC_PriestMDL->getmodel(), DEFAULTIDLE->getmotion() };
	HelperFunctionsGlobal.Weights->Apply(NPC_PriestMDL->getweightinfo(), &act, x);
	njAction(&act, x);
	njPopMatrix(1u);
	Shadow(twp, .5f);
}





const char* Default_Priest_Dialogue[2] = {
	{ "\aYou could make a religion out of this!"},
	 { nullptr },
};
const char* Priest1_Dialogue[3] = {
	{ "\aSonic, if you don't stop splashing in\nthe baptismal font during mass"},
	{ "\aI am going to hold you under!"},
	 { nullptr },
};
const char* Priest2_Dialogue[3] = {
	{ "\aThe church is going to go \nbankrupt if you keep"},
	{ "\astealing the pews for use \nin a fort!"},
	 { nullptr },
};
const char* Priest3_Dialogue[3] = {
	{ "\aTails. Stop sending your 'grammar \ncorrections' to our newsletter."},
	{ "\aWe cannot edit what is already printed."},
	 { nullptr },
};
const char* Priest4_Dialogue[3] = {
	{ "\aWhat do we do at our rituals to Solaris?\nThat is an interesting question."},
	{ "\aIt's very gay. So much homosexual activity. \nHe's all rainbow-y, after all."},
	 { nullptr },
};
const char* PriestForest1_Dialogue[3] = {
	{ "\aI'm a rebelious youth! \nThat's why i joined the church!"},
	{ "\aThe church is all about... rebelling?\n...I think my worlview might have fell apart."},
	 { nullptr },
};
const char* PriestForest2_Dialogue[2] = {
	{ "\aSolaris watches over us always. \nHe kinda needs to learn to respect boundaries."},
	 { nullptr },
};
const char* PriestForest3_Dialogue[3] = {
	{ "\aWe sing many songs in \nservice to Solaris."},
	{"Anything that mentions light?\nBosh, thats ours now."},
	 { nullptr },
};
const char* PriestCity1_Dialogue[3] = {
	{ "\aDo you think Solaris stays \nin heaven because he too"},
	{"\afears clipping through the floor?"},
	 { nullptr },
};
const char* PriestCity2_Dialogue[3] = {
	{ "\aActually, Solaris is not in heaven.\nthey where seperated into two and sealed."},
	{"\aDivorce is always so sad. \nTheir kids must be devastated!"},
	 { nullptr },
};

void NPC_Priest_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	
		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			const char* const* msg;
			switch (CurrentCharacter)
			{
			case Characters_Sonic:
				msg = Priest1_Dialogue;
				break;
			case Characters_Tails:
				msg = Priest3_Dialogue;
				break;
			default:
				msg = Default_Priest_Dialogue;
				break;
			}
			DisplayHintText(msg, 120);
		}

		tp->disp(tp);
	
}
void NPC_Priest2_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(Priest2_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_Priest3_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(Priest4_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_Priest4_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(PriestForest1_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_Priest5_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(PriestForest2_Dialogue, 120);
		}

	}

	tp->disp(tp);
}

void NPC_Priest6_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(PriestForest3_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_PriestCity1_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(PriestCity1_Dialogue, 120);
		}

	}

	tp->disp(tp);
}
void NPC_PriestCity2_Event(task* tp)
{
	tp->disp = DISPLAY_Priest;
	auto twp = tp->twp;

	if (IsPlayerInsideSphere(&tp->twp->pos, 30))
	{

		if (Controllers[0].PressedButtons & Buttons_Y)
		{
			EV_SetFace(EV_GetPlayer(0), "WWWWWWW");


			DisplayHintText(PriestCity2_Dialogue, 120);
		}

	}

	tp->disp(tp);
}

void Load_NPC_Priest()
{
	NPC_PriestMDL = LoadBasicModel("NPC_Priest");
	DEFAULTIDLE = LoadAnim("NPCWait");



}