#pragma once

#define VENGINE_CLIENT_INTERFACE_VERSION "VEngineClient014"

typedef struct player_info_s {
	int64_t __pad0;

	// 64-bit steamid
	union {
		int64_t xuid;
		struct {
			int xuidlow;
			int xuidhigh;
		};
	};

	// scoreboard information
	char name[MAX_PLAYER_NAME_LENGTH + 96];

	// local server user ID, unique while server is running
	int userid;

	// global unique player identifer
	char guid[SIGNED_GUID_LEN + 1];

	// friends identification number
	unsigned int friendsid;

	// friends name
	char friendsname[MAX_PLAYER_NAME_LENGTH + 96];

	// true, if player is a bot controlled by game.dll
	bool fakeplayer;

	// true if player is the HLTV proxy
	bool ishltv;

	// custom files CRC for this player
	unsigned int customfiles[4];

	// this counter increases each time the server downloaded a new file
	unsigned char filesdownloaded;
} player_info_t;

class IVEngineClient {
	public:
		bool GetPlayerInfo(int index, player_info_t* playerinfo) {
			return GetVirtualFunction<bool(*)(void*, int, player_info_t*)>(this, 8)(this, index, playerinfo);
		}

		int GetPlayerForUserID(int userid) {
			return GetVirtualFunction<int(*)(void*, int)>(this, 9)(this, userid);
		}

		int GetLocalPlayer() {
			return GetVirtualFunction<int(*)(void*)>(this, 12)(this);
		}
};

extern IVEngineClient* engine;