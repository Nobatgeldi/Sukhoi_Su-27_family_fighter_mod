class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		su_33_pilot="su_33_pilot";
		//commander="commander";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class su_33_pilot: Crew
		{
			file="\SU_33_Flanker_D\anim\su33_pilot.rtm";
			interpolateTo[]=
			{
				"su33_pilot_dead",
				1
			};
		};
		class su33_pilot_dead: DefaultDie
		{
			actions="DeadActions";
			speed=0.5;
			looped="false";
			terminal=1;
			file="\SU_33_Flanker_D\anim\su33_pilot_dead.rtm";
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
	};
};
