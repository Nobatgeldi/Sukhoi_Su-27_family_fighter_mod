#include "basicDefines_A3.hpp"
#include "BIS_AddonInfo.hpp"
#include "CfgMovesBasic.hpp"
#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"

class CfgPatches
{
	class Su33_Protatype_PT
	{
		units[] = {
			"Su33_Protatype_PT",
			"Su33_Protatype_PT_2"
		};
		weapons[] = {};
		requiredVersion = 0.0.1;
		requiredAddons[] = {};
	};
};

class CfgVehicles
{
	  class All{};
		class O_Pilot_F;
		class Sukhoi_Pilot: O_Pilot_F
		{
			class SpeechVariants
			{
				class Default
				{
					speechSingular[]=
					{
						"veh_infantry_pilot_s"
					};
					speechPlural[]=
					{
						"veh_infantry_pilot_p"
					};
				};
			};
			//textSingular="$STR_A3_nameSound_veh_infantry_pilot_s";
			//textPlural="$STR_A3_nameSound_veh_infantry_pilot_p";
			nameSound="veh_infantry_pilot_s";
			//author="$STR_A3_Bohemia_Interactive";
			_generalMacro="O_Pilot_F";
			displayName="Fighter Pilot";
			model="\A3\characters_F\Common\pilot_f.p3d";
			modelSides[]={3,1};
			//uniformClass="JS_JC_SU35_PilotCoveralls";
			weapons[]=
			{
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"Throw",
				"Put"
			};
			magazines[]={};
			respawnMagazines[]={};
			backpack="";
			linkedItems[]=
			{
				"H_PilotHelmetFighter_O",
				"ItemMap",
				"ItemCompass",
				"ItemWatch",
				"ItemRadio",
				"ItemGPS"
			};
			respawnLinkedItems[]=
			{
				"PilotHelmet",
				"ItemMap",
				"ItemCompass",
				"ItemWatch",
				"ItemRadio",
				"ItemGPS"
			};
			hiddenSelections[]=
			{
				"Camo"
			};
			hiddenSelectionsTextures[]=
			{
				"\A3\Characters_F\Common\Data\pilot_suit_iran_co.paa"
			};
			cost=165000;
		};
		class AllVehicles: All{};
		class Air: AllVehicles{};
		class Plane: Air
		{
			class NewTurret;
			class ViewPilot;
			class Sounds;
			class AnimationSources;
			class Eventhandlers;
		};
	class Su33_Protatype_PT: Plane
	{
		side = 0;
		faction = "OPF_F";
		crew = "Sukhoi_Pilot";
		author="Nobatgeldi Geldimammedov";
		driverAction="commander";
		driverCanSee = 1+2+4+8+16;
		getInAction = "";
		displayName="Sukhoi Su-33 Flanker-D";
		model="\SU_33_Flanker_D\Su33_protatype.p3d";
		animated=1;
		vehicleClass="Air";
		icon="\SU_33_Flanker_D\paa\icon.paa";
		picture="\SU_33_Flanker_D\paa\pic.paa";
		unitInfoType="UnitInfoAirplane";
		simulation="airplane";
		_generalMacro="Plane";
		scope=2;
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
		landingSpeed=180;
		extCameraPosition[] = {0, 2, -30};
		gearRetracting=1;
		maxSpeed=2100;
		//timeToStop=0.2;
		commanderUsesPilotView=true;
		flapsFrictionCoef=0.2;
		forceThrustMultiple = 2.0;
		flyInHeight=200;
		supplyRadius=13;
		airBrake = true;
		maxRotationX=10.5;
	    //secondaryExplosion = true;
		turnCoef=5.0
		damping=40;
		damperSize = 0.12;
		wheelWeight = 175;
		memoryPointGun="machinegun";
		memoryPointLRocket="L raketa";
		memoryPointRRocket="P raketa";
		driverRightHandAnimName = "sticker";
		driverLeftHandAnimName = "sticker";
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
		 //"Su_300Rnd_30mm_GSh301",
		 "Su_300Rnd_30mm_GSh301",

		 "Su_6Rnd_R73M1_AA",

		 "Su_2Rnd_R27EA",

		 "Su_4Rnd_R77",

     "300Rnd_CMFlare_Chaff_Magazine"
		};
		aileronSensitivity=2.5;
		elevatorSensitivity=2.9;
		envelope[]={0,0.40000001,1.9,4,6.8000002,8.3000002,8.5,7.8000002,6.1999998,4.5999999,3.7,2.8,2.3,2,1.8,1.5,1.2,0.80000001,0.5,0.30000001,0.2,0};

