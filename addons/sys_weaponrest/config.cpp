#include <script_component.hpp>
#include <CfgPatches.hpp>

class CfgMods
{
 class ADDON
 {
  dir = "@TUP";
  name = "Tupolov - Advanced Weapon Resting";
  picture = "";
  hidePicture = "true";
  hideName = "true";
  actionName = "Website";
  action = "http://arma3live.com";
 };
};

#include <CfgVehicles.hpp>
#include <EventHandlers.hpp>

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class WeaponSlotsInfo;
class SlotInfo;
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F;
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		alive_bipod = 1;
	};
	class EBR_base_F;
	class srifle_EBR_F: EBR_base_F
	{
		alive_bipod = 0;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bipod_tup_m"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};		
	};
	class arifle_MX_SW_F: Rifle_Base_F
	{
		alive_bipod = 1;
	};

	class arifle_MX_Base_F;
	class arifle_MX_F: arifle_MX_Base_F 
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bipod_tup"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";					
			};
		};
	};

	class arifle_MXC_F: arifle_MX_Base_F 
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bipod_tup"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";					
			};
		};
	};	

	class arifle_MXM_F: arifle_MX_Base_F 
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bipod_tup_m"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";					
			};
		};
	};	

	class VCB_L85A2_TES_base: Rifle_Base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bipod_tup"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};	
	};

	// Define Bayonet - based off suppressor config
	class InventoryMuzzleItem_Base_F;

	class muzzle_snds_H;

	class muzzle_bipod_tup: muzzle_snds_H
	{
		displayName = "Harris Bipod (MX/MXC)";
		picture = "\x\tup\addons\sys_weaponrest\data\UI\bipod.paa";
		model = "\x\tup\addons\sys_weaponrest\tup_bipod.p3d";

		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass = 5;
			soundTypeIndex = 0;

			class MagazineCoef
			{
				initSpeed = 1.0;
			};
			class AmmoCoef
			{
				hit = 1.0;
				visibleFire = 0.8;
				audibleFire = 1.0;
				visibleFireTime = 1.0;
				audibleFireTime = 1.0;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
			muzzleEnd = "zaslehPoint"; // memory point in muzzle supressor's model
			alternativeFire = "";  // class in cfgWeapons with model of muzzle flash
			
			class MuzzleCoef
 			{
 				dispersionCoef = 1.0;
 				artilleryDispersionCoef = 1.0;  
 
 				fireLightCoef = 0.1;
 
 				recoilCoef = 1.0;
 				recoilProneCoef = 1.0;
 
 				minRangeCoef = 1.0; minRangeProbabCoef = 1.0;
 				midRangeCoef = 1.0; midRangeProbabCoef = 1.0;
 				maxRangeCoef = 1.0; maxRangeProbabCoef = 1.0;
 			};
		};
	};
	class muzzle_bipod_tup_m: muzzle_bipod_tup
	{
		displayName = "Harris Bipod (MXM)";
		model = "\x\tup\addons\sys_weaponrest\tup_bipod_m.p3d";		
	};
};


class CfgMovesBasic
{
	class Actions
	{
		class RifleStandActions;
		class RifleStandActions_Steady: RifleStandActions
		{
			stop = "AmovPercMstpSrasWrflDnon_Steady";
			default = "AmovPercMstpSrasWrflDnon_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		class RifleAdjustBStandActions;
		class RifleAdjustBStandActions_Steady: RifleAdjustBStandActions
		{
			stop = "AadjPercMstpSrasWrflDdown_Steady";
			default = "AadjPercMstpSrasWrflDdown_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		class RifleAdjustFStandActions;
		class RifleAdjustFStandActions_Steady: RifleAdjustFStandActions
		{
			stop = "AadjPercMstpSrasWrflDup_Steady";
			default = "AadjPercMstpSrasWrflDup_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		
		class RifleKneelActions;
		class RifleKneelActions_Steady: RifleKneelActions
		{
			stop = "AmovPknlMstpSrasWrflDnon_Steady";
			default = "AmovPknlMstpSrasWrflDnon_Steady";
			weaponOff = "AmovPknlMstpSrasWrflDnon_Steady";
			Stand = "AmovPknlMstpSrasWrflDnon_Steady";
			Crouch = "AmovPknlMstpSrasWrflDnon_Steady";
			CanNotMove = "AmovPknlMstpSrasWrflDnon_Steady";
			FireNotPossible = "AmovPknlMstpSrasWrflDnon_Steady";
			strokeGun = "AmovPknlMstpSrasWrflDnon_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		class RifleAdjustFKneelActions;
		class RifleAdjustFKneelActions_Steady: RifleAdjustFKneelActions
		{
			stop = "AadjPknlMstpSrasWrflDup_Steady";
			default = "AadjPknlMstpSrasWrflDup_Steady";
			weaponOff = "AadjPknlMstpSrasWrflDup_Steady";
			Stand = "AadjPknlMstpSrasWrflDup_Steady";
			Crouch = "AadjPknlMstpSrasWrflDup_Steady";
			CanNotMove = "AadjPknlMstpSrasWrflDup_Steady";
			FireNotPossible = "AadjPknlMstpSrasWrflDup_Steady";
			strokeGun = "AadjPknlMstpSrasWrflDup_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		class RifleAdjustBKneelActions;
		class RifleAdjustBKneelActions_Steady: RifleAdjustBKneelActions
		{
			stop = "AadjPknlMstpSrasWrflDdown_Steady";
			default = "AadjPknlMstpSrasWrflDdown_Steady";
			weaponOff = "AadjPknlMstpSrasWrflDdown_Steady";
			Stand = "AadjPknlMstpSrasWrflDdown_Steady";
			Crouch = "AadjPknlMstpSrasWrflDdown_Steady";
			CanNotMove = "AadjPknlMstpSrasWrflDdown_Steady";
			FireNotPossible = "AadjPknlMstpSrasWrflDdown_Steady";
			strokeGun = "AadjPknlMstpSrasWrflDdown_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		
		
