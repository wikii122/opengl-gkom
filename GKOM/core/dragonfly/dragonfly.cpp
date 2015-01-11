#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "..\dragonfly.h"


gkom::Dragonfly::Dragonfly()
{

}

void gkom::Dragonfly::display(long time)
{
	position();
	//head.display(time);
	body.display();
	//wings.display(time);
	//tail.display(time);
}

void gkom::Dragonfly::position()
{

}
