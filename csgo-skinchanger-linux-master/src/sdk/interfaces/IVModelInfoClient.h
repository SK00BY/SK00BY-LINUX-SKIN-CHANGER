#pragma once

#define VMODELINFO_CLIENT_INTERFACE_VERSION "VModelInfoClient004"

class IVModelInfoClient {
	public:
		int GetModelIndex(const char* filename) {
			return GetVirtualFunction<int(*)(void*, const char*)>(this, 3)(this, filename);
		}
};

extern IVModelInfoClient* modelinfo;