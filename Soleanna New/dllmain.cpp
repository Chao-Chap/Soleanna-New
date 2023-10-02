#include "pch.h"
#include "SADXModLoader.h"
#include "Header.h"
#include <vector>
std::vector<NJS_MATERIAL*> castletown_watermats;
#define castletown_waterfirst (1108)
#define castletown_waterlast (1117)
int castletown_watercur = castletown_waterfirst;
#define castletown_waterdelay (2)
int castletown_waterframe = 0;
#include <vector>
std::vector<NJS_MATERIAL*> waveocean_watermats;
#define waveocean_waterfirst (149)
#define waveocean_waterlast (158)
int waveocean_watercur = waveocean_waterfirst;
#define waveocean_waterdelay (2)
int waveocean_waterframe = 0;

std::vector<NJS_MATERIAL*> newcity_watermats;
#define newcity_waterfirst (625)
#define newcity_waterlast (634)
int newcity_watercur = castletown_waterfirst;
#define newcity_waterdelay (2)
int newcity_waterframe = 0;
// or #include "stdafx.h" for previous Visual Studio versions

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{

		WriteData(reinterpret_cast<LoopHead***>(0x91A864), static_cast<LoopHead**>(untitled2_list));
		ECoast1_Actchg = { 4265.338, 55, 6954.677 };
		HMODULE hmod = GetModuleHandle(L"ADV00MODELS");
		LandTable** landarr = (LandTable**)GetProcAddress(hmod, "___LANDTABLESS");
		LandTable* land = landarr[3];

		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == castletown_waterfirst)
						castletown_watermats.push_back(&mdl->mats[j]);

		}
		land = GeoLists[LevelIDs_EmeraldCoast * 8 + 0];
		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == waveocean_waterfirst)
						waveocean_watermats.push_back(&mdl->mats[j]);
		}

		hmod = GetModuleHandle(L"ADV01MODELS");
		landarr = (LandTable**)GetProcAddress(hmod, "___LANDTABLESS");
		land = landarr[0];

		for (int i = 0; i < land->COLCount; ++i)
		{
			NJS_MODEL_SADX* mdl = land->Col[i].Model->basicdxmodel;
			if (mdl && mdl->mats)
				for (int j = 0; j < mdl->nbMat; ++j)
					if (mdl->mats[j].attr_texId == newcity_waterfirst)
						newcity_watermats.push_back(&mdl->mats[j]);


		}
	}
			__declspec(dllexport) void __cdecl OnFrame()
			{
				if (castletown_waterframe == castletown_waterdelay)
				{
					castletown_waterframe = 0;
					if (castletown_watercur == castletown_waterlast)
						castletown_watercur = castletown_waterfirst;
					else
						++castletown_watercur;
					for (auto mat : castletown_watermats)
						mat->attr_texId = castletown_watercur;
				}
				else
					++castletown_waterframe;
				
				if (waveocean_waterframe == waveocean_waterdelay)
					{
						waveocean_waterframe = 0;
						if (waveocean_watercur == waveocean_waterlast)
							waveocean_watercur = waveocean_waterfirst;
						else
							++waveocean_watercur;
						for (auto mat : waveocean_watermats)
							mat->attr_texId = waveocean_watercur;
					}
					else
						++waveocean_waterframe;
				
					
					if (newcity_waterframe == newcity_waterdelay)
					{
						newcity_waterframe = 0;
						if (newcity_watercur == newcity_waterlast)
							newcity_watercur = newcity_waterfirst;
						else
							++newcity_watercur;
						for (auto mat : newcity_watermats)
							mat->attr_texId = newcity_watercur;
					}
					else
						++newcity_waterframe;

				
			}
	
	
	
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

}
