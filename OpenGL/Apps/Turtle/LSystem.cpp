#include "LSystem.h"
#include <iostream>
#include <vector>

LSystem::LSystem(Turtle& turtle, const std::string& axiom, const std::unordered_map<char, std::string>& rules, int ruleCount, float angle)
	: m_Turtle(turtle),
	m_Axiom(axiom),
	m_Rules(rules),
	m_RuleCount(ruleCount),
	m_Angle(angle)
{
	Init();
}

void LSystem::Init() {

	m_Instructions = m_Axiom;
	for (int i = 0; i < m_RuleCount + 1; i++)
	{
		std::string instructions = m_Instructions;
		m_Instructions = "";
		for (const char& ch : instructions) {
			if (m_Rules.contains(ch))
				m_Instructions += m_Rules.at(ch);
			else
				m_Instructions += ch;
		}
	}
	//std::cout << m_Instructions<<std::endl;
}

void LSystem::Render()
{
	std::vector<std::pair<glm::vec2, glm::vec3>> stack;
	m_Turtle.ResetAll();
	m_Turtle.MoveTo({ 0, -400 });
	for (const char& ch : m_Instructions) {
		switch (ch)
		{
		case 'F':
			m_Turtle.Forward();
			break;
		case '+':
			m_Turtle.Rotate(m_Angle);
			break;
		case '-':
			m_Turtle.Rotate(-m_Angle);
			break;
		case '[':
			stack.push_back({ m_Turtle.GetPosition(), m_Turtle.GetDirection() });
			break;
		case ']':
		{
			auto& item = stack.back();
			m_Turtle.MoveTo(item.first);
			m_Turtle.SetDirection(item.second);
			stack.pop_back();
			break;
		}
		default:
			break;
		}
	}
}
