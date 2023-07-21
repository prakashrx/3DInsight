#include "Mesh.h"
#include <glm/gtc/type_ptr.hpp>

Mesh::Mesh(int draw_type = GL_LINE_LOOP)
	: m_DrawType(draw_type)
{
	m_Vertices = { {0.5, -0.5, 0.5},
		{-0.5, -0.5, 0.5 },
		{0.5, 0.5, 0.5},
		{-0.5, 0.5, 0.5 },
		{0.5, 0.5, -0.5},
		{-0.5, 0.5, -0.5 }
	};
	m_Triangles = { 0, 2, 3, 0, 3, 1 };
}

void Mesh::Draw()
{
	for (int i = 0; i < m_Triangles.size(); i += 3) {
		glBegin(m_DrawType);
		glVertex3fv(glm::value_ptr(m_Vertices[m_Triangles[i]]));
		glVertex3fv(glm::value_ptr(m_Vertices[m_Triangles[i + 1]]));
		glVertex3fv(glm::value_ptr(m_Vertices[m_Triangles[i + 2]]));
		glEnd();
	}
}
