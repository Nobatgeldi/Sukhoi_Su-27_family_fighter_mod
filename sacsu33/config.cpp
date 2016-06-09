class CfgPatches
{
	class SACSu33
	{
		units[]=
		{
			"SACSu33",
			"SACSu33A"
		};
		weapons[]={};
		requiredVersion=0.0.1;
		requiredAddons[]={};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class SAC_150Rnd_30mm_GSh301: VehicleMagazine
	{
		scope=2;
		count=500;
		ammo="B_35mm_AA";
		initSpeed=1036;
		tracersEvery=2;
		nameSound="cannon";
	};
	class SAC_6Rnd_R73: VehicleMagazine
	{
		scope=2;
		displayName="R-73";
		displayNameShort="R-73";
		ammo="SAC_M_R73_AA";
		count=6;
		initSpeed=0;
		maxLeadSpeed=450;
		sound[]=
		{
			"A3\sounds_f\dummysound",
			1,
			1,
			1300
		};
		reloadSound[]=
		{
			"A3\sounds_f\dummysound",
			0.00031622799,
			1,
			20
		};
		nameSound="missiles";
	};
	class SAC_4Rnd_R73: SAC_6Rnd_R73
	{
		count=4;
	};
	class SAC_6Rnd_R27RE: SAC_6Rnd_R73
	{
		scope=2;
		displayName="R-27RE";
		count=6;
		ammo="SAC_M_R27RE";
		initSpeed=0;
	};
	class SAC_4Rnd_R27RE: SAC_6Rnd_R27RE
	{
		count=4;
	};
	class SAC_6Rnd_R77: VehicleMagazine
	{
		scope=2;
		displayName="R-77";
		count=6;
		ammo="SAC_M_R77";
		initSpeed=0;
	};
	class SAC_4Rnd_R77: SAC_6Rnd_R77
	{
		count=4;
	};
};
class CfgAmmo
{
	class MissileBase;
	class SAC_M_R73_AA: MissileBase
	{
		model="\SACSu33\SACR27RE.p3d";
		proxyShape="\SACSu33\SACR27RE_proxy.p3d";
		hit=200;
		indirectHit=85;
		indirectHitRange=10;
		maneuvrability=27;
		simulationStep=0.0020000001;
		airLock=2;
		irLock=1;
		cost=1500;
		maxSpeed=828;
		timeToLive=40;
		airFriction=0.050000001;
		sideAirFriction=0.1;
		trackOversteer=1;
		trackLead=1;
		initTime=0;
		thrustTime=5;
		thrust=240;
		fuseDistance=500;
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		//effectsMissile="FX_SU35_Missile_AA";
		whistleDist=20;
		muzzleEffect="BIS_fnc_effectFiredHeliRocket";
		weaponLockSystem="2 + 16 + 4";
		missileLockCone=120;
		maxControlRange=8000;
	};
		class SAC_M_R27RE: SAC_M_R73_AA
	{
		model="\SACSu33\SACR27RE.p3d";
		proxyShape="\SACSu33\SACR27RE_proxy.p3d";
		hit=100;
		indirectHit=50;
		indirectHitRange=9;
		maneuvrability=20;
		simulationStep=0.0020000001;
		trackOversteer=5;
		trackLead=0.94999999;
		airLock=1;
		irLock=1;
		initTime=0.30000001;
		thrustTime=15;
		thrust=400;
		cost=10000;
		maxSpeed=2300;
		minRange=300;
		minRangeProbab=0.1;
		midRange=2000;
		midRangeProbab=0.89999998;
		maxRange=5000;
		maxRangeProbab=0.69999999;
		effectsMissile="SACmissile1";
	};
	class SAC_M_R77: SAC_M_R73_AA
	{
		model="\SACSu33\SACR77.p3d";
		proxyShape="\SACSu33\SACR77_proxy.p3d";
		hit=80;
		indirectHit=40;
		indirectHitRange=9;
		maneuvrability=30;
		simulationStep=0.0020000001;
		trackOversteer=5;
		trackLead=0.69999999;
		airLock=1;
		irLock=1;
		thrustTime=12;
		thrust=380;
		cost=10000;
		initTime=0.15000001;
		maxSpeed=2100;
		minRange=100;
		minRangeProbab=0.1;
		midRange=1800;
		midRangeProbab=0.89999998;
		maxRange=6000;
		maxRangeProbab=0.69999999;
		effectsMissile="SACmissile1";
	};
};

class CfgWeapons
{
	class CannonCore;
	class SACGSh301: CannonCore
	{
        scope=2;
		displayName="Gsh-301 30mm";
		displayNameMagazine="Gsh-301 30mm";
		shortNameMagazine="Gsh-301 30mm";
		nameSound="cannon";
		cursor="EmptyCursor";
		cursorAim="mg";
		magazines[]=
		{
			"SAC_150Rnd_30mm_GSh301"
		};
		canLock=2;
		ballisticsComputer=2;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		class GunParticles
		{
			class Effect
			{
				effectName="MachineGun1";
				positionName="nosegun";
				directionName="nosegun_dir";
			};
		};
		class manual: CannonCore
		{
			displayName="Gsh-301 30mm";
			autoFire=1;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F\weapons\30mm\30mm_st_02",
					1.99526,
					1,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				weaponSoundEffect="DefaultRifle";
			};
			reloadTime=0.1;
			dispersion=0.0024999999;
			soundContinuous=0;
			showToPlayer=1;
			burst=1;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=1;
			minRangeProbab=0.0099999998;
			midRange=2;
			midRangeProbab=0.0099999998;
			maxRange=3;
			maxRangeProbab=0.0099999998;
			textureType="fullAuto";
		};
		class close: manual
		{
			showToPlayer=0;
			burst=15;
			aiRateOfFire=0.25;
			aiRateOfFireDistance=400;
			minRange=0;
			minRangeProbab=0.050000001;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			burst=10;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=500;
			minRange=300;
			minRangeProbab=0.2;
			midRange=400;
			midRangeProbab=0.69999999;
			maxRange=500;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			burst=7;
			aiRateOfFire=1;
			aiRateOfFireDistance=900;
			minRange=400;
			minRangeProbab=0.2;
			midRange=700;
			midRangeProbab=0.69999999;
			maxRange=900;
			maxRangeProbab=0.2;
		};
		class far: close
		{
			burst=4;
			aiRateOfFire=1.5;
			aiRateOfFireDistance=1500;
			minRange=800;
			minRangeProbab=0.2;
			midRange=1000;
			midRangeProbab=0.40000001;
			maxRange=1500;
			maxRangeProbab=0.0099999998;
		};
	};
	class MissileBase;
	class MissileLauncher;
	class SACR73Launcher: MissileLauncher
	{
		canLock=2;
		autoFire=0;
		displayName="R-73 Archer";
		displayNameMagazine="R-73 Archer";
		shortNameMagazine="R-73";
		cursorAim="EmptyCursor";
		cursor="EmptyCursor";
		minRange=300;
		minRangeProbab=0.025;
		midRange=2500;
		midRangeProbab=0.090000004;
		maxRange=9000;
		maxRangeProbab=0.0099999998;
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\weapons\Rockets\missile_2",
				1.12202,
				1.3,
				1000
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			weaponSoundEffect="DefaultRifle";
		};
		soundFly[]=
		{
			"A3\Sounds_F\weapons\Rockets\rocket_fly_2",
			1,
			1.5,
			700
		};
		lockingTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			0.316228,
			1
		};
		lockedTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			0.316228,
			2.5
		};
		reloadTime=0.1;
		magazineReloadTime=0.1;
		magazines[]=
		{
			"SAC_6Rnd_R73"
		};
		holdsterAnimValue=3;
		weaponLockDelay=3;
		textureType="semi";
	};
	class SACR27Launcher: SACR73Launcher
	{
		displayName="R-27RE";
		magazines[]=
		{
			"SAC_6Rnd_R27RE",
			"SAC_4Rnd_R27RE"
		};
		reloadTime=0.30000001;
	};
	class SACR77Launcher: SACR73Launcher
	{
		displayName="R-77";
		magazines[]=
		{
			"SAC_6Rnd_R77",
			"SAC_4Rnd_R77"
		};
		reloadTime=0.30000001;
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
		model="\SACSu33\SACSu33.p3d";
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
		weapons[]=
		{
		 "SACGSh301",
		 "SACR73Launcher",
		 "SACR77Launcher",
		 "SACR27Launcher"		 
		};
		magazines[]=
		{
		 "SAC_150Rnd_30mm_GSh301",
         "SAC_4Rnd_R73",
		 "SAC_4Rnd_R77",
		 "SAC_4Rnd_R27RE"		 
		};
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
	class SACSu33B: SACSu33
	{
		displayName="Su-33 Flanker(FAB250,R-73,S-8T)";
		model="\SACSu33\SACSu33B.p3d";
		weapons[]=
		{
			"SACGSh301",
			"SACR73Launcher",
		};
		magazines[]=
		{
			"SAC_150Rnd_30mm_GSh301",
			"SAC_4Rnd_R73"
		};
		threat[]={1,1,0.85000002};
	};
 };