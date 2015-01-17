#include "stdafx.h"
#include "GLMatrixScope.h"
#include "gl/GLUT.H"


gkom::GLMatrixScope::GLMatrixScope()
{
	glPushMatrix();
}


gkom::GLMatrixScope::~GLMatrixScope()
{
	glPopMatrix();
}
