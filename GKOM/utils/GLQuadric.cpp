#include "stdafx.h"
#include "GLQuadric.h"

using namespace gkom;

std::stack<GLUquadric*> GLQuadric::stack = std::stack<GLUquadric*> ();

GLQuadric::GLQuadric()
{
	obj = gluNewQuadric();
	stack.push(obj);
}

GLQuadric::~GLQuadric()
{
	//gluDeleteQuadric(obj);
}

GLUquadricObj* GLQuadric::operator*() const
{
	return obj;
}

void GLQuadric::clean_stack()
{
	while (!stack.empty())
	{
		gluDeleteQuadric(stack.top());
		stack.pop();
	}
}
