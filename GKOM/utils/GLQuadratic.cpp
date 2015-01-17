#include "stdafx.h"
#include "GLQuadratic.h"


gkom::GLQuadratic::GLQuadratic()
{
	obj = gluNewQuadric();
}


gkom::GLQuadratic::~GLQuadratic()
{
	gluDeleteQuadric(obj);
}

GLUquadricObj* gkom::GLQuadratic::operator*()
{
	return obj;
}
