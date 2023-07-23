#pragma once
#include<memory>
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include "Input\InputManager.h"

class Application
{
public:
	Application(int screen_width = 800, int screen_height = 800);

	virtual void Initialize();
	virtual void Run();
	virtual void MainLoop();
	virtual void Update();
	virtual void PreRender();
	virtual void Render();

	virtual ~Application();
protected:
	int m_ScreenWidth, m_ScreenHeight;
	virtual void init_ortho(int left, int right, int bottom, int top);
	virtual void OnResize(int width, int height);
	GLFWwindow* window;
	std::unique_ptr<InputManager> m_InputManager;

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};