		class RifleProneActions;
		class RifleProneActions_Bipod: RifleProneActions
		{
			stop = "AmovPpneMstpSrasWrflDnon_Bipod";
			default = "AmovPpneMstpSrasWrflDnon_Bipod";
			weaponOff = "AmovPpneMstpSrasWrflDnon_Bipod";
			limitfast = 1;
			turnSpeed = 0.1;
		};
		class RifleAdjustBProneActions;
		class RifleAdjustBProneActions_Steady: RifleAdjustBProneActions
		{
			stop = "AadjPpneMstpSrasWrflDdown_Steady";
			default = "AadjPpneMstpSrasWrflDdown_Steady";
			weaponOff = "AadjPpneMstpSrasWrflDdown_Steady";
			limitfast = 1;
			turnSpeed = 0.1;
		};
		class RifleAdjustFProneActions;
		class RifleAdjustFProneActions_Steady: RifleAdjustFProneActions
		{
			stop = "AadjPpneMstpSrasWrflDup_Steady";
			default = "AadjPpneMstpSrasWrflDup_Steady";
			weaponOff = "AadjPpneMstpSrasWrflDup_Steady";
			limitfast = 1;
			turnSpeed = 0.1;
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AmovPercMstpSrasWrflDnon;
		class AmovPercMstpSrasWrflDnon_Steady: AmovPercMstpSrasWrflDnon
		{
			actions = "RifleStandActions_Steady";
			aimPrecision = 0.39;
			aiming = "aimingLying";
			camshakefire = 0.4;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AmovPercMstpSrasWrflDnon_Steady",0.02};
			connectFrom[] = {"AmovPercMstpSrasWrflDnon_Steady",0.02};
			interpolateFrom[] = {"AmovPercMstpSrasWrflDnon",0.02};
			interpolateTo[] = {"AmovPercMstpSrasWrflDnon",0.02};
		};
		class AadjPercMstpSrasWrflDdown;
		class AadjPercMstpSrasWrflDdown_Steady: AadjPercMstpSrasWrflDdown
		{
			actions = "RifleAdjustBStandActions_Steady";
			aimPrecision = 0.39;
			aiming = "aimingLying";
			camshakefire = 0.4;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AadjPercMstpSrasWrflDdown_Steady",0.02};
			connectFrom[] = {"AadjPercMstpSrasWrflDdown_Steady",0.02};
			interpolateFrom[] = {"AadjPercMstpSrasWrflDdown",0.02};
			interpolateTo[] = {"AadjPercMstpSrasWrflDdown",0.02};
		};
		class AadjPercMstpSrasWrflDup;
		class AadjPercMstpSrasWrflDup_Steady: AadjPercMstpSrasWrflDup
		{
			actions = "RifleAdjustFStandActions_Steady";
			aimPrecision = 0.39;
			aiming = "aimingLying";
			camshakefire = 0.4;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AadjPercMstpSrasWrflDup_Steady",0.02};
			connectFrom[] = {"AadjPercMstpSrasWrflDup_Steady",0.02};
			interpolateFrom[] = {"AadjPercMstpSrasWrflDup",0.02};
			interpolateTo[] = {"AadjPercMstpSrasWrflDup",0.02};
		};
		
		
		class AmovPknlMstpSrasWrflDnon;
		class AmovPknlMstpSrasWrflDnon_Steady: AmovPknlMstpSrasWrflDnon
		{
			actions = "RifleKneelActions_Steady";
			aimPrecision = 0.195;
			aiming = "aimingLying";
			camshakefire = 0.35;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AmovPknlMstpSrasWrflDnon_Steady",0.02};
			connectFrom[] = {"AmovPknlMstpSrasWrflDnon_Steady",0.02};
			interpolateFrom[] = {"AmovPknlMstpSrasWrflDnon",0.02};
			interpolateTo[] = {"AmovPknlMstpSrasWrflDnon",0.02};
		};
		class AadjPknlMstpSrasWrflDdown;
		class AadjPknlMstpSrasWrflDdown_Steady: AadjPknlMstpSrasWrflDdown
		{
			actions = "RifleAdjustBKneelActions_Steady";
			aimPrecision = 0.195;
			aiming = "aimingLying";
			camshakefire = 0.35;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AadjPknlMstpSrasWrflDdown_Steady",0.02};
			connectFrom[] = {"AadjPknlMstpSrasWrflDdown_Steady",0.02};
			interpolateFrom[] = {"AadjPknlMstpSrasWrflDdown",0.02};
			interpolateTo[] = {"AadjPknlMstpSrasWrflDdown",0.02};
		};
		class AadjPknlMstpSrasWrflDup;
		class AadjPknlMstpSrasWrflDup_Steady: AadjPknlMstpSrasWrflDup
		{
			actions = "RifleAdjustFKneelActions_Steady";
			aimPrecision = 0.195;
			aiming = "aimingLying";
			camshakefire = 0.35;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AadjPknlMstpSrasWrflDup_Steady",0.02};
			connectFrom[] = {"AadjPknlMstpSrasWrflDup_Steady",0.02};
			interpolateFrom[] = {"AadjPknlMstpSrasWrflDup",0.02};
			interpolateTo[] = {"AadjPknlMstpSrasWrflDup",0.02};
		};

		
		class AmovPpneMstpSrasWrflDnon: AmovPercMstpSrasWrflDnon
		{
			variantsAI[] = {"Alive_AmovPpneMstpSrasWrflDnon_Supported",1};
			variantAfter[] = {1,2,3};
		};
		class AmovPpneMrunSlowWrflDf: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_turnL: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_turnR: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_healed: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_Bipod: AmovPpneMstpSrasWrflDnon
		{
			actions = "RifleProneActions_Bipod";
			aimPrecision = 0.07;
			aiming = "aimingLying";
			camshakefire = 0.3;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AmovPpneMstpSrasWrflDnon_Bipod",0.02};
			connectFrom[] = {"AmovPpneMstpSrasWrflDnon_Bipod",0.02};
			interpolateFrom[] = {"AmovPpneMstpSrasWrflDnon",0.02};
			interpolateTo[] = {"AmovPpneMstpSrasWrflDnon",0.02};
		};
		class Alive_AmovPpneMstpSrasWrflDnon_Supported: AmovPpneMstpSrasWrflDnon_Bipod
		{
			equivalentTo = "AmovPpneMstpSrasWrflDnon";
			aimPrecision = 0.09;
		};
		
