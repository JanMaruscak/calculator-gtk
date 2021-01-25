#include "MainWindow.h"
#include "gtkmm/builder.h"

std::string num1 = "";
std::string num2 = "";
std::string operation = "";
bool operatorIn;
using namespace Gtk;
MainWindow::MainWindow()
{
	RefPtr<CssProvider> css_provider = CssProvider::create();
	css_provider->load_from_data("grid {background-image: image(black)} button {margin: 10px; background-image: image(gray); color: white; border: 0; outline: 0; border-radius: 25%; font-size: large;} window {background-image: image(black);} .orange{background-image: image(orange);} .big{border-radius: 25%; margin: 10px;} .light{background-image: image(lightgray); color: black;} label{color:white; font-size: 70;} .small{font-size: 30; color: gray;}");
	addition_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	substract_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	multiply_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	divide_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	equals_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	clear_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	dot_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	negate_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	percentage_button.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	label.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	grid.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

	this->grid.attach(this->label, 0, 0, 4, 1);

	this->grid.attach(this->addition_button, 4, 1, 1, 1);
	this->addition_button.set_label("+");
	this->addition_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "+"));
	this->addition_button.get_style_context()->add_class("orange");

	this->grid.attach(this->substract_button, 4, 2, 1, 1);
	this->substract_button.set_label("-");
	this->substract_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "-"));
	this->substract_button.get_style_context()->add_class("orange");

	this->grid.attach(this->multiply_button, 4, 3, 1, 1);
	this->multiply_button.set_label("*");
	this->multiply_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "*"));
	this->multiply_button.get_style_context()->add_class("orange");

	this->grid.attach(this->divide_button, 4, 4, 1, 1);
	this->divide_button.set_label("/");
	this->divide_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "/"));
	this->divide_button.get_style_context()->add_class("orange");

	this->grid.attach(this->equals_button, 0, 4, 1, 1);
	this->equals_button.set_label("=");
	this->equals_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "="));
	this->equals_button.get_style_context()->add_class("orange");

	this->grid.attach(this->clear_button, 2, 4, 1, 1);
	this->clear_button.set_label("C");
	this->clear_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "C"));
	this->clear_button.get_style_context()->add_class("orange");

	this->grid.attach(this->dot_button, 5, 1, 1, 1);
	this->dot_button.set_label(".");
	this->dot_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "."));
	this->dot_button.get_style_context()->add_class("orange");

	this->grid.attach(this->negate_button, 5, 2, 1, 1);
	this->negate_button.set_label("+/-");
	this->negate_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "+/-"));
	this->negate_button.get_style_context()->add_class("orange");

	this->grid.attach(this->percentage_button, 5, 3, 1, 1);
	this->percentage_button.set_label("%");
	this->percentage_button.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &MainWindow::oper_click), "%"));
	this->percentage_button.get_style_context()->add_class("orange");

	for (int i = 1; i < 10; i++) {
		this->grid.attach(this->m_buttons[i], (i - 1) % 3, (i - 1) / 3 + 1, 1, 1);
		this->m_buttons[i].set_label(std::to_string(i));
		this->m_buttons[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::num_click), i));
		this->m_buttons[i].get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
	}
	this->grid.attach(this->m_buttons[0], 1, 4, 1, 1);
	this->m_buttons[0].set_label(std::to_string(0));
	this->m_buttons[0].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::num_click), 0));
	this->m_buttons[0].get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

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
	else if (key == ".") {
		if (!operatorIn) {
			num1 += ".";
			this->label.set_text(num1);
		}
		else {
			num2 += ".";
			this->label.set_text(num1 + operation + num2);
		}
	}
	else if (key == "+/-") {
		if (!operatorIn) {
			float first = std::strtof(num1.c_str(), NULL);
			first *= -1;
			num1 = std::to_string(first);
			this->label.set_text(num1);
		}
		else {
			float second = std::strtof(num2.c_str(), NULL);
			second *= -1;
			num2 = std::to_string(second);
			this->label.set_text(num1 + operation + num2);
		}
	}
	else if (key == "%") {
		if (!operatorIn) {
			float first = std::strtof(num1.c_str(), NULL);
			first /= 100;
			num1 = std::to_string(first);
			this->label.set_text(num1);
		}
		else {
			float second = std::strtof(num2.c_str(), NULL);
			second /= 100;
			num2 = std::to_string(second);
			this->label.set_text(num1 + operation + num2);
		}
	}
}