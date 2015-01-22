#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include <iostream>
#include "parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadric.h"
#include "utils\textures.h"

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
	glTranslatef(0, -0.2, 1);
	GLQuadric quadratic;
	gluQuadricNormals(*quadratic, GLU_SMOOTH);
	gluSphere(*quadratic, 0.22, 64, 64);
}

Head::Eye::Eye(Side side):
side(side) {}

void Head::Eye::draw()
{
	Texture texture;
	if (side == Left) {
		GLMatrixScope scope;
		glScalef(1, 1.2, 1);
		glTranslatef(0.18, 0, 1.1);
		glRotatef(90, -1, 0, 0.0);
		GLQuadric quadratic;
		gluQuadricNormals(*quadratic, GLU_SMOOTH);
		texture.apply(quadratic, "eye");
		gluSphere(*quadratic, 0.21, 64, 64);
	} else {
		GLMatrixScope scope;
		glScalef(1, 1.2, 1);
		glTranslatef(-0.18, 0, 1.1);
		glRotatef(90, -1, 0.0, 0.0);
		GLQuadric quadratic;
		gluQuadricNormals(*quadratic, GLU_SMOOTH);
		texture.apply(quadratic, "eye");
		gluSphere(*quadratic, 0.21, 64, 64);
	}
}