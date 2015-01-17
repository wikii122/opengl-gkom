#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "..\dragonfly.h"
#include "utils\GLMatrixScope.h"


gkom::Dragonfly::Dragonfly()
{

}

void gkom::Dragonfly::draw(long time)
{
	GLMatrixScope scope;
	position();
	head.draw(time);
	body.draw(time);
	wings.draw(time);
	tail.draw(time);
}

void gkom::Dragonfly::position()
{

}
