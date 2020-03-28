#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<gtk/gtk.h>
#include<gtk/gtkx.h>
#include<math.h>
#include<ctype.h>

//Make these global

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *button1;
GtkWidget *label1;
GtkBuilder *builder;

int main(int argc, char *argv[]){

  gtk_init(&argc, &argv);// init Gtk

//------------------------------------------------------------------------
// Establish contact with xml code used to adjust widget settings 
//------------------------------------------------------------------------

  builder = gtk_builder_new_from_file("glade/first1.glade");

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

  g_signal_connect(window, "distroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(builder, NULL);

  fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "cont"));
  button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button"));
  label1 = GTK_WIDGET(gtk_builder_get_object(builder, "lable1"));

  gtk_widget_show(window);
  gtk_main();

  return EXIT_SUCCESS;
}
void on_button_clicked(GtkButton *b){
  gtk_label_set_text(GTK_LABEL(label1), (const gchar *)"Hello world!");
}


// TO Run 
//  gcc -o gladewin main1.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic