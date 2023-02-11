#pragma once

#include "../pch.h"

//original function
float(__thiscall* dash_o)();

//the hook function
float __fastcall dash_h() {
	return 200.0f;
}


class Dash {
private:
	std::string name = "DashCooldown";
	bool toggle = false;
	bool hook = false;
	void* Stat_GetDashCooldownSpeed;

public:
	void attach() {
		//we hook
		Stat_GetDashCooldownSpeed = Mono::Instance().GetMethod((char*)"Stat", (char*)"GetDashCooldownSpeed", 0, (char*)"Characters");


		if (Stat_GetDashCooldownSpeed == nullptr) {
			return;
		}

		CreateHook(name, Stat_GetDashCooldownSpeed, &dash_h, reinterpret_cast<LPVOID*>(&dash_o));
	}

	void update() {
		//check if enabled

		if (Stat_GetDashCooldownSpeed == nullptr)
			return;

		if (toggle && !hook) {
			hook = true;
			EnableHook(name, Stat_GetDashCooldownSpeed);
		}
		if (!toggle && hook) {
			hook = false;
			DisableHook(name, Stat_GetDashCooldownSpeed);
		}
	}

	void detach() {
		//bring back original function
		UnHook(name, Stat_GetDashCooldownSpeed);
	}

	void action() {
		toggle = !toggle;
	}
};