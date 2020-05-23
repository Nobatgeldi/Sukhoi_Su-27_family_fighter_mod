#define WEAPONGROUP_CANNONS      1  // Cannons
#define WEAPONGROUP_MGUNS        2  // Machine Guns
#define WEAPONGROUP_ROCKETS      4  // Rockets
#define WEAPONGROUP_AAMISSILES   8  // Anti-Air Missiles
#define WEAPONGROUP_ATMISSILES  16  // Anti-Tank Missiles
#define WEAPONGROUP_MISSILES    32  // All / Other Missiles
#define WEAPONGROUP_BOMBS       64  // Bombs
#define WEAPONGROUP_SPECIAL    128  // Laser Designator + Misc

class CfgVehicles
{
  class All{};

  #include "header/Sukhoi_Pilot.hpp"

  class AllVehicles: All{};
  class Air: AllVehicles{};

  class Plane: Air
  {
		class NewTurret;
    class ViewPilot;
    class Sounds;
    class HitPoints;
  };
  class Su_Base_F: Plane
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
		class Components;
		class Eventhandlers;

    thrustCoef[] ={
      1.5, // At 0 % of maxSpeed, thrust energy will be 1.5
      1.5, // 12.5 %
      1.4, // 25 %
      1.4, // 37.5 %
      1.4, // 50 %
      1.3, // 62.5 %
      1.3, // 75 %
      1.2, // 87.5 %
      1.2, // 100 %
      1.0, // 112.5 %
      1.0, // 125 %
      0.7, // 137.5 %
      0.5 // 150 %
    };
    altFullForce = 12000;
    altNoForce = 13000;
    airBrakeFrictionCoef = 3.4;
    //Force that affects the horizontal (X in model space) component of its velocity vector. Low values together with strong rudder authority will lead to skidding.
    draconicForceXCoef = 9.4;
    //Force that affects the vertical (Y in model space) component of its velocity vector. Bigger values allow for faster and sharper elevator turns.
    draconicForceYCoef = 10;	
    //Force that affects the forward (Z in model space) component of its velocity vector. Float
    draconicForceZCoef = 0.1;
	};
  #include "header/Su33_Base_F.hpp"

  #include "header/Su33_Protatype_PT_2.hpp"

  #include "header/Su33_Chine.hpp"

  #include "header/Su33_Chine_PT.hpp"
};
