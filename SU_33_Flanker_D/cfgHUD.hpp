// common definition for all vectors projected into HUD space

enableParallax = true;
#define PosY0Center (0.38)
#define PosY0CenterAdjust 0.13
#define PosYCenterHorizont 0.38
#define PosX0Center 0.50
#define SizeX10deg (0.94+0.03)
#define SizeY10deg (1.3-0.2)

#define XtoYscale  (SizeX10deg/SizeY10deg)

#define XY_Scaled(xx,yy) __EVAL(xx),__EVAL((yy)/(XtoYscale))

#define CIRCLE(bone,scale) \
{bone,{0,__EVAL(-scale/XtoYscale)},1},{bone,{__EVAL(+0.7*scale),__EVAL(-0.7*scale/XtoYscale)},1}, \
{bone,{+scale,0},1},                  {bone,{__EVAL(+0.7*scale),__EVAL(+0.7*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(+scale/XtoYscale)},1},{bone,{__EVAL(-0.7*scale),__EVAL(+0.7*scale/XtoYscale)},1}, \
{bone,{-scale,0},1},                  {bone,{__EVAL(-0.7*scale),__EVAL(-0.7*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(-scale/XtoYscale)},1}

#define CIRCLE_BIG(bone,scale) \
{bone,{0,__EVAL(-scale/XtoYscale)},1},{bone,{__EVAL(+0.50*scale),__EVAL(-0.87*scale/XtoYscale)},1},{bone,{__EVAL(+0.87*scale),__EVAL(-0.50*scale/XtoYscale)},1}, \
{bone,{__EVAL(+scale),0},1},                  {bone,{__EVAL(+0.87*scale),__EVAL(+0.50*scale/XtoYscale)},1},{bone,{__EVAL(+0.50*scale),__EVAL(+0.87*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(+scale/XtoYscale)},1},{bone,{__EVAL(-0.50*scale),__EVAL(+0.87*scale/XtoYscale)},1},{bone,{__EVAL(-0.87*scale),__EVAL(+0.50*scale/XtoYscale)},1}, \
{bone,{__EVAL(-scale),0},1},                  {bone,{__EVAL(-0.87*scale),__EVAL(-0.50*scale/XtoYscale)},1},{bone,{__EVAL(-0.50*scale),__EVAL(-0.87*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(-scale/XtoYscale)},1}


#define POINT_ON_CIRCLE(bone,scale,angle) {bone,{__EVAL(sin(angle)*scale),__EVAL(cos(angle)*scale/XtoYscale)},1}

#define CIRCLE_BIG2(bone,scale) \
POINT_ON_CIRCLE(bone,scale,0),POINT_ON_CIRCLE(bone,scale,15),POINT_ON_CIRCLE(bone,scale,30),POINT_ON_CIRCLE(bone,scale,45),POINT_ON_CIRCLE(bone,scale,60), \
POINT_ON_CIRCLE(bone,scale,75),POINT_ON_CIRCLE(bone,scale,90),POINT_ON_CIRCLE(bone,scale,105),POINT_ON_CIRCLE(bone,scale,120),POINT_ON_CIRCLE(bone,scale,135), \
POINT_ON_CIRCLE(bone,scale,150),POINT_ON_CIRCLE(bone,scale,165),POINT_ON_CIRCLE(bone,scale,180),POINT_ON_CIRCLE(bone,scale,195),POINT_ON_CIRCLE(bone,scale,210), \
POINT_ON_CIRCLE(bone,scale,225),POINT_ON_CIRCLE(bone,scale,240),POINT_ON_CIRCLE(bone,scale,255),POINT_ON_CIRCLE(bone,scale,270),POINT_ON_CIRCLE(bone,scale,285), \
POINT_ON_CIRCLE(bone,scale,300),POINT_ON_CIRCLE(bone,scale,315),POINT_ON_CIRCLE(bone,scale,330),POINT_ON_CIRCLE(bone,scale,345),POINT_ON_CIRCLE(bone,scale,360)


#define CIRCLE_MARK(bone,scaleIn,scaleOut,angle) \
{bone,{__EVAL((scaleIn) *sin(angle)),__EVAL(-(scaleIn) *cos(angle)/XtoYscale)},1}, \
{bone,{__EVAL((scaleOut)*sin(angle)),__EVAL(-(scaleOut)*cos(angle)/XtoYscale)},1}

#define CIRCLE_MARK_CENTER(XX,YY,scaleIn,scaleOut,angle) \
{{__EVAL(XX+(scaleIn) *sin(angle)),__EVAL(YY -(scaleIn) *cos(angle)/XtoYscale)},1}, \
{{__EVAL(XX+(scaleOut)*sin(angle)),__EVAL(YY -(scaleOut)*cos(angle)/XtoYscale)},1}


#define POINT(bone,xx,yy) \
{bone,{__EVAL(xx),__EVAL((yy)/(XtoYscale))},1}

#define POINT2(xx,yy) \
{{__EVAL(xx),__EVAL((yy)/(XtoYscale))},1}

#define POINT_END() {}

#define DOT(xx,yy) \
POINT2((xx)-0.0075,yy),POINT2((xx)+0.0075,yy),POINT_END(),POINT2(xx,(yy)-0.0075),POINT2(xx,(yy)+0.0075),POINT_END()

#define INSTRUMENT(xx,yy,scale) \
DOT(xx,(yy)+(scale)), \
DOT((xx)+((scale)* sin 36),(yy)+((scale)* cos 36)), \
DOT((xx)+((scale)* sin (36*2)),(yy)+((scale)* cos (36*2))), \
DOT((xx)+((scale)* sin (36*3)),(yy)+((scale)* cos (36*3))), \
DOT((xx)+((scale)* sin (36*4)),(yy)+((scale)* cos (36*4))), \
DOT((xx)+((scale)* sin (36*5)),(yy)+((scale)* cos (36*5))), \
DOT((xx)+((scale)* sin (36*6)),(yy)+((scale)* cos (36*6))), \
DOT((xx)+((scale)* sin (36*7)),(yy)+((scale)* cos (36*7))), \
DOT((xx)+((scale)* sin (36*8)),(yy)+((scale)* cos (36*8))), \
DOT((xx)+((scale)* sin (36*9)),(yy)+((scale)* cos (36*9)))




#define DEF_HORIZONTPlus(XX) \
	class LevelP##XX:Level0\
	{\
		type=line;\
		points[]=\
		{\
			{LevelP##XX,{-0.20,+0.03},1},\
			{LevelP##XX,{-0.20,0},1},\
			{LevelP##XX,{-0.05,0},1},\
			{},\
			{LevelP##XX,{ 0.05,0},1},\
			{LevelP##XX,{+0.20,0},1},\
			{LevelP##XX,{+0.20,+0.03},1}\
		};\
	}; \
	class VALP_1_##XX\
	{\
		type=text;\
		source=static;\
		text=#XX;\
		align=right;\
		scale=1;\
		sourceScale=1;\
		pos[]={LevelP##XX,{__EVAL(-0.23+0.05),0.032},1};\
		right[]={LevelP##XX,{__EVAL(-0.15+0.05),0.032},1};\
		down[]={LevelP##XX,{__EVAL(-0.23+0.05),0.082},1};\
	}

#define DEF_HORIZONTMinus(XX) \
	class LevelM##XX:Level0\
	{\
		type=line;\
		points[]=\
		{\
			{LevelM##XX,{-0.20,__EVAL(XX*0.001*(20-5)/(20-5))},1},\
			{LevelM##XX,{-0.17,__EVAL(XX*0.001*(17-5)/(20-5))},1},\
			{}, \
			{LevelM##XX,{-0.14,__EVAL(XX*0.001*(14-5)/(20-5))},1},\
			{LevelM##XX,{-0.11,__EVAL(XX*0.001*(11-5)/(20-5))},1},\
			{}, \
			{LevelM##XX,{-0.08,__EVAL(XX*0.001*(8-5)/(20-5))},1},\
			{LevelM##XX,{-0.05,0},1},\
			{LevelM##XX,{-0.05,-0.03},1},\
			{},\
			{LevelM##XX,{+0.05,-0.03},1},\
			{LevelM##XX,{0.05,0},1},\
			{LevelM##XX,{+0.08,__EVAL(XX*0.001*(8-5)/(20-5))},1},\
			{},\
			{LevelM##XX,{+0.11,__EVAL(XX*0.001*(11-5)/(20-5))},1},\
			{LevelM##XX,{+0.14,__EVAL(XX*0.001*(14-5)/(20-5))},1},\
			{}, \
			{LevelM##XX,{+0.17,__EVAL(XX*0.001*(17-5)/(20-5))},1},\
			{LevelM##XX,{+0.20,__EVAL(XX*0.001*(20-5)/(20-5))},1}\
		};\
	}; \
	class VALM_1_##XX\
	{\
		type=text;\
		source=static;\
		text=-##XX;\
		align=right;\
		scale=1;\
		sourceScale=1;\
		pos[]={LevelM##XX,{__EVAL(-0.23+0.05),-0.082},1};\
		right[]={LevelM##XX,{__EVAL(-0.15+0.05),-0.082},1};\
		down[]={LevelM##XX,{__EVAL(-0.23+0.05),-0.032},1};\
	}

class Pos10Vector
{
	type=vector;
	// position of 0-degree dive line
	pos0[]={__EVAL(PosX0Center),__EVAL(PosY0Center)};
	// position of 10 degree bank and 10-degree dive (used to adjust scale)
	pos10[]={__EVAL(PosX0Center+SizeX10deg),__EVAL(PosY0Center+SizeY10deg)};
};

topLeft = "HUD LH";
topRight = "HUD PH";
bottomLeft = "HUD LD";
/// adjust position inside of memory points LOD
borderLeft = 0;
borderRight = 0;
borderTop = 0;
borderBottom = 0;
color[]={0,1,0,0.1}; // master color

class Bones
{

	class PlaneW
	{
		type=fixed;
		pos[]={PosX0Center,PosYCenterHorizont};
	};
	class center
	{
		type=fixed;
		pos[]={PosX0Center,0.5};
	};

	class WeaponAim: Pos10Vector
	{
		source=weapon;
	};
	class Target: Pos10Vector
	{
		source=target;
	};
	class Velocity: Pos10Vector
	{
		type=vector;
		source=velocity;
		pos0[]={0.5,__EVAL(PosY0Center)};
		pos10[]={__EVAL(0.5+SizeX10deg),__EVAL(PosY0Center+SizeY10deg)};
	};
	class ILS_H
	{
		type=ils;
		// position when centered
		pos0[]={0.5,__EVAL(PosY0Center)};
		// position when 3-degree off in both directions
		pos3[]={__EVAL(0.5+SizeX10deg*3/10),__EVAL(PosY0Center)};
	};
	class ILS_W:ILS_H
	{
		pos3[]={0.5,__EVAL(PosY0Center+SizeY10deg*3/10)};
	};
	class Level0: Pos10Vector
	{
//		pos0[]={0.5,0.37};
//		pos10[]={__EVAL(0.5+0.65),__EVAL(0.34+0.6*XtoYscale)};
		pos0[]={PosX0Center,PosYCenterHorizont};
		pos10[]={__EVAL(PosX0Center+SizeX10deg),__EVAL(PosYCenterHorizont+SizeY10deg)};
		type=horizon;
		// horizon angle to which this line corresponds to
		angle=0;
	};
	class ASL_Instrument
	{
		type=rotational;
		source=altitudeASL;
		center[]={0,0};
		min=0;
		max=10000;
		minAngle=0;
		maxAngle=+36000;
		aspectRatio = __EVAL(1/XtoYscale);
	};

#define  HorizonBankScaleY 0.4
	class HorizonBankRot
	{
		type=rotational;
		source=horizonBank;
		center[]={PosX0Center,HorizonBankScaleY};
		min= __EVAL(-3.1416/90*15);
		max= __EVAL(3.1416/90*15);
		minAngle= __EVAL(180-83/4);
		maxAngle= __EVAL(180+83/4);
		aspectRatio = 1;
	};
	class Speed_Instrument:ASL_Instrument
	{
		source=speed;
		max=__EVAL(1000/3.6);
		maxAngle=+3600;
	};
	class ASL_Instrument_center
	{
		type=fixed;
		pos[]={0.85,__EVAL(PosY0CenterAdjust/XtoYscale)};
	};
	class Speed_Instrument_center
	{
		type=fixed;
		pos[]={0.15,__EVAL(PosY0CenterAdjust/XtoYscale)};
	};


	class LevelP5: Level0 {angle=+5;};
	class LevelM5: Level0 {angle=-5;};
	class LevelP10: Level0 {angle=+10;};
	class LevelM10: Level0 {angle=-10;};
	class LevelP15: Level0 {angle=+15;};
	class LevelM15: Level0 {angle=-15;};
	class LevelP20: Level0 {angle=+20;};
	class LevelM20: Level0 {angle=-20;};
	class LevelP25: Level0 {angle=+25;};
	class LevelM25: Level0 {angle=-25;};
	class LevelP30: Level0 {angle=+30;};
	class LevelM30: Level0 {angle=-30;};
	class LevelP35: Level0 {angle=+35;};
	class LevelM35: Level0 {angle=-35;};
	class LevelP40: Level0 {angle=+40;};
	class LevelM40: Level0 {angle=-40;};
	class LevelP45: Level0 {angle=+45;};
	class LevelM45: Level0 {angle=-45;};
	class LevelP50: Level0 {angle=+50;};
	class LevelM50: Level0 {angle=-50;};

	class LevelP55: Level0 {angle=+55;};
	class LevelM55: Level0 {angle=-55;};
	class LevelP60: Level0 {angle=+60;};
	class LevelM60: Level0 {angle=-60;};

	class LevelP65: Level0 {angle=+65;};
	class LevelM65: Level0 {angle=-65;};
	class LevelP70: Level0 {angle=+70;};
	class LevelM70: Level0 {angle=-70;};

	class LevelP75: Level0 {angle=+75;};
	class LevelM75: Level0 {angle=-75;};
	class LevelP80: Level0 {angle=+80;};
	class LevelM80: Level0 {angle=-80;};

	class LevelP85: Level0 {angle=+85;};
	class LevelM85: Level0 {angle=-85;};
	class LevelP90: Level0 {angle=+90;};
	class LevelM90: Level0 {angle=-90;};
};
class Draw
{
	alpha=0.4;
	color[]={0.0,0.3,0.05};
	condition="on";

	//color[]={0.5,0.05,0.05};
	class PlaneW
	{
		clipTL[]={0.0,1.0};
		clipBR[]={1.0,0.0};

		type=line;
		points[]={
			POINT(PlaneW,-0.03, 0.0), POINT(PlaneW,-0.01, 0.0),{},
			POINT(PlaneW,0.03, 0.0), POINT(PlaneW,0.01, 0.0),{},
			POINT(PlaneW,0.0, -0.03), POINT(PlaneW,0.0, -0.01),{},
			POINT(PlaneW,0.0, 0.03), POINT(PlaneW,0.0, 0.01),{}
		};
	};
	class PlaneHeading
	{
		clipTL[]={0.0,1.0};
		clipBR[]={1.0,0.0};
		type=line;
		points[]={
		CIRCLE(Velocity,0.02),{},
			{Velocity, { 0.04, __EVAL(0/XtoYscale)}, 1}, {Velocity, { 0.02, __EVAL(0/XtoYscale)}, 1},{},
			{Velocity, {-0.04, __EVAL(0/XtoYscale)}, 1}, {Velocity, {-0.02, __EVAL(0/XtoYscale)}, 1},{},
			{Velocity, {0, __EVAL(-0.04/XtoYscale)}, 1}, {Velocity, {0, __EVAL(-0.02/XtoYscale)}, 1},{}
		};
	};
	class Static
	{
		clipTL[]={0.0,0.1};
		clipBR[]={1.0,0.0};
		type=line;
		points[]={
			INSTRUMENT(0.85,PosY0CenterAdjust,0.1),
			INSTRUMENT(0.15,PosY0CenterAdjust,0.08),

			{Speed_Instrument_center,1,Speed_Instrument,{0,__EVAL(0.08)},1},
			{Speed_Instrument_center,1,Speed_Instrument,{0,__EVAL(0.04)},1},{},
			{ASL_Instrument_center,1,ASL_Instrument,{0,__EVAL(0.05)},1},
			{ASL_Instrument_center,1,ASL_Instrument,{0,__EVAL(0.10)},1},{},

			{{XY_Scaled(0.50, 0.08)}, 1},{{XY_Scaled(0.505, 0.10)}, 1},{{XY_Scaled(0.495, 0.10)}, 1},{{XY_Scaled(0.50, 0.08)}, 1},{},

			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.32,0.35,180-0),{},
			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.32,0.35,180-45/2),{},
			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.32,0.35,180+45/2),{},
			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.33,0.35,180-45/2/3),{},
			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.33,0.35,180+45/2/3),{},
			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.33,0.35,180-45/2/3*2),{},
			CIRCLE_MARK_CENTER(PosY0CenterAdjust,HorizonBankScaleY,0.33,0.35,180+45/2/3*2),{}
		};
	};

	class HorizonBankRot
	{
		type=line;
		points[]=
		{
			{HorizonBankRot,{XY_Scaled(0,0.35)},1},{HorizonBankRot,{XY_Scaled(0.01,0.37)},1},{HorizonBankRot,{XY_Scaled(-0.01,0.37)},1},{HorizonBankRot,{XY_Scaled(0,0.35)},1}
		};
	};

	class Horizont
	{
		clipTL[]={0.0,0.0};
		clipBR[]={1.0,1.0};

		class Dimmed
		{
			class Level0
			{
				type=line;
				points[]=
				{
					{Level0,{1,0},1},{Level0,{0.08,0},1},{},{Level0,{-0.08,0},1},{Level0,{-1,0},1},{},
					{Level0,{1,0.001},1},{Level0,{0.08,0.001},1},{},{Level0,{ -0.08,0.001},1},{Level0,{-1,0.001},1}
				};
			};
			DEF_HORIZONTMinus(5);
			DEF_HORIZONTPlus(5);
			DEF_HORIZONTMinus(10);
			DEF_HORIZONTPlus(10);
			DEF_HORIZONTMinus(15);
			DEF_HORIZONTPlus(15);
			DEF_HORIZONTMinus(20);
			DEF_HORIZONTPlus(20);
			DEF_HORIZONTMinus(25);
			DEF_HORIZONTPlus(25);
			DEF_HORIZONTMinus(30);
			DEF_HORIZONTPlus(30);
			DEF_HORIZONTMinus(35);
			DEF_HORIZONTPlus(35);
			DEF_HORIZONTMinus(40);
			DEF_HORIZONTPlus(40);
			DEF_HORIZONTMinus(45);
			DEF_HORIZONTPlus(45);
			DEF_HORIZONTMinus(50);
			DEF_HORIZONTPlus(50);
			DEF_HORIZONTMinus(55);
			DEF_HORIZONTPlus(55);
			DEF_HORIZONTMinus(60);
			DEF_HORIZONTPlus(60);
			DEF_HORIZONTMinus(65);
			DEF_HORIZONTPlus(65);
			DEF_HORIZONTMinus(70);
			DEF_HORIZONTPlus(70);
			DEF_HORIZONTMinus(75);
			DEF_HORIZONTPlus(75);
			DEF_HORIZONTMinus(80);
			DEF_HORIZONTPlus(80);
			DEF_HORIZONTMinus(85);
			DEF_HORIZONTPlus(85);
			DEF_HORIZONTMinus(90);
			DEF_HORIZONTPlus(90);


		};
	};
#ifndef NO_RADAR
	class RadarTargets
	{
		type=radar;
		pos0[]={__EVAL(PosX0Center),__EVAL(PosY0Center)};
		pos10[]={__EVAL(PosX0Center+SizeX10deg),__EVAL(PosY0Center+SizeY10deg)};

		points[]={
			POINT2(-0.05,-0.05),
			POINT2(+0.05,-0.05),
			POINT2(+0.05,+0.05),
			POINT2(-0.05,+0.05),
			POINT2(-0.05,-0.05)
		};
	};
#endif
	class MGun
	{
		condition="mgun";
		class Circle
		{
			type=line;
			points[]={
			};
		};
	};


	class Bomb
	{
		condition="bomb";
		class Circle
		{
			type=line;
			points[]={
				CIRCLE_BIG(center,0.1),{},
				{Velocity,0.001,center,{0.0, 0.0}, 1}, {Velocity,{0.0, 0.0}, 1},{},
				POINT(Target,0.0,-0.07),
				POINT(Target,+0.07,0.0),
				POINT(Target,0.0,+0.07),
				POINT(Target,-0.07,0.0),
				POINT(Target,0.0,-0.07)
			};
		};
	};
	class AAMissile
	{
		condition="AAmissile";
		class Circle
		{
			type=line;
			points[]={
				CIRCLE_BIG2(center,0.20),{},
				POINT(Target,0.0,-0.07),
				POINT(Target,+0.07,0.0),
				POINT(Target,0.0,+0.07),
				POINT(Target,-0.07,0.0),
				POINT(Target,0.0,-0.07)
			};
		};
	};
	class ATMissile
	{
		condition="ATmissile";
		class Circle
		{
			type=line;
			points[]={
				CIRCLE_BIG2(center,0.16),{},

				POINT(Target,0.0,-0.07),
				POINT(Target,+0.07,0.0),
				POINT(Target,0.0,+0.07),
				POINT(Target,-0.07,0.0),
				POINT(Target,0.0,-0.07)
			};
		};
	};
	class Rockets
	{
		condition="Rocket";
		class Circle
		{
			type=line;
			points[]={
				CIRCLE_BIG(WeaponAim,0.12),{}
			};
		};
	};


	class SpeedNumber
	{
		type=text;
		align=center;
		scale=1; // text size
		source=speed;
		sourceScale=3.6; // convert from m/s to km/h
		pos[]={{XY_Scaled(0.06+0.078,PosY0CenterAdjust-0.025)},1};
		right[]={{XY_Scaled(0.14+0.078,PosY0CenterAdjust-0.025)},1};
		down[]={{XY_Scaled(0.06+0.078,PosY0CenterAdjust+0.025)},1};
	};

	class AltNumber:SpeedNumber
	{
		source=altitudeASL;
		sourceScale=1;
		pos[]={{XY_Scaled(0.86-0.029,PosY0CenterAdjust-0.025)},1};
		right[]={{XY_Scaled(0.94-0.029,PosY0CenterAdjust-0.025)},1};
		down[]={{XY_Scaled(0.86-0.029,PosY0CenterAdjust+0.025)},1};
	};
	class AltNumberAGL
	{
		class text
		{
			type=text;
			source=static;
			text="H";
			align=right;
			scale=0.5; // text size
			sourceScale=1;
			pos[]={{XY_Scaled(0.75,0.34)},1};
			right[]={{XY_Scaled(0.83,0.34)},1};
			down[]={{XY_Scaled(0.75,0.39)},1};
		};
		class BOX
		{
			type=line;
			points[]={
				POINT2(0.80,0.390),
				POINT2(0.98,0.390),
				POINT2(0.98,0.340),
				POINT2(0.80,0.340),
				POINT2(0.80,0.390)
			};
		};
		class AltNumber:SpeedNumber
		{
			source=altitudeAGL;
			sourceScale=1;
			align=right;
			pos[]={{XY_Scaled(0.87,0.34)},1};
			right[]={{XY_Scaled(0.95,0.34)},1};
			down[]={{XY_Scaled(0.87,0.39)},1};
		};
	};

	class Gear
	{
		condition="ils";
		class text
		{
			type=text;
			source=static;
			text="GEAR";
			align=right;
			scale=0.5; // text size
			sourceScale=1;
			pos[]={{XY_Scaled(0.84,0.78)},1};
			right[]={{XY_Scaled(0.90,0.78)},1};
			down[]={{XY_Scaled(0.84,0.815)},1};

		};
	};
	class Flaps
	{
		condition="flaps";
		class text
		{
			type=text;
			source=static;
			text="FLAPS";
			align=right;
			scale=0.5; // text size
			sourceScale=1;
			pos[]={{XY_Scaled(0.84,0.825)},1};
			right[]={{XY_Scaled(0.90,0.825)},1};
			down[]={{XY_Scaled(0.84,0.86)},1};
		};
	};
	class weapons
	{
		type=text;
		source=weapon;
		align=right;
		scale=0.5; // text size
		sourceScale=1;
		pos[]={{XY_Scaled(0.1,0.78)},1};
		right[]={{XY_Scaled(0.16,0.78)},1};
		down[]={{XY_Scaled(0.1,0.815)},1};
	};
	class ammo
	{
		type=text;
		source=ammo;
		align=right;
		scale=0.5; // text size
		sourceScale=1;
		pos[]={{XY_Scaled(0.1,0.825)},1};
		right[]={{XY_Scaled(0.16,0.825)},1};
		down[]={{XY_Scaled(0.1,0.86)},1};
	};

	class HeadingScale
	{
		type=scale;
		scale=1; // text size
		source=Heading;
		sourceScale=0.1;
		align=center;

		pos[]={XY_Scaled(0.20,-0.005+0.02)};
		right[]={XY_Scaled(0.26,-0.005+0.02)};
		down[]={XY_Scaled(0.20,0.045+0.02)};

		lineXleft = __EVAL(0.06/XtoYscale+0.02);
		lineYright = __EVAL(0.05/XtoYscale+0.02);
		lineXleftMajor = __EVAL(0.06/XtoYscale+0.02);
		lineYrightMajor = __EVAL(0.04/XtoYscale+0.02);

		bottom= 0.80;
		center = 0.50;
		top = 0.20;
		step = __EVAL(18/90);
		StepSize = __EVAL((0.80- 0.2)/20);

		horizontal = true;
		min = none;
		max = none;
		numberEach = 5;
		majorLineEach = 5;
	};


#define SCALE 0.6
	class ILS
	{
		condition="ils";
		class Glideslope
		{
			clipTL[]={0.0,0.0};
			clipBR[]={1.0,1.0};

			class ILS
			{
				type=line;
				points[]={
					POINT(ILS_W,-0.4*SCALE,0*SCALE),	POINT(ILS_W,+0.4*SCALE,0*SCALE),{},
					POINT(ILS_W,0*SCALE,0.04*SCALE),	POINT(ILS_W,0*SCALE,-0.04*SCALE),{},
					POINT(ILS_W,0.2*SCALE,0.04*SCALE),	POINT(ILS_W,0.2*SCALE,-0.04*SCALE),{},
					POINT(ILS_W,0.4*SCALE,0.04*SCALE),	POINT(ILS_W,0.4*SCALE,-0.04*SCALE),{},
					POINT(ILS_W,-0.2*SCALE,0.04*SCALE),	POINT(ILS_W,-0.2*SCALE,-0.04*SCALE),{},
					POINT(ILS_W,-0.4*SCALE,0.04*SCALE),	POINT(ILS_W,-0.4*SCALE,-0.04*SCALE),{},
					POINT(ILS_H,0*SCALE,-0.4*SCALE),	POINT(ILS_H,0*SCALE,+0.4*SCALE),{},
					POINT(ILS_H,0.04*SCALE,0*SCALE),	POINT(ILS_H,-0.04*SCALE,0*SCALE),{},
					POINT(ILS_H,0.04*SCALE,0.2*SCALE),	POINT(ILS_H,-0.04*SCALE,0.2*SCALE),{},
					POINT(ILS_H,0.04*SCALE,0.4*SCALE),	POINT(ILS_H,-0.04*SCALE,0.4*SCALE),{},
					POINT(ILS_H,0.04*SCALE,-0.2*SCALE),	POINT(ILS_H,-0.04*SCALE,-0.2*SCALE),{},
					POINT(ILS_H,0.04*SCALE,-0.4*SCALE),	POINT(ILS_H,-0.04*SCALE,-0.4*SCALE)
				};
			};
		};
	};
};