
class CfgPatches {

	/*cfgPatches 'creates' the add-ons. Once you create an add-on (be it a weapon, vehicle etc.)
	  and you have CfgPatches in the code, and you create a mission with the add-on,
		cfgPatches gets written into the mission. This means that the mission you created requires that add-on.
		This avoids errors when you create missions with add-ons other people might not have.
    In cfgPatches you can also create a loading order, i.e. an order in which things should be loaded.
		This is done using the requiredAddons [] array*/

	class Sukhoi_Su30 {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.0.1;
		requiredAddons[] = {};
	};
};

class CfgVehicles {

	class All{}; // External class reference
	class AllVehicles: All{}; // External class reference
	class Air: AllVehicles{};	// External class reference

	class Plane : Air
	{
		class NewTurret;	// External class reference
		class ViewPilot;	// External class reference
		class ViewGunner;	// External class reference
		class Eventhandlers;// External class reference
		class AnimationSources;// External class reference
		class Sounds;// External class reference
	};
  class Sukhoi_Su30 : Plane //add new vehicle class
  {
		scope=2; 	S// public use only

		side = 0; 	//Sets the vehicle/ unit to a particular side.
									/*Mines are assigned a side of -1 (no side). "No side" differs from neutral
									in that the simulator engine spends no time looking for interaction with other objects.
									You can use a predefined string in place of the numerical values, for example:
									Predefined Strings: [defines.hpp and basic_defines.hpp]
									0 = SIDE_OPFOR, TEast
									1  SIDE_BLUFOR, SIDE_BLUEFOR, TWest
									2  SIDE_INDEPENDENT, TGuerrila
									3  SIDE_CIVILIAN, TCivilian
									4  TSideUnknown
									5  TEnemy
									6  TFriendly
									7  TLogic*/

		faction = "OPF_F";
		crew = "O_pilot_F"; 													//Defines the type of person that crews a vehicle, as placed in the Editor.
		author="Nobatgeldi Geldimammedov";						// mod developer
		vehicleClass = "Air"; 												//Vehicle group (Air, Armor...)
		displayName = "Sukhoi SU-30MK";								// displayed name on screen
		model = "\Sukhi_Su_30\models\su30MK.p3d";			// 3D model of vehicle
		icon = "\Sukhi_Su_30\tex\Icon_su30MK1_CA.paa";//icon on vehicle list
    picture="\Sukhi_Su_30\tex\picture_mkk_ca.paa";// piscture one edin editor
		//extCameraPosition[] = {0, 0, -30}; //Defines the position of the external camera in 3rd person view.
																				 //Coordinates are given relative to the center of the model in meters.
																				 //XYZ where Y is vertical and Z is fore and aft.

		animated=1;   							//Used by class models that inherit
		 														//from another animated 'vehicle' to
																// turn animations specific to the 'parent' vehicle off.

    getInAction = ""; 					//	Defines an animation for getting into a vehicle.

		driverAction="su_33_pilot"; //Defines the animation for the turned out driver position in a vehicle.

		driverIsCommander = true; //Defines the driver as the commander of a vehicle.
															//Usually set to 'true' when hasCommander = 'false'.

		driverCanSee = 1+2+4+8+16+32; //Defines which sensory inputs are available to the driver of a vehicle
																	/*CanSeeRadar = 1;
																		CanSeeEye = 2;
																		CanSeeOptics = 4;
																		CanSeeEar = 8;
																		CanSeeCompass = 16;
																		CanSeeRadarC = CanSeeRadar+CanSeeCompass;
																		CanSeeAll = 31;
																		CanSeePeripheral = 32;
																		You can also use the following predefined string in place of the numerical value:
																		driverCanSee = CanSeeEye + CanSeeEar + CanSeeCompass;*/

		gunnerCanSee = 1+2+4+8+16+32; // simlar to driverCanSee

		gunnerhasflares=1;						  // Defines whether the gunner has flares.

		gunnergetinaction="GetInLow";   //Defines an animation for getting into a vehicle.
																		/*	GetInLow, GetInMedium, GetInHigh*/

		gunnergetoutaction="GetOutLow"; // Defines an animation for getting out of a vehicle.
																		/*	GetOutLow, GetOutMedium, GetOutHigh*/

		unitInfoType="UnitInfoAirplane";/*Defines which HUD elements are displayed
																			at the top left of the screen. Includes items
																			such as armor health, weapons, altitude etc.*/

