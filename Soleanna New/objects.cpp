#include "pch.h"

void Objects_Init(const HelperFunctions& helperFunctions)
{
	// Add a new act to Red Mountain set/cam files (originally 0x210)
	SetDataThings[LevelIDs_RedMountain] = 0x3210;
	CamDataThings[LevelIDs_RedMountain] = 0x3210;

	// Compatibility with DC Conversion
	helperFunctions.ReplaceFile("system\\SET0500S_DC.bin", "system\\SETTPJ00S.bin");
	helperFunctions.ReplaceFile("system\\SET0501S_DC.bin", "system\\SETTPJ01S.bin");
	helperFunctions.ReplaceFile("system\\SET0501E_DC.bin", "system\\SETTPJ01E.bin");
	helperFunctions.ReplaceFile("system\\SET0502K_DC.bin", "system\\SETTPJ02K.bin");


}