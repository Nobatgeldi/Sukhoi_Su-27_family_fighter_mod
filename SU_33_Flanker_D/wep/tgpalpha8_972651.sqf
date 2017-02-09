// // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// Targeting Pod Script
// Version alpha 0.8.972651
// Date: 2015.11.15
// Authors: Lala14, Tajin
// // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// init line:
// null = [] execVM "tgpalpha8_972651.sqf";
// to disable on specific vehicle place in the init of the vehicle this setVariable ["uavisalive","none"];
// to disable on specific units/players place in the init of the unit/player this setVariable ["uavadded","none"];
// to make targeting pod invisible on specifc vechiles put in the init vehicle this setVariable ["TGP_visible",true];

/*DEFINABLE*/
if (isNil "TGP_Visible") then {
TGP_Visible = 1; //0 - Hide the darter, 1 - Show the "Darter"
};
if (isNil "TGP_Debug") then {
TGP_Debug = 0; //0 - Hide debug, 1 - Show where the "Darter" is being attached
};
if (isNil "TGP_Veh_Only") then {
TGP_Veh_Only = 0; //0 - Anyone can connect to via AV Termianl,1 - Only allow the PEOPLE in the helicopter to connect to the tgp. WORKINGish (is not displayed on the AV Terminal as well (only to the people in the helicopter))
};
if (isNil "TGP_Numbering") then {
TGP_Numbering = 1; //Set Numbering Format 0 = Original Way numbers don't get stored on vehicles 1 = Use the first number assigned to the vehicle every time 2 = Looks in the array to find the closest number to 0 that is not being used 3 = Random Select Should not bring the same number ever unless you've used 225 vehicle names during that period, also gets assigned to the vehicle
};
if (isNil "TGP_RPT_Debug") then {
TGP_RPT_Debug = 1; //Give you all kinds of information on who is executing stuff, what vehicle has turned on/off the TGP and when via RPT - 0 - Hide RPT Debug, 1 - Show the RPT Debug
};
if (isNil "TGP_Auto_Start") then {
TGP_Auto_Start = 1; //0 - No TGPs on from mission start, 1 = Start the mission with all TGP's turned on, 2 = Start mission with TGP's all on and Respawned ones as well
};
if (isNil "TGP_TrippleFormat") then {
TGP_TrippleFormat = 0; //1 - Show numbers with "001" or 0 - standard "1", useful when there is more than 9 planes on one side or using TGP_Numbering = 3
};
if (isNil "TGP_AutoConnect") then {
TGP_AutoConnect = 1; //0 = No/Off 1 = Automatically connect the player's AV Terminal to the TGP once TGP turned On 2 = Connect player's AV Terminal to TGP if not connected to another AV Device
};
if (isNil "TGP_Auto_Ai_On") then {
TGP_Auto_Ai_On = 1; // 0 - AI do not turn their TGPs on, 1- Automatically makes AI turn their TGP's on
};
if (isNil "TGP_Auto_Add_TGP") then {
TGP_Auto_Add_TGP = 1; //0 - Don't add any TGPs, use: null = [<vehicle name>] spawn TGP_fnc_Do_Start; or in the editor use: null = this spawn { waitUntil {!isNil "TGP_fnc_Do_Start" && !isNull (_this)}; [_this] spawn TGP_fnc_Do_Start;}; on the vehicles you want, 1 - default usage (all vehicles get a TGP)
};
if (isNil "TGP_crew_Only") then {
TGP_crew_Only = 0; //0 - Anyone in the vehicle has access to the addaction, 1 - only the crew can access the addactions and such (door gunner, co-pilot, NOT FFV turrets).
};
if (isNil "TGP_only_specific_turrets") then {
TGP_only_specific_turrets = 0; //0 - Normal control, 1 - Only turrets defined in config or overrided by TGP_turret_position_override
};
if (isNil "TGP_turret_position_override") then {
TGP_turret_position_override = []; //Requires TGP_only_specific_turrets = 1, when not filled out everyone in the vehicle has access, when filled out the turrets defined here will have access (e.g. [[0],[-1],[0,0]])
};
if (isNil "TGP_user_classname") then {
TGP_user_classname = []; //when not filled out everyone can access the addaction, when filled out only classes defined here can access the addactions (e.g. ["B_Pilot_F","B_HelicopterPilot_F"]) (please note that the TGP can still be accessed via AV Terminal (unless TGP_Veh_Only = 1))
};

/*Don't touch unless you know what your doing*/
//need to change so tgp deletion and creation is done server side for reasons
_tgpdiagticktimestart = diag_tickTime;

_TGP_fnc_currentScriptVer = {
	private ["_TGP_version1","_TGP_version2","_TGP_version3","_TGP_versionstr"];
	_TGP_version1 = 0;
	_TGP_version2 = 8;
	_TGP_version3 = 972651;
	_TGP_versionstr = "0.8.972651";
	[_TGP_version1,_TGP_version2,_TGP_version3,_TGP_versionstr];
};

TGP_fnc_checkVer = {
	private ["_TGP_isNew","_TGP_version1_bool","_TGP_version2_bool","_TGP_version3_bool","_TGP_versionstr_bool"];
	if (isNil "TGP_Loaded") exitWith {true};
	if (!TGP_Loaded) then
	{
		waitUntil {TGP_loaded};
	};
	if (TGP_loaded) then
	{
		if (isNil "TGP_versionstr") then
		{
			if (true) exitWith {true};
		} else {
			_TGP_version3_bool = false;
			_TGP_version2_bool = false;
			_TGP_version1_bool = false;
			_TGP_versionstr_bool = false;

			if (TGP_versionstr != ((call _TGP_fnc_currentScriptVer) select 3)) then { _TGP_versionstr_bool = true; };
			if (TGP_version1 < ((call _TGP_fnc_currentScriptVer) select 0)) then { _TGP_version1_bool = true };
			if (TGP_version2 < ((call _TGP_fnc_currentScriptVer) select 1)) then { _TGP_version2_bool = true; };
			if (TGP_version3 < ((call _TGP_fnc_currentScriptVer) select 2)) then { _TGP_version3_bool = true; };

			if (_TGP_versionstr_bool) then {
				_TGP_isNew = switch (true) do
				{
				    //case ( !(_TGP_version1_bool) ): { diag_log "TGP - !(_TGP_version1_bool)"; false };
				    case ( _TGP_version1_bool ): { diag_log "TGP - Condition - _TGP_version1_bool"; true };
				    case ( !(_TGP_version1_bool) && _TGP_version2_bool ): { diag_log "TGP - Condition - !(_TGP_version1_bool) && _TGP_version2_bool"; true };
				    case ( !(_TGP_version2_bool) && _TGP_version3_bool ): { diag_log "TGP - Condition - !(_TGP_version2_bool) && _TGP_version3_bool"; true };
				    default { false };
				};
			} else {
				_TGP_isNew = false;
			};

			if (_TGP_versionstr_bool) then
			{
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_verstionstr is not the same";};
			} else {
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_verstionstr is the same";};
			};

			if (_TGP_version1_bool) then
			{
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_version1 is not the same";};
			} else {
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_version1 is the same or less";};
			};

			if (_TGP_version2_bool) then
			{
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_version2 is not the same";};
			} else {
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_version2 is the same or less";};
			};

			if (_TGP_version3_bool) then
			{
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_version3 is not the same";};
			} else {
				if (TGP_RPT_Debug == 1) then {diag_log "TGP - TGP_version3 is the same or less";};
			};
		};
	};
	//if ((TGP_RPT_Debug == 1) && _TGP_isNew) then {diag_log format ["TGP is going to be reloaded to v%1 from v%2",((call _TGP_fnc_currentScriptVer) select 3),TGP_versionstr];};
	//if ((TGP_RPT_Debug == 1) && !_TGP_isNew) then { diag_log format ["TGP is the same version so not loading (v%1 and v%2)",((call _TGP_fnc_currentScriptVer) select 3),TGP_versionstr]; };
	_TGP_isNew
};

_isThisNewTGP = call TGP_fnc_checkVer;

if (!(_isThisNewTGP) && (!isNil "TGP_Loaded")) then { diag_log format ["TGP is the same version or less, so not loading functions, only going to check config (v%1 and v%2)",((call _TGP_fnc_currentScriptVer) select 3),TGP_versionstr]; };
if ((_isThisNewTGP) && (!isNil "TGP_Loaded")) then { diag_log format ["TGP is going to be reloaded to v%1 from v%2",((call _TGP_fnc_currentScriptVer) select 3),TGP_versionstr]; missionNamespace setVariable ["TGP_kill",true]; publicVariable "TGP_kill"; waitUntil { !(missionNamespace getVariable ["TGP_kill",false]) }; diag_log format ["TGP is going to be start reloading now to v%1",((call _TGP_fnc_currentScriptVer) select 3)];};
if ((_isThisNewTGP) OR (isNil "TGP_Loaded")) then {
	TGP_Loaded = false;

	//old dedicated line

	if (TGP_RPT_Debug == 1) then { diag_log "TGP Loading"; };

	if (hasInterface) then { waitUntil {!isNull player}; };
};
// config [["kindOf classnames"], [ ["position in modelspace" (as array or string) ] ], [turret positions (optional) (default: []) e.g. [[0],[-1]] ],(Hide TGP (default: false), [(PiP selectionTexture (default: []) (can be number or string) ]),[(need all of these weapons/magazines (default: false)), [(all of the magazines/weapons) default: [] ] ] ]
if (isNil "TGP_config") then { TGP_config = [] };
TGP_config append [
	[["Su33_Protatype_PT_2"], [
		 [ [-1.75,-0.2,-1.73] ]
	]],
];
if (!_isThisNewTGP) exitWith { null = [] spawn TGP_fnc_checkTGPConfig };
// The config-array can be modified at runtime. This also allows modulators to append their own settings without having to edit this script.

// vars
TGP_Uavs = [];
TGP_UavNo = ['TGP_0'];
if (count(missionNamespace getVariable ["TGP_CounterBLU",[]]) < 1) then { TGP_CounterBLU = [0] };
if (count(missionNamespace getVariable ["TGP_CounterOPF",[]]) < 1) then { TGP_CounterOPF = [0] };
if (count(missionNamespace getVariable ["TGP_CounterIND",[]]) < 1) then { TGP_CounterIND = [0] };
if (isNil "TGP_varname") then { TGP_varname = "uavisalive"; };
TGP_text_ON = "<t color='#FF0000'>Turn the Target Pod On</t>";
TGP_text_OFF = "<t color='#FF0000'>Turn the Target Pod Off</t>";
TGP_text_Use = "<t color='#FF0000'>Use Targeting Pod</t>";
TGP_text_Lock = "<t color='#FF0000'>Toggle Targeting Pod Locking</t>";
TGP_text_PiP = "<t color='#FF0000'>Toggle PiP</t>";
TGP_text_mfdpip = "<t color='#FF0000'>Toggle MFD PiP</t>";
TGP_text_headTrack = "<t color='#FF0000'>Toggle Head Tracking</t>";
TGP_text_setTGPTGTPos = "<t color='#FF0000'>Select TGP Target Map Pos</t>";
TGP_BLU_TGP = "B_UAV_01_F";
//TGP_BLU_TGP = "Targeting_Pod_B_lala13";
TGP_OPF_TGP = "O_UAV_01_F";
TGP_IND_TGP = "I_UAV_01_F";
TGP_version1 = 0;
TGP_version2 = 8;
TGP_version3 = 972651;
TGP_versionstr = "0.8.972651";

