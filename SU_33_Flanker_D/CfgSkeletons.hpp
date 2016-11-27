class CfgSkeletons
{
	class Default
	{
		isDiscrete = 1;
		skeletonInherit = "";
		skeletonBones[] = {};
	};
	class Vehicle : Default {};
	class Plane: Vehicle
	{
		skeletonInherit="Vehicle";
		skeletonBones[]=
		{
		};
	};
	class Su_33_Base_F: Plane
	{
		skeletonInherit = "Plane";
		skeletonBones[] =
		{
			"stick_pilot",""
		};
	};
	class Su_33_Plane_01_skeleton : Su_33_Base_F
	{
		isDiscrete = 0;
		skeletonInherit = "Su_33_Base_F";
		skeletonBones[]=
		{
			"rotor_1","",
			"rotor_2","",
			"flap_nr1","",
			"flap_nl1","",
			"flap_r11","",
			"flap_r12","flap_r11",
			"flap_l11","",
			"flap_l12","flap_l11",
			"flap_2_1","",
			"flap_2_2","",
			"canard","",
			"elevator_ll","",
			"elevator_l","elevator_ll",
			"elevator_l1","elevator_l",
			"elevator_rr","",
			"elevator_r","elevator_rr",
			"elevator_r1","elevator_r",
			"rudder_l","",
			"rudder_r","",
			"wing","",
			"wing_l","",
			"flap_nl2","wing_l",
			"flap_l21","wing_l",
			"flap_l22","flap_l21",
			"aileron_l1","wing_l",
			"aileron_l","aileron_l1",
			"wing_r","",
			"flap_nr2","wing_r",
			"flap_r21","wing_r",
			"flap_r22","flap_r21",
			"aileron_r1","wing_r",
			"aileron_r","aileron_r1",
			"airbrake","",
			"airbrake_1","",
			"airbrake_2","airbrake_1",
			"canopy_piston","",
			"canopy_piston2","canopy_piston",
			"canopy","",
			"hook","",
			"abcut","",
			"door_n","",
			"piston","",
			"gear_n","",
			"gear_n_steering","gear_n",
			"wheel_n","gear_n_steering",
			"gear_n_piston_2","",
			"gear_r1","",
			"gear_r","gear_r1",
			"wheel_r","gear_r",
			"gear_r_pick","gear_r",
			"door_br1","",
			"door_br2","",
			"gear_l1","",
			"gear_l","gear_l1",
			"wheel_l","gear_l",
			"gear_l_pick","gear_l",
			"door_bl1","",
			"door_bl2","",
			"nozzle1","",
			"nozzle2","",
			"nozzle3","",
			"nozzle4","",
			"nozzle5","",
			"nozzle6","",
			"nozzle7","",
			"nozzle8","",
			"ladder","",
		};
	};
};