		simulation="airplane";					/*Tells the simulator engine what simulation type
																			the object/ p3d model belongs to, and therefore
																			determines the engine behavior for the object/ model.*/
		_generalMacro="Plane";

		accuracy = 0.500000 			//Defines how easy an object is to identify. Smaller values are easier to recognize.
				/*Typical values:
				accuracy = 0.2; // buildings
				accuracy = 0.5; //small vehicles
				accuracy = 0.9; // truck
				accuracy = 3.500000; //sniper
				accuracy = 1.500000; //lawsoldier
				accuracy = 1000; //soldier, identifies (most) soldiers as 'man'
				Note: A value of 1000 causes the underlying class to be identified instead, e.g. bushy trees, pink trees and yellow trees, can all be 'identified' as "trees". The description "bushy trees" is then used solely when Editing.
				Values should not be set higher than 1000. Anything over 4 should be equivalent, meaning that the unit type is never correctly recognized.
				When used for moving vehicles, only angular velocity of relative movement is used and accuracy is decreased by -50% per rad/sec, with a maximum of -95% for 2 rad/sec.*/

		nameSound="aircraft";   /*Defines where AI units should go to, i.e. what 'vehicle' to attack.
														Sounds used are defined in CfgVoices, class Words.*/

		fuelCapacity=2500;			//Defines fuel capacity.
														/*Note: Fuel units used has no direct correlation with real life units,
														though a very rough approximation would be 1 unit equals 0.1 liters.
														Note: Vehicles which take damage to their fuel tanks (HitFuel for cars,
														motorcycles and tanks, HitHull for helicopters) lose fuel rapidly.*/

		camouflage=5; 					/*Defines how difficult it is for an AI to see a unit.
														The higher the value, the easier it is for an AI to detect a unit.*/

		lightOnGear = true; 		//Defines whether there are lights on landing gear.

		Audible=10;							//Defines how loud a vehicle is. The higher the value, the louder the vehicle.
														/*audible = 10; // planes are very loud
															audible = 6; // water vehicles*/

		mapSize=20;							//Used for the map editor to set the size of the icon associated with the model class.
														/*mapSize = 0.5; // man
														mapSize = 0.7;  small object such as a barrel
														mapSize = 5;  car
														mapSize = 10;  AV-8B*/

		MapUseRealSize = true;	//Defines whether the icon in the Map Editor is sized depending on the size of the bounding box
														//for the object/ vehicle.

		cost=1000000;						//Defines how important a unit/vehicle is for an enemy AI to kill,
														//when all other considerations are equ

		type=2; //Defines the thread type of a 'vehicle'.
						/*Usually defined at the top of configuration files for clarity:
							#define VSoft 0
							#define VArmor 1
							#define VAir 2*/

		threat[]={0.99999999,0.99999999,1}; //Defines how dangerous an AI considers a person/ vehicle versus various enemy types
																				//(VSoft, VArmor, VAir) respectively.
																				/*Range of 0 to 1 with 1 representing the greatest threat.
																					Syntax:
																					threat[]={VSoft, VArmor, VAir}
																					There are various predefined strings instead of the float array:
																					People
																					THREAT_LOW // poorly equiped or trained unit (pilots, civilians, etc)
																					THREAT_MID // standard infantry/rifleman
																					THREAT_HIGH //high threat to infantry (snipers,etc)
																					THREAT_MG //equipped w/machine gun - soft units consider this unit more dangerous
																					THREAT_AA //equipped w/anti-air weapon - air units consider this unit more dangerous
																					THREAT_AT //equipped w/anti-tank weapon - armor units consider this unit more dangerous

																					Vehicles
																					THREAT_UNARMED // unarmed vehicle of any type
																					THREAT_MG // trucks, armored trucks, boats, static weapons, and anything else not included below, armed with MG <= 7.62mm
																					THREAT_HMG // armed with MG or autocannon > 7.62mm
																					THREAT_AT // armed with AT missiles
																					THREAT_AA // armed with AA missiles / guns
																					THREAT_AFV_HMG // armored fighting vehicles (tank, apc, ifv, etc) armed with MG
																					THREAT_AFV_AUTOC // armed with autocannon (20mm+)
																					THREAT_AFV_AA // armed with anti-air missiles or guns
																					THREAT_AFV_TANK // main battle tanks
																					THREAT_HELO_MG // helocopters armed with MGs
																					THREAT_HELO_RKT // armed with autocannons and/or rockets
																					THREAT_HELO_MIS // armed with missiles, in addition to mg/rocket/etc
																					THREAT_PLANE_A2A // fixed wing aircraft w/mostly anti-air weapon loadout
																					THREAT_PLANE_A2G // armed w/mostly anti-ground weapon loadout*/
		armor=80;													 //Defines armor strength

