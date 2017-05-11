#include "../hooks.h"

bool hkFireEventClientSide(void* thisptr, IGameEvent* event) {
	while (event) {
		/* only make changes to player_death events */
		if (!strcmp(event->GetName(), "player_death")) {
			/* continue if we were the attacker */
			int attacker_uid = event->GetInt("attacker");

			if (!attacker_uid)
				break;

			if (engine->GetPlayerForUserID(attacker_uid) != engine->GetLocalPlayer())
				break;

			/* check the weapon id and perform replacements */
			const char* weapon = event->GetString("weapon");

			if (!strcmp(weapon, "knife_default_ct")) {
				/* Knife (CT) -> Karambit */
				event->SetString("weapon", "knife_karambit");
			} else if (!strcmp(weapon, "knife_t")) {
				/* Knife (T) -> M9 Bayonet */
				event->SetString("weapon", "knife_m9_bayonet");
			}
		}

		break;
	}

	/* call original function after we've made our changes */
	return gameevents_hook->GetOriginalFunction<FireEventClientSideFn>(10)(thisptr, event);
};