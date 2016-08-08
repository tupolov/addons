#include <script_component.hpp>
#include <CfgPatches.hpp>

class CfgMods
{
 class ADDON
 {
  dir = "@TUP";
  name = "Tupolov - Auto Cover";
  picture = "";
  hidePicture = "true";
  hideName = "true";
  actionName = "Website";
  action = "http://arma3live.com";
 };
};

#include <CfgVehicles.hpp>
#include <EventHandlers.hpp>

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
		class Showcase_Tup_AutoCover
		{
			briefingName = "Auto Cover";
			directory = "x\tup\addons\sys_autocover\showcases\Showcase_Autocover.Stratis";
		};
	};
};