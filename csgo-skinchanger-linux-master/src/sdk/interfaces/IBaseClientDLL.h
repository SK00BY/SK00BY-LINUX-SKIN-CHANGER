#pragma once

#define CLIENT_DLL_INTERFACE_VERSION "VClient018"

class ClientClass;

class IBaseClientDLL {
	public:
		ClientClass* GetAllClasses() {
			return GetVirtualFunction<ClientClass*(*)(void*)>(this, 8)(this);
		}
};

extern IBaseClientDLL* clientdll;