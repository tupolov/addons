#include "script_component.hpp"

private ["_weapon","_weaponType","_anims","_anim","_type","_hasBayonetAttached"];

PARAMS_1(_target);

// type 0 = grab, 1 = melee, 2 = rifle butt, 3 = bayonet

// Check to see if target is valid
if (isNull _target) exitWith { false };

if (side _target == side player) exitWith { false };

// Ensure target is man
if !(_target isKindOf "Man") exitWith { false };

// Ensure target is alive
if (!alive _target) exitWith { false };

// Protect the player during the attempt
player allowDamage false;

// stop AI from reacting
_target disableAI "ANIM";

TRACE_1("CURRENT ANIM",animationstate player);

// Get the weapon and weapon type
_weapon = currentWeapon player;
_weaponType = getNumber(configFile>>"CfgWeapons">>_weapon>>"type");

TRACE_2("",_weapon, _weaponType);

_bayonets = getArray(configFile>>"CfgBayonets">>"Bayonets">>"Items");

_hasBayonetAttached = false;
{
		if (_x in _bayonets) then
		{
			_hasBayonetAttached = true;
		};
} foreach (primaryWeaponItems player);


if (_weaponType > 0) then {
	if (_hasBayonetAttached) then {
		player playActionNow "thrust2";
		_type = 3;
	} else {
		player switchmove "AmelPercMstpSlowWrflDnon_StrokeGun";
		_type = 2;
	};
} else {
	// if the player is close enough and behind the target then go for the throat takedown
	if ( ((visiblePosition player) distance (visiblePosition _target) < 3) && ( (abs ((getdir player) - (getdir _target)) < 90) ||  (abs ((getdir player) - (getdir _target)) > 270) ) ) then {
		player playactionNow "knifecutThroat";
		_type = 0;
	} else {
		_anims = ["AmelPercMstpSnonWnonDnon_amaterUder1","AmelPercMstpSnonWnonDnon_amaterUder2","AmelPercMstpSnonWnonDnon_amaterUder3"];
		_anim = _anims select (floor random (count _anims));
		player switchmove _anim;
		_type = 1;
	};
};

[_target, _weapon, _type] spawn {
	private ["_target","_weapon","_type"];
	_target = _this select 0;
	_weapon = _this select 1;
	_type = _this select 2;
	sleep 0.24;
	if ((visiblePosition player) distance (visiblePosition _target) < 5) then {
		TRACE_2("Stealth Takedown", _target, _weapon);
		[QGVAR(stealth), [_target, _weapon, player, _type]] call CBA_fnc_receiverOnlyEvent;
		if ("muzzle_bayonet_tup" in (primaryWeaponItems player)) then
		{
				private "_id";
				player addPrimaryWeaponItem "muzzle_bayonet_tup_blood";
				_id = player addAction ["Clean Bayonet",{(_this select 1) addPrimaryWeaponItem "muzzle_bayonet_tup"; (_this select 1) removeAction (_this select 3);},_id,1,false,true,"","'muzzle_bayonet_tup_blood' in (primaryWeaponItems player)"];
		};
	} else {
		_target enableAI "ANIM";
	};
	player allowDamage true;
};

TRACE_1("NEW ANIM",animationstate player);



