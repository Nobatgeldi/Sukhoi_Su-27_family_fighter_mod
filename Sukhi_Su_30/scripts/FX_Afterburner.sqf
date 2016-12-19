
private ["_MaxIntensity","_Boost","_leftengine","_rightengine","_emitters","_Intensity","_looptime", "_plane","_illuminateL","_illuminateR","_veldir","_veldirx","_veldiry","_veldirz","_daylight","_cl0","_cl1","_cl2","_cl3","_risetime","_downtime","_day","_eftime","_ef"];

_MaxIntensity = 2;
_Boost = 1.5;
_Intensity = 0;
_veldir = 1;
_veldirx = 0;
_veldiry = 0;
_veldirz = 0;
_daylight = 0;
_cl0 = [0,0,0,0];
_cl1 = [0,0,0,0];
_cl2 = [0,0,0,0];
_cl3 = [0,0,0,0];
_eftime = [0,0,0,0];
_risetime = [7.08,7.56,7.66,7.16,6.44,5.50,4.75,4.5,4.69,5.16,5.84,6.50,7.08,7.56];
_downtime = [16.50,16.25,16.50,17.08,17.46,18.08,18.80,19.42,19.42,19.00,18.16,17.16,16.50,16.25];
_day = date;
//_plane = _this select 0
//_plane setobjecttexture[04, "\SU_33_Flanker_D\paa\engine_high.paa"]
//_plane setobjecttexture[05, "\SU_33_Flanker_D\paa\engine_high.paa"]
//[year, month, day, hour, minute]

_ef = [_risetime select (_day select 1),_risetime select (1+(_day select 1)),_downtime select (_day select 1),_downtime select (1+(_day select 1))];

_eftime = [((_ef select 0) + (((_ef select 1) - (_ef select 0))/ 31) * (_day select 2)) - 1,
(0.8 + (_ef select 0) + (((_ef select 1) - (_ef select 0))/ 31) * (_day select 2)),
((_ef select 2) + (((_ef select 3) - (_ef select 2))/ 31) * (_day select 2)) - 0.8,
(1 + (_ef select 2) + (((_ef select 3) - (_ef select 2))/ 31) * (_day select 2))];


_maxspeed = 2100;
_sizespeed = 800;
_plane = _this;

_leftengine = "#particlesource" createVehicle position _this;
_rightengine = "#particlesource" createVehicle position _this;

	   /* illuminate */
		//_illuminate = "#lightpoint" createVehicleLocal [0,0,0]; //local effect only
		_illuminateL = "#lightpoint" createVehicle (_this modelToWorld[-1.2,-8.8,-0.5]); //global effect only
		_illuminateR = "#lightpoint" createVehicle (_this modelToWorld[1.2,-8.8,-0.5]); //global effect only
		_illuminateL lightAttachObject [_this, [-1.14,-10.0,-0.5]];
		_illuminateR lightAttachObject [_this, [1.14,-10.0,-0.5]];
		_illuminateL setLightColor [0.2+_Intensity,0,0];
		_illuminateR setLightColor [0.2+_Intensity,0,0];
		_illuminateL setLightAmbient [0.1+_Intensity,0,0];
		_illuminateR setLightAmbient [0.1+_Intensity,0,0];


_emitters = [_leftengine,_rightengine];
{_x setParticleRandom [0.00,[0.05,0.05,0.05],[0.05,0.05,0.05],0,0.8,[0.1,0.1,0.1,0],0,0]} foreach _emitters;
{_x setDropInterval 0} foreach _emitters;
_looptime = 0.1;

