
private ["_R73_count","_R27_count","_R73M_count","_R77_count","_KH29_count","_KH31_count","_FAB2_count","_loadout","_station_1","_station_2","_station_3","_station_4","_station_5","_station_6","_station_7","_station_8","_station_9","_station_10","_station_11","_station_12","_station_13","_station_14","_plane","_S8","_R_73","_R_73M1","_R_27","_R_77","_FAB_250","_FAB_500","_Safe_m","_S81_magazine","_R_73_magazine","_R_73M1_magazine","_R_27_magazine","_R_77_magazine","_FAB_250_magazine","_FAB_500_magazine","_KH29_magazine","_KH31_magazine","_Fake_magazin","_KH29","_KH31","_Laser_designator","_Laser_designator_magazine"];

  _plane = _this;
//WEAPON CLASSNAME DEFINITIONS
    _R73_count  = 6;
    _R27_count  = 4;
    _R73M_count = 2;
    _R77_count  = 2;
    _KH29_count = 4;
    _KH31_count = 2;
    _FAB2_count = 6;
  //_Fak_count  = 10;

//LIST OF ALL POSSIBLE WEAPONS USED WITH THIS PLANE

    _S8      =  "Su_S8Laucher";

    _R_73    =  "Su_R73Launcher";

    _R_73M1  =  "Su_R73M1Launcher";

    _R_27    =  "Su_R27Launcher";

    _R_77    =  "Su_R77Launcher";

    _FAB_250 =  "Su_fab_250_Laucher";

    _FAB_500 =  "su_kab500l_Laucher";

    _KH29    =  "Su_kh29_Launcher";

    _KH31    =  "Su_KH31_Launcher";

    _Safe_m  =  "Su_fake_weapon";

    _Laser_designator = "Laserdesignator_mounted";

//MAGAZINE CLASSNAME DEFINITIONS
//LIST OF ALL POSSIBLE MAGAZINES USED WITH THIS PLANE
    _S81_magazine     = "Su_20Rnd1_S8T";

    _R_73_magazine    = "Su_R73";

    _R_73M1_magazine  = "Su_R73M1";

    _R_27_magazine    = "Su_R27R";

    _R_77_magazine    = "Su_R77";

    _FAB_250_magazine = "Su_fab_250";

    _FAB_500_magazine = "Su_fab_500";

    _KH29_magazine    = "Su_kh29";

    _KH31_magazine    = "Su_KH31";

    _Fake_magazin     = "Su_fake_M";

    _Laser_designator_magazine = "Laserbatteries";

//ROMEVE ALL POSSIBLE DEFAULT WEAPONS
   //removeAllWeapons _plane;
    _plane removeWeapon _S8;
    _plane removeWeapon _R_73;
    _plane removeWeapon _R_73M1;
    _plane removeWeapon _R_27;
    _plane removeWeapon _R_77;
    _plane removeWeapon _KH29;
    _plane removeWeapon _KH31;
    _plane removeWeapon _FAB_250;
    _plane removeWeapon _Laser_designator;

//ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
    _plane removeMagazine _S81_magazine;
    _plane removeMagazine _R_73_magazine;
    _plane removeMagazine _R_27_magazine;
    _plane removeMagazine _R_77_magazine;
    _plane removeMagazine _KH31_magazine;
    _plane removeMagazine _Laser_designator_magazine;

//DEFINE NEW LOADOUT
    _station_1 = _R_73_magazine;
    _station_2 = _R_73_magazine;

    _station_3 = _R_27_magazine;
    _station_4 = _R_27_magazine;

    _station_5 = _KH29_magazine;
    _station_6 = _KH29_magazine;
    _station_7 = _KH29_magazine;
    _station_8 = _KH29_magazine;

    _station_9 = _FAB_250_magazine;
    _station_10 = _FAB_250_magazine;
    _station_11 = _FAB_250_magazine;
    _station_12 = _FAB_250_magazine;
    _station_13 = _FAB_250_magazine;
    _station_14 = _FAB_250_magazine;

//systemChat "Weapons Loading!";
  titleText ["Weapons are Loading", "PLAIN DOWN",0.5];
  sleep 0.5;
    _plane addMagazine _station_1;
    _plane addMagazine _station_2;
      sleep 0.1;
      systemChat "R-73M1 AA missiles are loaded";
    _plane addMagazine _station_3;
    _plane addMagazine _station_4;
      sleep 0.1;
      systemChat "R-77 AA missiles are loaded";
    _plane addMagazine _station_5;
    _plane addMagazine _station_6;
    _plane addMagazine _station_7;
    _plane addMagazine _station_8;
      sleep 0.1;
      systemChat "KH-29 AT missiles are loaded";
    _plane addMagazine _station_9;
    _plane addMagazine _station_10;
    _plane addMagazine _station_11;
    _plane addMagazine _station_12;
    _plane addMagazine _station_13;
    _plane addMagazine _station_14;
      sleep 0.1;
      systemChat "FAB-250 bombs are loaded";

      //ADD NEW WEAPONS FOR PRELOADED MAGAZINES
        _loadout = magazines _plane;
        if ((_R_73_magazine in _loadout)) then
        {
          _plane addWeapon _R_73;
        };
        if ((_R_27_magazine in _loadout)) then
        {
          _plane addWeapon _R_27;
        };
        if ((_S81_magazine in _loadout)) then
        {
          _plane addWeapon _S8;
        };
        if ((_KH29_magazine in _loadout)) then
        {
          _plane addWeapon _KH29;
        };

        /*if ((_KH31_magazine in _loadout)) then
        {
          _plane addWeapon _KH31;
        };*/

        if ((_FAB_250_magazine in _loadout)) then
        {
          _plane addWeapon _FAB_250;
        };
        if ((_FAB_500_magazine in _loadout)) then
        {
          _plane addWeapon _FAB_500;
        };
        if ((_Laser_designator_magazine in _loadout)) then
        {
          _plane addWeapon _Laser_designator;
        };
        sleep 0.5;
        systemChat "Weapons are Loaded";

