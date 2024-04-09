#include <gtk/gtk.h>

// Function prototypes
typedef struct {
  int width, height;
  int max_color;
  int ***pixels;
} Image;

typedef struct {
  char *command;
  void (*func)(Image *, float);
} Command;

typedef struct {
  int cmd_index;
  int value;
} Adjustment;

/* Function prototypes*/
Image *load_ppm(const char *filename);
GdkPixbuf *convert_image_to_pixbuf(Image *img);
void updateAdjustment(GtkLabel *adj, int num);
void addAdjustment(GtkWidget *button, GtkLabel *adj);
void minusAdjustment(GtkWidget *button, GtkLabel *adj);

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  // Check for command line arguments (image filename)
  if (argc != 2) {
    g_printerr("Usage: %s <image.ppm>\n", argv[0]);
    return 1;
  }

  // Load PPM image
  Image *img = load_ppm(argv[1]);
  if (!img) {
    g_printerr("Error loading image\n");
    return 1;
  }

  // Convert image to GdkPixbuf
  GdkPixbuf *pixbuf = convert_image_to_pixbuf(img);
  if (!pixbuf) {
    g_printerr("Error converting image to pixbuf\n");
    return 1;
  }
  // Window and image widget
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "LiteRoom Image Editor");
  GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);

  GtkWidget *label_brightness = gtk_label_new("Brightness");
  GtkWidget *brightness_value = gtk_label_new("0");
  GtkWidget *label_temp = gtk_label_new("Temperature");
  GtkWidget *temp_value = gtk_label_new("0");
  GtkWidget *label_tint = gtk_label_new("Tint");
  GtkWidget *tint_value = gtk_label_new("0");


  // Button for brightness increase
  GtkWidget *button_increase_brightness = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_brightness, "clicked", G_CALLBACK(addAdjustment), brightness_value); // Pass image widget to the function

  // Button for brightness decrese
  GtkWidget *button_decrease_brightness = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_brightness, "clicked", G_CALLBACK(minusAdjustment), brightness_value); // Pass image widget to the function

  // Button for temp increase
  GtkWidget *button_increase_temp = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_temp, "clicked", G_CALLBACK(addAdjustment), temp_value); // Pass image widget to the function

  // Button for temp decrease
  GtkWidget *button_decrease_temp = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_temp, "clicked", G_CALLBACK(minusAdjustment), temp_value); // Pass image widget to the function

    // Button for tint increase
  GtkWidget *button_increase_tint = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_tint, "clicked", G_CALLBACK(addAdjustment), tint_value); // Pass image widget to the function

  // Button for tint decrease
  GtkWidget *button_decrease_tint = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_tint, "clicked", G_CALLBACK(minusAdjustment), tint_value); // Pass image widget to the function

  // Layout
  GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

  GtkWidget *editingbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);

  GtkWidget *brightnessbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(brightnessbox), button_decrease_brightness, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(brightnessbox), label_brightness, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(brightnessbox), brightness_value, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(brightnessbox), button_increase_brightness, TRUE, TRUE, 0);
  

  GtkWidget *tempbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(tempbox), button_decrease_temp, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(tempbox), label_temp, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(tempbox), temp_value, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(tempbox), button_increase_temp, TRUE, TRUE, 0);

  GtkWidget *tintbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(tintbox), button_decrease_tint, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(tintbox), label_tint, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(tintbox), tint_value, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(tintbox), button_increase_tint, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(editingbox), brightnessbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), tempbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), tintbox, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(hbox), editingbox, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(window), hbox);

  // Signals and show all
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);

  gtk_main();
  printf("Image editor closed\n");

  return 0;
}


Image *load_ppm(const char *filename) {
  int i, j;
  Image *img;

  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("File opening failed");
    return NULL;
  }

  img = malloc(sizeof(Image));
  if (fscanf(fp, "P3\n%d %d\n%d\n", &img->width, &img->height,
             &img->max_color) != 3) {
    fclose(fp);
    free(img);
    return NULL;
  }

  img->pixels = malloc(img->height * sizeof(int **));
  for (i = 0; i < img->height; i++) {
    img->pixels[i] = malloc(img->width * sizeof(int *));
    for (j = 0; j < img->width; j++) {
      img->pixels[i][j] = malloc(3 * sizeof(int));
      if (fscanf(fp, "%d %d %d", &img->pixels[i][j][0], &img->pixels[i][j][1],
                 &img->pixels[i][j][2]) != 3) {
        printf("Error reading pixel at (%d, %d)\n", i, j);
        fclose(fp);
        free(img);
        return NULL;
      }
    }
  }
  printf("Loaded image with width=%d, height=%d\n", img->width, img->height);

  fclose(fp);
  return img;
}

GdkPixbuf *convert_image_to_pixbuf(Image *img) {
  int i, j;
  GdkPixbuf *pixbuf;
  guchar *pixels;
  int rowstride, n_channels;

  n_channels = 3;
  rowstride = img->width * n_channels;
  pixels = malloc(rowstride * img->height);

  for (i = 0; i < img->height; i++) {
    for (j = 0; j < img->width; j++) {
      pixels[i * rowstride + j * n_channels] = img->pixels[i][j][0];
      pixels[i * rowstride + j * n_channels + 1] = img->pixels[i][j][1];
      pixels[i * rowstride + j * n_channels + 2] = img->pixels[i][j][2];
    }
  }

  pixbuf = gdk_pixbuf_new_from_data(pixels, GDK_COLORSPACE_RGB, FALSE, 8,
                                    img->width, img->height, rowstride, NULL, NULL);

  return pixbuf;
}

void updateAdjustment(GtkLabel *adj, int num) {
  gchar *display;
  display = g_strdup_printf("%d", num);         //convert num to str
  gtk_label_set_text (GTK_LABEL(adj), display); //set label to "display"
  g_free(display); 
}

void addAdjustment(GtkWidget *button, GtkLabel *adj) {
  int num = atoi(gtk_label_get_text(adj));
  num += 1;
  g_print("%d\n",num);
  updateAdjustment(GTK_LABEL(adj), num);
}

void minusAdjustment(GtkWidget *button, GtkLabel *adj) {
  int num = atoi(gtk_label_get_text(adj));
  num -= 1;
  g_print("%d\n",num);
  updateAdjustment(GTK_LABEL(adj), num);
}