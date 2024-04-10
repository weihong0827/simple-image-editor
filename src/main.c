#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Image states[5];

// add new state to the states array
void add_state(Image *img) {
  for (int i = 4; i > 0; i--) {
    states[i] = states[i - 1];
  }
  Image *new_img = malloc(sizeof(Image));
  new_img->width = img->width;
  new_img->height = img->height;
  new_img->pixels =  malloc(img->height * sizeof(int **));
  for (int i = 0; i < img->height; i++) {
    new_img->pixels[i] = malloc(img->width * sizeof(int *));
    for (int j = 0; j < img->width; j++) {
      new_img->pixels[i][j] = malloc(3 * sizeof(int));
      new_img->pixels[i][j][0] = img->pixels[i][j][0];
      new_img->pixels[i][j][1] = img->pixels[i][j][1];
      new_img->pixels[i][j][2] = img->pixels[i][j][2];
    }
  }
  states[0] = *new_img;
}

// undo the last state
void undo(Image *img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      img->pixels[i][j][0] = states[0].pixels[i][j][0];
      img->pixels[i][j][1] = states[0].pixels[i][j][1];
      img->pixels[i][j][2] = states[0].pixels[i][j][2];
    }
  }
  for (int i = 0; i < 4; i++) {
    states[i] = states[i + 1];
  }
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
  display = g_strdup_printf("%d", num);    
  gtk_label_set_text (GTK_LABEL(adj), display); 
  g_free(display);
}

void updateImage(GtkWidget *image, Image *img) {
  GdkPixbuf *pixbuf = convert_image_to_pixbuf(img);
  gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
}