		class MarkerLights
		{
			/*class Cockpit_light_1
			{
				name="pos player";
				ambient[]={1.0, 0.8, 0.2, 1.0};
				color[]={1.0, 0.8, 0.2, 1.0};
				brightness=0.10;
				blinking=0;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
				};
			};*/
			class Cockpit_light
			{
				name="pos player";
				ambient[]={0.0099999998,0.0099999998,0.0099999998,1};
				color[]={0.029999999,1,0.11,1};
				brightness=0.035;
				blinking=0;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
				};
			};
			class Green_Still_Rear
			{
				name="bily pozicni";
				color[]={0.0, 0.0, 1.0, 1.0};
				ambient[]={0.0, 0.0, 1.0, 1.0};
				brightness=0.1;
				blinking=true;
			};
			class red_Still_Flaps_L
			{
				name="cerveny pozicni";
				color[]={1000,0,0,1};
				ambient[]={1,0,0,1};
				brightness=0.029999999;
				blinking=1;
			};
			class red_Still_Flaps_R
			{
				name="zeleny pozicni";
				color[]={1000,0,0,1};
				ambient[]={1,0,0,1};
				brightness=0.029999999;
				blinking=1;
			};
		};
		class Exhausts
		{
			class Exhaust_left
			{
				position="levy prach";
				direction="Exhausts_end_left";
				effect="ExhaustsEffectPlane";
			};
			class Exhaust_right
			{
				position="pravy prach";
				direction="Exhausts_end_right";
				effect="ExhaustsEffectPlane";
			};
		};
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
				intensity=25;
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
				intensity=25;
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
		insideSoundCoef = 0.1;
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
			class sun_rise
			{
				source="user";
				animPeriod=2;
				initPhase=0;
			};
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
			class AfterburnerL2
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class AfterburnerR2
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
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
				statement="this animate [""ABcut"",0] and this animate [""AfterburnerLV2"",1] and this animate [""AfterburnerRV2"",1] and this animate [""AfterburnerL2"",1] and this animate [""AfterburnerR2"",1]";
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
				statement="this animate [""ABcut"",1] and this animate [""AfterburnerLV2"",0] and this animate [""AfterburnerRV2"",0] and this animate [""AfterburnerL2"",0] and this animate [""AfterburnerR2"",0]";
				showWindow=0;
				hideOnUse=1;
			};
			class sun_rise_up
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
			};
			/*class Hookon
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
			};*/
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
			};
		};
		/*class EventHandlers {
			init = "_this execVM ""\Sukhoi_Su33\sqs\init2.sqf"",[_this select 0]exec ""\Sukhoi_Su33\sqs\init.sqs"",[_this select 0]exec ""\Sukhoi_Su33\sqs\wing.sqs"",[_this select 0] execVM ""\Sukhoi_Su33\sqs\AircraftEffects.sqf"",_this exec ""\Sukhoi_Su33\sqs\ejectstart.sqs"",_this execVM ""a3\data_f\ParticleEffects\SCRIPTS\misc\aircraftvapour.sqf""";
			fired = "[_this] exec ""\Sukhoi_Su33\sqs\fireGsh.sqs"",_this call BIS_Effects_EH_Fired";
		};*/
		class pilotCamera
		{

		    class OpticsIn
		    {
		        //different optics mode, same as in turrets
		    }

		    minTurn = - 90; //yaw limits
		    maxTurn=   90;  //yaw limits
		    initTurn= 0;  //initial yaw angle
		    minElev = - 90; //pitch limits
		    maxElev =   90; //pitch limits
		    initElev =  0; //initial pitch angle
		    maxXRotSpeed = 0.5; // yawing speed
		    maxYRotSpeed = 0.5; // pitching speed
		    pilotOpticsShowCursor = 1; //to show aimCursor (is useful to see plane direction)
		    controllable = 1; // set false to have static camera
		 }
		class Eventhandlers: Eventhandlers
		{
			init="_this execVM ""\SU_33_Flanker_D\sqs\init2.sqf"",[_this select 0]exec ""\SU_33_Flanker_D\sqs\init.sqs"",[_this select 0]exec ""\SU_33_Flanker_D\sqs\wing.sqs"",[_this select 0] execVM ""\SU_33_Flanker_D\sqs\AircraftEffects.sqf"",_this execVM ""\SU_33_Flanker_D\sqs\aircraftvapour.sqf""";
			fired="[_this] exec ""\SU_33_Flanker_D\sqs\fireGsh.sqs"",_this call BIS_Effects_EH_Fired";
		};
		class Library
		{
			libTextDesc = "The Sukhoi Su-33 (NATO reporting name Flanker-D) is a carrier-based multi-role fighter aircraft produced by Russian firm Sukhoi beginning in 1982. \nThe main differences from the Su-27 are that the Su-33 can operate from aircraft carriers and is capable of aerial refueling. \nThe wings were fitted with power-assisted folding, and the vertical tails were shortened to allow the fighter to fit in the typically crowded hangars of an aircraft carrier. The rear radome was shortened and reshaped to allow for the tail hook, as well as to save space inside the hangars.";
		};
		//unitInfoType = UnitInfoAirplane;
		class MFD
		{
			class HUD_HMD
			{
				topLeft="HUD LH";
				topRight="HUD PH";
				bottomLeft="HUD LD";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={0,1,0,1};
				enableParallax=0;
				class Bones
				{
					class WeaponAim
					{
						type="vector";
						source="weapon";
						pos0[]={0.5,0.55500001};
						pos10[]={1.5,1.5549999};
					};
				};
				class Draw
				{
					color[]={0,1,0,1};
					alpha=0.5;
					condition="on";
					class StallGroup
					{
						type="group";
						condition="stall";
						color[]={1,0,0};
						class StallText
						{
							type="text";
							source="static";
							text="STALL";
							align="center";
							scale=1;
							pos[]=
							{

								{
									0.5,
									"0.53 - 0.25"
								},
								1
							};
							right[]=
							{

								{
									0.55000001,
									"0.53 - 0.25"
								},
								1
							};
							down[]=
							{

								{
									0.5,
									"0.53 - 0.17"
								},
								1
							};
						};
					};
					class AAMissile
					{
						type="group";
						condition="AAmissile";
						class AAMissileCrosshair
						{
							type="line";
							width=4;
							points[]=
							{

								{
									"WeaponAim",
									{0,-0.25},
									1
								},

								{
									"WeaponAim",
									{0.043400001,-0.2462},
									1
								},

								{
									"WeaponAim",
									{0.085500002,-0.234925},
									1
								},

								{
									"WeaponAim",
									{0.125,-0.2165},
									1
								},

								{
									"WeaponAim",
									{0.16069999,-0.19149999},
									1
								},

								{
									"WeaponAim",
									{0.19149999,-0.16069999},
									1
								},

								{
									"WeaponAim",
									{0.2165,-0.125},
									1
								},

								{
									"WeaponAim",
									{0.234925,-0.085500002},
									1
								},

								{
									"WeaponAim",
									{0.2462,-0.043400001},
									1
								},

								{
									"WeaponAim",
									{0.25,0},
									1
								},

								{
									"WeaponAim",
									{0.2462,0.043400001},
									1
								},

								{
									"WeaponAim",
									{0.234925,0.085500002},
									1
								},

								{
									"WeaponAim",
									{0.2165,0.125},
									1
								},

								{
									"WeaponAim",
									{0.19149999,0.16069999},
									1
								},

								{
									"WeaponAim",
									{0.16069999,0.19149999},
									1
								},

								{
									"WeaponAim",
									{0.125,0.2165},
									1
								},

								{
									"WeaponAim",
									{0.085500002,0.234925},
									1
								},

								{
									"WeaponAim",
									{0.043400001,0.2462},
									1
								},

								{
									"WeaponAim",
									{0,0.25},
									1
								},

								{
									"WeaponAim",
									{-0.043400001,0.2462},
									1
								},

								{
									"WeaponAim",
									{-0.085500002,0.234925},
									1
								},

								{
									"WeaponAim",
									{-0.125,0.2165},
									1
								},

								{
									"WeaponAim",
									{-0.16069999,0.19149999},
									1
								},

								{
									"WeaponAim",
									{-0.19149999,0.16069999},
									1
								},

								{
									"WeaponAim",
									{-0.2165,0.125},
									1
								},

								{
									"WeaponAim",
									{-0.234925,0.085500002},
									1
								},

								{
									"WeaponAim",
									{-0.2462,0.043400001},
									1
								},

								{
									"WeaponAim",
									{-0.25,0},
									1
								},

								{
									"WeaponAim",
									{-0.2462,-0.043400001},
									1
								},

								{
									"WeaponAim",
									{-0.234925,-0.085500002},
									1
								},

								{
									"WeaponAim",
									{-0.2165,-0.125},
									1
								},

								{
									"WeaponAim",
									{-0.19149999,-0.16069999},
									1
								},

								{
									"WeaponAim",
									{-0.16069999,-0.19149999},
									1
								},

								{
									"WeaponAim",
									{-0.125,-0.2165},
									1
								},

								{
									"WeaponAim",
									{-0.085500002,-0.234925},
									1
								},

								{
									"WeaponAim",
									{-0.043400001,-0.2462},
									1
								},

								{
									"WeaponAim",
									{0,-0.25},
									1
								}
							};
						};
					};
					class ATMissile
					{
						condition="ATmissile";
						type="group";
						class ATMissileCrosshair
						{
							type="line";
							width=4;
							points[]=
							{

								{
									"WeaponAim",
									{-0.15000001,-0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										-0.15000001,
										"-0.15 + 0.02"
									},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.15000001,0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										-0.15000001,
										"0.15 - 0.02"
									},
									1
								},
								{},

								{
									"WeaponAim",
									{0.15000001,-0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										0.15000001,
										"-0.15 + 0.02"
									},
									1
								},
								{},

								{
									"WeaponAim",
									{0.15000001,0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										0.15000001,
										"0.15 - 0.02"
									},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.15000001,-0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										"-0.15 + 0.02",
										-0.15000001
									},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.15000001,0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										"-0.15 + 0.02",
										0.15000001
									},
									1
								},
								{},

								{
									"WeaponAim",
									{0.15000001,-0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										"0.15 - 0.02",
										-0.15000001
									},
									1
								},
								{},

								{
									"WeaponAim",
									{0.15000001,0.15000001},
									1
								},

								{
									"WeaponAim",

									{
										"0.15 - 0.02",
										0.15000001
									},
									1
								}
							};
						};
					};
				};
				helmetMountedDisplay = 1;
				helmetPosition[] = {-0.04, 0.04, 0.1};
				helmetRight[] = {0.08, 0, 0};
				helmetDown[] = {0, -0.08, 0};
			};
			class HUD_statick
			{
				topLeft="HUD LH";
				topRight="HUD PH";
				bottomLeft="HUD LD";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={0,1,0,1};
				enableParallax=0;
				class Bones
				{
					class PlaneOrientation
					{
						type="fixed";
						pos[]={0.5,0.52999997};
					};
					class WeaponAim
					{
						type="vector";
						source="weapon";
						pos0[]={0.5,0.55500001};
						pos10[]={1.5,1.5549999};
					};
					class Velocity
					{
						type="vector";
						source="velocity";
						pos0[]={0.5,0.52999997};
						pos10[]={1.5,1.53};
						angle=-2.3;
					};
					class Level0
					{
						type="horizon";
						pos0[]={0.5,0.52999997};
						pos10[]={1.5,1.53};
						angle=-2.3;
					};
				};
				class Draw
				{
					color[]={0,1,0,1};
					alpha=1;
					condition="on";
					class Horizont
					{
						clipTL[]={0.25,0.25};
						clipBR[]={0.75,0.75};
						class Dimmed
						{
							class Level00
							{
								type="line";
								width=15;
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"0 * 1.4"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"0 * 1.4"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"-0.045 * 1.4",
											"0 * 1.4"
										},
										1
									},

									{
										"Level0",

										{
											"-0.005 * 1.4",
											"0 * 1.4"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"0.005 * 1.4",
											"0 * 1.4"
										},
										1
									},

									{
										"Level0",

										{
											"0.045 * 1.4",
											"0 * 1.4"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"0.125 * 1.4",
											"0 * 1.4"
										},
										1
									},

									{
										"Level0",

										{
											"0.200 * 1.4",
											"0 * 1.4"
										},
										1
									}
								};
							};
							class Level2M5: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 5"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 5"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 5"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 5"
										},
										1
									}
								};
							};
							class Level2P5: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 5"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 5"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 5"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 5"
										},
										1
									}
								};
							};
							class Level2M10: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 10"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 10"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 10"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 10"
										},
										1
									}
								};
							};
							class Level2P10: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 10"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 10"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 10"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 10"
										},
										1
									}
								};
							};
							class Level2M15: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 15"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 15"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 15"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 15"
										},
										1
									}
								};
							};
							class Level2P15: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 15"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 15"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 15"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 15"
										},
										1
									}
								};
							};
							class Level2P20: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 20"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 20"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 20"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 20"
										},
										1
									}
								};
							};
							class Level2M20: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 20"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 20"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 20"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 20"
										},
										1
									}
								};
							};
							class Level2P30: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 30"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 30"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 30"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 30"
										},
										1
									}
								};
							};
							class Level2M30: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 30"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 30"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 30"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 30"
										},
										1
									}
								};
							};
							class Level2P40: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 40"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 40"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 40"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 40"
										},
										1
									}
								};
							};
							class Level2M40: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 40"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 40"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 40"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 40"
										},
										1
									}
								};
							};
							class Level2P50: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 50"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 50"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 50"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 50"
										},
										1
									}
								};
							};
							class Level2M50: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 50"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 50"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 50"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 50"
										},
										1
									}
								};
							};
							class Level2P60: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 60"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 60"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 60"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 60"
										},
										1
									}
								};
							};
							class Level2M60: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 60"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 60"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 60"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 60"
										},
										1
									}
								};
							};
							class Level2P70: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 70"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 70"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 70"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 70"
										},
										1
									}
								};
							};
							class Level2M70: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 70"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 70"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 70"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 70"
										},
										1
									}
								};
							};
							class Level2P80: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 80"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 80"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 80"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 80"
										},
										1
									}
								};
							};
							class Level2M80: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 80"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 80"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 80"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 80"
										},
										1
									}
								};
							};
							class Level2P90: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"+1.0 / 10 * 90"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"+1.0 / 10 * 90"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"+1.0 / 10 * 90"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"+1.0 / 10 * 90"
										},
										1
									}
								};
							};
							class Level2M90: Level00
							{
								type="line";
								points[]=
								{

									{
										"Level0",

										{
											"-0.200 * 1.4",
											"-1.0 / 10 * 90"
										},
										1
									},

									{
										"Level0",

										{
											"-0.125 * 1.4",
											"-1.0 / 10 * 90"
										},
										1
									},
									{},

									{
										"Level0",

										{
											"+0.125 * 1.4",
											"-1.0 / 10 * 90"
										},
										1
									},

									{
										"Level0",

										{
											"+0.200 * 1.4",
											"-1.0 / 10 * 90"
										},
										1
									}
								};
							};
						};
					};
					class PlaneOrientation_MiniPlane
					{
						width=20;
						type="line";
						points[]=
						{

							{
								"PlaneOrientation",
								{0.20999999,0},
								1
							},

							{
								"PlaneOrientation",
								1,
								{0.07,0},
								1
							},
							{},

							{
								"PlaneOrientation",
								1,
								{-0.20999999,0},
								1
							},

							{
								"PlaneOrientation",
								{-0.07,0},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0,0},
								1
							},

							{
								"PlaneOrientation",
								{0,-0.14},
								1
							}
						};
					};
					class PlaneOrientationLines
					{
						clipTL[]={0,0.1};
						clipBR[]={1,0};
						type="line";
						width=4;
						points[]=
						{

							{
								"PlaneOrientation",
								{-0.20999999,7.2250699e-009},
								1
							},

							{
								"PlaneOrientation",
								{-0.28,9.6334301e-009},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0.20999999,-1.97107e-009},
								1
							},

							{
								"PlaneOrientation",
								{0.28,-2.62809e-009},
								1
							},
							{},

							{
								"PlaneOrientation",
								{-0.105,0.14314599},
								1
							},

							{
								"PlaneOrientation",
								{-0.14,0.190861},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0.105,0.14314599},
								1
							},

							{
								"PlaneOrientation",
								{0.14,0.190861},
								1
							},
							{},

							{
								"PlaneOrientation",
								{-0.18186501,0.0826452},
								1
							},

							{
								"PlaneOrientation",
								{-0.242487,0.110194},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0.18186501,0.0826452},
								1
							},

							{
								"PlaneOrientation",
								{0.242487,0.110194},
								1
							},
							{},

							{
								"PlaneOrientation",
								{-0.20284399,0.042780299},
								1
							},

							{
								"PlaneOrientation",
								{-0.270459,0.057040401},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0.20284399,0.042780299},
								1
							},

							{
								"PlaneOrientation",
								{0.270459,0.057040401},
								1
							},
							{},

							{
								"PlaneOrientation",
								{-0.20920099,0.014406},
								1
							},

							{
								"PlaneOrientation",
								{-0.244068,0.016806999},
								1
							},
							{},

							{
								"PlaneOrientation",
								{-0.20681,0.028702401},
								1
							},

							{
								"PlaneOrientation",
								{-0.24127799,0.033486102},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0.20681,0.028702401},
								1
							},

							{
								"PlaneOrientation",
								{0.24127799,0.033486102},
								1
							},
							{},

							{
								"PlaneOrientation",
								{0.20920099,0.014406},
								1
							},

							{
								"PlaneOrientation",
								{0.244068,0.016806999},
								1
							},
							{}
						};
					};
					class WeaponName
					{
						type="text";
						source="weapon";
						sourceScale=1;
						align="right";
						scale=1;
						pos[]=
						{
							{0.029999999,0.94},
							1
						};
						right[]=
						{
							{0.079999998,0.94},
							1
						};
						down[]=
						{
							{0.029999999,0.98000002},
							1
						};
					};
					class AmmoCount
					{
						type="text";
						source="ammo";
						sourceScale=1;
						align="right";
						scale=1;
						pos[]=
						{
							{0.029999999,0.88999999},
							1
						};
						right[]=
						{
							{0.079999998,0.88999999},
							1
						};
						down[]=
						{
							{0.029999999,0.93000001},
							1
						};
					};
					class FlapsGroup
					{
						type="group";
						condition="flaps";
						class FlapsText
						{
							type="text";
							source="static";
							text="FLAPS";
							align="right";
							scale=1;
							pos[]=
							{

								{
									0.029999999,
									"0.53 - 0.045"
								},
								1
							};
							right[]=
							{

								{
									0.079999998,
									"0.53 - 0.045"
								},
								1
							};
							down[]=
							{

								{
									0.029999999,
									"0.53 - 0.005"
								},
								1
							};
						};
					};
					class GearGroup
					{
						type="group";
						condition="ils";
						class GearText
						{
							type="text";
							source="static";
							text="GEAR";
							align="right";
							scale=1;
							pos[]=
							{

								{
									0.029999999,
									"0.53 + 0.005"
								},
								1
							};
							right[]=
							{

								{
									0.079999998,
									"0.53 + 0.005"
								},
								1
							};
							down[]=
							{

								{
									0.029999999,
									"0.53 + 0.045"
								},
								1
							};
						};
					};
					class LightsGroup
					{
						type="group";
						condition="lights";
						class LightsText
						{
							type="text";
							source="static";
							text="LIGHTS";
							align="right";
							scale=1;
							pos[]=
							{

								{
									0.029999999,
									"0.53 + 0.055"
								},
								1
							};
							right[]=
							{

								{
									0.079999998,
									"0.53 + 0.055"
								},
								1
							};
							down[]=
							{

								{
									0.029999999,
									"0.53 + 0.095"
								},
								1
							};
						};
					};
					class CollisionLightsGroup
					{
						type="group";
						condition="collisionlights";
						class CollisionLightsText
						{
							type="text";
							source="static";
							text="A-COL";
							align="right";
							scale=1;
							pos[]=
							{

								{
									0.029999999,
									"0.53 + 0.105"
								},
								1
							};
							right[]=
							{

								{
									0.079999998,
									"0.53 + 0.105"
								},
								1
							};
							down[]=
							{

								{
									0.029999999,
									"0.53 + 0.145"
								},
								1
							};
						};
					};
					class PitchNumber
					{
						type="text";
						source="horizonDive";
						sourceScale=57.295799;
						align="right";
						scale=1;
						pos[]=
						{
							{0.50999999,0.88999999},
							1
						};
						right[]=
						{
							{0.56,0.88999999},
							1
						};
						down[]=
						{
							{0.50999999,0.93000001},
							1
						};
					};
					class PitchText
					{
						type="text";
						source="static";
						text="PITCH";
						align="left";
						scale=1;
						pos[]=
						{
							{0.49000001,0.88999999},
							1
						};
						right[]=
						{
							{0.54000002,0.88999999},
							1
						};
						down[]=
						{
							{0.49000001,0.93000001},
							1
						};
					};
					class RollNumber
					{
						type="text";
						source="horizonBank";
						sourceScale=57.295799;
						align="right";
						scale=1;
						pos[]=
						{
							{0.50999999,0.83999997},
							1
						};
						right[]=
						{
							{0.56,0.83999997},
							1
						};
						down[]=
						{
							{0.50999999,0.88},
							1
						};
					};
					class RollText
					{
						type="text";
						source="static";
						text="ROLL";
						align="left";
						scale=1;
						pos[]=
						{
							{0.49000001,0.83999997},
							1
						};
						right[]=
						{
							{0.54000002,0.83999997},
							1
						};
						down[]=
						{
							{0.49000001,0.88},
							1
						};
					};
					class SpeedNumber
					{
						type="text";
						source="speed";
						sourceScale=3.5999999;
						align="right";
						scale=1;
						pos[]=
						{
							{0.13,0.14},
							1
						};
						right[]=
						{
							{0.18000001,0.14},
							1
						};
						down[]=
						{
							{0.13,0.18000001},
							1
						};
					};
					class SpeedText
					{
						type="text";
						source="static";
						text="SPD";
						align="left";
						scale=1;
						pos[]=
						{
							{0.11,0.14},
							1
						};
						right[]=
						{
							{0.16,0.14},
							1
						};
						down[]=
						{
							{0.11,0.18000001},
							1
						};
					};
					class AltitudeNumber
					{
						type="text";
						source="altitudeAGL";
						sourceScale=1;
						align="right";
						scale=1;
						pos[]=
						{
							{0.88999999,0.14},
							1
						};
						right[]=
						{
							{0.94,0.14},
							1
						};
						down[]=
						{
							{0.88999999,0.18000001},
							1
						};
					};
					class AltitudeText
					{
						type="text";
						source="static";
						text="AGL";
						align="left";
						scale=1;
						pos[]=
						{
							{0.87,0.14},
							1
						};
						right[]=
						{
							{0.92000002,0.14},
							1
						};
						down[]=
						{
							{0.87,0.18000001},
							1
						};
					};
					class AltitudeArrow
					{
						type="line";
						width=4;
						points[]=
						{

							{

								{
									"0.88 + 0.018",
									"0.40 - 0.016"
								},
								1
							},

							{
								{0.88,0.40000001},
								1
							},

							{

								{
									"0.88 + 0.018",
									"0.40 + 0.016"
								},
								1
							}
						};
					};
					class AltitudeLine
					{
						type="line";
						width=4;
						points[]=
						{

							{
								{0.87,0.60000002},
								1
							},

							{
								{0.87,0.2},
								1
							}
						};
					};
					class AltitudeScale
					{
						type="scale";
						horizontal=0;
						source="altitudeAGL";
						sourceScale=1;
						width=4;
						top=0.60000002;
						center=0.40000001;
						bottom=0.2;
						lineXleft=0.88;
						lineYright=0.88999999;
						lineXleftMajor=0.88;
						lineYrightMajor=0.89999998;
						majorLineEach=5;
						numberEach=5;
						step=20;
						stepSize="(0.60 - 0.20) / 15";
						align="right";
						scale=1;
						pos[]={0.91000003,0.57999998};
						right[]={0.95999998,0.57999998};
						down[]={0.91000003,0.62};
					};
					class ClimbNumber
					{
						type="text";
						source="vspeed";
						sourceScale=1;
						align="right";
						scale=1;
						pos[]=
						{
							{0.88999999,0.94},
							1
						};
						right[]=
						{
							{0.94,0.94},
							1
						};
						down[]=
						{
							{0.88999999,0.98000002},
							1
						};
					};
					class ClimbText
					{
						type="text";
						source="static";
						text="CLIMB";
						align="left";
						scale=1;
						pos[]=
						{
							{0.87,0.94},
							1
						};
						right[]=
						{
							{0.92000002,0.94},
							1
						};
						down[]=
						{
							{0.87,0.98000002},
							1
						};
					};
					class ClimbArrow
					{
						type="line";
						width=4;
						points[]=
						{

							{

								{
									"0.88 + 0.018",
									"0.80 - 0.016"
								},
								1
							},

							{
								{0.88,0.80000001},
								1
							},

							{

								{
									"0.88 + 0.018",
									"0.80 + 0.016"
								},
								1
							}
						};
					};
					class ClimbLine
					{
						type="line";
						width=4;
						points[]=
						{

							{
								{0.87,0.92500001},
								1
							},

							{
								{0.87,0.67500001},
								1
							}
						};
					};
					class ClimbScale
					{
						type="scale";
						horizontal=0;
						source="vspeed";
						sourceScale=1;
						width=4;
						top=0.92500001;
						center=0.80000001;
						bottom=0.67500001;
						lineXleft=0.88;
						lineYright=0.88999999;
						lineXleftMajor=0.88;
						lineYrightMajor=0.89999998;
						majorLineEach=2;
						numberEach=4;
						step=5;
						stepSize="(0.925 - 0.675) / 15";
						align="right";
						scale=1;
						pos[]={0.91000003,0.90499997};
						right[]={0.95999998,0.90499997};
						down[]={0.91000003,0.94499999};
					};
					class HeadingArrow
					{
						type="line";
						width=4;
						points[]=
						{

							{

								{
									"0.5 - 0.02",
									"0.11 - 0.02"
								},
								1
							},

							{
								{0.5,0.11},
								1
							},

							{

								{
									"0.5 + 0.02",
									"0.11 - 0.02"
								},
								1
							}
						};
					};
					class HeadingLine
					{
						type="line";
						width=4;
						points[]=
						{

							{
								{0.30000001,0.12},
								1
							},

							{
								{0.69999999,0.12},
								1
							}
						};
					};
					class HeadingScale
					{
						type="scale";
						scale=1;
						source="Heading";
						sourceScale=1;
						align="center";
						pos[]=
						{
							"0.21-0.01",
							0
						};
						right[]=
						{
							"0.29-0.01",
							0
						};
						down[]=
						{
							"0.21-0.01",
							0.050000001
						};
						lineXleft=0.059999999;
						lineYright=0.050000001;
						lineXleftMajor=0.059999999;
						lineYrightMajor=0.039999999;
						bottom=0.80000001;
						center=0.5;
						top=0.2;
						step="18/9";
						StepSize="(0.80- 0.2)/20";
						horizontal=1;
						min="none";
						max="none";
						numberEach=5;
						majorLineEach=5;
					};
					class RadarTargets
					{
						type="radar";
						width=4;
						angle=-2.3;
						pos0[]={0.5,0.55500001};
						pos10[]={1.24,1.325};
						points[]=
						{

							{
								{-0.050000001,-0.047297299},
								1
							},

							{
								{0.050000001,-0.047297299},
								1
							},

							{
								{0.050000001,0.047297299},
								1
							},

							{
								{-0.050000001,0.047297299},
								1
							},

							{
								{-0.050000001,-0.047297299},
								1
							}
						};
					};
				};
			};
			class Parallax_HUD
			{
				topLeft="HUD LH";
				topRight="HUD PH";
				bottomLeft="HUD LD";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={0,1,0,1};
				enableParallax=1;
				class Bones
				{
					class PlaneOrientation
					{
						type="fixed";
						pos[]={0.5,0.52999997};
					};
					class WeaponAim
					{
						type="vector";
						source="weapon";
						pos0[]={0.5,0.55500001};
						pos10[]={1.5,1.5549999};
					};
					class Velocity
					{
						type="vector";
						source="velocity";
						pos0[]={0.5,0.52999997};
						pos10[]={1.5,1.53};
					};
					class Level0
					{
						type="horizon";
						pos0[]={0.5,0.52999997};
						pos10[]={1.5,1.53};
						angle=-2.3;
					};
				};
				class Draw
				{
					color[]={0,1,0,1};
					alpha=0.5;
					condition="on";
					class PlaneMovementCrosshair
					{
						type="line";
						width=4;
						points[]=
						{

							{
								"Velocity",
								{0,-0.02},
								1
							},

							{
								"Velocity",
								{0.0099999998,-0.01732},
								1
							},

							{
								"Velocity",
								{0.01732,-0.0099999998},
								1
							},

							{
								"Velocity",
								{0.02,0},
								1
							},

							{
								"Velocity",
								{0.01732,0.0099999998},
								1
							},

							{
								"Velocity",
								{0.0099999998,0.01732},
								1
							},

							{
								"Velocity",
								{0,0.02},
								1
							},

							{
								"Velocity",
								{-0.0099999998,0.01732},
								1
							},

							{
								"Velocity",
								{-0.01732,0.0099999998},
								1
							},

							{
								"Velocity",
								{-0.02,0},
								1
							},

							{
								"Velocity",
								{-0.01732,-0.0099999998},
								1
							},

							{
								"Velocity",
								{-0.0099999998,-0.01732},
								1
							},

							{
								"Velocity",
								{0,-0.02},
								1
							},
							{},

							{
								"Velocity",
								{0.039999999,0},
								1
							},

							{
								"Velocity",
								{0.02,0},
								1
							},
							{},

							{
								"Velocity",
								{-0.039999999,0},
								1
							},

							{
								"Velocity",
								{-0.02,0},
								1
							},
							{},

							{
								"Velocity",
								{0,-0.039999999},
								1
							},

							{
								"Velocity",
								{0,-0.02},
								1
							}
						};
					};
					class MGun
					{
						condition="mgun";
						class Circle
						{
							type="line";
							points[]=
							{

								{
									"WeaponAim",
									{0.0099999998,0},
									1
								},

								{
									"WeaponAim",
									{-0.0099999998,0},
									1
								},
								{},

								{
									"WeaponAim",
									{0,0.0094594602},
									1
								},

								{
									"WeaponAim",
									{0,-0.0094594602},
									1
								},
								{},

								{
									"WeaponAim",
									{0,-0.066216201},
									1
								},

								{
									"WeaponAim",
									{0.048999999,-0.046351399},
									1
								},

								{
									"WeaponAim",
									{0.07,0},
									1
								},

								{
									"WeaponAim",
									{0.048999999,0.046351399},
									1
								},

								{
									"WeaponAim",
									{0,0.066216201},
									1
								},

								{
									"WeaponAim",
									{-0.048999999,0.046351399},
									1
								},

								{
									"WeaponAim",
									{-0.07,0},
									1
								},

								{
									"WeaponAim",
									{-0.048999999,-0.046351399},
									1
								},

								{
									"WeaponAim",
									{0,-0.066216201},
									1
								},
								{},

								{
									"WeaponAim",
									{0,-0.132432},
									1
								},

								{
									"WeaponAim",
									{0.07,-0.115216},
									1
								},

								{
									"WeaponAim",
									{0.1218,-0.066216201},
									1
								},

								{
									"WeaponAim",
									{0.14,0},
									1
								},

								{
									"WeaponAim",
									{0.1218,0.066216201},
									1
								},

								{
									"WeaponAim",
									{0.07,0.115216},
									1
								},

								{
									"WeaponAim",
									{0,0.132432},
									1
								},

								{
									"WeaponAim",
									{-0.07,0.115216},
									1
								},

								{
									"WeaponAim",
									{-0.1218,0.066216201},
									1
								},

								{
									"WeaponAim",
									{-0.14,0},
									1
								},

								{
									"WeaponAim",
									{-0.1218,-0.066216201},
									1
								},

								{
									"WeaponAim",
									{-0.07,-0.115216},
									1
								},

								{
									"WeaponAim",
									{0,-0.132432},
									1
								},
								{},

								{
									"WeaponAim",
									{0,-0.132432},
									1
								},

								{
									"WeaponAim",
									{0,-0.151351},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.07,-0.11469},
									1
								},

								{
									"WeaponAim",
									{-0.079999998,-0.131074},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.121244,-0.066216201},
									1
								},

								{
									"WeaponAim",
									{-0.13856401,-0.075675704},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.14,5.7888099e-009},
									1
								},

								{
									"WeaponAim",
									{-0.16,6.6157799e-009},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.121244,0.066216201},
									1
								},

								{
									"WeaponAim",
									{-0.13856401,0.075675704},
									1
								},
								{},

								{
									"WeaponAim",
									{-0.07,0.11469},
									1
								},

								{
									"WeaponAim",
									{-0.079999998,0.131074},
									1
								},
								{},

								{
									"WeaponAim",
									{1.22392e-008,0.132432},
									1
								},

								{
									"WeaponAim",
									{1.39876e-008,0.151351},
									1
								},
								{},

								{
									"WeaponAim",
									{0.07,0.11469},
									1
								},

								{
									"WeaponAim",
									{0.079999998,0.131074},
									1
								},
								{},

								{
									"WeaponAim",
									{0.121244,0.066216201},
									1
								},

								{
									"WeaponAim",
									{0.13856401,0.075675704},
									1
								},
								{},

								{
									"WeaponAim",
									{0.14,-1.57924e-009},
									1
								},

								{
									"WeaponAim",
									{0.16,-1.80485e-009},
									1
								},
								{},

								{
									"WeaponAim",
									{0.121244,-0.066216201},
									1
								},

								{
									"WeaponAim",
									{0.13856401,-0.075675704},
									1
								},
								{},

								{
									"WeaponAim",
									{0.07,-0.11469},
									1
								},

								{
									"WeaponAim",
									{0.079999998,-0.131074},
									1
								},
								{}
							};
						};
					};
					class BombCrosshairGroup
					{
						type="group";
						condition="bomb";
						class BombCrosshair
						{
							type="line";
							width=4;
							points[]=
							{

								{
									"WeaponAim",
									{0,-0.1},
									1
								},

								{
									"WeaponAim",
									{0.01736,-0.098480001},
									1
								},

								{
									"WeaponAim",
									{0.034200002,-0.093970001},
									1
								},

								{
									"WeaponAim",
									{0.050000001,-0.086599998},
									1
								},

								{
									"WeaponAim",
									{0.064280003,-0.0766},
									1
								},

								{
									"WeaponAim",
									{0.0766,-0.064280003},
									1
								},

								{
									"WeaponAim",
									{0.086599998,-0.050000001},
									1
								},

								{
									"WeaponAim",
									{0.093970001,-0.034200002},
									1
								},

								{
									"WeaponAim",
									{0.098480001,-0.01736},
									1
								},

								{
									"WeaponAim",
									{0.1,0},
									1
								},

								{
									"WeaponAim",
									{0.098480001,0.01736},
									1
								},

								{
									"WeaponAim",
									{0.093970001,0.034200002},
									1
								},

								{
									"WeaponAim",
									{0.086599998,0.050000001},
									1
								},

								{
									"WeaponAim",
									{0.0766,0.064280003},
									1
								},

								{
									"WeaponAim",
									{0.064280003,0.0766},
									1
								},

								{
									"WeaponAim",
									{0.050000001,0.086599998},
									1
								},

								{
									"WeaponAim",
									{0.034200002,0.093970001},
									1
								},

								{
									"WeaponAim",
									{0.01736,0.098480001},
									1
								},

								{
									"WeaponAim",
									{0,0.1},
									1
								},

								{
									"WeaponAim",
									{-0.01736,0.098480001},
									1
								},

								{
									"WeaponAim",
									{-0.034200002,0.093970001},
									1
								},

								{
									"WeaponAim",
									{-0.050000001,0.086599998},
									1
								},

								{
									"WeaponAim",
									{-0.064280003,0.0766},
									1
								},

								{
									"WeaponAim",
									{-0.0766,0.064280003},
									1
								},

								{
									"WeaponAim",
									{-0.086599998,0.050000001},
									1
								},

								{
									"WeaponAim",
									{-0.093970001,0.034200002},
									1
								},

								{
									"WeaponAim",
									{-0.098480001,0.01736},
									1
								},

								{
									"WeaponAim",
									{-0.1,0},
									1
								},

								{
									"WeaponAim",
									{-0.098480001,-0.01736},
									1
								},

								{
									"WeaponAim",
									{-0.093970001,-0.034200002},
									1
								},

								{
									"WeaponAim",
									{-0.086599998,-0.050000001},
									1
								},

								{
									"WeaponAim",
									{-0.0766,-0.064280003},
									1
								},

								{
									"WeaponAim",
									{-0.064280003,-0.0766},
									1
								},

								{
									"WeaponAim",
									{-0.050000001,-0.086599998},
									1
								},

								{
									"WeaponAim",
									{-0.034200002,-0.093970001},
									1
								},

								{
									"WeaponAim",
									{-0.01736,-0.098480001},
									1
								},

								{
									"WeaponAim",
									{0,-0.1},
									1
								},
								{},

								{
									"Velocity",
									0.001,
									"WeaponAim",
									{0,0},
									1
								},

								{
									"Velocity",
									{0,0},
									1
								}
							};
						};
					};
				};
			};
		};
	};
	class Su33_Protatype_PT_2: Su33_Protatype_PT
	{
		displayName="Sukhoi Su-33 Flanker-D";
		model="\SU_33_Flanker_D\Su33_protatype_2.p3d";
	}
};
/*class CfgFunctions
{
	class sukhoi
	{
		class SU33_MFD
		{
			file="\Su_33_Flanker_D\sqs\su33_MFD.sqf";
		};
	};
};*/

