#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/builder.h>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
	auto app = Application::create(argc, argv, "org.gtkmm.example");

	MainWindow mainWin;

	return app->run(mainWin);
}