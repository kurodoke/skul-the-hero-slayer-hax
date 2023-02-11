#pragma once
#include "pch.h"

namespace Skul {
	struct MonitorData;
	struct Health;
	struct Character;
	struct playerComponents;

	struct __declspec(align(8)) Object_1__Fields { void* m_CachedPtr; };
	struct Component_1__Fields { struct Object_1__Fields _; };
	struct Behaviour__Fields { struct Component_1__Fields _; };
	struct MonoBehaviour__Fields { struct Behaviour__Fields _; };

	struct __declspec(align(8)) String__Fields {
		int32_t m_stringLength;
		uint16_t m_firstChar;
	};

	enum Key {
		// Token: 0x04000F38 RID: 3896
		Unspecified,
		// Token: 0x04000F39 RID: 3897
		Player1,
		// Token: 0x04000F3A RID: 3898
		Player2,
		// Token: 0x04000F3B RID: 3899
		SmallProp = 101,
		// Token: 0x04000F3C RID: 3900
		LargeProp,
		// Token: 0x04000F3D RID: 3901
		BrutalityAltar = 201,
		// Token: 0x04000F3E RID: 3902
		EnergyAltar,
		// Token: 0x04000F3F RID: 3903
		RageAltar,
		// Token: 0x04000F40 RID: 3904
		SteelAltar,
		// Token: 0x04000F41 RID: 3905
		MinionCarleonRecruit = 501,
		// Token: 0x04000F42 RID: 3906
		MinionCarleonArcher,
		// Token: 0x04000F43 RID: 3907
		MinionCarleonAssassin,
		// Token: 0x04000F44 RID: 3908
		MinionCarleonManAtArms,
		// Token: 0x04000F45 RID: 3909
		CaerleonRecruit = 10001,
		// Token: 0x04000F46 RID: 3910
		CaerleonArcher,
		// Token: 0x04000F47 RID: 3911
		CaerleonAssassin,
		// Token: 0x04000F48 RID: 3912
		CaerleonManAtArms,
		// Token: 0x04000F49 RID: 3913
		CaerleonLowClassWizard,
		// Token: 0x04000F4A RID: 3914
		FireCaerleonLowClassWizard,
		// Token: 0x04000F4B RID: 3915
		IceCaerleonLowClassWizard,
		// Token: 0x04000F4C RID: 3916
		Ent = 10101,
		// Token: 0x04000F4D RID: 3917
		OldTreeEnt,
		// Token: 0x04000F4E RID: 3918
		GiganticEnt,
		// Token: 0x04000F4F RID: 3919
		BlossomEnt,
		// Token: 0x04000F50 RID: 3920
		GoldManeRecruit = 20001,
		// Token: 0x04000F51 RID: 3921
		GoldManeArcher,
		// Token: 0x04000F52 RID: 3922
		GoldManeSpearMan,
		// Token: 0x04000F53 RID: 3923
		GoldManeLowClassWizard,
		// Token: 0x04000F54 RID: 3924
		GoldManeManAtArms,
		// Token: 0x04000F55 RID: 3925
		GoldManePriest,
		// Token: 0x04000F56 RID: 3926
		ChiefMaid = 20101,
		// Token: 0x04000F57 RID: 3927
		MeleeMaid,
		// Token: 0x04000F58 RID: 3928
		RangeMaid,
		// Token: 0x04000F59 RID: 3929
		Servant,
		// Token: 0x04000F5A RID: 3930
		DarkQuartzEnt = 30001,
		// Token: 0x04000F5B RID: 3931
		DarkQuartzOgre,
		// Token: 0x04000F5C RID: 3932
		DarkQuartzRecruit,
		// Token: 0x04000F5D RID: 3933
		DarkQuartzGolem,
		// Token: 0x04000F5E RID: 3934
		Alchemist = 30101,
		// Token: 0x04000F5F RID: 3935
		HighAlchemist,
		// Token: 0x04000F60 RID: 3936
		GrandAlchemist,
		// Token: 0x04000F61 RID: 3937
		LooseSubject = 30201,
		// Token: 0x04000F62 RID: 3938
		StrangeSubject,
		// Token: 0x04000F63 RID: 3939
		RefinedRevengefulSpiritBottle = 30301,
		// Token: 0x04000F64 RID: 3940
		RefinedRevengefulSpirit,
		// Token: 0x04000F65 RID: 3941
		UnstableRevengefulSpiritBottle,
		// Token: 0x04000F66 RID: 3942
		UnstableRevengefulSpirit,
		// Token: 0x04000F67 RID: 3943
		Fanatic = 40001,
		// Token: 0x04000F68 RID: 3944
		AgedFanatic,
		// Token: 0x04000F69 RID: 3945
		FanaticRecruit,
		// Token: 0x04000F6A RID: 3946
		MartyrFanaric,
		// Token: 0x04000F6B RID: 3947
		HighFanatic,
		// Token: 0x04000F6C RID: 3948
		MissionaryFanatic,
		// Token: 0x04000F6D RID: 3949
		Brave,
		// Token: 0x04000F6E RID: 3950
		Wisdom,
		// Token: 0x04000F6F RID: 3951
		WeepingAngel,
		// Token: 0x04000F70 RID: 3952
		HolyKnightsRecruit,
		// Token: 0x04000F71 RID: 3953
		HolyKnightsArcher,
		// Token: 0x04000F72 RID: 3954
		HolyKnightsAssassin,
		// Token: 0x04000F73 RID: 3955
		HolyKnightsMagician,
		// Token: 0x04000F74 RID: 3956
		HolyKnightsPreist,
		// Token: 0x04000F75 RID: 3957
		HolyKnightsSpearMan,
		// Token: 0x04000F76 RID: 3958
		HolyKnightsManAtArms,
		// Token: 0x04000F77 RID: 3959
		Guadian = 50001,
		// Token: 0x04000F78 RID: 3960
		CaerleonRecruitElite = 1001,
		// Token: 0x04000F79 RID: 3961
		Yggdrasil = 2001,
		// Token: 0x04000F7A RID: 3962
		LeianaShortHair,
		// Token: 0x04000F7B RID: 3963
		LeianaLongHair,
		// Token: 0x04000F7C RID: 3964
		AwakenLeiana,
		// Token: 0x04000F7D RID: 3965
		Chimera,
		// Token: 0x04000F7E RID: 3966
		Pope,
		// Token: 0x04000F7F RID: 3967
		FirstHero1,
		// Token: 0x04000F80 RID: 3968
		FirstHero2,
		// Token: 0x04000F81 RID: 3969
		FirstHero3
	};

