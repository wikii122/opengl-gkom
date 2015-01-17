#pragma once
#include <string>

class Textures
{
	Textures();
public:
	static Textures manager;

	Textures(Textures const&) = delete;
	Textures operator=(Textures const&) = delete;

	void load(std::string path, std::string name);
	void apply(std::string name);
};

