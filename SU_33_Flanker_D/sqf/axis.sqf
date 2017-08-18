
///-------------------<>----------------///
///     Author: Gabby_NG                ///
///       Date: 15 July                 ///
///    Project: SU_33_Flanker_D         ///
///       File: axis.sqf                ///
/// Permission: GPL v3.0                ///
///-------------------<>----------------///

private ["_plane","_x_axis","_y_axis","_z_axis","_old_x_axis","_old_y_axis","_old_z_axis","_return"];

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
    _y_axis = round (getDir _plane);
    _z_axis = round (deg _z_axis);

        _old_x_axis = _x_axis;
        _old_y_axis = _y_axis;
        _old_z_axis = _z_axis;
        sleep 0.005;
        _x_axis = round (deg _x_axis);
        _y_axis = round (deg _y_axis);
        _z_axis = round (deg _z_axis);

    if(!(_old_y_axis == _y_axis))then
    {
        private _return ="Nobat_ext" callExtension "y";
    }
    if(!(_old_x_axis == _x_axis))then
    {
        private _return ="Nobat_ext" callExtension "x";
    }
    if(!(_old_z_axis == _z_axis))then
    {
        private _return ="Nobat_ext" callExtension "z";
    }
    else
    {
        private _return ="Nobat_ext" callExtension "2";
    };
    /*_axis =
    [
     _y_axis,
     _x_axis,
     _z_axis
    ];*/
    /*_axis =
    [
     _y_axis
    ];
    _string =_axis joinString ""; //  360/180/180
    private _versionEx ="Nobat_ext" callExtension _string;*/

    if (_versionEx == "") then
    {
        private _errorMsg = "Dll not installed";

        hintSilent _errorMsg;

    }
    else
    {
         hintSilent _versionEx;
    };

    sleep 0.01;
};

