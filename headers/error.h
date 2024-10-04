#ifndef ERRORDIALOG
#define ERRORDIALOG

#include <gtkmm/window.h>
#include "todo.h"

enum err_signals
{
    FILE_FAILED_TO_OPEN,
    INVALID_OPERATION
};

//Declaration of function that pops up an error dialog
void error(Todo& parent, err_signals signal);

#endif