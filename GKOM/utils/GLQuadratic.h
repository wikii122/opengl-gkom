#pragma once
#include <Windows.h>
#include <gl/GLU.h>

namespace gkom
{
	class GLQuadratic
	{
		GLUquadricObj* obj;
	public:
		GLQuadratic();
		~GLQuadratic();
		
		GLUquadricObj* operator*();
	};
};