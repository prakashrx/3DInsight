#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>

class InputManager
{
public:
	InputManager(GLFWwindow* window);

	bool IsKeyPressed(int key) const { return m_Keys[key]; }
	bool IsButtonPressed(int button) const { return m_MouseButtons[button]; }
	glm::vec2 GetMousePosition() const;
	void SetMousePosition(const glm::vec2& pos);
	void SetMouseVisible(bool visible);
	double GetMouseScroll() const { return m_MouseScroll; }

	static void Update();
private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	static bool m_Keys[GLFW_KEY_LAST];
	static bool m_MouseButtons[GLFW_MOUSE_BUTTON_LAST];
	GLFWwindow* m_Window;
	static double m_MouseScroll;

};

