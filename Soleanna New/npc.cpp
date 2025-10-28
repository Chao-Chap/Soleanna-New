#include "pch.h"
#include "weights.h"
#include "sadx-utils.h"
AnimationFile* NPCIDLE = nullptr;
ModelInfo* NPC_SONICMANMDL = nullptr;

void DISPLAY_SonicMAN(task* tp)
{


	auto twp = tp->twp;
	
	njSetTexture(&TEXLIST_NPC_SONICMAN);
	
	njPushMatrix(0);

	njTranslateV(0, &twp->pos);
	njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
	x += 1;

	HelperFunctionsGlobal.Weights->Init(NPC_SONICMANMDL->getweightinfo(), NPC_SONICMANMDL->getmodel());
	NJS_ACTION act = { NPC_SONICMANMDL->getmodel(), NPCIDLE->getmotion()};
	HelperFunctionsGlobal.Weights->Apply(NPC_SONICMANMDL->getweightinfo(), &act, x);
	njAction(&act,x);
	njPopMatrix(1u);
	Shadow(twp, .8f);
}


Bool lookatsonicman = false;



AnimationFile* LoadAnim(const char* name)
{
    std::string fullPath = "system\\models\\";

	fullPath = fullPath + name + ".saanim";

	AnimationFile* file = new AnimationFile(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (file->getmotion() != nullptr) {
		PrintDebug("[Soleanna] Loaded animation: %s.", name);
	}
	else {
		PrintDebug("[Soleanna] Failed loading animation: %s.", name);
	}

	return file;
}

const char* SonicManDialogue1[3] = {
	{ "\a I'm Sonic-Man!\n The Blue Blur Himself!"},
	{ "\a I would race you but i don't\n Want to Humilate you!"},
	 { nullptr },
};
const char* SonicManDialogue2[2] = {
	{"\aRemember kids, by request of my parole officer, \nSonic-man says 'no' to drugs!"},
	{ nullptr },
};


void NPC_SONICMAN_Event(task* tp)
{
	tp->disp = DISPLAY_SonicMAN;
	auto twp = tp->twp;

		for (int i = 0; i < 4; ++i) 		if (IsPlayerInsideSphere(&tp->twp->pos, 30) == i + 1)
	{

	
	if (Controllers[i].PressedButtons & Buttons_Y)
	{
		EV_SetFace(	EV_GetPlayer(i), "WWWWWWW");
		
	
		DisplayHintText(SonicManDialogue1, 120);
	}


}
	tp->disp(tp);
}

	void Load_NPC_SONICMAN()
{
		NPC_SONICMANMDL = LoadBasicModel("NPC_SONICMAN");
		 NPCIDLE = LoadAnim("SonicMan_Wait");
	


}