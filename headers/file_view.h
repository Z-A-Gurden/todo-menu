#ifndef FILE_BUFFER
#define FILE_BUFFER

#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>

class Todo;

class TodoFile : public Gtk::TextView
{
    public:
        TodoFile(Todo& parent);
        TodoFile(TodoFile& origin);
        ~TodoFile() override;
        bool get_error_flag(){return error_flag;}
        int save_buffer_into_file();
        int read_file_into_buffer();
        int erase_list();

    private:
        Glib::RefPtr<Gtk::TextBuffer> m_buffer;
        Todo& m_parent;
        bool error_flag{false};
};

#endif