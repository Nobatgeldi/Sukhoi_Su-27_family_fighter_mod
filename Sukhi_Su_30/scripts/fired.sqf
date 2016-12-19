_plane = _this select 0;
_weapon = _this select 1;
_ammoname = _this select 4;

_planetype = typeOf _plane;

switch (_planetype) do
{

	case "Sukhi_Su-30":
	{
		switch (_weapon) do
		{
		/*
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
		*/
			case "Aus_R73Launcher":
			{
				_alamcount = _plane ammo "Aus_R73Launcher";
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot12", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot01", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot02", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot11", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_kb500Launcher":
			{
				_alamcount = _plane ammo "Aus_kb500Launcher";

				if (_alamcount == 5) then
				{
					_plane animate ["HideWeaponSlot03", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-4.5,-2,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 4) then
				{
					_plane animate ["HideWeaponSlot10", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [4.5,-2,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot08", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot05", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot09", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot04", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_R27Launcher":
			{
				_alamcount = _plane ammo "Aus_R27Launcher";

				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot06", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-0.5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot07", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
		};
	};

	case "Aus_Su30MKK3":
	{
		switch (_weapon) do
		{
		/*
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
		*/
			case "Aus_R73Launcher":
			{
				_alamcount = _plane ammo "Aus_R73Launcher";
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot12", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot01", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot02", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot11", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_Kh31Launcher":
			{
				_alamcount = _plane ammo "Aus_Kh31Launcher";

				if (_alamcount == 5) then
				{
					_plane animate ["HideWeaponSlot03", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-4.5,-2,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 4) then
				{
					_plane animate ["HideWeaponSlot10", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [4.5,-2,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot08", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot05", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot09", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot04", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_R27Launcher":
			{
				_alamcount = _plane ammo "Aus_R27Launcher";

				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot06", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-0.5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot07", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
		};
	};

	case "Aus_Su30MKK2":
	{
		switch (_weapon) do
		{
		/*
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
		*/
			case "Aus_R73Launcher":
			{
				_alamcount = _plane ammo "Aus_R73Launcher";
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot12", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot01", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot02", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot11", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_Kh29Launcher":
			{
				_alamcount = _plane ammo "Aus_Kh29Launcher";

				if (_alamcount == 5) then
				{
					_plane animate ["HideWeaponSlot06", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-0.5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 4) then
				{
					_plane animate ["HideWeaponSlot07", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot08", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot05", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot09", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot04", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
		};
	};
	case "Aus_Su30MKI":
	{
		switch (_weapon) do
		{
			case "Aus_fb250Launcher":
			{
				_rounds = 2.86*(_plane ammo "Aus_fb250Launcher");
				_plane animate ["WeaponAmount2", _rounds];
			};
		};
	};
	case "Aus_Su30MKI_TVC":
	{
		switch (_weapon) do
		{
		/*
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
		*/
			case "Aus_R73Launcher":
			{
				_alamcount = _plane ammo "Aus_R73Launcher";
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot12", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot01", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-7.04,-3.5,-0.9]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot02", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot11", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [6.015,-3.5,-1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_R27Launcher":
			{
				_alamcount = _plane ammo "Aus_R27Launcher";

				if (_alamcount == 5) then
				{
					_plane animate ["HideWeaponSlot06", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-0.5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 4) then
				{
					_plane animate ["HideWeaponSlot07", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [0,-5,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 3) then
				{
					_plane animate ["HideWeaponSlot03", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-4.5,-2,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 2) then
				{
					_plane animate ["HideWeaponSlot10", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [4.5,-2,-1.25]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot09", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot04", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-3.4,-1.5,-1.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
			case "Aus_Kh29Launcher":
			{
				_alamcount = _plane ammo "Aus_Kh29Launcher";

				if (_alamcount == 1) then
				{
					_plane animate ["HideWeaponSlot08", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
				if (_alamcount == 0) then
				{
					_plane animate ["HideWeaponSlot05", 1];
					_missobj = nearestobject[_plane, _ammoname];
					_missobj SetPos (_plane ModelToWorld [-1.2,-0.4,-2.1]);
					_missobj SetvectorUp (VectorUp _plane);
				};
			};
		};
	};
};
