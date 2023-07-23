#pragma once
#include<vector>
#include <utility>
#include "Input/InputManager.h"
#include "Utils/Utils.h"
#include <glm/glm.hpp>

class MousePaint
{
public:
	MousePaint(const InputManager* input, int screenWidth, int screenHeight, int orthoLeft, int orthoRight, int orthoTop, int orthoBottom);

	void SetScreenSize(int screenWidth, int screenHeight);
	void Render();
	
private:
	void DrawPoints();
	inline glm::vec2 GetPoint(const glm::vec2& pos) {
		double newX = Utils::MapRange(0, m_ScreenWidth, m_OrthoLeft, m_OrthoRight, pos.x);
		double newY = Utils::MapRange(0, m_ScreenHeight, m_OrthoTop, m_OrthoBottom, pos.y);
		return glm::vec2(newX, newY);
	}

	const InputManager* m_InputManager;
	std::vector <std::vector<glm::vec2>> m_Points;
	int m_ScreenWidth, m_ScreenHeight;
	int m_OrthoLeft, m_OrthoRight, m_OrthoTop, m_OrthoBottom;
};

