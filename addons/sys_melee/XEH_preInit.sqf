#include "script_component.hpp"
#include "\A3\editor_f\Data\Scripts\dikCodes.h"

ADDON = false;
LOG(MSG_INIT);

PREP(melee);
PREP(stealth);

[QGVAR(melee), {_this call FUNC(melee)}] call CBA_fnc_addReceiverOnlyEventhandler;
[QGVAR(recover), {_this switchmove "AmovPpneMstpSnonWnonDnon_healed"}] call CBA_fnc_addEventHandler;

[QGVAR(stealth), {_this call FUNC(stealth)}] call CBA_fnc_addReceiverOnlyEventhandler;

ADDON = true;
