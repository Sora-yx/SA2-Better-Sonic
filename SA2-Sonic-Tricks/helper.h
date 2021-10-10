#pragma once

extern bool sa1dash;
extern bool sa1speed;
extern bool sa1SFX;
extern bool sonicBall;
extern bool sonicGrunt;
extern bool shGrunt;
extern bool amyGrunt;
extern bool superBounce;
extern bool shBounce;



extern AnimationInfo SonicAnimationListR[];


FunctionPointer(void, DrawObject, (NJS_OBJECT* a1), 0x42E730);
ObjectFunc(Dynamite_Main, 0x6da880);
ObjectFunc(DynamiteHiddenBase_Main, 0x714610);
ObjectFunc(DynamiteSandOcean_Main, 0x65AEA0);
ObjectFunc(PrisonLaneDoor, 0x606400);
ObjectFunc(PrisonLaneDoor4, 0x606A10);
ObjectFunc(DoorIG, 0x69D1D0);
ObjectFunc(DoorIG2, 0x69F460);
ObjectFunc(RocketIG, 0x6A10A0);
ObjectFunc(DoorCCThing, 0x79AFB0);
ObjectFunc(DoorHB, 0x715560);
ObjectFunc(MetalBox, 0x6D6490);
ObjectFunc(MetalBoxGravity, 0x77BB90);


void Init_NewAnimation();
void Init_BetterSonic();
void Init_Helper();


void init_SpinDash();
bool is2PCharacter();
bool isBlackShield();
void Init_Bounce();