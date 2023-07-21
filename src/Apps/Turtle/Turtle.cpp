#include "Turtle.h"

Turtle::Turtle():
    m_CurrentPosition {0,0},
    m_Direction{ 0, 1, 0 }
{
}


void Turtle::ResetAll()
{
    m_CurrentPosition = { 0, 0 };
    m_Direction = { 0, 1, 0 };
}

void Turtle::ResetRotation()
{
    m_Direction = { 0, 1, 0 };
}

void Turtle::ResetLocation()
{
    m_CurrentPosition = { 0, 0 };
}


void Turtle::Forward()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(m_CurrentPosition.x, m_CurrentPosition.y);
    m_CurrentPosition = m_CurrentPosition + glm::vec2(m_Direction * ForwardLength);
    glVertex2f(m_CurrentPosition.x, m_CurrentPosition.y);
    glEnd();
}

void Turtle::MoveTo(const glm::vec2& to)
{
    m_CurrentPosition = to;
}

void Turtle::SetDirection(const glm::vec3& direction)
{
    m_Direction = direction;
}

void Turtle::Rotate(float angle)
{
    m_Direction = Utils::z_rotation(m_Direction, angle);
}


void Turtle::Render()
{
    ResetAll();

    glBegin(GL_POINTS);
    glVertex2f(m_CurrentPosition.x, m_CurrentPosition.y);
    glEnd();

    Forward();
    Forward();
    Rotate(90);
    Forward();
    MoveTo({ 10, 10 });
    
    ResetRotation();
    Forward();
    Rotate(-45);
    Forward();
}