// functions
TGP_fnc_inList = {
	private ["_index","_found"];
	_found = false;
	_index = -1;
	{
		_types = _x select 0;
		{
			if (_this isKindOf _x) exitWith { _found = true; };
		} forEach _types;
		if _found exitWith {_index = _forEachIndex;};
	} forEach TGP_config;
	_index
};

TGP_fnc_inArrayIsKindOf = {
	private ["_whatIfound","_whereitsin","_index"];
	_whatIfound = _this select 0;
	_whereitsin = _this select 1;
	if (isNil {_whatIfound} || isNil {_whereitsin}) exitWith {-1};
	_index = -1;
	{
		if (_whatIfound isKindOf _x) exitWith { _index = _forEachIndex; };
	}forEach _whereitsin;
	_index
};

TGP_fnc_checkTGPConfig = {
	private ["_checkbra","_types","_quitit","_copiesTGPconfig","_indexcheck","_indexhere","_types","_thebegginerindex","_thegoods","_theindex"];
	if (TGP_RPT_Debug == 1) then { diag_log "TGP - Checking Config for repeats" };
	_copiesTGPconfig = +TGP_config;
	_checkbra = [];
	{
		_types = _x select 0;
		_indexhere = _forEachIndex;
		_quitit = false;
		if (count _checkbra > 0) then {
			{
				if (_types isEqualto (_x select 0)) exitWith { _quitit = true };
			}forEach _checkbra;
		};
		if (!_quitit) then
		{
			_indexcheck = (count _checkbra);
			_checkbra set [(count (_checkbra)),[]];
			(_checkbra select _indexcheck) pushBack _types;
			(_checkbra select _indexcheck) set [(count (_checkbra select _indexcheck)),[]];
			{
				if (_types isEqualto (_x select 0)) then { (_checkbra select _indexcheck select ((count (_checkbra select _indexcheck)) - 1)) pushBack _forEachIndex };
			}forEach _copiesTGPconfig;
			if (count (_checkbra select _indexcheck select 1) < 2) then
			{
				_checkbra set [_indexcheck,objNull];
				_checkbra = _checkbra - [objNull];
			};
		};
	}forEach _copiesTGPconfig;
	if (count _checkbra < 1) exitWith { if (TGP_RPT_Debug == 1) then { diag_log "TGP - No config repeats found, stopping search ..." } };
	{
		_thebegginerindex = (_x select 1 select 0);
		_theindex = (_x select 1 select ((count (_x select 1)) - 1));
		_thegoods = +(TGP_config select _theindex);
		if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - TGP_config repeat found at %1 (%2) replacing with %3 (%4)",_thebegginerindex,(TGP_config select _thebegginerindex),_theindex,_thegoods] };
		{
			TGP_config set [_x,objNull];
		}forEach (_x select 1);
		TGP_config set [_thebegginerindex,_thegoods];
	}forEach _checkbra;
	TGP_config = TGP_config - [objNull];
	if (TGP_RPT_Debug == 1) then { diag_log "TGP - Finishing checking for config repeats" };
};

TGP_fnc_inArrayTurret = {
	private ["_veh","_unit","_index"];
	_unit = _this select 0;
	_veh = _this select 1;
	_index = -1;
	{
		if ((_veh turretUnit _x) isEqualto _unit) exitWith {_index = _forEachIndex;};
	}forEach (allTurrets [_veh,false]);
	_index;
};

TGP_fnc_Uav_Death = {
	if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 - %3 - TGP Killed event handler added", attachedTo (_this select 0), getText (configFile >> 'cfgVehicles' >> typeOf (attachedTo (_this select 0)) >> 'displayName'), (_this select 0)] };
	(_this select 0) addEventHandler ["Killed", { null = _this spawn
		{
			private ["_uav","_killer","_veh","_olduavname","_tgpvar","_unit","_controlledunit"];
			_uav = _this select 0;
			if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - TGP killed event handler started",_uav] };
			_killer = _this select 1;
			_veh = attachedTo _uav;
			_olduavname = vehicleVarName _uav;
			_tgpvar = _veh getVariable [TGP_varname,false];
			_veh setVariable ["TGP",nil,true];
			_unit = uavControl _uav select 0;
			_controlledunit = uavControl _uav select 1;

			if (!isNull _unit) then {
				_unit connectTerminalToUav objNull;
				if ( _controlledunit != "") then {
					_uav action ["BackFromUAV",_unit];
				};
			} else {_unit = _killer};

			if (alive _killer) then {
				if ((side _killer != sideEnemy) OR (_killer == _unit)) then {
					if (TGP_RPT_Debug == 1) then { diag_log format ["%1 adding to rating 1400, %2",_killer,typeOf _uav];};
					_killer addRating 1400;
				};
			};
			if (_tgpvar) then {
				TGP_Uavs = TGP_Uavs - [_uav];
				publicVariable "TGP_Uavs";
			};
			if (alive _veh) then {
				deleteVehicle _uav;
				_veh setVariable [TGP_varname,false,true];
				if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 TGP was Destroyed, Recreating ...",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
				[_veh] call TGP_fnc_Do_Start;
			} else {
			if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 Vehicle Destroyed, Leaving TGP dead",_veh,getText (configFile >> 'cfgVehicles' >> typeOf 	_veh >> 'displayName')];};
			};
			if (_tgpvar) then {
				if (_unit in (crew _veh)) then {
					sleep 0.01;
					[_unit] spawn TGP_fnc_Do_Stuff;
				} else {
					sleep 0.01;
					[_veh] spawn TGP_fnc_Do_Stuff;
					waitUntil { (!isNull gunner (_veh getVariable "TGP")) };
					_unit connectTerminalToUav (_veh getVariable "TGP");
					if (_controlledunit != "") then {
						_switchtouavaction = format ["SwitchToUAV%1",_controlledunit];
						_unit action [_switchtouavaction, (_veh getVariable "TGP")];
					};
				};
			};
			[_veh,_olduavname] spawn {
				_veh = _this select 0;
				_olduavname = _this select 1;
				//[_veh] spawn TGP_fnc_Do_Start;

				waitUntil{alive (_veh getVariable "TGP")};

				(_veh) spawn { _newuavname = vehicleVarName (_this getVariable "TGP"); TGP_UavNo = TGP_UavNo - [_newuavname]; publicVariable "TGP_UavNo"; };

				if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 TGP Created",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> '	displayName')]; };

				[_veh,_olduavname] spawn {
					_veh = _this select 0;
					_olduavname = _this select 1;
					_tgp = (_veh getVariable 'TGP');
					if (TGP_RPT_Debug == 1) then { diag_log format ["%1 changed name to %2",_tgp,_olduavname]; };
					_tgp setVehicleVarName _olduavname;
					_tgp setName _olduavname;
					missionNamespace setVariable [_olduavname,_tgp];
					publicVariable _olduavname;
				};
			};
		};
	}];

	[(_this select 0)] spawn {
		_uav = _this select 0;
		waitUntil{sleep 0.1; (isNull (attachedTo _uav))};
		if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 Parent Was Destroyed/Disappeared Deleting TGP",_uav,getText (configFile >> 'cfgVehicles' >> typeOf _uav >> 'displayName')]; };
		deleteVehicle _uav;
	};
	TGP_Uavs = TGP_Uavs - [objNull];
	publicVariable "TGP_Uavs";
};

TGP_fnc_Veh_Only = {
	_veh = vehicle (_this select 0);
	_ison = _veh getVariable [TGP_varname,false];

	if (_ison) then {
		_veh setVariable[TGP_varname,false,true];
	} else {
		_veh setVariable[TGP_varname,true,true];
	};
};

TGP_fnc_Select_Veh_Only = {
	if (TGP_Veh_Only == 0) then {
		[(_this select 0)] spawn TGP_fnc_Do_Stuff;
	};

	if (TGP_Veh_Only == 1) then {
		[(_this select 0)] spawn TGP_fnc_Veh_Only;
	};
};

