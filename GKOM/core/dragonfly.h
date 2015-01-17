#pragma once
#include <memory>
#include "dragonfly\parts.h"

namespace gkom
{

	class Dragonfly
	{
		void position();
	public:
		Dragonfly();
		void draw(long t);
	private:
		dragonfly::Body body;
		dragonfly::Head head;
		dragonfly::Tail tail;
		dragonfly::Wings wings;
	};
};

