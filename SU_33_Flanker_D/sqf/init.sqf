
private ["_plane","_num","_num1","_num2","_scripts"];

_plane = _this select 0;

_scripts = [];
_scripts set [0, _plane execVM "\SU_33_Flanker_D\sqf\FX_Afterburner.sqf"];
_scripts set [1, _plane execVM "\SU_33_Flanker_D\sqf\FX_SonicBoom.sqf"];
_scripts set [2, _plane execVM "\SU_33_Flanker_D\sqf\FX_WingtipTrails.sqf"];
_scripts set [3, _plane execVM "\SU_33_Flanker_D\sqf\FX_FuselageVapour.sqf"];
//_scripts set [4, _plane execVM "\SU_33_Flanker_D\sqf\weapons.sqf"];
//_scripts set [5, _plane exec "\SU_33_Flanker_D\sqf\wing.sqs"];
//[_this select 0]exec ""\SU_33_Flanker_D\sqf\wing.sqs""

_plane setObjectTexture[0, "\SU_33_Flanker_D\tex\omote.paa"];
_plane setObjectTexture[1, "\SU_33_Flanker_D\tex\glass.paa"];
_plane setObjectTexture[2, "\SU_33_Flanker_D\tex\omote.paa"];

_plane setObjectTexture[3, "\SU_33_Flanker_D\num\2.paa"];
_plane setObjectTexture[4, "\SU_33_Flanker_D\num\1.paa"];

_num = (random 99);

_num1 = floor( _num / 10);
_num2 = floor( _num - (_num1 * 10 ));

switch (_num1) do
{
	case 0:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\0.paa"];
	};
	case 1:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\1.paa"];
	};
	case 2:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\2.paa"];
	};
	case 3:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\3.paa"];
	};
	case 4:
	{
		_plane setObjectTextureGlobal [0, "\SU_33_Flanker_D\num\4.paa"];
	};
	case 5:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\5.paa"];
	};
	case 6:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\6.paa"];
	};
	case 7:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\7.paa"];
	};
	case 8:
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\8.paa"];
	};

	default
	{
		_plane setObjectTextureGlobal [3, "\SU_33_Flanker_D\num\9.paa"];
	};
};

switch (_num2) do
{
	case 0:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\0.paa"];
	};
	case 1:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\1.paa"];
	};
	case 2:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\2.paa"];
	};
	case 3:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\3.paa"];
	};
	case 4:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\4.paa"];
	};
	case 5:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\5.paa"];
	};
	case 6:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\6.paa"];
	};
	case 7:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\7.paa"];
	};
	case 8:
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\8.paa"];
	};

	default
	{
		_plane setObjectTextureGlobal [4, "\SU_33_Flanker_D\num\9.paa"];
	};
};

