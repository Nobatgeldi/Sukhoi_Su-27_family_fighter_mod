// -----------------------------
// Original FX scripts by Lethal
// configured for su-33 by Nobat
// -----------------------------

///-------------------<>----------------///
///     Author: Gabby_NG                ///
///       Date: 02 July                 ///
///    Project: SU_33_Flanker_D         ///
///       File: Su_Afterburner.sqf      ///
/// Permission: GPL v3.0                ///
///-------------------<>----------------///


private ["_MaxIntensity","_maxspeed","_Boost","_Intensity","_looptime", "_plane"];

_plane = _this;
_MaxIntensity = 1.5;
_Boost = 1.2;
_Intensity = 0.6;
_maxspeed = getNumber (configFile >> "cfgVehicles" >> typeOf _plane >> "maxSpeed");
 sleep 0.5;


_looptime = 0.1;
while {(alive _plane)} do
{
    if ((isEngineOn _plane) and ((_plane animationPhase "ABcut") < 0.3)) then
    {
        if (_Intensity < _MaxIntensity) then
        {
            _Intensity = _Intensity + 0.1*(15*_looptime);
         };
        if ((speed _plane) < _maxspeed) then
        {
         _plane setVelocity [(velocity _plane select 0)+((vectorDir _plane) select 0)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _plane select 1)+((vectorDir _plane) select 1)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _plane select 2)+((vectorDir _plane) select 2)*((_Boost*_Intensity/2)*(15*_looptime))]
        };
        if (fuel _plane > 0) then {_plane setFuel ((fuel _plane)-((1/9000)*(3*_looptime)))};
    }
    else
    {
        if (_Intensity > 0) then
        {
         _Intensity = _Intensity - 0.2*(15*_looptime);
        };
    };

    sleep 0.05;
};
sleep 3;
