#include "script_component.hpp"

private ["_inj","_wtype","_anim","_anims", "_playedanim", "_ransound","_hitsound","_reactsound"];

PARAMS_4(_target,_weapon,_attacker,_type);

// type 0 = grab, 1 = melee, 2 = rifle butt, 3 = bayonet

TRACE_1("",_this);

// Make the target react to the hit
if ((_target call CBA_fnc_getUnitAnim) select 0 != "prone") then {

	switch (_type) do {
		case 3 : {
			sleep 0.3;
			_anims = ["AmelPercMstpSnonWnonDnon_zasah7bricho"];
			_hitsound = ["TUP_Stab1","TUP_Stab2"];
			_reactsound = ["TUP_Grunt2","TUP_Grunt3"];
		};
		default {
			sleep 0.4;
			_anims = ["AmelPercMstpSnonWnonDnon_zasah1","AmelPercMstpSnonWnonDnon_zasah2","AmelPercMstpSnonWnonDnon_zasah3hard","AmelPercMstpSnonWnonDnon_zasah4","AmelPercMstpSnonWnonDnon_zasah5hard","AmelPercMstpSnonWnonDnon_zasah6hlava"];
			_hitsound = ["TUP_Melee1", "TUP_Melee2"];
			_reactsound = ["TUP_Grunt1","TUP_Grunt2"];
		};

	};

	_anim = _anims select (floor random (count _anims));
	TRACE_1("HIT ANIM",_anim);
	_target switchmove _anim;
	_playedanim = true;
} else {
	_hitsound = ["TUP_Melee1", "TUP_Melee2"];
	_reactsound = ["TUP_Grunt1","TUP_Grunt2"];
	_playedanim = false;
	_target switchmove "Die";
};

_ransound = _hitsound select (floor random (count _hitsound));
[[_target], _ransound] call CBA_fnc_globalSay;

_ransound = _reactsound select (floor random (count _reactsound));
[[_target], _ransound] call CBA_fnc_globalSay;


_wtype = getNumber(configFile>>"CfgWeapons">>_weapon>>"type");

_timespan = switch (true) do {
	case (_wtype == 1): {5 + random 5};
	case (_wtype == 2): {3 + random 5};
	case (_wtype > 2): {7 + random 5}; // MG?
	default {2 + random 3};
};

// Injure target
_inj = switch (true) do {
	case (_wtype == 1): {0.15};
	case (_wtype == 2): {0.1};
	case (_wtype > 2): {0.2}; // MG?
	default {0.07};
};

_bayonets = getArray(configFile>>"CfgBayonets">>"Bayonets">>"Items");

_hasBayonetAttached = false;
{
		if (_x in _bayonets) then
		{
			_hasBayonetAttached = true;
		};
} foreach (primaryWeaponItems _attacker);

if (_hasBayonetAttached) then {
	_inj = 0.3;
};

_target setDamage ((damage _target) + _inj);

TRACE_2("TUP Melee", diag_tickTime, name _attacker, _inj);

// If target is really injured, knock them down
if (damage _target > 0.5) then {
	[_target, _timespan, _playedanim] spawn {
		private ["_timespan"];
		PARAMS_3(_target,_timespan,_playedanim);
		if (_playedanim) then {
			sleep 0.2;
			_target playActionNow "Die";
		};
		_timeend = time + _timespan;
		waitUntil {sleep 0.412; time >= _timeend || {!alive _target} };
		if (!isNull _target && {alive _target}) then {
			[QGVAR(recover), _target] call CBA_fnc_GlobalEvent;
			_target setVariable [QGVAR(melee), false, true];
		};
	};
};

_target setVariable [QGVAR(melee), false, true];



