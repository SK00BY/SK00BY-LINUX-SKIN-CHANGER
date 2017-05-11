#pragma once

#include <dlfcn.h>

/* function prototypes */
typedef void* (*CreateInterfaceFn) (const char*, int*);

/* helper functions */
template <typename interface> interface* GetInterface(const char* filename, const char* version) {
	void* library = dlopen(filename, RTLD_NOLOAD | RTLD_NOW);

	if (!library)
		return nullptr;

	void* createinterface_sym = dlsym(library, "CreateInterface");

	if (!createinterface_sym)
		return nullptr;

	CreateInterfaceFn factory = reinterpret_cast<CreateInterfaceFn>(createinterface_sym);

	return reinterpret_cast<interface*>(factory(version, nullptr));
}

inline void**& GetVirtualTable(void* baseclass) {
	return *reinterpret_cast<void***>(baseclass);
}

template <typename Fn = void*> inline Fn GetVirtualFunction(void* baseclass, size_t index) {
	return reinterpret_cast<Fn>(GetVirtualTable(baseclass)[index]);
}