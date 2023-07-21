#pragma once
#include <GLFW\glfw3.h>

struct MousePosition {
	double x;
	double y;
};

class InputManager
{
public:
	InputManager(GLFWwindow* window);

	bool IsKeyPressed(int key) const { return m_Keys[key]; }
	bool IsButtonPressed(int button) const { return m_MouseButtons[button]; }
	MousePosition GetMousePosition() const { return m_MousePos;  }
	double GetMouseScroll() const { return m_MouseScroll; }

	static void Update();
private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	static bool m_Keys[GLFW_KEY_LAST];
	static bool m_MouseButtons[GLFW_MOUSE_BUTTON_LAST];
	GLFWwindow* m_Window;
	static MousePosition m_MousePos;
	static double m_MouseScroll;

};

