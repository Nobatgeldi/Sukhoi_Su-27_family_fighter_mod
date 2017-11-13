#include "basicDefines_A3.hpp"
#include "BIS_AddonInfo.hpp"
#include "CfgMovesBasic.hpp"
#include "DefaultVehicleSystemsDisplayManagerLeft.hpp"
#include "DefaultVehicleSystemsDisplayManagerRight.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicleClasses.hpp"
class SensorTemplatePassiveRadar;	// External class reference
class SensorTemplateAntiRadiation;	// External class reference
class SensorTemplateActiveRadar;	// External class reference
class SensorTemplateIR;	// External class reference
class SensorTemplateVisual;	// External class reference
class SensorTemplateMan;	// External class reference
class SensorTemplateLaser;	// External class reference
class SensorTemplateNV;	// External class reference
#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgVehicles.hpp"

enum
{
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 4,
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXESXYZ = 4,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	DESTRUCTNO = 0,
	STABILIZEDINAXESNONE = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

class CfgPatches
{
	class Su33_Protatype_PT
	{
		units[] =
		{
			"Su33_Protatype_PT_2",
			"Sukhoi_Pilot",
			"Su33_Protatype_Dynamic"
		};
		weapons[] = {};
		requiredVersion = 1.3;
		requiredAddons[] = {};
	};
};
