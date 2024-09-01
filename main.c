#include<gtk/gtk.h>

static void cd_button_clicked(GtkWidget *button, gpointer user_data){
  gtk_main_quit();
}

int main(int argc,char *argv[]){

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *image;
  GtkWidget *vbox;

  if(argc !=2){
    g_print("Usage: %s image-file\n",argv[0]);
    exit(1);
  }
  //init
  gtk_init(&argc,&argv);

  //Window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(window,300,200);
  
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);

  image = gtk_image_new_from_file(argv[1]);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_box_pack_start(GTK_BOX(vbox), image, TRUE, TRUE, 0);

  //button
  button = gtk_button_new_with_label("Quit");
  gtk_container_add(GTK_CONTAINER(window),button);
  gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

  //quit
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(cd_button_clicked), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
