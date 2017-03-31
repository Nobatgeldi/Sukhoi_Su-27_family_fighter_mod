// -----------------------------
// Original FX scripts by Lethal
// Modified by Gnat
// configured for su-33 by Nobat
// -----------------------------
private ["_positions","_emitters","_direction","_opacity","_rate","_looptime"];


switch (typeOf _this) do
{
	case "A10":
	{
		_positions = [[-3,0.4,0.5],[-4,-1,0.5],[-1.5,-1.5,0.5],[3,0.4,0.5],[4,-1,0.5],[1.5,-1.5,0.5]];
	};
	case "AV8B":
	{
		_positions = [[-2,0.4,1.5],[-2.5,-1,0.5],[-1.5,-1.5,0.5],[2,0.4,0.5],[2.5,-1,0.5],[1.5,-1.5,0.5]];
	};
	case "AV8B2":
	{
		_positions = [[-2,0.4,1.5],[-2.5,-1,0],[-1.5,-1.5,0],[2,0.4,0],[2.5,-1,0],[1.5,-1.5,0]];
	};
	case default
	{
		_positions = [[-2,0.4,1],[-2.5,-1,1],[-1.5,-1.5,1],[2,0.4,1],[2.5,-1,1],[1.5,-1.5,1]];
	};
};

_emitters = [];
{_tmpemitter = "#particlesource" createVehicle position _this; _emitters = _emitters + [_tmpemitter]} foreach _positions;
{_x setParticleRandom [0.1,[0.1,0.1,0.1],[1,1,1],0,0.1,[0.1,0.1,0.1,0.1],0,0]} foreach _emitters;
{_x setDropInterval 0} foreach _emitters;
_direction = vectordir _this;
_opacity = 0;
_looptime = 0.1;
while {(alive _this) and (_this animationPhase "KillFx" == 0)} do
	{
		_rate = round(((abs(((vectordir _this select 0) - (_direction select 0))*1000)) + (abs(((vectordir _this select 1) - (_direction select 1))*1000)) + (abs(((vectordir _this select 2) - (_direction select 2))*1000)))/3);
		_direction = vectordir _this;
		if ((_rate*((speed _this)/1000)) > (8*(10*_looptime))) then {if (_opacity < 1) then {_opacity = _opacity + 0.1*(10*_looptime)}}
		else {if (_opacity > 0) then {_opacity = _opacity - 0.4*(10*_looptime)}};
		for "_i" from 0 to ((count _positions)-1) do {(_emitters select _i) setParticleParams [["\a3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 13, 0],"","Billboard",1,0.1,(_positions select _i),(velocity _this),1,1.275,1,0.01,[1,3,10],[[1,1,1,0],[1,1,1,0.02*_opacity],[1,1,1,0.005*_opacity],[1,1,1,0]],[0],0.001,5,"","",_this]};
		{_x setpos (getpos _this)} foreach _emitters;
		if (_opacity > 0) then {{_x setDropInterval 0.001} foreach _emitters} else {{_x setDropInterval 0} foreach _emitters};
		_i = 0;
		_looptime = time;
		waitUntil {_i = _i + 1; _i > 1};
		_looptime = time - _looptime;
	};
{deleteVehicle _x} foreach _emitters;
