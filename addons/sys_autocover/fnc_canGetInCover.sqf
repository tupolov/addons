/* alive_sys_autocover| fnc_canGetInCover.sqf - "Get in cover" | (c) Tupolov*/

#include "script_component.hpp"

#define __man_height 1.7

private ["_currentHeight","_cover","_coverheight","_middleoffset","_debug","_colorred","_colorgreen","_dir","_leftoffest","_rightoffest","_frontoffest","_downoffset","_weaponpitch","_distance","_posleft","_posleft0","_posleft1","_posright","_posright0","_posright1","_coverHeight","_cover","_num","_posmiddle","_posmiddle0","_posmiddle1","_height","_cAnim","_colorblue","_colorblack","_colorwhite","_backoffset"];

PARAMS_1(_cAnim); 
	
	_colorred=[1,0,0,1];
	_colorgreen=[0,1,0,1];
	_colorblue=[0,0,1,1];
	_colorblack=[0,0,0,1];
	_colorwhite=[1,1,1,1];
	
	_distance = 1;
	
	_cover = false;
	_coverHeight = 0;
	
	_dir=direction  player;
	_leftoffest=0.6;
	_rightoffest=0.7;
	_frontoffest=1;
	_backoffset=1;
	_middleoffset = 0.01;
	_downoffset=0.1;
	
	// Get current player height
	_currentHeight = (ASLToATL (eyepos player)) select 2;
	
	// for each height, draw left, middle, right lines and check for intersect. If intersect, exit and record height.
	_height = 0.1;
	
	while {_height < (_currentHeight + _downoffset)} do {
		_posleft=[(eyepos player select 0)+_leftoffest*(sin (_dir-90)),(eyepos player select 1)+_leftoffest*(cos (_dir-90)), ((getposASL player) select 2) + _height];
		_posleft0=[(_posleft  select 0)-_distance*(sin _dir),( _posleft select 1)-_distance*(cos _dir),( _posleft select 2)];
		_posleft1=[(_posleft  select 0)+_distance*(sin _dir),( _posleft select 1)+_distance*(cos _dir),(_posleft select 2)];

		_posright=[(eyepos player select 0)+_rightoffest*(sin (_dir+90)),(eyepos player select 1)+_rightoffest*(cos (_dir+90)),((getposASL player) select 2) + _height];
		_posright0=[( _posright select 0)-_distance*(sin _dir),( _posright select 1)-_distance*(cos _dir),( _posright select 2)];
		_posright1=[( _posright select 0)+_distance*(sin _dir),( _posright select 1)+_distance*(cos _dir),( _posright select 2)];

		_posmiddle=[(eyepos player select 0)+_middleoffset*(sin (_dir+90)),(eyepos player select 1)+_middleoffset*(cos (_dir+90)),((getposASL player) select 2) + _height];
		_posmiddle0=[( _posmiddle select 0)-_distance*(sin _dir),( _posmiddle select 1)-_distance*(cos _dir),( _posmiddle select 2)];
		_posmiddle1=[( _posmiddle select 0)+_distance*(sin _dir),( _posmiddle select 1)+_distance*(cos _dir),( _posmiddle select 2)];

		_debug = false;
		if (_debug) then {
			_num = time;
			while {time < _num + 1} do {
					drawLine3D [ASLToATL _posleft0,ASLToATL _posleft1,_colorwhite];
					drawLine3D [ASLToATL _posright0,ASLToATL _posright1,_colorblue];
					drawLine3D [ASLToATL _posmiddle0,ASLToATL _posmiddle1,_colorred];
					
			};
		};

		if !(lineIntersects [_posmiddle0,_posmiddle1,player] || {lineIntersects [_posleft0,_posleft1,player] || lineIntersects [_posright0,_posright1,player]}) exitWith
		{
			TRACE_3("GETINCOVER", _height, _currentHeight, _cover);
			_cover = true;
		};
		_height = _height + _downoffset;
	};
	
	if ((vehicle player!=player) or !(alive player)) then {_height = 0;};
	if (_height == 0.1) then {_height = 0};
	if (_height > _currentHeight) then {_height = -1};
	
_height;



