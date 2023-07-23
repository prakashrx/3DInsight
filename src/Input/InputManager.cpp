#include "InputManager.h"

bool InputManager::m_Keys[GLFW_KEY_LAST] = { 0 };
bool InputManager::m_MouseButtons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
double InputManager::m_MouseScroll = 0;

InputManager::InputManager(GLFWwindow* window)
: m_Window(window)
{
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
    glfwSetScrollCallback(m_Window, scroll_callback);
}

glm::vec2 InputManager::GetMousePosition() const
{
    double x, y;
    glfwGetCursorPos(m_Window, &x, &y);
    return { x,y };
}

void InputManager::SetMousePosition(const glm::vec2& pos)
{
    glfwSetCursorPos(m_Window, pos.x, pos.y);
}

void InputManager::SetMouseVisible(bool visible)
{
    glfwSetInputMode(m_Window, GLFW_CURSOR, visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
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

void InputManager::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    m_MouseScroll += yoffset;
}