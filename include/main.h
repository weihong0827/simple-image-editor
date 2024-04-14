#include <dirent.h>
#include <gtk/gtk.h>

#include "image.h"
#include "preset.h"

#define MAX_HISTORY 10

typedef enum { INITIAL, WAITING_FOR_FILE, EDITING, EXPORTING } ProgramState;

typedef struct {
    char *command;
    GtkWidget *adj;
    GtkWidget *image;
    Image *img;
} CallbackData;

typedef struct {
    GtkWidget *image;
    Image *img;
} UndoData;

typedef struct {
    GtkWidget *image;
    Image *original_img;
    Image *edited_img;
    GtkWidget *brightness_adj;
    GtkWidget *shadow_adj;
    GtkWidget *temperature_adj;
    GtkWidget *tint_adj;
    GtkWidget *noise_adj;
} ResetData;

GdkPixbuf *convert_image_to_pixbuf(Image *img);
void add_state(Image *img);
void undo(Image *img);
void updateImage(GtkWidget *image, Image *img);
void updateAdjustment(GtkLabel *adj, int num);
void addAdjustment(GtkWidget *button, CallbackData *data);
void minusAdjustment(GtkWidget *button, CallbackData *data);
void redNegate(GtkWidget *button, CallbackData *data);
void greenNegate(GtkWidget *button, CallbackData *data);
void blueNegate(GtkWidget *button, CallbackData *data);
void redFlatten(GtkWidget *button, CallbackData *data);
void greenFlatten(GtkWidget *button, CallbackData *data);
void blueFlatten(GtkWidget *button, CallbackData *data);
void applyHighContrast(GtkWidget *button, CallbackData *data);
void applyGrayscale(GtkWidget *button, CallbackData *data);
void undo_button_clicked(GtkButton *button, UndoData *data);
void reset_button_clicked(GtkButton *button, ResetData *data);
void save_button_clicked(GtkButton *button, Image *img);
