#include "stdafx.h"
#include "GLMatrixScope.h"
#include "gl/GLUT.H"


GLMatrixScope::GLMatrixScope()
{
	glPushMatrix();
}


GLMatrixScope::~GLMatrixScope()
{
	glPopMatrix();
}
