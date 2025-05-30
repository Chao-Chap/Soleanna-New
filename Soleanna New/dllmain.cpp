#include "pch.h"
#include "SADXModLoader.h"
#include "Header.h"
#include <vector>
#include "sadx-utils.h"
#include "multi.h"
#include <vector>
#include "mod.h"
#include "hub.h"
#include "o_skybox.h"
int MusicID_CastleTown;

const HelperFunctions* gHelperFunctions;

std::string ModPath;
HelperFunctions HelperFunctionsGlobal;

// or #include "stdafx.h" for previous Visual Studio versions

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
	
		MusicInfo BGM_CASTLETOWN{ "castletown", 1 };

		MusicID_CastleTown = helperFunctions.RegisterMusicFile(BGM_CASTLETOWN);


		LoadingFunctionProxy();
		
		ModPath = path;
		HelperFunctionsGlobal = helperFunctions;
		WriteData((char*)0x719292, (char)3);
		WriteData((char*)0x71928B, (char)0);
		WriteData((char*)0x729514, (char)29);
		WriteData((char*)0x729512, (char)0);
		WriteCall((int*)0x4237D5, LoadingFunctionProxy);
		WriteData<1>((int*)0x004237DD, 0xEB);
		WriteData<1>((int*)0x004237DE, 0xD4);
		*(float*)0x7E9624 = -10000;
		INIT_LevelTask();


		if (CurrentLevel = LevelIDs_E)
		{
			
			STARTPOSITIONS_CastleTown();
			INIT_Objects();
	
		}

}
	__declspec(dllexport) void __cdecl OnFrame()
	{
		ANIM_Water();

		if (CurrentLevel == LevelIDs_E)
		{
			initCTmusic();
			
		}
	}
	
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

}

//450.62073, -21.966679, -2481.5488