class CfgNonAIVehicles
{
	class ProxyDriver;
	class ProxyWeapon;
	class Proxym_kh29: ProxyWeapon
	{
		model="\SU_33_Flanker_D\wep\KH-29";
		simulation="maverickweapon";
	};
	class Proxym_r73: ProxyWeapon
	{
		model="\SU_33_Flanker_D\wep\R73_proxy";
		simulation="maverickweapon";
	};
	class Proxym_r77: ProxyWeapon
	{
		model="\SU_33_Flanker_D\wep\R77_proxy";
		simulation="maverickweapon";
	};
	class Proxym_r27: ProxyWeapon
	{
		model="\SU_33_Flanker_D\wep\R27RE_proxy";
		simulation="maverickweapon";
	};
	class Proxym_kab500l: ProxyWeapon
	{
		model="\SU_33_Flanker_D\wep\FAB-500";
		simulation="maverickweapon";
	};
	/*class Proxym_s8_launcher_x1: ProxyWeapon
	{
		model="\js_jc_su35\stores\m_s8_launcher_x1";
		simulation="maverickweapon";
	};
	class Proxym_s8_launcher_x2: ProxyWeapon
	{
		model="\js_jc_su35\stores\m_s8_launcher_x2";
		simulation="maverickweapon";
	};*/
};
