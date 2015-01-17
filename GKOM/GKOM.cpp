// GKOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "core/scene.h"

void display();
void reshape(int width, int height);

gkom::Scene scene;

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**) argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);

	glutCreateWindow("GKOM Ważka");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	scene.init();

	glutMainLoop();

	return 0;
}

void display()
{
	scene.draw();
}

void reshape(int width, int heigth)
{
	scene.reshape(width, heigth);
}
