#include <dirent.h>
#include "image.h"
#define MAX_HISTORY 10

typedef enum { LOAD_IMAGES, EDITING, EXPORTING, EXIT} ProgramState;
Image **access_files(char *dir_path, int * all);
