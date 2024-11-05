#include <iostream>
#include "../headers/dialog.h"
Dialog::Dialog(Todo& parent, err_signals signal)
: m_parent{parent}, m_dialog{Gtk::AlertDialog::create()}
{
    m_dialog->set_modal();
    error(signal);
}

void Dialog::error(err_signals signal)
{
    switch(signal)
    {   
        case FILE_FAILED_TO_OPEN:
            m_dialog->set_message("File Error!");
            m_dialog->set_detail("A file failed to open!\nTry restarting the program.");
            break;
        case INVALID_OPERATION:
            m_dialog->set_message("Invalid Operation");
            m_dialog->set_detail("You have entered an invalid operation!");
    }
    m_dialog->show(m_parent);
}