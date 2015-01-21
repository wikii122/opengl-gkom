#pragma once
#include <memory>
#include "core\dragonfly.h"
#include "core\camera.h"
#include "skybox.h"
namespace gkom
{
	class Scene
	{
		Dragonfly dragonfly;
		Camera camera;
		Skybox skybox;
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

