class CfgAmmo
{
	class MissileBase;
	class B_35mm_AA_Tracer_Yellow;
	class Bomb_04_F;
	class LaserBombCore;
	class BombCore;

	class Su_fak_ammo: MissileBase
	{
		model="\SU_33_Flanker_D\wep\fake_w.p3d";
		proxyShape="\SU_33_Flanker_D\wep\fake_w.p3d";
	};

	class Su_GSh301_35mm: B_35mm_AA_Tracer_Yellow
	{
   // bla blaa blaa
	};
	class Su_fab_250: Bomb_04_F
	{
		model="\SU_33_Flanker_D\wep\fab250.p3d";
		proxyShape="\SU_33_Flanker_D\wep\fab250.p3d";
	};
	/*class su_kab500: LaserBombCore
	{
		hit=6000;
		model="\SU_33_Flanker_D\wep\FAB500.p3d";
		proxyShape="\SU_33_Flanker_D\wep\FAB500.p3d";
		indirectHit=1800;
		indirectHitRange=12;
		irlock=0;
		laserLock=1;
		airlock=0;
		artilleryLock=1;
		nvLock=1;
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\expl_big_1",
			2.5118899,
			1,
			2400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\expl_big_2",
			2.5118899,
			1,
			2400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\expl_big_3",
			2.5118899,
			1,
			2400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\expl_shell_1",
			2.5118899,
			1,
			2400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\expl_shell_2",
			2.5118899,
			1,
			2400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.2,
			"soundHit5",
			0.2
		};
		explosionSoundEffect="DefaultExplosion";
		trackOversteer=1;
		trackLead=0.94999999;
		maneuvrability=20;
		CraterEffects="BombCrater";
		explosionEffects="BombExplosion";
		explosionTime=2;
		fuseDistance=35;
		whistleDist=24;
		weaponLockSystem="2 + 16 + 4";
		missileLockCone=120;
		maxControlRange=8000;
		manualControl=1;
	};*/
	class Su_kh_29: MissileBase
	{
		hit=1500;
		indirectHit=950;
		indirectHitRange=10.5;
		model="\SU_33_Flanker_D\wep\KH29\KH29T.p3d";
		proxyShape="\SU_33_Flanker_D\wep\KH29\KH29T.p3d";
		trackOversteer=1;
		whistleDist=8;
		maxControlRange=11000;
		maneuvrability=14;
		simulationStep=0.0020000001;
		airLock=0;
		irLock=1;
		laserLock=1;
		cmimmunity=0.80000001;
		manualControl=1;
		cost=1000;
		maxSpeed=400;
		timeToLive=45;
		airFriction=0.039999999;
		sideAirFriction=0.079999998;
		trackLead=1;
		initTime=0.15000001;
		thrustTime=2;
		thrust=366;
		fuseDistance=500;
		CraterEffects="ATMissileCrater";
		explosionEffects="ATMissileExplosion";
		muzzleEffect="BIS_fnc_effectFiredHeliRocket";
		soundHit[]=
		{
			"",
			1,
			1,
			1900
		};
		class Hiteffects
		{
			hitWater="ImpactEffectsSmall";
		};
		class CamShakeExplode
		{
			power="(110*0.2)";
			duration="((round (110^0.5))*0.2 max 0.2)";
			frequency=20;
			distance="((10 + 110^0.5)*8)";
		};
		class CamShakeHit
		{
			power=110;
			duration="((round (110^0.25))*0.2 max 0.2)";
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power="(80^0.25)";
			duration="((round (80^0.5))*0.2 max 0.2)";
			frequency=20;
			distance="((80^0.5)*8)";
		};
		class CamShakePlayerFire
		{
			power=4;
			duration=0.1;
			frequency=20;
			distance=1;
		};
		weaponLockSystem="2 + 16 + 4";
	};
	class Su_MissileBase_AGM : MissileBase {
		model = "";
		proxyShape = "";
		hit = 3000;
		indirectHit = 100;
		indirectHitRange = 200;
		cost = 10000;
		irLock = 1;
		laserLock = 0;
		maxControlRange = 27000;
		initTime = 0.15;
		trackOversteer = 1;
		trackLead = 1;
		timeToLive = 120;
		maneuvrability = 30;
		simulationStep = 0.01;
		sideAirFriction = 0.02;
		maxSpeed = 300;
		thrustTime = 2.0;
		thrust = 100;
		effectsMissile = "missile1";
		whistleDist = 4;
		weaponLockSystem=8 + 16;
		cmImmunity = 0.9;
	};
	class Su_KH31_AG : Su_MissileBase_AGM {
		model = "\SU_33_Flanker_D\wep\KH31\KH31.p3d";
		proxyShape = "\SU_33_Flanker_D\wep\KH31\KH31.p3d";
		hit = 5000;
		missileLockMaxDistance = 20000;
		indirectHit = 5000;
		offBoresightAngle = 80; // 160° laser sensor FoV
		indirectHitRange = 12;
		maxSpeed = 2520;
		explosive = 1;//Defines whether ammunition is explosive, and if so, by how much.
		maxControlRange = 150000;
		initTime = 2;
		thrustTime = 18;
		thrust = 150;
		maneuvrability = 45;
		effectsMissile = "missile1";
		soundHit[]=
		{
			"A3\Sounds_F\weapons\Rockets\explosion_missile_02",
			2.5118899,
			1,
			1800
		};
		laserLock = 1;
		nvLock = 1;
	};
	class Su_rocket_80mm_HE: MissileBase
	{
		model="\A3\Weapons_F\Ammo\Rocket_02_fly_F";
		proxyShape="\SU_33_Flanker_D\wep\s8_launcher_aircraft";
		hit=210;
		weaponType = "rocket";
		indirectHit=55;
		indirectHitRange=15;
		cost=500;
		maxSpeed=590;
		initTime=0.0020000001;
		thrustTime=0.69;
		thrust=1060;
		airFriction=0.090000004;
		sideAirFriction=0.0049999999;
		fuseDistance=50;
		whistleDist=30;
		timeToLive=60;
		effectsMissileInit="MissileDAR1";
		CraterEffects="HERocketCrater";
		explosionEffects="HERocketExplosion";
		muzzleEffect="BIS_fnc_effectFiredRocket";
		effectsMissile="missile1";
		soundHit[]=
		{
			"A3\Sounds_F\weapons\Rockets\explosion_missile_02",
			2.5118899,
			1,
			1800
		};
		explosionSoundEffect="DefaultExplosion";
		soundFly[]=
		{
			"A3\Sounds_F\weapons\Rockets\rocket_fly_2",
			2.2,
			1,
			400
		};
		soundEngine[]=
		{
			"A3\Sounds_F\weapons\Rockets\rocket_fly_2",
			2.2,
			1,
			20
		};
		supersonicCrackNear[]=
		{
			"",
			1,
			1,
			50
		};
		supersonicCrackFar[]=
		{
			"",
			1,
			1,
			150
		};
		airLock=0;
		irLock=0;
		laserLock=0;
	};
	// short range
	class Su_R73_AA: MissileBase
	{
		model="\SU_33_Flanker_D\wep\R73\R_73.p3d";
		proxyShape="\SU_33_Flanker_D\wep\R73\R_73.p3d";
		hit=200;
		weaponType = "missileAA"; //Overrides the engine determination of weapon type
															//based on ammo simulation, for vehicle weapon grouping.
		guidanceInitTime=1; //Defines how long a projectile waits before starting its engine.
		trackOversteer=2;   //Defines how a missile over steers.	1 - no oversteer
										    //Values higher than 1 result in more over steer.
		indirectHit=85;
		indirectHitRange=10;
		maneuvrability=27;
		cmImmunity=0.70;
		simulation="shotMissile";
		simulationStep=0.0020000001;

