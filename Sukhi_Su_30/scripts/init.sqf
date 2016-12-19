// -------------------------------
// ArmA Multi-Missile Proxy Launch
// --------------------------------
// Init our local vars
_plane = _this select 0;



_planetype = typeOf _plane;
//_weapons = weapons _plane;

switch (_planetype) do
{
	case "Sukhoi_Su30":
	{
		[_plane] execVM "\Sukhi_Su-30\scripts\MKK3.sqf";

		/*for [{_i=0}, {_i< count _weapons}, {_i = _i +1}] do
		{
			switch (_weapons select _i) do
			{
				case "Aus_GSh301":
				{
					_rounds = _plane ammo "Aus_GSh301";
					_plane animate ["WeaponAmount1", _rounds];
				};
				case "Aus_S8Launcher":
				{
					_rounds = _plane ammo "Aus_S8Launcher";
					_plane animate ["WeaponAmount2", _rounds];
				};
				case "Aus_R73Launcher":
				{
					_alamcount = _plane ammo "Aus_R73Launcher";

					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot12", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot01", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot02", 1];
					};
					if (_alamcount == 0) then
					{
						_plane animate ["HideWeaponSlot11", 1];
					};
				};
				case "Aus_kb500Launcher":
				{
					_alamcount = _plane ammo "Aus_kb500Launcher";

					if (_alamcount <= 5) then
					{
						_plane animate ["HideWeaponSlot03", 1];
					};
					if (_alamcount <= 4) then
					{
						_plane animate ["HideWeaponSlot10", 1];
					};
					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot08", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot05", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot09", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot04", 1];
					};
				};
				case "Aus_R27Launcher":
				{
					_alamcount = _plane ammo "Aus_R27Launcher";

					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot06", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot07", 1];
					};
				};
			};
		};*/
	};
	/*
	case "Aus_Su30MKK3":
	{
		[_plane] execVM "\aus_su30\scripts\MKK3.sqf";

		for [{_i=0}, {_i< count _weapons}, {_i = _i +1}] do
		{
			switch (_weapons select _i) do
			{
				case "Aus_GSh301":
				{
					_rounds = _plane ammo "Aus_GSh301";
					_plane animate ["WeaponAmount1", _rounds];
				};
				case "Aus_S8Launcher":
				{
					_rounds = _plane ammo "Aus_S8Launcher";
					_plane animate ["WeaponAmount2", _rounds];
				};
				case "Aus_R73Launcher":
				{
					_alamcount = _plane ammo "Aus_R73Launcher";

					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot12", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot01", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot02", 1];
					};
					if (_alamcount == 0) then
					{
						_plane animate ["HideWeaponSlot11", 1];
					};
				};
				case "Aus_Kh31Launcher":
				{
					_alamcount = _plane ammo "Aus_Kh31Launcher";

					if (_alamcount <= 5) then
					{
						_plane animate ["HideWeaponSlot03", 1];
					};
					if (_alamcount <= 4) then
					{
						_plane animate ["HideWeaponSlot10", 1];
					};
					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot08", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot05", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot09", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot04", 1];
					};
				};
				case "Aus_R27Launcher":
				{
					_alamcount = _plane ammo "Aus_R27Launcher";

					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot06", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot07", 1];
					};
				};
			};
		};
	};

	case "Aus_Su30MKK2":
	{
		[_plane] execVM "\aus_su30\scripts\MKK2.sqf";

		for [{_i=0}, {_i< count _weapons}, {_i = _i +1}] do
		{
			switch (_weapons select _i) do
			{
				case "Aus_GSh301":
				{
					_rounds = _plane ammo "Aus_GSh301";
					_plane animate ["WeaponAmount1", _rounds];
				};
				case "Aus_S8Launcher":
				{
					_rounds = _plane ammo "Aus_S8Launcher";
					_plane animate ["WeaponAmount2", _rounds];
				};
				case "Aus_R73Launcher":
				{
					_alamcount = _plane ammo "Aus_R73Launcher";

					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot12", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot01", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot02", 1];
					};
					if (_alamcount == 0) then
					{
						_plane animate ["HideWeaponSlot11", 1];
					};
				};
				case "Aus_Kh29Launcher":
				{
					_alamcount = _plane ammo "Aus_Kh29Launcher";

					if (_alamcount <= 5) then
					{
						_plane animate ["HideWeaponSlot06", 1];
					};
					if (_alamcount <= 4) then
					{
						_plane animate ["HideWeaponSlot07", 1];
					};
					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot08", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot05", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot09", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot04", 1];
					};
				};
			};
		};
	};
	case "Aus_Su30MKI":
	{
		[_plane] execVM "\aus_su30\scripts\MKI.sqf";

		for [{_i=0}, {_i< count _weapons}, {_i = _i +1}] do
		{
			switch (_weapons select _i) do
			{
				case "Aus_GSh301":
				{
					_rounds = _plane ammo "Aus_GSh301";
					_plane animate ["WeaponAmount1", _rounds];
				};
				case "Aus_fb250Launcher":
				{
					_rounds = 2.86*(_plane ammo "Aus_fb250Launcher");
					_plane animate ["WeaponAmount2", _rounds];
				};
			};
		};
	};
	case "Aus_Su30MKI_TVC":
	{
		[_plane] execVM "\aus_su30\scripts\MKI_TVC.sqf";

		for [{_i=0}, {_i< count _weapons}, {_i = _i +1}] do
		{
			switch (_weapons select _i) do
			{
				case "Aus_GSh301":
				{
					_rounds = _plane ammo "Aus_GSh301";
					_plane animate ["WeaponAmount1", _rounds];
				};
				case "Aus_S8Launcher":
				{
					_rounds = _plane ammo "Aus_S8Launcher";
					_plane animate ["WeaponAmount2", _rounds];
				};
				case "Aus_R73Launcher":
				{
					_alamcount = _plane ammo "Aus_R73Launcher";

					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot12", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot01", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot02", 1];
					};
					if (_alamcount == 0) then
					{
						_plane animate ["HideWeaponSlot11", 1];
					};
				};
				case "Aus_R27Launcher":
				{
					_alamcount = _plane ammo "Aus_R27Launcher";

					if (_alamcount <= 5) then
					{
						_plane animate ["HideWeaponSlot06", 1];
					};
					if (_alamcount <= 4) then
					{
						_plane animate ["HideWeaponSlot07", 1];
					};
					if (_alamcount <= 3) then
					{
						_plane animate ["HideWeaponSlot03", 1];
					};
					if (_alamcount <= 2) then
					{
						_plane animate ["HideWeaponSlot10", 1];
					};
					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot09", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot04", 1];
					};
				};
				case "Aus_Kh29Launcher":
				{
					_alamcount = _plane ammo "Aus_Kh29Launcher";

					if (_alamcount <= 1) then
					{
						_plane animate ["HideWeaponSlot08", 1];
					};
					if (_alamcount <= 0) then
					{
						_plane animate ["HideWeaponSlot05", 1];
					};
				};
			};
		};
	};*/
};
