#include "pch.h"
#include "Header.h"

Loop SPLINEKDV_entries[] = {
	{ 0xEBE2u, 0xA135u, 20.20834f, -742.63416f, -56.60223f, -447.34583f },
	{ 0xEA79u, 0x9F64u, 20.46309f, -753.96460f, -55.51976f, -464.04391f },
	{ 0xE7C9u, 0x99BFu, 16.40207f, -765.94745f, -52.41619f, -480.33862f },
	{ 0xE3A4u, 0x94C9u, 14.94451f, -774.84808f, -47.09314f, -493.04578f },
	{ 0xDD23u, 0x92DAu, 14.27638f, -782.21094f, -39.44874f, -503.56671f },
	{ 0xD61Fu, 0x920Fu, 14.43314f, -788.07581f, -29.48298f, -511.93939f },
	{ 0xCFBBu, 0x93C3u, 15.20533f, -792.51617f, -17.30241f, -518.28229f },
	{ 0xCAC2u, 0x992Cu, 33.47476f, -795.67163f, -3.12669f, -522.78717f },
	{ 0xCCE1u, 0xB3B9u, 44.42342f, -799.79907f, 29.56590f, -528.67944f },
	{ 0xE0DFu, 0xBF4Au, 208.49979f, -801.05725f, 73.93510f, -530.47687f },
	{ 0xEF0Au, 0xC000u, 0.00000f, -801.05725f, 282.43488f, -530.47681f }
};

LoopHead SPLINEKDV = { 0, LengthOfArray<int16_t>(SPLINEKDV_entries), 402.33081f, SPLINEKDV_entries, (ObjectFuncPtr)0x4BB1F0 };
LoopHead* splinekdv_list[] = {
  &SPLINEKDV,
 nullptr
};