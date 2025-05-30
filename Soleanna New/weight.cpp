#include "pch.h"
#include "SADXModLoader.h"
#include "IniFile.hpp"
#include "ModelInfo.h"
#include "FunctionHook.h"
#include "UsercallFunctionHandler.h"
#include <map>
#include <vector>
#include "weights.h"

using std::map;
using std::vector;
using std::string;



const intptr_t sonicWeldPointers[] = {
	0x49AB7E,
	0x49ABAC,
	0x49ACB6,
	0x7D27BA,
	0x7D30A0,
	0x7D58B1,
	0x7D5D21
};

const intptr_t tailsWeldPointers[] = {
	0x461896,
	0x7D2867,
	0x7D3149,
	0x7D595A,
	0x7D5DB5
};

const intptr_t knucklesWeldPointers[] = {
	0x47A89E,
	0x7D2914,
	0x7D31F6,
	0x7D33D3,
	0x7D5A01
};

const intptr_t amyWeldPointers[] = {
	0x48AD0B,
	0x7D29C1,
	0x7D5AB6
};

const intptr_t gammaWeldPointers[] = {
	0x483630
};

const intptr_t bigWeldPointers[] = {
	0x490C14,
	0x7D2B04,
	0x7D329B,
	0x7D5BF4
};

const intptr_t metalWeldPointers[] = {
	0x49ACC2
};

map<int, CharInfo> charInfos = {
	{
		Characters_Sonic,
		{
			"\\models\\sonic\\",
			"___SONIC_OBJECTS",
			79,
			"___SONIC_ACTIONS",
			149,
			arrayptrandlengthT(sonicWeldPointers, int)
		}
	},
	{
		Characters_Tails,
		{
			"\\models\\tails\\",
			"___MILES_OBJECTS",
			72,
			"___MILES_ACTIONS",
			114,
			arrayptrandlengthT(tailsWeldPointers, int)
		}
	},
	{
		Characters_Knuckles,
		{
			"\\models\\knuckles\\",
			"___KNUCKLES_OBJECTS",
			74,
			"___KNUCKLES_ACTIONS",
			90,
			arrayptrandlengthT(knucklesWeldPointers, int)
		}
	},
	{
		Characters_Amy,
		{
			"\\models\\amy\\",
			"___AMY_OBJECTS",
			39,
			"___AMY_ACTIONS",
			80,
			arrayptrandlengthT(amyWeldPointers, int)
		}
	},
	{
		Characters_Gamma,
		{
			"\\models\\gamma\\",
			"___E102_OBJECTS",
			28,
			"___E102_ACTIONS",
			78,
			arrayptrandlengthT(gammaWeldPointers, int)
		}
	},
	{
		Characters_Big,
		{
			"\\models\\big\\",
			"___BIG_OBJECTS",
			44,
			"___BIG_ACTIONS",
			90,
			arrayptrandlengthT(bigWeldPointers, int)
		}
	},
	{
		Characters_MetalSonic,
		{
			"\\models\\metalsonic\\",
			"___SONIC_OBJECTS",
			79,
			"___SONIC_ACTIONS",
			149,
			arrayptrandlengthT(metalWeldPointers, int)
		}
	}
};

const BasicWeightFuncs* weightFuncs;

NJS_MATRIX matrix;
void ProcessWeights(CharObj2* a3, NJS_OBJECT*& object, NJS_MOTION* motion, float frame)
{
	map<NJS_OBJECT*, ModelWeightInfo>* weightinfo = (map<NJS_OBJECT*, ModelWeightInfo>*)a3->AnimationThing.WeldInfo;
	switch (a3->AnimationThing.field_2)
	{
	case 0:
		for (auto& nodeweights : *weightinfo)
			weightFuncs->Init(nodeweights.second.weights, nodeweights.first);
		a3->AnimationThing.field_2 = 1;
		break;
	case 1:
	{
		NJS_ACTION action = { object, motion };
		auto nodeweights = weightinfo->find(object);
		if (nodeweights != weightinfo->end())
		{
			weightFuncs->Apply(nodeweights->second.weights, &action, frame);
			{
				int* nodeidx = &nodeweights->second.rightHandNode;
				int* dir = &nodeweights->second.rightHandDir;
				for (int i = 0; i < 6; i++)
					if (*nodeidx != -1)
					{
						NJS_VECTOR pos{};
						NJS_VECTOR norm{};
						(&norm.x)[dir[i]] = 1;
						SetInstancedMatrix(nodeidx[i], matrix);
						njCalcPoint(matrix, &pos, &a3->SoManyVectors[i]);
						njCalcVector(matrix, &norm, &a3->SoManyVectors[i + 6]);
					}
			}
		}
	}
	break;
	default:
		for (auto& nodeweights : *weightinfo)
			weightFuncs->DeInit(nodeweights.second.weights, nodeweights.first);
		break;
	}
}

