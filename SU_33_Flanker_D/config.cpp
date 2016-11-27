#include "basicdefines_A3.hpp"
#include "CfgPatches.hpp"

class CfgVehicles
{
	class All
	{
	};
	class AllVehicles: All
	{
	};
	class Air: AllVehicles
	{
	};
	class Plane: Air
	{
		class HitPoints;
		class NewTurret;
		class ViewPilot;
		class Sounds;
		class AnimationSources;
	};
	class Su_33_Base_F: Plane
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
	};
	class Su_33_Plane_01_base_F: Su_33_Base_F
	{
		side = 0;
		faction = "OPF_F";
		crew = "O_pilot_F";
		author="Nobatgeldi Geldimammedov";
		DriverAction="pilot";
		getInAction = "";
		displayName="Su-33 Flanker-D";
		model="\SU_33_Flanker_D\Su33A.p3d";
		animated=1;
		vehicleClass="Air";
		icon="\SU_33_Flanker_D\paa\icon.paa";
		picture="\SU_33_Flanker_D\paa\pic.paa";
		unitInfoType="UnitInfoAirplane";
		accuracy=0.8;
		simulation="airplane";
		_generalMacro="Plane";
		scope=2;
		nameSound="aircraft";
		fuelCapacity=2550;
		camouflage=5;
		lightOnGear = true;
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
		irTarget=1;
		irScanRangeMin=100;
		irScanRangeMax=10500;
		irScanToEyeFactor=4;
		irScanGround=1;
		LockDetectionSystem="2 + 4 + 8";
		landingAoa="rad 10";
		landingSpeed=180;
		acceleration = 600;
		extCameraPosition[] = {0, 2, -30};
		gearRetracting=1;
		maxSpeed=2600;
		//commanderCanSee = 31+32;
		commanderUsesPilotView=true;
		flapsFrictionCoef=0.5;
		forceThrustMultiple = 1.7;
		flyInHeight=200;
		supplyRadius=13;
		airBrake = true;
	    //secondaryExplosion = true;
		turnCoef=3.0
		damping=92;
		damperSize = 0.12;
		wheelWeight = 175;
		memoryPointGun="machinegun";
		memoryPointLRocket="L raketa";
		memoryPointRRocket="P raketa";
		weapons[]=
		{
         "CMFlareLauncher"
		};
		magazines[]=
		{
         "300Rnd_CMFlare_Chaff_Magazine"
		};
		aileronSensitivity=1.2;
		elevatorSensitivity=1;
		/// forces keeping plane aligned with its speed direction - the bigger force the better it changes the direction of flight
				draconicForceXCoef = 4.5;
				draconicForceYCoef = 1.5;
				draconicForceZCoef = 1.5;
				draconicTorqueXCoef = 1.15;
				draconicTorqueYCoef = 4.0;

		envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};
		/*class Light
		{
			position="gear_n";
			ambient[] = {0.3,0.15,0.0,1.0};
			size = 5.3;
			brightness = 0.08;
			color[] = {1.0,0.5,0.0,1.0};

		};
		class MarkerLights
		{
			class Green_Still_L
			{
				name="num1";
				color[]={0.029999999,0.30000001,0.029999999,1};
				ambient[]={0.003,0.029999999,0.003,1};
				brightness=0.050000001;
				blinking=0;
			};
		};*/
		/*class Exhausts
		{
			class Exhaust_left
			{
				position="Exhausts_start_left";
				direction="Exhausts_end_left";
				effect="ExhaustsEffectPlane";
			};
			class Exhaust_right
			{
				position="Exhausts_start_right";
				direction="Exhausts_end_right";
				effect="ExhaustsEffectPlane";
			};
		};*/
		#include "sounds.hpp"
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
		insideSoundCoef = 0.05;
		hiddenselections[]=
		{
			"canopy",
			"canopyglass",
			"num1",
			"num2"
		};
		class MFD				/// class for helmet mounted displays, is going to be documented separately
		{
			class AirplaneHUD
			{
				#include "cfgHUD.hpp"
			};
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
		class Eventhandlers;
		class EventHandlers: Eventhandlers
		{
			init="_this execVM ""\sacsu33\sqs\init2.sqf"",[_this select 0]exec ""\SACSu33\sqs\init.sqs"",[_this select 0]exec ""\SACSu33\sqs\wing.sqs"",[_this select 0] execVM ""\SACSu33\sqs\AircraftEffects.sqf"",_this execVM ""\sacsu33\sqs\aircraftvapour.sqf""";
			fired="[_this] exec ""\SACSu33\sqs\fireGsh.sqs"",_this call BIS_Effects_EH_Fired";
		};
		class Library
		{
			libTextDesc="The Sukhoi Su-33 (NATO reporting name Flanker-D)";
		};
	};
 };
