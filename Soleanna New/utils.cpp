#include "pch.h"

//	Counters:
uint8_t DragonCount{ 0 };


//	Bools and code to check if certain mods or config options are enabled:

bool HD_GUI = false;
bool DC_Conversion = false;
bool HUD_Plus = false;

bool DC_HudTweaks = false;

//	Expand Draw Queue Memory Pool (Applies to the entire game):

void ExpandDrawQueueMemoryPool()
{
	WriteData((Uint32*)0x408643, 0x100000ui32);
	WriteData((Uint32*)0x40864D, 0x100000ui32);
	WriteData((Uint32*)0x40866B, 0x100000ui32);
}


//	Function for loading Basic Models:

ModelInfo* LoadBasicModel(const char* name)
{
    PrintDebug("[CastleTown] Loading basic model: %s... ", name);

    std::string fullPath = "system\\models\\";
    fullPath = fullPath + name + ".sa1mdl";

    ModelInfo* mdl = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

    if (mdl->getformat() != ModelFormat_Basic)
    {
        PrintDebug("Failed!\n");

        delete mdl;
        return nullptr;
    }

    PrintDebug("Done!\n");

    return mdl;
}


//  Function for loading LandTables:

void LoadLandTable(LandTableInfo** info, const char* name, NJS_TEXLIST* texlist)
{
	std::string fullPath = "system\\landtables\\";
	fullPath = fullPath + name + ".sa1lvl";

	LandTableInfo* land = new LandTableInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (land->getlandtable() == nullptr)
	{
		delete land;
		*info = nullptr;
	}
	
	else
	{
		if (texlist != nullptr)
		{
			land->getlandtable()->TexList = texlist;
		}

		*info = land;
	}
}


//	Function for loading Chunk Models:

ModelInfo* LoadChunkModel(const char* name)
{
	PrintDebug("[CastleTown] Loading chunk model: %s... ", name);

	std::string fullPath = "system\\models\\";
	fullPath = fullPath + name + ".sa2mdl";

	ModelInfo* mdl = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (mdl->getformat() != ModelFormat_Chunk)
	{
		PrintDebug("Failed!\n");
		
		delete mdl;
		return nullptr;
	}

	PrintDebug("Done!\n");
	
	return mdl;
}


//	Functions for rendering Chunk Models:

void SetupWorldMatrix()
{
    ProjectToWorldSpace();
    Direct3D_SetWorldTransform();
    memcpy(_nj_current_matrix_ptr_, &ViewMatrix, sizeof(NJS_MATRIX));
}

void SetupChunkModelRender()
{
    SetupWorldMatrix();
    Direct3D_SetChunkModelRenderState();
}

void ResetChunkModelRender()
{
    Direct3D_ResetWorldTransform();
    Direct3D_UnsetChunkModelRenderState();

	CnkRestoreSpecular();
}

FunctionPointer(void, _njCnkDrawModel, (NJS_CNK_MODEL* a3), 0x789750);

void njCnkAction(NJS_ACTION* action, float frame)
{
	DisplayAnimationFrame(action, frame, (QueuedModelFlagsB)0, 0, (void(__cdecl*)(NJS_MODEL_SADX*, int, int))_njCnkDrawModel);
}


//	Functions for loading Animations:



//	Functions for rendering Sprites:

void SetSpriteParam()
{
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
	SetMaterial(1.0f, 1.0, 1.0f, 1.0f);
}

void ResetSpriteParam()
{
	ResetMaterial();
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
}

void ScaleUI(uiscale::Align type)
{
	HelperFunctionsGlobal.PushScaleUI((uiscale::Align)(type), false, 1.0f, 1.0f);
}

void ResetScaleUI()
{
	HelperFunctionsGlobal.PopScaleUI();
}