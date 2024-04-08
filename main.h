#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "image.h"

#define MAX_HISTORY 10

typedef enum { INITIAL, WAITING_FOR_FILE, EDITING, EXPORTING } ProgramState;

typedef struct {
  char *command;
  void (*func)(Image *, float);
} Command;

typedef struct{
  int cmd_index;
  float value;
}Preset;

Command *initCommand(char *command, int size, void (*func)(Image *, int));
