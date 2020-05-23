// Always change this to be the path (without drive) to the directory you are working in.

class Su33_Protatype_PT_2: Su33_Base_F
{
  model="\SU_33_Flanker_D\model\Su33_protatype_3.p3d";

  hiddenSelections[] = {
    "selection_engine_cover",
    "selection_engine",
    "selection_hull",
    "selection_hull_mid",
    "selection_rudder",
    "selection_wing_l",
    "selection_wing_r"
  };
  hiddenSelectionsTextures[] = {
    "\SU_33_Flanker_D\texture\engine_cover.paa",
    "\SU_33_Flanker_D\texture\engine.paa",
    "\SU_33_Flanker_D\texture\hull.paa",
    "\SU_33_Flanker_D\texture\hull_mid.paa",
    "\SU_33_Flanker_D\texture\rudder.paa",
    "\SU_33_Flanker_D\texture\wing_l.paa",
    "\SU_33_Flanker_D\texture\wing_r.paa"
  };

  driverAction="su_33_pilot";
  getInAction = "";
  animated=1;
  icon="\SU_33_Flanker_D\texture\UI\icon.paa";
  picture="\SU_33_Flanker_D\texture\UI\pic.paa";
  editorpreview = "\SU_33_Flanker_D\texture\UI\pic.paa";
  scope=2;
  tailHook = 1;
  accuracy = 3.50;
  fuelCapacity=2500;
  camouflage=5;
  Audible=9;
  mapSize=20;
  MapUseRealSize = true;
  cost=1000000;
  type=2;
  //new
  cabinOpening = 1;
  threat[]={0.99999999,0.99999999,1};
  armor=80;
  damageResistance=0.00336;
  armorStructured=1;
  incomingMissileDetectionSystem=2 + 4 + 8 + 16;
  radarType=4;
  // Vehicle/turret setting. Displays all targets known to vehicle sensors in via the ingame UI. Values can be combined.
  showAllTargets = 2; //LockYes, show targets from all sensors
  //Vehicle/turret setting. Displays gunner/commander turret aimpoints on the HUD.
  showCrewAim = 1+2+4; // values can be combined
  radarRange = 150000;
  laserScanner=1;
  irTarget=1;
  irScanRangeMin=100;
  irScanRangeMax=100000;
  irScanToEyeFactor=2;
  irScanGround=1;
  visualTarget=1;
  visualTargetSize=1.2;
  nvTarget = 1;
  nvScanner = 1;
  maxDetectRange = 20;
  detectSkill = 20;
  LockDetectionSystem=1 + 2 + 4 + 8 + 16;
  crewCrashProtection = 2.0;
  landingAoa="rad 10";
  stallSpeed = 220;
  sweepDisengageRandomCourseCoef = 1;
  landingSpeed=180;
  enableGPS = 1;
  fuelLeakiness = 20;
  extCameraPosition[] = {0, 2, -30};
  gearRetracting=1;
  gearDownTime = 2;
  gearUpTime = 3.33;
  maxSpeed=2300;
  wheelSteeringSensitivity = 2.3;
  //timeToStop=0.2;
  commanderUsesPilotView=true;
  flapsFrictionCoef=0.2;
  forceThrustMultiple = 2.0;
  flyInHeight=150;
  supplyRadius=13;
  airBrake = true;
  maxRotationX=10.5;
    //secondaryExplosion = true;
  turnCoef=3.5;
  damping=40;
  damperSize = 0.12;
  wheelWeight = 175;

  getInRadius=8.5;

  #include "header/Components.hpp"

  weapons[]={
    "Su_fake_weapon",

    "Su_GSh301",

    "CMFlareLauncher"
  };

  magazines[]={
    "Su_300Rnd_30mm_GSh301",

    "300Rnd_CMFlare_Chaff_Magazine"
  };
  
  weaponsGroup1 = WEAPONGROUP_CANNONS + WEAPONGROUP_MGUNS;                                // Adds Cannons and Machine Guns to Weapons Group 1
  weaponsGroup2 = WEAPONGROUP_ROCKETS;                                                    // Adds Rockets to Weapons Group 2
  weaponsGroup3 = WEAPONGROUP_AAMISSILES + WEAPONGROUP_ATMISSILES + WEAPONGROUP_MISSILES; // Adds All Missile types to Weapons Group 3
  weaponsGroup4 = WEAPONGROUP_BOMBS + WEAPONGROUP_SPECIAL;                                // Adds Bombs and Laser Designators to Weapons Group 4

