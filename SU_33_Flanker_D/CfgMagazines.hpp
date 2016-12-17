class CfgMagazines
{
	class VehicleMagazine;
	class Su_4Rnd_fab_500: VehicleMagazine
	{
		scope=2;
		count=4;
		ammo="Fab_500";
		initSpeed=0;
		ammoIsProxy = true;
	};
	class Su_300Rnd_30mm_GSh301: VehicleMagazine
	{
		scope=2;
		count=300;
		ammo="Su_GSh301_30mm";
		initSpeed=900;
		tracersEvery=1;
		ammoIsProxy = true;
	};
	class Su33_kh29_x4: VehicleMagazine
	{
		scope=2;
		displayName="Kh-29L";
		displayNameShort="Kh-29L";
		ammo="Su35_kh_29";
		ammoIsProxy = true;
		initSpeed=0;
		maxLeadSpeed=220;
		sound[]=
		{
			"",
			1,
			1
		};
		reloadSound[]=
		{
			"",
			0.00031622799,
			1
		};
		count=4;
		nameSound="missiles";
	};
	class Su_6Rnd_R73: VehicleMagazine
	{
		scope=2;
		displayName="R-73";
		displayNameShort="R-73";
		ammo="Su_M_R73_AA";
		ammoIsProxy = true;
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
	class Su_6Rnd_R73M1_AA: Su_6Rnd_R73
	{
		ammo="Su_M_R73M1_AA";
		displayName="R-73M1";
		displayNameShort="R-73M1";
		ammoIsProxy = true;
		count=6
	};
	class Su_2Rnd_R27R: Su_6Rnd_R73
	{
		scope=2;
		displayName="R-27R";
		displayNameShort="R-27R";
		count=2;
		ammoIsProxy = true;
		ammo="Su_M_R27R";
		initSpeed=0;
	};
	class Su_2Rnd_R27EA: Su_2Rnd_R27R
	{
		scope=2;
		displayName="R-27EA";
		displayNameShort="R-27EA";
		count=2;
		ammoIsProxy = true;
		ammo="Su_M_R27EA";
		initSpeed=0;
	};
	class Su_4Rnd_R77: Su_6Rnd_R73
	{
		scope=2;
		displayName="R-77";
		displayNameShort="R-77";
		count=4;
		ammoIsProxy = true;
		ammo="Su_M_R77";
		initSpeed=0;
		maxLeadSpeed=650;
	};
	class Su_80Rnd_S8T: VehicleMagazine
	{
		scope=2;
		displayName="S8 Rocket";
		ammo="Su_rocket_80mm_HE";
		count=80;
		ammoIsProxy = true;
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
