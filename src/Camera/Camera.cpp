
#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>>
#include<iostream>

Camera::Camera(InputManager* inputManager)
	:m_InputManager(inputManager)
{
	m_Yaw = glm::radians(-90.0f);
	m_Pitch = 0;
}

void Camera::SetViewPort(int width, int height)
{
	m_ScreenWidth = width;
	m_ScreenHeight = height;
}

void Camera::Rotate(float deltaX, float deltaY)
{
    float yaw = MouseSensitivity * deltaX;
    float pitch = MouseSensitivity * deltaY;

    // Constraining the pitch angle to avoid flip at the zenith.
    constexpr float maxPitch = glm::radians(89.0f);
	constexpr float minPitch = glm::radians(-89.0f);
    m_Pitch = glm::clamp(m_Pitch + pitch, minPitch, maxPitch);

    m_Yaw =  glm::mod(m_Yaw + yaw, glm::radians(360.0f));
    // Recalculate forward direction.
    m_ForwardDirection.x = cos(m_Yaw) * cos(m_Pitch);
    m_ForwardDirection.y = sin(m_Pitch);
    m_ForwardDirection.z = sin(m_Yaw) * cos(m_Pitch);
    m_ForwardDirection = glm::normalize(m_ForwardDirection);
	m_RightDirection = glm::normalize(glm::cross(m_ForwardDirection, {0,1,0}));
	m_UpDirection = glm::normalize(glm::cross(m_RightDirection, m_ForwardDirection));
}

void Camera::Update()
{
	auto mousePos = m_InputManager->GetMousePosition();
	auto delta = m_LastMousePos - mousePos;
	m_InputManager->SetMousePosition({ m_ScreenWidth / 2, m_ScreenHeight / 2 });
	m_LastMousePos = m_InputManager->GetMousePosition();
	Rotate(-delta.x, delta.y);
	

	if (m_InputManager->IsKeyPressed(GLFW_KEY_S))
		m_Eye -= m_ForwardDirection * Speed;
	else if (m_InputManager->IsKeyPressed(GLFW_KEY_W))
		m_Eye += m_ForwardDirection * Speed;
	else if (m_InputManager->IsKeyPressed(GLFW_KEY_A))
		m_Eye -= m_RightDirection * Speed;
	else if (m_InputManager->IsKeyPressed(GLFW_KEY_D))
		m_Eye += m_RightDirection * Speed;

	auto lookAt = m_Eye + m_ForwardDirection;

	glLoadIdentity();
	gluLookAt(m_Eye.x, m_Eye.y, m_Eye.z, lookAt.x, lookAt.y, lookAt.z, m_UpDirection.x, m_UpDirection.y, m_UpDirection.z);
}
