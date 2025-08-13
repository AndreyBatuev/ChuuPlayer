#include "audio.h"
#include <iostream>
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ChuuPlayer");
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), hbox);

    GtkWidget *left_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(hbox), left_container, FALSE, FALSE, 0);
    
    GtkWidget *right_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(hbox), right_container, TRUE, TRUE, 0);

    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "#left { background: #c978bb; min-width: 200px; }"
        "#right { background: #c03833; }", -1, NULL);
    
    gtk_widget_set_name(left_container, "left");
    gtk_widget_set_name(right_container, "right");
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}