#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files
#include <Windows.h>

// Standard Header Files
#include <iostream>
#include <vector>
#include <tlhelp32.h>
#include <Psapi.h>
#include <thread>
#include <cstdint>
#include <array>
#include <codecvt>

// Custom Header Files
#include <MinHook.h>

#include "helpers/mono.h"
#include "helpers/hook.h"
#include "game.h"