		maxOmega				= 2000; // this parameters affects maximum engine rpm which also limits maximal wheel rotational speed
		antiRollbarForceCoef 	= 0 ;
		antiRollbarForceLimit 	= 0;
		antiRollbarSpeedMin 	= 50;
		antiRollbarSpeedMax 	= 300;

		class Wheels
		{
			class Wheel_1
			{
				boneName					= "Wheel_1";
				steering					= true;
				side						= "left";
				center						= "Wheel_1_center";
				boundary					= "Wheel_1_rim";
				width						= 0.2;
				mass						= 20;
				MOI							= 0.4;
				dampingRate					= 0.1;
				dampingRateDamaged			= 1;
				dampingRateDestroyed		= 1000;
				maxBrakeTorque				= 0;
				maxHandBrakeTorque			= 0;
				suspTravelDirection[]		= {0, -1, 0};
				suspForceAppPointOffset		= "Wheel_1_center";
				tireForceAppPointOffset		= "Wheel_1_center";
				maxCompression				= 0.3;
				maxDroop					= 0.3;
				sprungMass					= 1500;
				springStrength				= 150000;
				springDamperRate			= 30000;
				longitudinalStiffnessPerUnitGravity	= 300;
				latStiffX					= 3;
				latStiffY					= 20.0;
				frictionVsSlipGraph[]		= {{0, 1}, {0.5, 1}, {1,1}};
			};
			class Wheel_2: Wheel_1
			{
				steering					= false;
				boneName					= "Wheel_2";
				center						= "Wheel_2_center";
				boundary					= "Wheel_2_rim";
				mass						= 35;
				MOI							= 1.575;
				width						= 0.3;
				maxBrakeTorque				= 1500;
				maxCompression				= 0.3;
				maxDroop					= 0.3;
				sprungMass					= 3350;
				springStrength				= 335000;
				springDamperRate			= 67000;
				longitudinalStiffnessPerUnitGravity	= 500;
				suspForceAppPointOffset		= "Wheel_2_center";
				tireForceAppPointOffset		= "Wheel_2_center";
			};
			class Wheel_3: Wheel_2
			{
				boneName					= "Wheel_3";
				side						= "right";
				center						= "Wheel_3_center";
				boundary					= "Wheel_3_rim";
				suspForceAppPointOffset		= "Wheel_3_center";
				tireForceAppPointOffset		= "Wheel_3_center";
			};
		};