class CfgAmmo
{
	class MissileBase;
	class Missile_AA_03_F;
	class Su_rocket_80mm_HE: MissileBase
	{
		model="\A3\Weapons_F\Ammo\Rocket_02_fly_F";
		proxyShape="\Sukhoi_Su33\m_empty";
		hit=210;
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
	class Su_M_R73_AA: MissileBase
	{
		model="\Sukhoi_Su33\R27RE.p3d";
		proxyShape="\Sukhoi_Su33\R27RE_proxy.p3d";
		hit=200;
		indirectHit=85;
		indirectHitRange=10;
		maneuvrability=27;
		cmImmunity=0.70;
		simulation="shotMissile";
		simulationStep=0.0020000001;
		airLock=2;
		irLock=1;
		laserLock = true;
		laserScanRange = 10000;
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
	class Su_M_R73M1_AA: Su_M_R73_AA
	{
		hit=350;
		indirectHit=100;
		indirectHitRange=20;
		maneuvrability=35;
	};
	// long range missile up to 80 km
	class Su_M_R27R: Su_M_R73_AA
	{
		model="\Sukhoi_Su33\R27RE.p3d";
		proxyShape="\Sukhoi_Su33\R27RE_proxy.p3d";
		hit=1200;
		indirectHit=600;
		indirectHitRange=30;
		airFriction=0.078000002;
		sideAirFriction=0.2;
		maneuvrability=90;
		simulationStep=0.0020000001;
		trackOversteer=1;
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
		fuseDistance=50;
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		effectsMissileInit="RocketBackEffectsRPG";
		//effectsMissile="FX_SU35_Missile_AA";
		weaponLockSystem="2 + 16 + 4";
	};
	// long range missile up to 130 km
	class Su_M_R27EA: Su_M_R27R
	{
		hit=1200;
		indirectHit=600;
		indirectHitRange=30;
		airFriction=0.078000002;
		sideAirFriction=0.2;
		maneuvrability=90;
		simulationStep=0.0020000001;
		trackOversteer=1;
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
		fuseDistance=50;
		weaponLockSystem="2 + 16 + 4";
	};
	// medium range
	class Su_M_R77: Su_M_R73_AA
	{
		model="\Sukhoi_Su33\R77.p3d";
		proxyShape="\Sukhoi_Su33\R77_proxy.p3d";
		hit=600;
		indirectHit=300;
		indirectHitRange=25;
		airFriction=0.078000002;
		sideAirFriction=0.2;
		maneuvrability=60;
		simulationStep=0.0020000001;
		trackOversteer=1;
		trackLead=1;
		airLock=2;
		irLock=1;
		laserLock=0;
		cost=1000;
		timeToLive=20;
		maxSpeed=950;
		initTime=0.25;
		thrustTime=30.5;
		thrust=385;
		fuseDistance=50;
		CraterEffects="AAMissileCrater";
		explosionEffects="AAMissileExplosion";
		effectsMissileInit="RocketBackEffectsRPG";
		//effectsMissile="FX_SU35_Missile_AA";
		weaponLockSystem="2 + 16 + 4";
	};
};
