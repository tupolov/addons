#include "script_component.hpp"
#include "\A3\editor_f\Data\Scripts\dikCodes.h"

ADDON = false;
LOG(MSG_INIT);

GVAR(key_pid) = [] spawn {};

PREP(keypressed);
PREP(check);
PREP(canGetInCover);

["Advanced Combat Ability", "Get into cover", { _this call FUNC(keypressed)}, [DIK_X, [true, false, false]]] call CBA_fnc_registerKeybind;

ADDON = true;
