#include "pch.h"
#include "helpers/hook.h"

bool MH_CheckStatus(std::string name, MH_STATUS minhook, std::string funcname) {
	if (minhook != MH_OK && minhook != MH_ERROR_ALREADY_CREATED && minhook != MH_ERROR_ALREADY_INITIALIZED) {
		fprintf(stderr, "[MINHOOK ERR] Error %s in %s status: %s \n", funcname, name.c_str(), MH_StatusToString(minhook));
		return false;
	}
	printf("[MINHOOK] Success %s in %s \n", funcname, name.c_str());
	return true;
}

void CreateHook(std::string funcName, LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal) {
	MH_CheckStatus(funcName, MH_CreateHook(pTarget, pDetour, ppOriginal), __func__);
}

void EnableHook(std::string funcName, LPVOID pTarget) {
	MH_CheckStatus(funcName, MH_EnableHook(pTarget), __func__);
}

void DisableHook(std::string funcName, LPVOID pTarget) {
	MH_CheckStatus(funcName, MH_DisableHook(pTarget), __func__);
}

void UnHook(std::string funcName, LPVOID pTarget) {
	MH_CheckStatus(funcName, MH_DisableHook(pTarget), __func__);
}