//roop
while {(alive _plane)} do {

//get daytime
_daylight = 0;

//night
if ((dayTime < (_eftime select 0)) || (dayTime > (_eftime select 3)))
	then
		{
			_daylight = 1;
		}
	else
	{
//rise
		if ((dayTime >= (_eftime select 0)) && (dayTime <= (_eftime select 1)))
			then
			{
				_daylight = abs(((_eftime select 1) - daytime)/((_eftime select 1) - (_eftime select 0)));
			}
			else
			{
//down
				if ((dayTime >= (_eftime select 2)) && (dayTime <= (_eftime select 3)))
				then
				{
					_daylight = abs((daytime - (_eftime select 2))/((_eftime select 3) - (_eftime select 2)));
				};
			};
	};



if ((isengineon _this) and ((_this animationPhase "ABcut") < 0.3)) then
{
    if (_Intensity < _MaxIntensity) then
     {
     	_Intensity = _Intensity + 0.1*(10*_looptime);

		if (_daylight > 0) then
		{
		_illuminateL setLightColor [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
		_illuminateR setLightColor [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
		_illuminateL setLightAmbient [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
		_illuminateR setLightAmbient [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
        _illuminateL setLightBrightness ( _Intensity/90);
        _illuminateR setLightBrightness ( _Intensity/90);
        //_daylight = 1;
        };
      };
     if ((speed _this) < _maxspeed) then
      {_this setVelocity [(velocity _this select 0)+((vectordir _this) select 0)*((_Boost*_Intensity/2)*(10*_looptime)),(velocity _this select 1)+((vectordir _this) select 1)*((_Boost*_Intensity/2)*(10*_looptime)),(velocity _this select 2)+((vectordir _this) select 2)*((_Boost*_Intensity/2)*(10*_looptime))]};
     if (fuel _this > 0) then {_this setFuel ((fuel _this)-((1/3000)*(3*_looptime)))};
}
else {
	if (_Intensity > 0) then
		{
			_Intensity = _Intensity - 0.2*(10*_looptime);
			_illuminateL setLightColor [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateR setLightColor [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateL setLightAmbient [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateR setLightAmbient [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateL setLightBrightness ( _Intensity/90);
			_illuminateR setLightBrightness ( _Intensity/90);
		};
			_illuminateL setLightColor [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateR setLightColor [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateL setLightAmbient [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
			_illuminateR setLightAmbient [(0.090 - _daylight*0.050),(0.050 + _daylight*0.015),(0.030 + _daylight*0.050)];
		_illuminateL setLightBrightness ( _Intensity/100);
		_illuminateR setLightBrightness ( _Intensity/100);
};

//set burner color
_cl0 = [(0.90 - _daylight*0.50),(0.50 + _daylight*0.15),(0.30 + _daylight*0.50),(1 -(ceil _daylight)*2)*0.01*_Intensity];
_cl1 = [(0.90 - _daylight*0.50),(0.50 + _daylight*0.15),(0.30 + _daylight*0.50),(1 -(ceil _daylight)*2)*0.005*_Intensity];
_cl2 = [(0.90 - _daylight*0.50),(0.50 + _daylight*0.15),(0.30 + _daylight*0.50),(1 -(ceil _daylight)*2)*0.002*_Intensity];
_cl3 = [0,0,0,0];
//get vector
_veldir = sqrt(((vectordir _this) select 0)^2 + ((vectordir _this) select 1)^2 + ((vectordir _this) select 2)^2);
_veldirx = ((vectordir _this) select 0) / _veldir;
_veldiry = ((vectordir _this) select 1) / _veldir;
_veldirz = ((vectordir _this) select 2) / _veldir;

//drop burner
	_leftengine setParticleParams ["\SU_33_Flanker_D\cl_exp2","","Billboard",1,(0.06 - (0.05*((speed _this) / (_maxspeed /2) ))),(_this selectionposition "burner_l"),[(velocity _this select 0) - _veldirx *30,(velocity _this select 1) - _veldiry *30,(velocity _this select 2) - _veldirz *30],1,1.2745,1,0,[0.7,0.1],[_cl0,_cl1,_cl2,_cl3],[0],0,0,"","",_this];
	_rightengine setParticleParams ["\SU_33_Flanker_D\cl_exp2","","Billboard",1,(0.06 - (0.05*((speed _this) / (_maxspeed /2) ))),(_this selectionposition "burner_r"),[(velocity _this select 0) - _veldirx *30,(velocity _this select 1) - _veldiry *30,(velocity _this select 2) - _veldirz *30],1,1.2745,1,0,[0.7,0.1],[_cl0,_cl1,_cl2,_cl3],[0],0,0,"","",_this];

{_x setpos (getpos _this)} foreach _emitters;
if (_Intensity > 0) then {{_x setDropInterval 0.001} foreach _emitters} else {{_x setDropInterval 0} foreach _emitters};

_looptime = time;

sleep 0.05; // mod by Crowe
//hintSilent format["day : %1 \nclR : %2 \nclG : %3\nclB : %4\ndayl : %5",_daylight,_cl0 select 0,_cl0 select 1,_cl0 select 2,_daylight];

_looptime = time - _looptime;
};
/*_plane setobjecttexture[04, "\SU_33_Flanker_D\paa\engine_low.paa"]
_plane setobjecttexture[05, "\SU_33_Flanker_D\paa\engine_low.paa"]*/
deleteVehicle _leftengine;
deleteVehicle _rightengine;
deleteVehicle _illuminateL;
deleteVehicle _illuminateR;
