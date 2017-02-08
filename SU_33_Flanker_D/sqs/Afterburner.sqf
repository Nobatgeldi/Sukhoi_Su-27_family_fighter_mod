private ["_MaxIntensity","_Boost","_leftengine","_rightengine","_emitters","_Intensity","_looptime", "_plane"];

_MaxIntensity = 0.15;
_Boost = 0.030;
_Intensity = 0.12;
//_this setvariable ["afterburner",false];

_maxspeed = 2100;
_plane = _this;
_Su33 = _this select 0;
//_plane animate ["ABcut",1];
sleep 0.5;

_looptime = 0.1;
_runtime = 200;
while {(alive _plane) and (_plane animationphase "ABcut" < 0.3)} do
{
  if (isengineon _plane) then
  {
    if (_Intensity < _MaxIntensity) then {_Intensity = _Intensity + 0.1*(15*_looptime)};
    if ((speed _this) < _maxspeed) then {_this setVelocity [(velocity _this select 0)+((vectordir _this) select 0)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _this select 1)+((vectordir _this) select 1)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _this select 2)+((vectordir _this) select 2)*((_Boost*_Intensity/2)*(10*_looptime))]};
    if (fuel _this > 0) then {_this setFuel ((fuel _this)-((0.002/5000)*(3*_looptime)))};
  }
  else
  {
    if (_Intensity > 0) then {_Intensity = _Intensity - 0.2*(15*_looptime)}
  };
  _looptime = time;

  sleep 0.05; // mod by Crowe

  _runtime = _runtime - 1;
};
sleep 3;
