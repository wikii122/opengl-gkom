#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "core\dragonfly\parts.h"
#include "utils\GLMatrixScope.h"

gkom::dragonfly::Body::Body()
{}

void gkom::dragonfly::Body::display()
{
	GLMatrixScope();
	glScalef(1, 1, 2);
	GLUquadricObj *qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, 3);
	gluSphere(qObj, 0.5, 50, 50);
}