#include "pch.h"
#include "NPC.h"
#include "o_skybox.h"

//	Town Square Textures:

NJS_TEXNAME TEX_CastleTown[500] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown = { arrayptrandlength(TEX_CastleTown) };
NJS_TEXNAME TEX_CastleTown_Sky[5] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown_Sky = { arrayptrandlength(TEX_CastleTown_Sky) };

NJS_TEXNAME TEX_NPC_SONICMAN[18];
NJS_TEXLIST  TEXLIST_NPC_SONICMAN = { arrayptrandlengthT(TEX_NPC_SONICMAN, Uint32) };

NJS_TEXNAME TEX_CastleTown_Water[14] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown_Water = { arrayptrandlength(TEX_CastleTown_Water) };
//	Object List:

_OBJ_ITEMENTRY OBJECTLIST_CastleTown_Entries[] = {
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x450370, "O RING" }, // ID 0
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x79B2F0, "O RING GROUP" }, // ID 1
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4C30, "O SPRING GROUND" }, // ID 2
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4E50, "O SPRING AIR" }, // ID 3
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x79F860, "O SPRING TRIPLE" }, // ID 4
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4450, "O DASH PANEL" }, // ID 5
	{ 14, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A26F0, "O DASH RING" }, // ID 6
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D6F10, "O ITEMBOX" }, // ID 7
	{ 15, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4C07D0, "O ITEMBOX AIR" }, // ID 8
	{ 15, 6, 1, 1000000.0f, 0, (TaskFuncPtr)0x44F540, "O CHECKPOINT" }, // ID 9
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x46B170, "O CAPSULE" }, // ID 10
	{ 3, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4A3420, "O EMERALD SHARD" }, // ID 11
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A1AA0, "O TIKAL" }, // ID 12
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A9140, "O TIKAL THIS WAY" }, // ID 13
	{ 10, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A2B60, "O WEED" }, // ID 14
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4850, "C PUSHWALL" }, // ID 15
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4700, "C SPHERE" }, // ID 16
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4770, "C CYLINDER" }, // ID 17
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D47E0, "C CUBE" }, // ID 18
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4B70, "C LEDGE" }, // ID 19
	{ 2, 0, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4E10, "C NOT UNDERWATER" }, // ID 20
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B0DF0, "E SPINNER A" }, // ID 21
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B0F40, "E SPINNER B" }, // ID 22
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B1090, "E SPINNER C" }, // ID 23
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF190, "E UNIDUS A" }, // ID 24
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF500, "E UNIDUS B" }, // ID 25
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x615200, "O HW BELL" }, // ID 26
	{ 2, 0, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4BE0, "BIGWJUMP" }, // ID 27
	{ 2, 2, 0, 1000000.0f, 0, (TaskFuncPtr)0x640850, "SCENE CHANGE" }, // ID 28
	{ 2, 2, 1, 1000000.0f, 0, NPC_SONICMAN_Event, "SONICMANNPC"}, // ID 29

};

_OBJ_ITEMTABLE OBJECTLIST_CastleTown = { LengthOfArray(OBJECTLIST_CastleTown_Entries), 0, OBJECTLIST_CastleTown_Entries };

//	Texture List:

TEX_PVMTABLE TEXTURELIST_CastleTown[] = {

	{ "OBJ_HIGHWAY",(TexList*)0x26703F0},
	{ "CastleTown_Water", &TEXLIST_CastleTown_Water },
	{ "CastleTown_Sky", &TEXLIST_CastleTown_Sky },

	{"NPC_SONICMANTEX",(&TEXLIST_NPC_SONICMAN)},
	{ "PEN", (TexList*)0x92D39C }, // Penguin
	{ "LION", (TexList*)0x944094 }, // Lion
	{ "MOGU", (TexList*)0x93ECEC }, // Mole
	{ "ZOU", (TexList*)0x94160C }, // Elephant
	{ "GORI", (TexList*)0x945964 }, // Gorilla
	{ "SUPI_SUPI", (TexList*)0x96F518 }, // Spinner
	{ "UNI_A_UNIBODY", (TexList*)0x96CB5C }, // Unidus Black
	{ "TOGEBALL_TOGEBALL", (TexList*)0x96BC54 }, // Spiked Ball
	



	
	{ 0 }
};


//	Load Objects:

void LOAD_Objects()
{
	Load_NPC_SONICMAN();
	LOAD_CastleTown_Skybox();
}


//	Init Objects:

void INIT_Objects()
{
	ListofPvmList[LevelIDs_E] = TEXTURELIST_CastleTown;


	objItemTable[LevelIDs_E * 8 + 0] = &OBJECTLIST_CastleTown;

	LOAD_Objects();


}