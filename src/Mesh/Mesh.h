#pragma once
#include <glm/glm.hpp>
#include <GLEW\glew.h>
#include <vector>
#include <string>

class Mesh
{
public:
	Mesh(int draw_type);
	virtual void Draw();

	bool LoadMesh(const std::string& filePath);



private:

	std::vector<glm::vec3> m_Vertices;
	std::vector<int> m_Triangles;
	int m_DrawType = GL_LINE_LOOP;
};

