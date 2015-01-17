#include "stdafx.h"
#include <iostream>
#include "Windows.h"
#include "gl\GL.h"
#include "gl\GLU.h"
#include "gl\GLUT.h"
#include "gl\IL\il.h"
#include "gl\IL\ilu.h"
#include "gl\IL\ilut.h"
#include "textures.h"

using namespace gkom;
using std::string;

std::map<std::string, GLuint> Texture::ids = std::map <std::string, GLuint> {};

Texture::~Texture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::init()
{
	ilInit();
	iluInit();
	ilutInit();
	ilClearColour(255, 255, 255, 000);

	ilutRenderer(ILUT_OPENGL);
}
void Texture::load(string const& path, string const& name)
{
	GLuint texture_id = ilutGLLoadImage((ILstring) path.c_str());
	if (texture_id == 0) {
		throw file_not_found("Could not open file " + path);
	}

	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glBindTexture(GL_TEXTURE_2D, NULL);
	
	ids[name] = texture_id;
}

void Texture::apply(GLQuadric const& quadratic, string const& name)
{
	GLuint id = ids[name];
	if (id == 0) {
		std::cout << "Undefined name for texture: " << name << std::endl;
		return;
	}
	gluQuadricTexture(*quadratic, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, id);
}
const char* file_not_found::what() const
{
	return msg.c_str();
}