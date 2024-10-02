#include "todo.h"
#include <iostream>
//#include <iterator>

Todo::Todo()
:   m_optionsFrame{"Options"},
    m_listButton{"List goals"}, m_addButton{"Add goals"}, m_markButton{"Mark goals"},
    m_removeButton{"Remove goals"}, m_eraseButton{"Erase list"}, m_exitButton{"Exit todo"}
{
    set_title("Todo-Menu");
    set_default_size(300, 300);
    set_child(m_mainBox);
    m_mainBox.set_margin(10);
    m_mainBox.set_valign(Gtk::Align::CENTER);
    m_mainBox.set_halign(Gtk::Align::CENTER);
    m_mainBox.append(m_optionsFrame);

    m_optionsFrame.set_child(m_optionsGrid);
    m_optionsFrame.set_expand(true);
    m_optionsGrid.attach(m_listButton, 0, 0);
    m_optionsGrid.attach(m_addButton, 1, 0);
    m_optionsGrid.attach(m_markButton, 2, 0);
    m_optionsGrid.attach(m_removeButton, 0, 1);
    m_optionsGrid.attach(m_eraseButton, 1, 1);
    m_optionsGrid.attach(m_exitButton, 2, 1);
}

Todo::~Todo()
{}
