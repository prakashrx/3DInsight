#include <iostream>
#include "Application.h"

Application::Application(int screen_width, int screen_height)
	:m_ScreenWidth(screen_width),
	m_ScreenHeight(screen_height)
{
	
}

Application::~Application()
{
	glfwTerminate();
}

void Application::Initialize()
{
	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	window = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, "3D Insight", NULL, NULL);
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
}

void Application::PreRender() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Application::Render()
{
}

void Application::MainLoop()
{
	/* Poll for and process events */
	InputManager::Update();
	Update();
	PreRender();
	Render();
	glfwSwapBuffers(window);
}

void Application::Update()
{
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