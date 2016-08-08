class Extended_PreInit_EventHandlers
{
	class ADDON
	{
		Init = "call ('\x\tup\addons\sys_melee\XEH_preInit.sqf' call SLX_XEH_COMPILE)";	
		clientInit = "call ('\x\tup\addons\sys_melee\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
