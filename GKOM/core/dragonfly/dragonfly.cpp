#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "..\dragonfly.h"
#include "utils\GLMatrixScope.h"

void draw_fog()
{
	GLfloat fogColor[] = { 0.2f, 0.2f, 0.2f, 0.2 };
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, 220);
	glFogf(GL_FOG_END, 260);
}

gkom::Dragonfly::Dragonfly()
{

}

void gkom::Dragonfly::draw(long time)
{
	GLMatrixScope scope;

	GLfloat mat_ambient[] = { 0.1, 0.01, 0.01, 0.1 };
	GLfloat mat_specular[] = { 0.05, 0.1, 0.01, 0.1 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 10.0);

	draw_fog();
	position();
	head.draw(time);
	body.draw(time);
	wings.draw(time);
	tail.draw(time);
}

void gkom::Dragonfly::position()
{

}
