#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Calculator : public Gtk::Window
{
public:
	Calculator();
	virtual ~Calculator();

protected:
	//Signal handlers:
	virtual void on_button_clicked();

	//Child widgets:
	Gtk::Button m_button;
};

#endif //GTKMM_EXAMPLE_BUTTONS_H