		damageResistance=0.00336; 				 //Defines when and when not to shoot.For AI only.

		armorStructured=1; 								 //Defines damage done to the global armor value.

		incomingMissileDetectionSystem=16; //Defines which munitions guided towards the vehicle the vehicle can detect.
																			 /*0  No missile-in-flight detection
																			   8  Active Radar Homing missile-in-flight detection
																			   16 Detects all missiles (Missile Approach Warning)*/

		radarType=4;						 					 //Defines the type of radar UI the vehicle will use.
																			 // 0; No radar (used for infantry)
																			 // 1; Tactical display (not used)
																			 // 2; Vehicle radar (used for AAA) - shows compass, turret directions and targets
																			 // 4; Air radar (used for jets and gunships)  - shows compass, turret directions and targets
																			 // 8; Compass + turret directions (used for majority of vehicles and their turret

		// Vehicle/turret setting. Displays all targets known to vehicle sensors in via the ingame UI. Values can be combined.
		showAllTargets = 2; //LockYes, show targets from all sensors

		//Vehicle/turret setting. Displays gunner/commander turret aimpoints on the HUD.
		showCrewAim = 1+2+4; // values can be combined

		hasCommander = true; //Defines whether the vehicle has a commander
												 //that is not the main gunner. Controls the 'get in' commands.

		radarRange = 150000; //Defines the radar range (in meters)

		laserScanner=1; //Defines if the vehicle has a Laser Spot Tracker and
										// is able to detect and lock laser targets (for example, CAS jets, gunships).

		irTarget=1;			//IRTarget is used if undefined for backwards compatibility.
		irScanRangeMin=100;
		irScanRangeMax=10000;
		irScanToEyeFactor=4;
		irScanGround=1;
		LockDetectionSystem="1 + 2 + 4 + 8";
		landingAoa="rad 10";
		sweepDisengageRandomCourseCoef = 1;
		landingSpeed=220;
		extCameraPosition[] = {0, 2, -30};
		gearRetracting=1;
		maxSpeed=2300;
		//timeToStop=0.2;
		commanderUsesPilotView=true;
		flapsFrictionCoef=0.2;
		forceThrustMultiple = 2.0;
		flyInHeight=200;
		supplyRadius=13;
		airBrake = true;
		maxRotationX=1.5;
			//secondaryExplosion = true;
		turnCoef=5.0
		damping=40;
		damperSize = 0.12;
		wheelWeight = 175;

		altNoForce = 10000; //	Specifies full engine thrust up to the defined altitude.
												//  Simulates the affect of thinning air on engine performance.

