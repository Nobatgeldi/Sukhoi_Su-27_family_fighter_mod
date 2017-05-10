// -----------------------------
// Original FX scripts by Lethal
// Modified by Gnat
// configured for su-33 by Nobat
// -----------------------------
private ["_opacity","_leftwingemitter","_rightwingemitter","_emitters","_rate","_direction","_looptime","_VectorL","_VectorR"];

switch (typeOf _this) do
{
	case "A10":
	{
	_VectorL = [-8.7,-1,1.3];
	_VectorR = [8.7,-1,1.3];
	};
	case "AV8B":
	{
	_VectorL = [-4.8,-3.9,-0.4];
	_VectorR = [4.8,-3.9,-0.4];
	};
	case "AV8B2":
	{
	_VectorL = [-4.8,-3.9,-0.4];
	_VectorR = [4.8,-3.9,-0.4];
	};
	case default
	{
	_VectorL = [-7.1,-6.1,0.2];
	_VectorR = [7.1,-6.1,0.2];
	};
};

_opacity = 0;
_leftwingemitter = "#particlesource" createVehicle position _this;
_rightwingemitter = "#particlesource" createVehicle position _this;
_emitters = [_leftwingemitter,_rightwingemitter];
{_x setParticleRandom [0.5,[0.1,0.1,0.1],[0,0,0],0,0.1,[0.1,0.1,0.1,0.05],0,0]} forEach _emitters;
{_x setDropInterval 0} forEach _emitters;
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
		{_x setPos (getPos _this)} forEach _emitters;
		if (_opacity > 0) then {{_x setDropInterval 0.001} forEach _emitters} else {{_x setDropInterval 0} forEach _emitters};
		_i = 0;
		_looptime = time;
		waitUntil {_i = _i + 1; _i > 1};
		_looptime = time - _looptime;
	};
deleteVehicle _leftwingemitter;
deleteVehicle _rightwingemitter;
