#include "script_component.hpp"

// Auto cover, when player presses SHIFT-X (and not prone) they will duck behind nearest cover.
private ["_r"];
TRACE_1("",_this);
_r = false;
if (scriptDone GVAR(key_pid)) then {
	_anim = animationstate player;
	TRACE_1("ANIMATION",_anim);

	if ( [_anim, "Ppne"] call CBA_fnc_find == -1 || {([_anim, "AadjPpne"] call CBA_fnc_find != -1 && [_anim, "Dup"] call CBA_fnc_find != -1)}) then {
		GVAR(key_pid) = [animationstate player] spawn FUNC(check);
		_r = true;
	};
};

_r;
