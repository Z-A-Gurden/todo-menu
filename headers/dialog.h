#ifndef DIALOG_BOX
#define DIALOG_BOX

#include <memory>
#include <optional>
#include <gtkmm/alertdialog.h>
#include <glib-object.h>
#include "todo.h"
#include "file_view.h"

enum err_signals
{
    FILE_FAILED_TO_OPEN,
    INVALID_OPERATION
};
enum dia_signals
{
    CONFIRM_ERASE,
    CONFIRM_EXIT
};

class Dialog : public Gtk::AlertDialog
{
    public:
    Dialog(Todo& parent, err_signals signal);
    Dialog(Todo& parent, dia_signals signal);

    private:
    // Creates error dialog, needs an enum err_signals signal(declared in dialog.h): FILE_FAILED_TO_OPEN, INVALID_OPERATION
    void error(err_signals signal);
    // Creates confirm dialog prompt(declared in dialog.h): CONFIRM_ERASE, CONFIRM_EXIT
    void confirm(dia_signals signal);
    void on_button_press(const Glib::RefPtr<Gio::AsyncResult>& result);
    Todo& m_parent;
    Glib::RefPtr<Gtk::AlertDialog> m_dialog;
    std::optional<TodoFile> m_file;
};
#endif