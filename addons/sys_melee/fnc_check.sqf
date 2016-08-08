#include "script_component.hpp"

// Original code by ACE2 team

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

// Can't hit a target that is already down
if (_target getVariable [QGVAR(melee), false]) exitWith { false };

// Check weapon is a valid type
if !(getNumber(configFile >> "cfgweapons" >> currentweapon player >> "type") in [0,1,2]) exitWith { false };

// Check to see if they are pressing the key before last action has completed
if (GVAR(meleepressed) == time) exitwith { false };

// Set time key was pressed
GVAR(meleepressed) = time;

TRACE_1("CURRENT ANIM",animationstate player);

// Get the weapon and weapon type
_weapon = currentWeapon player;
_weaponType = getNumber(configFile>>"CfgWeapons">>_weapon>>"type");
_bayonets = getArray(configFile>>"CfgBayonets">>"Bayonets">>"Items");

_hasBayonetAttached = false;
{
		if (_x in _bayonets) then
		{
			_hasBayonetAttached = true;
		};
} foreach (primaryWeaponItems player);


TRACE_3("",_weapon, _weaponType, GVAR(meleepressed));

if (_weaponType == 0) then {
	_anims = ["AmelPercMstpSnonWnonDnon_amaterUder1","AmelPercMstpSnonWnonDnon_amaterUder2","AmelPercMstpSnonWnonDnon_amaterUder3"];
	_anim = _anims select (floor random (count _anims));
	TRACE_1("",_anim);
	player switchMove _anim;
	_type = 1;
	[_target, _weapon, _type] spawn {
		private ["_target","_weapon","_type"];
		_target = _this select 0;
		_weapon = _this select 1;
		_type = _this select 2;
		sleep 0.5;
		if ((visiblePosition player) distance (visiblePosition _target) < 2.5) then {
			TRACE_2("Melee No weapon", _target, _weapon);
			[QGVAR(melee), [_target, _weapon, player,_type]] call CBA_fnc_receiverOnlyEvent;
		};
	};
} else {
	// check to see if player has bayonet attached
	if (_hasBayonetAttached) then {
		player playActionNow "Thrust2";
		_type = 3;
	} else {
		player switchMove "AmelPercMstpSlowWrflDnon_StrokeGun";
		_type = 2;
	};
	TRACE_1("PLAYER ANIM",animationstate player);
	[_target, _weapon, _type] spawn {
		private ["_target","_weapon","_type"];
		_target = _this select 0;
		_weapon = _this select 1;
		_type = _this select 2;
		sleep 0.5;
		if ((visiblePosition player) distance (visiblePosition _target) < 2.5) then {
			TRACE_2("Melee with weapon", _target, _weapon);
			[QGVAR(melee), [_target, _weapon, player, _type]] call CBA_fnc_receiverOnlyEvent;
			//Switch bayonet for bloody bayonet
			if ("muzzle_bayonet_tup" in (primaryWeaponItems player)) then
			{
					private "_id";
					player addPrimaryWeaponItem "muzzle_bayonet_tup_blood";
					_id = player addAction ["Clean Bayonet",{(_this select 1) addPrimaryWeaponItem "muzzle_bayonet_tup"; (_this select 1) removeAction (_this select 3);},_id,1,false,true,"","'muzzle_bayonet_tup_blood' in (primaryWeaponItems player)"];
			};
		};
	};
};


