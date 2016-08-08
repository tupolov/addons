#include "script_component.hpp"

private ["_stealth","_wtype","_anim","_anims", "_playedanim", "_ransound","_hitsound","_reactsound"];

PARAMS_4(_target,_weapon,_killer,_type);

// type 0 = grab, 1 = melee, 2 = rifle butt, 3 = bayonet

TRACE_1("",_this);
	

// Make the target react to the hit
if ((_target call CBA_fnc_getUnitAnim) select 0 != "prone") then {

	switch (_type) do {
		case 0 : {
			sleep 0.1;
			//Grab the target
			_target attachTo [_killer, [-0.1,0.55,-0.1],"rightfoot"];
			_anims = ["knifeVictim"];
			_hitsound = ["TUP_Slice1","TUP_Slice2"];
			_reactsound = ["TUP_strangle1","TUP_strangle2"];
		};
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
	if (_type == 0) then {
		_target playActionNow _anim;
	} else {
		_target switchmove _anim;
	};
	_playedanim = true;
} else {
	_playedanim = false;
	_target playActionNow "Die";
};

_ransound = _hitsound select (floor random (count _hitsound));
[[_target], _ransound] call CBA_fnc_globalSay;

_ransound = _reactsound select (floor random (count _reactsound));
[[_target], _ransound] call CBA_fnc_globalSay;

// Wait for anim to play out
if (_playedanim) then {
	sleep 1;
};
	
// You can't have a killing blow if they know you are coming at them
_stealth = _target knowsAbout _killer;
if (_stealth < 4) then {
	_target setDamage 1;
} else {
	_target setDamage (damage _target + (0.8 + (random 0.31)));
};

TRACE_4("TUP Stealth", _target, name _killer, damage _target, _stealth);

detach _target;
_target enableAI "ANIM";

