#include "audio.h"
#include <iostream>
#include <gtk/gtk.h>

static AudioPlayer player;

int PlayClick(GtkWidget *widget, gpointer data) {
    g_print("PlayBtn %s\n", (char*)data);

    if (!player.load("song.mp3")) {
        std::cerr << "Failed to load audio file!" << std::endl;
        return 1;
    }

    player.play();
    player.setVolume(100.0f);

    sf::SoundSource::Status status = player.getStatus();
    const char* statusStr;
    switch(status) {
        case sf::SoundSource::Stopped: statusStr = "Stopped"; break;
        case sf::SoundSource::Paused:  statusStr = "Paused"; break;
        case sf::SoundSource::Playing: statusStr = "Playing"; break;
        default: statusStr = "Unknown";
    }
    g_print("Playback status: %s\n", statusStr);
    return 0;
}

void on_slider_changed(GtkRange *range, gpointer user_data) {
    double value = gtk_range_get_value(range);
    g_print("Slider value: %.2f\n", value);
}
void createMusicTimeSlider(GtkWidget *right_container){


    GtkWidget *slider = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0.0, 100.0, 1.0);

    gtk_range_set_value(GTK_RANGE(slider), 50.0);
    gtk_scale_set_draw_value(GTK_SCALE(slider), FALSE);
    g_signal_connect(slider, "value-changed", G_CALLBACK(on_slider_changed), NULL);

    gtk_container_add(GTK_CONTAINER(right_container), slider);

}
void createButtons(GtkWidget *right_container) {
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);  
    
    GtkWidget *align = gtk_alignment_new(0.5, 0.9, 0, 0);  
    
    GtkWidget *nextBtn = gtk_button_new_with_label("Next");
    GtkWidget *playBtn = gtk_button_new_with_label("Play");
    GtkWidget *backBtn = gtk_button_new_with_label("Back");
    
    g_signal_connect(nextBtn, "clicked", G_CALLBACK(PlayClick), (gpointer)"Next");
    g_signal_connect(playBtn, "clicked", G_CALLBACK(PlayClick), (gpointer)"Play");
    g_signal_connect(backBtn, "clicked", G_CALLBACK(PlayClick), (gpointer)"Back");
    
    gtk_box_pack_start(GTK_BOX(button_box), nextBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), playBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), backBtn, FALSE, FALSE, 0);
    
    gtk_container_add(GTK_CONTAINER(align), button_box);  
    
    gtk_container_add(GTK_CONTAINER(right_container), align);
}

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


    createButtons(right_container);
    createMusicTimeSlider(right_container);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
