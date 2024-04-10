#ifndef PRESET_H
#define PRESET_H
#include "image.h"

#define NUM_COMMANDS 8

typedef struct
{
  char *command;
  void (*func)(Image *, float);
} Command;

typedef struct
{
  int cmd_index;
  float value;
} Preset;

extern Command commands[NUM_COMMANDS];

Preset *init_preset(float value, int cmd_index);
void delete_preset(Preset **preset, int f);
int find_command(const char *name);
Preset **enter_edits(void);
#endif