void __cdecl ProcessVertexWelds_Check_(EntityData1* a1, EntityData2* a2, CharObj2* a3)
{
	NJS_OBJECT* object;
	NJS_MOTION* motion;
	if (a3->AnimationThing.State == 2)
	{
		object = a3->AnimationThing.action->object;
		motion = a3->AnimationThing.action->motion;
	}
	else
	{
		object = a3->AnimationThing.AnimData[(unsigned __int16)a3->AnimationThing.Index].Animation->object;
		motion = a3->AnimationThing.AnimData[(unsigned __int16)a3->AnimationThing.Index].Animation->motion;
	}
	if (MetalSonicFlag)
	{
		if (object == SONIC_OBJECTS[0])
			object = SONIC_OBJECTS[68];
		else if (object == SONIC_OBJECTS[66])
			object = SONIC_OBJECTS[69];
		else if (object == SONIC_OBJECTS[67])
			object = SONIC_OBJECTS[70];
	}
	ProcessWeights(a3, object, motion, a3->AnimationThing.Frame);
}

FunctionHook<void, EntityData1*, EntityData2*, CharObj2*> ProcessVertexWelds_h(ProcessVertexWelds);


UsercallFuncVoid(mr_join_vertex_init, (PL_JOIN_VERTEX* join_vtx_p), (join_vtx_p), 0x51A7A0, rEAX);
void __cdecl mr_join_vertex_init_Check(PL_JOIN_VERTEX* join_vtx_p)
{
	for (auto& ch : charInfos)
		if ((void*)join_vtx_p == &ch.second.modelWeights)
		{
			for (auto& nodeweights : ch.second.modelWeights)
				weightFuncs->Init(nodeweights.second.weights, nodeweights.first);
			return;
		}
	mr_join_vertex_init.Original(join_vtx_p);
}

UsercallFuncVoid(mr_join_vertex_exec, (Uint32 obj_num, PL_JOIN_VERTEX* join_vtx_p, NJS_ACTION* act_p, NJS_MATRIX* mat_p, Float frame), (obj_num, join_vtx_p, act_p, mat_p, frame), 0x52EBA0, rEAX, rECX, stack4, stack4, stack4);
void __cdecl mr_join_vertex_exec_Check(Uint32 obj_num, PL_JOIN_VERTEX* join_vtx_p, NJS_ACTION* act_p, NJS_MATRIX* mat_p, Float frame)
{
	for (auto& ch : charInfos)
		if ((void*)join_vtx_p == &ch.second.modelWeights)
		{
			auto nodeweights = ch.second.modelWeights.find(act_p->object);
			if (nodeweights != ch.second.modelWeights.end())
				weightFuncs->Apply(nodeweights->second.weights, act_p, frame);
			return;
		}

	mr_join_vertex_exec.Original(obj_num, join_vtx_p, act_p, mat_p, frame);
}

UsercallFuncVoid(mr_join_vertex_end, (PL_JOIN_VERTEX* join_vtx_p), (join_vtx_p), 0x52ED50, rEAX);
void __cdecl mr_join_vertex_end_Check(PL_JOIN_VERTEX* join_vtx_p)
{
	for (auto& ch : charInfos)
		if ((void*)join_vtx_p == &ch.second.modelWeights)
		{
			for (auto& nodeweights : ch.second.modelWeights)
				weightFuncs->DeInit(nodeweights.second.weights, nodeweights.first);
			return;
		}
	mr_join_vertex_end.Original(join_vtx_p);
}

UsercallFuncVoid(ec_join_vertex_end, (PL_JOIN_VERTEX* join_vtx_p), (join_vtx_p), 0x51A8D0, rEAX);
void __cdecl ec_join_vertex_end_Check(PL_JOIN_VERTEX* join_vtx_p)
{
	for (auto& ch : charInfos)
		if ((void*)join_vtx_p == &ch.second.modelWeights)
		{
			for (auto& nodeweights : ch.second.modelWeights)
				weightFuncs->DeInit(nodeweights.second.weights, nodeweights.first);
			return;
		}
	ec_join_vertex_end.Original(join_vtx_p);
}

std::pair<string, string> nodeKeys[] = {
	{ "RightHandPosition", "RightHandDirection" },
	{ "LeftHandPosition", "LeftHandDirection" },
	{ "RightFootPosition", "RightFootDirection" },
	{ "LeftFootPosition", "LeftFootDirection" },
	{ "User0Position", "User0Direction" },
	{ "User1Position", "User1Direction" }
};

