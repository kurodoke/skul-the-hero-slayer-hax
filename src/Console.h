#pragma once
#include "../pch.h"

class Console {
public:

    Console(){
        AllocConsole();
        FILE* filep;
        freopen_s(&filep, "CONOUT$", "w", stdout);
    }

    ~Console() {
        fclose(reinterpret_cast<FILE*>(stdout));
        PostMessageW(GetConsoleWindow(), WM_CLOSE, 0, 0);
        FreeConsole();
    }

};