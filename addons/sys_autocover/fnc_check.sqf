#include "script_component.hpp"

private ["_anim","_height","_currentAnim","_newAction","_newpose","_newD","_array","_action","_pose","_darray","_d","_move","_stan","_hand","_check"];

#define __standup "aadjpercmstpsraswrfldup"
#define __stand "amovpercmstpsraswrfldnon"
#define __standdown "aadjpercmstpsraswrflddown"

#define __kneelup "aadjpknlmstpsraswrfldup"
#define __kneel "amovpknlmstpsraswrfldnon"
#define __kneeldown "aadjpknlmstpsraswrflddown"

#define __proneup "aadjppnemstpsraswrfldup"
#define __prone "amovppnemstpsraswrfldnon"
#define __pronedown "aadjppnemstpsraswrflddown"

PARAMS_1(_currentAnim);

_currentAnim = tolower(_currentAnim);

_height = [_currentAnim] call FUNC(canGetInCover);

TRACE_1("",_height);

// Check to see if you can hide behind something, function returns height of object in relation to man
if (_height == 0) exitwith { hintSilent "Can't get in cover here"};
if (_height == -1) exitwith { hintSilent "Already in cover."};

// Split the animation string into action, pose, movement, stance, hand class, direction
_array = [_currentAnim, ""] call cba_fnc_split;

if (_array select 0 != "a") exitWith {hint "You are sitting, get off your ass!"};

// Get hand class
_hand = [[(_array select 16),(_array select 17),(_array select 18),(_array select 19)],""] call CBA_fnc_join;
TRACE_1("",_hand);

// Switch to equivalent
switch (true) do {
	case (_height > 1.7): {_anim = __standup;};
	case (_height > 1.6 && _height <= 1.7): {_anim = __stand;};
	case (_height > 1.4 && _height <= 1.6): {_anim = __standdown;};
	case (_height > 1.3 && _height <= 1.4): {_anim = __kneelup;};
	case (_height > 1.1 && _height <= 1.3): {_anim = __kneel;};
	case (_height > 0.8 && _height <= 1.1): {_anim = __kneeldown;};
	case (_height > 0.6 && _height <= 0.8): {_anim = __proneup;};
	case (_height <= 0.6 && _height >= 0.3): {_anim = __prone;};
	default {_anim = __pronedown;};
};

// If the player is using a pistol, then switch the anim
if (_hand != "wrfl") then {
	_weapon = currentWeapon player;
	_weaponCheck = [configFile >> "CfgWeapons" >> _weapon >> "nameSound", "text", "missing"] call CBA_fnc_getConfigEntry;
	if (_weaponCheck == "Pistol") then {
		TRACE_1("",_weaponCheck);
		_anim = [_anim, "wrfl", "wpst"] call cba_fnc_replace; 
	};
};

// *** get in cover

// *** Visual feedback
hint (localize "STR_ALIVE_INCOVER");

// Check that new anim is legit
_check = [configFile >> "CfgMovesMaleSdr" >> "States" >> _anim >> "access", "number", 0] call CBA_fnc_getConfigEntry;

if (_check == 3) then {
	// Switch to new anim
	TRACE_2("Correct Anim",_currentAnim, _anim);
	player switchmove _anim;
} else {
	TRACE_2("Incorrect Anim", _currentAnim, _anim);
};