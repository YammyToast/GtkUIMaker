// src/main.cpp

#include <gtk/gtk.h>

#include <argparse/argparse.hpp>
#include <iostream>

static void on_activate(GtkApplication* app, gpointer user_data) {
    GtkWidget* window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GTK4 Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_widget_show(window);
}

int main(int argc, char** argv) {
    GtkApplication* app;
    int status;

    app = gtk_application_new("com.example.MyGtkApp", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}