TGP_fnc_ConditionsExtra = {
	private ["_unit","_veh","_return","_indexpl","_themagsorweapons","_wefoundit","_lel1","_themagsorweaponscopied","_wedone","_mag","_weapon","_doweneedallofthese"];
	_unit = _this select 0;
	_veh = _this select 1;
	_indexpl = (_veh call TGP_fnc_inList);
	if (_indexpl < 0) exitWith {false};
	if (count (_veh getVariable ["TGP_conditionextraresultsstuff",[]]) > 0) then
	{
		if !((magazines _veh) isEqualto (_veh getVariable "TGP_conditionextraresultsstuff" select 1)) then
		{
			_veh setVariable ["TGP_conditionextraresults",nil,true];
		};
		if !((weapons _veh) isEqualto (_veh getVariable "TGP_conditionextraresultsstuff" select 0)) then
		{
			_veh setVariable ["TGP_conditionextraresults",nil,true];
		};
	};
	if (!isNil {_veh getVariable "TGP_conditionextraresults"}) exitWith { (_veh getVariable ["TGP_conditionextraresults",false]) };
	_wefoundit = false;

	_themagsorweapons = [];
	if (count (TGP_config select _indexpl) > 4) then
	{
		_doweneedallofthese = TGP_config select _indexpl select 5 select 0;
		_themagsorweapons = TGP_config select _indexpl select 5 select 1;
		if (count _themagsorweapons < 1) exitWith {_wefoundit = true; true};
		_themagsorweaponscopied = +(TGP_config select _indexpl select 5 select 1);
		{
			_mag = [toLower(_x),_forEachIndex];
			{
				if ((_mag select 0) isEqualto toLower(_x)) then { _themagsorweaponscopied set [(_mag select 1),true]; };
			}forEach (magazines _veh);
		}forEach _themagsorweaponscopied;
		_wedone = { _x isEqualto true } count _themagsorweaponscopied;
		if (_doweneedallofthese) then
		{
			if (_wedone == (count _themagsorweapons)) exitWith {_wefoundit = true; true};
		} else {
			if (_wedone > 0) exitWith {_wefoundit = true; true};
		};
		{
			if (typeName _x isEqualto "STRING") then
			{
				_weapon = [toLower(_x),_forEachIndex];
				{
					if ((_weapon select 0) isEqualto toLower(_x)) then { _themagsorweaponscopied set [(_weapon select 1),true]; };
				}forEach (weapons _veh);
			};
		}forEach _themagsorweaponscopied;
		_wedone = { _x isEqualto true } count _themagsorweaponscopied;
		if (_doweneedallofthese) then
		{
			if (_wedone == (count _themagsorweapons)) exitWith {_wefoundit = true; true};
		} else {
			if (_wedone > 0) exitWith {_wefoundit = true; true};
		};
	} else {
		if (true) exitWith {_wefoundit = true; true};
	};
	if (!_wefoundit) then
	{
		_lel1 = {isClass (configFile >> "CfgMagazines" >> _x)} count _themagsorweapons > 0;
		if (_lel1) exitWith {};
		_lel1 = {isClass (configFile >> "CfgWeapons" >> _x)} count _themagsorweapons > 0;
		if (!_lel1) exitWith {_wefoundit = true; if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Could not find %1 in cfgWeapons or cfgMagazines",_themagsorweapons] }; _veh setVariable ["TGP_conditionextraresults",true,true]; true};
	};
	_veh setVariable ["TGP_conditionextraresults",_wefoundit,true];
	_veh setVariable ["TGP_conditionextraresultsstuff",[weapons _veh,magazines _veh],true];
	_wefoundit;
};

TGP_fnc_Conditions = {
	private ["_unit","_veh","_return","_indexpl"];
	_unit = _this select 0;
	_veh = _this select 1;
	_indexpl = (_veh call TGP_fnc_inList);
	if (_indexpl < 0) exitWith {false};

	_return = (_veh getVariable [TGP_varname,false] isEqualTo true && _veh call TGP_fnc_inList > -1);
	if (TGP_crew_Only == 1 && TGP_only_specific_turrets == 0) then {_return = _return && ( ([_unit,_veh] call TGP_fnc_inArrayTurret > -1) OR (driver _veh == _unit) )};
	if (TGP_only_specific_turrets == 1) then { if (_indexpl > -1 && (count(TGP_turret_position_override)) <= 0) then { if (!isNil {count(TGP_config select _indexpl select 2)}) then { if (count (TGP_config select _indexpl select 2) > 0) then { if (count (assignedVehicleRole _unit) > 1) then {_return = _return && ((assignedVehicleRole _unit select 1) in (TGP_config select _indexpl select 2)) } else { _return = _return && ((toLower(assignedVehicleRole _unit select 0) == "driver") && ([-1] in (TGP_config select _indexpl select 2))) } }; }; } else { if (count (assignedVehicleRole _unit) > 1) then {_return = _return && ((assignedVehicleRole _unit select 1) in (TGP_turret_position_override)) } else { _return = _return && ((toLower(assignedVehicleRole _unit select 0) == "driver") && ([-1] in (TGP_turret_position_override))) } }; };
	if (count (TGP_user_classname) > 0) then { _return = _return && ( ([_unit,TGP_user_classname] call TGP_fnc_inArrayIsKindOf) > -1 ) };
	if (TGP_Veh_Only == 1) then { [_unit] call TGP_fnc_Do_Stuff; };

	_return;
};

TGP_fnc_Conditions2 = {
	private ["_unit","_veh","_return","_indexpl"];
	_unit = _this select 0;
	_veh = _this select 1;
	_indexpl = (_veh call TGP_fnc_inList);
	if (_indexpl < 0) exitWith {false};

	_return = (_veh getVariable [TGP_varname,false] isEqualTo false && _veh call TGP_fnc_inList > -1);
	_return = _return && ([_unit,_veh] call TGP_fnc_ConditionsExtra);
	if (TGP_Auto_Add_TGP == 0) then { _return = _return && ( { _attachedobj = _x; _found = false; { if (_attachedobj isKindOf _x) exitWith {_found = true;} }forEach [TGP_BLU_TGP,TGP_OPF_TGP,TGP_IND_TGP]; _found; }forEach (attachedObjects _veh) ) };
	if (TGP_crew_Only == 1 && TGP_only_specific_turrets == 0) then {_return = _return && ( ([_unit,_veh] call TGP_fnc_inArrayTurret > -1) OR (driver _veh == _unit) )};
	if (TGP_only_specific_turrets == 1) then { if (_indexpl > -1 && (count(TGP_turret_position_override)) <= 0) then { if (!isNil {count(TGP_config select _indexpl select 2)}) then { if (count (TGP_config select _indexpl select 2) > 0) then { if (count (assignedVehicleRole _unit) > 1) then {_return = _return && ((assignedVehicleRole _unit select 1) in (TGP_config select _indexpl select 2)) } else { _return = _return && ((toLower(assignedVehicleRole _unit select 0) == "driver") && ([-1] in (TGP_config select _indexpl select 2))) } }; }; } else { if (count (assignedVehicleRole _unit) > 1) then {_return = _return && ((assignedVehicleRole _unit select 1) in (TGP_turret_position_override)) } else { _return = _return && ((toLower(assignedVehicleRole _unit select 0) == "driver") && ([-1] in (TGP_turret_position_override))) }; }; };
	if (TGP_Veh_Only == 1) then { [_unit] call TGP_fnc_Do_Stuff; };
	if (count (TGP_user_classname) > 0) then { _return = _return && ( ([_unit,TGP_user_classname] call TGP_fnc_inArrayIsKindOf) > -1 ) };

	_return;
};

TGP_fnc_Conditions3 = {
	private ["_unit","_veh","_return","_inexpl","_extra","_extraa"];
	_this params ["_unit","_veh",["_extra",true],["_extraa",false]];
	_unit = _this select 0;
	_veh = _this select 1;
	_indexpl = (_veh call TGP_fnc_inList);

	if (_indexpl < 0) exitWith {false};
	_return = (((_veh getVariable [TGP_varname,false]) isEqualTo true) && (_veh call TGP_fnc_inList > -1));
	if (_extra) then { _return = _return && (((uavControl (_veh getVariable "TGP") select 1) != "GUNNER")); };
	if (_extraa) then { if (count(TGP_config select _indexpl) >= 5) then { if (count(TGP_config select _indexpl select 4) == 0) then { _return = _return && false; }; } else { _return = _return && false }; };
	if (TGP_crew_Only == 1 && TGP_only_specific_turrets == 0) then {_return = _return && ( ([_unit,_veh] call TGP_fnc_inArrayTurret > -1) OR (driver _veh == _unit) )};
	if (TGP_only_specific_turrets == 1) then {  if (_indexpl > -1 && (count(TGP_turret_position_override)) <= 0) then { if (!isNil {count(TGP_config select _indexpl select 2)}) then { if (count (TGP_config select _indexpl select 2) > 0) then { if (count (assignedVehicleRole _unit) > 1) then {_return = _return && ((assignedVehicleRole _unit select 1) in (TGP_config select _indexpl select 2)) } else { _return = _return && ((toLower(assignedVehicleRole _unit select 0) == "driver") && ([-1] in (TGP_config select _indexpl select 2))) } }; }; } else { if (count (assignedVehicleRole _unit) > 1) then {_return = _return && ((assignedVehicleRole _unit select 1) in (TGP_turret_position_override)) } else { _return = _return && ((toLower(assignedVehicleRole _unit select 0) == "driver") && ([-1] in (TGP_turret_position_override))) }; }; };
	if (count (TGP_user_classname) > 0) then { _return = _return && ( ([_unit,TGP_user_classname] call TGP_fnc_inArrayIsKindOf) > -1 ) };

	_return;
};

TGP_fnc_CountInList = {
	_number = _this select 0;
	_tocount = _this select 1;

	_index = 'nil';

	if (_number in _tocount) then { _index = _number; };

	_index
};

TGP_fnc_getAttachToStuff = {
	if (count _this <= 0) exitWith {};
	_veh = _this select 0;
	_attachToData = _this select 1;

	switch (typeName _attachToData) do {
	    case "ARRAY": {
	    	_attachToData = [_veh,_attachToData,""];
	    };
	    case "STRING" : {
	    	_attachToData = [_veh,[0,0,0],_attachToData];
		};
	};
	_attachToData
};

TGP_fnc_NumberCorrections = {
	private ['_unit','_veh','_CorrectNumber'];
	if (count _this == 0) exitWith { if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - NumberCorrections error %1",_this]; }; };
	_unit = _this select 0;
	if (isNull _unit) exitWith {};
	_veh = if (vehicle _unit == _unit) then { _unit } else { vehicle _unit };
	_specialside = civilian;
	_CorrectNumber = -1;

	if ( ((!isPlayer _unit) OR (side _unit == sideEnemy)) && (_unit != _veh))  then {
		//_unit = if !(isNull (_veh getVariable ["TGP",objNull])) then { (_veh getVariable ["TGP",objNull]) } else { _unit };
	} else {
		if ( ([_veh] call TGP_fnc_getCfgSide) == 1) then {_specialside = west;};
		if ( ([_veh] call TGP_fnc_getCfgSide) == 0) then {_specialside = east;};
		if ( ([_veh] call TGP_fnc_getCfgSide) == 2) then {_specialside = resistance;};
	};
	if ((side _unit == west) OR (_specialside == west)) then {
		if (TGP_Numbering == 0) then {
			_CorrectNumber = count TGP_CounterBLU;
			TGP_CounterBLU pushBack _CorrectNumber;
			publicVariable "TGP_CounterBLU";
		};
		if (TGP_Numbering == 1) then {
			if (isNil {_veh getVariable "TGP_StorageBLU"}) then {
				_veh setVariable ["TGP_StorageBLU",count TGP_CounterBLU,true];
				_CorrectNumber = (_veh getVariable "TGP_StorageBLU");
				TGP_CounterBLU pushBack _CorrectNumber;
				publicVariable "TGP_CounterBLU";
			} else {
				_CorrectNumber = (_veh getVariable "TGP_StorageBLU");
			};
		};
		if (TGP_Numbering == 2) then {
			for [{_x=1},{_x<=count TGP_CounterBLU},{_x=_x+1}] do
			{
				if (_x in TGP_CounterBLU isEqualTo false) then { _CorrectNumber = _x; };
			};
			TGP_CounterBLU pushBack _CorrectNumber;
			publicVariable "TGP_CounterBLU";
		};
		if (TGP_Numbering == 3) then {
			if (isNil {_veh getVariable "TGP_StorageBLU"}) then {
				_veh setVariable ["TGP_StorageBLU",floor (random 226),true];
			if ((_veh getVariable "TGP_StorageBLU") in TGP_CounterBLU) then {
					_veh setVariable ["TGP_StorageBLU",nil,true];
					[_unit] call TGP_fnc_NumberCorrections;
				} else {
					_CorrectNumber = (_veh getVariable "TGP_StorageBLU");
					TGP_CounterBLU pushBack _CorrectNumber;
					publicVariable "TGP_CounterBLU";
				};
			} else {
				_CorrectNumber = (_veh getVariable "TGP_StorageBLU");
			};
		};
	};
	if ((side _unit == east) OR (_specialside == east)) then {
		if (TGP_Numbering == 0) then {
			_CorrectNumber = count TGP_CounterOPF;
			TGP_CounterOPF pushBack _CorrectNumber;
			publicVariable "TGP_CounterOPF";
		};
		if (TGP_Numbering == 1) then {
			if (isNil {_veh getVariable "TGP_StorageOPF"}) then {
				_veh setVariable ["TGP_StorageOPF",count TGP_CounterOPF,true];
				_CorrectNumber = (_veh getVariable "TGP_StorageOPF");
				TGP_CounterOPF pushBack _CorrectNumber;
				publicVariable "TGP_CounterOPF";
			} else {
				_CorrectNumber = (_veh getVariable "TGP_StorageOPF");
			};
		};
		if (TGP_Numbering == 2) then {
			for [{_x=1},{_x<=count TGP_CounterOPF},{_x=_x+1}] do
			{
				if (_x in TGP_CounterOPF isEqualTo false) then { _CorrectNumber = _x; };
			};
			TGP_CounterOPF pushBack _CorrectNumber;
			publicVariable "TGP_CounterOPF";
		};
		if (TGP_Numbering == 3) then {
			if (isNil {_veh getVariable "TGP_StorageOPF"}) then {
				_veh setVariable ["TGP_StorageOPF",floor (random 226),true];
			if ((_veh getVariable "TGP_StorageOPF") in TGP_CounterOPF) then {
					_veh setVariable ["TGP_StorageOPF",nil,true];
					[_unit] call TGP_fnc_NumberCorrections;
				} else {
					_CorrectNumber = (_veh getVariable "TGP_StorageOPF");
					TGP_CounterOPF pushBack _CorrectNumber;
					publicVariable "TGP_CounterOPF";
				};
			} else {
				_CorrectNumber = (_veh getVariable "TGP_StorageOPF");
			};
		};
	};
	if ((side _unit == resistance) or (_specialside == resistance)) then {
		if (TGP_Numbering == 0) then {
			_CorrectNumber = count TGP_CounterIND;
			TGP_CounterIND pushBack _CorrectNumber;
			publicVariable "TGP_CounterIND";
		};
		if (TGP_Numbering == 1) then {
			if (isNil {_veh getVariable "TGP_StorageIND"}) then {
				_veh setVariable ["TGP_StorageIND",count TGP_CounterIND,true];
				_CorrectNumber = (_veh getVariable "TGP_StorageIND");
				TGP_CounterIND pushBack _CorrectNumber;
				publicVariable "TGP_CounterIND";
			} else {
				_CorrectNumber = (_veh getVariable "TGP_StorageIND");
			};
		};
		if (TGP_Numbering == 2) then {
			for [{_x=1},{_x<=count TGP_CounterIND},{_x=_x+1}] do
			{
				if (_x in TGP_CounterIND isEqualTo false) then { _CorrectNumber = _x; };
			};
			TGP_CounterIND pushBack _CorrectNumber;
			publicVariable "TGP_CounterIND";
		};
		if (TGP_Numbering == 3) then {
			if (isNil {_veh getVariable "TGP_StorageIND"}) then {
				_veh setVariable ["TGP_StorageIND",floor (random 226),true];
			if ((_veh getVariable "TGP_StorageIND") in TGP_CounterIND) then {
					_veh setVariable ["TGP_StorageIND",nil,true];
					[_unit] call TGP_fnc_NumberCorrections;
				} else {
					_CorrectNumber = (_veh getVariable "TGP_StorageIND");
					TGP_CounterIND pushBack _CorrectNumber;
					publicVariable "TGP_CounterIND";
				};
			} else {
				_CorrectNumber = (_veh getVariable "TGP_StorageIND");
			};
		};
	};
	if ((typeName _CorrectNumber == "STRING") or (_CorrectNumber == -1)) exitWith {[_unit] call TGP_fnc_NumberCorrections; false};
	if (TGP_TrippleFormat == 1) then {
		if (_CorrectNumber < 10) exitWith {
			_CorrectNumber = format ['00%1',_CorrectNumber];
		};
		if ((_CorrectNumber > 9) && (_CorrectNumber < 100)) exitWith {
			_CorrectNumber = format ['0%1',_CorrectNumber];
		};
	};
	_CorrectNumber;
};

TGP_fnc_Do_Stuff = {
	private ["_unit","_veh","_i","_ison"];
	_unit = _this select 0;
	_veh = vehicle _unit;
	_i = _veh call TGP_fnc_inList;
	_ison = _veh getVariable [TGP_varname,false];

	if (TGP_Veh_Only == 0) then {
		if (_ison isEqualTo true) then {
			_veh setVariable[TGP_varname,false,true];
		} else {
			_veh setVariable[TGP_varname,true,true];
		};
	};

	if (TGP_Veh_Only == 0) then {
		if (_i > -1) then {
			if (_ison isEqualto false) then {
				if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Turned On",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
				_tgps = (TGP_config select _i) select 1;
				if (isNil {(_veh getVariable "TGP")}) exitWith { if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Was Not Found, Restarting ...",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];}; [_veh] spawn TGP_fnc_Do_Start; };
				if !(alive (_veh getVariable "TGP")) exitWith {if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Was Destroyed (damage of %3 - %4), Restarting ...",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'),damage (_veh getVariable "TGP"),!(alive (_veh getVariable "TGP"))];}; deleteVehicle (_veh getVariable "TGP"); [_veh] spawn TGP_fnc_Do_Start; };
				if (isNull (_veh getVariable "TGP")) exitWith {deleteVehicle (_veh getVariable "TGP"); if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Was Disappeared, Restarting ...",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];}; [_veh] spawn TGP_fnc_Do_Start;};
				{
					_tgp = objNull;
					if ((side _unit == west) && (TGP_Veh_Only == 0)) then {
						if !(([(_veh getVariable "TGP")] call TGP_fnc_getCfgSide) == 1) then {
							_uavname = vehicleVarName (_veh getVariable "TGP");
							if (isNil "_uavname") then {
								_tgpname = format ["TGP_%1",count TGP_UavNo];
								_uavname = _tgpname;
								TGP_UavNo pushBack _tgpname;
								publicVariable "TGP_UavNo";
							};
							TGP_Uavs = TGP_Uavs - [ (_veh getVariable "TGP") ];
							publicVariable "TGP_Uavs";
							deleteVehicle (_veh getVariable "TGP");
							_tgp = TGP_BLU_TGP createVehicle [0,0,0];
							_tgp setVehicleVarName _uavname;
							_tgp setName _uavname;
							missionNamespace setVariable [_uavname,_tgp];
							publicVariable _uavname;
							_veh setVariable ["TGP",_tgp,true];
							_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
							if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
							_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);
							if (TGP_Debug == 1) then { _veh vehicleChat "Changing vehicle to Blu AR-2"; _veh vehicleChat format ['TGP attachto %1',[getText (configFile >> "cfgVehicles" >> typeOf _veh >> "displayName"),(_x select 0)]]; };
							if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 - %4 TGP Changed sides to %3",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'),side _unit,_uavname];};
							[_tgp] spawn TGP_fnc_Uav_Death;
						};
					};
					if ((side _unit == east) && (TGP_Veh_Only == 0)) then {
						if !(([(_veh getVariable "TGP")] call TGP_fnc_getCfgSide) == 0) then {
							_uavname = vehicleVarName (_veh getVariable "TGP");
							if (isNil "_uavname") then {
								_tgpname = format ["TGP_%1",count TGP_UavNo];
								_uavname = _tgpname;
								TGP_UavNo pushBack _tgpname;
								publicVariable "TGP_UavNo";
							};
							deleteVehicle (_veh getVariable "TGP");
							_tgp = TGP_OPF_TGP createVehicle [0,0,0];
							_tgp setVehicleVarName _uavname;
							_tgp setName _uavname;
							missionNamespace setVariable [_uavname,_tgp];
							publicVariable _uavname;
							_veh setVariable ["TGP",_tgp,true];
							_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
							if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
							_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);
							if (TGP_Debug == 1) then { _veh vehicleChat "Changing vehicle to Opf AR-2"; _veh vehicleChat format ['TGP attachTo %1',[getText (configFile >> "cfgVehicles" >> typeOf _veh >> "displayName"),(_x select 0)]]; };
							if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 - %4 TGP Changed sides to %3",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'),side _unit,_uavname];};
							[_tgp] spawn TGP_fnc_Uav_Death;
						};
					};
					if ((side _unit == resistance) && (TGP_Veh_Only == 0)) then {
						if !(([(_veh getVariable "TGP")] call TGP_fnc_getCfgSide) == 2) then {
							_uavname = vehicleVarName (_veh getVariable "TGP");
							if (isNil _uavname) then {
								_tgpname = format ["TGP_%1",count TGP_UavNo];
								_uavname = _tgpname;
								TGP_UavNo pushBack _tgpname;
								publicVariable "TGP_UavNo";
							};
							TGP_Uavs = TGP_Uavs - [ (_veh getVariable "TGP") ];
							publicVariable "TGP_Uavs";
							deleteVehicle (_veh getVariable "TGP");
							_tgp = TGP_IND_TGP createVehicle [0,0,0];
							_tgp setVehicleVarName _uavname;
							_tgp setName _uavname;
							missionNamespace setVariable [_uavname,_tgp];
							publicVariable _uavname;
							_veh setVariable ["TGP",_tgp,true];
							_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
							if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
							_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);
							if (TGP_Debug == 1) then { _veh vehicleChat "Changing vehicle to Indep AR-2"; _veh vehicleChat format ['TGP attachTo %1',[getText (configFile >> "cfgVehicles" >> typeOf _veh >> "displayName"),(_x select 0)]]; };
							if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 - %4 TGP Changed sides to %3",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'),side _unit,_uavname];};
							[_tgp] spawn TGP_fnc_Uav_Death;
						};
					};
					_tgp = (_veh getVariable ["TGP",objNull]);
					if (isNull _tgp) exitWith { if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 - TGP Was not found", _unit, _veh] }; };
					if (typeName (_veh getVariable [TGP_varname,false]) isEqualto "BOOL") then {
						createVehicleCrew _tgp;
						if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Units created",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
						_tgp deleteVehicleCrew (driver _tgp);
					};
					if !(_tgp in TGP_Uavs) then { TGP_Uavs pushBack _tgp; publicVariable "TGP_Uavs"; };
					if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Driver removed",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
					if (TGP_Veh_Only == 0) then {
						_TGP_GroupID = format ['%2-%1 Targeting Pod',getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'),([_unit] call TGP_fnc_NumberCorrections)];
						[[(group _tgp),[_TGP_GroupID]],'setGroupID',true,true] spawn BIS_FNC_MP;
						if !( ("B_UavTerminal" in assignedItems _unit) OR ("O_UavTerminal" in assignedItems _unit) OR ("I_UavTerminal" in assignedItems _unit) ) then {
							hint format ["No AV Terminal Assigned\nYour TGP Name:\n%1",_TGP_GroupID];
						};
					};
					if (isPlayer _unit) then {_unit disableAI "AUTOTARGET";};
					if ( (("B_UavTerminal" in assignedItems _unit) OR ("O_UavTerminal" in assignedItems _unit) OR ("I_UavTerminal" in assignedItems _unit)) && (TGP_AutoConnect > 0) ) then {
						if (TGP_AutoConnect == 1) then {
							_unit connectTerminalToUav _tgp;
						};
						if ((TGP_AutoConnect == 2) && (isNull getConnectedUav _unit) && (isPlayer _unit)) then {
							_unit connectTerminalToUav _tgp;
						};

						if (TGP_Debug == 1) then {
							[_veh] spawn {
								_veh = _this select 0;
								sleep 0.1;
								hint format ["You Are Now Connected To %1\nTGP Name: %2",group _tgp,_tgp];
							};
						};
						if (TGP_RPT_Debug == 1) then {diag_log format ["%1 Connected To TGP %2 - %3",profileName,group _tgp,_tgp];};
					};
				}forEach _tgps;
			};
			if (_ison isEqualTo true) then {
				if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Turned Off",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
				if (TGP_Numbering == 2) then {
					if (side _unit == west) then {
						TGP_CounterBLU = TGP_CounterBLU - [ (_veh getVariable "TGP_StorageBLU") ];
					};

					if (side _unit == east) then {
						TGP_CounterOPF = TGP_CounterOPF - [ (_veh getVariable "TGP_StorageOPF") ];
					};
					if (side _unit == resistance) then {
						TGP_CounterIND = TGP_CounterIND - [ (_veh getVariable "TGP_StorageIND") ];
					};
				};
				if (getConnectedUav _unit == (_veh getVariable "TGP")) then {
					_unit connectTerminalToUav objNull;
				};
				deleteVehicle (gunner (_veh getVariable "TGP"));
				if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP gunner removed",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
				TGP_Uavs = TGP_Uavs - [(_veh getVariable "TGP")];
				publicVariable "TGP_Uavs";
				if (isPlayer _unit) then {_unit enableAI "AUTOTARGET";};
			};
		};
	};

	if (TGP_Veh_Only == 1) then {
		if (_veh != _unit) then {
			_i = _veh call TGP_fnc_inList;
			if (_i > -1) then {
				_tgps = (TGP_config select _i) select 1;
				_ison = _veh getVariable [TGP_varname,false];
				if (_ison) then {
					if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Turned On",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
					if (count TGP_Uavs == 0) then {
						{
							if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP creating TGP for %3",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'),name _unit];};
							if ((side _unit == west) && (TGP_Veh_Only == 1)) then {
									_tgp = TGP_BLU_TGP createVehicleLocal [0,0,0];
									_veh setVariable ["TGP",_tgp,true];
									_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
									if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
									_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);
									createVehicleCrew _tgp;
									(group _tgp) setGroupId ["Targeting Pod"];
									_tgp deleteVehicleCrew driver _tgp;
									TGP_Uavs pushBack _tgp;
							};
							if ((side _unit == east) && (TGP_Veh_Only == 1)) then {
									_tgp = TGP_OPF_TGP createVehicleLocal [0,0,0];
									_veh setVariable ["TGP",_tgp,true];
									_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
									if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
									_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);
									createVehicleCrew _tgp;
									(group _tgp) setGroupId ["Targeting Pod"];
									_tgp deleteVehicleCrew driver _tgp;
									TGP_Uavs pushBack _tgp;
							};
							if ((side _unit == resistance) && (TGP_Veh_Only == 1)) then {
									_tgp = TGP_IND_TGP createVehicleLocal [0,0,0];
									_veh setVariable ["TGP",_tgp,true];
									_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
									if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
									_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);
									createVehicleCrew _tgp;
									(group _tgp) setGroupId ["Targeting Pod"];
									_tgp deleteVehicleCrew driver _tgp;
									TGP_Uavs pushBack _tgp;
							};
							if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Units created",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
						}forEach _tgps;
					};
				} else {
					if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP Turned Off deleting ...",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
					{
						TGP_Uavs = TGP_Uavs - [ _x ];
						if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP deleting TGP for %3 because it is off",attachedTo _x,getText (configFile >> 'cfgVehicles' >> typeOf (attachedTo _x) >> 'displayName'),name _unit];};
						deleteVehicle _x;
					}forEach TGP_Uavs;
				};
			};
		} else {
			{
				TGP_Uavs = TGP_Uavs - [ _x ];
				if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP deleting TGP for %3 because he is not in a vehicle",attachedTo _x,getText (configFile >> 'cfgVehicles' >> typeOf (attachedTo _x) >> 'displayName'),name _unit];};
				deleteVehicle _x;
			}forEach TGP_Uavs;
		};
	};
};

TGP_fnc_Do_Start = {
	_unit = _this select 0;
	_veh = vehicle _unit;
	_veh setVariable ["TGP",objNull];

	_i = _veh call TGP_fnc_InList;
	if (_i <= -1) exitWith { if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 - Not found in TGP_config when using TGP_fnc_Do_Start", _veh, (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')]; }; };
	_tgps = (TGP_config select _i) select 1;
	{
		_tgp = objNull;
		_tgp = switch ([_veh] call TGP_fnc_getCfgSide) do
		{
			case 0: { TGP_OPF_TGP createVehicle [0,0,0]; };
			case 1: { TGP_BLU_TGP createVehicle [0,0,0]; };
			case 2: { TGP_IND_TGP createVehicle [0,0,0]; };
		};
		//if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 - %3 created at %4", _unit, _veh, _tgp, position _tgp] };
		_tgp setDamage 0;
		if (TGP_RPT_Debug == 1) then { diag_log format ["%1 - %2 - %3 created with %4", _veh, getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName'), _tgp, damage _tgp] };
		_veh setVariable ["TGP",_tgp,true];
		_tgpvisible = if (count (TGP_config select _i) > 3) then { ((TGP_config select _i) select 3) } else { false };
		if ((TGP_Visible isEqualto 0) OR (_veh getVariable ["TGP_Visible",false]) OR (_tgpvisible)) then { _tgp hideObjectGlobal true };
		_tgp attachTo ([_veh,(_x select 0)] call TGP_fnc_getAttachToStuff);

		_tgpname = format ["TGP_%1",count TGP_UavNo];
		_tgp setVehicleVarName _tgpname;
		_tgp setName _tgpname;
		TGP_UavNo pushBack _tgpname;
		publicVariable "TGP_UavNo";
		TGP_Uavs pushBack _tgp;
		publicVariable "TGP_Uavs";
		missionNamespace setVariable [_tgpname,_tgp];
		publicVariable _tgpname;

		[_tgp] spawn TGP_fnc_Uav_Death;
	}forEach _tgps;

	if ((TGP_Auto_Start == 2) && ((_veh getVariable [TGP_varname,false]) isEqualTo false)) then {
		if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 - Auto-Started TGP",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
		[_veh] spawn TGP_fnc_Do_Stuff;
	};
};

TGP_fnc_camCreate = {
	_this params [["_unit",player],["_kilit",false]];
	if (_kilit && !(isNil {_unit getVariable "TGP_PIP"})) exitWith { (_unit getVariable "TGP_PIP") cameraEffect ["terminate","back"]; camDestroy (_unit getVariable "TGP_PIP"); _unit setVariable ["TGP_PIP",nil,true]; };
	if (!isNull (_unit getVariable ["TGP_PIP",objNull])) exitWith {hint "Camera already created!"};
	_cam = "camera" camCreate [0,0,0];
	_unit setVariable ["TGP_PIP",_cam,true];
	_cam camCommit 0;
	_cam camCommitPrepared 0;

	_cam cameraEffect ["internal","back","rendertargetpod"];
	"rendertargetpod" setPiPEffect (_veh getVariable ["TGP_PIP_Mode",[2]]);
	if (isNil {_veh getVariable "TGP_PIP_Mode"}) then {	_veh setVariable ["TGP_PIP_Mode",[[[0],[1],[2],[3,1,1,0.4,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]],[7]],2],true]; "rendertargetpod" setPiPEffect [2];} else { "rendertargetpod" setPiPEffect ((_veh getVariable "TGP_PIP_Mode" select 0) select ((_veh getVariable "TGP_PIP_Mode") select 1)); };

	_cam camSetFov (_veh getVariable ["TGP_PIP_Zoom",0.1]); // set zoom
};

TGP_fnc_PIP = {
	_this params [["_unit",player],["_2dPiP",true]];
	_veh = vehicle _unit;
	_uav = _veh getVariable "TGP";
	//if (!isNil {_veh getVariable "TGP_PIP"}) exitWith {_veh setVariable ["TGP_PIP",nil,true];};
	if (isNull (group _uav)) exitWith {hint "Turn the TPG On!"};

	_PosMem = getText (configFile >> "CfgVehicles" >> typeOf _uav >> "uavCameraGunnerPos");
	_DirMem = getText (configFile >> "CfgVehicles" >> typeOf _uav >> "uavCameraGunnerDir");

	_cam = (_unit getVariable ["TGP_PIP",objNull]);

	if (isNull (_cam)) then {[_unit] call TGP_fnc_camCreate; _cam = (_unit getVariable "TGP_PIP")};

	/*_cam = "camera" camCreate [0,0,0];
	_cam attachTo [_uav,[0,0,0],_PosMem];
	_cam camCommit 0;
	_cam camCommitPrepared 0;


	_cam cameraEffect ["internal","back","rendertargetpod"];
	//"rendertargetpod" setPiPEffect [3,1,1,0.4,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]];
	"rendertargetpod" setPiPEffect (_veh getVariable ["TGP_PIP_Mode",[2]]);
	if (isNil {_veh getVariable "TGP_PIP_Mode"}) then {	_veh setVariable ["TGP_PIP_Mode",[[[0],[1],[2],[3,1,1,0.4,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]],[7]],2],true]; "rendertargetpod" setPiPEffect [2];} else { "rendertargetpod" setPiPEffect ((_veh getVariable "TGP_PIP_Mode" select 0) select ((_veh getVariable "TGP_PIP_Mode") select 1)); };*/

	if (_2dPiP) then {
		[_unit] spawn TGP_fnc_2DPiP;
	};

	if ((_cam in (attachedObjects _uav))) exitWith {};
	_cam attachTo [_uav,[0,0,0],_PosMem];

	//_veh setVariable ["TGP_PIP",_cam,true];

	_cam camSetFov (_veh getVariable ["TGP_PIP_Zoom",0.1]); // set zoom

	waitUntil {
		//hintSilent format ["%1", (_uav modelToWorld (_uav selectionPosition _PosMem)) distance (aimPos _uav)];
		_dir = (_uav selectionPosition _PosMem) vectorFromTo (_uav selectionPosition _DirMem);
		_cam setVectorDirAndUp [_dir,_dir vectorCrossProduct [-(_dir select 1), _dir select 0, 0]];
		// OR ((uavControl _uav select 0) == _unit)
		//((isNull (group _uav)) OR (isNull (_cam)) OR (isNil {_veh getVariable "TGP_PIP"}) OR (vehicle _unit != _veh))
		((isNull (group _uav)) OR (isNull (_cam)) OR (isNil {_unit getVariable "TGP_PIP"}) OR (vehicle _unit != _veh) OR (_unit == _veh) OR !(_cam in (attachedObjects _uav)))
	};
	/*_veh setVariable ["TGP_PIP",nil,true];
	_cam cameraEffect ["terminate","back"];
	camDestroy _cam;*/

	//hint "TGP Feed off!";
};

TGP_fnc_2DPiP = {
	_this params [["_unit",player]];
	_veh = vehicle _unit;
	_uav = _veh getVariable "TGP";
	_cam = (_unit getVariable ["TGP_PIP",objNull]);
	if ((!isNull ((findDisplay 46) displayCtrl 89979)) && (!isNull ((findDisplay 46) displayCtrl 89980))) exitWith {ctrlDelete ((findDisplay 46) displayCtrl 89979); ctrlDelete ((findDisplay 46) displayCtrl 89980)};

	with uiNamespace do {
		TGPPiP = findDisplay 46 ctrlCreate ["RscPicture", 89979];
		//TGPPiP ctrlSetPosition [0.9,0.7,0.6,0.6];
		TGPPiP ctrlSetPosition [
			0.665 * safezoneW + safezoneX,
			0.61 * safezoneH + safezoneY,
			0.2475 * safezoneW,
			0.33 * safezoneH
		];
		TGPPiP ctrlCommit 0;
		TGPPiP ctrlSetText "#(argb,512,512,1)r2t(rendertargetpod,1.0)";

		TGPPiP_Fired = findDisplay 46 ctrlCreate ["RscStructuredText", 89980];
		TGPPiP_Fired ctrlSetPosition [
			0.670156 * safezoneW + safezoneX,
			0.621 * safezoneH + safezoneY,
			0.139219 * safezoneW,
			0.044 * safezoneH
		];
		TGPPiP_Fired ctrlCommit 0;
		TGPPiP_Fired ctrlSetStructuredText parseText "<t color='#FF0000'>Loading</t>";
	};

	_veh setVariable ["TGP_current_PiPs",[true] + [((_veh getVariable ["TGP_current_PiPs",[false,false]]) select 1)],true];

	waitUntil {
		if (!isNull laserTarget (_uav)) then {(uiNamespace getVariable "TGPPiP_Fired") ctrlSetStructuredText parseText "<t color='#FF0000'>Laser On</t>";} else {(uiNamespace getVariable "TGPPiP_Fired") ctrlSetStructuredText parseText "<t color='#FF0000'>Laser Off</t>";};
		((isNull (group _uav)) OR (isNull (_cam)) OR (isNil {_unit getVariable "TGP_PIP"}) OR (vehicle _unit != _veh) OR (_unit == _veh) OR (isNull ((findDisplay 46) displayCtrl 89979)) OR (isNull ((findDisplay 46) displayCtrl 89980)) OR !(_cam in (attachedObjects _uav)))
	};
	ctrlDelete (uiNamespace getVariable "TGPPiP");
	ctrlDelete (uiNamespace getVariable "TGPPiP_Fired");
	_veh setVariable ["TGP_current_PiPs",[false] + [((_veh getVariable ["TGP_current_PiPs",[false,false]]) select 1)],true];
};

TGP_fnc_MFDPIP = {
	_this params [["_unit",player],["_2dPiP",true]];
	_veh = vehicle _unit;
	_tgp = _veh getVariable "TGP";
	if (isNull (group _tgp)) exitWith {hint "Turn the TPG On!"};
	_i = _veh call TGP_fnc_inList;
	_zselections = TGP_config select _i select 4;
	if ((count _zselections) < 1) exitWith { hint ("No selections defined in TGP_config for " + str(typeOf _veh) + "!") };
	_selections = [];
	{
		_ex = _x;
		switch (typeName _ex) do
		{
			case "STRING" : {
				_vehtextures = getArray (configFile >> 'cfgVehicles' >> typeOf _veh >> "hiddenSelections");
				{
					if (_ex isEqualto (toLower _x)) then { _selections pushBack _forEachIndex; };
				}forEach _vehtextures;
				if ((count _selections) < 1) exitWith {
					systemChat (_ex + " was not found in the hiddenSelections");
					if (true) exitWith { _selections pushBack -1; };
				};
			};
			case "SCALAR" : {
				_vehtextures = getArray (configFile >> 'cfgVehicles' >> typeOf _veh >> "hiddenSelections");
				{
					if (_ex >= (count _vehtextures)) exitWith { _selections pushBack -1; systemChat (str(_ex) + "was too big to be found from anarray 	with" + str(count _vehtextures)) };
					if (true) exitWith { _selections pushBack _ex; };
				}forEach _vehtextures;
			};
			default { _selections pushBack -1; };
		};
	}forEach _zselections;
	if (-1 in _selections) exitWith { hint ("Selection was not found in " + str(typeOf _veh) + "!") };
	_veh setVariable ["TGP_current_PiPs",[((_veh getVariable ["TGP_current_PiPs",[false,false]]) select 0)] + [true],true];
	null = [_unit,_2dPiP] spawn TGP_fnc_PIP;
	if (count (_veh getVariable ["TGP_MFD_Old_Textures",[]]) > 0) exitWith {
		{
			_selectioner = _x;
			{
				_veh setObjectTextureGlobal [_selectioner,_x];
			}forEach (_veh getVariable ["TGP_MFD_Old_Textures",[]]);
		}forEach _selections;
		_veh setVariable ["TGP_MFD_Old_Textures",[],true];
		_veh setVariable ["TGP_current_PiPs",[((_veh getVariable ["TGP_current_PiPs",[false,false]]) select 0)] + [false],true];
	};
	_veh setVariable ["TGP_MFD_Old_Textures",[],true];
	_oldTextures = getObjectTextures _veh;
	{ _veh setObjectTextureGlobal [_x,"#(argb,512,512,1)r2t(rendertargetpod,1.0)"]; _veh setVariable ["TGP_MFD_Old_Textures",(_veh getVariable ["TGP_MFD_Old_Textures",[]]) + [_oldTextures select _x],true] }forEach _selections;
	waitUntil { (vehicle _unit != _veh) && (count (_veh getVariable ["TGP_MFD_Old_Textures",[]]) > 0) };
	if (count (_veh getVariable ["TGP_MFD_Old_Textures",[]]) > 0) exitWith {
		{
			_selectioner = _x;
			{
				_veh setObjectTextureGlobal [_selectioner,_x];
			}forEach (_veh getVariable ["TGP_MFD_Old_Textures",[]]);
		}forEach _selections;
		_veh setVariable ["TGP_MFD_Old_Textures",[],true];
		_veh setVariable ["TGP_current_PiPs",[((_veh getVariable ["TGP_current_PiPs",[false,false]]) select 0)] + [false],true];
	};
};

TGP_fnc_trackHead = {
	_this params [["_unit",player]];
	_veh = vehicle _unit;
	_uav = _veh getVariable "TGP";
	if (isNull (group _uav)) exitWith {hint "Turn the TPG On!"};
	if (!isNil {_veh getVariable "TGP_trackHead"}) exitWith {_veh setVariable ["TGP_trackHead",nil,true];};
	hint "TGP Head tracking on";
	_veh setVariable ["TGP_trackHead",true,true];
	waitUntil {
		[_uav,(screenToWorld [0.5,0.5])] call TGP_fnc_setCameraDirection;
		((isNull (group _uav)) OR (isNil {_veh getVariable "TGP_trackHead"}) OR (vehicle _unit != _veh))
	};
	hint "TGP Head tracking off";
};

TGP_fnc_PIPMode = {
	if ((vehicle player getVariable [TGP_varname,false] isEqualTo true)  && (vehicle player call TGP_fnc_inList > -1) && (!isNil {vehicle player getVariable "TGP_PIP_Mode"}) && (!isNil {player getVariable "TGP_PIP"}) && (((vehicle player getVariable ["TGP_current_PiPs",[false,false]]) find true) > -1)) then {
		_modes = vehicle player getVariable "TGP_PIP_Mode";
		_allmodes = _modes select 0;
		_current = _modes select 1;
		"rendertargetpod" setPiPEffect [3,0,1,0.4,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]];
		sleep 0.001;
		if ((count _allmodes - 1) == _current) then {
			"rendertargetpod" setPiPEffect (_allmodes select 0);
			vehicle player setVariable ["TGP_PIP_Mode",[_allmodes] + [0],true];
		} else {
			"rendertargetpod" setPiPEffect (_allmodes select (_current + 1));
			vehicle player setVariable ["TGP_PIP_Mode",[_allmodes] + [_current + 1],true];
		};
		switch (str (_allmodes select ((vehicle player getVariable "TGP_PIP_Mode") select 1))) do
		{
			case "[0]": {hint "PiP Colour Mode"};
			case "[1]": {hint "PiP Night Vision Mode"};
			case "[2]": {hint "PiP White Hot Thermal Mode"};
			case "[3,1,1,0.4,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]]": {hint "PiP TV Mode"};
			case "[7]": {hint "PiP Black Hot Themal Mode"};
			default {hint "PiP Unkown mode"};
		};
	};
};

TGP_fnc_getCfgSide = {
	private "_veh";
	//0 - Opfor
	//1 - Blufor
	//2 - Resistance
	//3 - Civilian
	_veh = _this select 0;
	if (isNil {_veh}) exitWith {3};
	getNumber (configfile >> 'cfgVehicles' >> typeOf _veh >> 'side');
};

TGP_fnc_forceLaserFire = {
	private ["_unit","_veh","_tgp","_weapons","_laserindex","_laser"];
	_this params [["_unit",player]];
	_veh = vehicle _unit;
	_tgp = _veh getVariable ["TGP",objNull];
	if (isNull (group _tgp)) exitWith {hint "Turn the TPG On!"};
	_weapons = weapons _tgp;
	_laserindex = -1;

	{
		if ((toLower _x find 'laser') > -1) exitWith {_laserindex = _forEachIndex};
	}forEach _weapons;

	_laser = _weapons select _laserindex;
	if (!isNil {_laser}) then {
		(gunner _tgp) forceWeaponFire [_laser,_laser];
	};
};

TGP_fnc_setCameraDirection = {
	private ["_tgp","_targetpos"];
	_this params [["_tgp",objNull],["_targetpos",nil]];
	if (isNull (_tgp)) exitWith {hint "TGP Not Found!"};
	if (isNull (group _tgp)) exitWith {hint "Turn the TPG On!"};
	if (isNil "_targetpos") exitWith {hint "Second Paramater Not Defined!"};

	switch (typeName(_targetpos)) do {
	    case "OBJECT" : { _tgp lockCameraTo [_targetpos,[0]]; _tgp setVariable ["TGP_CurrentTarget",_targetpos,true]; };
	    case "ARRAY" : { _tgp lockCameraTo [_targetpos,[0]]; _tgp setVariable ["TGP_CurrentTarget",_targetpos,true]; };
	    default { hint 'nothing found to lock to'; };
	};

	if (typeName (_tgp getVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5])]) isEqualto "OBJECT") then {
		if (isNull (_tgp getVariable ["TGP_CurrentTarget",objNull])) then { _tgp setVariable ["TGP_CurrentTarget",nil,true]; };
	};
};

