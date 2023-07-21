#include <iostream>
#include "Apps\Paint\PaintApp.h"
#include "Apps\Turtle\LSystemApp.h"

int main(void)
{
	Application* app = new LSystemApp();

	app->Initialize();
	app->Run();
	delete app;

	return 0;
}