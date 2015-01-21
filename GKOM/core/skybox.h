#pragma once
#include "core\camera.h"
namespace gkom
{
	class Skybox
	{
		int const size = 40;
	public:
		void init();
		void draw(Camera&);
	};
};

