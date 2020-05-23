
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
	class Su_300Rnd_30mm_GSh301: VehicleMagazine
	{
		scope=2;
		count=150;
		ammo="Su_GSh301_35mm";
		initSpeed=900;
		tracersEvery=1;
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
};
