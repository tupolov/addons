#include <script_component.hpp>
#include <CfgPatches.hpp>

class CfgMods
{
 class ADDON
 {
  dir = "@TUP";
  name = "Tupolov - Bayonets";
  picture = "";
  hidePicture = "true";
  hideName = "true";
  actionName = "Website";
  action = "http://alivemod.com";
 };
};

class CfgBayonets
{
	class Bayonets
	{
		Items[] = {"muzzle_bayonet_ak74","muzzle_bayonet_ak74_s","muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_m7","muzzle_bayonet_m7_s","muzzle_bayonet_us_s","muzzle_bayonet_us"};
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class WeaponSlotsInfo;
class SlotInfo;
class CfgWeapons
{
	class arifle_Katiba_Base_F;
	class arifle_Katiba_F: arifle_Katiba_Base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_ak74"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};

	class arifle_Katiba_C_F: arifle_Katiba_Base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_ak74_s"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};	

	class Tavor_Base_F;
	class arifle_TRG21_F: Tavor_Base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_m7"};	
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};

	class arifle_TRG20_F: Tavor_Base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_m7_s"};	
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};	

	class mk20_base_F;
	class arifle_Mk20_F: mk20_base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_ak74"};	
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};

	class arifle_Mk20C_F: mk20_base_F
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_ak74_s"};	
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};	

	class arifle_MX_Base_F;
	class arifle_MX_F: arifle_MX_Base_F 
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_us"};
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
				compatibleItems[] += {"muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_us_s"};
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";				
			};
		};
	};	

	class Rifle_Base_F;
	class arifle_MX_SW_F: Rifle_Base_F 
	{

		class WeaponSlotsInfo: WeaponSlotsInfo
		{

			class MuzzleSlot: SlotInfo
			{
				compatibleItems[] += {"muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_us_s"};
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
				compatibleItems[] = {"muzzle_bayonet_tup","muzzle_bayonet_tup_blood","muzzle_bayonet_ak74","muzzle_bayonet_us","muzzle_bayonet_m7"};	
				picture = "\x\tup\addons\m_bayonet\data\UI\gear_VCB_L85_TES_m_ca.paa";			
			};
		};	
	};

	// Define Bayonet - based off suppressor config
	class InventoryMuzzleItem_Base_F;

	class muzzle_snds_H;

	class muzzle_bayonet_tup: muzzle_snds_H
	{
		displayName = "L85A2 Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\bayonet.paa";
		model = "\x\tup\addons\m_bayonet\bayonet.p3d";

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

	class muzzle_bayonet_tup_blood: muzzle_bayonet_tup
	{
		model = "\x\tup\addons\m_bayonet\bayonet_blood.p3d";
	};

	class muzzle_bayonet_ak74: muzzle_bayonet_tup
	{
		displayName = "Katiba/Mk20 Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\AK74_bayonet.paa";
		model = "\x\tup\addons\m_bayonet\ak_bayonet.p3d";
	};

	class muzzle_bayonet_ak74_s: muzzle_bayonet_tup
	{
		displayName = "Katiba/MK20 Compact Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\AK74_bayonet.paa";
		model = "\x\tup\addons\m_bayonet\ak_s_bayonet.p3d";
	};	

	class muzzle_bayonet_us: muzzle_bayonet_tup
	{
		displayName = "MX Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\US_bayonet.paa";
		model = "\x\tup\addons\m_bayonet\US_bayonet.p3d";
	};

	class muzzle_bayonet_us_s: muzzle_bayonet_tup
	{
		displayName = "MXC/SW Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\US_bayonet.paa";
		model = "\x\tup\addons\m_bayonet\US_s_bayonet.p3d";
	};

	class muzzle_bayonet_m7: muzzle_bayonet_tup
	{
		displayName = "TRG21 Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\m7_bayonet.paa";
		model = "\x\tup\addons\m_bayonet\m7_bayonet.p3d";
	};	

	class muzzle_bayonet_m7_s: muzzle_bayonet_tup
	{
		displayName = "TRG20 Bayonet";
		picture = "\x\tup\addons\m_bayonet\data\UI\m7_bayonet.paa";
		model = "\x\tup\addons\m_bayonet\m7_s_bayonet.p3d";
	};	
};

class CfgVehicles
{
	class NATO_Box_Base;
	class EAST_Box_Base;
	class IND_Box_Base;	
	class FIA_Box_Base_F;
	class Box_NATO_Support_F: NATO_Box_Base 
	{
		class TransportItems
		{
			class _xx_muzzle_bayonet_tup
			{
				name = "muzzle_bayonet_tup";
				count = 20;
			};
			class _xx_muzzle_bayonet_us_s
			{
				name = "muzzle_bayonet_us_s";
				count = 20;
			};					
			class _xx_muzzle_bayonet_us
			{
				name = "muzzle_bayonet_us";
				count = 20;
			};						
		};
		
	};

	class Box_EAST_Support_F: EAST_Box_Base 
	{
		class TransportItems
		{
			class _xx_muzzle_bayonet_ak74
			{
				name = "muzzle_bayonet_ak74";
				count = 20;
			};
			class _xx_muzzle_bayonet_ak74_s
			{
				name = "muzzle_bayonet_ak74_s";
				count = 20;
			};								
		};
		
	};

	class Box_IND_Support_F: IND_Box_Base 
	{
		class TransportItems
		{
			class _xx_muzzle_bayonet_ak74
			{
				name = "muzzle_bayonet_ak74";
				count = 20;
			};
			class _xx_muzzle_bayonet_ak74_s
			{
				name = "muzzle_bayonet_ak74_s";
				count = 20;
			};								
		};
		
	};

	class ReammoBox_F;
	class IG_supplyCrate_F: ReammoBox_F
	{
		class TransportItems
		{
			class _xx_muzzle_bayonet_m7
			{
				name = "muzzle_bayonet_m7";
				count = 20;
			};
			class _xx_muzzle_bayonet_m7_s
			{
				name = "muzzle_bayonet_m7_s";
				count = 20;
			};														
		};
	};	

	class Box_FIA_Support_F: FIA_Box_Base_F 
	{
		class TransportItems
		{
			class _xx_muzzle_bayonet_m7
			{
				name = "muzzle_bayonet_m7";
				count = 20;
			};
			class _xx_muzzle_bayonet_m7_s
			{
				name = "muzzle_bayonet_m7_s";
				count = 20;
			};														
		};
	};					

};