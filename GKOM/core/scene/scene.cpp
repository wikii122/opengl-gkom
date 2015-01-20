#include "stdafx.h"
#include "../scene.h"
#include "gl\GLUT.H"
#include "utils\GLMatrixScope.h"
#include "utils\textures.h"

using namespace gkom;

void Scene::init()
{
	init_scene();
	init_light();
	init_textures();
}

void Scene::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	{
		GLMatrixScope scope;
		dragonfly.draw(time);
	}
	glutSwapBuffers();
	++time;
}

void Scene::reshape(int width, int height)
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
		gluLookAt(-20.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glMatrixMode(GL_MODELVIEW);
	}
}


void Scene::init_light()
{
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.4, 0.4, 0.4, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel(GL_FLAT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Scene::init_scene()
{
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_TEXTURE_2D);
}

void Scene::init_textures()
{
	Texture manager = Texture();
	manager.init();
	manager.load("res/eye.png", "eye");
}