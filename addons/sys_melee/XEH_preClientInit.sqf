#include "script_component.hpp"
#include "\A3\editor_f\Data\Scripts\dikCodes.h"

ADDON = false;
LOG(MSG_INIT);

GVAR(key_pid) = [] spawn {};

PREP(meleepressed);
PREP(stealthpressed);

PREP(check);
PREP(stealthcheck);

GVAR(meleepressed) = 0;

["Advanced Combat Ability", "Melee", ["Melee","Strike enemy with fists or weapons"],{ _this call FUNC(meleepressed)}, "", [DIK_GRAVE, [true, false, false]]] call CBA_fnc_addKeybind;
["Advanced Combat Ability", "StealthTakedown", ["Stealth Takedown","Silently take down enemy when close enough"],{ _this call FUNC(stealthpressed)}, "", [DIK_SPACE, [true, false, false]]] call CBA_fnc_addKeybind;

ADDON = true;
