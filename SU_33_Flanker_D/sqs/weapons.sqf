
  private ["_plane"];

  _plane = _this;

//WEAPON CLASSNAME DEFINITIONS
//LIST OF ALL POSSIBLE WEAPONS USED WITH THIS PLANE
//_GSH301 = "Su_GSh301";
  _S8 = "Su_S8Laucher";
    _R_73 = "Su_R73Launcher";
    _R_27 = "Su_R27Launcher";
    _FAB_250 = "Su_fab_250_Laucher";
    _FAB_500 = "su_kab500l_Laucher";
    _Laser_designator = "Laserdesignator_mounted";
    _KH29 = "Su_kh29_Launcher";
//MAGAZINE CLASSNAME DEFINITIONS
//LIST OF ALL POSSIBLE MAGAZINES USED WITH THIS PLANE

  _S81_magazine = "Su_20Rnd1_S8T";
    _R_73_magazine = "Su_R73M1_AA";
    _R_27_magazine = "Su_R27R";
    _FAB_250_magazine = "Su_fab_250";
    _FAB_500_magazine = "Su_fab_500";
    _KH29_magazine = "Su_kh29";
    _Laser_designator_magazine = "Laserbatteries";

//ROMEVE ALL POSSIBLE DEFAULT WEAPONS
  _plane removeWeapon _S8;
    _plane removeWeapon _R_73;
    _plane removeWeapon _R_27;
    _plane removeWeapon _FAB_250;
    _plane removeWeapon _Laser_designator;

//ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
  _plane removeMagazine _S81_magazine;
    _plane removeMagazine _R_73_magazine;
    _plane removeMagazine _R_27_magazine;
    _plane removeMagazine _FAB_250_magazine;
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

    _station_15 = _FAB_500_magazine;
    _station_16 = _FAB_500_magazine;
//systemChat "Weapons Loading!";
  titleText ["Weapons are Loading", "PLAIN DOWN",0.3];
  sleep 5.0;
    _plane addMagazine _station_1;
    _plane addMagazine _station_2;
      sleep 1.0;
      systemChat "R-73M1 AA missiles are loaded";
    _plane addMagazine _station_3;
    _plane addMagazine _station_4;
      sleep 1.0;
      systemChat "R-27R AA missiles are loaded";
    _plane addMagazine _station_5;
    _plane addMagazine _station_6;
    _plane addMagazine _station_7;
    _plane addMagazine _station_8;
      sleep 1.0;
      systemChat "KH-29 AT missiles are loaded";
    _plane addMagazine _station_9;
    _plane addMagazine _station_10;
    _plane addMagazine _station_11;
    _plane addMagazine _station_12;
    _plane addMagazine _station_13;
    _plane addMagazine _station_14;
      sleep 1.0;
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
        sleep 1.5;
        systemChat "Weapons are Loaded";
while {(alive _plane)} do {
    if (((_this animationPhase "AA_load") == 1)) then
    {
      //ROMEVE ALL POSSIBLE DEFAULT WEAPONS
        _plane removeWeapon _S8;
          _plane removeWeapon _R_73;
          _plane removeWeapon _KH29;
          _plane removeWeapon _R_27;
          _plane removeWeapon _FAB_250;
          _plane removeWeapon _Laser_designator;

        //ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
        _R73_count = 10;
        _R27_count = 10;
        _KH29_count = 4;
        _FAB2_count = 6;
      for "_h" from 0 to _R73_count do
      {
        if ((_R_73_magazine in _loadout)) then
        {
          _plane removeMagazine _R_73_magazine;
        };
      };
      for "_h" from 0 to _R27_count do
      {
        if ((_R_27_magazine in _loadout)) then
        {
          _plane removeMagazine _R_27_magazine;
        };
      };
      for "_h" from 0 to _KH29_count do
      {
        if ((_KH29_magazine in _loadout)) then
        {
          _plane removeMagazine _KH29_magazine;
        };
      };
      for "_h" from 0 to _FAB2_count do
      {
        if ((_FAB_250_magazine in _loadout)) then
        {
          _plane removeMagazine _FAB_250_magazine;
        };
      };
        sleep 1.5;
        systemChat "Weapons are unloaded";
        sleep 2.0;
        titleText ["Weapons are Loading", "PLAIN DOWN",0.3];

        _plane addMagazine _R_73_magazine;
        _plane addMagazine _R_73_magazine;
          sleep 1.0;
          systemChat "R-73M1 AA missiles are loaded";
        _plane addMagazine _R_27_magazine;
        _plane addMagazine _R_27_magazine;
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
        systemChat "R-73M1 AA missiles are loaded";
        //ADD NEW WEAPONS FOR PRELOADED MAGAZINES
        if ((_R_73_magazine in _loadout)) then
        {
          _plane addWeapon _R_73;
        };
        if ((_R_27_magazine in _loadout)) then
        {
          _plane addWeapon _R_27;
        };
    };
    if (((_this animationPhase "AA_load") == 0.3)) then
    {
      //ROMEVE ALL POSSIBLE DEFAULT WEAPONS
        _plane removeWeapon _R_73;
        _plane removeWeapon _R_27;

      //ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
      _R73_count = 15;
      _R27_count = 10;
      for "_h" from 0 to _R73_count do
      {
        if ((_R_73_magazine in _loadout)) then
        {
          _plane removeMagazine _R_73_magazine;

        };
      };
      sleep 1.5;
      systemChat "R-73 missiles are unloaded";
      for "_h" from 0 to _R27_count do
      {
        if ((_R_27_magazine in _loadout)) then
        {
          _plane removeMagazine _R_27_magazine;
        };
      };
      sleep 1.5;
      systemChat "R-27 missiles are unloaded";
    };
    _plane animate ["AA_load", 0];
    sleep 0.5;
};
