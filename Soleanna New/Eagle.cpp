#include "pch.h"
#include "sadx-utils.h"
#include "object-utils.h"

NJS_TEXNAME TEX_EAGLE[18];
NJS_TEXLIST  TEXLIST_EAGLE = { arrayptrandlengthT(TEX_EAGLE, Uint32) };

#define PNUM(twp) twp->btimer
AnimationFile* EAGLEFLY = nullptr;
ModelInfo* EAGLEMDL = nullptr;
CCL_INFO EAGLECOL = { 0, CI_FORM_SPHERE, 0xF0, 0, 0, {0.0f, 0.0f, 0.0f}, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };
void __cdecl Eagle_Display(task* tp) {
	if (!MissedFrames) {
		// Handle display
		auto twp = tp->twp;

		njSetTexture(&TEXLIST_EAGLE);

		njPushMatrix(0);

		njTranslateV(0, &twp->pos);
		njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
		x += 1;

		HelperFunctionsGlobal.Weights->Init(EAGLEMDL->getweightinfo(), EAGLEMDL->getmodel());
		NJS_ACTION act = { EAGLEMDL->getmodel(), EAGLEFLY->getmotion() };
		HelperFunctionsGlobal.Weights->Apply(EAGLEMDL->getweightinfo(), &act, x);
		njAction(&act, x);
		njPopMatrix(1u);
	}
}

void __cdecl EagleExec(task* obj) {
	taskwk* twp = obj->twp;


	obj->disp(obj);
}
void __cdecl Eagle_Init(task* obj) {

	obj->exec = EagleExec;
	obj->disp = Eagle_Display;
}
