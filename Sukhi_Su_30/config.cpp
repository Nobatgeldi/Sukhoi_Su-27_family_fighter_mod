
class CfgPatches {
	class Sukhoi_Su30 {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.0.1;
		requiredAddons[] = {};
	};
};

class CfgVehicles {

	class All{};
	class AllVehicles: All{};
	class Air: AllVehicles{};	// External class reference

	class Plane : Air {
		class NewTurret;	// External class reference
		class ViewPilot;	// External class reference
		class ViewGunner;	// External class reference
		class Eventhandlers;
		class AnimationSources;
		class Sounds;
	};
  class Sukhoi_Su30 : Plane
  {
		scope=2;
		side = 0;
		faction = "OPF_F";
		crew = "O_pilot_F";
		author="Nobatgeldi Geldimammedov";
		vehicleClass = "Air";
		displayName = "Sukhoi SU-30MK";
		model = "\Sukhi_Su_30\models\su30MK.p3d";
		icon = "\Sukhi_Su_30\tex\Icon_su30MK1_CA.paa";
    picture="\Sukhi_Su_30\tex\picture_mkk_ca.paa";
		//extCameraPosition[] = {0, 0, -30};
		animated=1;
    getInAction = "";
		driverAction="commander";
		driverIsCommander = true;
		driverrighthandanimname="stick_pilot";
		driverCanSee = 1+2+4+8+16+32;
		gunnerCanSee = 1+2+4+8+16+32;
		gunnerhasflares=1;
		gunnergetinaction="GetInLow";
		gunnergetoutaction="GetOutLow";
		hasGunner=1;
		unitInfoType="UnitInfoAirplane";
		simulation="airplane";
		_generalMacro="Plane";
		accuracy = 3.500000
		nameSound="aircraft";
		fuelCapacity=2500;
		camouflage=5;
		lightOnGear = true;
		Audible=9;
		mapSize=20;
		MapUseRealSize = true;
		cost=1000000;
		type=2;
		threat[]={0.99999999,0.99999999,1};
		armor=80;
		damageResistance=0.00336;
		armorStructured=1;
		incomingMissileDetectionSystem=16;
		radarType=4;

		// Vehicle/turret setting. Displays all targets known to vehicle sensors in via the ingame UI. Values can be combined.
		showAllTargets = 2; //LockYes, show targets from all sensors

		//Vehicle/turret setting. Displays gunner/commander turret aimpoints on the HUD.
		showCrewAim = 1+2+4; // values can be combined

		hasCommander = true;

		radarRange = 150000;
		laserScanner=1;
		irTarget=1;
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

		 /*"Su_R73Launcher",

		 "Su_R27Launcher",

		 "Su_R77Launcher",

		 "CMFlareLauncher"*/
		};
		magazines[]=
		{
		 "Su_300Rnd_30mm_GSh301",
		 /*"Su_300Rnd_30mm_GSh301",

		 "Su_6Rnd_R73M1_AA",

		 "Su_2Rnd_R27EA",

		 "Su_4Rnd_R77",

		 "300Rnd_CMFlare_Chaff_Magazine"*/
		};
		class LightSystems
		{
			class Light
			{
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
				frequency="1.0 min (rpm + 0.5)";
				volume="engineOn*camPos*(rpm factor[0.85, 0])";
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
				frequency="1";
				volume="engineOn*camPos*(rpm factor[0.55, 1.0])";
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
					"SU_33_Flanker_D\sounds\int-av8b-engine-low",
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
					"SU_33_Flanker_D\sounds\int-av8b-engine",
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
					"SU_33_Flanker_D\sounds\int-av8b-forsage-1",
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
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			0.1,
			1.5
		};
		soundGearUp[]=
		{
			"A3\Sounds_F_EPC\CAS_02\gear_up",
			0.79432797,
			1,
			150
		};
		soundGearDown[]=
		{
			"A3\Sounds_F_EPC\CAS_02\gear_down",
			0.79432797,
			1,
			150
		};
		soundFlapsUp[]=
		{
			"A3\Sounds_F_EPC\CAS_02\Flaps_Up",
			0.63095701,
			1,
			100
		};
		soundFlapsDown[]=
		{
			"A3\Sounds_F_EPC\CAS_02\Flaps_Down",
			0.63095701,
			1,
			100
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
		class Turrets
		{
			class MainTurret : NewTurret {
				body = "";
				gun = "";
				hasCrew = true;
				primaryGunner = true;
				commanding = -2;
				proxyIndex=2;
				startEngine = false;
				proxyType= CPGunner;
				gunnerCompartments = Compartment1;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
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

				 "Su_6Rnd_R73M1_AA",

				 "Su_2Rnd_R27EA",

				 "Su_4Rnd_R77",

				 "300Rnd_CMFlare_Chaff_Magazine"
				};
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerOpticsModel = "\Sukhi_Su_30\optika_SU30_gunner";
				gunnerForceOptics = 0;
				gunnerAction = "pilot";
				gunnerInAction = "pilot";

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
				statement="this animate [""ABcut"",0];";
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
				statement="this animate [""ABcut"",1];";
				showWindow=0;
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
