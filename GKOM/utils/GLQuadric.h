#pragma once
#include <stack>
#include <Windows.h>
#include <gl/GLU.h>

namespace gkom
{
	class GLQuadric
	{
		GLUquadricObj* obj;
		static std::stack<GLUquadric*> stack;
	public:
		GLQuadric();
		~GLQuadric();
		
		GLUquadricObj* operator*() const;

		static void clean_stack();
	};
};