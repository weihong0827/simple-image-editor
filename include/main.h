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
} ResetData;

GdkPixbuf *convert_image_to_pixbuf(Image *img);
void updateAdjustment(GtkLabel *adj, int num);
void addAdjustment(GtkWidget *button, CallbackData *data);
void minusAdjustment(GtkWidget *button, CallbackData *data);