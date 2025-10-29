#pragma once

extern NJS_TEXLIST TEXLIST_CastleTown;
extern NJS_TEXLIST TEXLIST_wvo;
extern NJS_TEXLIST TEXLIST_FOREST;
extern NJS_TEXLIST TEXLIST_City;
extern NJS_TEXLIST TEXLIST_SOLDIER;
extern NJS_TEXLIST TEXLIST_PRIEST;
extern NJS_TEXLIST TEXLIST_WOMAN1;
extern NJS_TEXLIST TEXLIST_CastleTown_Sky;
extern NJS_TEXLIST TEXLIST_EAGLE;
extern NJS_TEXLIST TEXLIST_BENCH;
extern NJS_TEXLIST TEXLIST_CastleTown_Sky_Night;
extern NJS_TEXLIST TEXLIST_CastleTown_Sky_Eve;
extern NJS_TEXNAME TEX_CastleTown_Sky[5];
extern NJS_TEXNAME TEX_CastleTown_Sky_Night[5];
extern NJS_TEXNAME TEX_CastleTown_Sky_Eve[5];
extern NJS_TEXNAME TEX_CastleTown_Water[14];
extern NJS_TEXLIST TEXLIST_CastleTown_Water;
extern _OBJ_ITEMTABLE OBJECTLIST_FOREST;

PointerInfo pointers[];
void loadEagle();
extern ObjectList StationSquareObjectListNew;
ObjectListEntry StationSquareObjectListNew_list[];
void Init_newSSset();
void __cdecl Eagle_Init(task* obj);
void INIT_Objects();
void INIT_WVOObjects();
void LOAD_Objects();

