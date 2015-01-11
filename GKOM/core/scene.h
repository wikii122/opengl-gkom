#pragma once
#include <memory>
#include "core/dragonfly.h"


namespace gkom
{
	class Scene
	{
		std::unique_ptr<Dragonfly> dragonfly;
		long time;
	public:
		Scene() :
			time(0) {}

		void init();
		void display();
		void reshape(int width, int heigth);
	private:
		void init_light();
	};
};

