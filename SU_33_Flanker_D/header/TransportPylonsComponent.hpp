class TransportPylonsComponent
{
    uiPicture = "\SU_33_Flanker_D\texture\UI\Pylon.paa";

    //hardpoints[] = {"RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29","RHS_HP_FAB100_BD3_UMK2A","RHS_HP_FAB100_MBD3_U4T",
    //"RHS_HP_FAB250_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_KAB500_BD3_UMK2A","RHS_HP_KMGU2_BD3_UMK2A","RHS_HP_BD3_USK_A_O25L",
    //"RHS_HP_APU68M3_S24","RHS_HP_B13L_BD3_UMK2A","RHS_HP_B8M1_BD3_UMK2A","RHS_HP_UB16_BD3_UMK2A","RHS_HP_UB32_BD3_UMK2A",
    //"RHS_HP_R77M_AKU170_MIG29","RHS_HP_R77_AKU170_MIG29","RHS_HP_R27_APU470","RHS_HP_R60_APU60","RHS_HP_R73_APU73","RHS_HP_PTB1150"};

    //hardpoints[] = {"RHS_HP_KH25_APU68_MIG29","RHS_HP_FAB100_BD3_UMK2A","RHS_HP_FAB100_MBD3_U4T","RHS_HP_FAB250_BD3_UMK2A",
    //"RHS_HP_FAB500_BD3_UMK2A","RHS_HP_KAB500_BD3_UMK2A","RHS_HP_KMGU2_BD3_UMK2A","RHS_HP_BD3_USK_A_O25L","RHS_HP_APU68M3_S24",
    //"RHS_HP_B13L_BD3_UMK2A","RHS_HP_B8M1_BD3_UMK2A","RHS_HP_UB16_BD3_UMK2A","RHS_HP_UB32_BD3_UMK2A","RHS_HP_R77M_AKU170_MIG29",
    //"RHS_HP_R77_AKU170_MIG29","RHS_HP_R60_APU60","RHS_HP_R73_APU73"};

    // Pylons are indexed to aircraft model's proxies IDs in the order they are written in class Pylons
    class Pylons 
    {
        class Pylons1 // left wingtip
        {
            maxweight     = 500;           //kg ,magazine with higher mass will not be allowed on this pylon
            hardpoints[]  = {"RHS_HP_R77_AKU170_MIG29", O_R77, O_R73, "RHS_HP_R73_APU73"};// magazine with at least one same hardpoints name will be attachable
            //hardpoint[] = {"A164_PYLON_1_10","LAU_7","B_ASRAAM", "SUU_63_PYLON","BRU_32_EJECTOR","B_BOMB_PYLON"}; // just example for community, I am sure you will go closer to realism
            attachment    = "PylonMissile_Missile_AA_R73_x1"; // default magazine
            //bay           = -1; // index of bay for animation
            priority      = 5;    // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
            UIposition[] = {0.05, 0.30}; // x,y coordinates in 3DEN UI
            //turret[]      = {};        // default owner of pylon/weapon, empty for driver
        };
        class Pylons2 : Pylons1
        {
            maxweight = 500;
            hardpoints[] = {"RHS_HP_R77_AKU170_MIG29", O_R77, O_R73, "RHS_HP_R73_APU73"};
            priority = 4;
            attachment = "PylonMissile_Missile_AA_R73_x1";
            UIposition[] = {0.60, 0.30};
        };

        // engine hardpoints
        class Pylons3 : Pylons1
        {
            hardpoints[] = {O_KH58, "RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29","RHS_HP_UB16_BD3_UMK2A",O_MISSILE_PYLON, O_BOMB_PYLON, O_R77, O_R73, O_KH25, "FIR_OPFOR_Combined_HP","RHS_HP_R27_APU470", FIR_OPFOR_AG_HP,"RHS_HP_FAB250_BD3_UMK2A","RHS_HP_KAB500_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_B8M1_BD3_UMK2A"};
            priority = 3;
            attachment = "Su_KH31_magazine";
            maxweight = 2000;
            UIposition[] = {0.40, 0.40};
        };
        class Pylons4 : Pylons1
        {
            hardpoints[] = {O_KH58, "RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29","RHS_HP_UB16_BD3_UMK2A",O_MISSILE_PYLON, O_BOMB_PYLON, O_R77, O_R73, O_KH25, "FIR_OPFOR_Combined_HP","RHS_HP_R27_APU470", FIR_OPFOR_AG_HP,"RHS_HP_FAB250_BD3_UMK2A","RHS_HP_KAB500_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_B8M1_BD3_UMK2A"};
            priority = 2;
            attachment = "Su_KH31_magazine";
            maxweight = 2000;
            UIposition[] = {0.21, 0.40};
        };

        //hardpoints[] = {"O_R77_INT","O_KH25_INT","O_KAB250_BOMB","O_KH58_INT"};
        // third hardpoints
        class Pylons5 : Pylons1
        {
            hardpoints[] = {O_KAB250_BOMB, O_KH58,"RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29","RHS_HP_UB16_BD3_UMK2A",O_MISSILE_PYLON, O_R77, O_R73, O_BOMB_PYLON, B_BOMB_PYLON, O_KH25,"RHS_HP_FAB250_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_R27_APU470",};
            priority = 4;
            attachment = "PylonMissile_Bomb_KAB250_x1";
            maxweight = 1500;
            UIposition[] = {0.15, 0.35};
        };
        class Pylons6 : Pylons1
        {
            hardpoints[] = {O_KAB250_BOMB, O_KH58,"RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29","RHS_HP_UB16_BD3_UMK2A",O_MISSILE_PYLON, O_R77, O_R73, O_BOMB_PYLON, B_BOMB_PYLON, O_KH25,"RHS_HP_FAB250_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_R27_APU470",};
            priority = 4;
            attachment = "PylonMissile_Bomb_KAB250_x1";
            maxweight = 1500;
            UIposition[] = {0.50, 0.35};
        };

        // midd hardpoints
        class Pylons7 : Pylons1
        {
            hardpoints[] = {O_R77, O_BOMB_PYLON, B_BOMB_PYLON, O_KH25, FIR_OPFOR_AG_HP, O_KH58, O_KAB250_BOMB,"RHS_HP_UB16_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_FAB250_BD3_UMK2A"};
            priority = 3;
            attachment = "PylonMissile_Bomb_KAB250_x1";
            maxweight = 2000;
            UIposition[] = {0.30, 0.45};
        };
        class Pylons8 : Pylons1
        {
            hardpoints[] = {O_R77, O_BOMB_PYLON, B_BOMB_PYLON, O_KH25, FIR_OPFOR_AG_HP, O_KH58, O_KAB250_BOMB,"RHS_HP_UB16_BD3_UMK2A","RHS_HP_FAB500_BD3_UMK2A","RHS_HP_FAB250_BD3_UMK2A"};
            priority = 2;
            attachment = "PylonMissile_Bomb_KAB250_x1";
            maxweight = 2000;
            UIposition[] = {0.30, 0.50};
        };

        // second hardpoints
        class Pylons9 : Pylons1
        {
            maxweight     = 500;           //kg ,magazine with higher mass will not be allowed on this pylon
            hardpoints[]  = {"RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29",O_R77, O_R73, O_KH25, O_KH58, "RHS_HP_FAB250_BD3_UMK2A","RHS_HP_R27_APU470",};// magazine with at least one same hardpoints name will be attachable
            attachment    = "PylonMissile_Missile_AA_R77_x1"; // default magazine
            priority      = 5;
            UIposition[] = {0.075, 0.23}; // x,y coordinates in 3DEN UI
        };
        class Pylons10 : Pylons1
        {
            maxweight = 500;
            hardpoints[] = {"RHS_HP_KH25_APU68_MIG29","RHS_HP_KH29_AKU58_MIG29",O_R77, O_R73, O_KH25, O_KH58, "RHS_HP_FAB250_BD3_UMK2A","RHS_HP_R27_APU470",};
            priority = 4;
            attachment = "PylonMissile_Missile_AA_R77_x1";
            UIposition[] = {0.57, 0.23};
        };

        //end of wings
        class Pylons11 // left wingtip
        {
            maxweight     = 500;           //kg ,magazine with higher mass will not be allowed on this pylon
            hardpoints[]  = {O_R73, "RHS_HP_R73_APU73"};// magazine with at least one same hardpoints name will be attachable
            attachment    = "PylonMissile_Missile_AA_R73_x1"; // default magazine
            priority      = 5;    // pylon with higher priority is used to fire missile first, this can by changed in run time by script command setPylonsPriority
            UIposition[] = {0.00, 0.18}; // x,y coordinates in 3DEN UI
        };
        class Pylons12 : Pylons1
        {
            maxweight = 500;
            hardpoints[] = {O_R73, "RHS_HP_R73_APU73"};
            priority = 4;
            attachment = "PylonMissile_Missile_AA_R73_x1";
            UIposition[] = {0.65, 0.18};
        };
    };

    class Presets
    {
        class Empty
        {
            displayName = "Empty";
            attachment[] = {};
        };
        class AGMIXED
        {
            displayName = "AG Mixed";
            attachment[] = 
            {
                "PylonMissile_Missile_AA_R77_x1",
                "PylonMissile_Missile_AA_R77_x1",

                "Su_KH31_magazine", 
                "Su_KH31_magazine",

                "PylonMissile_Missile_KH58_x1",
                "PylonMissile_Missile_KH58_x1",

                "PylonMissile_Bomb_KAB250_x1",
                "PylonMissile_Bomb_KAB250_x1",

                "PylonMissile_Missile_AGM_KH25_x1",
                "PylonMissile_Missile_AGM_KH25_x1",

                "PylonMissile_Missile_AA_R73_x1",
                "PylonMissile_Missile_AA_R73_x1"
            };
        };
        class Combined
        {
            displayName = "Combined";
            attachment[] = 
            {
                "PylonMissile_Missile_AA_R73_x1",
                "PylonMissile_Missile_AA_R73_x1",

                "PylonMissile_Missile_KH58_x1", 
                "PylonMissile_Missile_KH58_x1",

                "PylonMissile_Missile_AGM_KH25_x1",
                "PylonMissile_Missile_AGM_KH25_x1",

                "PylonMissile_Bomb_KAB250_x1",
                "PylonMissile_Bomb_KAB250_x1",

                "PylonMissile_Missile_AA_R77_x1",
                "PylonMissile_Missile_AA_R77_x1",

                "PylonMissile_Missile_AA_R73_x1",
                "PylonMissile_Missile_AA_R73_x1"
            };
        };
        class AA
        {
            displayName = "AA";
            attachment[] = 
            {
                "PylonMissile_Missile_AA_R73_x1",
                "PylonMissile_Missile_AA_R73_x1",

                "PylonMissile_Missile_AA_R77_x1", 
                "PylonMissile_Missile_AA_R77_x1",

                "PylonMissile_Missile_AA_R77_x1",
                "PylonMissile_Missile_AA_R77_x1",

                "PylonMissile_Missile_AA_R77_x1",
                "PylonMissile_Missile_AA_R77_x1",

                "PylonMissile_Missile_AA_R73_x1",
                "PylonMissile_Missile_AA_R73_x1",

                "PylonMissile_Missile_AA_R73_x1",
                "PylonMissile_Missile_AA_R73_x1"
            };
        };
    };
};
