#include "View3D.h"

View3D::View3D(const std::string& modelFilePath) 
	: Application(1000, 800)
	, m_Mesh(GL_LINE_LOOP)
{
	m_Mesh.LoadMesh(modelFilePath);
}

void View3D::Initialize() {

	Application::Initialize();
	glClearColor(m_BackgroundColor.r, m_BackgroundColor.r, m_BackgroundColor.b, m_BackgroundColor.a);
	glColor3fv(glm::value_ptr(m_ForegroundColor));

	// projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (m_ScreenWidth / m_ScreenHeight), 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, m_ScreenWidth, m_ScreenHeight);
	glEnable(GL_DEPTH_TEST);

	m_Camera = std::make_unique<Camera>(m_InputManager.get());
	m_Camera->SetViewPort(m_ScreenWidth, m_ScreenHeight);

}
void View3D::Update() {

	if (m_InputManager->IsButtonPressed(GLFW_MOUSE_BUTTON_1)) {
		m_MouseCapture = true;
		m_InputManager->SetMousePosition({ m_ScreenWidth / 2, m_ScreenHeight / 2 });
		m_InputManager->SetMouseVisible(false);
	}
	else if (m_InputManager->IsKeyPressed(GLFW_KEY_ESCAPE)) {
		m_MouseCapture = false;
		m_InputManager->SetMouseVisible(true);
	}

	if (m_MouseCapture) {
		m_Camera->Update();
	}
}
void View3D::Render() {

	glPushMatrix();
	m_Mesh.Draw();
	glPopMatrix();
}

void View3D::OnResize(int width, int height)
{
	Application::OnResize(width, height);
	m_Camera->SetViewPort(width, height);
}
