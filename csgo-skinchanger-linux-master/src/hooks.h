#pragma once

#include <memory>

#include "sdk/sdk.h"
#include "vmthook/vmthook.h"

/* function prototypes */
typedef bool (*FireEventClientSideFn) (void*, IGameEvent*);
typedef void (*FrameStageNotifyFn) (void*, ClientFrameStage_t);

/* hooked functions */
extern void hkFrameStageNotify(void*, ClientFrameStage_t);
extern bool hkFireEventClientSide(void*, IGameEvent*);

/* virtual table hooks */
extern std::unique_ptr<VMTHook> clientdll_hook;
extern std::unique_ptr<VMTHook> gameevents_hook;