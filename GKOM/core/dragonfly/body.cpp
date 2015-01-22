#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "core\dragonfly\parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadric.h"

void gkom::dragonfly::Body::draw(long time)
{
	GLMatrixScope scope;
	glScalef(1, 1, 3);

	legs.draw(time);

	GLQuadric quadratic;
	gluQuadricNormals(*quadratic, GLU_SMOOTH);
	gluSphere(*quadratic, 0.4, 64, 64);
}

void gkom::dragonfly::Body::Legs::draw(long time)
{
	glLineWidth(2.5);
	glBegin(GL_LINES);

	glVertex3f(0, 0, 0);
	glVertex3f(0.5, -0.7, 0.5);

	glVertex3f(0, 0, 0);
	glVertex3f(-0.5, -0.7, 0.5);

	glVertex3f(0, 0, 0);
	glVertex3f(-0.5, -0.7, -0.5);

	glVertex3f(0, 0, 0);
	glVertex3f(0.5, -0.7, -0.5);

	glVertex3f(0, 0, 0);
	glVertex3f(0.5, -0.7, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(-0.5, -0.7, 0);

	glEnd();
}