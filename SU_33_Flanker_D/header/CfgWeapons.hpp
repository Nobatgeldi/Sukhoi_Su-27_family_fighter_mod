class CfgWeapons
{
	class MissileLauncher;
	class weapon_R73Launcher;
	class FakeWeapon;
	class autocannon_35mm;

	class Su_GSh301: autocannon_35mm
	{
		displayName="GSH-301 30mm";
		displayNameMagazine="GSH-301 30mm";
		shortNameMagazine="GSH-301 30mm";
		cursor="EmptyCursor";
		cursorAim="";
		cursorAimOn="";
		type=WeaponHardMounted;
		burst=2;
		reloadTime=0.1;
		dispersion=0.0024999999;
		soundContinuous=0;
		showToPlayer=1;
		aiRateOfFire=0.5;
		aiRateOfFireDistance=50;
		minRange=1;
		minRangeProbab=0.0099999998;
		midRange=2;
		midRangeProbab=0.0099999998;
		maxRange=3;
		maxRangeProbab=0.0099999998;
		magazines[]=
		{
			"Su_300Rnd_30mm_GSh301"
		};
	};
	class Su_R73Launcher: weapon_R73Launcher
	{
		canLock=2;
		autoFire=0;
		displayName="R-73 Archer";
		displayNameMagazine="R-73 Archer";
		shortNameMagazine="R-73 Archer";
		cursorAim="EmptyCursor";
		cursor="EmptyCursor";
		minRange=300;
		minRangeProbab=0.025;
		maxRange=9000;
		maxRangeProbab=0.0099999998;
		sound[]={"A3\Sounds_F\weapons\Rockets\rocket_fly_2",db+47,1};
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\weapons\Rockets\missile_2",
				1.12202,
				1.3,
				1000
			};
			soundBegin[]=
			{
				"begin1",
				1
			};
			weaponSoundEffect="DefaultRifle";
		};
		soundFly[]=
		{
			"A3\Sounds_F\weapons\Rockets\rocket_fly_2",
			1,
			1.5,
			700
		};
		lockingTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			0.316228,
			1
		};
		lockedTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			0.316228,
			2.5
		};
		reloadTime=0.1;
		magazineReloadTime=0.1;
		magazines[]=
		{
			"Su_R73"
		};
		holdsterAnimValue=3;
		weaponLockSystem="2 + 16 + 4";
		weaponLockDelay=3;
		textureType="semi";
	};
	class Su_R73M1Launcher: Su_R73Launcher
	{
		displayName="R-73M1 Archer";
		displayNameMagazine="R-73M1 Archer";
		shortNameMagazine="R-73M1 Archer";
		magazines[]=
		{
			"Su_R73M1"
		};
	};
	class Su_fake_weapon: FakeWeapon
	{
		displayName="Safe mod";
		displayNameMagazine="Safe mod";
		type=WeaponHardMounted;
		shortNameMagazine="Safe mod";
		magazines[]=
		{
		};
	};
	/*class Su_K31_weapon: MissileLauncher
	{
      scope = 2;
      holdsterAnimValue = 1;
      displayName = "Kh-31U Krypton";
      displayNameMagazine = "Kh-31U";
      shortNameMagazine = "Kh-31U";
      sounds[] = {"StandardSound"};
      class StandardSound {
          begin1[] = {"A3\Sounds_F\weapons\Rockets\titan_1", 2.51189, 1, 1100};
          soundBegin[] = {"begin1", 1};
          weaponSoundEffect = "DefaultRifle";
      };
      initspeed = 10;
      magazineReloadTime = 0.1;
      reloadTime = 0.5;
      aiRateOfFire = 4;
      aiRateOfFireDistance = 500;
      minRange = 100;
      minRangeProbab = 0.04;
      midRange = 1000;
      midRangeProbab = 0.85;
      maxRange = 4000;
      maxRangeProbab = 0.55;
      maxLeadSpeed = 2500;
      magazines[] = {"Su_KH31_magazine"};
  };*/
};
