#ifndef TODO_TITLE
#define TODO_TITLE
#include <gtkmm/drawingarea.h>

class Todo_Title : public Gtk::DrawingArea
{
    // Constructor/Destructor forwared declaration
    public:
        Todo_Title();
        virtual ~Todo_Title();

    // Function used for drawing the todo title
    protected:
        void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int w_width, int w_height);
};

#endif