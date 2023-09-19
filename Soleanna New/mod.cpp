#include "pch.h"
#include "SADXModLoader.h"
#include "Header.h"

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		WriteData(reinterpret_cast<LoopHead***>(0x91A864), static_cast<LoopHead**>(untitled2_list));
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}