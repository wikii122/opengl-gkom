#include "stdafx.h"
#include "parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadric.h"

using namespace gkom::dragonfly;

void Tail::draw(long time)
{
	GLMatrixScope display;
	glScalef(0.7f, 0.5f, 4.0f);
	glTranslatef(0, 0.18f, -0.5f);
	GLQuadric quadratic;
	gluQuadricNormals(*quadratic, GLU_SMOOTH);
	gluSphere(*quadratic, 0.5, 50, 50);
}