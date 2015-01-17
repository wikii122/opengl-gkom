#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include <iostream>
#include "parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadratic.h"

using namespace gkom::dragonfly;

Head::Head():
left(Eye(Left)),
right(Eye(Right))
{}

void Head::draw(long time)
{
	GLMatrixScope scope;
	left.draw();
	right.draw();
	draw_object(time);
}

void Head::draw_object(long time)
{
	GLMatrixScope scope;
	glTranslatef(0, -0.25, 1);
	glRotatef(0, 0, 0.0, 0.0);
	GLQuadratic quadratic;
	gluQuadricNormals(*quadratic, GLU_SMOOTH);
	gluSphere(*quadratic, 0.26, 50, 50);
}

Head::Eye::Eye(Side side):
side(side) {}

void Head::Eye::draw()
{
	if (side == Left) {
		GLMatrixScope scope;
		glScalef(1, 1.2, 1);
		glTranslatef(0.22, 0, 1);
		glRotatef(90, -1, 0, 0.0);
		GLQuadratic quadratic;
		gluQuadricNormals(*quadratic, GLU_SMOOTH);
		gluSphere(*quadratic, 0.28, 50, 50);
	} else {
		GLMatrixScope scope;
		glScalef(1, 1.2, 1);
		glTranslatef(-0.22, 0, 1);
		glRotatef(90, -1, 0.0, 0.0);
		GLQuadratic quadratic;
		gluQuadricNormals(*quadratic, GLU_SMOOTH);
		gluSphere(*quadratic, 0.28, 50, 50);
	}
}