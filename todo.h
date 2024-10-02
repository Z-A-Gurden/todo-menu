#ifndef TODO
#define TODO

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/frame.h>

class Todo : public Gtk::Window
{
    // Declarations of constructor and destructor
    public:
    Todo();
    ~Todo() override;

    protected:

    // Containers
    Gtk::Frame m_optionsFrame;
    Gtk::Grid m_optionsGrid;
    Gtk::Box m_mainBox;

    // Widgets
    Gtk::Button m_listButton;
    Gtk::Button m_addButton;
    Gtk::Button m_markButton;
    Gtk::Button m_removeButton;
    Gtk::Button m_eraseButton;
    Gtk::Button m_exitButton;
    Gtk::Entry m_entry;

};

#endif