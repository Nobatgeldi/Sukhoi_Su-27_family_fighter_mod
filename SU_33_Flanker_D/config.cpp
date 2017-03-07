#include "basicDefines_A3.hpp"
#include "BIS_AddonInfo.hpp"
#include "CfgMovesBasic.hpp"
#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgVehicles.hpp"

class CfgPatches
{
	class Su33_Protatype_PT
	{
		units[] = {
			"Su33_Protatype_PT_2",
			"Sukhoi_Pilot"
		};
		weapons[] = {};
		requiredVersion = 1.3;
		requiredAddons[] = {"CBA_Extended_EventHandlers"};
	};
};