		lowerterrain=1; //If defined as 'true', the ammunition can change/ lower the terrain.
		offBoresightAngle = 80; //Defines the FOV angle of LOBL/ LOAL laser sensors.
		airLock=2;
		irLock=1;
		laserLock = true;
		laserScanRange = 50000;
		cost=1500;
		maxSpeed=828; //Meters per second  Defines the maximum speed of ammunition (missiles and rockets).
		timeToLive=40;
		airFriction=0.050000001;
		sideAirFriction=0.1;
		trackLead=1;
		initTime=0;
		thrustTime=5;
		thrust=240;
		fuseDistance=500; //Defines the distance traveled before ammunition is fused.
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		whistleDist=20;
		muzzleEffect="BIS_fnc_effectFiredHeliRocket";

		weaponLockSystem="2 + 8 + 4"; //	Defines the type of detection system
																	 // that can detect this munition when it is locked on to a target.
																	 // GUIDANCE_NONE 0 GUIDANCE_VISUAL 1
																	 // GUIDANCE_INFRARED 2 GUIDANCE_LASER 4
																	 // GUIDANCE_RADAR 8 DETECTION_MISSILE 16
		missileLockCone=120;
		maxControlRange=8000;
		class LaunchModes
		{
			class LOBL
			{
				launchAngle=20;
				targetingMode="LOBL";
				targetDistanceOverride=150;
			};
		};
	};
	class Su_R73M1_AA: Su_R73_AA
	{
		hit=350;
		indirectHit=100;
		indirectHitRange=20;
		maneuvrability=35;
	};
	// medium range missile up to 80 km
	class Su_R27R_AA: Su_R73_AA
	{
		model="\SU_33_Flanker_D\wep\R27\R_27.p3d";
		proxyShape="\SU_33_Flanker_D\wep\R27\R_27.p3d";
		hit=1200;
		indirectHit=600;
		indirectHitRange=30;
		airFriction=0.078000002;
		sideAirFriction=0.2;
		maneuvrability=90;
		simulationStep=0.0020000001;
		trackOversteer=5;
		trackLead=1;
		airLock=2;
		irLock=1;
		laserLock=0;
		cost=1000;
		timeToLive=20;
		maxSpeed=1200;
		initTime=0.25;
		thrustTime=30.5;
		thrust=385;
		fuseDistance=1000;
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		effectsMissileInit="RocketBackEffectsRPG";
		weaponLockSystem="2 + 8 + 8";
	};
	// long range missile up to 130 km
	class Su_R27EA_AA: Su_R27R_AA
	{
		hit=1400;
		indirectHit=800;
		indirectHitRange=40;
		airFriction=0.078000002;
		sideAirFriction=0.2;
		maneuvrability=100;
		simulationStep=0.0020000001;
		trackOversteer=10;
		trackLead=1;
		airLock=2;
		irLock=1;
		laserLock=0;
		cost=1000;
		timeToLive=20;
		maxSpeed=1500;
		initTime=0.25;
		thrustTime=30.5;
		thrust=385;
		fuseDistance=1500;
		weaponLockSystem="2 + 8 + 8";
	};
	// medium range
	class Su_R77_AA: Su_R73_AA
	{
		model="\SU_33_Flanker_D\wep\R77\R_77.p3d";
		proxyShape="\SU_33_Flanker_D\wep\R77\R_77_proxy.p3d";
		hit=1200;
		indirectHit=600;
		indirectHitRange=30;
		airFriction=0.078000002;
		sideAirFriction=0.2;
		maneuvrability=90;
		simulationStep=0.0020000001;
		trackOversteer=5;
		trackLead=1;
		airLock=2;
		irLock=1;
		laserLock=0;
		cost=1000;
		timeToLive=20;
		maxSpeed=1200;
		initTime=0.25;
		thrustTime=30.5;
		thrust=385;
		fuseDistance=1000;
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		effectsMissileInit="RocketBackEffectsRPG";
		weaponLockSystem="2 + 8 + 8";
	};
};
