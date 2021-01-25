#include "MainWindow.h"
#include "gtkmm/builder.h"

std::string num1 = "";
std::string num2 = "";
std::string operation = "";
bool operatorIn;
using namespace Gtk;
MainWindow::MainWindow()
{
	this->grid.attach(this->label, 0, 0, 4, 1);

	this->grid.attach(this->addition_button, 4, 1, 1, 1);
	this->addition_button.set_label("+");
	this->addition_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "+"));

	this->grid.attach(this->substract_button, 4, 2, 1, 1);
	this->substract_button.set_label("-");
	this->substract_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "-"));

	this->grid.attach(this->multiply_button, 4, 3, 1, 1);
	this->multiply_button.set_label("x");
	this->multiply_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "x"));

	this->grid.attach(this->divide_button, 4, 4, 1, 1);
	this->divide_button.set_label("/");
	this->divide_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "/"));

	this->grid.attach(this->equals_button, 0, 4, 1, 1);
	this->equals_button.set_label("=");
	this->equals_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "="));

	this->grid.attach(this->clear_button, 2, 4, 1, 1);
	this->clear_button.set_label("C");
	this->clear_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "C"));

	for (int i = 1; i < 10; i++) {
		this->grid.attach(this->m_buttons[i], (i - 1) % 3, (i - 1) / 3 + 1, 1, 1);
		this->m_buttons[i].set_label(std::to_string(i));
		this->m_buttons[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::num_click), i));
	}
	this->grid.attach(this->m_buttons[0], 1, 4, 1, 1);
	this->m_buttons[0].set_label(std::to_string(0));
	this->m_buttons[0].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::num_click), 0));

	this->add(grid);
	this->grid.show_all();
}

void MainWindow::num_click(int i) {
	std::cout << i << std::endl;
	if (!operatorIn) {
		num1 += std::to_string(i);
		this->label.set_text(num1);
	}
	else {
		num2 += std::to_string(i);
		this->label.set_text(num1 + operation + num2);
	}
}
void MainWindow::oper_click(std::string key) {
	if (key == "+") {
		operatorIn = true;
		operation = key;
		this->label.set_text(num1 + key);
	}
	else if (key == "-") {
		operatorIn = true;
		operation = key;
		this->label.set_text(num1 + key);
	}
	else if (key == "/") {
		operatorIn = true;
		operation = key;
		this->label.set_text(num1 + key);
	}
	else if (key == "*") {
		operatorIn = true;
		operation = key;
		this->label.set_text(num1 + key);
	}
	else if (key == "=") {
		float first = std::strtof(num1.c_str(), NULL);
		float second = std::strtof(num2.c_str(), NULL);
		float result = 0;
		if (operation == "+")
		{
			result = first + second;
		}
		else if (operation == "-") {
			result = first - second;
		}
		else if (operation == "*") {
			result = first * second;
		}
		else if (operation == "/") {
			result = first / second;
		}
		this->label.set_text(std::to_string(result));
		operatorIn = false;
		num1 = std::to_string(result);
		num2 = "";
	}
	else if (key == "C") {
		operatorIn = false;
		num1 = "";
		num2 = "";
		this->label.set_text("");
	}
}