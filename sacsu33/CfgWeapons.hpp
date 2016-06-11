class CfgWeapons
{
	class CannonCore;
	class SACGSh301: CannonCore
	{
        scope=2;
		displayName="Gsh-301 30mm";
		displayNameMagazine="Gsh-301 30mm";
		shortNameMagazine="Gsh-301 30mm";
		nameSound="cannon";
		cursor="EmptyCursor";
		cursorAim="mg";
		showAimCursorInternal = true;
		magazines[]=
		{
			"SAC_150Rnd_30mm_GSh301"
		};
		canLock=2;
		ballisticsComputer=2;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		class GunParticles
		{
			class Effect
			{
				effectName="MachineGun1";
				positionName="nosegun";
				directionName="nosegun_dir";
			};
		};
		class manual: CannonCore
		{
			displayName="Gsh-301 30mm";
			autoFire=1;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F\weapons\30mm\30mm_st_02",
					1.99526,
					1,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				weaponSoundEffect="DefaultRifle";
			};
			reloadTime=0.1;
			dispersion=0.0024999999;
			soundContinuous=0;
			showToPlayer=1;
			burst=1;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=1;
			minRangeProbab=0.0099999998;
			midRange=2;
			midRangeProbab=0.0099999998;
			maxRange=3;
			maxRangeProbab=0.0099999998;
			textureType="fullAuto";
		};
		class close: manual
		{
			showToPlayer=0;
			burst=15;
			aiRateOfFire=0.25;
			aiRateOfFireDistance=400;
			minRange=0;
			minRangeProbab=0.050000001;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			burst=10;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=500;
			minRange=300;
			minRangeProbab=0.2;
			midRange=400;
			midRangeProbab=0.69999999;
			maxRange=500;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			burst=7;
			aiRateOfFire=1;
			aiRateOfFireDistance=900;
			minRange=400;
			minRangeProbab=0.2;
			midRange=700;
			midRangeProbab=0.69999999;
			maxRange=900;
			maxRangeProbab=0.2;
		};
		class far: close
		{
			burst=4;
			aiRateOfFire=1.5;
			aiRateOfFireDistance=1500;
			minRange=800;
			minRangeProbab=0.2;
			midRange=1000;
			midRangeProbab=0.40000001;
			maxRange=1500;
			maxRangeProbab=0.0099999998;
		};
	};
	class MissileBase;
	class MissileLauncher;
	class CMFlareLauncher
	{	
	};	
	class SACR73Launcher: MissileLauncher
	{
		canLock=2;
		autoFire=0;
		displayName="R-73 Archer";
		displayNameMagazine="R-73 Archer";
		shortNameMagazine="R-73";
		cursorAim="EmptyCursor";
		cursor="EmptyCursor";
		minRange=300;
		minRangeProbab=0.025;
		midRange=2500;
		midRangeProbab=0.090000004;
		maxRange=9000;
		maxRangeProbab=0.0099999998;
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
			"SAC_6Rnd_R73",
			"SAC_4Rnd_R73"
		};
		holdsterAnimValue=3;
		weaponLockDelay=3;
		textureType="semi";
	};
	class SACR27Launcher: SACR73Launcher
	{
		displayName="R-27RE";
		magazines[]=
		{
			"SAC_6Rnd_R27RE",
			"SAC_4Rnd_R27RE"
		};
		reloadTime=0.30000001;
	};
	class SACR77Launcher: SACR73Launcher
	{
		displayName="R-77";
		magazines[]=
		{
			"SAC_6Rnd_R77",
			"SAC_4Rnd_R77"
		};
		reloadTime=0.30000001;
	};
};