		advancedWeaponSelection = true;
		afMax = 115;
		//memoryPointMissile[] = {"aux_missile_muzzle", "aux_missile_muzzle"};
		weapons[]=
		{
		 "Su_GSh301",

		 "Su_R73Launcher",

		 "Su_R27Launcher",

		 "Su_R77Launcher",

		 "CMFlareLauncher"
		};
		magazines[]=
		{
		 "Su_300Rnd_30mm_GSh301",
		};
		class LightSystems
		{
			class Light
			{
					//actionKey = "";
					color[]={7000,7500,10000,1};
					ambient[]={255,0,0,0};
					position="podsvit pristroju";
					size=0.2;
					brightness=0.003;
			};
		};
		class Eventhandlers: Eventhandlers
		{
			init = "_this execVM ""\Sukhi_Su_30\scripts\init.sqf"",[_this select 0] execVM ""\Sukhi_Su_30\scripts\AircraftEffects.sqf""";
			fired="[_this] exec ""\Sukhi_Su_30\scripts\fireGsh.sqs"",_this call BIS_Effects_EH_Fired";
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[]=
				{
					"SU_33_Flanker_D\sounds\ext-jetair-engine-low1",
					2.5118899,
					1,
					1600
				};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"SU_33_Flanker_D\sounds\ext-jetair-engine-high3",
					2.5118899,
					1.3,
					1800
				};
				frequency = "1";
				volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};
			class ForsageOut
			{
				sound[]=
				{
					"SU_33_Flanker_D\sounds\ext-jetair-forsage1",
					2.5118899,
					1.1,
					2000
				};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[] = {3.14, 3.92, 2.0, 0.5};
			};
			class WindNoiseOut
			{
				sound[] = {"A3\Sounds_F_EPC\CAS_02\noise", 0.562341, 1.0, 150};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};
			class EngineLowIn
			{
				sound[]=
				{
					"SU_33_Flanker_D\sounds\int-av8b-engine-low",
					0.56234097,
					1
				};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
			};
			class EngineHighIn
			{
				sound[]=
				{
					"SU_33_Flanker_D\sounds\int-av8b-engine",
					1,
					1
				};
				frequency = "1";
				volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
			};
			class ForsageIn
			{
				sound[]=
				{
					"SU_33_Flanker_D\sounds\int-av8b-forsage-1",
					0.56234097,
					1.1
				};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\air\Plane_Fighter_03\noise",
					0.70794576,
					1
				};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
			class RainExt
			{
				sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1.77828, 1.0, 100};
				frequency = 1;
				volume = "camPos * rain * (speed factor[50, 0])";
			};

			class RainInt
			{
				sound[] = {"A3\Sounds_F\vehicles\noises\rain1_int", 1.0, 1.0, 100};
				frequency = 1;
				volume = "(1-camPos) * rain * (speed factor[50, 0])";
			};
		};
		attenuationEffectType = "PlaneAttenuation";
		soundGetIn[] = {"A3\Sounds_F_EPC\CAS_02\TO_getin", 1.0, 1};
		soundGetOut[] = {"A3\Sounds_F_EPC\CAS_02\getout", 1.0, 1, 40};
		soundDammage[] = {"", 0.562341, 1};
		soundEngineOnInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_int", 0.794328, 1.0};
		soundEngineOnExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_ext", 1.0, 1.0, 500};
		soundEngineOffInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_int", 0.794328, 1.0};
		soundEngineOffExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_ext", 1.0, 1.0, 500};
		soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1", 0.316228, 1};
		soundIncommingMissile[] = {"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4", 0.398107, 1.0};
		soundGearUp[] = {"A3\Sounds_F_EPC\CAS_02\gear_up", 0.794328, 1.0, 150};
		soundGearDown[] = {"A3\Sounds_F_EPC\CAS_02\gear_down", 0.794328, 1.0, 150};
		soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up", 0.630957, 1.0, 100};
		soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down", 0.630957, 1.0, 100};
		class scrubLandInt {
			sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt", 1.0, 1.0, 100};
			frequency = 1;
			volume = "(scrubLand factor[0.01, 0.20])";
		};
		enableGPS = 1;
		brakeDistance = 500
		insideSoundCoef = 0.1;
		aileronSensitivity=2.6;
		elevatorSensitivity=3.2;
		envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};
		memoryPointGun="machinegun";
		memoryPointLRocket="L raketa";
		memoryPointRRocket="P raketa";
		driverRightHandAnimName = "stick_pilot";
		driverLeftHandAnimName = "stick_pilot";
		class Exhausts
		{
			class Exhaust_left
			{
				position="exhaust_l";
				direction="Exhausts_end_left";
				effect="ExhaustsEffectPlane";
			};
			class Exhaust_right
			{
				position="exhaust_r";
				direction="Exhausts_end_right";
				effect="ExhaustsEffectPlane";
			};
		};
		class ViewPilot : ViewPilot
		{
			initFov = 0.8;
			minFov = 0.3;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -135;
			maxAngleY = 135;
		};
		memoryPointDriverOptics = "PilotCamera_pos";
		class pilotCamera {
			class OpticsIn {
				class Wide {
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
		class Turrets
		{
			class MainTurret : NewTurret {
				body = "";
				gun = "";
				hasCrew = true;
				hasGunner = 1;
				primaryGunner = true;
				proxyIndex=2;
				startEngine = true;
				IWVicon = "gunner";
				commanding = -2;
				proxyType= CPGunner;
				gunnerCompartments = Compartment1;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnerAction = "su_33_pilot";
				gunnerInAction = "su_33_pilot";
				gunnergetinaction="GetInLow";
				gunnergetoutaction="GetOutHigh";
				gunnerrighthandanimname="stick_pilot";
				caneject=1;
				weapons[]=
				{
				 "Su_R73Launcher",

				 "Su_R27Launcher",

				 "Su_R77Launcher",

				 "CMFlareLauncher"
				};
				magazines[]=
				{
				 "Su_6Rnd_R73",

				 "Su_R27R",
				 "Su_R27R",

				 "Su_4Rnd_R77",

				 "300Rnd_CMFlare_Chaff_Magazine"
				};
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerOpticsModel = "\Sukhi_Su_30\optika_SU30_gunner";
				gunnerForceOptics = 0;

				class Viewoptics
				{
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = 0.18;
					minFov = 0.18;
					maxFov = 0.4;
				};

				class ViewGunner : ViewGunner
				{
					initFov = 0.8;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -135;
					maxAngleY = 135;
				};
			};
		};

		class AnimationSources
		{
			class ABcut
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class AfterburnerLV2
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};

			class AfterburnerRV2
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
	   /*		class UserAB {
				source = "user";
				animPeriod = 1.0;
			};

			class UserDisplay {
				source = "user";
				animPeriod = 0.01;
			};

			class UserWeapon {
				source = "user";
				animPeriod = 0.01;
			};

			class UserWeapon1 {
				source = "user";
				animPeriod = 0.01;
			};

			class UserWeapon2 {
				source = "user";
				animPeriod = 0.01;
			};*/
		};

		class UserActions
		{
			class ABon
			{
				displayName="Afterburner ON";
				position="pos player";
				shortcut="SeagullFastForward";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""ABcut"" == 1 and player in this and isengineon this";
				statement="this animate [""ABcut"",0],this animate [""AfterburnerRV2"",1], this animate [""AfterburnerLV2"",1];";
				hideOnUse=1;
				showWindow=0;
			};
			class ABoff
			{
				displayName="Afterburner Off";
				position="pos player";
				shortcut="SeagullFastForward";
				radius=20;
				onlyforplayer=0;
				condition="this animationPhase ""ABcut"" == 0 and player in this and isengineon this";
				statement="this animate [""ABcut"",1],this animate [""AfterburnerRV2"",0], this animate [""AfterburnerLV2"",0];";
				showWindow=0;
				hideOnUse=1;
			};
			class Farsouge_on
			{
				displayName ="Farsouge On";
				position = "pos player";
				radius =20;
				showWindow = 0;
				condition = "this animationPhase ""AfterburnerLV2"" == 0 and player in this and isengineon this";
				statement = "this animate [""AfterburnerRV2"",1], this animate [""AfterburnerLV2"",1];";
				onlyforplayer = false;
				hideOnUse=1;
			};

			class Farsouge_off
			{
				displayName ="Farsouge OFF";
				position = "pos player";
				radius =20;
				showWindow = 0;
				condition = "this animationPhase ""AfterburnerLV2"" == 1 and player in this and isengineon this";
				statement = "this animate [""AfterburnerRV2"",0], this animate [""AfterburnerLV2"",0],;";
				onlyforplayer = false;
				hideOnUse=1;
			};
  	/*class ABurner_on {
				displayName = "Enable Burners";
				position = "pilotcontrol";
				onlyforplayer = 0;
				radius = 0.75;
				condition = "(this animationPhase ""ABSwitch"" < 0.1)";
				statement = "this animate [""ABSwitch"",1]";
			};

			class ABurner_off {
				displayName = "Burners Off";
				position = "pilotcontrol";
				onlyforplayer = 0;
				radius = 0.75;
				condition = "(this animationPhase ""ABSwitch"" > 0.9)";
				statement = "this animate [""ABSwitch"",0]";
			};

			class SwitchToDisplay2 {
				displayName = "Switch Display";
				position = "pilotcontrol";
				onlyforplayer = 1;
				radius = 1.5;
				condition = "(this animationPhase ""DisplayFirstLayer"" < 0.1)";
				statement = "this animate [""DisplayFirstLayer"",1];this animate [""DisplaySecondLayer"",1]";
			};

			class SwitchToDisplay1 {
				displayName = "Switch Display";
				position = "pilotcontrol";
				onlyforplayer = 1;
				radius = 1.5;
				condition = "(this animationPhase ""DisplayFirstLayer"" > 0.9)";
				statement = "this animate [""DisplayFirstLayer"",0];this animate [""DisplaySecondLayer"",0]";
			};*/
		};

		class MFD
		{
			borderLeft = 0.09;
			borderRight = 0.02;
			borderTop = 0.02;
			borderBottom = 0.1;

			class AirplaneHUD {
				topLeft = "HUD LH";
				topRight = "HUD PH";
				bottomLeft = "HUD LD";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0, 1, 0, 0.0};

				class Pos10Vector {
					type = "vector";
					pos0[] = {0.5, 0.725};
					pos10[] = {0.5+0.9, 0.725+0.7};
				};

				class Bones {
					class AGLMove1 {
						type = "fixed";
						source = "altitudeAGL";
						Pos[] = {0.78, 0.175};
					};

					class AGLMove2 {
						type = "fixed";
						pos[] = {0.05, 0.8};
					};

					class ASLMove1 {
						type = "linear";
						source = "altitudeASL";
						min = 0;
						max = 500;
						minPos[] = {0.1, 0.1};
						maxPos[] = {0.1, 0.8};
					};

					class ASLMove2 {
						type = "fixed";
						pos[] = {0.1, 0.8};
					};

					class VertSpeed {
						type = "linear";
						source = "vSpeed";
						min = -25;
						max = 25;
						minPos[] = {0, -0.4};
						maxPos[] = {0, 0.4};
					};

					class SpdMove2 {
						source = "speed";
						type = "fixed";
						Pos[] = {0.3, 0.175};
					};

					class ILS {
						type = "ils";
						pos0[] = {0.5, 0.4};
						pos3[] = {0.7, 0.6};
					};

					class WeaponAim : Pos10Vector {
						source = "weapon";
						pos0[] = {0.5, -0.2};
					};

					class Target : Pos10Vector {
						source = "target";
					};

					class TargetDistanceMissile {
						type = "rotational";
						source = "targetDist";
						center[] = {0, 0};
						min = 100;
						max = 3000;
						minAngle = -120;
						maxAngle = 120;
					};

					class TargetDistanceMGun {
						type = "rotational";
						source = "targetDist";
						center[] = {0, 0};
						min = 100;
						max = 1000;
						minAngle = -180;
						maxAngle = 90;
					};

					class Level0 : Pos10Vector {
						type = "horizon";
						angle = 0;
					};

					class LevelP5 : Level0 {
						angle = 5;
					};

					class LevelM5 : Level0 {
						angle = -5;
					};

					class LevelP10 : Level0 {
						angle = 10;
					};

					class LevelM10 : Level0 {
						angle = -10;
					};

					class LevelP15 : Level0 {
						angle = 15;
					};

					class LevelM15 : Level0 {
						angle = -15;
					};

					class Velocity : Pos10Vector {
						type = "vector";
						source = "velocity";
						pos0[] = {0.505, 0.52};
					};

					class PlaneW {
						type = "fixed";
						pos[] = {0.5, 0.725};
					};
				};

				class Draw {
					alpha = 0.6;
					color[] = {0, 0.3, 0};
					clipTL[] = {0.0, 0.05};
					clipBR[] = {1.0, 0.9};
					condition = "on";

					class Altitude {
						type = "text";
						align = "right";
						scale = 1;
						source = "altitudeAGL";
						sourceScale = 1;
						pos[] = {"AGLMove1", {-0.05, -0.03}, 1};
						right[] = {"AGLMove1", {0.01, -0.03}, 1};
						down[] = {"AGLMove1", {-0.05, 0.03}, 1};
					};

					class DimmedBase {
						alpha = 0.3;

						class AltitudeBase {
							type = "line";
							points[] = {{"AGLMove2", 1}, {"ASLMove2", 1}};
						};
					};

					class Speed {};

					class SpeedNumber {
						type = "text";
						align = "left";
						scale = 1;
						source = "speed";
						sourceScale = 3.6;
						pos[] = {"SpdMove2", {-0.05, -0.03}, 1};
						right[] = {"SpdMove2", {0.01, -0.03}, 1};
						down[] = {"SpdMove2", {-0.05, 0.03}, 1};
					};

					class PlaneW {
						clipTL[] = {0.0, 0.1};
						clipBR[] = {1.0, 0.9};

						class LineHL {};

						class Velocity {
							type = "line";
							points[] = {{"Velocity", {0, -0.02}, 1}, {"Velocity", {0.02, 0}, 1}, {"Velocity", {0, 0.02}, 1}, {"Velocity", {-0.02, 0}, 1}, {"Velocity", {0, -0.02}, 1}};
						};
					};

					class MGun {
						condition = "mgun";

						class Circle {
							type = "line";
							points[] = {{"WeaponAim", {0, -0.07}, 1}, {"WeaponAim", {+0.7*0.07, -0.7*0.07}, 1}, {"WeaponAim", {0.07, 0}, 1}, {"WeaponAim", {+0.7*0.07, +0.7*0.07}, 1}, {"WeaponAim", {0, 0.07}, 1}, {"WeaponAim", {-0.7*0.07, +0.7*0.07}, 1}, {"WeaponAim", {-0.07, 0}, 1}, {"WeaponAim", {-0.7*0.07, -0.7*0.07}, 1}, {"WeaponAim", {0, -0.07}, 1}, {}, {"WeaponAim", {0, -0.01}, 1}, {"WeaponAim", {+0.7*0.01, -0.7*0.01}, 1}, {"WeaponAim", {0.01, 0}, 1}, {"WeaponAim", {+0.7*0.01, +0.7*0.01}, 1}, {"WeaponAim", {0, 0.01}, 1}, {"WeaponAim", {-0.7*0.01, +0.7*0.01}, 1}, {"WeaponAim", {-0.01, 0}, 1}, {"WeaponAim", {-0.7*0.01, -0.7*0.01}, 1}, {"WeaponAim", {0, -0.01}, 1}, {}, {"WeaponAim", {0.03*sin(-180), -0.03*cos(-180)}, 1}, {"WeaponAim", {0.07*sin(-180), -0.07*cos(-180)}, 1}, {}, {"WeaponAim", {0.03*sin(+90), -0.03*cos(+90)}, 1}, {"WeaponAim", {0.07*sin(+90), -0.07*cos(+90)}, 1}, {}, {"WeaponAim", 1, "TargetDistanceMGun", {0, 0.04}, 1}, {"WeaponAim", 1, "TargetDistanceMGun", {0, 0.07}, 1}};
						};
					};

					class Missile {
						condition = "missile";

						class Circle {
							type = "line";
							points[] = {{"WeaponAim", {0, -0.1}, 1}, {"WeaponAim", {+0.7*0.1, -0.7*0.1}, 1}, {"WeaponAim", {0.1, 0}, 1}, {"WeaponAim", {+0.7*0.1, +0.7*0.1}, 1}, {"WeaponAim", {0, 0.1}, 1}, {"WeaponAim", {-0.7*0.1, +0.7*0.1}, 1}, {"WeaponAim", {-0.1, 0}, 1}, {"WeaponAim", {-0.7*0.1, -0.7*0.1}, 1}, {"WeaponAim", {0, -0.1}, 1}, {}, {"WeaponAim", {0.1*0.8*sin(-120), -0.1*0.8*cos(-120)}, 1}, {"WeaponAim", {0.1*1.2*sin(-120), -0.1*1.2*cos(-120)}, 1}, {}, {"WeaponAim", {0.1*0.8*sin(+120), -0.1*0.8*cos(+120)}, 1}, {"WeaponAim", {0.1*1.2*sin(+120), -0.1*1.2*cos(+120)}, 1}, {}, {"WeaponAim", 1, "TargetDistanceMissile", {0, 0.1*0.8}, 1}, {"WeaponAim", 1, "TargetDistanceMissile", {0, 0.1*1.2}, 1}};
						};

						class Target {
							type = "line";
							points[] = {{"Target", {-0.05, -0.05}, 1}, {"Target", {0.05, -0.05}, 1}, {"Target", {0.05, 0.05}, 1}, {"Target", {-0.05, 0.05}, 1}, {"Target", {-0.05, -0.05}, 1}};
						};
					};

					class Horizont {};

					class ILS {
						condition = "ils";

						class Glideslope {
							clipTL[] = {0.29, 0.29};
							clipBR[] = {0.71, 0.71};

							class ILS {
								type = "line";
								points[] = {{ILS, {-10, 0}, 1}, {ILS, {10, 0}, 1}, {}, {ILS, {0, -10}, 1}, {ILS, {0, 10}, 1}};
							};
						};

						class AOABracket {
							type = "line";
							points[] = {{{0.42, 0.78}, 1}, {{0.4, 0.78}, 1}, {{0.4, 0.88}, 1}, {{0.42, 0.88}, 1}};
						};
					};
				};
			};
		};
	};
};
