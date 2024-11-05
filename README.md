# todo-menu
This is a todo list app made using gtk/gtkmm-4.0.
This is simply a learning project and isn't for serious use.
Currently todo supports basic i/o, and has numbered lines like in my cli todo list. It currently lacks other todo features such as checking goals. i.e at the moment it is a text editor with numbered lines.

## Planned Behaviour and Issues
It is planned to also add confirm dialogs (hence the renaming of error.* to dialog.* from previous versions). Currently there are issues I am having with that, and my best guess for why that is is that maybe Gtk::AlertDialog does not allow for it, but I'm not too sure as this is simply a learning project. Potential solutions for this could be to make my own dialog with Gtk::Window, or try other 'convenience' dialogs such as Gtk::MessageDialog.

## Dependencies
[gtk4](https://www.gtk.org/docs/installations/index) and [gtkmm-4.0](https://gtkmm.org/en/download.html).

## How to build
simply type within the directory:
```
make
```

## Miscellaneous
To clean up your directory of any object files, type:
```
make clean
```