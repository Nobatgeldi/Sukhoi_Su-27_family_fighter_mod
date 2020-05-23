
class CfgCloudlets {
	class BodyTrail {};

	class BodyTrailMed {};

	class SU_33_BodyTrail : BodyTrail {
		lifeTime = 0.0002;
		lifeTimeVar = 0.0001;
		size[] = {1.5};
		sizeVar = 0.75;
		colorCoef[] = {1, 1, 1, "(accelY interpolate [80,250,0,1]) * ((altitude*altitude) interpolate [400,10000,2,0.5])"};
	};

	class SU_33_BodyTrailMed : BodyTrailMed {
		lifeTime = 0.0001;
		lifeTimeVar = 5e-005;
		size[] = {1.5};
		sizeVar = 0.75;
		colorCoef[] = {1, 1, 1, "(accelY interpolate [80,250,0,1]) * ((altitude*altitude) interpolate [400,10000,2,0.5])"};
	};
};
