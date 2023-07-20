#pragma once
#include<vector>
#include "Input/InputManager.h"
#include "Utils/Utils.h"
#include <glm/glm.hpp>

class Turtle
{
public:
	Turtle();
	void ResetAll();
	void ResetRotation();
	void ResetLocation();
	void Forward();
	void MoveTo(const glm::vec2& to);
	void SetDirection(const glm::vec3& direction);
	void Rotate(float angle);
	void Render();

	glm::vec2 GetPosition() const { return m_CurrentPosition; }
	glm::vec3 GetDirection() const { return m_Direction; }

private:
	glm::vec2 m_CurrentPosition;
	glm::vec3 m_Direction;
	const float ForwardLength = 5;
};

