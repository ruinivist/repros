#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

int main(int argc, char **argv) {
  gtk_init(&argc, &argv);
  if (argc != 2) {
    g_printerr("usage: %s index.html\n", argv[0]);
    return 1;
  }

  gchar *html;
  GError *error = NULL;
  if (!g_file_get_contents(argv[1], &html, NULL, &error)) {
    g_printerr("%s\n", error->message);
    g_error_free(error);
    return 1;
  }

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *view = webkit_web_view_new();
  gtk_window_set_default_size(GTK_WINDOW(window), 640, 360);
  gtk_container_add(GTK_CONTAINER(window), view);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  webkit_web_view_load_html(WEBKIT_WEB_VIEW(view), html,
                            "https://clipboard-repro.invalid/");
  gtk_widget_show_all(window);
  gtk_main();
  g_free(html);
}
