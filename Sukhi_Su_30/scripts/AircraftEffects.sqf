_veh = (_this select 0);

//Private ["_script1[]"];

_script1 = [];


			_script1 set [0, _veh execVM "\Sukhi_Su_30\scripts\FX_Afterburner.sqf"];
			_script1 set [1, _veh execVM "\Sukhi_Su_30\scripts\FX_SonicBoom.sqf"];
			_script1 set [2, _veh execVM "\Sukhi_Su_30\scripts\FX_WingtipTrails.sqf"];
			_script1 set [3, _veh execVM "\Sukhi_Su_30\scripts\FX_FuselageVapour.sqf"];
