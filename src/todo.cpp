#include "../headers/todo.h"
#include "../headers/add_list.h"
#include <iostream>
#include <gtkmm/application.h>
#include <fstream>

// Constructor
Todo::Todo()
:   m_optionsFrame{"Options"}, m_mainBox{Gtk::Orientation::VERTICAL},
    m_listButton{"List goals"}, m_addButton{"Add goals"}, m_markButton{"Mark goals"},
    m_removeButton{"Remove goals"}, m_eraseButton{"Erase list"}, m_exitButton{"Exit todo"}
{
    // Main window setup
    set_title("Todo-Menu");
    set_default_size(500, 500);
    set_child(m_mainBox);

    // Sets up the child widgets of m_mainbox as well as the m_mainbox's format
    m_mainBox.set_margin(10);
    m_mainBox.set_valign(Gtk::Align::FILL);
    m_mainBox.set_halign(Gtk::Align::CENTER);
    m_mainBox.append(m_title_box);
    m_mainBox.append(m_optionsFrame);

    // Setting up the todo title drawing area and assigning size
    m_title_box.append(m_title_area);
    m_title_area.set_content_width(150);
    m_title_area.set_content_height(100);

    // create list preemptively
    std::ofstream list{"todo.txt"};

    // It is not likely all the current buttons will exist, and will be replaced with methods less
    // similar to the similar todo cli, these buttons are clearly based on the cli as a placeholder
    m_optionsFrame.set_child(m_optionsGrid);
    m_optionsGrid.attach(m_listButton, 0, 0);
    m_optionsGrid.attach(m_addButton, 1, 0);
    m_optionsGrid.attach(m_markButton, 2, 0);
    m_optionsGrid.attach(m_removeButton, 0, 1);
    m_optionsGrid.attach(m_eraseButton, 1, 1);
    m_optionsGrid.attach(m_exitButton, 2, 1);

    // Binds buttons to signal handlers so that once pressed the signal emmitted can be catched
    m_listButton.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Todo::on_button_clicked), 1));
    m_addButton.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Todo::on_button_clicked), 2));
    m_exitButton.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Todo::on_button_clicked), 6));
}

Todo::~Todo()
{}

// Function that in the future will determine what happens when the buttons are pressed
// It is not likely all the current buttons will exist, and will be replaced with methods less
// similar to the similar todo cli, these buttons are clearly based on the cli as a placeholder
void Todo::on_button_clicked(int menu_option)
{   
    switch (menu_option) 
    {
        case 1:

            break;
        case 2:
            //add_to_list(*this);
            break;
        case 6:
            close();
        default: break;
    }
}