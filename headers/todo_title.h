#ifndef TODO_TITLE
#define TODO_TITLE

#include <gtkmm/drawingarea.h>

class TodoTitle : public Gtk::DrawingArea
{
    // Constructor/Destructor forwared declaration
    public:
        TodoTitle();
        virtual ~TodoTitle();

    // Function used for drawing the todo title
    protected:
        void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
    
    private:
        void draw_title_text(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};

#endif