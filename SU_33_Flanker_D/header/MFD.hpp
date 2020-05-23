class MFD
{
    class HUD_HMD
    {
        topLeft="HUD LH";
        topRight="HUD PH";
        bottomLeft="HUD LD";
        borderLeft=0;
        borderRight=0;
        borderTop=0;
        borderBottom=0;
        color[]={0,1,0,1};
        enableParallax=0;
        class Bones
        {
            class WeaponAim
            {
                type="vector";
                source="weapon";
                pos0[]={0.5,0.55500001};
                pos10[]={1.5,1.5549999};
            };
        };
        class Draw
        {
            color[]={0,1,0,1};
            alpha=0.5;
            condition="on";
            class StallGroup
            {
                type="group";
                condition="stall";
                color[]={1,0,0};
                class StallText
                {
                    type="text";
                    source="static";
                    text="STALL";
                    align="center";
                    scale=1;
                    pos[]=
                    {

                        {
                            0.5,
                            "0.53 - 0.25"
                        },
                        1
                    };
                    right[]=
                    {

                        {
                            0.55000001,
                            "0.53 - 0.25"
                        },
                        1
                    };
                    down[]=
                    {

                        {
                            0.5,
                            "0.53 - 0.17"
                        },
                        1
                    };
                };
            };
            class AAMissile
            {
                type="group";
                condition="AAmissile";
                class AAMissileCrosshair
                {
                    type="line";
                    width=4;
                    points[]=
                    {

                        {
                            "WeaponAim",
                            {0,-0.25},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.043400001,-0.2462},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.085500002,-0.234925},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.125,-0.2165},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.16069999,-0.19149999},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.19149999,-0.16069999},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.2165,-0.125},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.234925,-0.085500002},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.2462,-0.043400001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.25,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.2462,0.043400001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.234925,0.085500002},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.2165,0.125},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.19149999,0.16069999},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.16069999,0.19149999},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.125,0.2165},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.085500002,0.234925},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.043400001,0.2462},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,0.25},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.043400001,0.2462},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.085500002,0.234925},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.125,0.2165},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.16069999,0.19149999},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.19149999,0.16069999},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.2165,0.125},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.234925,0.085500002},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.2462,0.043400001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.25,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.2462,-0.043400001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.234925,-0.085500002},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.2165,-0.125},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.19149999,-0.16069999},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.16069999,-0.19149999},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.125,-0.2165},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.085500002,-0.234925},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.043400001,-0.2462},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,-0.25},
                            1
                        }
                    };
                };
            };
            class ATMissile
            {
                condition="ATmissile";
                type="group";
                class ATMissileCrosshair
                {
                    type="line";
                    width=4;
                    points[]=
                    {

                        {
                            "WeaponAim",
                            {-0.15000001,-0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                -0.15000001,
                                "-0.15 + 0.02"
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.15000001,0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                -0.15000001,
                                "0.15 - 0.02"
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.15000001,-0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                0.15000001,
                                "-0.15 + 0.02"
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.15000001,0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                0.15000001,
                                "0.15 - 0.02"
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.15000001,-0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                "-0.15 + 0.02",
                                -0.15000001
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.15000001,0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                "-0.15 + 0.02",
                                0.15000001
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.15000001,-0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                "0.15 - 0.02",
                                -0.15000001
                            },
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.15000001,0.15000001},
                            1
                        },

                        {
                            "WeaponAim",

                            {
                                "0.15 - 0.02",
                                0.15000001
                            },
                            1
                        }
                    };
                };
            };
        };
        helmetMountedDisplay = 1;
        helmetPosition[] = {-0.04, 0.04, 0.1};
        helmetRight[] = {0.08, 0, 0};
        helmetDown[] = {0, -0.08, 0};
    };
    class HUD_statick
    {
        topLeft="HUD LH";
        topRight="HUD PH";
        bottomLeft="HUD LD";
        borderLeft=0;
        borderRight=0;
        borderTop=0;
        borderBottom=0;
        color[]={0,1,0,1};
        enableParallax=0;
        class Bones
        {
            class PlaneOrientation
            {
                type="fixed";
                pos[]={0.5,0.52999997};
            };
            class WeaponAim
            {
                type="vector";
                source="weapon";
                pos0[]={0.5,0.55500001};
                pos10[]={1.5,1.5549999};
            };
            class Velocity
            {
                type="vector";
                source="velocity";
                pos0[]={0.5,0.52999997};
                pos10[]={1.5,1.53};
                angle=-2.3;
            };
            class Level0
            {
                type="horizon";
                pos0[]={0.5,0.52999997};
                pos10[]={1.5,1.53};
                angle=-2.3;
            };
        };
        class Draw
        {
            color[]={0,1,0,1};
            alpha=1;
            condition="on";
            class Horizont
            {
                clipTL[]={0.25,0.25};
                clipBR[]={0.75,0.75};
                class Dimmed
                {
                    class Level00
                    {
                        type="line";
                        width=15;
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "-0.045 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.005 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "0.005 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "0.045 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "0.125 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "0.200 * 1.4",
                                    "0 * 1.4"
                                },
                                1
                            }
                        };
                    };
                    class Level2M5: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 5"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 5"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 5"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 5"
                                },
                                1
                            }
                        };
                    };
                    class Level2P5: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 5"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 5"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 5"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 5"
                                },
                                1
                            }
                        };
                    };
                    class Level2M10: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 10"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 10"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 10"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 10"
                                },
                                1
                            }
                        };
                    };
                    class Level2P10: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 10"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 10"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 10"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 10"
                                },
                                1
                            }
                        };
                    };
                    class Level2M15: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 15"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 15"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 15"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 15"
                                },
                                1
                            }
                        };
                    };
                    class Level2P15: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 15"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 15"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 15"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 15"
                                },
                                1
                            }
                        };
                    };
                    class Level2P20: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 20"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 20"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 20"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 20"
                                },
                                1
                            }
                        };
                    };
                    class Level2M20: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 20"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 20"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 20"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 20"
                                },
                                1
                            }
                        };
                    };
                    class Level2P30: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 30"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 30"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 30"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 30"
                                },
                                1
                            }
                        };
                    };
                    class Level2M30: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 30"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 30"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 30"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 30"
                                },
                                1
                            }
                        };
                    };
                    class Level2P40: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 40"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 40"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 40"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 40"
                                },
                                1
                            }
                        };
                    };
                    class Level2M40: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 40"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 40"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 40"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 40"
                                },
                                1
                            }
                        };
                    };
                    class Level2P50: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 50"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 50"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 50"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 50"
                                },
                                1
                            }
                        };
                    };
                    class Level2M50: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 50"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 50"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 50"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 50"
                                },
                                1
                            }
                        };
                    };
                    class Level2P60: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 60"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 60"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 60"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 60"
                                },
                                1
                            }
                        };
                    };
                    class Level2M60: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 60"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 60"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 60"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 60"
                                },
                                1
                            }
                        };
                    };
                    class Level2P70: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 70"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 70"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 70"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 70"
                                },
                                1
                            }
                        };
                    };
                    class Level2M70: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 70"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 70"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 70"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 70"
                                },
                                1
                            }
                        };
                    };
                    class Level2P80: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 80"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 80"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 80"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 80"
                                },
                                1
                            }
                        };
                    };
                    class Level2M80: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 80"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 80"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 80"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 80"
                                },
                                1
                            }
                        };
                    };
                    class Level2P90: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "+1.0 / 10 * 90"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "+1.0 / 10 * 90"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "+1.0 / 10 * 90"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "+1.0 / 10 * 90"
                                },
                                1
                            }
                        };
                    };
                    class Level2M90: Level00
                    {
                        type="line";
                        points[]=
                        {

                            {
                                "Level0",

                                {
                                    "-0.200 * 1.4",
                                    "-1.0 / 10 * 90"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "-0.125 * 1.4",
                                    "-1.0 / 10 * 90"
                                },
                                1
                            },
                            {},

                            {
                                "Level0",

                                {
                                    "+0.125 * 1.4",
                                    "-1.0 / 10 * 90"
                                },
                                1
                            },

                            {
                                "Level0",

                                {
                                    "+0.200 * 1.4",
                                    "-1.0 / 10 * 90"
                                },
                                1
                            }
                        };
                    };
                };
            };
            class PlaneOrientation_MiniPlane
            {
                width=20;
                type="line";
                points[]=
                {

                    {
                        "PlaneOrientation",
                        {0.20999999,0},
                        1
                    },

                    {
                        "PlaneOrientation",
                        1,
                        {0.07,0},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        1,
                        {-0.20999999,0},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.07,0},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0,0},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0,-0.14},
                        1
                    }
                };
            };
            class PlaneOrientationLines
            {
                clipTL[]={0,0.1};
                clipBR[]={1,0};
                type="line";
                width=4;
                points[]=
                {

                    {
                        "PlaneOrientation",
                        {-0.20999999,7.2250699e-009},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.28,9.6334301e-009},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0.20999999,-1.97107e-009},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0.28,-2.62809e-009},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {-0.105,0.14314599},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.14,0.190861},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0.105,0.14314599},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0.14,0.190861},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {-0.18186501,0.0826452},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.242487,0.110194},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0.18186501,0.0826452},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0.242487,0.110194},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {-0.20284399,0.042780299},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.270459,0.057040401},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0.20284399,0.042780299},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0.270459,0.057040401},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {-0.20920099,0.014406},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.244068,0.016806999},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {-0.20681,0.028702401},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {-0.24127799,0.033486102},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0.20681,0.028702401},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0.24127799,0.033486102},
                        1
                    },
                    {},

                    {
                        "PlaneOrientation",
                        {0.20920099,0.014406},
                        1
                    },

                    {
                        "PlaneOrientation",
                        {0.244068,0.016806999},
                        1
                    },
                    {}
                };
            };
            class WeaponName
            {
                type="text";
                source="weapon";
                sourceScale=1;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.029999999,0.94},
                    1
                };
                right[]=
                {
                    {0.079999998,0.94},
                    1
                };
                down[]=
                {
                    {0.029999999,0.98000002},
                    1
                };
            };
            class AmmoCount
            {
                type="text";
                source="ammo";
                sourceScale=1;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.029999999,0.88999999},
                    1
                };
                right[]=
                {
                    {0.079999998,0.88999999},
                    1
                };
                down[]=
                {
                    {0.029999999,0.93000001},
                    1
                };
            };
            class FlapsGroup
            {
                type="group";
                condition="flaps";
                class FlapsText
                {
                    type="text";
                    source="static";
                    text="FLAPS";
                    align="right";
                    scale=1;
                    pos[]=
                    {

                        {
                            0.029999999,
                            "0.53 - 0.045"
                        },
                        1
                    };
                    right[]=
                    {

                        {
                            0.079999998,
                            "0.53 - 0.045"
                        },
                        1
                    };
                    down[]=
                    {

                        {
                            0.029999999,
                            "0.53 - 0.005"
                        },
                        1
                    };
                };
            };
            class GearGroup
            {
                type="group";
                condition="ils";
                class GearText
                {
                    type="text";
                    source="static";
                    text="GEAR";
                    align="right";
                    scale=1;
                    pos[]=
                    {

                        {
                            0.029999999,
                            "0.53 + 0.005"
                        },
                        1
                    };
                    right[]=
                    {

                        {
                            0.079999998,
                            "0.53 + 0.005"
                        },
                        1
                    };
                    down[]=
                    {

                        {
                            0.029999999,
                            "0.53 + 0.045"
                        },
                        1
                    };
                };
            };
            class LightsGroup
            {
                type="group";
                condition="lights";
                class LightsText
                {
                    type="text";
                    source="static";
                    text="LIGHTS";
                    align="right";
                    scale=1;
                    pos[]=
                    {

                        {
                            0.029999999,
                            "0.53 + 0.055"
                        },
                        1
                    };
                    right[]=
                    {

                        {
                            0.079999998,
                            "0.53 + 0.055"
                        },
                        1
                    };
                    down[]=
                    {

                        {
                            0.029999999,
                            "0.53 + 0.095"
                        },
                        1
                    };
                };
            };
            class CollisionLightsGroup
            {
                type="group";
                condition="collisionlights";
                class CollisionLightsText
                {
                    type="text";
                    source="static";
                    text="A-COL";
                    align="right";
                    scale=1;
                    pos[]=
                    {

                        {
                            0.029999999,
                            "0.53 + 0.105"
                        },
                        1
                    };
                    right[]=
                    {

                        {
                            0.079999998,
                            "0.53 + 0.105"
                        },
                        1
                    };
                    down[]=
                    {

                        {
                            0.029999999,
                            "0.53 + 0.145"
                        },
                        1
                    };
                };
            };
            class PitchNumber
            {
                type="text";
                source="horizonDive";
                sourceScale=57.295799;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.50999999,0.88999999},
                    1
                };
                right[]=
                {
                    {0.56,0.88999999},
                    1
                };
                down[]=
                {
                    {0.50999999,0.93000001},
                    1
                };
            };
            class PitchText
            {
                type="text";
                source="static";
                text="PITCH";
                align="left";
                scale=1;
                pos[]=
                {
                    {0.49000001,0.88999999},
                    1
                };
                right[]=
                {
                    {0.54000002,0.88999999},
                    1
                };
                down[]=
                {
                    {0.49000001,0.93000001},
                    1
                };
            };
            class RollNumber
            {
                type="text";
                source="horizonBank";
                sourceScale=57.295799;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.50999999,0.83999997},
                    1
                };
                right[]=
                {
                    {0.56,0.83999997},
                    1
                };
                down[]=
                {
                    {0.50999999,0.88},
                    1
                };
            };
            class RollText
            {
                type="text";
                source="static";
                text="ROLL";
                align="left";
                scale=1;
                pos[]=
                {
                    {0.49000001,0.83999997},
                    1
                };
                right[]=
                {
                    {0.54000002,0.83999997},
                    1
                };
                down[]=
                {
                    {0.49000001,0.88},
                    1
                };
            };
            class SpeedNumber
            {
                type="text";
                source="speed";
                sourceScale=3.5999999;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.13,0.14},
                    1
                };
                right[]=
                {
                    {0.18000001,0.14},
                    1
                };
                down[]=
                {
                    {0.13,0.18000001},
                    1
                };
            };
            class SpeedText
            {
                type="text";
                source="static";
                text="SPD";
                align="left";
                scale=1;
                pos[]=
                {
                    {0.11,0.14},
                    1
                };
                right[]=
                {
                    {0.16,0.14},
                    1
                };
                down[]=
                {
                    {0.11,0.18000001},
                    1
                };
            };
            class AltitudeNumber
            {
                type="text";
                source="altitudeAGL";
                sourceScale=1;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.88999999,0.14},
                    1
                };
                right[]=
                {
                    {0.94,0.14},
                    1
                };
                down[]=
                {
                    {0.88999999,0.18000001},
                    1
                };
            };
            class AltitudeText
            {
                type="text";
                source="static";
                text="AGL";
                align="left";
                scale=1;
                pos[]=
                {
                    {0.87,0.14},
                    1
                };
                right[]=
                {
                    {0.92000002,0.14},
                    1
                };
                down[]=
                {
                    {0.87,0.18000001},
                    1
                };
            };
            class AltitudeArrow
            {
                type="line";
                width=4;
                points[]=
                {

                    {

                        {
                            "0.88 + 0.018",
                            "0.40 - 0.016"
                        },
                        1
                    },

                    {
                        {0.88,0.40000001},
                        1
                    },

                    {

                        {
                            "0.88 + 0.018",
                            "0.40 + 0.016"
                        },
                        1
                    }
                };
            };
            class AltitudeLine
            {
                type="line";
                width=4;
                points[]=
                {

                    {
                        {0.87,0.60000002},
                        1
                    },

                    {
                        {0.87,0.2},
                        1
                    }
                };
            };
            class AltitudeScale
            {
                type="scale";
                horizontal=0;
                source="altitudeAGL";
                sourceScale=1;
                width=4;
                top=0.60000002;
                center=0.40000001;
                bottom=0.2;
                lineXleft=0.88;
                lineYright=0.88999999;
                lineXleftMajor=0.88;
                lineYrightMajor=0.89999998;
                majorLineEach=5;
                numberEach=5;
                step=20;
                stepSize="(0.60 - 0.20) / 15";
                align="right";
                scale=1;
                pos[]={0.91000003,0.57999998};
                right[]={0.95999998,0.57999998};
                down[]={0.91000003,0.62};
            };
            class ClimbNumber
            {
                type="text";
                source="vspeed";
                sourceScale=1;
                align="right";
                scale=1;
                pos[]=
                {
                    {0.88999999,0.94},
                    1
                };
                right[]=
                {
                    {0.94,0.94},
                    1
                };
                down[]=
                {
                    {0.88999999,0.98000002},
                    1
                };
            };
            class ClimbText
            {
                type="text";
                source="static";
                text="CLIMB";
                align="left";
                scale=1;
                pos[]=
                {
                    {0.87,0.94},
                    1
                };
                right[]=
                {
                    {0.92000002,0.94},
                    1
                };
                down[]=
                {
                    {0.87,0.98000002},
                    1
                };
            };
            class ClimbArrow
            {
                type="line";
                width=4;
                points[]=
                {

                    {

                        {
                            "0.88 + 0.018",
                            "0.80 - 0.016"
                        },
                        1
                    },

                    {
                        {0.88,0.80000001},
                        1
                    },

                    {

                        {
                            "0.88 + 0.018",
                            "0.80 + 0.016"
                        },
                        1
                    }
                };
            };
            class ClimbLine
            {
                type="line";
                width=4;
                points[]=
                {

                    {
                        {0.87,0.92500001},
                        1
                    },

                    {
                        {0.87,0.67500001},
                        1
                    }
                };
            };
            class ClimbScale
            {
                type="scale";
                horizontal=0;
                source="vspeed";
                sourceScale=1;
                width=4;
                top=0.92500001;
                center=0.80000001;
                bottom=0.67500001;
                lineXleft=0.88;
                lineYright=0.88999999;
                lineXleftMajor=0.88;
                lineYrightMajor=0.89999998;
                majorLineEach=2;
                numberEach=4;
                step=5;
                stepSize="(0.925 - 0.675) / 15";
                align="right";
                scale=1;
                pos[]={0.91000003,0.90499997};
                right[]={0.95999998,0.90499997};
                down[]={0.91000003,0.94499999};
            };
            class HeadingArrow
            {
                type="line";
                width=4;
                points[]=
                {

                    {

                        {
                            "0.5 - 0.02",
                            "0.11 - 0.02"
                        },
                        1
                    },

                    {
                        {0.5,0.11},
                        1
                    },

                    {

                        {
                            "0.5 + 0.02",
                            "0.11 - 0.02"
                        },
                        1
                    }
                };
            };
            class HeadingLine
            {
                type="line";
                width=4;
                points[]=
                {

                    {
                        {0.30000001,0.12},
                        1
                    },

                    {
                        {0.69999999,0.12},
                        1
                    }
                };
            };
            class HeadingScale
            {
                type="scale";
                scale=1;
                source="Heading";
                sourceScale=1;
                align="center";
                pos[]=
                {
                    "0.21-0.01",
                    0
                };
                right[]=
                {
                    "0.29-0.01",
                    0
                };
                down[]=
                {
                    "0.21-0.01",
                    0.050000001
                };
                lineXleft=0.059999999;
                lineYright=0.050000001;
                lineXleftMajor=0.059999999;
                lineYrightMajor=0.039999999;
                bottom=0.80000001;
                center=0.5;
                top=0.2;
                step="18/9";
                StepSize="(0.80- 0.2)/20";
                horizontal=1;
                min="none";
                max="none";
                numberEach=5;
                majorLineEach=5;
            };
            class RadarTargets
            {
                type="radar";
                width=4;
                angle=-2.3;
                pos0[]={0.5,0.55500001};
                pos10[]={1.24,1.325};
                points[]=
                {

                    {
                        {-0.050000001,-0.047297299},
                        1
                    },

                    {
                        {0.050000001,-0.047297299},
                        1
                    },

                    {
                        {0.050000001,0.047297299},
                        1
                    },

                    {
                        {-0.050000001,0.047297299},
                        1
                    },

                    {
                        {-0.050000001,-0.047297299},
                        1
                    }
                };
            };
        };
    };
    class Parallax_HUD
    {
        topLeft="HUD LH";
        topRight="HUD PH";
        bottomLeft="HUD LD";
        borderLeft=0;
        borderRight=0;
        borderTop=0;
        borderBottom=0;
        color[]={0,1,0,1};
        enableParallax=1;
        class Bones
        {
            class PlaneOrientation
            {
                type="fixed";
                pos[]={0.5,0.52999997};
            };
            class WeaponAim
            {
                type="vector";
                source="weapon";
                pos0[]={0.5,0.55500001};
                pos10[]={1.5,1.5549999};
            };
            class Velocity
            {
                type="vector";
                source="velocity";
                pos0[]={0.5,0.52999997};
                pos10[]={1.5,1.53};
            };
            class Level0
            {
                type="horizon";
                pos0[]={0.5,0.52999997};
                pos10[]={1.5,1.53};
                angle=-2.3;
            };
        };
        class Draw
        {
            color[]={0,1,0,1};
            alpha=0.5;
            condition="on";
            class PlaneMovementCrosshair
            {
                type="line";
                width=4;
                points[]=
                {

                    {
                        "Velocity",
                        {0,-0.02},
                        1
                    },

                    {
                        "Velocity",
                        {0.0099999998,-0.01732},
                        1
                    },

                    {
                        "Velocity",
                        {0.01732,-0.0099999998},
                        1
                    },

                    {
                        "Velocity",
                        {0.02,0},
                        1
                    },

                    {
                        "Velocity",
                        {0.01732,0.0099999998},
                        1
                    },

                    {
                        "Velocity",
                        {0.0099999998,0.01732},
                        1
                    },

                    {
                        "Velocity",
                        {0,0.02},
                        1
                    },

                    {
                        "Velocity",
                        {-0.0099999998,0.01732},
                        1
                    },

                    {
                        "Velocity",
                        {-0.01732,0.0099999998},
                        1
                    },

                    {
                        "Velocity",
                        {-0.02,0},
                        1
                    },

                    {
                        "Velocity",
                        {-0.01732,-0.0099999998},
                        1
                    },

                    {
                        "Velocity",
                        {-0.0099999998,-0.01732},
                        1
                    },

                    {
                        "Velocity",
                        {0,-0.02},
                        1
                    },
                    {},

                    {
                        "Velocity",
                        {0.039999999,0},
                        1
                    },

                    {
                        "Velocity",
                        {0.02,0},
                        1
                    },
                    {},

                    {
                        "Velocity",
                        {-0.039999999,0},
                        1
                    },

                    {
                        "Velocity",
                        {-0.02,0},
                        1
                    },
                    {},

                    {
                        "Velocity",
                        {0,-0.039999999},
                        1
                    },

                    {
                        "Velocity",
                        {0,-0.02},
                        1
                    }
                };
            };
            class MGun
            {
                condition="mgun";
                class Circle
                {
                    type="line";
                    points[]=
                    {

                        {
                            "WeaponAim",
                            {0.0099999998,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.0099999998,0},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0,0.0094594602},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,-0.0094594602},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0,-0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.048999999,-0.046351399},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.07,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.048999999,0.046351399},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.048999999,0.046351399},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.07,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.048999999,-0.046351399},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,-0.066216201},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0,-0.132432},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.07,-0.115216},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.1218,-0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.14,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.1218,0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.07,0.115216},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,0.132432},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.07,0.115216},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.1218,0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.14,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.1218,-0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.07,-0.115216},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,-0.132432},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0,-0.132432},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,-0.151351},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.07,-0.11469},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.079999998,-0.131074},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.121244,-0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.13856401,-0.075675704},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.14,5.7888099e-009},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.16,6.6157799e-009},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.121244,0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.13856401,0.075675704},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {-0.07,0.11469},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.079999998,0.131074},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {1.22392e-008,0.132432},
                            1
                        },

                        {
                            "WeaponAim",
                            {1.39876e-008,0.151351},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.07,0.11469},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.079999998,0.131074},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.121244,0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.13856401,0.075675704},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.14,-1.57924e-009},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.16,-1.80485e-009},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.121244,-0.066216201},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.13856401,-0.075675704},
                            1
                        },
                        {},

                        {
                            "WeaponAim",
                            {0.07,-0.11469},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.079999998,-0.131074},
                            1
                        },
                        {}
                    };
                };
            };
            class BombCrosshairGroup
            {
                type="group";
                condition="bomb";
                class BombCrosshair
                {
                    type="line";
                    width=4;
                    points[]=
                    {

                        {
                            "WeaponAim",
                            {0,-0.1},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.01736,-0.098480001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.034200002,-0.093970001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.050000001,-0.086599998},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.064280003,-0.0766},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.0766,-0.064280003},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.086599998,-0.050000001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.093970001,-0.034200002},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.098480001,-0.01736},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.1,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.098480001,0.01736},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.093970001,0.034200002},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.086599998,0.050000001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.0766,0.064280003},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.064280003,0.0766},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.050000001,0.086599998},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.034200002,0.093970001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0.01736,0.098480001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,0.1},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.01736,0.098480001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.034200002,0.093970001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.050000001,0.086599998},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.064280003,0.0766},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.0766,0.064280003},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.086599998,0.050000001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.093970001,0.034200002},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.098480001,0.01736},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.1,0},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.098480001,-0.01736},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.093970001,-0.034200002},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.086599998,-0.050000001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.0766,-0.064280003},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.064280003,-0.0766},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.050000001,-0.086599998},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.034200002,-0.093970001},
                            1
                        },

                        {
                            "WeaponAim",
                            {-0.01736,-0.098480001},
                            1
                        },

                        {
                            "WeaponAim",
                            {0,-0.1},
                            1
                        },
                        {},

                        {
                            "Velocity",
                            0.001,
                            "WeaponAim",
                            {0,0},
                            1
                        },

                        {
                            "Velocity",
                            {0,0},
                            1
                        }
                    };
                };
            };
        };
    };
};
