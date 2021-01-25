#pragma once
#include <gtkmm/entry.h>
#include <gtkmm/fixed.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm.h>
#include <iostream>
#include <string>

using namespace Gtk;
using namespace Glib;

class MainWindow : public Window
{
	Gtk::Grid grid;
	Gtk::Label label;
	Gtk::Button m_buttons[10];
	Gtk::Button equals_button;
	Gtk::Button multiply_button;
	Gtk::Button divide_button;
	Gtk::Button addition_button;
	Gtk::Button substract_button;
	Gtk::Button clear_button;
public:
	MainWindow();
	void num_click(int i);
	void oper_click(std::string key);
};