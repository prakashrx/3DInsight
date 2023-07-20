#include "InputManager.h"

bool InputManager::m_Keys[GLFW_KEY_LAST] = { 0 };
bool InputManager::m_MouseButtons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
MousePosition InputManager::m_MousePos = { 0, 0 };
double InputManager::m_MouseScroll = 0;

InputManager::InputManager(GLFWwindow* window)
: m_Window(window)
{
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
    glfwSetCursorPosCallback(m_Window, cursor_position_callback);
    glfwSetScrollCallback(m_Window, scroll_callback);
}

void InputManager::Update()
{
    glfwPollEvents();
}

void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        m_Keys[key] = true;
    }
    else if (action == GLFW_RELEASE) {
        m_Keys[key] = false;
    }
}

void InputManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        m_MouseButtons[button] = true;
    }
    else if (action == GLFW_RELEASE) {
        m_MouseButtons[button] = false;
    }
}

void InputManager::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    m_MousePos = { xpos, ypos };
}

void InputManager::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    m_MouseScroll += yoffset;
}