#include "todo.h"
#include <gtkmm.h>

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("todo.menu");

  return app->make_window_and_run<Todo>(argc, argv);
}