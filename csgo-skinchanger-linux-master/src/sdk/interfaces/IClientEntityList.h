#pragma once

#define VCLIENTENTITYLIST_INTERFACE_VERSION "VClientEntityList003"

class IClientEntity;

class IClientEntityList {
	public:
		IClientEntity* GetClientEntity(int index) {
			return GetVirtualFunction<IClientEntity*(*)(void*, int)>(this, 3)(this, index);
		}
};

extern IClientEntityList* entitylist;