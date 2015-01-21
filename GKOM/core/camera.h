#pragma once

namespace gkom
{
	class Camera
	{
		double eye_x, eye_y, eye_z;
		double model_x, model_y, model_z;
	public:
		Camera() :
			eye_x(80), eye_y(10), eye_z(20),
			model_x(0), model_y(0), model_z(0)
		{}
		void set(long time);
		void center(); // Dangerous
	};
};