//while {(alive _plane and (_plane distance (nearestObject [_plane, "O_Truck_03_ammo_F"]) < 25) and (damage (nearestObject [_plane, "O_Truck_03_ammo_F"]) < 1) and player == driver _plane)}
while {(alive _plane)}do
{
    //A to A load
    if (((_this animationPhase "AA_load") == 1)) then
    {
      //ROMEVE ALL POSSIBLE DEFAULT WEAPONS
          _plane removeWeapon _S8;
          _plane removeWeapon _R_73;
          _plane removeWeapon _R_73M1;
          _plane removeWeapon _R_27;
          _plane removeWeapon _R_77;
          _plane removeWeapon _KH29;
          _plane removeWeapon _KH31;
          _plane removeWeapon _FAB_250;
          _plane removeWeapon _Laser_designator;

      //ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
            for "_h" from 0 to 10 do
            {
              _plane removeMagazine _Fake_magazin;
            };
            systemChat "Fake weapons are unloaded";
            for "_h" from 0 to _R73_count do
            {
              if ((_R_73_magazine in _loadout)) then
              {
                _plane removeMagazine _R_73_magazine;
              };
            };
            systemChat "R-73 missiles are unloaded";
            for "_h" from 0 to _R27_count do
            {
              if ((_R_27_magazine in _loadout)) then
              {
                _plane removeMagazine _R_27_magazine;
              };
            };
            systemChat "R-27 missiles are unloaded";
            for "_h" from 0 to _R73M_count do
            {

                _plane removeMagazine _R_73M1_magazine;
            };
            systemChat "R-73M missiles are unloaded";
            for "_h" from 0 to _R77_count do
            {

                _plane removeMagazine _R_77_magazine;
            };
            systemChat "R-77 missiles are unloaded";
            for "_h" from 0 to _KH29_count do
            {
              if ((_KH29_magazine in _loadout)) then
              {
                _plane removeMagazine _KH29_magazine;
              };
            };
            systemChat "KH-29 missiles are unloaded";
            for "_h" from 0 to _KH31_count do
            {

                _plane removeMagazine _KH31_magazine;
            };
            systemChat "KH-31 missiles are unloaded";
            for "_h" from 0 to _FAB2_count do
            {
              if ((_FAB_250_magazine in _loadout)) then
              {
                _plane removeMagazine _FAB_250_magazine;
              };
            };
            systemChat "FAB-250 bobms are unloaded";
            for "_h" from 0 to 10 do
            {
              _plane removeMagazine _Fake_magazin;
            };
            systemChat "Fake weapons are unloaded";
        sleep 1.5;
        systemChat "Weapons are unloaded";
        sleep 2.0;
        titleText ["Weapons are Loading", "PLAIN DOWN",0.3];

        _plane addMagazine _R_73M1_magazine;
        _plane addMagazine _R_73M1_magazine;
          sleep 1.0;
          systemChat "R-73M1 AA missiles are loaded";
        _plane addMagazine _R_77_magazine;
          sleep 2.0;
        _plane addMagazine _R_77_magazine;
          systemChat "R-77 AA  missiles are loaded";
        _plane addMagazine _R_27_magazine;
        _plane addMagazine _R_27_magazine;
        _plane addMagazine _R_27_magazine;
        _plane addMagazine _R_27_magazine;
          sleep 1.0;
          systemChat "R-27R AA missiles are loaded";
        _plane addMagazine _R_73_magazine;
        _plane addMagazine _R_73_magazine;
        _plane addMagazine _R_73_magazine;
        _plane addMagazine _R_73_magazine;
        _plane addMagazine _R_73_magazine;
        _plane addMagazine _R_73_magazine;
        sleep 1.0;
        systemChat "R-73 AA missiles are loaded";

        _plane addWeapon _R_73M1;
        _plane addWeapon _R_77;
        _plane addWeapon _R_73;
        _plane addWeapon _R_27;
    };
    //A to G load(anti-ship)
    if (((_this animationPhase "AG_load") == 1)) then
    {
      //ROMEVE ALL POSSIBLE DEFAULT WEAPONS
          _plane removeWeapon _S8;
          _plane removeWeapon _R_73;
          _plane removeWeapon _R_27;
          _plane removeWeapon _R_77;
          _plane removeWeapon _KH29;
          _plane removeWeapon _KH31;
          _plane removeWeapon _FAB_250;
          _plane removeWeapon _Laser_designator;

      //ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
            for "_h" from 0 to 10 do
            {
              _plane removeMagazine _Fake_magazin;
            };
            systemChat "Fake weapons are unloaded";
            for "_h" from 0 to _R73_count do
            {
              if ((_R_73_magazine in _loadout)) then
              {
                _plane removeMagazine _R_73_magazine;
              };
            };
            systemChat "R-73 missiles are unloaded";
            for "_h" from 0 to _R27_count do
            {
              if ((_R_27_magazine in _loadout)) then
              {
                _plane removeMagazine _R_27_magazine;
              };
            };
            systemChat "R-27 missiles are unloaded";
            for "_h" from 0 to _R73M_count do
            {

                _plane removeMagazine _R_73M1_magazine;
            };
            systemChat "R-73M missiles are unloaded";
            for "_h" from 0 to _R77_count do
            {

                _plane removeMagazine _R_77_magazine;
            };
            systemChat "R-77 missiles are unloaded";
            for "_h" from 0 to _KH29_count do
            {

              if ((_KH29_magazine in _loadout)) then
              {
                _plane removeMagazine _KH29_magazine;
              };
            };
            systemChat "KH-29 missiles are unloaded";
            for "_h" from 0 to _KH31_count do
            {
              if ((_KH31_magazine in _loadout)) then
              {
                _plane removeMagazine _KH31_magazine;
              };
            };
            systemChat "KH-31 missiles are unloaded";
            for "_h" from 0 to _FAB2_count do
            {

              if ((_FAB_250_magazine in _loadout)) then
              {
                _plane removeMagazine _FAB_250_magazine;
              };
            };
            systemChat "FAB-250 bombs are unloaded";
        removeAllWeapons _plane;
        sleep 1.5;
        systemChat "Weapons are unloaded";

      _plane addMagazine _R_73M1_magazine;
      _plane addMagazine _R_73M1_magazine;
        sleep 1.0;
        systemChat "R-73M1 AA missiles are loaded";

      _plane addMagazine _KH31_magazine;
          sleep 2.0;
      _plane addMagazine _KH31_magazine;
          systemChat "R-77 AA  missiles are loaded";
      for "_h" from 0 to 10 do
       {
        _plane addMagazine _Fake_magazin;
       };
          systemChat "Fake weapons are loaded";

      //_plane addWeapon _Safe_m;
      _plane addWeapon _R_73M1;
      _plane addWeapon _KH31;
    };
    //unload all
    if (((_this animationPhase "AA_load") == 0.3)) then
    {

      //ROMEVE ALL POSSIBLE DEFAULT WEAPONS
          _plane removeWeapon _S8;
          _plane removeWeapon _R_73;
          _plane removeWeapon _R_73M1;
          _plane removeWeapon _R_27;
          _plane removeWeapon _R_77;
          _plane removeWeapon _KH29;
          _plane removeWeapon _KH31;
          _plane removeWeapon _FAB_250;
          _plane removeWeapon _Laser_designator;

      //ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
            for "_h" from 0 to _R73_count do
            {
              if ((_R_73_magazine in _loadout)) then
              {
                _plane removeMagazine _R_73_magazine;
              };
            };
            systemChat "R-73 missiles are unloaded";
            for "_h" from 0 to _R27_count do
            {
              if ((_R_27_magazine in _loadout)) then
              {
                _plane removeMagazine _R_27_magazine;
              };
            };
            systemChat "R-27 missiles are unloaded";
            for "_h" from 0 to _R73M_count do
            {

                _plane removeMagazine _R_73M1_magazine;
            };
            systemChat "R-73M missiles are unloaded";
            for "_h" from 0 to _R77_count do
            {

                _plane removeMagazine _R_77_magazine;
            };
            systemChat "R-77 missiles are unloaded";
            for "_h" from 0 to _KH29_count do
            {
              if ((_KH29_magazine in _loadout)) then
              {
                _plane removeMagazine _KH29_magazine;
              };
            };
            systemChat "KH-29 missiles are unloaded";
            for "_h" from 0 to _KH31_count do
            {

                _plane removeMagazine _KH31_magazine;
            };
            systemChat "KH-31 missiles are unloaded";
            for "_h" from 0 to _FAB2_count do
            {

              if ((_FAB_250_magazine in _loadout)) then
              {
                _plane removeMagazine _FAB_250_magazine;
              };
            };
            systemChat "FAB-250 bombs are unloaded";
            for "_h" from 0 to 10 do
            {
              _plane removeMagazine _Fake_magazin;
            };
            systemChat "Fake weapons are unloaded";
        removeAllWeapons _plane;
        sleep 1.5;
        systemChat "Weapons are unloaded";
    };
    _plane animate ["AA_load", 0];
    _plane animate ["AG_load", 0];
    sleep 0.5;
};
