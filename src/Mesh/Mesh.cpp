#include "Mesh.h"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

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

bool Mesh::LoadMesh(const std::string& filePath)
{
	std::ifstream file(filePath, std::ios::in);
	if (file.is_open()) {
		m_Vertices.clear();
		m_Triangles.clear();
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string type;
			iss >> type;
			if (type == "v") {
				float x, y, z;
				iss >> x >> y >> z;
				m_Vertices.push_back({ x,y,z });
				//std::cout << "Vertex : " << x << y << z << std::endl;
			}
			else if (type == "f") {
				std::string value;
				iss >> value;
				m_Triangles.push_back(std::stoi(value.substr(0, value.find('/'))) - 1);
				iss >> value;
				m_Triangles.push_back(std::stoi(value.substr(0, value.find('/'))) - 1);
				iss >> value;
				m_Triangles.push_back(std::stoi(value.substr(0, value.find('/'))) - 1);

				/*std::cout << "Triangle : " << t1 << " "<<t2 <<" "<< t3 << std::endl;*/
			}
		}
	}

	return false;
}