TGP_fnc_cameraMoveDirection = {
	private ["_unit","_direction","_veh","_tgp","_posmove"];
	_this params [["_unit",player],["_direction",null]];
	_veh = vehicle _unit;
	_tgp = _veh getVariable "TGP";
	if (isNull (group _tgp)) exitWith {hint "Turn the TPG On!"};
	if (typeName (_tgp getVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5])]) isEqualto "OBJECT") then
	{
		if (isNull (_tgp getVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5])])) then
		{
			_tgp setVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5]),true];
		} else {
		_tgp setVariable ["TGP_CurrentTarget",getPosASLVisual (_tgp getVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5])]),true];
		};
	};
	_posmove = (_tgp getVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5])]);
	switch (toLower(_direction)) do {
	    case 'up': { [_tgp,[(_posmove select 0) + (sin(round(getDir vehicle player)) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 1) + (cos(round(getDir vehicle player)) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    //case 'up': { [_tgp,[(_posmove select 0), (_posmove select 1) + (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    case 'down': { [_tgp,[(_posmove select 0) + (sin((round(getDir vehicle player)) + 180) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 1) + (cos((round(getDir vehicle player)) + 180) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    //case 'down': { [_tgp,[(_posmove select 0), (_posmove select 1) - (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    case 'right': { [_tgp,[(_posmove select 0) + (sin((round(getDir vehicle player)) + 90) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 1) + (cos((round(getDir vehicle player)) + 90) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    //case 'right': { [_tgp,[(_posmove select 0) + (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2), (_posmove select 1), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    case 'left': { [_tgp,[(_posmove select 0) + (sin((round(getDir vehicle player)) - 90) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 1) + (cos((round(getDir vehicle player)) - 90) * (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2)), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };
	    //case 'left': { [_tgp,[(_posmove select 0) - (10 * (_veh getVariable ["TGP_PIP_Zoom",0.1]) * 2), (_posmove select 1), (_posmove select 2)]] call TGP_fnc_setCameraDirection; };

	    default { hint 'unable to find direction to go into'; };
	};
	hint format ["TGP Locked to Grid: %1",mapGridPosition (_tgp getVariable ["TGP_CurrentTarget",(screenToWorld[0.5,0.5])])];
};

TGP_fnc_lockCameraGridPos = {
	_this params [["_unit",player]];
	_veh = vehicle _unit;
	_tgp = _veh getVariable "TGP";
	if (isNull (group _tgp)) exitWith {hint "Turn the TPG On!"};
	if (_unit getVariable ["TGP_MapClickCameraGridPosLockPlayerDone",false]) exitWith { hint "You're already in the Map to set Grid! Please exit" };
	_unit setVariable ["TGP_MapClickCameraGridPosLockPlayerDone",false,true];
	openMap [true,false];
	waitUntil { visibleMap };
	["TGP_MapClickCameraGridPosLock", "onMapSingleClick",
	{
		hint format ["TGP Locked to Grid: %1",mapGridPosition _pos]; [(vehicle player) getVariable ["TGP",objNull],ATLtoASL _pos] call TGP_fnc_setCameraDirection; player setVariable ["TGP_MapClickCameraGridPosLockPlayerDone",true,true];
	}] spawn bis_fnc_addStackedEventHandler;
	if (!isNil {_tgp getVariable "TGP_CurrentTarget"}) then
	{
		_lemarker = createMarkerLocal ["TGP_AimingPos", _tgp getVariable "TGP_CurrentTarget"];
		_lemarker setMarkerShape "ICON";
		_lemarker setMarkerType "mil_dot";
		_lemarker setMarkerText "TGP Current Aim Position";
	};
	waitUntil { (_unit getVariable ["TGP_MapClickCameraGridPosLockPlayerDone",false]) OR !visibleMap };
	openMap [false,false];
	_unit setVariable ["TGP_MapClickCameraGridPosLockPlayerDone",nil,true];
	["TGP_MapClickCameraGridPosLock", "onMapSingleClick"] spawn bis_fnc_removeStackedEventHandler;
	if (!((markerColor "TGP_AimingPos") isEqualto "")) then
	{
		deleteMarker "TGP_AimingPos";
	};
};

TGP_fnc_addAction = {
	if (isNil {player getVariable "uavadded"} ) then {

		if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Adding TGP addActions to %1-%2",player, name player]; };
		_tgpon = player addAction [TGP_text_ON,{[(_this select 0)] spawn TGP_fnc_Select_Veh_Only},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions2'];

		_tgplock = player addAction [TGP_text_Lock, {[((vehicle (_this select 0)) getVariable "TGP"),cursorTarget] call TGP_fnc_setCameraDirection; if (isNull cursorTarget) then {hint "Lock Removed"} else {hint format ["TGP Locked to %1",getText (configFile >> 'cfgVehicles' >> typeOf cursorTarget >> 'displayName')]}},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions3'];

		_tgpuse = player addAction [TGP_text_Use,{vehicle (_this select 0) switchCamera "Internal"; (_this select 0) action ["SwitchToUAVGunner", (vehicle (_this select 0) getVariable "TGP")]; (_this select 0) disableAI "AUTOTARGET"; enableCamShake false; waitUntil { isNull (uavControl (vehicle (_this select 0) getVariable "TGP") select 0) }; enableCamShake true;},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions3'];

		_tgppip = player addAction [TGP_text_PiP, {[(_this select 0)] spawn TGP_fnc_PIP},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions3'];

		_tgpmfdpip = player addAction [TGP_text_mfdpip, {[(_this select 0),false] spawn TGP_fnc_MFDPIP},"",-99,false,true,"",'[_this,_target,true,true] call TGP_fnc_Conditions3'];

		_tgpTGTPos = player addAction [TGP_text_setTGPTGTPos, {[(_this select 0)] spawn TGP_fnc_lockCameraGridPos},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions3'];

		_tgptrack = player addAction [TGP_text_headTrack, {[(_this select 0)] spawn TGP_fnc_trackHead},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions3'];

		_tgpoff = player addAction [TGP_text_Off,{[(_this select 0)] spawn TGP_fnc_Select_Veh_Only},"",-99,false,true,"",'[_this,_target] call TGP_fnc_Conditions'];

		player setVariable ["uavadded",[_tgpon,_tgplock,_tgpuse,_tgppip,_tgpmfdpip,_tgpTGTPos,_tgptrack,_tgpoff],true];

		if (isClass (configfile >> "CfgPatches" >> "cba_keybinding")) then {
			if ((parsenumber (getText(configfile >> "CfgPatches" >> "cba_main_a3" >> "version")) > 1)) then {
				/*if (count (player getVariable ["TGP_cbaKeyBinds_TempFix",[]]) > 0) then
				{
					{
						if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Executing Temporary Key binding fix for %1",_x]; };
						["Targeting Pod", _x, ["TGP TEMP FIX", "TGP TEMP FIX"], {  }, {  }, [20, [false,false, false]], nil, nil, false] call cba_fnc_addKeybind;
					}forEach (player getVariable ["TGP_cbaKeyBinds_TempFix",[]]);
				};*/
				if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Adding TGP CBA Keybinds to %1-%2",player, name player]; };
				//_tgplockkey = ["Targeting Pod", "Toggle Lock", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle player 	call 	TGP_fnc_inList > -1 && (uavControl (vehicle player getVariable 'TGP') select 1 != 'GUNNER')) then {((vehicle player) getVariable 	"TGP") 	lockCameraTo [cursorTarget,[0]]; if (isNull cursorTarget) then {hint "Lock Removed"} else {hint format ["TGP Locked to 	%1",getText (configFile	 >> 'cfgVehicles' >> typeOf cursorTarget >> 'displayName')]}}}, [20, [false, false, false]], false, "keydown"] 	call cba_fnc_registerKeybind;

				_tgplockkey = ["Targeting Pod", "TGPToggleLock", ["Toggle Lock", "When the cursorTarget finds an object press this and the TGP will lock"]	, {if ([player,(vehicle player)] call TGP_fnc_Conditions3) then {[((vehicle player) getVariable "TGP"),cursorTarget] call TGP_fnc_setCameraDirection; if (isNull cursorTarget) then {hint "Lock Removed"} else {hint format ["TGP Locked to %1",getText (configFile	 >> 'cfgVehicles' >> 	typeOf cursorTarget >> 'displayName')]}}}, { }, [20, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockuse = ["Targeting Pod", "Enter TGP View", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle player 	call 	TGP_fnc_inList > -1 && (uavControl (vehicle player getVariable 'TGP') select 1 != 'GUNNER')) then {vehicle player switchCamera 	"Internal"; 	player action ["SwitchToUAVGunner", (vehicle player getVariable "TGP")]; player disableAI "AUTOTARGET";}}, [35, [false, 	false, false]], false	, "keydown"] call cba_fnc_registerKeybind;

				_tgplockuse = ["Targeting Pod", "TGPEnterTGPView", ["Enter TGP View", "Switches the controls over to the TGP and into first person"], {if (	[player,(vehicle player)] call TGP_fnc_Conditions3) then {vehicle player switchCamera "Internal"; player action ["SwitchToUAVGunner", (vehicle player getVariable "TGP")]; player disableAI "AUTOTARGET"; enableCamShake false;}}, { }, [35, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockexit = ["Targeting Pod", "Exit TGP View", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle player 	call TGP_fnc_inList > -1 && ((uavControl (vehicle player getVariable 'TGP') select 1 == 'GUNNER') && (uavControl (vehicle player 	getVariable 'TGP') select 0 == player)) ) then {vehicle player switchCamera "Internal"; (vehicle player getVariable 'TGP') action [	"BackFromUAV", player]; player enableAI "AUTOTARGET";}}, [36, [false, false, false]], false, "keyup"] call cba_fnc_registerKeybind;

				_tgplockexit = ["Targeting Pod", "TGPExitTGPView", ["Exit TGP View", "Switches back into the plane controls"], { }, {if (([player,(vehicle player),false] call TGP_fnc_Conditions3) && ((uavControl (vehicle player getVariable 'TGP') select 1 == 'GUNNER') && (	uavControl (vehicle player getVariable 'TGP') select 0 == player)) ) then {vehicle player switchCamera "Internal"; (vehicle player	getVariable 'TGP') action ["BackFromUAV", player]; player enableAI "AUTOTARGET"; enableCamShake true;}}, [36, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockpip = ["Targeting Pod", "PiP Toggle", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle player call 	TGP_fnc_inList > -1 ) then {[player] spawn TGP_fnc_PIP}}, [55, [false, false, false]], false, "KeyDown"] call cba_fnc_registerKeybind;

				_tgplockpip = ["Targeting Pod", "TGPPiPToggle", ["PiP Toggle", "Toggles between the PiP on and off"], {if ( ([player,(vehicle player)] call	 TGP_fnc_Conditions3) ) then {[player] spawn TGP_fnc_PIP}}, { }, [55, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockpipzoomin = ["Targeting Pod", "PiP Zoom In", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle 	player call TGP_fnc_inList > -1 ) then {_zoom = ((vehicle player getVariable ["TGP_PIP_Zoom",0.1]) * 0.5); if (_zoom < 0.01) then {_zoom = 	0.01}; (vehicle player getVariable "TGP_PIP") camSetFov _zoom; vehicle player setVariable ["TGP_PIP_Zoom",_zoom,true];}}, [78, [false, 	false, false]], false, "KeyDown"] call cba_fnc_registerKeybind;

				_tgplockpipzoomin = ["Targeting Pod", "TGPPiPZoomIn", ["PiP Zoom In", "Zooms in the PiP screen"], {if (([player,(vehicle player),false] call TGP_fnc_Conditions3) && (((vehicle player getVariable ["TGP_current_PiPs",[false,false]]) find true) > -1)) then {_zoom = ((vehicle player getVariable ["TGP_PIP_Zoom",0.1]) * 0.5); if (_zoom < 0.01) then {_zoom = 0.01}; (player getVariable "TGP_PIP") camSetFov _zoom; vehicle player setVariable ["TGP_PIP_Zoom",_zoom,true];}}, { }, [78, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockpipzoomout = ["Targeting Pod", "PiP Zoom Out", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle 	player call TGP_fnc_inList > -1 ) then {_zoom = ((vehicle player getVariable ["TGP_PIP_Zoom",0.1]) / 0.5); if (_zoom > 1) then {_zoom = 	1}; (vehicle player getVariable "TGP_PIP") camSetFov _zoom; vehicle player setVariable ["TGP_PIP_Zoom",_zoom,true];}}, [74, [false, false, 	false]], false, "KeyDown"] call cba_fnc_registerKeybind;

				_tgplockpipzoomout = ["Targeting Pod", "TGPPiPZoomOut", ["PiP Zoom Out", "Zooms out the PiP screen"], {if (([player,(vehicle player),false] call TGP_fnc_Conditions3) && (((vehicle player getVariable ["TGP_current_PiPs",[false,false]]) find true) > -1)) then {_zoom = ((vehicle player getVariable ["TGP_PIP_Zoom",0.1]) / 0.5); if (_zoom > 1) then {_zoom = 1}; (player getVariable "TGP_PIP") camSetFov _zoom; vehicle player setVariable ["TGP_PIP_Zoom",_zoom,true];}}, { }, [74, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockpipmode = ["Targeting Pod", "PiP Mode", {[] spawn TGP_fnc_PIPMode;}, [55, [false, false, false]], false, "KeyDown"] call 	cba_fnc_registerKeybind;

				_tgplockpipmode = ["Targeting Pod", "TGPPiPMode", ["PiP Mode", "Toggles through all PiP modes"], {[] spawn TGP_fnc_PIPMode;}, { }, [83, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgplockhead = ["Targeting Pod", "Head Tracking Toggle", {if (vehicle player getVariable [TGP_varname,false] isEqualTo true  && vehicle 	player call TGP_fnc_inList > -1 ) then {[player] spawn TGP_fnc_PIP}}, [181, [false, false, false]], false, "KeyDown"] call 	cba_fnc_registerKeybind;

				_tgplockhead = ["Targeting Pod", "TGPPiPLockHead", ["Head Tracking Toggle", "Toggles on and off Head Tracking Mode"], {if ( ([player,(vehicle player)] call TGP_fnc_Conditions3) ) then {[player] spawn TGP_fnc_trackHead}}, { }, [181, [false, false, false]],nil, nil, false] call cba_fnc_addKeybind;

				//_tgpkeyfired = ["Targeting Pod", "Fire TGP Laser", {[player] spawn TGP_fnc_forceLaserFire;}, [20, [false, true, false]], false, "KeyDown"	] call cba_fnc_registerKeybind;

				_tgpkeyfired = ["Targeting Pod", "TGPPiPLaserFire", ["Fire TGP Laser", "Toggles on and off TGP Laser"], {if ([player,(vehicle player)] call TGP_fnc_Conditions3) then {[player] spawn TGP_fnc_forceLaserFire;};}, { }, [20, [false, true, false]],nil, nil, false] call cba_fnc_addKeybind;

				_tgpkeyup = ["Targeting Pod", "TGPMoveUp",["TGP Up","Moves TGP camera in the up direction"], { if ([player,(vehicle player)] call TGP_fnc_Conditions3) then { [player,'up'] call TGP_fnc_cameraMoveDirection } }, { }, [39,[false,false,false]],nil, nil, false] call cba_fnc_addKeybind;

				_tgpkeydown = ["Targeting Pod", "TGPMoveDown",["TGP Down","Moves TGP camera in the down direction"], { if ([player,(vehicle player)] call TGP_fnc_Conditions3) then { [player,'down'] call TGP_fnc_cameraMoveDirection } }, { }, [52,[false,false,false]],nil, nil, false] call cba_fnc_addKeybind;

				_tgpkeyright = ["Targeting Pod", "TGPMoveRight",["TGP Right","Moves TGP camera in the right direction"], { if ([player,(vehicle player)] call TGP_fnc_Conditions3) then { [player,'right'] call TGP_fnc_cameraMoveDirection } }, { }, [53,[false,false,false]],nil, nil, false] call cba_fnc_addKeybind;

				_tgpkeyup = ["Targeting Pod", "TGPMoveLeft",["TGP Left","Moves TGP camera in the left direction"], { if ([player,(vehicle player)] call TGP_fnc_Conditions3) then { [player,'left'] call TGP_fnc_cameraMoveDirection } }, { }, [51,[false,false,false]],nil, nil, false] call cba_fnc_addKeybind;
				player setVariable ["TGP_cbaKeyBinds_TempFix",["TGPToggleLock","TGPEnterTGPView","TGPExitTGPView","TGPPiPToggle","TGPPiPZoomIn","TGPPiPZoomOut","TGPPiPMode","TGPPiPLockHead","TGPPiPLaserFire","TGPMoveUp","TGPMoveDown","TGPMoveRight","TGPMoveLeft"],true];
				//player setVariable ["TGP_cbaKeyBinds",["TGPToggleLock","TGPEnterTGPView","TGPExitTGPView","TGPPiPToggle","TGPPiPZoomIn","TGPPiPZoomOut","TGPPiPMode","TGPPiPLockHead","TGPPiPLaserFire","TGPMoveUp","TGPMoveDown","TGPMoveRight","TGPMoveLeft"],true];
			} else {
				systemChat "Targeting Pod: CBA not updated! Keybindings will not work";
				diag_log "TGP: CBA not updated! Keybindings will not work";
			};
		} else {
			systemChat "Targeting Pod: CBA Missing! Keybindings will not work";
			diag_log "TGP: CBA Missing! Keybindings will not work";
		};

		if (TGP_RPT_Debug == 1) then {diag_log format ["%1 TGP Actions Added",player];};
	};
};

Lala_fnc_TGPadd = {
	_this params [["_isthisfistlaunch",false]];
	if (missionNamespace getVariable ["TGP_kill",false]) exitWith {diag_log format ["TGP - TGP Loop killed at %1",time]; null = [] spawn Lala_fnc_TGPKill;};
	_currentcountveh = count vehicles;
	waitUntil {sleep 0.1; (count vehicles != _currentcountveh) OR _isthisfistlaunch OR (missionNamespace getVariable ["TGP_kill",false])};
	if (missionNamespace getVariable ["TGP_kill",false]) exitWith {diag_log format ["TGP - TGP Loop killed at %1",time]; null = [] spawn Lala_fnc_TGPKill;};
	{ if ( (_x call TGP_fnc_inList > -1) && ( isNil {_x getVariable "TGP"} ) &&  (TGP_Veh_Only == 0) && ( isNil {_x getVariable TGP_varname} OR {_x getVariable "uavisalive" isEqualTo 'display'} ) ) then {
			if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 - creating TGP",_x,getText (configFile >> 'cfgVehicles' >> typeOf _x >> 'displayName')];};
			[_x] call TGP_fnc_Do_Start;
		};
	}forEach vehicles;

	if (TGP_Auto_Ai_On == 1) then {
		{
			if ((vehicle _x != _x) && ((vehicle _x) call TGP_fnc_inList > -1) && ( !isNil {vehicle _x getVariable "TGP"} ) && ((vehicle _x getVariable [TGP_varname,false]) isEqualTo false) ) then {
				_veh = vehicle _x;
				if (isNil {_veh getVariable "uavadded"} && !(isPlayer _x)) then {
					_veh setVariable ["uavadded",true,true];
					if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 TGP - AI Start - variable added",_veh,getText (configFile >> 'cfgVehicles' >> typeOf _veh >> 'displayName')];};
					[(driver _veh)] spawn TGP_fnc_Do_Stuff;
					if (!isNull (commander _veh)) then {
						(commander _veh) enableAI "AUTOTARGET";
						if (TGP_RPT_Debug == 1) then {diag_log format ["%1 TGP - AI enableAI AUTOTARGET",(commander _veh)];};
					};
					if (!isNull (driver _veh)) then {
						(driver _veh) enableAI "AUTOTARGET";
						if (TGP_RPT_Debug == 1) then {diag_log format ["%1 TGP - AI enableAI AUTOTARGET",(driver _veh)];};
					};
					if (!isNull (gunner _veh)) then {
						(gunner _veh) enableAI "AUTOTARGET";
						if (TGP_RPT_Debug == 1) then {diag_log format ["%1 TGP - AI enableAI AUTOTARGET",(gunner _veh)];};
					};
				};
			};
		} forEach allUnits;
	};

	if (TGP_Debug == 1) then {systemChat "TGP_Debug - A Vehicle was Added/Removed";};

	if (TGP_RPT_Debug == 1) then {diag_log format ["TGP - Time Since Start %1 Seconds",time];};
	if (missionNamespace getVariable ["TGP_kill",false]) exitWith {diag_log format ["TGP - TGP Loop killed at %1",time]; null = [] spawn Lala_fnc_TGPKill;};
	[false,false] spawn Lala_fnc_TGPadd;
};

Lala_fnc_TGPKill = {
	if (!(missionNamespace getVariable ["TGP_kill",false])) exitWith { diag_log (("TGP - Lala_fnc_TGPKill was executed at ") + str(time) + (" without TGP_kill being set to false! Operation was not run!")); };
	{
		if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Removing %1 because of restart",_x]; };
		(attachedTo _x) setVariable ["TGP",nil,true];
		(attachedTo _x) setVariable ["TGP_conditionextraresults",nil,true];
		(attachedTo _x) setVariable ["TGP_conditionextraresultsstuff",nil,true];
		deleteVehicle _x;
	}forEach TGP_Uavs;
	TGP_Uavs = [];
	publicVariable "TGP_Uavs";
	{
		if (isPlayer _x) then
		{
			if ((count (_x getVariable ["uavadded",[]])) > 0) then
			{
				_leplayer = _x;
				{

					if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Removing %1 action from %2",_x,name _leplayer]; };
					_leplayer removeAction _x;
				}forEach (_x getVariable "uavadded");
				_leplayer removeEventHandler ["Respawn",(_leplayer getVariable ["tgprespawn",-1])];
				if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Removing %1 respawn EventHandler from %2",(_leplayer getVariable ["tgprespawn",-1]),name _leplayer]; };
				_leplayer setVariable ["tgprespawn",nil,true];
				_leplayer setVariable ["uavadded",nil,true];
			};
		} else {
			if ((vehicle _x != _x) && ((vehicle _x) call TGP_fnc_inList > -1)) then
			{
				_veh = vehicle _x;
				if (!isNil {_veh getVariable "uavadded"}) then
				{
					_veh setVariable ["uavadded",nil,true];
					if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Removing AI Auto Action from %1 - %2",_x,name _x]; };
				};
			};
		};
	}forEach allUnits;
	{
		if (!isNil {_x getVariable TGP_varname}) then
		{
			if (typeName (_x getVariable TGP_varname) == "BOOL") then
			{
				if (_x getVariable TGP_varname) then
				{
					if (TGP_RPT_Debug == 1) then { diag_log format ["TGP - Shutting down TGP from %1 - %2",_x,getText (configFile >> 'cfgVehicles' >> typeOf _x >> 'displayName')]; };
					_x setVariable [TGP_varname,false,true];
				};
			};
		};
	}forEach vehicles;
	missionNamespace setVariable ["TGP_kill",nil];
	publicVariable "TGP_kill";
};

//Let's begin the script finally!
if (TGP_RPT_Debug == 1) then {diag_log format ["TGP - It took %1 ms seconds to load functions",(diag_tickTime - _tgpdiagticktimestart) * 1000];};

//if (isDedicated) exitWith { TGP_Loaded = true; };

null = [] call TGP_fnc_checkTGPConfig;
//player only stuff
if (hasInterface) then {
	[] spawn TGP_fnc_addAction;
	if (TGP_RPT_Debug == 1) then {diag_log format ["%1 TGP Action Executed",name player];};
	if ((player getVariable ["tgprespawn",-1]) < 0) then {
		_tgprespawnvar = player addEventHandler ["Respawn", {
			(_this select 0) setVariable ["uavadded",nil,true];
			[] spawn TGP_fnc_addAction;
			if (TGP_RPT_Debug == 1) then {diag_log format ["%1 TGP - Respawn - variable removed",name (_this select 0)];};
		}];
		player setVariable ["tgprespawn",_tgprespawnvar,true];
	};
};
//server only stuff for now
if ((TGP_Auto_Add_TGP == 1) && (isDedicated OR isServer)) then {
	waitUntil {time > 0};
	if (TGP_RPT_Debug == 1) then {diag_log format ["TGP Loop starting for the first time",time];};
	[true,false] call Lala_fnc_TGPadd;
};

systemChat "Targeting Pod: Loading";

if ((TGP_Auto_Start == 1) && (isDedicated OR isServer)) then {
	waitUntil {count TGP_Uavs > 0};
	{ if ( (_x call TGP_fnc_inList > -1) && ( !isNil {_x getVariable "TGP"} ) && (TGP_Veh_Only == 0) && ((_x getVariable [TGP_varname,false]) isEqualTo false) && (isNil {_x getVariable "uavadded"})) then {
			if (TGP_RPT_Debug == 1) then {diag_log format ["%1 - %2 - Auto-Started TGP",_x,getText (configFile >> 'cfgVehicles' >> typeOf _x >> 'displayName')];};
			_x setVariable ["uavadded",true,true];
			[_x] spawn TGP_fnc_Do_Stuff;
		};
	}forEach vehicles;
};

TGP_Loaded = true;
_tgpdiagticktimestop = diag_tickTime;

if (TGP_RPT_Debug == 1) then {diag_log format ["TGP - It took %1 ms seconds to load everything",(_tgpdiagticktimestop - _tgpdiagticktimestart) * 1000];};
if (TGP_RPT_Debug == 1) then {diag_log format ["TGP - Loaded at %1 mission time",time];};
if (TGP_RPT_Debug == 1) then {diag_log format ["Current TGP ver is %1",TGP_versionstr];};
diag_log "TGP Loaded";
systemChat "Targeting Pod: Initialized";
if (isDedicated) exitWith {};
waitUntil {!(isNull (findDisplay 46))};
if ((!isNull ((findDisplay 46) displayCtrl 89979)) && (!isNull ((findDisplay 46) displayCtrl 89980))) then {ctrlDelete ((findDisplay 46) displayCtrl 89979); ctrlDelete ((findDisplay 46) displayCtrl 89980)};