	enum Type {
		// Token: 0x04002F1C RID: 12060
		TrashMob,
		// Token: 0x04002F1D RID: 12061
		Named,
		// Token: 0x04002F1E RID: 12062
		Adventurer,
		// Token: 0x04002F1F RID: 12063
		Boss,
		// Token: 0x04002F20 RID: 12064
		Summoned,
		// Token: 0x04002F21 RID: 12065
		Trap,
		// Token: 0x04002F22 RID: 12066
		Player,
		// Token: 0x04002F23 RID: 12067
		Dummy,
		// Token: 0x04002F24 RID: 12068
		PlayerMinion
	};

	enum LookingDirection {
		// Token: 0x04002F26 RID: 12070
		Right,
		// Token: 0x04002F27 RID: 12071
		Left
	};

	enum SizeForEffect {
		// Token: 0x04002F29 RID: 12073
		Small,
		// Token: 0x04002F2A RID: 12074
		Medium,
		// Token: 0x04002F2B RID: 12075
		Large,
		// Token: 0x04002F2C RID: 12076
		ExtraLarge,
		// Token: 0x04002F2D RID: 12077
		None
	};

	struct Health__Fields {
		struct MonoBehaviour__Fields _;
		DWORD onTookDamage;
		DWORD onDie;
		DWORD onDied;
		DWORD onDiedTryCatch;
		DWORD onChanged;
		DWORD onHealed;
		bool onTakeDamage;
		struct Character* owner;
		struct Shield* shield;
		struct GrayHealth* grayHealth;
		double currentHealth;
		double maximumHealth;
		double percent;
		bool dead;
	};

