_plane = _this select 0;

_weapons = weapons _plane;

while {(alive _plane)} do {



					_rounds = _plane ammo "Aus_GSh301";
					_plane animate ["WeaponAmount1", _rounds];

					_rounds = _plane ammo "Aus_S8Launcher";
					_plane animate ["WeaponAmount2", _rounds];	


		sleep 3.159;


};