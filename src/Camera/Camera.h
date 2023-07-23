#pragma once
#include <glm/glm.hpp>
#include "Application.h"
#include "Input/InputManager.h"


class Camera
{
public:
	Camera(InputManager* inputManager);
	void SetViewPort(int width, int height);
	void Update();

private:

	void Rotate(float deltaX, float deltaY);

	int m_ScreenWidth, m_ScreenHeight;
	InputManager* m_InputManager;
	glm::vec3 m_Eye = { 0,0,0 };
	glm::vec3 m_UpDirection = { 0,1,0 };
	glm::vec3 m_RightDirection = { 1,0,0 };
	glm::vec3 m_ForwardDirection = { 0,0,-1 };
	glm::vec2 m_LastMousePos = { 0,0 };
	float m_Pitch = 0;
	float m_Yaw = 0;
	const float Speed = 0.1f;
	const float MouseSensitivity = 0.0005f;
};