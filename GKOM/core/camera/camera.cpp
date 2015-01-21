#include "stdafx.h"
#include <Windows.h>
#include "gl/Gl.h"
#include "gl/GLU.h"
#include "gl/GLUT.h"
#include "..\camera.h"
#include "utils\GLMatrixScope.h"

void gkom::Camera::set(long time)
{
	gluLookAt(eye_x, eye_y, eye_z, model_x, model_y, model_z, 0.0, 1.0, 0.0);
	eye_x -= 0.1;
}

void gkom::Camera::center()
{
	glTranslatef(eye_x, eye_y, eye_z);
}