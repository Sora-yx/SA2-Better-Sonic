#include "stdafx.h"

Trampoline* Sonic_Main_t;

void RestorePhysic(CharObj2Base* co2) {
	co2->PhysData.CollisionSize = PhysicsArray[0].CollisionSize;
	co2->PhysData.RippleSize = PhysicsArray[0].RippleSize;
	co2->PhysData.FloorGrip = PhysicsArray[0].FloorGrip;
	co2->PhysData.YOff = PhysicsArray[0].YOff;
	return;
}

//Apply Somersault physics/collision 
void SetPlayerSomersaultPhysics(CharObj2Base* co2, EntityData1* v1) {
	co2->PhysData.CollisionSize = PhysicsArray[0].CollisionSize * 0.4000000059604645;
	co2->PhysData.RippleSize = PhysicsArray[0].RippleSize * 0.4000000059604645;
	co2->PhysData.FloorGrip = PhysicsArray[0].FloorGrip * 0.4000000059604645;
	co2->PhysData.YOff = PhysicsArray[0].YOff * 0.4000000059604645;
	v1->Collision->CollisionArray->push &= ~0x4000u;
	return;
}


void Sonic_Main_r(ObjectMaster* obj)
{
	ObjectFunc(origin, Sonic_Main_t->Target());
	origin(obj);

	CharObj2Base* co2 = MainCharObj2[obj->Data2.Character->PlayerNum];
	EntityData1* data1 = MainCharObj1[obj->Data2.Character->PlayerNum];

	//Add somersault physics to spin dash, this is very hacky, but that's how SA2 does it, so... lol.
	if (data1->Action == 3 || data1->Action == Action_SpinRelease || data1->Action >= 61 && data1->Action <= 63 || data1->Action >= 66 && data1->Action <= 68)
	{
		SetPlayerSomersaultPhysics(co2, data1);
	}
	else {
		RestorePhysic(co2);
	}
}

void Init_BetterSonic() {
	Sonic_Main_t = new Trampoline((int)Sonic_Main, (int)Sonic_Main + 0x6, Sonic_Main_r);

	Init_NewAnimation();

	WriteData<48>((int*)0x717a75, 0x90); //remove "restore physics" every frame, we will manually do it.


	if (!amyGrunt)
		WriteData<5>((int*)0x71AF71, 0x90);

	if (!shGrunt)
		WriteData<5>((int*)0x71B3EC, 0x90);

	if (!sonicGrunt)
		WriteData<5>((int*)0x71AF97, 0x90);

}