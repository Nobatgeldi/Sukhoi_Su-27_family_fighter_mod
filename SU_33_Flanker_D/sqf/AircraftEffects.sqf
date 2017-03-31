_veh = (_this select 0);

//Private ["_script1[]"];

_script1 = [];


			_script1 set [0, _veh execVM "\SU_33_Flanker_D\sqf\FX_Afterburner.sqf"];
			_script1 set [1, _veh execVM "\SU_33_Flanker_D\sqf\FX_SonicBoom.sqf"];
			_script1 set [2, _veh execVM "\SU_33_Flanker_D\sqf\FX_WingtipTrails.sqf"];
     	_script1 set [3, _veh execVM "\SU_33_Flanker_D\sqf\FX_FuselageVapour.sqf"];
			_script1 set [4, _veh execVM "\SU_33_Flanker_D\sqf\weapons.sqf"];
