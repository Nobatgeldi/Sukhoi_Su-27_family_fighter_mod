class CfgAmmo
{
	class MissileBase;
	class B_35mm_AA_Tracer_Yellow;

	class Su_fake_ammo: MissileBase
	{
		model="\SU_33_Flanker_D\wep\fake_w.p3d";
		proxyShape="\SU_33_Flanker_D\wep\fake_w.p3d";
	};

	class Su_GSh301_35mm: B_35mm_AA_Tracer_Yellow
	{
        // bla blaa blaa
	};

	/*class Su_KH_31: MissileBase
	{
		hit=15000;
		indirectHit=5000;
		indirectHitRange=10.5;
		model="\SU_33_Flanker_D\wep\KH31\KH31_fly";
		proxyShape="\SU_33_Flanker_D\wep\KH31\KH31";
		trackOversteer=1;
		whistleDist=8;
		maxControlRange=11000;
		maneuvrability=20;
		deflecting = 5;
		simulationStep=0.0020000001;
		simulation="shotMissile";
		audibleFire = 5.0;
		airLock=0;
		irLock=1;
		laserLock=1;
		cmimmunity=0.8;
		manualControl=1;
		cost=1000;
		maxSpeed=400;
		timeToLive=45;
		airFriction=0.039999999;
		sideAirFriction=0.7;
		trackLead=1;
		initTime=1.0;
		thrustTime=2;
		thrust=366;
		fuseDistance=500;
		CraterEffects="ATMissileCrater";
		explosionEffects="ATMissileExplosion";
		soundHit[] = { "A3\Sounds_F\weapons\Rockets\explosion_missile_01", 3.1622777, 1, 1800 };
		missileLockCone = 180;
        missileKeepLockedCone = 180;
        missileLockMaxDistance = 6000;
        missileLockMinDistance = 50;
        missileLockMaxSpeed = 550;
		class Components
        {
            class SensorsManagerComponent
            {
                class Components
                {
                    class SomeRadarSensorComponent
                    {
                        componentType = "IRSensorComponent";
                        class AirTarget      // ranges for targets with sky background
                        {
                            minRange = 0;         //minimum possible range in meters
                            maxRange = 0;       //maximum possible range in meters
                            objectDistanceLimitCoef = -1;    //range not limited by obj. view distance
                            viewDistanceLimitCoef = -1;      //range not limited by view distance
                        };
                        class GroundTarget      // ranges for targets with ground background
                        {
                            minRange = 50;
                            maxRange = 6000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        typeRecognitionDistance = 6000; // distance how far the target type gets recognized
                        angleRangeHorizontal = 180;     // sensor azimuth coverage in degrees
                        angleRangeVertical = 240;       // sensor elevation coverage in degrees
                        groundNoiseDistanceCoef = -1;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
                        maxGroundNoiseDistance = -1;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
                        minSpeedThreshold = -1;        // target speed in km/h above which the target will start to become visible
                        maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold
                    };
                    class LaserSensorComponent : SensorTemplateLaser
                    {
                        class AirTarget {
                            minRange = 20000;
                            maxRange = 20000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };

                        class GroundTarget {
                            minRange = 20000;
                            maxRange = 20000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        maxTrackableSpeed = 55;
                        angleRangeHorizontal = 180;
                        angleRangeVertical = 240;
                    };
                };
            };
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
	};*/
};