	struct Health {
		uint64_t pCharacterHealth;
		int a;
		int b;
		uint64_t pVisibility;
		uint64_t pTookDamageDelegate;
		uint64_t pAction_1;
		uint64_t pAction_2;
		uint64_t pAction_3;
		int c;
		int d;
		int e;
		int f;
		uint64_t p_Class_unk_1;
		uint64_t p_BoxCollider2D;
		Character* owner;
	};

	struct Character__Fields {
		struct MonoBehaviour__Fields _;
		DWORD onDie;
		DWORD onEvade;
		DWORD onStartAction;
		DWORD onEndAction;
		DWORD onCancelAction;
		DWORD onStartMotion;
		Key key;
		struct CharacterHealth* health;
		struct CharacterHit* hit;
		struct Unity_BoxCollider2D* collider;
		struct Movement* movement;
		struct CharacterAnimationController* animationController;
		struct CharacterStatus* status;
		bool stunedOrFreezed;
		Type type;
		SizeForEffect sizeForEffect;
		struct Unity_SortingGroup* sortingGroup;
		struct Unity_Transform* base;
		LookingDirection lookingDirection;
		struct PlayerComponents* playerComponents;
		LookingDirection desiringLookingDirection;
		struct List_Character_Actions_Action* actions;
		DWORD spriteEffectStack;
		struct Mark* mark;
		struct AbilityManager* ability;
		struct Character_Actions_Motion* motion;
		struct Character_Actions_Motion* runningMotion;
		struct GameObject* attach;
		struct GameObject* attachWithFlip;
		bool liveAndActive;
	};

	struct Character {

		char mono_behaviour[16];		//0x0
		uint64_t m_CachedPtr;			//0x10
		uint64_t onGiveDamage;			//0x18
		uint64_t onGaveDamage;			//0x20
		uint64_t onGiveStatus;			//0x28
		uint64_t onDie;					//0x30
		uint64_t onEvade;				//0x38
		uint64_t onKilled;				//0x40
		uint64_t onStartAction;			//0x48
		uint64_t onEndAction;			//0x50
		uint64_t onCancelAction;		//0x58
		uint64_t onStartMotion;			//0x60
		uint64_t onStartCharging;		//0x68
		uint64_t onStopCharging;		//0x70
		uint64_t onCancelCharging;		//0x78
		uint64_t invulnerable;			//0x80
		uint64_t blockLook;				//0x88
		uint64_t stealth;				//0x90
		uint64_t stat;					//0x98
		uint64_t chronometer;			//0xA0
		uint64_t _health;				//0xA8
		uint64_t _hit;					//0xB0
		uint64_t _collider;				//0xB8
		uint64_t _movement;				//0xC0
		uint64_t _animationController;	//0xC8
		uint64_t _status;				//0xD0
		uint64_t _sortingGroup;			//0xD8
		uint64_t _baseStat;				//0xE0
		uint64_t _base;					//0xE8
		uint64_t _weapon;				//0xF0
		uint64_t _attach;				//0xF8
		char _cWaitForEndOfAction[16];	//0x100
		uint64_t playerComponents_k_BackingField;
		uint64_t actions_k_BackingField;
		uint64_t spriteEffectStack_k_BackingField;
		uint64_t mark_k_BackingField;
		uint64_t ability_k_BackingField;
		uint64_t motion_k_BackingField;
		uint64_t attachWithFlip_k_BackingField;
		int _key;
	};
}