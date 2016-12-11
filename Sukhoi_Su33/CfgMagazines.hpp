class CfgMagazines
{
	class VehicleMagazine;
	class Su_300Rnd_30mm_GSh301: VehicleMagazine
	{
		scope=2;
		count=300;
		ammo="B_40mm_GPR_Tracer_Red";
		initSpeed=1036;
		tracersEvery=1;
		nameSound="cannon";
	};
	class Su_6Rnd_R73: VehicleMagazine
	{
		scope=2;
		displayName="R-73";
		displayNameShort="R-73";
		ammo="Su_M_R73_AA";
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
	class Su_4Rnd_R73: Su_6Rnd_R73
	{
		count=4;
	};
	class Su_6Rnd_R73M1_AA: Su_4Rnd_R73
	{
		ammo="Su_M_R73M1_AA";
		displayName="R-73M1";
		displayNameShort="R-73M1";
		count=6
	};
	class Su_2Rnd_R73: Su_6Rnd_R73
	{
		count=2;
	}
	class Su_6Rnd_R27R: Su_6Rnd_R73
	{
		scope=2;
		displayName="R-27ER";
		displayNameShort="R-27ER";
		count=6;
		ammo="Su_M_R27ER";
		initSpeed=0;
	};
	class Su_6Rnd_R27EA: Su_6Rnd_R73
	{
		scope=2;
		displayName="R-27EA";
		displayNameShort="R-27EA";
		count=6;
		ammo="Su_M_R27EA";
		initSpeed=0;
	};
	class Su_4Rnd_R27R: Su_6Rnd_R27R
	{
		displayName="R-27ER";
		displayNameShort="R-27ER";
		count=4;
	};
	class Su_2Rnd_R27R: Su_6Rnd_R27R
	{
		count=2;
	};
	class Su_6Rnd_R77: Su_6Rnd_R73
	{
		scope=2;
		displayName="R-77";
		count=6;
		ammo="Su_M_R77";
		initSpeed=0;
	};
	class Su_4Rnd_R77: Su_6Rnd_R77
	{
		count=4;
	};
	class Su_2Rnd_R77: Su_6Rnd_R77
	{
		count=2;
	};
	class Su_80Rnd_S8T: VehicleMagazine
	{
		scope=2;
		displayName="S8 Rocket";
		ammo="Su_rocket_80mm_HE";
		count=80;
		initSpeed=0;
		nameSound="rockets";
		sound[]=
		{
			"A3\sounds_f\weapons\rockets\explosion_missile_02",
			1,
			1,
			1200
		};
		reloadSound[]=
		{
			"",
			0.00031622799,
			1
		};
	};
};
