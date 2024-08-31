#include<gtk/gtk.h>

static void cd_button_clicked(GtkWidget *button, gpointer user_data){
  gtk_main_quit();
}

int main(int argc,char *argv[]){
  //Window
  GtkWidget *window;
  gtk_init(&argc,&argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(window,300,200);
  
  //button
  GtkWidget *button;
  button = gtk_button_new_with_label("Quit");
  gtk_container_add(GTK_CONTAINER(window),button);

  //quit
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(cd_button_clicked), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
