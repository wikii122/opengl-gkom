#include "stdafx.h"
#include <Windows.h>
#include "gl/GL.h"
#include "gl/GLU.h"
#include "gl/GLUT.h"
#include "../skybox.h"
#include "core\camera.h"
#include "utils\textures.h"
#include "utils\GLQuadric.h"
#include "utils\GLMatrixScope.h"

using namespace gkom;

const std::string front = "skybox:front";
const std::string left = "skybox:left";
const std::string right = "skybox:right";
const std::string top = "skybox:top";
const std::string bottom = "skybox:bottom";
const std::string back = "skybox:back";
void Skybox::init()
{
	Texture texture;
	texture.load("res/back.jpg", back);
	texture.load("res/front.jpg", front);
	texture.load("res/left.jpg", left);
	texture.load("res/right.jpg", right);
	texture.load("res/up.jpg", top);
	texture.load("res/down.jpg", bottom);
}

void Skybox::draw(Camera& camera)
{
	Texture texture;
	GLMatrixScope scope;


	camera.center();

	glDisable(GL_LIGHTING); 
	glDisable(GL_DEPTH_TEST);
	
	texture.apply(back);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(size/2, size/2, size/2); 
		glTexCoord2f(1, 1); glVertex3f(-size/2, size/2, size/2);
		glTexCoord2f(1, 0); glVertex3f(-size/2, -size/2, size/2);
		glTexCoord2f(0, 0); glVertex3f(size/2, -size/2, size/2);
	glEnd();

	texture.apply(left);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(-size/2, size/2, size/2);
		glTexCoord2f(1, 1); glVertex3f(-size/2, size/2, -size/2);
		glTexCoord2f(1, 0); glVertex3f(-size/2, -size/2, -size/2);
		glTexCoord2f(0, 0); glVertex3f(-size/2, -size/2, size/2);
	glEnd();

	texture.apply(front);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1); glVertex3f(size/2, size/2, -size/2);
		glTexCoord2f(0, 1); glVertex3f(-size/2, size/2, -size/2);
		glTexCoord2f(0, 0); glVertex3f(-size/2, -size/2, -size/2);
		glTexCoord2f(1, 0); glVertex3f(size/2, -size/2, -size/2);
	glEnd();

	texture.apply(right);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(size/2, size/2, -size/2);
		glTexCoord2f(1, 1); glVertex3f(size/2, size/2, size/2);
		glTexCoord2f(1, 0); glVertex3f(size/2, -size/2, size/2);
		glTexCoord2f(0, 0); glVertex3f(size/2, -size/2, -size/2);
	glEnd();

	texture.apply(top);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 1); glVertex3f(size/2, size/2, size/2);
		glTexCoord2f(0, 1); glVertex3f(-size/2, size/2, size/2);
		glTexCoord2f(0, 0); glVertex3f(-size/2, size/2, -size/2);
		glTexCoord2f(1, 0); glVertex3f(size/2, size/2, -size/2);
	glEnd();

	texture.apply(bottom);
	glBegin(GL_QUADS);
		glTexCoord2f(1, 0); glVertex3f(size/2, -size/2, size/2);
		glTexCoord2f(1, 1); glVertex3f(size/2, -size/2, -size/2);
		glTexCoord2f(0, 1); glVertex3f(-size/2, -size/2, -size/2);
		glTexCoord2f(0, 0); glVertex3f(-size/2, -size/2, size/2);
	glEnd();

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}