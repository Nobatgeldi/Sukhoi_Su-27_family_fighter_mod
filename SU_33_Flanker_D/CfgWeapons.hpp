class CfgWeapons
{

	class CannonCore;
	class MissileLauncher;
	class RocketPods;
	class H_PilotHelmetFighter_O;
	class Bomb_03_Plane_CAS_02_F;
	class Bomb_04_Plane_CAS_01_F;
	class FakeWeapon;
	class autocannon_35mm;

	class Su_GSh301: autocannon_35mm
	{
		displayName="Gsh-301 30mm";
		displayNameMagazine="Gsh-301 30mm";
		shortNameMagazine="Gsh-301 30mm";
		cursor="EmptyCursor";
		cursorAim="";
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
	class su_kab500l_Laucher: RocketPods
	{
		canLock=2;
		displayName="KAB-500L";
		displayNameMagazine="KAB-500L";
		shortNameMagazine="KAB-500L";
		magazines[]=
		{
			"Su_fab_500"
		};
		reloadTime=0.1;
		magazineReloadTime=0.5;
		aiRateOfFire=5;
		aiRateOfFireDistance=500;
		nameSound="";
		cursor="EmptyCursor";
		cursorAim="EmptyCursor";
		textureType="fullAuto";
		missileLockCone=180;
		weaponLockDelay=1;
	};
	class Su_kh29_Launcher: MissileLauncher
	{
		canLock=2;
		autoFire=0;
		displayName="Kh-29 Kedge";
		displayNameMagazine="Kh-29 Kedge";
		shortNameMagazine="Kh-29";
		type=WeaponHardMounted;
		autoAimEnabled=true;
		magazines[]=
		{
			"Su_kh29"
		};
		reloadTime=0.1;
		magazineReloadTime=0.1;
		aiRateOfFire=5;
		aiRateOfFireDistance=500;
		nameSound="MissileLauncher";
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			begin1[]=
			{
				"A3\Sounds_F\weapons\Rockets\missile_1",
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
			"A3\Sounds_F\weapons\Rockets\rocket_fly_1",
			1,
			1.1,
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
		cursor="EmptyCursor";
		cursorAim="EmptyCursor";
		weaponLockDelay=1;
		textureType="fullAuto";
		minRange=300;
		minRangeProbab=0.25;
		midRange=2500;
		midRangeProbab=0.89999998;
		maxRange=9000;
		maxRangeProbab=0.0099999998;
	};
	class Su_KH31_Launcher : Su_kh29_Launcher {
		scope = 2;
		displayName = "Kh-31U";
		minRange = 50;
		minRangeProbab = 0.6;
		midRange = 5000;
		midRangeProbab = 0.9;
		maxRange = 60000;
		maxRangeProbab = 0.1;
		reloadTime = 4;
		magazines[] = {"Su_KH31"};
		//GLT_isGPSguided = 1;
	};
	class Su_kab500K_Laucher: Bomb_04_Plane_CAS_01_F
	{
		displayName="KAB-500K";
		displayNameMagazine="KAB-500K";
		shortNameMagazine="KAB-500K";
	};
	class Su_fab_250_Laucher: Bomb_04_Plane_CAS_01_F
	{
		displayName="FAB-250 BOMB";
		displayNameMagazine="FAB-250";
		shortNameMagazine="FAB-250";
		optics = true;
		magazines[]=
		{
			"Su_fab_250"
		};
		ballisticsComputer = 8;
	};
	class Su_R73Launcher: MissileLauncher
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
	class Su_R27Launcher: Su_R73Launcher
	{
		displayName="R-27 Alamo";
		displayNameMagazine="R-27 Alamo";
		shortNameMagazine="R-27 Alamo";
		magazines[]=
		{
			"Su_R27R",
			"Su_R27EA"
		};
		reloadTime=0.30000001;
	};
	class Su_R77Launcher: Su_R73Launcher
	{
		displayName="R-77 Adder";
		displayNameMagazine="R-77 Adder";
		shortNameMagazine="R-77 Adder";
		magazines[]=
		{
			"Su_R77"
		};
		reloadTime=0.30000001;
	};
	class Su_S8Laucher: RocketPods
	{
		displayName="S8 80mm Rockets";
		magazines[]=
		{
			"Su_20Rnd1_S8T",
			"Su_20Rnd2_S8T",
			"Su_20Rnd3_S8T",
			"Su_20Rnd4_S8T"
		};
		cursor="Air_Dot";
		cursorSize=1;
	};
	class Su_fake_weapon: FakeWeapon
	{
		displayName="Safe mod";
		displayNameMagazine="Safe mod";
		shortNameMagazine="Safe mod";
		magazines[]=
		{
		};
	};
};
