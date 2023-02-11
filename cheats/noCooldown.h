#pragma once

#include "../pch.h"

//original function
float(__thiscall* noSkillCooldown_o)();

//the hook function
float __fastcall noSkillCooldown_h() {

	return 200.0f;
}
//original function
float(__thiscall* noSwapCooldown_o)();

//the hook function
float __fastcall noSwapCooldown_h() {

	return 200.0f;
}
//original function
float(__thiscall* noQuintessenceCooldown_o)();

//the hook function
float __fastcall noQuintessenceCooldown_h() {

	return 200.0f;
}

class NoCooldown {
private:
	std::string name = "NoCooldown";
	bool toggle = false;
	bool hook = false;
	void* Stat_GetSkillCooldownSpeed;
	void* Stat_GetSwapCooldownSpeed;
	void* Stat_GetQuintessenceCooldownSpeed;


public:
	void attach() {
		//we hook
		Stat_GetSkillCooldownSpeed = Mono::Instance().GetMethod((char*)"Stat", (char*)"GetSkillCooldownSpeed", 0, (char*)"Characters");
		Stat_GetSwapCooldownSpeed = Mono::Instance().GetMethod((char*)"Stat", (char*)"GetSwapCooldownSpeed", 0, (char*)"Characters");
		Stat_GetQuintessenceCooldownSpeed = Mono::Instance().GetMethod((char*)"Stat", (char*)"GetQuintessenceCooldownSpeed", 0, (char*)"Characters");

		if (Stat_GetSkillCooldownSpeed == nullptr || Stat_GetSwapCooldownSpeed == nullptr || Stat_GetQuintessenceCooldownSpeed == nullptr) {
			return;
		}

		//hooking skill cooldown
		CreateHook(name, Stat_GetSkillCooldownSpeed, &noSkillCooldown_h, reinterpret_cast<LPVOID*>(&noSkillCooldown_o));
		//hooking swap cooldown
		CreateHook(name, Stat_GetSwapCooldownSpeed, &noSwapCooldown_h, reinterpret_cast<LPVOID*>(&noSwapCooldown_o));
		//hooking quintessence cooldown
		CreateHook(name, Stat_GetQuintessenceCooldownSpeed, &noQuintessenceCooldown_h, reinterpret_cast<LPVOID*>(&noQuintessenceCooldown_o));
	}

	void update() {
		//check if enabled

		if (Stat_GetSkillCooldownSpeed == nullptr)
			return;

		if (toggle && !hook) {
			hook = true;
			EnableHook(name, Stat_GetSkillCooldownSpeed);
			EnableHook(name, Stat_GetSwapCooldownSpeed);
			EnableHook(name, Stat_GetQuintessenceCooldownSpeed);
		}
		if (!toggle && hook) {
			hook = false;
			DisableHook(name, Stat_GetSkillCooldownSpeed);
			DisableHook(name, Stat_GetSwapCooldownSpeed);
			DisableHook(name, Stat_GetQuintessenceCooldownSpeed);
		}
	}

	void detach() {
		//bring back original function
		UnHook(name, Stat_GetSkillCooldownSpeed);
		UnHook(name, Stat_GetSwapCooldownSpeed);
		UnHook(name, Stat_GetQuintessenceCooldownSpeed);
	}

	void action() {
		toggle = !toggle;
	}
};