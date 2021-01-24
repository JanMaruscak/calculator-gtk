#include "MainWindow.h"
#include "gtkmm/builder.h"
MainWindow::MainWindow()
{
	this->grid.attach(this->label, 0, 0, 1, 1);

	this->grid.attach(this->addition_button, 4, 1, 1, 1);
	this->addition_button.set_label("+");

	this->grid.attach(this->substract_button, 4, 2, 1, 1);
	this->substract_button.set_label("-");

	this->grid.attach(this->multiply_button, 4, 3, 1, 1);
	this->multiply_button.set_label("x");

	this->grid.attach(this->divide_button, 4, 4, 1, 1);
	this->divide_button.set_label("/");

	this->grid.attach(this->equals_button, 1, 4, 1, 1);
	this->equals_button.set_label("=");

	this->grid.attach(this->clear_button, 2, 4, 1, 1);
	this->clear_button.set_label("C");

	for (int i = 0; i < 10; i++) {
		this->grid.attach(this->m_buttons[i], i % 3, i / 3 + 1, 1, 1);
		this->m_buttons[i].set_label(std::to_string(i));
		this->m_buttons[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &MainWindow::btn_click), i));
	}
	this->add(grid);
	this->grid.show_all();
}

void MainWindow::btn_click(int i) {
	std::cout << i << std::endl;
	this->label.set_text(std::to_string(i));
}