
///-------------------<>----------------///
///     Author: Gabby_NG                ///
///       Date: 15 July                 ///
///    Project: SU_33_Flanker_D         ///
///       File: axis.sqf                ///
/// Permission: GPL v3.0                ///
///-------------------<>----------------///

private ["_plane","_x_axis","_y_axis","_z_axis","_string","_axis","_reverse"];

_plane = _this;
//_names = animationNames _plane;
while {(alive _plane)} do
{
    //_y_axis = _plane animationSourcePhase "horizonDive";
   // get radian numbers for x and z axis
    _x_axis = _plane animationPhase  "horizonDive";
    _z_axis = _plane animationPhase  "horizonBank";

    //Convert a number from Radians to Degrees.
    _x_axis = round (deg _x_axis);
    _z_axis = round (deg _z_axis);
    _y_axis = round (getDir _plane);

    _axis =
    [
     _y_axis,
     _x_axis,
     _z_axis
    ];
    _string =_axis joinString "/--/";
    private _versionEx ="Nobat_ext" callExtension _string;
    private _reverse ="ARMAExtCS" callExtension _string;

    if (_reverse == "") then
    {
        private _errorMsg = "Dll not installed";

        hintSilent _errorMsg;

    }
    else
    {
         hintSilent _reverse;
    };

    sleep 0.01;
};

