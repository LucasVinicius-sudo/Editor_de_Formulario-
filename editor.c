/*INCOMPLETO**/
#include <gtk/gtk.h>
#include <stdio.h>
void mostrar()//Mostra o Formulario 
{


  FILE *fpointer;
  fpointer = fopen("formulario.txt","r");
  char singleline[200];


  while(!feof(fpointer))
  {
    fgets(singleline,70,fpointer);
    printf("%s",singleline );
  }


  fclose(fpointer);
}
/*gcc `pkg-config --cflags gtk+-3.0` -o start start.c `pkg-config --libs gtk+-3.0`*/
int main(int argc, char *argv[])
{

//Varivaies//
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *label;
  GtkWidget *toolbar;
  GtkToolItem *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb;
  GtkToolItem *sep;
  GtkToolItem *exitTb;
  GtkToolItem *editTb;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
  gtk_window_set_title(GTK_WINDOW(window), "EDITOR DE FORMULARIO");

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
//NOVO JANELA///
  newTb = gtk_tool_button_new (gtk_image_new_from_icon_name ("document-new", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

  //SEPARADOR
    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);


//ABRI UM DOCUMENTO
  openTb = gtk_tool_button_new (gtk_image_new_from_icon_name ("document-new", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

  //SEPARADOR
    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);


//SALVAR UM DOCUMENTO
  saveTb = gtk_tool_button_new (gtk_image_new_from_icon_name ("edit-copy", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

//SEPARADOR
  sep = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);

  //Editar um Arquivo
  editTb = gtk_tool_button_new(gtk_image_new_from_icon_name("gtk-convert",GTK_ICON_SIZE_SMALL_TOOLBAR),NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), editTb, -1);

  //SEPARADOR
    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);


//SAIR DA JANELA
  exitTb = gtk_tool_button_new (gtk_image_new_from_icon_name ("gtk-quit", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  g_signal_connect(G_OBJECT(exitTb), "clicked",G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);





  gtk_widget_show_all(window);

  gtk_main();
  //mostrar();
  return 0;
}
