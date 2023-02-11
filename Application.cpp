#include "pch.h"
#include "src/Application.h"
#include "src/console.h"
#include "cheats.h"



void App::run() {

	Console* csl = new Console;	
	MH_Initialize();
	health->attach();
	cooldown->attach();
	dash->attach();

	while (!GetAsyncKeyState(VK_F5)) {
		if (GetAsyncKeyState(VK_F1)) {
			health->action();
		}

		if (GetAsyncKeyState(VK_F2)) {
			cooldown->action();
		}

		if (GetAsyncKeyState(VK_F3)) {
			dash->action();
		}

		if (GetAsyncKeyState(VK_F8)) {
			health->detach();
			cooldown->detach();
			dash->detach();
			break;
		}
		
		health->update();
		cooldown->update();
		dash->update();
		Sleep(100);
	}
	delete csl;
}
