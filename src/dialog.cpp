#include <iostream>
#include "../headers/dialog.h"
Dialog::Dialog(Todo& parent, err_signals signal)
: m_parent{parent}, m_dialog{Gtk::AlertDialog::create()}
{
    m_dialog->set_modal();
    error(signal);
}
Dialog::Dialog(Todo& parent, dia_signals signal)
: m_parent{parent}, m_dialog{Gtk::AlertDialog::create()}, m_file{parent.get_file()}
{
    m_dialog->set_modal();
    confirm(signal);
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

void Dialog::confirm(dia_signals signal)
{
    switch(signal)
    {
        case CONFIRM_ERASE:
            m_dialog->set_message("Erase List?");
            m_dialog->set_detail("You have clicked \"erase list\", press confirm to proceed or press cancel");
            m_dialog->set_buttons({"Confirm", "Cancel"});
            m_dialog->set_default_button(0);
            //m_dialog->set_cancel_button(1);
            break;
        case CONFIRM_EXIT:
            break;
    }
    m_dialog->choose(m_parent, sigc::mem_fun(*this, &Dialog::on_button_press));
}

void Dialog::on_button_press(const Glib::RefPtr<Gio::AsyncResult>& signal)
{
    const int id{m_dialog->choose_finish(signal)};
        switch(id)
        {
            /* case 0:
                m_file->erase_list();
                break; */
            default:
                std::cout << "Unexpected Result!\n";
                m_file->erase_list();
        }
}

