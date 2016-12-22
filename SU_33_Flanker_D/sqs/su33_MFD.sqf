//Script loop created to control MFCD's on SU35
//created by: John_Spartan

Private ["_SU33"];
_SU33 = _this select 0;

/*_current_map = worldName;
if (_current_map == "Stratis") then {_SU33 setObjectTextureGlobal [12, "\js_jc_su35\data\displays\SU35_mfcd_map_stratis.paa"];_SU35 setObjectTextureGlobal [13, "\js_jc_su35\data\displays\su35_mfcd_ca.paa"];};
if (_current_map == "Altis") then {_SU33 setObjectTextureGlobal [12, "\js_jc_su35\data\displays\SU35_mfcd_map_altis.paa"];_SU35 setObjectTextureGlobal [13, "\js_jc_su35\data\displays\su35_mfcd_ca.paa"];};
*/


while {(alive _SU33)} do
{
	if ((player == driver _SU33) and (isengineon _SU33)) then
	{
		_world_size = [] call BIS_fnc_mapSize;


		_gridPosX = [(getpos _SU33) select 0,0] call BIS_fnc_cutDecimals;
		_gridPosY = [(getpos _SU33) select 1,0] call BIS_fnc_cutDecimals;

		_map_anim_x = _gridPosX/_world_size;
		_map_anim_y = _gridPosY/_world_size;

		_SU33 animate ["MFD_Displays_Map_miniplane_animX",_map_anim_x];
		_SU33 animate ["MFD_Displays_Map_miniplane_animY",_map_anim_y];


		//hintsilent format["WORLD SIZE: %1\nPOSX: %2\nPOSY: %3\nMAP ANIM X:%4\nMAP ANIM Y:%5",_world_size,_gridPosX,_gridPosY,_map_anim_x,_map_anim_y];

	};

	sleep 0.1;
};
