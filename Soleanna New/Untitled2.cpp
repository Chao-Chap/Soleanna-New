#include "pch.h"
#include "SADXModLoader.h"


Loop untitled2_entries[] = {
	{ 0x141, 0x872A, 21.23161f, { 142.42683f, 926.35419f, -620.56903f } },
	{ 0xFEBF, 0x8817, 20.81023f, { 129.76347f, 924.63477f, -603.61426f } },
	{ 0xF840, 0x8819, 20.07984f, { 117.71808f, 920.36322f, -587.19086f } },
	{ 0xF170, 0x887A, 20.27109f, { 106.42713f, 913.78131f, -571.94641f } },
	{ 0xEC56, 0x8C14, 19.29087f, { 95.84674f, 904.37183f, -557.44006f } },
	{ 0xE8B6, 0x8F25, 18.01091f, { 86.53287f, 893.00116f, -544.94617f } },
	{ 0xE5D2, 0x913B, 16.56778f, { 78.62440f, 881.34174f, -533.72534f } },
	{ 0xE27E, 0x95E0, 17.08727f, { 71.79079f, 869.53455f, -524.32410f } },
	{ 0xDDE1, 0x9CF5, 21.41490f, { 65.79295f, 855.69904f, -516.28796f } },
	{ 0xD8EC, 0xA421, 27.84012f, { 60.56744f, 836.32935f, -508.79749f } },
	{ 0xD5DD, 0xAA90, 29.43289f, { 55.54147f, 809.79340f, -502.04062f } },
	{ 0xD4E0, 0xAF97, 29.68126f, { 51.74648f, 781.06122f, -496.90692f } },
	{ 0xD586, 0xB22B, 33.41853f, { 48.87233f, 751.81860f, -492.71332f } },
	{ 0xD62E, 0xB3FE, 33.76573f, { 45.49789f, 718.86865f, -488.27350f } },
	{ 0xD5AF, 0xB609, 33.65781f, { 42.91375f, 685.41486f, -484.49329f } },
	{ 0xD532, 0xB795, 36.13643f, { 40.82645f, 651.96454f, -481.40009f } },
	{ 0xD604, 0xB86B, 64.37567f, { 38.67317f, 615.99091f, -478.73499f } },
	{ 0xD6DC, 0xB96D, 63.20673f, { 35.00273f, 551.91974f, -473.67133f } },
	{ 0xD3F4, 0xBA50, 62.80392f, { 32.05652f, 488.88892f, -469.99347f } },
	{ 0xD06C, 0xBBFD, 62.10571f, { 30.28740f, 426.18652f, -466.89313f } },
	{ 0xCE98, 0xBE29, 54.83462f, { 29.14446f, 364.09805f, -465.98004f } },
	{ 0xC9E1, 0xBE85, 50.47197f, { 28.76895f, 309.26715f, -465.46375f } },
	{ 0xC83C, 0xBEA4, 46.42065f, { 28.87427f, 258.79642f, -465.12628f } },
	{ 0xCDB7, 0xBF46, 39.67818f, { 28.84757f, 212.37698f, -464.79156f } },
	{ 0xD0FB, 0xBB04, 26.32256f, { 28.69178f, 172.69933f, -464.66034f } },
	{ 0xD0DC, 0xACA6, 23.41516f, { 26.93817f, 146.50722f, -462.71735f } },
	{ 0xD1C3, 0x9C98, 24.26101f, { 22.16176f, 124.14005f, -457.70084f } },
	{ 0xD458, 0x8C80, 25.22374f, { 15.89310f, 101.96497f, -450.11362f } },
	{ 0xDA22, 0x8085, 26.44046f, { 6.28582f, 81.95452f, -438.13367f } },
	{ 0xDF82, 0x7B7C, 25.85978f, { -5.28644f, 64.40754f, -422.09360f } },
	{ 0xE47A, 0x7967, 25.72761f, { -17.82402f, 50.04427f, -404.62265f } },
	{ 0xEA2D, 0x77B3, 25.28547f, { -31.57419f, 39.17178f, -385.79099f } },
	{ 0xF04E, 0x7566, 24.73757f, { -45.88536f, 32.40239f, -366.07498f } },
	{ 0xF724, 0x7295, 23.77392f, { -60.21847f, 30.04774f, -346.05087f } },
	{ 0xFDAC, 0x6EE4, 23.42086f, { -73.27288f, 32.35665f, -326.31638f } },
	{ 0x2BE, 0x698D, 23.48789f, { -85.43105f, 38.85209f, -307.38162f } },
	{ 0x75C, 0x635E, 23.45334f, { -96.49366f, 49.58266f, -289.65723f } },
	{ 0xBC0, 0x5D2A, 23.42594f, { -105.77255f, 64.14546f, -273.78632f } },
	{ 0xE31, 0x55D6, 23.65905f, { -113.09712f, 81.92496f, -260.40668f } },
	{ 0xD8E, 0x4CA4, 24.22894f, { -118.12466f, 102.34912f, -249.57486f } },
	{ 0xD1F, 0x4433, 23.47537f, { -120.13223f, 125.32478f, -242.14987f } },
	{ 0x1107, 0x3D52, 23.53076f, { -119.12506f, 148.44014f, -238.18011f } },
	{ 0x1396, 0x355F, 23.55300f, { -115.14652f, 171.62201f, -237.49539f } },
	{ 0xD7B, 0x2E65, 23.51445f, { -108.00293f, 193.91328f, -240.10532f } },
	{ 0x5AA, 0x297B, 23.72140f, { -98.23219f, 214.53424f, -245.78320f } },
	{ 0xB7D, 0x1D99, 51.53069f, { -86.08015f, 233.02948f, -254.32480f } },
	{ 0x1858, 0x900, 23.59375f, { -101.69685f, 251.11974f, -299.97864f } },
	{ 0x18D4, 0xFB45, 23.51582f, { -85.04114f, 261.17062f, -313.32898f } },
	{ 0x12B7, 0xF6A2, 23.53922f, { -67.42427f, 266.79080f, -327.85666f } },
	{ 0xD60, 0xF1CC, 23.55280f, { -49.32619f, 267.83182f, -342.87234f } },
	{ 0x8D1, 0xEC9E, 23.51761f, { -31.33949f, 264.52203f, -357.71344f } },
	{ 0x524, 0xE6CC, 23.54243f, { -14.12537f, 256.82788f, -371.76877f } },
	{ 0x1B5, 0xE11A, 23.94802f, { 1.84743f, 245.03683f, -384.42133f } },
	{ 0xFC85, 0xDB7B, 23.92429f, { 16.29362f, 229.32480f, -395.28168f } },
	{ 0xF4E3, 0xD640, 23.35546f, { 27.89933f, 210.05182f, -403.41995f } },
	{ 0xED49, 0xD0F2, 23.60955f, { 36.83282f, 189.01514f, -408.22916f } },
	{ 0xEAC5, 0xC926, 23.51637f, { 43.52473f, 166.46797f, -410.29178f } },
	{ 0xEEC6, 0xC0E0, 23.48863f, { 46.93536f, 143.25050f, -408.76318f } },
	{ 0xF207, 0xB9CB, 23.49560f, { 47.24151f, 120.25401f, -403.98999f } },
	{ 0xF387, 0xB2F4, 24.28198f, { 44.71589f, 98.32877f, -395.93094f } },
	{ 0xF681, 0xAC15, 24.35584f, { 38.92003f, 77.05568f, -385.75851f } },
	{ 0xF977, 0xA4F0, 23.53131f, { 31.34245f, 60.00610f, -370.10287f } },
	{ 0xFBC0, 0x9E7F, 23.95313f, { 21.46220f, 46.21069f, -353.79980f } },
	{ 0xFDCD, 0x98E8, 24.27365f, { 9.99425f, 35.25962f, -335.84674f } },
	{ 0xFF36, 0x9591, 24.41882f, { -2.49133f, 26.95604f, -316.75824f } },
	{ 0xC, 0x952B, 24.47431f, { -15.61315f, 19.42549f, -297.59088f } },
	{ 0x48, 0x9528, 24.39701f, { -28.93521f, 11.88635f, -278.49438f } },
	{ 0x28, 0x94D1, 0.00000f, { -41.99683f, 4.65082f, -259.20047f } }
};

LoopHead untitled2 = { 0, LengthOfArray<int16_t>(untitled2_entries), 1904.92944f, untitled2_entries, (ObjectFuncPtr)0x4BB1F0 };

LoopHead* untitled2_list[] = {
  &untitled2,
 nullptr
};