// ---------------------
// Original FX scripts by Lethal
// Modified by Gnat
// ---------------------
private ["_emitter","_nowspeed", "_lastspeed"];

_emitter = "#particlesource" createVehicle position _this;
_emitter setParticleRandom [0.05,[2,2,2],[5,5,5],0,0.5,[0.1,0.1,0.1,0.5],0,0];
_emitter setDropInterval 0;

while {(alive _this) and (_this animationPhase "KillFx" == 0)} do
{
	_nowspeed = speed _this;
	if ((_nowspeed > 850) and (_nowspeed < 880)) then /*and (_lastspeed < _nowspeed)*/
	{
		_emitter setDropInterval 0.0005;
		for "_i" from 1 to 100 do
		  {
			_emitter setParticleRandom [0.4,[10*(_i/100),10*(_i/100),10*(_i/100)],[10*(_i/100),10*(_i/100),10*(_i/100)],0,0.3,[0.1,0.15,0.3,0.5],0,0];
			_emitter setParticleParams ["\a3\data\cl_basic","","Billboard",1,0.1,[0,(-12*(_i/100)+8),-0.5],(velocity _this),1,1.2745,1,0.001,[20*(_i/100)],[[1,1,1,0],[1,1,1,0.1*(_i/100)],[1,1,1,0]],[0],0,0,"","",_this];
			 sleep 0.005;
		   };
		_emitter setDropInterval 0;
		sleep ((random 5)+ 5);
	 }
	else
	{
		_emitter setDropInterval 0
	};
	_emitter setParticleParams ["\wop_gui\ROCKETSMOKE\RocketSmoke","","Billboard",1,0.05,[0,-0.5,1.0],(velocity _this),1,1.2745,1,0.001,[10,20],[[1,1,1,0],[1,1,1,0.1],[1,1,1,0]],[0],0,0,"","",_this];
	_emitter setpos (getpos _this);
	_lastspeed = speed _this;
	sleep 0.356759;
};
deleteVehicle _emitter;
