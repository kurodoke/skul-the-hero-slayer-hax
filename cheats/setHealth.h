#pragma once

#include "../pch.h"

//original function
double(__thiscall* takeHealth_o)(Skul::Health*, double);

//the hook function
double __fastcall takeHealth_h(Skul::Health* __this, double dmg) {

	int key = __this->owner->_key;//1 || 2 is a player

	if (key == 1 || key == 2)
		dmg = 0.0f;

	return takeHealth_o(__this, dmg);
}

class SetHealth{
private:
	std::string name = "Health_TakeHealth";
	bool toggle = false;
	bool hook = false;
	void* Health_TakeHealth;

public:
	void attach() {
		//we hook
		Health_TakeHealth = Mono::Instance().GetMethod((char*)"Health", (char*)"TakeHealth", -1, (char*)"Characters");


		if (Health_TakeHealth == nullptr) {
			return;
		}

		CreateHook(name, Health_TakeHealth, &takeHealth_h, reinterpret_cast<LPVOID*>(&takeHealth_o));
	}

	void update() {
		//check if enabled

		if (Health_TakeHealth == nullptr)
			return;

		if (toggle && !hook) {
			hook = true;
			EnableHook(name, Health_TakeHealth);
		}
		if (!toggle && hook) {
			hook = false;
			DisableHook(name, Health_TakeHealth);
		}
	}

	void detach() {
		//bring back original function
		UnHook(name, Health_TakeHealth);
	}

	void action() {
		toggle = !toggle;
	}
};