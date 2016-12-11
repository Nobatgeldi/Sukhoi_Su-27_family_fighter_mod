_veh = (_this select 0);

//Private ["_script1[]"];

_script1 = [];


			_script1 set [0, _veh execVM "\Sukhoi_Su33\sqs\FX_Afterburner.sqf"];
			_script1 set [1, _veh execVM "\Sukhoi_Su33\sqs\FX_SonicBoom.sqf"];
			_script1 set [2, _veh execVM "\Sukhoi_Su33\sqs\FX_WingtipTrails.sqf"];
     	_script1 set [3, _veh execVM "\Sukhoi_Su33\sqs\FX_FuselageVapour.sqf"];
