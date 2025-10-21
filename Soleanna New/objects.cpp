#include "pch.h"
#include "NPC.h"
#include "o_skybox.h"

//	Town Square Textures:

NJS_TEXNAME TEX_CastleTown[500] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown = { arrayptrandlength(TEX_CastleTown) };

NJS_TEXNAME TEX_FOREST[100] = { 0 };
NJS_TEXLIST TEXLIST_FOREST = { arrayptrandlength(TEX_FOREST) };

NJS_TEXNAME TEX_City[640] = { 0 };
NJS_TEXLIST TEXLIST_City = { arrayptrandlength(TEX_City) };

NJS_TEXNAME TEX_CastleTown_Sky[5] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown_Sky = { arrayptrandlength(TEX_CastleTown_Sky) };

NJS_TEXNAME TEX_CastleTown_Sky_Night[5] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown_Sky_Night = { arrayptrandlength(TEX_CastleTown_Sky_Night) };

NJS_TEXNAME TEX_CastleTown_Sky_Eve[5] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown_Sky_Eve = { arrayptrandlength(TEX_CastleTown_Sky_Eve) };


NJS_TEXNAME TEX_NPC_SONICMAN[18];
NJS_TEXLIST  TEXLIST_NPC_SONICMAN = { arrayptrandlengthT(TEX_NPC_SONICMAN, Uint32) };




NJS_TEXNAME TEX_NPC_SOLDIER[10];
NJS_TEXLIST  TEXLIST_NPC_SOLDIER = { arrayptrandlengthT(TEX_NPC_SOLDIER, Uint32) };


NJS_TEXNAME TEX_NPC_PRIEST[10];
NJS_TEXLIST  TEXLIST_NPC_PRIEST = { arrayptrandlengthT(TEX_NPC_PRIEST, Uint32) };

NJS_TEXNAME TEX_NPC_WOMAN1[10];
NJS_TEXLIST  TEXLIST_NPC_WOMAN1 = { arrayptrandlengthT(TEX_NPC_WOMAN1, Uint32) };

NJS_TEXNAME TEX_CastleTown_Water[14] = { 0 };
NJS_TEXLIST TEXLIST_CastleTown_Water = { arrayptrandlength(TEX_CastleTown_Water) };

NJS_TEXNAME TEX_BENCH[18];
NJS_TEXLIST  TEXLIST_BENCH = { arrayptrandlengthT(TEX_BENCH, Uint32) };
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
	{ 2, 2, 1, 1000000.0f, 0, NPC_SOLDIER_Event, "SOLDIER"}, // ID 30
	{ 2, 2, 1, 1000000.0f, 0, NPC_SOLDIER2_Event, "SOLDIER2"}, // ID 31
	{ 2, 2, 1, 1000000.0f, 0, NPC_SOLDIER3_Event, "SOLDIER3"}, // ID 32
	{ 2, 2, 1, 1000000.0f, 0, NPC_SOLDIER4_Event, "SOLDIER4"}, // ID 33
	{ 2, 2, 1, 1000000.0f, 0, NPC_SOLDIER5_Event, "SOLDIER5"}, // ID 34
	{ 2, 2, 1, 1000000.0f, 0, NPC_Priest_Event, "Priest1"}, // ID 35
	{ 2, 2, 1, 1000000.0f, 0, NPC_Priest2_Event, "Priest2"}, // ID 36
	{ 2, 2, 1, 1000000.0f, 0, NPC_Priest3_Event, "Priest3"}, // ID 37
	{ 2, 2, 1, 1000000.0f, 0, NPC_Woman1_Event, "Woman1"}, // ID 38
	{ 2, 2, 1, 1000000.0f, 0, NPC_Woman2_Event, "Woman2"}, // ID 39
	{ 2, 2, 1, 1000000.0f, 0, BENCHExec, "BENCH"}, // ID 40
};

_OBJ_ITEMTABLE OBJECTLIST_CastleTown = { LengthOfArray(OBJECTLIST_CastleTown_Entries), 0, OBJECTLIST_CastleTown_Entries };



