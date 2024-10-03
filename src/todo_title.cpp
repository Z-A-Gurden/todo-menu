#include "../headers/todo_title.h"

// Constructor sets the function used for drawing with Cairo
Todo_Title::Todo_Title()
{
    set_draw_func(sigc::mem_fun(*this, &Todo_Title::on_draw));
}

Todo_Title::~Todo_Title()
{}

// Creates the context and draws the todo title text
void Todo_Title::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int w_width, int w_height)
{
    // The below commented code is test code for cairo drawing:
    // int xc, yc;
    // xc = w_width/2;
    // yc = w_height/2;

    // cr->set_line_width(10.0);

    // cr->set_source_rgb(0.8, 0.0, 00);
    // cr->move_to(0, 0);
    // cr->line_to(xc, yc);
    // cr->line_to(0, w_height);
    // cr->move_to(xc, yc);
    // cr->line_to(w_width, yc);
    // cr->stroke();

    cr->set_source_rgb(119, 136, 153);

    // Creates the 'font description' which consists of the font family and the weight, then it is assigned to a layout
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::Weight::BOLD);
    auto layout = create_pango_layout("Welcome to Todo");
    layout->set_font_description(font);

    int text_width, text_height;
    layout->get_pixel_size(text_width, text_height);
    cr->move_to((w_width-text_width)/2, (w_height-text_height)/2);
    // Draws the text layout
    layout->show_in_cairo_context(cr);
}