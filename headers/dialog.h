#ifndef DIALOG_BOX
#define DIALOG_BOX

#include <gtkmm/alertdialog.h>
#include <glib-object.h>
#include "todo.h"
#include "file_view.h"

enum err_signals
{
    FILE_FAILED_TO_OPEN,
    INVALID_OPERATION
};

class Dialog : public Gtk::AlertDialog
{
    public:
    Dialog(Todo& parent, err_signals signal);

    private:
    // Creates error dialog, needs an enum err_signals signal(declared in dialog.h): FILE_FAILED_TO_OPEN, INVALID_OPERATION
    void error(err_signals signal);
    Todo& m_parent;
    Glib::RefPtr<Gtk::AlertDialog> m_dialog;
};
#endif