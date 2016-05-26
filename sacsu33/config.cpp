class CfgPatches
{
	class SACSu33
	{
		units[]=
		{
			"SACSu33"
		};
		weapons[]={};
		requiredVersion=0.0.1;
		requiredAddons[]={};
	};
};
class CfgModels
{
	class Default
	{
	};
	class Name_Of_Your_Model : Default
	{

		class Animations
		{

			class nozzle1
			{
				type="translation";
				offset0=0.9;
				offset1=-0.9;
				axis="gear_l1_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle1";
			};
			class nozzle2
			{
				type="translation";
				offset0=0.9;
				offset1=-0.9;
				axis="nozzle2_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle2";
			};
			class nozzle3
			{
				type="translation";
				offset0=0.9;
				offset1=-0.9;
				axis="canopy_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle3";
			};
			class nozzle4
			{
				type="translation";
				offset0=0.9;
				offset1=-0.9;
				axis="nozzle4_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle4";
			};
			class nozzle5
			{
				type="translation";
				offset0=-0.9;
				offset1=0.9;
				axis="gear_l1_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle5";
			};
			class nozzle6
			{
				type="translation";
				offset0=-0.9;
				offset1=0.9;
				axis="nozzle2_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle6";
			};
			class nozzle7
			{
				type="translation";
				offset0=-0.9;
				offset1=0.9;
				axis="canopy_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle7";
			};
			class nozzle8
			{
				type="translation";
				offset0=-0.9;
				offset1=0.9;
				axis="nozzle4_axis";
				memory=1;
				minValue=0;
				maxValue=1;
				minPhase=0;
				maxPhase=1;
				source="rpm";
				sourceAddress=0;
				selection="nozzle8";
			};
		};
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
		faction = "turkmenAF";
		crew = "O_pilot_F";
		author="Nobatgeldi Geldimammedov";
		DriverAction="pilot";
		getInAction = GetInLow;
		displayName="Su-33 Flanker";
		model="\SACSu33\SACSu33B.p3d";
		animated=1;
		vehicleClass="Air";
		icon="\SACSu33\paa\icon.paa";
		picture="\SACSu33\paa\pic.paa";
		unitInfoType="UnitInfoAirplane";
		accuracy=0.2;
		simulation="airplane";
		_generalMacro="Plane";
		scope=2;
		nameSound="aircraft";
		fuelCapacity=2540;
		camouflage=10;
		Audible=6;
		mapSize=20;
		cost=100000000;
		type=2;
		threat[]={0.69999999,0.69999999,1};
		armor=60;
		damageResistance=0.00336;
		armorStructured=1;
		laserScanner=1;
		LockDetectionSystem="2 + 4 + 8";
		landingAoa="rad 10";
		landingSpeed=215;
		gearRetracting=1;
		maxSpeed=2100;
		supplyRadius=13;
		memoryPointGun="machinegun";
		memoryPointLRocket="L raketa";
		memoryPointRRocket="P raketa";
		weapons[]={};
		magazines[]={};
		aileronSensitivity=1.2;
		elevatorSensitivity=1;
		envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};
		class Reflectors
		{
			class Left
			{
				color[]={0.80000001,0.80000001,1,1};
				ambient[]={0.07,0.07,0.07,1};
				position="light_1_1_source";
				direction="light_1_1_target";
				hitpoint="L svetlo";
				selection="L svetlo";
				size=1;
				brightness=1;
			};
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[]=
				{
					"js_jc_su35\sounds\ext-jetair-engine-low1",
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
					"js_jc_su35\sounds\ext-jetair-engine-high3",
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
					"js_jc_su35\sounds\ext-jetair-forsage1",
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
					"js_jc_su35\sounds\int-av8b-engine-low",
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
					"js_jc_su35\sounds\int-av8b-engine",
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
					"js_jc_su35\sounds\int-av8b-forsage-1",
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
		hiddenselections[]=
		{
			"canopy",
			"canopyglass",
			"seat",
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
			class HOOKon
			{
				displayName="HOOK ON";
				position="pos player";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""hook"" == 0";
				statement="this animate [""hook"",1];";
			};
			class HOOKoff
			{
				displayName="HOOK OFF";
				position="pos player";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""hook"" == 1";
				statement="this animate [""hook"",0];";
			};
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
			//,_this execVM ""\sacsu33\sqsaircraftvapour.sqf""
			fired="[_this] exec ""\SACSu33\sqs\fireGsh.sqs"",_this call BIS_Effects_EH_Fired";
		};
		class Library
		{
			libTextDesc="The Sukhoi Su-33 (NATO reporting name Flanker-D)";
		};
	   };
 };