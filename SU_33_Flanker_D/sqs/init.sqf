scriptName "init.sqf (particleEffects)";
//_v=_this select 0;
//private ["_Su33"];

//Since model.cfg is not always available for reference,
//most animation names could also be obtained from animationNames command.
//Class names listed in CfgVehicles AnimationSources bound to "Proxy"
//controller can also be animated with animate command (see createVehicle/vehicles):
//offroad animate ["HideBackpacks", 0];


//_Su33 = _this select 0;
/*_Su33 animate ["thrust1",0.4];
_Su33 animate ["thrust2",0.4];
_Su33 animate ["thrust3",0.4];
_Su33 animate ["thrust4",0.4];
_Su33 animate ["thrust5",0.4];
_Su33 animate ["thrust6",0.4];
_Su33 animate ["thrust7",0.4];
_Su33 animate ["thrust8",0.4];
_Su33 animate ["thrust9",0.4];*/

/*if (isengineon _Su33) then
{
	_Su33 animate ["thrust1",0.8];
	_Su33 animate ["thrust2",0.8];
	_Su33 animate ["thrust3",0.8];
	_Su33 animate ["thrust4",0.8];
	_Su33 animate ["thrust5",0.8];
	_Su33 animate ["thrust6",0.8];
	_Su33 animate ["thrust7",0.8];
	_Su33 animate ["thrust8",0.8];
	_Su33 animate ["thrust9",0.8];
	_Su33 animate ["thrust10",0.8];
	_Su33 animate ["thrust11",0.8];
	_Su33 animate ["thrust12",0.8];
	_Su33 animate ["thrust13",0.8];
	_Su33 animate ["thrust14",0.8];
	_Su33 animate ["thrust15",0.8];
	_Su33 animate ["thrust16",0.8];
	_Su33 animate ["thrust17",0.8];
	_Su33 animate ["thrust18",0.8];
	_Su33 animate ["thrust19",0.8];
	_Su33 animate ["thrust20",0.8];
	_Su33 animate ["thrust21",0.8];
	_Su33 animate ["thrust22",0.8];
	_Su33 animate ["thrust23",0.8];
	_Su33 animate ["thrust24",0.8];
	_Su33 animate ["thrust25",0.8];
	_Su33 animate ["thrust26",0.8];
	_Su33 animate ["thrust27",0.8];
	_Su33 animate ["thrust28",0.8];
	_Su33 animate ["thrust29",0.8];
	_Su33 animate ["thrust20",0.8];
	_Su33 animate ["thrust31",0.8];
	_Su33 animate ["thrust32",0.8];
}
else
{
	_Su33 animate ["thrust1",0];
	_Su33 animate ["thrust2",0];
	_Su33 animate ["thrust3",0];
	_Su33 animate ["thrust4",0];
	_Su33 animate ["thrust5",0];
	_Su33 animate ["thrust6",0];
	_Su33 animate ["thrust7",0];
	_Su33 animate ["thrust8",0];
	_Su33 animate ["thrust9",0];
	_Su33 animate ["thrust10",0];
	_Su33 animate ["thrust11",0];
	_Su33 animate ["thrust12",0];
	_Su33 animate ["thrust13",0];
	_Su33 animate ["thrust14",0];
	_Su33 animate ["thrust15",0];
	_Su33 animate ["thrust16",0];
	_Su33 animate ["thrust17",0];
	_Su33 animate ["thrust18",0];
	_Su33 animate ["thrust19",0];
	_Su33 animate ["thrust20",0];
	_Su33 animate ["thrust21",0];
	_Su33 animate ["thrust22",0];
	_Su33 animate ["thrust23",0];
	_Su33 animate ["thrust24",0];
	_Su33 animate ["thrust25",0];
	_Su33 animate ["thrust26",0];
	_Su33 animate ["thrust27",0];
	_Su33 animate ["thrust28",0];
	_Su33 animate ["thrust29",0];
	_Su33 animate ["thrust30",0];
	_Su33 animate ["thrust31",0];
	_Su33 animate ["thrust32",0];
};*/
if(isNil 'BIS_Effects_Init') then
	{
	BIS_Effects_Init=true;
	BIS_Effects_EH_Fired=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\fired.sqf";
	BIS_Effects_EH_Killed=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\killed.sqf";

	BIS_Effects_Rifle=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\rifle.sqf";
	BIS_Effects_Cannon=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\cannon.sqf";
	BIS_Effects_Mortar=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\mortar.sqf";
	BIS_Effects_HeavyCaliber=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\heavycaliber.sqf";
	BIS_Effects_HeavySniper=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\heavysniper.sqf";
	BIS_Effects_Rocket=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\rocket.sqf";
	BIS_Effects_SmokeShell=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\smokeshell.sqf";
	BIS_Effects_SmokeLauncher=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\smokelauncher.sqf";
	BIS_Effects_Flares=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\flares.sqf";
	BIS_Effects_HeliRocket=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\helirocket.sqf";

	//must use spawn command for these:
	BIS_Effects_Burn=compile preprocessFileLineNumbers "\SU_33_Flanker_D\sqs\burn.sqf";
	BIS_Effects_AircraftVapour=compile preprocessFileLineNumbers "\SU_33_Flanker_D\sqs\aircraftvapour.sqf";
	BIS_Effects_AirDestruction=compile preprocessFileLineNumbers "\SU_33_Flanker_D\sqs\AirDestruction.sqf";
	BIS_Effects_AirDestructionStage2=compile preprocessFileLineNumbers "\SU_33_Flanker_D\sqs\AirDestructionStage2.sqf";
	BIS_Effects_Secondaries=compile preprocessFileLineNumbers "\SU_33_Flanker_D\sqs\Secondaries.sqf";
	//BIS_Effects_RocketTrail=compile preprocessFileLineNumbers "\A3\data_f\ParticleEffects\SCRIPTS\muzzle\rockettrail.sqf";

	};

/*
if (_v iskindof "Plane")
then
{
	[_v] spawn BIS_Effects_AircraftVapour;
};
*/

/*if (isnil 'BIS_functions_mainscope') then
	{
	BIS_functions_mainscope = _this select 0;
	if (isServer) then
		{
		private ["_ok"];
		_ok = _this execVM "A3\modules\functions\main.sqf";
		}
	};
if (isnil 'RE') then
	{
	private ["_ok"];
	_ok = [] execVM "\A3\Modules\MP\data\scripts\MPframework.sqf";
	};
*/
