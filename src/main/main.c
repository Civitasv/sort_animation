#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shuffle/shuffle.h"

static void
gtk_css_set(GtkWidget *g_widget);

static void
activate(GtkApplication *app,
         gpointer user_data);

static void
gtk_css_set(GtkWidget *g_widget)
{
    GtkCssProvider *provider = gtk_css_provider_new();

    gtk_css_provider_load_from_path(provider,
                                    "./sort_animation.css", NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(g_widget);

    gtk_style_context_add_provider(context,
                                   GTK_STYLE_PROVIDER(provider),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

static void
activate(GtkApplication *app,
         gpointer user_data)
{
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Sort Animation");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

    gtk_widget_show_all(window);
}

int main(int argc,
         char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.civitasv.sort.animation", G_APPLICATION_FLAGS_NONE);
    // add callback on active application
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    // free memory
    g_object_unref(app);
    return 0;
}
