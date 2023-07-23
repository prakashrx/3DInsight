#include <iostream>
#include "Apps\Paint\PaintApp.h"
#include "Apps\Turtle\LSystemApp.h"
#include "Apps\View3D\View3D.h"

int main(void)
{
	Application* app = new View3D("../assets/suzanne.obj");

	app->Initialize();
	app->Run();
	delete app;

	return 0;
}