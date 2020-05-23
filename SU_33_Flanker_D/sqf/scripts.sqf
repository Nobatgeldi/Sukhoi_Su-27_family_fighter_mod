
private ["_plane","_scripts"];

_plane = _this select 0;

_scripts = [];


			_scripts set [0, _plane execVM "\SU_33_Flanker_D\sqf\FX_Afterburner.sqf"];
			_scripts set [1, _plane execVM "\SU_33_Flanker_D\sqf\FX_SonicBoom.sqf"];
			_scripts set [2, _plane execVM "\SU_33_Flanker_D\sqf\FX_WingtipTrails.sqf"];
 	    _scripts set [3, _plane execVM "\SU_33_Flanker_D\sqf\FX_FuselageVapour.sqf"];
			_scripts set [4, _plane execVM "\SU_33_Flanker_D\sqf\weapons.sqf"];
