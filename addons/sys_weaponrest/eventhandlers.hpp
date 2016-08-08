class Extended_PreInit_EventHandlers
{
	class ADDON
	{
		clientInit = "call ('\x\tup\addons\sys_weaponrest\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ADDON
	{
		clientInit = "call ('\x\tup\addons\sys_weaponrest\XEH_clientInit.sqf' call SLX_XEH_COMPILE)";
	};
};