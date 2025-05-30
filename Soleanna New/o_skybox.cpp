#include "pch.h"

//  Model:

ModelInfo* MDL_CastleTown_Skybox = nullptr;


//  Skybox - Main:

void DISPLAY_CastleTown_Skybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_CastleTown_Sky);

    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, -1000.0f, 0.0f);
    njScale(0,3.0f, 3.0f, 3.0f);

    DrawModel(MDL_CastleTown_Skybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_CastleTown_Skybox(task* tp)
{
    auto twp = tp->twp;

    if (!twp->mode)
    {  
        SetGlobalPoint2Col_Colors(0x331544, 0x331544, 0x331544);
        
        twp->mode++;
    }

    tp->disp(tp);
}

void BG_CastleTown(task* tp)
{
    tp->exec = EXEC_CastleTown_Skybox;
    tp->disp = DISPLAY_CastleTown_Skybox;
}


//  Skybox - Load Assets:

void LOAD_CastleTown_Skybox()
{
    MDL_CastleTown_Skybox = LoadBasicModel("CastleTown_Skybox");
}