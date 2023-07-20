#include "Application.h"
#include "MousePaint.h"

class PaintApp : public Application
{
public:
	PaintApp() {}

	virtual void Initialize() override {
		Application::Initialize();

		int orthoLeft = -1, orthoRight = 1, orthoTop = 1, orthoBottom = -1;
		init_ortho(orthoLeft, orthoRight, orthoBottom, orthoTop);

		m_Paint = std::make_unique<MousePaint>(m_InputManager.get(), m_ScreenWidth, m_ScreenHeight, orthoLeft, orthoRight, orthoTop, orthoBottom);
	}

	virtual void Render() override {
		m_Paint->Render();
	}


	virtual void OnResize(int width, int height) override {
		Application::OnResize(width, height);
		m_Paint->SetScreenSize(width, height);
	}

private:

	std::unique_ptr<MousePaint> m_Paint;
};