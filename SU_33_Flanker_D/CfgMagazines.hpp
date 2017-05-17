class CfgMagazines
{
	class VehicleMagazine;

	class Su_fake_M: VehicleMagazine
	{
		scope=2;
		count=1;
		ammo="Su_fak_ammo";
		initSpeed=0;
		ammoIsProxy = true;
	};
	class Su_fab_250: VehicleMagazine
	{
		scope=2;
		count=1;
		ammo="Su_fab_250";
		initSpeed=0;
		ammoIsProxy = true;
	};
	class Su_fab_500: VehicleMagazine
	{
		scope=2;
		displayName="KAB-500L";
		descriptionShort="KAB-500L";
		displayNameShort="KAB-500L";
		ammo="su_kab500";
		ammoIsProxy = true;
		initSpeed=0;
		maxLeadSpeed=1000;
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
		count=1;
		nameSound="";
	};
	class Su_300Rnd_30mm_GSh301: VehicleMagazine
	{
		scope=2;
		count=300;
		ammo="Su_GSh301_35mm";
		initSpeed=900;
		tracersEvery=1;
		ammoIsProxy = true;
	};
	class Su_MagazineBase_AG : VehicleMagazine
	{
		scope = 1;
		displayName = "";
		ammo = "";
		count = 2;
		initSpeed = 0;
		maxLeadSpeed = 150;
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
		nameSound = "missiles";
		WeaponLockSystem = 8;
		cmImmunity = 0.9;
	};
	class Su_kh29: VehicleMagazine
	{
		scope=2;
		displayName="Kh-29L";
		displayNameShort="Kh-29L";
		ammo="Su_kh_29";
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
		count=1;
		nameSound="missiles";
	};
	class Su_KH31 : Su_MagazineBase_AG
	{
		scope = 2;
		displayName = "Kh-31U Krypton";
		ammo = Su_KH31_AG;
		count = 1;
		ammoIsProxy = true;
	};
	class Su_R73: VehicleMagazine
	{
		scope=2;
		displayName="R-73";
		displayNameShort="R-73";
		ammo="Su_R73_AA";
		ammoIsProxy = true;
		count=1;
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
	class Su_R73M1: Su_R73
	{
		ammo="Su_R73M1_AA";
		displayName="R-73M1";
		displayNameShort="R-73M1";
		ammoIsProxy = true;
		count=1;
	};
	class Su_R27R: Su_R73
	{
		scope=2;
		displayName="R-27R";
		displayNameShort="R-27R";
		count=1;
		ammoIsProxy = true;
		ammo="Su_R27R_AA";
		initSpeed=0;
	};
	class Su_R27EA: Su_R27R
	{
		scope=2;
		displayName="R-27EA";
		displayNameShort="R-27EA";
		count=1;
		ammoIsProxy = true;
		ammo="Su_R27EA_AA";
		initSpeed=0;
	};
	class Su_R77: Su_R73
	{
		scope=2;
		displayName="R-77";
		displayNameShort="R-77";
		count=1;
		ammoIsProxy = true;
		ammo="Su_R77_AA";
		initSpeed=0;
	};
	class Su_20Rnd1_S8T: VehicleMagazine
	{
		scope=2;
		displayName="S8 Rocket";
		ammo="Su_rocket_80mm_HE";
		count=20;
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
	class Su_20Rnd2_S8T: VehicleMagazine
	{
		scope=2;
		displayName="S8 Rocket";
		ammo="Su_rocket_80mm_HE";
		count=20;
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
	class Su_20Rnd3_S8T: VehicleMagazine
	{
		scope=2;
		displayName="S8 Rocket";
		ammo="Su_rocket_80mm_HE";
		count=20;
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
	class Su_20Rnd4_S8T: VehicleMagazine
	{
		scope=2;
		displayName="S8 Rocket";
		ammo="Su_rocket_80mm_HE";
		count=20;
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
