class CfgVehicles {
		class Module_F;
		class TUP_NoMelee: Module_F
		{
			displayName = "Disable Melee";
			vehicleClass = "Modules";
			class Eventhandlers
			{
				init = "TUP_Melee = true; publicVariable 'TUP_Melee'";
			};
		};
};
