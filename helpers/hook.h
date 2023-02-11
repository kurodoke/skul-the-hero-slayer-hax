#pragma once

#include "../pch.h"

bool MH_CheckStatus(std::string name, MH_STATUS minhook, std::string funcname);

void CreateHook(std::string funcName, LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal);

void EnableHook(std::string funcName, LPVOID pTarget);

void DisableHook(std::string funcName, LPVOID pTarget);

void UnHook(std::string funcName, LPVOID pTarget);