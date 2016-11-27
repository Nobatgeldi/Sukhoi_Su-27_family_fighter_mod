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
    frequency="1.0 min (rpm + 0.5)";
    volume="engineOn*camPos*(rpm factor[0.85, 0])";
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
    frequency="1";
    volume="engineOn*camPos*(rpm factor[0.55, 1.0])";
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
    frequency="1";
    volume="engineOn*camPos*(thrust factor[0.5, 1.0])";
    cone[]={3.1400001,3.9200001,2,0.40000001};
  };
  class WindNoiseOut
  {
    sound[]=
    {
      "A3\Sounds_F\air\Plane_Fighter_03\noise",
      1,
      1,
      150
    };
    frequency="(0.1+(1.2*(speed factor[1, 150])))";
    volume="camPos*(speed factor[1, 150])";
  };

  /*	INTERNAL SOUNDS */

  class EngineLowIn
  {
    sound[]=
    {
      "SU_33_Flanker_D\sounds\int-av8b-engine-low",
      0.56234097,
      1
    };
    frequency="1.0 min (rpm + 0.5)";
    volume="(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
  };
  class EngineHighIn
  {
    sound[]=
    {
      "SU_33_Flanker_D\sounds\int-av8b-engine",
      1,
      1
    };
    frequency="1";
    volume="(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
  };
  class ForsageIn
  {
    sound[]=
    {
      "SU_33_Flanker_D\sounds\int-av8b-forsage-1",
      0.56234097,
      1.1
    };
    frequency="1";
    volume="(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
  };
  class WindNoiseIn
  {
    sound[]=
    {
      "A3\Sounds_F\air\Plane_Fighter_03\noise",
      0.70794576,
      1
    };
    frequency="(0.1+(1.2*(speed factor[1, 150])))";
    volume="(1-camPos)*(speed factor[1, 150])";
  };
};
