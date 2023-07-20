#include "MousePaint.h"


MousePaint::MousePaint(const InputManager* inputManager, int screenWidth, int screenHeight, int orthoLeft, int orthoRight, int orthoTop, int orthoBottom)
    : m_InputManager(inputManager),
    m_ScreenWidth(screenWidth),
    m_ScreenHeight(screenHeight),
    m_OrthoLeft(orthoLeft),
    m_OrthoRight(orthoRight),
    m_OrthoTop(orthoTop),
    m_OrthoBottom(orthoBottom)
{
}

void MousePaint::DrawPoints() {
    
    for (auto& points: m_Points) {
        glBegin(GL_LINE_STRIP);
        for (auto& p : points) {
            glVertex2f(p.x, p.y);
        }
        glEnd();
    }
    
}

void MousePaint::SetScreenSize(int screenWidth, int screenHeight)
{
    m_ScreenWidth = screenWidth;
    m_ScreenHeight = screenHeight;
}

void MousePaint::Render()
{
    if (m_InputManager->IsKeyPressed(GLFW_KEY_ESCAPE)) {
        m_Points.clear();
    }
    if (m_InputManager->IsButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
        auto position = m_InputManager->GetMousePosition();
        
        if (!m_Points.empty()) {
            auto &last = m_Points.back();

            if (!last.empty()) {
                auto &lastPos = last.back();
                if (lastPos.x != position.x || lastPos.y != position.y)
                    last.push_back(GetPoint(position));
            }
            else {
                last.push_back(GetPoint(position));
            }
        }
        else {
            m_Points.push_back({});
            auto &last = m_Points.back();
            last.push_back(GetPoint(position));
        }
    }
    else if (m_Points.empty() || (!m_Points.empty() && !m_Points.back().empty()) ){
        m_Points.push_back({});
    }
    DrawPoints();
}
