class Sounds
{
    class EngineLowOut
    {
        sound[]=
        {
            "SU_33_Flanker_D\sounds\ext-jetair-engine-low1",
            2.5118899,
            1,
            1600
        };
        frequency = "1.0 min (rpm + 0.5)";
        volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
    };
    class EngineHighOut
    {
        sound[]=
        {
            "SU_33_Flanker_D\sounds\ext-jetair-engine-high3",
            2.5118899,
            1.3,
            1800
        };
        frequency = "1";
        volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
    };
    class ForsageOut
    {
        sound[]=
        {
            "SU_33_Flanker_D\sounds\ext-jetair-forsage1",
            2.5118899,
            1.1,
            2000
        };
        frequency = "1";
        volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
        cone[] = {3.14, 3.92, 2.0, 0.5};
    };
    class WindNoiseOut
    {
        sound[] = {"A3\Sounds_F_EPC\CAS_02\noise", 0.562341, 1.0, 150};
        frequency = "(0.1+(1.2*(speed factor[1, 150])))";
        volume = "camPos*(speed factor[1, 150])";
    };
    class EngineLowIn
    {
        sound[]=
        {
            "SU_33_Flanker_D\sounds\int-av8b-engine-low",
            0.56234097,
            1
        };
        frequency = "1.0 min (rpm + 0.5)";
        volume = "(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
    };
    class EngineHighIn
    {
        sound[]=
        {
            "SU_33_Flanker_D\sounds\int-av8b-engine",
            1,
            1
        };
        frequency = "1";
        volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
    };
    class ForsageIn
    {
        sound[]=
        {
            "SU_33_Flanker_D\sounds\int-av8b-forsage-1",
            0.56234097,
            1.1
        };
        frequency = "1";
        volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
    };
    class WindNoiseIn
    {
        sound[]=
        {
            "A3\Sounds_F\air\Plane_Fighter_03\noise",
            0.70794576,
            1
        };
        frequency = "(0.1+(1.2*(speed factor[1, 150])))";
        volume = "(1-camPos)*(speed factor[1, 150])";
    };
    class RainExt
    {
        sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1.77828, 1.0, 100};
        frequency = 1;
        volume = "camPos * rain * (speed factor[50, 0])";
    };

    class RainInt
    {
        sound[] = {"A3\Sounds_F\vehicles\noises\rain1_int", 1.0, 1.0, 100};
        frequency = 1;
        volume = "(1-camPos) * rain * (speed factor[50, 0])";
    };
};
attenuationEffectType = "PlaneAttenuation";
soundGetIn[] = {"A3\Sounds_F_EPC\CAS_02\TO_getin", 1.0, 1};
soundGetOut[] = {"A3\Sounds_F_EPC\CAS_02\getout", 1.0, 1, 40};
cabinOpenSound[] = {"A3\Sounds_F\air\noises\Plane_CAS02_CabinOpen", 3.16228, 1, 40};
cabinCloseSound[] = {"A3\Sounds_F\air\noises\Plane_CAS02_CabinClose", 3.16228, 1, 40};
cabinOpenSoundInternal[] = {"A3\Sounds_F\air\noises\Plane_CAS02_CabinOpen", 10.0, 1, 40};
cabinCloseSoundInternal[] = {"A3\Sounds_F\air\noises\Plane_CAS02_CabinClose", 10.0, 1, 40};
soundDammage[] = {"", 0.562341, 1};
soundEngineOnInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_int", 0.794328, 1.0};
soundEngineOnExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_start_ext", 1.0, 1.0, 500};
soundEngineOffInt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_int", 0.794328, 1.0};
soundEngineOffExt[] = {"A3\Sounds_F_EPC\CAS_02\CAS_02_stop_ext", 1.0, 1.0, 500};
soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1", 0.316228, 1};
soundIncommingMissile[] = {"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_4", 0.398107, 1.0};
soundGearUp[] = {"A3\Sounds_F_EPC\CAS_02\gear_up", 0.794328, 1.0, 150};
soundGearDown[] = {"A3\Sounds_F_EPC\CAS_02\gear_down", 0.794328, 1.0, 150};
soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up", 0.630957, 1.0, 100};
soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down", 0.630957, 1.0, 100};
soundWaterCollision1[] = {"A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_1", 1.41254, 1, 500};
soundWaterCollision2[] = {"A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_2", 1.41254, 1, 500};
soundWaterCrashes[] = {"soundWaterCollision1", 0.5, "soundWaterCollision2", 0.5};
buildCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1.0, 1, 900};
buildCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1.0, 1, 900};
buildCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1.0, 1, 900};
buildCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1.0, 1, 900};
soundBuildingCrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
WoodCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1", 3.16228, 1, 900};
WoodCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_2", 3.16228, 1, 900};
WoodCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_6", 3.16228, 1, 900};
WoodCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_8", 3.16228, 1, 900};
soundWoodCrash[] = {"woodCrash0", 0.25, "woodCrash1", 0.25, "woodCrash2", 0.25, "woodCrash3", 0.25};
armorCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1.0, 1, 900};
armorCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1.0, 1, 900};
armorCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1.0, 1, 900};
armorCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1.0, 1, 900};
soundArmorCrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
Crash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1.0, 1, 900};
Crash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1.0, 1, 900};
Crash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1.0, 1, 900};
Crash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1.0, 1, 900};
soundCrashes[] = {"Crash0", 0.25, "Crash1", 0.25, "Crash2", 0.25, "Crash3", 0.25};
class scrubLandInt {
    sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt", 1.0, 1.0, 100};
    frequency = 1;
    volume = "(scrubLand factor[0.01, 0.20])";
};
insideSoundCoef = 0.1;
