#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "core\dragonfly\parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadratic.h"

void gkom::dragonfly::Body::draw(long time)
{
	GLMatrixScope scope;
	glScalef(1, 1, 2);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0, 0, 0.0, 0.0);

	legs.draw(time);

	GLQuadratic quadratic;
	gluQuadricNormals(*quadratic, GLU_SMOOTH);
	gluSphere(*quadratic, 0.5, 50, 50);
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