// -----------------------------
// configured for mig-29 by Gabby_NG
// -----------------------------
private ["_array","_weapon","_plane","_gunmodelpos","_vel"];

_array = _this select 0;
_weapon = _array select 1;
//_ammoname = _array select 4;
_plane = _array select 0;


//main

if(_weapon == "Su_GSh301") then
{
	_gunmodelpos = _plane selectionPosition  "machinegun";
	_vel = speed _plane;
	if(_vel > 40) then
	{
		drop [["\a3\data_f\ParticleEffects\Universal\Universal",16,1,16],	"", "Billboard", 0.3,0.01,_gunmodelpos,[5-random 20,5-random 20,5-random 20],1,1.275,1,0,[2.0, 2.0],[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]],[32], 0.01, 0.01, "", "", _plane];
		drop [["\a3\data_f\ParticleEffects\Universal\Universal", 16, 8, 16],"", "Billboard", 0.5, 0.07,_gunmodelpos,[5-random 20,5-random 20,5-random 20],1,1.275,1,0,[3,4+((3.3+random 4) /3)],[[0.6,0.6,0.6,0.2],[0.7,0.7,0.7,0.5],[0.7,0.7,0.7,0.35],[0.9,0.9,0.9,0.18], [1,1,1,0]],[8 + random 8],0.01,0.01,"","", _plane];
		sleep 0.005;
		drop [["\a3\data_f\ParticleEffects\Universal\Universal", 16, 8, 16],"", "Billboard", 0.5, 0.07,_gunmodelpos,[5-random 20,5-random 20,5-random 20],1,1.275,1,0,[4,4+((3.3+random 4) /3)],[[0.6,0.6,0.6,0.25],[0.7,0.7,0.7,0.4],[0.7,0.7,0.7,0.3],[0.9,0.9,0.9,0.18], [1,1,1,0]],[8 + random 8],0.01,0.01,"","", _plane];
	}
	else
	{
		drop [["\a3\data_f\ParticleEffects\Universal\Universal",16,0,32],	"", "Billboard", 0.3,0.05,_gunmodelpos,velocity _plane,1,1.275,1,0,[2.0, 2.0],[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]],[3 + random 2], 0.01, 0.01, "", "", _plane];
		drop [["\a3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48],"", "Billboard", 0.5, 0.3,_gunmodelpos,velocity _plane,1,1.275,1,0,[3,6+((3.3+random 5) /3)],[[0.6,0.6,0.6,0.2],[0.7,0.7,0.7,0.7],[0.7,0.7,0.7,0.65],[0.8,0.8,0.8,0.35],[0.9,0.9,0.9,0.18], [1,1,1,0]],[3 + random 2],0.01,0.01,"","", _plane];
	}
};
