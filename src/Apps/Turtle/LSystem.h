#pragma once
#include <string>
#include <unordered_map>
#include "Turtle.h"

class LSystem
{
public:
	LSystem(Turtle& turtle, const std::string& axiom, const std::unordered_map<char, std::string>& rules, int ruleCount = 5, float angle = 90.0f);

	void Render();

private:
	void Init();

	const std::string& m_Axiom;
	const std::unordered_map<char, std::string>& m_Rules;
	std::string m_Instructions;
	Turtle& m_Turtle;
	const int m_RuleCount;
	const float m_Angle;
};

