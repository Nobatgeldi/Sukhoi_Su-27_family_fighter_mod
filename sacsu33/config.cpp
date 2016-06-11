#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgSkeletons.hpp"
#include "basicDefines_A3.hpp"

class CfgPatches
{
	class SACSu33
	{
		units[]=
		{
			"SACSu33",
			"SACSu33B"
		};
		weapons[]={};
		requiredVersion=0.0.1;
		requiredAddons[]={};
	};
};

class CfgVehicles
{
	class All;
	class Air;
	class Plane;
	class SACSu33: Plane
	{
		side = 0;
		faction = "OPF_F";
		crew = "O_pilot_F";
		author="Nobatgeldi Geldimammedov";
		DriverAction="pilot";
		getInAction = "";
		displayName="Su-33 Flanker-D";
		model="\SACSu33\SACSu33.p3d";
		animated=1;
		vehicleClass="Air";
		icon="\SACSu33\paa\icon.paa";
		picture="\SACSu33\paa\pic.paa";
		unitInfoType="UnitInfoAirplane";
		accuracy=0.4;
		simulation="airplane";
		_generalMacro="Plane";
		scope=2;
		nameSound="aircraft";
		fuelCapacity=2550;
		camouflage=5;
		Audible=9;
		mapSize=20;
		cost=100000000;
		type=2;
		threat[]={0.99999999,0.99999999,1};
		armor=120;
		damageResistance=0.00336;
		armorStructured=1;
		incomingMissileDetectionSystem=16;
		radarType=4;
		laserScanner=1;
		irTarget = true;
		irScanRangeMin=100;
		irScanRangeMax=10500;
		irScanToEyeFactor=4;
		irScanGround=1;
		irScanToEyeFactor = 2;
		LockDetectionSystem="2 + 4 + 8";
		landingAoa="rad 10";
		landingSpeed=180;
		extCameraPosition[] = {0, 2, -30};
		gearRetracting=1;
		maxSpeed=2100;
		commanderCanSee = 31+32;
		commanderUsesPilotView=rue;
		flapsFrictionCoef=0.5;
		forceThrustMultiple = 1.7;
		supplyRadius=13;
	    //secondaryExplosion = true;
		turnCoef=6.0
		memoryPointGun="machinegun";
		memoryPointLRocket="L raketa";
		memoryPointRRocket="P raketa";
		weapons[]=
		{
		 "SACGSh301",
		 "SACR73Launcher",
		 "GBU12BombLauncher",
		 "SACR27Launcher",
         "CMFlareLauncher"		 
		};
		magazines[]=
		{
		 "SAC_150Rnd_30mm_GSh301",
         "SAC_6Rnd_R73",
		 "2Rnd_GBU12_LGB_MI10",
		 "SAC_4Rnd_R27RE",	
         "300Rnd_CMFlare_Chaff_Magazine"		 
		};
		aileronSensitivity=1.2;
		elevatorSensitivity=1;
		envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};
		class Reflectors
		{
			class Left
			{
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				position="light_1_1_source";
				direction="light_1_1_target";
				hitpoint="L svetlo";
				selection="L svetlo";
				size=1;
				innerAngle=20;
				outerAngle=60;
				coneFadeCoef=10;
				intensity=50;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
				};
			};
			class Right
			{
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				position="light_1_2_source";
				direction="light_1_2_target";
				hitpoint="P svetlo";
				selection="P svetlo";
				size=1;
				innerAngle=20;
				outerAngle=60;
				coneFadeCoef=10;
				intensity=50;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
				};
			};
		};
		class Sounds
		{
			/*class someVehicleClass
			{
			...
			//declared sounds for hitSounds
			hitSound1[] = {"\VBS2\people\data\sound\hit_man\hit1", 0.177828, 1};
			hitSound2[] = {"\VBS2\people\data\sound\hit_man\hit2", 0.177828, 1};
			...
			hitSound30[] = {"\VBS2\people\data\sound\hit_man\hit30", 0.177828, 1};
			 
			//this parameter applies the sounds
			hitSounds[] = {"hitSound1", 0.033333, "hitSound2", 0.033333, ..., "hitSound30", 0.033333};
			...
			};*/
			class EngineLowOut
			{
				sound[]=
				{
					"sacsu33\sounds\ext-jetair-engine-low1",
					2.5118899,
					1,
					1600
				};
				frequency="1.0 min (rpm + 0.5)";
				volume="engineOn*camPos*(rpm factor[0.85, 0])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"sacsu33\sounds\ext-jetair-engine-high3",
					2.5118899,
					1.3,
					1800
				};
				frequency="1";
				volume="engineOn*camPos*(rpm factor[0.55, 1.0])";
			};
			class ForsageOut
			{
				sound[]=
				{
					"sacsu33\sounds\ext-jetair-forsage1",
					2.5118899,
					1.1,
					2000
				};
				frequency="1";
				volume="engineOn*camPos*(thrust factor[0.5, 1.0])";
				cone[]={3.1400001,3.9200001,2,0.40000001};
			};
			class WindNoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\air\Plane_Fighter_03\noise",
					1,
					1,
					150
				};
				frequency="(0.1+(1.2*(speed factor[1, 150])))";
				volume="camPos*(speed factor[1, 150])";
			};
			class EngineLowIn
			{
				sound[]=
				{
					"sacsu33\sounds\int-av8b-engine-low",
					0.56234097,
					1
				};
				frequency="1.0 min (rpm + 0.5)";
				volume="(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
			};
			class EngineHighIn
			{
				sound[]=
				{
					"sacsu33\sounds\int-av8b-engine",
					1,
					1
				};
				frequency="1";
				volume="(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
			};
			class ForsageIn
			{
				sound[]=
				{
					"sacsu33\sounds\int-av8b-forsage-1",
					0.56234097,
					1.1
				};
				frequency="1";
				volume="(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\air\Plane_Fighter_03\noise",
					0.70794576,
					1
				};
				frequency="(0.1+(1.2*(speed factor[1, 150])))";
				volume="(1-camPos)*(speed factor[1, 150])";
			};
		};
		insideSoundCoef = 0.05;
		hiddenselections[]=
		{
			"canopy",
			"canopyglass",
			"num1",
			"num2"
		};
		class AnimationSources
		{
			class wing
			{
				source="user";
				animPeriod=5;
				initPhase=0;
			};
			class wing_r: wing
			{
			};
			class wing_l: wing
			{
			};
			class elevator_r1
			{
				source="user";
				animPeriod=5;
				initPhase=0;
			};
			class elevator_l1: elevator_r1
			{
			};
			class piston
			{
				source="user";
				animPeriod=3;
			};
			class hook
			{
				source="user";
				animPeriod=3;
				initPhase=0;
			};
			class ABcut
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
		};
		class UserActions
		{
			class ABon
			{
				displayName="Afterburner ON";
				position="pos player";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""ABcut"" == 1 and player in this and isengineon this";
				statement="this animate [""ABcut"",0];";
			};
			class ABoff
			{
				displayName="Afterburner Off";
				position="pos player";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""ABcut"" == 0 and player in this and isengineon this";
				statement="this animate [""ABcut"",1];";
			};
			class Hookon
			{
				displayName="HOOK ON";
				position="pos player";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""hook"" == 0";
				statement="this animate [""hook"",1];";
			};
			class Hookoff
			{
				displayName="HOOK OFF";
				position="pos player";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""hook"" == 1";
				statement="this animate [""hook"",0];";
			};
			class folding_wing
			{
				displayName="Fold Wing";
				position="pos player";
				radius=20;
				condition="this animationphase ""wing"" == 0 and alive this and count (crew this) > 0 and speed this < 30";
				statement="this animate [""wing"",1];";
				onlyforplayer=0;
			};
			class open_wing
			{
				displayName="Unfold Wing";
				position="pos player";
				radius=20;
				condition="this animationphase ""wing"" == 1 and alive this and count (crew this) > 0 and speed this < 30";
				statement="this animate [""wing"",0];";
				onlyforplayer=0;
			};
		};
		class EventHandlers
		{
			init="_this execVM ""\sacsu33\sqs\init2.sqf"",[_this select 0]exec ""\SACSu33\sqs\init.sqs"",[_this select 0]exec ""\SACSu33\sqs\wing.sqs"",[_this select 0] execVM ""\SACSu33\sqs\AircraftEffects.sqf"",_this execVM ""\sacsu33\sqs\aircraftvapour.sqf""";
			fired="[_this] exec ""\SACSu33\sqs\fireGsh.sqs"",_this call BIS_Effects_EH_Fired";
		};
		class Library
		{
			libTextDesc="The Sukhoi Su-33 (NATO reporting name Flanker-D)";
		};
	   };
	class SACSu33B: SACSu33
	{
		displayName="Su-33B Flanker-D";
		model="\SACSu33\SACSu33B.p3d";
		weapons[]=
		{
			"SACGSh301",
			"SACR73Launcher",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"SAC_150Rnd_30mm_GSh301",
			"SAC_4Rnd_R73",
			"300Rnd_CMFlare_Chaff_Magazine"
		};
		threat[]={1,1,0.85000002};
	};
 };