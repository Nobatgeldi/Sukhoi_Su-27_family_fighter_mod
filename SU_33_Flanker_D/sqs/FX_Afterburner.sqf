
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


if ((isengineon _this) and ((_this animationPhase "wing") < 0.1) and ((_this animationPhase "ABcut") < 0.3)) then
{
	/*_plane animate ["thrust1A",0.6];
	_plane animate ["thrust2",0.6];
	_plane animate ["thrust3",0.6];
	_plane animate ["thrust4",0.6];
	_plane animate ["thrust5",0.6];
	_plane animate ["thrust6",0.6];
	_plane animate ["thrust7",0.6];
	_plane animate ["thrust8",0.6];
	_plane animate ["thrust9",0.6];
	_plane animate ["thrust10",0.6];
	_plane animate ["thrust11",0.6];
	_plane animate ["thrust12",0.6];
	_plane animate ["thrust13",0.6];
	_plane animate ["thrust14",0.6];
	_plane animate ["thrust15",0.6];
	_plane animate ["thrust16",0.6];
	_plane animate ["thrust17",0.6];
	_plane animate ["thrust18",0.6];
	_plane animate ["thrust19",0.6];
	_plane animate ["thrust20",0.6];
	_plane animate ["thrust21",0.6];
	_plane animate ["thrust22",0.6];
	_plane animate ["thrust23",0.6];
	_plane animate ["thrust24",0.6];
	_plane animate ["thrust25",0.6];
	_plane animate ["thrust26",0.6];
	_plane animate ["thrust27",0.6];
	_plane animate ["thrust28",0.6];
	_plane animate ["thrust29",0.6];
	_plane animate ["thrust20",0.6];
	_plane animate ["thrust31",0.6];
	_plane animate ["thrust32",0.6];*/

	_plane animate ["AfterburnerLV2",1];
	_plane animate ["AfterburnerRV2",1];
	_plane animate ["AfterburnerL2",1];
	_plane animate ["AfterburnerR2",1];
	//engine left
	_plane animate ["thrust1A",0.1];
	_plane animate ["thrust2",0.1];
	_plane animate ["thrust3",0.1];
	_plane animate ["thrust4",0.1];
	_plane animate ["thrust5",0.1];
	_plane animate ["thrust6",0.1];
	_plane animate ["thrust7",0.1];
	_plane animate ["thrust8",0.1];
	_plane animate ["thrust9",0.1];
	_plane animate ["thrust10",0.1];
	_plane animate ["thrust11",0.1];
	_plane animate ["thrust12",0.1];
	_plane animate ["thrust13",0.1];
	_plane animate ["thrust14",0.1];
	_plane animate ["thrust15",0.1];
	_plane animate ["thrust16",0.1];
	_plane animate ["thrust17",0.1];
	_plane animate ["thrust18",0.1];
	_plane animate ["thrust19",0.1];
	_plane animate ["thrust20",0.1];
	_plane animate ["thrust21",0.1];
	_plane animate ["thrust22",0.1];
	_plane animate ["thrust23",0.1];
	_plane animate ["thrust24",0.1];
	_plane animate ["thrust25",0.1];
	_plane animate ["thrust26",0.1];
	_plane animate ["thrust27",0.1];
	_plane animate ["thrust28",0.1];
	_plane animate ["thrust29",0.1];
	_plane animate ["thrust30",0.1];
	_plane animate ["thrust31",0.1];
	_plane animate ["thrust32",0.1];
	//right Engine
	_plane animate ["thrust1b",0.1];
	_plane animate ["thrust2b",0.1];
	_plane animate ["thrust3b",0.1];
	_plane animate ["thrust4b",0.1];
	_plane animate ["thrust5b",0.1];
	_plane animate ["thrust6b",0.1];
	_plane animate ["thrust7b",0.1];
	_plane animate ["thrust8b",0.1];
	_plane animate ["thrust9b",0.1];
	_plane animate ["thrust10b",0.1];
	_plane animate ["thrust11b",0.1];
	_plane animate ["thrust12b",0.1];
	_plane animate ["thrust13b",0.1];
	_plane animate ["thrust14b",0.1];
	_plane animate ["thrust15b",0.1];
	_plane animate ["thrust16b",0.1];
	_plane animate ["thrust17b",0.1];
	_plane animate ["thrust18b",0.1];
	_plane animate ["thrust19b",0.1];
	_plane animate ["thrust20b",0.1];
	_plane animate ["thrust21b",0.1];
	_plane animate ["thrust22b",0.1];
	_plane animate ["thrust23b",0.1];
	_plane animate ["thrust24b",0.1];
	_plane animate ["thrust25b",0.1];
	_plane animate ["thrust26b",0.1];
	_plane animate ["thrust27b",0.1];
	_plane animate ["thrust28b",0.1];
	_plane animate ["thrust29b",0.1];
	_plane animate ["thrust30b",0.1];
	_plane animate ["thrust31b",0.1];
	_plane animate ["thrust32b",0.1];


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
      {
				_this setVelocity [(velocity _this select 0)+((vectordir _this) select 0)*((_Boost*_Intensity/2)*(10*_looptime)),(velocity _this select 1)+((vectordir _this) select 1)*((_Boost*_Intensity/2)*(10*_looptime)),(velocity _this select 2)+((vectordir _this) select 2)*((_Boost*_Intensity/2)*(10*_looptime))]
			};
     if (fuel _this > 0) then
		 {
			 _this setFuel ((fuel _this)-((1/3000)*(3*_looptime)))
		 };
}
/*if (((_this animationPhase "ABcut") > 0.3)) then
{

	_plane animate ["thrust1",0.6];
	_plane animate ["thrust2",0.6];
	_plane animate ["thrust3",0.6];
	_plane animate ["thrust4",0.6];
	_plane animate ["thrust5",0.6];
	_plane animate ["thrust6",0.6];
	_plane animate ["thrust7",0.6];
	_plane animate ["thrust8",0.6];
	_plane animate ["thrust9",0.6];
	_plane animate ["thrust10",0.6];
	_plane animate ["thrust11",0.6];
	_plane animate ["thrust12",0.6];
	_plane animate ["thrust13",0.6];
	_plane animate ["thrust14",0.6];
	_plane animate ["thrust15",0.6];
	_plane animate ["thrust16",0.6];
	_plane animate ["thrust17",0.6];
	_plane animate ["thrust18",0.6];
	_plane animate ["thrust19",0.6];
	_plane animate ["thrust20",0.6];
	_plane animate ["thrust21",0.6];
	_plane animate ["thrust22",0.6];
	_plane animate ["thrust23",0.6];
	_plane animate ["thrust24",0.6];
	_plane animate ["thrust25",0.6];
	_plane animate ["thrust26",0.6];
	_plane animate ["thrust27",0.6];
	_plane animate ["thrust28",0.6];
	_plane animate ["thrust29",0.6];
	_plane animate ["thrust20",0.6];
	_plane animate ["thrust31",0.6];
	_plane animate ["thrust32",0.6];
};*/
else {
	    _plane animate ["AfterburnerLV2",0];
			_plane animate ["AfterburnerRV2",0];
			_plane animate ["AfterburnerL2",0];
			_plane animate ["AfterburnerR2",0];
			//engine left
			_plane animate ["thrust1A",0.5];
			_plane animate ["thrust2",0.5];
			_plane animate ["thrust3",0.5];
			_plane animate ["thrust4",0.5];
			_plane animate ["thrust5",0.5];
			_plane animate ["thrust6",0.5];
			_plane animate ["thrust7",0.5];
			_plane animate ["thrust8",0.5];
			_plane animate ["thrust9",0.5];
			_plane animate ["thrust10",0.5];
			_plane animate ["thrust11",0.5];
			_plane animate ["thrust12",0.5];
			_plane animate ["thrust13",0.5];
			_plane animate ["thrust14",0.5];
			_plane animate ["thrust15",0.5];
			_plane animate ["thrust16",0.5];
			_plane animate ["thrust17",0.5];
			_plane animate ["thrust18",0.5];
			_plane animate ["thrust19",0.5];
			_plane animate ["thrust20",0.5];
			_plane animate ["thrust21",0.5];
			_plane animate ["thrust22",0.5];
			_plane animate ["thrust23",0.5];
			_plane animate ["thrust24",0.5];
			_plane animate ["thrust25",0.5];
			_plane animate ["thrust26",0.5];
			_plane animate ["thrust27",0.5];
			_plane animate ["thrust28",0.5];
			_plane animate ["thrust29",0.5];
			_plane animate ["thrust30",0.5];
			_plane animate ["thrust31",0.5];
			_plane animate ["thrust32",0.5];
			//engine right
			_plane animate ["thrust1b",0.6];
			_plane animate ["thrust2b",0.6];
			_plane animate ["thrust3b",0.6];
			_plane animate ["thrust4b",0.6];
			_plane animate ["thrust5b",0.6];
			_plane animate ["thrust6b",0.6];
			_plane animate ["thrust7b",0.6];
			_plane animate ["thrust8b",0.6];
			_plane animate ["thrust9b",0.6];
			_plane animate ["thrust10b",0.6];
			_plane animate ["thrust11b",0.6];
			_plane animate ["thrust12b",0.6];
			_plane animate ["thrust13b",0.6];
			_plane animate ["thrust14b",0.6];
			_plane animate ["thrust15b",0.6];
			_plane animate ["thrust16b",0.6];
			_plane animate ["thrust17b",0.6];
			_plane animate ["thrust18b",0.6];
			_plane animate ["thrust19b",0.6];
			_plane animate ["thrust20b",0.6];
			_plane animate ["thrust21b",0.6];
			_plane animate ["thrust22b",0.6];
			_plane animate ["thrust23b",0.6];
			_plane animate ["thrust24b",0.6];
			_plane animate ["thrust25b",0.6];
			_plane animate ["thrust26b",0.6];
			_plane animate ["thrust27b",0.6];
			_plane animate ["thrust28b",0.6];
			_plane animate ["thrust29b",0.6];
			_plane animate ["thrust30b",0.6];
			_plane animate ["thrust31b",0.6];
			_plane animate ["thrust32b",0.6];

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

{
	_x setpos (getpos _this)
} foreach _emitters;
if (_Intensity > 0) then
{
	{
		_x setDropInterval 0.001} foreach _emitters
	}
else
{
	{
		_x setDropInterval 0
	} foreach _emitters
};

_looptime = time;

sleep 0.05; // mod by Crowe
//hintSilent format["day : %1 \nclR : %2 \nclG : %3\nclB : %4\ndayl : %5",_daylight,_cl0 select 0,_cl0 select 1,_cl0 select 2,_daylight];

_looptime = time - _looptime;
};
deleteVehicle _leftengine;
deleteVehicle _rightengine;
deleteVehicle _illuminateL;
deleteVehicle _illuminateR;
