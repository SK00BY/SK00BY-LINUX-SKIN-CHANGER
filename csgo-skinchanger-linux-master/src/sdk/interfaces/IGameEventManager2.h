#pragma once

#define INTERFACEVERSION_GAMEEVENTSMANAGER2 "GAMEEVENTSMANAGER002"

class IGameEventManager2;

class IGameEvent {
	public:
		const char* GetName() {
			return GetVirtualFunction<const char*(*)(void*)>(this, 2)(this);
		}

		int GetInt(const char* key) {
			return GetVirtualFunction<int(*)(void*, const char*, int)>(this, 7)(this, key, 0);
		}

		const char* GetString(const char* key) {
			return GetVirtualFunction<const char*(*)(void*, const char*, int)>(this, 10)(this, key, 0);
		}

		void SetString(const char* key, const char* value) {
			return GetVirtualFunction<void(*)(void*, const char*, const char*)>(this, 17)(this, key, value);
		}
};

extern IGameEventManager2* gameevents;