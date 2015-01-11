#include "stdafx.h"
#include "../scene.h"
#include "gl\GLUT.H"


void gkom::Scene::init()
{
	init_light();
}

void gkom::Scene::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	dragonfly->display(time);
	glFlush();

	++time;
}

void gkom::Scene::reshape(int width, int height)
{
	if (height > 0 && width > 0) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (width <= height) {
			glFrustum(-2.25, 2.25, -2.25*height/width, 2.25*height/width, 10.0, 200.0);
		}
		else {
			glFrustum(-2.25*width/height, 2.25*width/height, -2.25, 2.25, 10.0, 200.0);
		}
		gluLookAt(-50.0, 0.0, -50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glMatrixMode(GL_MODELVIEW);
	}
}


void gkom::Scene::init_light()
{
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel(GL_FLAT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
}