		class AadjPpneMstpSrasWrflDdown;
		class AadjPpneMstpSrasWrflDdown_Steady: AadjPpneMstpSrasWrflDdown
		{
			actions = "RifleAdjustBProneActions_Steady";
			aimPrecision = 0.09;
			aiming = "aimingLying";
			camshakefire = 0.3;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AadjPpneMstpSrasWrflDdown_Steady",0.02};
			connectFrom[] = {"AadjPpneMstpSrasWrflDdown_Steady",0.02};
			interpolateFrom[] = {"AadjPpneMstpSrasWrflDdown",0.02};
			interpolateTo[] = {"AadjPpneMstpSrasWrflDdown",0.02};
		};
		class AadjPpneMstpSrasWrflDup;
		class AadjPpneMstpSrasWrflDup_Steady: AadjPpneMstpSrasWrflDup
		{
			actions = "RifleAdjustFProneActions_Steady";
			aimPrecision = 0.09;
			aiming = "aimingLying";
			camshakefire = 0.3;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AadjPpneMstpSrasWrflDup_Steady",0.02};
			connectFrom[] = {"AadjPpneMstpSrasWrflDup_Steady",0.02};
			interpolateFrom[] = {"AadjPpneMstpSrasWrflDup",0.02};
			interpolateTo[] = {"AadjPpneMstpSrasWrflDup",0.02};
		};
	};
};
class CfgSounds
{
	class alive_deployweapon_1
	{
		name = "alive_deployweapon_1";
		sound[] = {"x\tup\addons\sys_weaponrest\sound\depl1.ogg",5,1};
		titles[] = {};
	};
	class alive_deployweapon_2
	{
		name = "alive_deployweapon_2";
		sound[] = {"x\tup\addons\sys_weaponrest\sound\depl2.ogg",5,1};
		titles[] = {};
	};
	class alive_deployweapon_3
	{
		name = "alive_deployweapon_3";
		sound[] = {"x\tup\addons\sys_weaponrest\sound\depl3.ogg",5,1};
		titles[] = {};
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
		class Showcase_Tup_WeaponRest
		{
			briefingName = "Weapon Resting and Bipods";
			directory = "x\tup\addons\sys_weaponrest\showcases\Showcase_WeaponRest.Stratis";
		};
	};
};