void addAdjustment(GtkWidget *button, CallbackData *data) {
  int num = atoi(gtk_label_get_text(GTK_LABEL(data->adj)));
  num += 1;
  updateAdjustment(GTK_LABEL(data->adj), num);

  if (strcmp(data->command, "Brightness") == 0) {
    adjust_brightness(data->img, 5);
  }
  else if (strcmp(data->command, "Shadow") == 0) {
    adjust_shadow(data->img, 1.05);
  }
  else if (strcmp(data->command, "Temperature") == 0) {
    adjust_temperature(data->img, 5);
  }
  else if (strcmp(data->command, "Tint") == 0) {
    adjust_tint(data->img, 5);
  }
  else if (strcmp(data->command, "Noise") == 0) {
    add_noise(data->img, 0.1);
  }

  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void minusAdjustment(GtkWidget *button, CallbackData *data) {
  int num = atoi(gtk_label_get_text(GTK_LABEL(data->adj)));
  num -= 1;
  updateAdjustment(GTK_LABEL(data->adj), num);

  if (strcmp(data->command, "Brightness") == 0) {
    adjust_brightness(data->img, -5);
  }
  else if (strcmp(data->command, "Shadow") == 0) {
    adjust_shadow(data->img, 0.95);
  }
  else if (strcmp(data->command, "Temperature") == 0) {
    adjust_temperature(data->img, -5);
  }
  else if (strcmp(data->command, "Tint") == 0) {
    adjust_tint(data->img, -5);
  }

  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void redNegate(GtkWidget *button, CallbackData *data) {
  adjust_negate(data->img, 0);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void greenNegate(GtkWidget *button, CallbackData *data) {
  adjust_negate(data->img, 1);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void blueNegate(GtkWidget *button, CallbackData *data) {
  adjust_negate(data->img, 2);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void redFlatten(GtkWidget *button, CallbackData *data) {
  flatten(data->img, 0);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void greenFlatten(GtkWidget *button, CallbackData *data) {
  flatten(data->img, 1);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void blueFlatten(GtkWidget *button, CallbackData *data) {
  flatten(data->img, 2);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void applyHighContrast(GtkWidget *button, CallbackData *data) {
  high_contrast(data->img, 128);
  add_state(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void undo_button_clicked(GtkButton *button, UndoData *data) {
  if (states[0].pixels == NULL) {
    printf("No more undo\n");
    return;
  }
  undo(data->img);
  updateImage(GTK_WIDGET(data->image), data->img);
}

void reset_button_clicked(GtkButton *button, ResetData *data) {
  for (int i = 0; i < data->original_img->height; i++) {
    for (int j = 0; j < data->original_img->width; j++) {
      data->edited_img->pixels[i][j][0] = data->original_img->pixels[i][j][0];
      data->edited_img->pixels[i][j][1] = data->original_img->pixels[i][j][1];
      data->edited_img->pixels[i][j][2] = data->original_img->pixels[i][j][2];
    }
  }
  updateImage(GTK_WIDGET(data->image), data->edited_img);
  for (int i = 0; i < 5; i++) {
    states[i].pixels = NULL;
  }
}

void save_button_clicked(GtkButton *button, Image *img) {
  save_ppm("output.ppm", img);
  printf("Image saved\n");
  gtk_main_quit();
}


int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  // Check for command line arguments (image filename)
  if (argc != 2) {
    printf("Usage: %s <image.ppm>\n", argv[0]);
    return 1;
  }

  // Load PPM image
  Image *img = load_ppm(argv[1]);
  if (!img) {
    printf("Error loading image\n");
    return 1;
  }

  // copy the image to original_image for reset
  Image *original_img = load_ppm(argv[1]);
  if (!original_img) {
    printf("Error loading image\n");
    return 1;
  }

  // Convert image to GdkPixbuf
  GdkPixbuf *pixbuf = convert_image_to_pixbuf(img);
  if (!pixbuf) {
    printf("Error converting image to pixbuf\n");
    return 1;
  }

  // Window and image widget
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "LiteRoom Image Editor");
  GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);

  // Labels
  GtkWidget *label_brightness = gtk_label_new("Brightness");
  GtkWidget *brightness_value = gtk_label_new("0");
  GtkWidget *label_shadow = gtk_label_new("Shadow");
  GtkWidget *shadow_value = gtk_label_new("0");
  GtkWidget *label_temp = gtk_label_new("Temperature");
  GtkWidget *temp_value = gtk_label_new("0");
  GtkWidget *label_tint = gtk_label_new("Tint");
  GtkWidget *tint_value = gtk_label_new("0");
  GtkWidget *label_noise = gtk_label_new("Noise");
  GtkWidget *noise_value = gtk_label_new("0");
  GtkWidget *label_negate = gtk_label_new("Negate");
  GtkWidget *label_flatten = gtk_label_new("Flatten");
  GtkWidget *label_high_contrast = gtk_label_new("High Contrast");

  UndoData *undo_data = malloc(sizeof(UndoData));
  undo_data->image = image;
  undo_data->img = img;
  
  ResetData *reset_data = malloc(sizeof(ResetData));
  reset_data->image = image;
  reset_data->original_img = original_img;
  reset_data->edited_img = img;

  CallbackData *brightness_data = malloc(sizeof(CallbackData));
  brightness_data->command = "Brightness";
  brightness_data->adj = brightness_value;
  brightness_data->image = image;
  brightness_data->img = img;

  CallbackData *shadow_data = malloc(sizeof(CallbackData));
  shadow_data->command = "Shadow";
  shadow_data->adj = shadow_value;
  shadow_data->image = image;
  shadow_data->img = img;

  CallbackData *temp_data = malloc(sizeof(CallbackData));
  temp_data->command = "Temperature";
  temp_data->adj = temp_value;
  temp_data->image = image;
  temp_data->img = img;

  CallbackData *tint_data = malloc(sizeof(CallbackData));
  tint_data->command = "Tint";
  tint_data->adj = tint_value;
  tint_data->image = image;
  tint_data->img = img;

  CallbackData *noise_data = malloc(sizeof(CallbackData));
  noise_data->command = "Noise";
  noise_data->adj = noise_value;
  noise_data->image = image;
  noise_data->img = img;

  CallbackData *negate_data = malloc(sizeof(CallbackData));
  negate_data->command = "Negate";
  negate_data->adj = label_negate;
  negate_data->image = image;
  negate_data->img = img;

  CallbackData *flatten_data = malloc(sizeof(CallbackData));
  flatten_data->command = "Flatten";
  flatten_data->adj = label_flatten;
  flatten_data->image = image;
  flatten_data->img = img;

  CallbackData *high_contrast_data = malloc(sizeof(CallbackData));
  high_contrast_data->command = "High Contrast";
  high_contrast_data->adj = label_high_contrast;
  high_contrast_data->image = image;
  high_contrast_data->img = img;

  // Undo button
  GtkWidget *undo_button = gtk_button_new_with_label("Undo");
  g_signal_connect(undo_button, "clicked", G_CALLBACK(undo_button_clicked), undo_data);

  // Reset button
  GtkWidget *reset_button = gtk_button_new_with_label("Reset");
  g_signal_connect(reset_button, "clicked", G_CALLBACK(reset_button_clicked), reset_data);

  // Save button
  GtkWidget *save_button = gtk_button_new_with_label("Save");
  g_signal_connect(save_button, "clicked", G_CALLBACK(save_button_clicked), img);

  // Button for brightness increase
  GtkWidget *button_increase_brightness = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_brightness, "clicked", G_CALLBACK(addAdjustment), brightness_data); // Pass image widget to the function

  // Button for brightness decrese
  GtkWidget *button_decrease_brightness = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_brightness, "clicked", G_CALLBACK(minusAdjustment), brightness_data); // Pass image widget to the function

  // Button for shadow increase
  GtkWidget *button_increase_shadow = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_shadow, "clicked", G_CALLBACK(addAdjustment), shadow_data); // Pass image widget to the function

  // Button for shadow decrease
  GtkWidget *button_decrease_shadow = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_shadow, "clicked", G_CALLBACK(minusAdjustment), shadow_data); // Pass image widget to the function

  // Button for temp increase
  GtkWidget *button_increase_temp = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_temp, "clicked", G_CALLBACK(addAdjustment), temp_data); // Pass image widget to the function

  // Button for temp decrease
  GtkWidget *button_decrease_temp = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_temp, "clicked", G_CALLBACK(minusAdjustment), temp_data); // Pass image widget to the function

  // Button for tint increase
  GtkWidget *button_increase_tint = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_tint, "clicked", G_CALLBACK(addAdjustment), tint_data); // Pass image widget to the function

  // Button for tint decrease
  GtkWidget *button_decrease_tint = gtk_button_new_with_label("-");
  g_signal_connect(button_decrease_tint, "clicked", G_CALLBACK(minusAdjustment), tint_data); // Pass image widget to the function

  // Button for noise increase
  GtkWidget *button_increase_noise = gtk_button_new_with_label("+");
  g_signal_connect(button_increase_noise, "clicked", G_CALLBACK(addAdjustment), noise_data); // Pass image widget to the function

  // Button for negate red, green, blue
  GtkWidget *button_negate_red = gtk_button_new_with_label("Red");
  GtkWidget *button_negate_green = gtk_button_new_with_label("Green");
  GtkWidget *button_negate_blue = gtk_button_new_with_label("Blue");
  g_signal_connect(button_negate_red, "clicked", G_CALLBACK(redNegate), negate_data); // Pass image widget to the function
  g_signal_connect(button_negate_green, "clicked", G_CALLBACK(greenNegate), negate_data); // Pass image widget to the function
  g_signal_connect(button_negate_blue, "clicked", G_CALLBACK(blueNegate), negate_data); // Pass image widget to the function
  GtkWidget *button_flatten_red = gtk_button_new_with_label("Red");
  GtkWidget *button_flatten_green = gtk_button_new_with_label("Green");
  GtkWidget *button_flatten_blue = gtk_button_new_with_label("Blue");
  g_signal_connect(button_flatten_red, "clicked", G_CALLBACK(redFlatten), flatten_data); // Pass image widget to the function
  g_signal_connect(button_flatten_green, "clicked", G_CALLBACK(greenFlatten), flatten_data); // Pass image widget to the function
  g_signal_connect(button_flatten_blue, "clicked", G_CALLBACK(blueFlatten), flatten_data); // Pass image widget to the function
  GtkWidget *button_high_contrast = gtk_button_new_with_label("Apply");
  g_signal_connect(button_high_contrast, "clicked", G_CALLBACK(applyHighContrast), high_contrast_data); // Pass image widget to the function

  // Layout
  GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_pack_start(GTK_BOX(hbox), image, TRUE, TRUE, 0);

  GtkWidget *editingbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 11);

  GtkWidget *brightnessbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(brightnessbox), button_decrease_brightness, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(brightnessbox), label_brightness, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(brightnessbox), brightness_value, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(brightnessbox), button_increase_brightness, TRUE, TRUE, 0);

  GtkWidget *shadowbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(shadowbox), button_decrease_shadow, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(shadowbox), label_shadow, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(shadowbox), shadow_value, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(shadowbox), button_increase_shadow, TRUE, TRUE, 0);

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

  GtkWidget *noisebox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(noisebox), label_noise, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(noisebox), noise_value, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(noisebox), button_increase_noise, TRUE, TRUE, 0);

  GtkWidget *negatebox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(negatebox), label_negate, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(negatebox), button_negate_red, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(negatebox), button_negate_green, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(negatebox), button_negate_blue, TRUE, TRUE, 0);

  GtkWidget *flattenbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_box_pack_start(GTK_BOX(flattenbox), label_flatten, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(flattenbox), button_flatten_red, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(flattenbox), button_flatten_green, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(flattenbox), button_flatten_blue, TRUE, TRUE, 0);

  GtkWidget *high_contrast_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
  gtk_box_pack_start(GTK_BOX(high_contrast_box), label_high_contrast, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(high_contrast_box), button_high_contrast, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(editingbox), brightnessbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), shadowbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), tempbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), tintbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), noisebox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), negatebox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), flattenbox, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), high_contrast_box, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), undo_button, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), reset_button, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(editingbox), save_button, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(hbox), editingbox, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(window), hbox);

  // Signals and show all
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);

  gtk_main();
  printf("Image editor closed\n");

  return 0;
}

