#include <fstream>
#include <iostream>
#include "../headers/file_view.h"
#include "../headers/file.h"
#include "../headers/error.h"

// Constructor reads the file into the textview and also sets m_buffer as the buffer to *this
TodoFile::TodoFile(Todo& parent)
    : m_buffer{Gtk::TextBuffer::create()}, m_parent{parent}
{
    error_flag = read_file_into_buffer();
    set_buffer(m_buffer);
}

TodoFile::~TodoFile()
{}

// This function will read the contents of todo.txt into the textview contained within the scrollable window
int TodoFile::read_file_into_buffer()
{
    std::ifstream in{dir / "todo.txt"};
    if(!in)
    {
        error(m_parent, FILE_FAILED_TO_OPEN);
        m_buffer->set_text("File failed to open! Try restarting the program.");
        set_editable(false);
        return -1;
    }

    std::string file{};
    std::string line{};
    //int line_num{1};
    while(getline(in, line))
    {
        //file += std::to_string(line_num) + ". " + line + '\n';
        file += line + '\n';
        //line_num++;
    }
    m_buffer->set_text(file);
    return 0;
}

// This function saves contents of m_buffer into todo.txt, i.e if a user enters text into the text viewer/buffer, pressing this
// will save the extra info along with the old info
int TodoFile::save_buffer_into_file()
{
    std::ofstream out{dir / "todo.txt"};
    if(!out)
    {
        // Note, need to implement logic that prevents the overwrite that occurs as a result of the preceeding
        // file opening in spite of file failure to open
        error(m_parent, FILE_FAILED_TO_OPEN);
        return -1;
    }

    out << m_buffer->get_text();
    return 0;
}