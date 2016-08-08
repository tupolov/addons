#include <script_component.hpp>
#include <CfgPatches.hpp>

class CfgMods
{
 class ADDON
 {
  dir = "@TUP";
  name = "Tupolov - Melee";
  picture = "";
  hidePicture = "true";
  hideName = "true";
  actionName = "Website";
  action = "http://alivemod.com";
 };
};

#include <CfgVehicles.hpp>
#include <EventHandlers.hpp>

class CfgSounds
{
	class TUP_Grunt1
	{
		name = "TUP_Grunt1";
		sound[] = {"\x\tup\addons\sys_melee\sound\grunt1.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Grunt2
	{
		name = "TUP_Grunt2";
		sound[] = {"\x\tup\addons\sys_melee\sound\grunt2.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Grunt3
	{
		name = "TUP_Grunt3";
		sound[] = {"\x\tup\addons\sys_melee\sound\grunt3.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Melee1
	{
		name = "TUP_Melee1";
		sound[] = {"\x\tup\addons\sys_melee\sound\melee1.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Melee2
	{
		name = "TUP_Melee2";
		sound[] = {"\x\tup\addons\sys_melee\sound\melee2.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Slice1
	{
		name = "TUP_Slice1";
		sound[] = {"\x\tup\addons\sys_melee\sound\slice1.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Slice2
	{
		name = "TUP_Slice2";
		sound[] = {"\x\tup\addons\sys_melee\sound\slice2.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Stab1
	{
		name = "TUP_Stab1";
		sound[] = {"\x\tup\addons\sys_melee\sound\stab1.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Stab2
	{
		name = "TUP_Stab2";
		sound[] = {"\x\tup\addons\sys_melee\sound\stab2.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Strangle1
	{
		name = "TUP_Strangle1";
		sound[] = {"\x\tup\addons\sys_melee\sound\strangle1.ogg","db-10",1};
		titles[] = {};
	};
	class TUP_Strangle2
	{
		name = "TUP_Strangle2";
		sound[] = {"\x\tup\addons\sys_melee\sound\strangle2.ogg","db-10",1};
		titles[] = {};
	};

};

class CfgMovesBasic
{
	class ManActions
	{
		Thrust[] = {"Thrust","Gesture"};
		Thrust2[] = {"Thrust_2","Gesture"};
		ThrustMode[] = {"ThrustMode","Gesture"};
		knifeCutThroat[] = {"action_cutThroat","Gesture"};
		knifeVictim[] = {"action_cutThroat_victim","Gesture"};
	};
	class Actions
	{
		
		class RifleLowStandActions;
		class RifleLowStandActions_StrokeGun: RifleLowStandActions
		{
			stop = "AmovPercMstpSlowWrflDnon";
			default = "AmelPercMstpSlowWrflDnon_StrokeGun";
		};
		class RifleAdjustBStandActions;
		class RifleAdjustBStandActions_StrokeGun: RifleAdjustBStandActions
		{
			stop = "AadjPercMstpSrasWrflDdown";
			default = "AmelPercMstpSlowWrflDnon_StrokeGun";
		};
		class RifleAdjustFStandActions;
		class RifleAdjustFStandActions_StrokeGun: RifleAdjustFStandActions
		{
			stop = "AadjPercMstpSrasWrflDup";
			default = "AmelPercMstpSlowWrflDnon_StrokeGun";
		};
		
		class PistolLowStandActions;
		class PistolLowStandActions_StrokeGun: PistolLowStandActions
		{
			stop = "AmovPercMstpSlowWpstDnon";
			default = "AmelPercMstpSlowWpstDnon_StrokeGun";
		};
		class PistolAdjustBStandActions;
		class PistolAdjustBStandActions_StrokeGun: PistolAdjustBStandActions
		{
			stop = "AadjPercMstpSrasWpstDdown";
			default = "AmelPercMstpSlowWpstDnon_StrokeGun";
		};
		class PistolAdjustFStandActions;
		class PistolAdjustFStandActions_StrokeGun: PistolAdjustFStandActions
		{
			stop = "AadjPercMstpSrasWpstDup";
			default = "AmelPercMstpSlowWpstDnon_StrokeGun";
		};
	};
};	

class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AmovPercMstpSnonWnonDnon;
		class AmovPercMstpSlowWrflDnon;
		class AmovPercMstpSlowWpstDnon;
		class AmelPercMstpSlowWrflDnon_StrokeGun: AmovPercMstpSlowWrflDnon
		{
			actions = "RifleLowStandActions_StrokeGun";
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSlowWrflDnon_StrokeGun";
			speed = 0.232558;
			looped = 0;
			ConnectTo[] = {"AmovPercMstpSlowWrflDnon",0.02,"AmelPercMstpSlowWrflDnon_StrokeGun",0.02};
			interpolateTo[] = {"DeadState",0.01};
			variantsPlayer[] = {"AmelPercMstpSlowWrflDnon_StrokeGun",1};
		};
		class AmelPercMstpSlowWpstDnon_StrokeGun: AmovPercMstpSlowWpstDnon
		{
			actions = "PistolLowStandActions_StrokeGun";
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSlowWrflDnon_StrokeGun";
			speed = 0.232558;
			looped = 0;
			ConnectTo[] = {"AmovPercMstpSlowWrflDnon",0.02,"AmelPercMstpSlowWpstDnon_StrokeGun",0.02};
			interpolateTo[] = {"DeadState",0.01};
			variantsPlayer[] = {"AmelPercMstpSlowWpstDnon_StrokeGun",1};
		};
		class AmelPercMstpSnonWnonDnon_amaterUder1: AmovPercMstpSnonWnonDnon
		{
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_amaterUder1";
			speed = 0.27027;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_amaterUder1",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_amaterUder1",0.02};
			variantsPlayer[] = {"AmelPercMstpSnonWnonDnon_amaterUder1",0.34,"AmelPercMstpSnonWnonDnon_amaterUder2",0.33,"AmelPercMstpSnonWnonDnon_amaterUder3",0.33};
		};
		class AmelPercMstpSnonWnonDnon_amaterUder2: AmelPercMstpSnonWnonDnon_amaterUder1
		{
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_amaterUder2";
			speed = 0.348837;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_amaterUder2",0.02};
			InterpolateTo[] = {"DeadState",0.01};
		};
		class AmelPercMstpSnonWnonDnon_amaterUder3: AmelPercMstpSnonWnonDnon_amaterUder1
		{
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_amaterUder3";
			speed = 0.223881;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_amaterUder3",0.02};
			InterpolateTo[] = {"DeadState",0.01};
		};
		class AmelPercMstpSnonWnonDnon_zasah1: AmelPercMstpSnonWnonDnon_amaterUder1
		{
			interpolationRestart = 1;
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah1";
			speed = 0.566038;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah1",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_zasah1",0.02};
			variantsAI[] = {"AmelPercMstpSnonWnonDnon_zasah1",0.2,"AmelPercMstpSnonWnonDnon_zasah2",0.15,"AmelPercMstpSnonWnonDnon_zasah3hard",0.15,"AmelPercMstpSnonWnonDnon_zasah4",0.15,"AmelPercMstpSnonWnonDnon_zasah5hard",0.15,"AmelPercMstpSnonWnonDnon_zasah6hlava",0.1,"AmelPercMstpSnonWnonDnon_zasah7bricho",0.1};
			variantsPlayer[] = {"AmelPercMstpSnonWnonDnon_zasah1",0.2,"AmelPercMstpSnonWnonDnon_zasah2",0.15,"AmelPercMstpSnonWnonDnon_zasah3hard",0.15,"AmelPercMstpSnonWnonDnon_zasah4",0.15,"AmelPercMstpSnonWnonDnon_zasah5hard",0.15,"AmelPercMstpSnonWnonDnon_zasah6hlava",0.1,"AmelPercMstpSnonWnonDnon_zasah7bricho",0.1};
		};
		class AmelPercMstpSnonWnonDnon_zasah2: AmelPercMstpSnonWnonDnon_zasah1
		{
			interpolationRestart = 1;
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah2";
			speed = 0.294118;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah2",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_zasah2",0.02};
		};
		class AmelPercMstpSnonWnonDnon_zasah3hard: AmelPercMstpSnonWnonDnon_zasah1
		{
			interpolationRestart = 1;
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah3hard";
			speed = 0.27027;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah3hard",0.02};
			InterpolateTo[] = {"DeadState",0.01};
		};
		class AmelPercMstpSnonWnonDnon_zasah4: AmelPercMstpSnonWnonDnon_zasah1
		{
			interpolationRestart = 1;
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah4";
			speed = 0.222222;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah4",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_zasah4",0.02};
		};
		class AmelPercMstpSnonWnonDnon_zasah5hard: AmelPercMstpSnonWnonDnon_zasah1
		{
			interpolationRestart = 1;
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah5hard";
			speed = 0.189873;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah5hard",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_zasah5hard",0.02};
		};
		class AmelPercMstpSnonWnonDnon_zasah6hlava: AmelPercMstpSnonWnonDnon_zasah1
		{
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah6hlava";
			speed = 0.227273;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah6hlava",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_zasah6hlava",0.02};
		};
		class AmelPercMstpSnonWnonDnon_zasah7bricho: AmelPercMstpSnonWnonDnon_zasah1
		{
			interpolationRestart = 1;
			file = "\x\tup\addons\sys_melee\anims\AmelPercMstpSnonWnonDnon_zasah7bricho";
			speed = 0.232558;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02,"AmelPercMstpSnonWnonDnon_zasah7bricho",0.02};
			InterpolateTo[] = {"DeadState",0.01,"AmelPercMstpSnonWnonDnon_zasah7bricho",0.02};
		};
	};
};

class CfgGesturesMale
{
	class ManActions;
	class Default;
	class States
	{
		class WeaponMagazineReloadStand_g;
		class Thrust: WeaponMagazineReloadStand_g
		{
			file = "\x\tup\addons\sys_melee\anims\Bayonet\thrust";
			speed = 1;
			rightHandIKBeg = 0;
			rightHandIKEnd = 0;
			rightHandIKCurve[] = {0};
			leftHandIKBeg = 0;
			leftHandIKEnd = 0;
			leftHandIKCurve[] = {};
			enableOptics = "false";
			disableWeapons = "false";
			disableWeaponsLong = "false";
			canPullTrigger = "true";
			mask = "upperTorso";
		};
		class Thrust_2: Thrust
		{
			file = "\x\tup\addons\sys_melee\anims\Bayonet\thrust_v2";
			rightHandIKBeg = 0;
			rightHandIKEnd = 0;
			leftHandIKBeg = 0;
			leftHandIKEnd = 0;
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};
		};
		class ThrustMode: Thrust_2
		{
			file = "\x\tup\addons\sys_melee\anims\Bayonet\thrustMode";
			looped = "true";
			enableOptics = "false";
			rightHandIKBeg = 0;
			rightHandIKEnd = 0;
			leftHandIKBeg = 0;
			leftHandIKEnd = 0;
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};
		};
		class action_cutThroat: Thrust_2
		{
			file = "\x\tup\addons\sys_melee\anims\stealthTakedown_knife";
			speed = 0.33;
			mask = "upperTorso";
		};
		class action_cutThroat_victim: action_cutThroat
		{
			file = "\x\tup\addons\sys_melee\anims\stealthTakedown_knife_victim";
			speed = 0.4;
		};
	};
};

class CfgMissions
{
	class Challenges{};
	class Missions
	{
		displayName = "$STR_A3_CFGMISSIONS_MISSIONS0";
		overview = "";
	};
	class Showcases
	{
		displayName = "$STR_A3_CFGMISSIONS_SHOWCASES0";
		briefingName = "$STR_A3_CFGMISSIONS_SHOWCASES0";
		author = "$STR_A3_Bohemia_Interactive";
		overviewPicture = "a3\Missions_F_Beta\data\img\Campaign_overview_CA.paa";
		overviewText = "$STR_A3_CFGMISSIONS_SHOWCASES0";
		class Showcase_Tup_Melee
		{
			briefingName = "Melee";
			directory = "x\tup\addons\sys_melee\showcases\Showcase_Melee.Stratis";
		};
		class Showcase_Tup_Stealth
		{
			briefingName = "Stealth";
			directory = "x\tup\addons\sys_melee\showcases\Showcase_Stealth.Stratis";
		};
		class Showcase_Tup_Bayonet
		{
			briefingName = "Bayonets";
			directory = "x\tup\addons\sys_melee\showcases\Showcase_Bayonet.Stratis";
		};		
	};
};