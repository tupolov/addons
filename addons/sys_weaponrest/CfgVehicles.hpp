class CfgVehicles {
	class Land_HelipadEmpty_F;
	class ALIVE_LogicDummy: Land_HelipadEmpty_F
	{
		scope = 1;
		slx_xeh_disabled = 1;
		class EventHandlers {
			init = "(_this select 0) enableSimulation false";
		};
	};
	class NATO_Box_Base;
	class Box_NATO_Support_F: NATO_Box_Base
	{
		class TransportItems
		{
			class _xx_muzzle_bipod_tup
			{
				name = "muzzle_bipod_tup";
				count = 20;
			};
			class _xx_muzzle_bipod_tup_m
			{
				name = "muzzle_bipod_tup";
				count = 10;
			};
		};

	};
};
