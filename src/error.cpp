#include <iostream>
#include <gtkmm/alertdialog.h>
#include "../headers/error.h"

// Function creates a dialog which is modal to the parent (can't interact with parent window until dialog closed), 
// dialog is mapped transiently as recommended
// This can pop up whenever there is an error, further implementation could be that there is a param flag for each error,
// linked to a switch to choose the dialog text in set_detail
void error(Todo& parent, err_signals signal)
{
    auto m_error_dialogue {Gtk::AlertDialog::create()};
    m_error_dialogue->set_modal();

    switch(signal)
    {   
        case 0:
            m_error_dialogue->set_message("File Error!");
            m_error_dialogue->set_detail("A file failed to open!\nTry restarting the program.");
            break;
        case 1:
            m_error_dialogue->set_message("Invalid Operation");
            m_error_dialogue->set_detail("You have entered an invalid operation!");
    }
    m_error_dialogue->show(parent);
}