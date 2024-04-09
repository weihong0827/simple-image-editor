#include <dirent.h>

#define MAX_HISTORY 10

typedef enum { INITIAL, WAITING_FOR_FILE, EDITING, EXPORTING } ProgramState;
