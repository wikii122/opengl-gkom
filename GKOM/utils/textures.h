#pragma once
#include <exception>
#include <map>
#include <string>
#include "utils\GLQuadric.h"

namespace gkom
{
	class Texture
	{
	private:
		int counter;
		static std::map<std::string, GLuint> ids;
	public:
		~Texture();
		void init();
		void load(std::string const& path, std::string const& name);
		void apply(GLQuadric const& quadratic, std::string const& name);
		void apply(std::string name);
	};

	class file_not_found : std::exception
	{
		std::string msg;
	public:
		file_not_found(std::string message) :
			msg(message) {}
		virtual const char* what() const override;
	};
};