#include "stdafx.h"
#include <cmath>
#include <iostream>
#include "parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadric.h"

using namespace gkom::dragonfly;

Wings::Wings():
left(Wing(Left)),
right(Wing(Right))
{}

Wings::Wing::Wing(Side side) :
side(side) {}

void Wings::draw(long time)
{
	GLMatrixScope scope;
	left.draw(time);
	right.draw(time);
}

void Wings::Wing::draw(long time)
{
	int angle = 40.0 * std::sin(((double)time)*.11);
	if (side == Left) {
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.3f, 0);
			glRotatef(-angle, 0, 0, 1);
			glTranslatef(1.9f, 0, 0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadric quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.3f, 0);
			glRotatef(-angle, 0, 0, 1);
			glTranslatef(1.9f, 0, -0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadric quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
	} else {
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.4f, 0);
			glRotatef(angle, 0, 0, 1);
			glTranslatef(-1.9f, 0, -0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadric quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.4f, 0);
			glRotatef(angle, 0, 0, 1);
			glTranslatef(-1.9f, 0, 0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadric quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
	}
}