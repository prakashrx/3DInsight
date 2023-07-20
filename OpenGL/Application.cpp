#include <iostream>
#include "Application.h"

Application::Application(int screen_width, int screen_height)
	:m_ScreenWidth(screen_width),
	m_ScreenHeight(screen_height)
{
	
}

void Application::Initialize()
{
	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	window = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, "OpenGL World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Failed to Create GLFW Window" << std::endl;
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (glewInit() != GLEW_OK)
		std::cout << "Error initialzing GLEW";

	m_InputManager = std::make_unique<InputManager>(window);
}

void Application::Run()
{
	while (!glfwWindowShouldClose(window))
		MainLoop();

	glfwTerminate();
}

void Application::MainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Render();

	glfwSwapBuffers(window);
	/* Poll for and process events */
	InputManager::Update();
}

void Application::init_ortho(int left, int right, int bottom, int top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void Application::OnResize(int width, int height)
{
	m_ScreenWidth = width;
	m_ScreenHeight = height;
	glViewport(0, 0, width, height);
}

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
	app->OnResize(width, height);
}