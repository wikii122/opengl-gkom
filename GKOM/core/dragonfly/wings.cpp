#include "stdafx.h"
#include "parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadratic.h"

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
	if (side == Left) {
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.4f, 0);
			glRotatef(-45, 0, 0, 1);
			glTranslatef(1.9f, 0, 0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadratic quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.4f, 0);
			glRotatef(-45, 0, 0, 1);
			glTranslatef(1.9f, 0, -0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadratic quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
	} else {
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.4f, 0);
			glRotatef(45, 0, 0, 1);
			glTranslatef(-1.9f, 0, -0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadratic quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
		{
			GLMatrixScope scope;
			glTranslatef(0, 0.4f, 0);
			glRotatef(45, 0, 0, 1);
			glTranslatef(-1.9f, 0, 0.3f);
			glScalef(4, 0.01f, 0.5f);
			GLQuadratic quadratic;
			gluQuadricNormals(*quadratic, GLU_SMOOTH);
			gluSphere(*quadratic, 0.5f, 50, 50);
		}
	}
}