#pragma once

#include "../pch.h"

class App {
private: 
	bool initialized = false;

public:
	static App& getInstance() {
		static App _instance;
		return _instance;
	}

	static App& CreateApp() {
		static App _instance;
		_instance.initialized = true;
		return _instance;
	}

	static void run();
};
