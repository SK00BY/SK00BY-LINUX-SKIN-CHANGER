/*

	Chameleon -- basic skin changer for CS:GO on 64-bit Linux.
	Copyright (C) 2017, aixxe. (www.aixxe.net)
	
	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Chameleon. If not, see <http://www.gnu.org/licenses/>.

*/

#include "sdk/sdk.h"
#include "hooks.h"

/* game interface pointers */
IBaseClientDLL* clientdll = nullptr;
IVModelInfoClient* modelinfo = nullptr;
IVEngineClient* engine = nullptr;
IClientEntityList* entitylist = nullptr;
IGameEventManager2* gameevents = nullptr;

/* virtual table hooks */
std::unique_ptr<VMTHook> clientdll_hook;
std::unique_ptr<VMTHook> gameevents_hook;

/* called when the library is loading */
int __attribute__((constructor)) chameleon_init() {
	/* obtain pointers to game interface classes */
	clientdll = GetInterface<IBaseClientDLL>("./csgo/bin/linux64/client_client.so", CLIENT_DLL_INTERFACE_VERSION);
	modelinfo = GetInterface<IVModelInfoClient>("./bin/linux64/engine_client.so", VMODELINFO_CLIENT_INTERFACE_VERSION);
	engine = GetInterface<IVEngineClient>("./bin/linux64/engine_client.so", VENGINE_CLIENT_INTERFACE_VERSION);
	entitylist = GetInterface<IClientEntityList>("./csgo/bin/linux64/client_client.so", VCLIENTENTITYLIST_INTERFACE_VERSION);
	gameevents = GetInterface<IGameEventManager2>("./bin/linux64/engine_client.so", INTERFACEVERSION_GAMEEVENTSMANAGER2);
	
	/* hook IBaseClientDLL::FrameStageNotify */
	clientdll_hook = std::make_unique<VMTHook>(clientdll);
	clientdll_hook->HookFunction(reinterpret_cast<void*>(hkFrameStageNotify), 36);

	/* hook IGameEventManager2::FireEventClientSide */
	gameevents_hook = std::make_unique<VMTHook>(gameevents);
	gameevents_hook->HookFunction(reinterpret_cast<void*>(hkFireEventClientSide), 10);

	return 0;
}