#include "../headers/todo_title.h"

// Constructor sets the function used for drawing with Cairo
TodoTitle::TodoTitle()
{
    set_draw_func(sigc::mem_fun(*this, &TodoTitle::on_draw));
}

TodoTitle::~TodoTitle()
{}

// Creates the context and draws the todo title text
void TodoTitle::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{   
    cr->set_source_rgba(0.3, 0.3, 0.3, 0.5);
    cr->rectangle(0, 0, width, height);
    cr->fill();
    draw_title_text(cr, width, height);
}

void TodoTitle::draw_title_text(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
    cr->save();
     cr->set_source_rgba(0.4, 0.4, 0.4, 1);

    // Creates the 'font description' which consists of the font family and the weight, then it is assigned to a layout
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::Weight::BOLD);
    auto layout = create_pango_layout("Welcome to Todo");
    layout->set_font_description(font);

    int text_width, text_height;
    layout->get_pixel_size(text_width, text_height);
    cr->move_to((width-text_width)/2, (height-text_height)/2);
    // Draws the text layout
    layout->show_in_cairo_context(cr);
    cr->restore();
}