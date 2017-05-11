#pragma once

/* network variable offsets */
#define m_lifeState 0x293
#define m_nModelIndex 0x28C
#define m_iAccountID 0x288
#define m_hViewModel 0x3AD4
#define m_hWeapon 0x3060
#define m_hMyWeapons 0x3528
#define m_AttributeManager 0x34C0
#define m_Item 0x60
#define m_iItemDefinitionIndex 0x268
#define m_iEntityQuality 0x26C
#define m_iItemIDHigh 0x280
#define m_szCustomName 0x340
#define m_nFallbackPaintKit 0x39B8
#define m_nFallbackSeed 0x39BC
#define m_flFallbackWear 0x39C0
#define m_nFallbackStatTrak 0x39C4

class IClientEntity {};

class C_BaseEntity: public IClientEntity {
	public:
		int* GetModelIndex() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_nModelIndex);
		}
};

class C_BasePlayer: public C_BaseEntity {
	public:
		unsigned char GetLifeState() {
			return *reinterpret_cast<unsigned char*>(uintptr_t(this) + m_lifeState);
		}

		int* GetWeapons() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_hMyWeapons);
		}

		int GetViewModel() {
			return *reinterpret_cast<int*>(uintptr_t(this) + m_hViewModel);
		}
};

class C_BaseAttributableItem: public C_BaseEntity {
	public:
		int* GetAccountID() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_AttributeManager + m_Item + m_iAccountID);
		}

		int* GetItemDefinitionIndex() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_AttributeManager + m_Item + m_iItemDefinitionIndex);
		}

		int* GetItemIDHigh() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_AttributeManager + m_Item + m_iItemIDHigh);
		}

		int* GetEntityQuality() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_AttributeManager + m_Item + m_iEntityQuality);
		}

		char* GetCustomName() {
			return reinterpret_cast<char*>(uintptr_t(this) + m_AttributeManager + m_Item + m_szCustomName);
		}

		int* GetFallbackPaintKit() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_nFallbackPaintKit);
		}

		int* GetFallbackSeed() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_nFallbackSeed);
		}

		float* GetFallbackWear() {
			return reinterpret_cast<float*>(uintptr_t(this) + m_flFallbackWear);
		}

		int* GetFallbackStatTrak() {
			return reinterpret_cast<int*>(uintptr_t(this) + m_nFallbackStatTrak);
		}
};

class C_BaseCombatWeapon: public C_BaseAttributableItem {};

class C_BaseViewModel: public C_BaseEntity {
	public:
		int GetWeapon() {
			return *reinterpret_cast<int*>(uintptr_t(this) + m_hWeapon);
		}
};
