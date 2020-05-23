class Components : Components
{
    class SensorsManagerComponent
    {
        class Components
        {
            class IRSensorComponent : SensorTemplateIR
            {
                class AirTarget
                {
                    minRange = 50;
                    maxRange = 30000;
                    objectDistanceLimitCoef = -1;
                    viewDistanceLimitCoef = -1;
                };

                class GroundTarget
                {
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

        defaultDisplay = "MinimapDisplayComponent";

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
        defaultDisplay = "SensorDisplay";

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

    #include "header/TransportPylonsComponent.hpp"
};
