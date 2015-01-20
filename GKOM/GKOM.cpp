// GKOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLUT.h>
#include "core/scene.h"
#include "utils\GLQuadric.h"

void display();
void reshape(int width, int height);

gkom::Scene scene;

int _tmain(int argc, _TCHAR* argv[])
try {
	glutInit(&argc, (char**) argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);

	glutCreateWindow("GKOM Ważka");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	scene.init();

	glutMainLoop();

	return 0;
} catch (std::exception e) {
	std::cout << e.what() << std::endl;
	std::cout << "Press any key to exit..." << std::endl;
	system("pause");

	return 1;
} catch (...) {
	std::cout << "Unrecognized error." << std::endl;
	system("pause");

	return 1;
}

void display()
{
	scene.draw();
	// Prevent memory leak.
	gkom::GLQuadric::clean_stack();
}

void reshape(int width, int heigth)
{
	scene.reshape(width, heigth);
}
