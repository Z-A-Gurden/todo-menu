#ifndef TODO
#define TODO

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/frame.h>
#include <gtkmm/textview.h>
#include <gtkmm/scrolledwindow.h>
#include "todo_title.h"
#include "file_view.h"

class Todo : public Gtk::Window
{
    // Declarations of constructor and destructor
    public:
    Todo();
    ~Todo() override;
    TodoFile& get_file();

    protected:

    // Signal handlers
    void on_button_clicked(int menu_option);

    // Other functions

    // Containers
    Gtk::Frame m_optionsFrame;
    Gtk::Grid m_optionsGrid;
    Gtk::Box m_mainBox;
    Gtk::Box m_title_box;
    Gtk::ScrolledWindow m_file_scroller;

    // Widgets
    Gtk::Button m_save_list_button;
    Gtk::Button m_erase_list_button;
    Gtk::Button m_exit_button;
    TodoTitle m_title_area;
    TodoFile m_file_view;

};

#endif