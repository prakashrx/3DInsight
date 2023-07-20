#pragma once
#include <glm/glm.hpp>
#include <GLEW\glew.h>
#include <vector>

class Mesh
{
public:
	Mesh(int draw_type);
	virtual void Draw();
private:

	std::vector<glm::vec3> m_Vertices;
	std::vector<int> m_Triangles;
	int m_DrawType = GL_LINE_LOOP;
};

