#pragma once

#include "../pch.h"

//include mono stuff
#include <mono/metadata/threads.h>
#include <mono/metadata/object.h>

//mono things damn...
typedef MonoDomain* (*t_mono_get_root_domain)();
typedef MonoThread* (*t_mono_thread_attach) (MonoDomain*);
typedef MonoAssembly* (*t_mono_domain_assembly_open)(MonoDomain* mDomain, const char* name);
typedef MonoImage* (*t_mono_assembly_get_image)(MonoAssembly* mAssembly);
typedef MonoClass* (*t_mono_class_from_name)(MonoImage* mImage, const char* name_space, const char* name);
typedef MonoMethod* (*t_mono_class_get_method_from_name)(MonoClass* mClass, const char* name, int param_count);
typedef void* (*t_mono_compile_method)(MonoMethod* mMethod);
typedef MonoProperty* (*t_mono_class_get_property_from_name)(MonoClass* mClass, const char* name);
typedef MonoObject* (*t_mono_property_get_value)(MonoProperty* prop, void* obj, void** params, MonoObject** exc);


class Mono {
private:
	bool initialized = false;
	HMODULE hMono;

	//mono init
	t_mono_domain_assembly_open mono_domain_assembly_open;
	t_mono_assembly_get_image mono_assembly_get_image;
	t_mono_class_from_name mono_class_from_name;
	t_mono_class_get_method_from_name mono_class_get_method_from_name;
	t_mono_compile_method mono_compile_method;
	t_mono_class_get_property_from_name mono_class_get_property_from_name;
	t_mono_property_get_value mono_property_get_value;

	t_mono_thread_attach mono_thread_attach;
	t_mono_get_root_domain mono_get_root_domain;
	//zero constructor
	Mono() {}

public:
	static Mono& Instance() {
		
		static Mono _instance;

		if (!_instance.initialized) {
			_instance.Initialize();
			_instance.initialized = true;
		}

		return _instance;
	}

	void Initialize() {
	
		hMono = GetModuleHandle("mono-2.0-bdwgc.dll");
		if (hMono == NULL)
			return;

		//mono things to get function addresses
		mono_domain_assembly_open = reinterpret_cast<t_mono_domain_assembly_open>(GetProcAddress(hMono, "mono_domain_assembly_open"));
		mono_assembly_get_image = reinterpret_cast<t_mono_assembly_get_image>(GetProcAddress(hMono, "mono_assembly_get_image"));
		mono_class_from_name = reinterpret_cast<t_mono_class_from_name>(GetProcAddress(hMono, "mono_class_from_name"));
		mono_class_get_method_from_name = reinterpret_cast<t_mono_class_get_method_from_name>(GetProcAddress(hMono, "mono_class_get_method_from_name"));
		mono_compile_method = reinterpret_cast<t_mono_compile_method>(GetProcAddress(hMono, "mono_compile_method"));
		mono_class_get_property_from_name = reinterpret_cast<t_mono_class_get_property_from_name> (GetProcAddress(hMono, "mono_class_get_property_from_name"));
		mono_property_get_value = reinterpret_cast<t_mono_property_get_value> (GetProcAddress(hMono, "mono_property_get_value"));

		// thread to prevent crash (idk what this does man, just copied from the tutorial.. hope it useful)
		mono_thread_attach = reinterpret_cast<t_mono_thread_attach>(GetProcAddress(hMono, "mono_thread_attach"));
		mono_get_root_domain = reinterpret_cast<t_mono_get_root_domain>(GetProcAddress(hMono, "mono_get_root_domain"));
		mono_thread_attach(mono_get_root_domain());

	}

	void* GetMethod(char* className, char* methodName, int methodParam , char* nameSpace = (char*)"", char* assemblyName = (char*)"Assembly-CSharp") {

		auto pDomain = mono_get_root_domain();
		if (pDomain == nullptr)
			return nullptr;
		//printf("domain\n");

		auto pThread = mono_thread_attach(pDomain);
		if (pThread == nullptr)
			return nullptr;
		//printf("thread\n");

		auto pAssembly = mono_domain_assembly_open(pDomain, assemblyName);
		if (pAssembly == nullptr)
			return nullptr;
		//printf("assembly\n");

		auto pImage = mono_assembly_get_image(pAssembly);
		if (pImage == nullptr)
			return nullptr;
		//printf("image\n");

		auto pClass = mono_class_from_name(pImage, nameSpace, className);
		if (pClass == nullptr)
			return nullptr;
		//printf("class\n");

		auto pMethod = mono_class_get_method_from_name(pClass, methodName, methodParam);
		if (pMethod == nullptr)
			return nullptr;
		//printf("method\n");

		auto pCompileMethod = mono_compile_method(pMethod);
		//printf("compile\n");
		return pCompileMethod;
	}

	void* GetClass(char* className, char* nameSpace = (char*)"", char* assemblyName = (char*)"Assembly-CSharp") {

		auto pDomain = mono_get_root_domain();
		if (pDomain == nullptr)
			return nullptr;
		//printf("domain\n");

		auto pThread = mono_thread_attach(pDomain);
		if (pThread == nullptr)
			return nullptr;
		//printf("thread\n");

		auto pAssembly = mono_domain_assembly_open(pDomain, assemblyName);
		if (pAssembly == nullptr)
			return nullptr;
		//printf("assembly\n");

		auto pImage = mono_assembly_get_image(pAssembly);
		if (pImage == nullptr)
			return nullptr;
		//printf("image\n");

		auto pClass = mono_class_from_name(pImage, nameSpace, className);
		return pClass;
	}

	void* GetProperty(char* className, char* propName, char* nameSpace = (char*)"", char* assemblyName = (char*)"Assembly-CSharp") {

		auto pDomain = mono_get_root_domain();
		if (pDomain == nullptr)
			return nullptr;
		//printf("domain\n");

		auto pThread = mono_thread_attach(pDomain);
		if (pThread == nullptr)
			return nullptr;
		//printf("thread\n");

		auto pAssembly = mono_domain_assembly_open(pDomain, assemblyName);
		if (pAssembly == nullptr)
			return nullptr;
		//printf("assembly\n");

		auto pImage = mono_assembly_get_image(pAssembly);
		if (pImage == nullptr)
			return nullptr;
		//printf("image\n");

		auto pClass = mono_class_from_name(pImage, nameSpace, className);
		if (pClass == nullptr)
			return nullptr;
		//printf("class\n");

		auto pProp = mono_class_get_property_from_name(pClass, propName);
		return pProp;
	}
};
