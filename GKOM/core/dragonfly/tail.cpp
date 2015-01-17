#include "stdafx.h"
#include "parts.h"
#include "utils\GLMatrixScope.h"
#include "utils\GLQuadric.h"

using namespace gkom::dragonfly;

void Tail::draw(long time)
{
	GLMatrixScope scope;
	glScalef(0.5f, 0.4f, 4.1f);
	glTranslatef(0, 0.18f, -0.5f);
	glRotatef(0, 0, 0, 0);
	GLQuadric quadratic;
	gluQuadricNormals(*quadratic, GLU_SMOOTH);
	gluSphere(*quadratic, 0.5, 50, 50);
}