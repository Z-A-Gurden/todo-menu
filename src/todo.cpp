#include <iostream>
#include <fstream>
#include <gtkmm/application.h>
#include "../headers/todo.h"
#include "../headers/dialog.h"

// Constructor
Todo::Todo()
:   m_optionsFrame{"Options"}, m_mainBox{Gtk::Orientation::VERTICAL},
    m_save_list_button{"Save list"}, m_erase_list_button{"Erase list"}, m_exit_button{"Exit todo"},
    m_file_view{*this}
{
    // Main window setup
    set_title("Todo-Menu");
    set_default_size(500, 250);
    int width, height;
    get_default_size(width, height);
    set_child(m_mainBox);

    // Sets up the child widgets of m_mainbox as well as the m_mainbox's format
    m_mainBox.set_margin(10);
    m_mainBox.set_valign(Gtk::Align::FILL);
    m_mainBox.set_halign(Gtk::Align::CENTER);
    m_mainBox.append(m_title_box);
    m_mainBox.append(m_file_scroller);
    m_mainBox.append(m_optionsFrame);

    // Setting up the todo title drawing area and assigning size
    m_title_box.append(m_title_area);
    m_title_area.set_margin(10);
    m_title_area.set_hexpand(true);
    m_title_area.set_content_height(50);

    // create list preemptively
    //std::ofstream list{"todo.txt", std::ios::app};
    
    // Puts the text view into a scrollable widget
    m_file_scroller.set_child(m_file_view);
    m_file_scroller.set_size_request(width, height);

    // It is not likely all the current buttons will exist, and will be replaced with methods less
    // similar to the similar todo cli, these buttons are clearly based on the cli as a placeholder
    m_optionsFrame.set_child(m_optionsGrid);
    m_optionsGrid.attach(m_save_list_button, 0, 0);
    m_optionsGrid.attach(m_erase_list_button, 1, 0);
    m_optionsGrid.attach(m_exit_button, 2, 0);

    // Binds buttons to signal handlers so that once pressed the signal emmitted can be catched
    m_save_list_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Todo::on_button_clicked), 1));
    m_erase_list_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Todo::on_button_clicked), 2));
    m_exit_button.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Todo::on_button_clicked), 3));
}

Todo::~Todo()
{}

TodoFile& Todo::get_file(){ return m_file_view; }

// Function that in the future will determine what happens when the buttons are pressed
// It is not likely all the current buttons will exist, and will be replaced with methods less
// similar to the similar todo cli, these buttons are clearly based on the cli as a placeholder
void Todo::on_button_clicked(int menu_option)
{   
    /* if(menu_option == 1)
    {
        if(m_file_view.get_error_flag())
        {
            Dialog error(*this, INVALID_OPERATION);
        }
        m_file_view.save_buffer_into_file();
    }
    else if(menu_option == 2)
    {
        Dialog confirm(*this, CONFIRM_ERASE, m_file_view);
    }
    else close(); */
    
    switch (menu_option) 
    {
        case 1:
            if(m_file_view.get_error_flag())
                {
                    Dialog error(*this, INVALID_OPERATION);
                    break;
                }
            m_file_view.save_buffer_into_file();
            break;
        case 2:
        {
            //m_file_view.erase_list();
            Dialog confirm(*this, CONFIRM_ERASE);
            break;
        }
        case 3:
            close();
        default: break;
    }
   
}