  class pilotCamera
  {
    class OpticsIn
    {
      class Wide
      {
        opticsDisplayName = WFOV;
        initAngleX = 0;
        minAngleX = 0;
        maxAngleX = 0;
        initAngleY = 0;
        minAngleY = 0;
        maxAngleY = 0;
        initFov = (30 / 120);
        minFov = (30 / 120);
        maxFov = (30 / 120);
        directionStabilized = 1;
        visionMode[] = {"Normal", "Ti"};
        thermalMode[] = {0, 1};
        //gunnerOpticsModel = "\SU_33_Flanker_D\wep\optika.p3d";
        gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
        opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
      };
      class Medium : Wide {
        opticsDisplayName = MFOV;
        initFov = (15 / 120);
        minFov = (15 / 120);
        maxFov = (15 / 120);
        gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
      };
      class Narrow : Wide {
        opticsDisplayName = NFOV;
        initFov = (3.75 / 120);
        minFov = (3.75 / 120);
        maxFov = (3.75 / 120);
        gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
      };
      showMiniMapInOptics = 1;
      showUAVViewInOptics = 0;
      showSlingLoadManagerInOptics = 0;
    };
    minTurn = -160;
    maxTurn = 160;
    initTurn = 0;
    minElev = -10;
    maxElev = 90;
    initElev = 0;
    maxXRotSpeed = 0.3;
    maxYRotSpeed = 0.3;
    pilotOpticsShowCursor = 1;
    controllable = 1;
  };
  memoryPointDriverOptics = "PilotCamera_pos";
  aileronSensitivity=1.6;
  elevatorSensitivity=3.0;
  radarTargetSize=1.0; /* Radar cross-section coefficient of the vehicle. Works as a coefficient of
                          RADAR Sensor's range within the given combat situation.
                          Early test values
                          0.1 - fully stealth (<0.0005m2 RCS) (not recommended)
                          0.7 - small aircrafts, semi-stealth (~1m2 RCS)
                          1.0 - mid sized aircraft, car (~5m2 RCS)
                          1.2 - tanks, trucks (~10m2 RCS)
                          2.0 - large bomber, small ship and bigger (>80m2 RCS)*/

  receiveRemoteTargets = true; //if the vehicle is able to receive targets
                               //and positions from friendly vehicles with reportRemoteTargets.

  reportRemoteTargets = true; /* Says if the vehicle is able to broadcast targets acquired by own sensors*/
  reportOwnPosition = true; 	/*Says if the vehicle is able to broadcast its own position*/

  envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};

  class MarkerLights
  {
    class Green_Still_Rear
    {
      name="Green_Still_Rear";
      color[]={0.0, 0.0, 1.0, 1.0};
      ambient[]={0.0, 0.0, 1.0, 1.0};
      brightness=0.05;
      blinking=1;
    };
    class red_Still_Flaps_L
    {
      name="red_Still_Flaps_L";
      color[]={1.0, 0.0, 0.0, 1.0};
      ambient[]={1, 0.0, 0.0, 1.0};
      brightness=0.05;
      blinking=1;
    };
    class red_Still_Flaps_R
    {
      name="red_Still_Flaps_R";
      color[]={1.0, 0.0, 0.0, 1.0};
      ambient[]={1.0, 0.0, 0.0, 1.0};
      brightness=0.05;
      blinking=1;
    };
  };

  class Reflectors
  {
    class Gear_Light_1
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
      intensity=25;
      useFlare=1;
      dayLight=0;
      FlareSize=4;
      class Attenuation
      {
        start = 1;
                  constant = 0;
                  linear = 0;
                  quadratic = 4;
                  hardLimitStart = 9;
                  hardLimitEnd = 10;
      };
    };
    class Gear_Light_2
    {
        color[]={7000,7500,10000,1};
        ambient[]={100,100,100,0};
        position="light_1_2_source";
        direction="light_1_2_target";
        hitpoint="L svetlo";
        selection="L svetlo";
        size=1;
        innerAngle=20;
        outerAngle=60;
        coneFadeCoef=10;
        intensity=25;
        useFlare=1;
        dayLight=0;
        FlareSize=4;
        class Attenuation
        {
            start = 1;
            constant = 0;
            linear = 0;
            quadratic = 4;
            hardLimitStart = 9;
            hardLimitEnd = 10;
        };
    };
    class Gear_Light_3
    {
        color[]={7000,7500,10000,1};
        ambient[]={100,100,100,0};
        position="light_1_3_source";
        direction="light_1_3_target";
        hitpoint="L svetlo";
        selection="L svetlo";
        size=1;
        innerAngle=10;
        outerAngle=30;
        coneFadeCoef=10;
        intensity=25;
        useFlare=1;
        dayLight=0;
        FlareSize=4;
        class Attenuation
        {
            start = 1;
            constant = 0;
            linear = 0;
            quadratic = 4;
            hardLimitStart = 9;
            hardLimitEnd = 10;
        };
    };
  };
  /*class RenderTargets
  {
      class mfdFlir
      {
          renderTarget = "rendertarget0";

          class CameraView1
          {
              pointPosition = "flir_pos";
              pointDirection = "flir_dir";
              renderQuality = 2;
              renderVisionMode = 2;
              fov = 0.3;
          };
      };
    };*/

  hiddenselections[]= {
    "canopy",
    "canopyglass",
    "seat",
    "num1",
    "num2"
  };
  class AnimationSources
  {
    class afterburner
    {
        source="user";
        animPeriod=1;
        initPhase=1;
    };
    class Wheel_1_source			{source = wheel; wheel = Wheel_1;};
    class Wheel_2_source			{source = wheel; wheel = Wheel_2;};
    class Wheel_3_source			{source = wheel; wheel = Wheel_3;};
    class Damper_1_source			{source = damper; wheel = Wheel_1;};
    class Damper_2_source			{source = damper; wheel = Wheel_2;};
    class Damper_3_source			{source = damper; wheel = Wheel_3;};

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
    class hook_up
    {
      displayName="Hook Down";
      position="pos player";
      radius=20;
      onlyforplayer=0;
      hideOnUse=1;
      condition="this animationPhase ""hook"" == 0";
      statement="this animate [""hook"",1];";
      showWindow=0;
    };
    class hook_down
    {
      displayName="Hook Up";
      position="pos player";
      radius=20;
      onlyforplayer=0;
      hideOnUse=1;
      condition="this animationPhase ""hook"" == 1";
      statement="this animate [""hook"",0];";
      showWindow=0;
    };
    /*class sun_rise_up
    {
      displayName="Sun Visor Up";
      position="pos player";
      radius=20;
      onlyforplayer=0;
      hideOnUse=1;
      condition="this animationPhase ""sun_rise"" == 0";
      statement="this animate [""sun_rise"",1];";
      showWindow=0;
    };
    class sun_rise_down
    {
      displayName="Sun Visor Down";
      position="pos player";
      radius=20;
      onlyforplayer=0;
      hideOnUse=1;
      condition="this animationPhase ""sun_rise"" == 1";
      statement="this animate [""sun_rise"",0];";
      showWindow=0;
    };
    class folding_wing
    {
      displayName="Fold Wing";
      position="pos player";
      //shortcut="SeagullFastForward";
      radius=20;
      condition="this animationphase ""wing"" == 0 and alive this and count (crew this) > 0 and speed this < 30";
      statement="this animate [""wing"",1];";
      onlyforplayer=0;
      hideOnUse=1;
      showWindow=0;
    };
    class open_wing
    {
      displayName="Unfold Wing";
      position="pos player";
      //shortcut="SeagullFastForward";
      radius=20;
      condition="this animationphase ""wing"" == 1 and alive this and count (crew this) > 0 and speed this < 30";
      statement="this animate [""wing"",0];";
      onlyforplayer=0;
      hideOnUse=1;
      showWindow=0;
    };*/
  };
  #include "header/physx.hpp" 						// PhysX suspension setup
  class Eventhandlers: Eventhandlers
  {
      init= "[_this select 0] execVM ""\SU_33_Flanker_D\sqf\init_m.sqf"",";
      fired="[_this] execVM ""\SU_33_Flanker_D\sqf\Gsh.sqf"",_this call BIS_Effects_EH_Fired";
  };
  class Library
  {
    libTextDesc = "The Sukhoi Su-33 (NATO reporting name Flanker-D) is a carrier-based multi-role fighter aircraft produced by Russian firm Sukhoi beginning in 1982. \nThe main differences from the Su-27 are that the Su-33 can operate from aircraft carriers and is capable of aerial refueling. \nThe wings were fitted with power-assisted folding, and the vertical tails were shortened to allow the fighter to fit in the typically crowded hangars of an aircraft carrier. The rear radome was shortened and reshaped to allow for the tail hook, as well as to save space inside the hangars.";
  };
  //unitInfoType = UnitInfoAirplane;

};