_OBJ_ITEMENTRY OBJECTLIST_NewCity_Entries[] = {
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
	{ 2, 2, 1, 1000000.0f, 0, NPC_CITYSOLDIER_Event, "Soldier"}, // ID 29
	{ 2, 2, 1, 1000000.0f, 0, NPC_PriestCity1_Event, "Priest"}, // ID 30
	{ 2, 2, 1, 1000000.0f, 0, NPC_PriestCity2_Event, "Priest"}, // ID 31
	{ 2, 2, 1, 1000000.0f, 0, NPC_WomanCity1_Event, "Woman"}, // ID 32
	{ 2, 2, 1, 1000000.0f, 0, NPC_WomanCity2_Event, "Woman"}, // ID 33
	{ 2, 2, 1, 1000000.0f, 0, BENCHExec, "BENCH"}, // ID 34
};

_OBJ_ITEMTABLE OBJECTLIST_NewCity = { LengthOfArray(OBJECTLIST_NewCity_Entries), 0, OBJECTLIST_NewCity_Entries };





//	Texture List:

TEX_PVMTABLE TEXTURELIST_CastleTown[] = {

	{ "OBJ_HIGHWAY",(TexList*)0x26703F0},
	{ "CastleTown_Water", &TEXLIST_CastleTown_Water },
	{ "CastleTown_Sky", &TEXLIST_CastleTown_Sky },
	{ "CastleTown_Sky_Night", &TEXLIST_CastleTown_Sky_Night },
	{ "CastleTown_Sky_Eve", &TEXLIST_CastleTown_Sky_Eve },

	{ "Bench", &TEXLIST_BENCH},

	{"NPC_SONICMANTEX",(&TEXLIST_NPC_SONICMAN)},
	{"SOLDIER",(&TEXLIST_NPC_SOLDIER)},
	{"PRIEST",(&TEXLIST_NPC_PRIEST)},
	{"WOMAN",(&TEXLIST_NPC_WOMAN1)},
	{ "PEN", (TexList*)0x92D39C }, // Penguin
	{ "LION", (TexList*)0x944094 }, // Lion
	{ "MOGU", (TexList*)0x93ECEC }, // Mole
	{ "ZOU", (TexList*)0x94160C }, // Elephant
	{ "GORI", (TexList*)0x945964 }, // Gorilla
	{ "SUPI_SUPI", (TexList*)0x96F518 }, // Spinner
	{ "UNI_A_UNIBODY", (TexList*)0x96CB5C }, // Unidus Black
	{ "TOGEBALL_TOGEBALL", (TexList*)0x96BC54 }, // Spiked Ball
	



	
	{ 0 }

}; TEX_PVMTABLE TEXTURELIST_Forest[] = {

	{ "CastleTown_Water", &TEXLIST_CastleTown_Water },
	{ "CastleTown_Sky", &TEXLIST_CastleTown_Sky },
	{ "CastleTown_Sky_Night", &TEXLIST_CastleTown_Sky_Night },
	{ "CastleTown_Sky_Eve", &TEXLIST_CastleTown_Sky_Eve },

	{ "Bench", &TEXLIST_BENCH},


	{"SOLDIER",(&TEXLIST_NPC_SOLDIER)},
	{"PRIEST",(&TEXLIST_NPC_PRIEST)},
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
	Load_NPC_SOLDIER();
	LOAD_CastleTown_Skybox();
	Load_NPC_Priest();
	Load_NPC_Woman1();
	LOAD_Bench();
}


//	Init Objects:

void INIT_Objects()
{
	ListofPvmList[LevelIDs_Soleanna_Hub ] = TEXTURELIST_CastleTown;
	objItemTable[LevelIDs_Soleanna_Hub * 8] = &OBJECTLIST_CastleTown;
	objItemTable[LevelIDs_Soleanna_Hub * 8 + 0] = &OBJECTLIST_CastleTown;

	objItemTable[LevelIDs_Soleanna_Hub * 8 + 1] = &OBJECTLIST_FOREST;
	
	objItemTable[LevelIDs_Soleanna_Hub * 8 + 2] = &OBJECTLIST_NewCity;
	LOAD_Objects();


}