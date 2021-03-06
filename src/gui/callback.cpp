/*
 * File : callback.cpp
 *
 * File created by : Corentin Gay
 * File was created the : 08/09/2017
 */

#include <callback.hpp>

static GdkPixbuf* global = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, 160, 144);
static GdkPixbuf* scaled = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, 1600, 1440);

static std::unordered_map<std::string, Key> bindings =
	{{"Up", Key::UP},
	 {"Down", Key::DOWN},
	 {"Left", Key::LEFT},
	 {"Right", Key::RIGHT},
	 {"a", Key::A},
	 {"s", Key::B},
	 {"d", Key::SELECT},
	 {"f", Key::START},
	};

GdkPixbuf* get_global_pixbuf()
{
	return global;
}

void NYI(GtkWidget * b, gpointer user_data)
{
	(void)user_data;
	std::cout << "Button \"" << gtk_menu_item_get_label(GTK_MENU_ITEM(b))
		    << "\" not yet implemented." << std::endl;
}

gboolean key_pressed_callback(GtkWidget *widget, GdkEventKey *event)
{
	if (!event) return false;
	std::string str(gdk_keyval_name(event->keyval));
	if (bindings.find(str) != bindings.end())
		Emulator::getInstance().key_press(bindings[str]);

	return true;
}

gboolean key_released_callback(GtkWidget *widget, GdkEventKey *event)
{
	if (!event) return false;
	std::string str(gdk_keyval_name(event->keyval));
	if (bindings.find(str) != bindings.end())
		Emulator::getInstance().key_release(bindings[str]);

	return true;
}

void stop_callback(GtkWidget * w, gpointer user_data)
{
	(void)w;
	(void)user_data;
	Emulator::getInstance().stop();
}


void open_button_callback(GtkWidget * b, gpointer user_data)
{
	(void)b;
	OpenButtonHelper *helper = (OpenButtonHelper *)user_data;
	GFile* g = helper->open_file_with_dialog();
	uint8_t *data = helper->load_content(g);

	if (!data)
		return;

	// Emulator takes ownership of the data pointer
	Emulator::getInstance().changeCartridge(data);

	free(data);
}

void run_button_callback(GtkWidget * b, gpointer user_data)
{
	(void)b;
	(void)user_data;

	Emulator::getInstance().start();
}

gboolean draw_callback(GtkWidget * w, cairo_t *cr, gpointer user_data)
{
	int width = 0, height = 0;
	GtkStyleContext *context;

	context = gtk_widget_get_style_context(w);
	width = gtk_widget_get_allocated_width(w);
	height = gtk_widget_get_allocated_height(w);

	gtk_render_background(context, cr, 150, 150, width, height);

	gdk_cairo_set_source_pixbuf(cr, global, 0, 0);
 	cairo_paint (cr);

	return FALSE;
}

int trigger_draw(GtkWidget * area, GdkFrameClock * c, gpointer user_data)
{
	(void)c;
	(void)user_data;
	gtk_widget_queue_draw_area(area, 0, 0,
			gtk_widget_get_allocated_width(area),
			gtk_widget_get_allocated_height(area));
	return 42;
}
