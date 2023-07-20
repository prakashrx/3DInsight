#include <memory>
#include "Application.h"
#include "Turtle.h"
#include "LSystem.h"

class LSystemApp : public Application
{
public:
	LSystemApp() {}

	virtual void Initialize() override {
		Application::Initialize();

		int orthoLeft = -400, orthoRight = 400, orthoTop = 400, orthoBottom = -400;
		init_ortho(orthoLeft, orthoRight, orthoBottom, orthoTop);

		//LSystem l_system(turtle, "F", { {'F', "F[+F]F"} });
		//LSystem l_system(turtle, "X", { {'F', "FF"}, {'X', "F-[[X]+X]+F[+FX]-X,F+[[X]-X]-F[-FX]+X"} }, 5, 22.5);
		//LSystem l_system(turtle, "X", { {'F', "FF"}, {'X', "F[+X][-X]FX"} }, 5, 30);

		/*std::string axiom = "F";
		std::unordered_map<char, std::string> rules = { {'F', "F[+F]F"} };*/
		
		std::string axiom = "X";
		std::unordered_map<char, std::string> rules = { {'F', "FF"}, {'X', "F[+X][-X]FX"} };
		//std::unordered_map<char, std::string> rules = { {'F', "FF"}, {'X', "F-[[X]+X]+F[+FX]-X,F+[[X]-X]-F[-FX]+X"} };
		m_LSystem = std::make_unique<LSystem>(m_Turtle, axiom, rules, 5, 22.5f);
	}

	virtual void Render() override {
		m_LSystem->Render();
	}

private:
	Turtle m_Turtle;
	std::unique_ptr<LSystem> m_LSystem;
};