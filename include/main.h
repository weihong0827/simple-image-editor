#include "image.h"
#include <dirent.h>
#define MAX_HISTORY 10

typedef enum {
  LOAD_IMAGES,
  ENTER_COMMAND,
  EDITING,
  EXPORTING,
  EXIT
} ProgramState;
Image **access_files(char *dir_path, int *all);
