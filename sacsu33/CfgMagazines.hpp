class CfgMagazines
{
	class VehicleMagazine;
	class 300Rnd_CMFlare_Chaff_Magazine;
	class SAC_150Rnd_30mm_GSh301: VehicleMagazine
	{
		scope=2;
		count=500;
		ammo="B_35mm_AA";
		initSpeed=1036;
		tracersEvery=2;
		nameSound="cannon";
	};
	class SAC_6Rnd_R73: VehicleMagazine
	{
		scope=2;
		displayName="R-73";
		displayNameShort="R-73";
		ammo="SAC_M_R73_AA";
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
	class SAC_4Rnd_R73: SAC_6Rnd_R73
	{
		count=4;
	};
	class SAC_6Rnd_R27RE: SAC_6Rnd_R73
	{
		scope=2;
		displayName="R-27RE";
		count=6;
		ammo="SAC_M_R27RE";
		initSpeed=0;
	};
	class SAC_4Rnd_R27RE: SAC_6Rnd_R27RE
	{
		count=4;
	};
	class SAC_6Rnd_R77: VehicleMagazine
	{
		scope=2;
		displayName="R-77";
		count=6;
		ammo="SAC_M_R77";
		initSpeed=0;
	};
	class SAC_4Rnd_R77: SAC_6Rnd_R77
	{
		count=4;
	};
};
