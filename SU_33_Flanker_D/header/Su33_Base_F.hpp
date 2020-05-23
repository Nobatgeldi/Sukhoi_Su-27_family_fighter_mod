class Su33_Base_F : Su_Base_F
{
  side = 0;
  faction = "OPF_F";
  crew = "Sukhoi_Pilot";
  author="Nobatgeldi Geldimammedov";
  displayName="Sukhoi Su-33 Flanker-D ";
  driverCanSee = 31;
  vehicleClass="air";
  unitInfoType="RscOptics_CAS_Pilot";
  driverWeaponsInfoType = "RscOptics_CAS_01_TGP";
  simulation="airplaneX";
  _generalMacro="Su33_Protatype_PT_2";
  nameSound="aircraft";
  lightOnGear = 1;
  class AnimationSources;	// External class reference

  class Components;	// External class reference

  memoryPointMissile[] ={
		"l strela",
		"p strela"
	};
  
  // camera shake caused by the G force
  class camShakeGForce	
  {
      power 		= 2;	/// power of the shake
      frequency 	= 20;
      distance 	= 0;	/// how far from the vehicle does the shake appear
      minSpeed 	= 150;	/// minimum speed of the vehicle to start the shake
      duration	= 2;	/// duration of the shake, does cross-fade if higher than 1
  };
  minGForce 				= 5;	/// minimum G-force required for the shake
  maxGForce				= 10;	/// strength interpolates between min and max
  gForceShakeAttenuation 	= 0.5;	/// multiplies strength of the shake

  memoryPointGun="machinegun";
  memoryPointLRocket="L raketa";
  memoryPointRRocket="P raketa";
  driverRightHandAnimName = "ControlStick";
  driverLeftHandAnimName = "control_throttle";
  driverLeftLegAnimName = "pilot_pedal_L";
  driverRightLegAnimName = "pilot_pedal_R";
  
  /*memoryPointLDust = "pos_dust_left";
  memoryPointRDust = "pos_dust_right";
  memoryPointGun = "pos_nosegun";
  memoryPointLMissile = "l strela";
  memoryPointRMissile = "p strela";*/

  memoryPointCM[] = {"flare_L","flare_R"};
  memoryPointCMDir[] = {"flare_L_dir","flare_R_dir"};
  memoryPointsGetInCargo = "get_in";
  memoryPointsGetInCoDriver = "get_in";
  memoryPointsGetInCommander = "get_in";
  memoryPointsGetInDriver = "get_in";
  memoryPointsGetInGunner = "get_in";
  //driveOnComponent[] = {"wheel_f","wheel_r","wheel_l"};	// Caesar BTT
  class Exhausts
  {
    class Exhaust_left
    {
        //intensity
      position="exhaust_L";
      direction="exhaust_L_dir";
      effect="ExhaustsEffectPlane";
      engineIndex = 0;
    };
    class Exhaust_right
    {
        //intensity
      position="exhaust_R";
      direction="exhaust_R_dir";
      effect="ExhaustsEffectPlane";
      engineIndex = 1;
    };
  };
  #include "header/Sound.hpp"

  class WingVortices
  {
      class WingTipLeft {
          effectName = "WingVortices";
          position = "red_Still_Flaps_L";
      };

      class WingTipRight {
          effectName = "WingVortices";
          position = "red_Still_Flaps_R";
      };

      class BodyLeft {
          effectName = "SU_33_BodyVortices";
          position = "body_vapour_L_S";
      };

      class BodyRight {
          effectName = "SU_33_BodyVortices";
          position = "body_vapour_R_S";
      };
  };
  //HUD configuration
  #include "header/MFD.hpp"
  class HitPoints: HitPoints
  {
    class HitHull: HitHull				{armor = 4;		explosionShielding = 3;		name = "HitHull";			passThrough = 1;	visual = "Hit_Hull";		radius = 0.3;	minimalHit = 0.05;	depends = "0";	material = -1;};
    class HitEngineR: HitHull			{armor = 4;		explosionShielding = 3.5;	name = "HitEngineR";			passThrough = 1;	visual = "Hit_Engine_R";		radius = 0.3;	minimalHit = 0.05;	depends = "0";};
    class HitEngineL: HitHull			{armor = 4;		explosionShielding = 3.5;	name = "HitEngineL";			passThrough = 1;	visual = "Hit_Engine_L";		radius = 0.3;	minimalHit = 0.05;	depends = "0";};

    // Wingtips fuel tanks
    class HitFuel_Lead_Left: HitHull	{armor = 1.8;	explosionShielding = 3;		name = "HitFuel1_Leads";	passThrough = 0;	visual = "wing_l";	radius = 0.13;	minimalHit = 0.1;	};
    class HitFuel_Lead_Right: HitHull	{armor = 1.8;	explosionShielding = 3;		name = "HitFuel2_leads";	passThrough = 0;	visual = "wing_r";	radius = 0.13;	minimalHit = 0.1;	};

    // Cockpit glass
    class HitGlass1: HitHull			{armor = 1.2;	explosionShielding = 3;		name = "HitGlass1";			passThrough = 0;	visual = "canopy_glass"; 			radius = 0.2;	minimalHit = 0.1;	depends = "0";};
  };
};
