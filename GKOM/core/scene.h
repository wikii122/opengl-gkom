#pragma once
#include <memory>
#include "core/dragonfly.h"


namespace gkom
{
	class Scene
	{
		Dragonfly dragonfly;
		long time;
	public:
		Scene() :
			time(0) {}

		void init();
		void draw();
		void reshape(int width, int heigth);
	private:
		void init_light();
		void init_scene();
		void init_textures();
	};
};

