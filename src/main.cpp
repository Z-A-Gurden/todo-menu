#include "../headers/todo.h"
#include <gtkmm/application.h>

// creates application and runs it, then returns whether or not it was successful once closed
int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("todo.menu");

  return app->make_window_and_run<Todo>(argc, argv);
}