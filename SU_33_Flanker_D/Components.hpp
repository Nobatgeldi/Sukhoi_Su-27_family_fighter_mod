class Components : Components
{
    class SensorsManagerComponent
    {
        class Components
        {
            class IRSensorComponent : SensorTemplateIR {
                class AirTarget {
                    minRange = 50;
                    maxRange = 30000;
                    objectDistanceLimitCoef = -1;
                    viewDistanceLimitCoef = -1;
                };

                class GroundTarget {
                    minRange = 100;
                    maxRange = 20000;
                    objectDistanceLimitCoef = -1;
                    viewDistanceLimitCoef = -1;
                };
                angleRangeHorizontal = 60;
                angleRangeVertical = 60;
                maxSpeedThreshold = 40;
                maxTrackableATL = 1e+010;
                maxTrackableSpeed = 1e+010;
                minSpeedThreshold = 30;
                minTrackableATL = -1e+010;
                minTrackableSpeed = -1e+010;
                animDirection = "PilotCameraY";
            };

            class VisualSensorComponent : SensorTemplateVisual {
                class AirTarget {
                    minRange = 50;
                    maxRange = 10000;
                    objectDistanceLimitCoef = -1;
                    viewDistanceLimitCoef = -1;
                };

                class GroundTarget {
                    minRange = 50;
                    maxRange = 10000;
                    objectDistanceLimitCoef = -1;
                    viewDistanceLimitCoef = -1;
                };
                angleRangeHorizontal = 90;
                angleRangeVertical = 90;
                maxSpeedThreshold = 40;
                maxTrackableATL = 1e+010;
                maxTrackableSpeed = 1e+010;
                minSpeedThreshold = 30;
                minTrackableATL = -1e+010;
                minTrackableSpeed = -1e+010;
                animDirection = "PilotCameraY";
            };

            class AntiRadiationSensorComponent : SensorTemplateAntiRadiation {};

            class ActiveRadarSensorComponent : SensorTemplateActiveRadar
            {
                class AirTarget {
                    minRange = 50;
                    maxRange = 100000;
                };
                angleRangeHorizontal = 160;
                angleRangeVertical = 160;
                maxSpeedThreshold = 40;
                maxTrackableATL = 1e+010;
                maxTrackableSpeed = 1e+010;
                minSpeedThreshold = 30;
                minTrackableATL = -1e+010;
                minTrackableSpeed = -1e+010;
            };

            class PassiveRadarSensorComponent : SensorTemplatePassiveRadar {};

            class LaserSensorComponent : SensorTemplateLaser{};

            class NVSensorComponent : SensorTemplateNV {};
        };
    };

    class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft
    {
        componentType = "VehicleSystemsDisplayManager";

        defaultDisplay = "VehicleDriverDisplay";

        class Components {
            class EmptyDisplay {
                componentType = "EmptyDisplayComponent";
            };

            class MinimapDisplay {
                componentType = "MinimapDisplayComponent";
                resource = "RscCustomInfoMiniMap";
            };

            class UAVDisplay {
                componentType = "UAVFeedDisplayComponent";
            };

            class SlingLoadDisplay      //Slingload Assistant
            {
                componentType = "SlingLoadDisplayComponent";
                resource = "RscCustomInfoSlingLoad";
            };

            class VehicleDriverDisplay {
                componentType = "TransportFeedDisplayComponent";
                source = "Driver";
            };

            class VehicleMissileDisplay {
                componentType = "TransportFeedDisplayComponent";
                source = "Missile";
            };

            class SensorDisplay {
                componentType = "SensorsDisplayComponent";
                range[] = {16000, 8000, 4000, 2000};
                showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024;
                // 1 - Sensor sectors, 2 - Threats, 4 - Marked tgt symbol,
                //8 - Own detection, 16 - Remote detection, 32 - Active detection,
                //64 - Passive detection, 128 - Ground tgts, 256 - Air tgts,
                //512 - Men, 1024 - Special (laser, NV)
                resource = "RscCustomInfoSensors";
            };
        };
    };

    class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight
    {
        componentType = "VehicleSystemsDisplayManager";
        defaultDisplay = "SensorsDisplay";

        class Components {
            class EmptyDisplay {
                componentType = "EmptyDisplayComponent";
            };

            class MinimapDisplay {
                componentType = "MinimapDisplayComponent";
                resource = "RscCustomInfoMiniMap";
            };

            class UAVDisplay {
                componentType = "UAVFeedDisplayComponent";
            };

            class VehicleDriverDisplay {
                componentType = "TransportFeedDisplayComponent";
                source = "Driver";
            };

            class VehicleMissileDisplay {
                componentType = "TransportFeedDisplayComponent";
                source = "Missile";
            };

            class SensorDisplay {
                componentType = "SensorsDisplayComponent";
                range[] = {16000, 8000, 4000, 2000};
                showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024; // 1 - Sensor sectors, 2 - Threats, 4 - Marked tgt symbol, 8 - Own detection, 16 - Remote detection, 32 - Active detection, 64 - Passive detection, 128 - Ground tgts, 256 - Air tgts, 512 - Men, 1024 - Special (laser, NV)
                resource = "RscCustomInfoSensors";
            };
        };
    };

    class TransportPylonsComponent
    {

        uiPicture = "\SU_33_Flanker_D\tex\UI\Pylon.paa";

        class Pylons // Pylons are indexed to aircraft model's proxies IDs in the order they are written in class Pylons
        {
            class Pylons1 // left wingtip
            {
                maxweight     = 300;           //kg ,magazine with higher mass will not be allowed on this pylon
                hardpoints[]  = {O_R77, O_R73};// magazine with at least one same hardpoints name will be attachable
                //hardpoint[] = {"A164_PYLON_1_10","LAU_7","B_ASRAAM", "SUU_63_PYLON","BRU_32_EJECTOR","B_BOMB_PYLON"}; // just example for community, I am sure you will go closer to realism
                attachment    = "PylonMissile_Missile_AA_R73_x1"; // default magazine
                //bay           = -1; // index of bay for animation
                priority      = 5;    // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
                UIposition[] = {0.00, 0.30}; // x,y coordinates in 3DEN UI
                //turret[]      = {};        // default owner of pylon/weapon, empty for driver
            };
            class Pylons2 : Pylons1
            {
                maxweight = 300;
                hardpoints[] = {O_R77, O_R73};
                priority = 4;
                attachment = "PylonMissile_Missile_AA_R73_x1";
                UIposition[] = {0.65, 0.30};
            };

            // engine hardpoints
            class Pylons3 : Pylons1
            {
                hardpoints[] = {O_MISSILE_PYLON, O_BOMB_PYLON, O_R77, O_R73, O_KH25, "FIR_OPFOR_Combined_HP", FIR_OPFOR_AG_HP};
                priority = 3;
                attachment = "PylonMissile_Missile_AGM_KH25_x1";
                maxweight = 1200;
                UIposition[] = {0.40, 0.40};
            };
            class Pylons4 : Pylons1
            {
                hardpoints[] = {O_MISSILE_PYLON, O_BOMB_PYLON, O_R77, O_R73, O_KH25, "FIR_OPFOR_Combined_HP", FIR_OPFOR_AG_HP};
                priority = 2;
                attachment = "PylonMissile_Missile_AGM_KH25_x1";
                maxweight = 1200;
                UIposition[] = {0.21, 0.40};
            };

            // third hardpoints
            class Pylons5 : Pylons1
            {
                hardpoints[] = {O_MISSILE_PYLON, O_R77, O_R73};
                priority = 4;
                attachment = "PylonMissile_Missile_AA_R73_x1";
                maxweight = 300;
                UIposition[] = {0.15, 0.35};
            };
            class Pylons6 : Pylons1
            {
                hardpoints[] = {O_MISSILE_PYLON, O_R77, O_R73};
                priority = 4;
                attachment = "PylonMissile_Missile_AA_R73_x1";
                maxweight = 300;
                UIposition[] = {0.50, 0.35};
            };

            // midd hardpoints
            class Pylons7 : Pylons1
            {
                hardpoints[] = {O_BOMB_PYLON, B_BOMB_PYLON, O_R77, O_KH25, FIR_OPFOR_AG_HP};
                priority = 3;
                attachment = "PylonMissile_Bomb_KAB250_x1";
                maxweight = 1500;
                UIposition[] = {0.30, 0.45};
            };
            class Pylons8 : Pylons1
            {
                hardpoints[] = {O_BOMB_PYLON, B_BOMB_PYLON, O_R77, O_KH25, FIR_OPFOR_AG_HP};
                priority = 2;
                attachment = "PylonMissile_Bomb_KAB250_x1";
                maxweight = 1500;
                UIposition[] = {0.30, 0.50};
            };

            // second hardpoints
            class Pylons9 : Pylons1
            {
                maxweight     = 300;           //kg ,magazine with higher mass will not be allowed on this pylon
                hardpoints[]  = {O_R77, O_R73};// magazine with at least one same hardpoints name will be attachable
                attachment    = "PylonMissile_Missile_AA_R73_x1"; // default magazine
                priority      = 5;
                UIposition[] = {0.075, 0.18}; // x,y coordinates in 3DEN UI
            };
            class Pylons10 : Pylons1
            {
                maxweight = 300;
                hardpoints[] = {O_R77, O_R73};
                priority = 4;
                attachment = "PylonMissile_Missile_AA_R73_x1";
                UIposition[] = {0.57, 0.18};
            };
        };
        class Presets
        {
            class Empty
            {
                displayName = "Empty";
                attachment[] = {};
            };

            class AA
            {
                displayName = "Combined";
                attachment[] = {"PylonMissile_Missile_AA_R73_x1","PylonMissile_Missile_AA_R73_x1", "PylonMissile_Missile_AA_R77_x1", "PylonMissile_Missile_AA_R77_x1","PylonMissile_Missile_AGM_KH25_x1","PylonMissile_Missile_AGM_KH25_x1","PylonMissile_Missile_AGM_KH25_x1","PylonMissile_Missile_AGM_KH25_x1","PylonMissile_Missile_AGM_KH25_x1"};
            };
        };
    };
};