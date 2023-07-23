#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include "Application.h"
#include "Mesh/Mesh.h"
#include "Camera/Camera.h"

class View3D : public Application
{
	using color = glm::vec4;

public:
	View3D(const std::string& modelFilePath);
	void Initialize() override;
	void Update() override;
	void Render() override;
	void OnResize(int width, int height) override;

private:
	color m_BackgroundColor = { 0,0,0,1 };
	color m_ForegroundColor = { 1,1,1,1 };
	Mesh m_Mesh;
	std::unique_ptr<Camera> m_Camera;
	bool m_MouseCapture = false;
};

