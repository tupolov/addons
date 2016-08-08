class CfgPatches
{
	class vcb_hats_A3
	{
		units[] = {"Box_VCB_Support_F"};
		weapons[] = {"H_Booniehat_VCB","H_Cap_black_VCB","H_Cap_VCB","H_Cap_tan_VCB","H_Cap_Funny_VCB","H_Beanie_VCB","H_Beret_VCB","H_HelmetCrew_VCB","H_PilotHelmetFighter_VCB","H_CrewHelmetHeli_VCB","H_PilotHelmetHeli_VCB","H_Helmet_VCB"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F","A3_Weapons_F","A3_Characters_F_Beta"};
	};
};

class CfgAddons
{
 class PreloadAddons
 {
  class vcb_hats_A3
  {
   list[] = {"vcb_hats_A3"};
  };
 };
};

class cfgWeapons
{
	class InventoryItem_Base_F;
	class ItemCore;
	class Uniform_Base;
	class H_BoonieHat_khk;
	class H_Cap_red;
	class H_Cap_headphones;
	class H_MilCap_ocamo;
	class H_Bandanna_surfer;
	class H_Watchcap_blk;
	class H_Beret_blk;
	class H_Shemag_olive;
	class H_ShemagOpen_khk;
	class H_HelmetB;
	class H_HelmetCrew_B;
	class H_PilotHelmetFighter_B;
	class H_CrewHelmetHeli_B;
	class H_PilotHelmetHeli_B;
	class H_Booniehat_VCB: H_Booniehat_khk
	{
		displayName = "VCB Boonie Hat";
		picture = "\vcb_hats_A3\Data\UI\icon_H_booniehat_vcb_ca.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\booniehat_vcb_co.paa"};
	};
	
	class H_Cap_VCB: H_Cap_red
	{
		displayName = "VCB Patrol Cap";
		picture = "\vcb_hats_A3\Data\UI\icon_H_Cap_VCB_CA.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\cap_vcb_co.paa"};
	};
	
	class H_Cap_black_VCB: H_Cap_red
	{
		displayName = "VCB Black Cap";
		picture = "\vcb_hats_A3\Data\UI\icon_H_Cap_VCB_CA.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\cap_black_vcb_co.paa"};
	};
	
	class H_Cap_tan_VCB: H_Cap_red
	{
		displayName = "VCB Tan Cap";
		picture = "\vcb_hats_A3\Data\UI\icon_H_Cap_VCB_CA.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\cap_tan_VCB_co.paa"};
	};
	
	class H_Cap_funny_VCB:  H_Cap_red
	{
		displayName = "VCB Black Cap (Logo)";
		picture = "\vcb_hats_A3\Data\UI\icon_H_Cap_VCB_CA.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\cap_black_funny_vcb_co.paa"};
	};
	
	class H_Beanie_VCB: H_Watchcap_blk
	{
		displayName = "VCB Beanie";
		picture = "\vcb_hats_A3\Data\UI\icon_H_beanie_vcb_ca.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\beanie_vcb_co.paa"};
	};
	
	class H_Beret_VCB: H_Beret_blk
	{
		displayName = "VCB Beret";
		picture = "\vcb_hats_A3\Data\UI\icon_H_beret_vcb_ca.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\headgear_beret_VCB_co.paa"};
	};
	
	class H_Helmet_VCB: H_HelmetB
	{
		displayName = "VCB Helmet";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\equip_vcb_co.paa"};
	};
	
	class H_HelmetCrew_VCB: H_HelmetCrew_B
	{
		displayName = "VCB Crew Helmet";
		picture = "\vcb_hats_A3\Data\UI\icon_h_helmetcrew_vcb_ca.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\helmet_crew_vcb_co.paa"};
	};
	
	class H_PilotHelmetFighter_VCB: H_PilotHelmetFighter_B
	{
		displayName = "VCB Fighter Pilot Helmet";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\pilot_helmet_vcb_co.paa"};
	};
	
	class H_CrewHelmetHeli_VCB: H_CrewHelmetHeli_B
	{
		displayName = "VCB Heli Crew Helmet";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\helmet_heli_vcb_co.paa"};
	};
	
	class H_PilotHelmetHeli_VCB: H_PilotHelmetHeli_B
	{
		displayName = "VCB Heli Pilot Helmet";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\helmet_heli_pilot_VCB_co.paa"};
	};
	
/*	
	class H_Bandanna_VCB: H_Bandanna_surfer
	{
		displayName = "VCB Bandanna";
		picture = "\vcb_hats_A3\Data\UI\icon_H_bandanna_vcb_ca.paa";
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\h_bandana_mcamoCap__VCB_co.paa"};
	};
	
	class H_Shemag_VCB: H_Shemag_olive
	{
		displayName = "VCB Shemag";
	};
	
	class H_ShemagOpen_VCB: H_ShemagOpen_khk
	{
		displayName = "VCB Shemag (Open)";
	};
*/
	
};

class CfgVehicles
{
	class Box_NATO_Support_F;
	class Box_VCB_Support_F : Box_NATO_Support_F
	{
		displayName = "Support Crate [VCB]";
		hiddenSelections[] = {"Camo_Signs","Camo"};
		hiddenSelectionsTextures[] = {"\vcb_hats_A3\Data\AmmoBox_signs_VCB_CA.paa","\vcb_hats_A3\Data\AmmoBox_VCB_CO.paa"};
		class TransportItems
		{
			class _xx_H_Booniehat_VCB
			{
				name = "H_Booniehat_VCB";
				count = 30;
			};
			class _xx_H_Cap_VCB
			{
				name = "H_Cap_VCB";
				count = 30;
			};
			class _xx_H_Cap_Black_VCB
			{
				name = "H_Cap_Black_VCB";
				count = 10;
			};
			class _xx_H_Cap_headphones_VCB
			{
				name = "H_Cap_headphones_VCB";
				count = 30;
			};
			class _xx_H_MilCap_VCB
			{
				name = "H_MilCap_VCB";
				count = 30;
			};
			class _xx_H_Beanie_VCB
			{
				name = "H_Beanie_VCB";
				count = 30;
			};
			class _xx_H_Beret_VCB
			{
				name = "H_Beret_VCB";
				count = 6;
			};
			class _xx_H_Helmet_VCB
			{
				name = "H_Helmet_VCB";
				count = 30;
			};
			class _xx_H_HelmetCrew_VCB
			{
				name = "H_HelmetCrew_VCB";
				count = 10;
			};
			class _xx_H_PilotHelmetFighter_VCB
			{
				name = "H_PilotHelmetFighter_VCB";
				count = 5;
			};
			class _xx_H_CrewHelmetHeli_VCB
			{
				name = "H_CrewHelmetHeli_VCB";
				count = 5;
			};
			class _xx_H_PilotHelmetHeli_VCB
			{
				name = "H_PilotHelmetHeli_VCB";
				count = 5;
			};
		};
	};
};
