#include <iostream>
#include <fstream>
#include <regex>
#include "../headers/file_view.h"
#include "../headers/file.h"
#include "../headers/dialog.h"

// Constructor reads the file into the textview and also sets m_buffer as the buffer to *this
TodoFile::TodoFile(Todo& parent)
    : m_buffer{Gtk::TextBuffer::create()}, m_parent{parent}
{
    error_flag = read_file_into_buffer();
    set_buffer(m_buffer);
}

// copy constructor
TodoFile::TodoFile(TodoFile& origin)
: m_buffer{origin.m_buffer}, m_parent{origin.m_parent}
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
        Dialog error(m_parent, FILE_FAILED_TO_OPEN);
        m_buffer->set_text("File failed to open! Try restarting the program.");
        set_editable(false);
        return -1;
    }

    std::string file{};
    std::string line{};
    int line_num{1};
    while(getline(in, line))
    {
        file += std::to_string(line_num) + ". " + line + '\n';
        line_num++;
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
        Dialog error(m_parent, FILE_FAILED_TO_OPEN);
        return -1;
    
    }
    // updated from old regex pattern, replacement of numbers mid line SEEMS to be fixed.
    std::regex pattern{"^[0-9].[[:space:]]", std::regex_constants::multiline};
    std::string temp{m_buffer->get_text()};
    std::string result{std::regex_replace(temp, pattern, "")};
    out << result;

    return 0;
}

// Erase list defined here for consistency
// Removed previous file overwrite code as I feel that erase list should not erase until save list is used or future confirm dialog upon exit
int TodoFile::erase_list()
{
    m_buffer->set_text("");
    return 0;
}
