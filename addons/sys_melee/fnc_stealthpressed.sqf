#include "script_component.hpp"

// Stealth Takedown, when player presses SHIFT-LWIN (and not prone) they will takedown the target.
private ["_r"];
TRACE_1("",_this);
_r = false;
if (scriptDone GVAR(key_pid)) then {
	
	if !(isNil "TUP_Stealth") exitWith { _r = false };
	
	// If player is not in vehicle and alive
	if (vehicle player != player || {!alive player}) exitWith { _r = false };
	
	// Make sure they are not on the floor
	if ( [_anim, "Ppne"] call CBA_fnc_find == -1) then {
		GVAR(key_pid) = [cursorTarget] spawn FUNC(stealthcheck);
		_r = true;
	};
};

_r;
