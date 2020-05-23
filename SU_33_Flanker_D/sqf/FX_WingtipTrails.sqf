// -----------------------------
// Original FX scripts by Lethal
// Modified by Nobat
// -----------------------------
private ["_opacity","_leftwingemitter","_rightwingemitter","_emitters","_rate","_direction","_looptime","_VectorL","_VectorR"];

_VectorL = _this selectionPosition "red_Still_Flaps_L";
_VectorR = _this selectionPosition "red_Still_Flaps_R";


_opacity = 0;
_leftwingemitter = "#particlesource" createVehicle (_this selectionPosition "red_Still_Flaps_L");
_rightwingemitter = "#particlesource" createVehicle (_this selectionPosition "red_Still_Flaps_R");
_emitters = [_leftwingemitter,_rightwingemitter];

{
    _x setParticleRandom [0.5,[0.1,0.1,0.1],[0,0,0],0,0.1,[0.1,0.1,0.1,0.05],0,0]
} forEach _emitters;

{
    _x setDropInterval 0
} forEach _emitters;

_direction = vectorDir _this;
_looptime = 0.1;

while {(alive _this)} do
{
    _rate = round(((abs(((vectorDir _this select 0) - (_direction select 0))*1000)) + (abs(((vectorDir _this select 1) - (_direction select 1))*1000)) + (abs(((vectorDir _this select 2) - (_direction select 2))*1000)))/3);
    _direction = vectorDir _this;
    if ((_rate*((speed _this)/1000)) > (5*(10*_looptime))) then
    {
        if (_opacity < 1) then
           {
            _opacity = _opacity + 0.05*(10*_looptime);
           }
    }
    else
    {
        if (_opacity > 0) then
        {
            _opacity = _opacity - 0.2*(10*_looptime);
        }
    };
    _leftwingemitter setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0],"","Billboard",1,1.5,_VectorL,(velocity _this),1,1.275,1,0.1,[0.5,0.7],[[1,1,1,0.01*_opacity],[1,1,1,0.2*_opacity],[1,1,1,0]],[0],0.01,0.01,"","",_this];
    _rightwingemitter setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0],"","Billboard",1,1.5,_VectorR,(velocity _this),1,1.275,1,0.1,[0.5,0.7],[[1,1,1,0.01*_opacity],[1,1,1,0.2*_opacity],[1,1,1,0]],[0],0.01,0.01,"","",_this];

    {
        _x setPos (getPos _this)
    } forEach _emitters;

    if (_opacity > 0) then
    {
        {
            _x setDropInterval 0.001;
        } forEach _emitters
    }
    else
    {
        {
            _x setDropInterval 0
        } forEach _emitters
    };
    _i = 0;
    _looptime = time;
    waitUntil {_i = _i + 1; _i > 1};
    _looptime = time - _looptime;
};
deleteVehicle _leftwingemitter;
deleteVehicle _rightwingemitter;
