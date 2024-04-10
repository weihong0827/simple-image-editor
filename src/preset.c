#include "preset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Command commands[] = {
    {"brightness", adjust_brightness},
    {"shadow", adjust_shadow},
    {"high_contrast", high_contrast},
    {"noise", add_noise},
    {"flatten", flatten},
    {"negate", adjust_negate},
    {"temperature", adjust_temperature},
    {"tint", adjust_tint},
};

Preset *init_preset(float value, int cmd_index)
{
  Preset *preset = (Preset *)malloc(sizeof(Preset));
  preset->value = value;
  preset->cmd_index = cmd_index;
  return preset;
}

void delete_preset(Preset **preset, int f)
{
  int i;
  for (i = 0; i < f; i++)
  {
    free(preset[i]);
  }
  free(preset);
}

int find_command(const char *name)
{
  int i;
  int num_commands = sizeof(commands) / sizeof(commands[0]);
  for (i = 0; i < num_commands; i++)
  {
    if (strcmp(commands[i].command, name) == 0)
    {
      return i;
    }
  }
  return -1;
}
void parseCSV(Preset ***presets, char *path, int *count)
{
  FILE *file = fopen(path, "r");
  char line[1024];
  int cmd_index;
  float value;
  char *token;
  char *command;
  while (fgets(line, 1024, file))
  {
    (*count)++;
    *presets = (Preset **)realloc(*presets, sizeof(Preset *) * (*count + 1));
    token = strtok(line, ",");
    command = token;
    token = strtok(NULL, ",");
    value = atof(token);
    cmd_index = find_command(command);
    if (cmd_index >= 0)
    {
      *presets[*count - 1] = init_preset(value, cmd_index);
    }
    else
    {
      printf("Unknown command.\n");
      continue;
    }
  }
}

Preset **enter_edits(void)
{
  char command[100];
  float value;
  int count = 0;
  Preset **presets = (Preset **)malloc(sizeof(Preset *));
  int cmd_index;

  while (1)
  {
    printf("Enter edit command (e.g., 'brightness') or 'done' to end edit: ");
    scanf("%s", command);
    if (strcmp(command, "done") == 0)
    {
      presets[count] = NULL;
      printf("Done entering edits.\n");
      return presets;
    }
    if (strcmp(command, "csv") == 0)
    {
      printf("Enter path to CSV file: ");
      scanf("%s", command);
      parseCSV(&presets, command, &count);
    }
    printf("%s\n", command);
    cmd_index = find_command(command);
    if (cmd_index >= 0)
    {
      count++;
      printf("Enter value (e.g., +10): ");
      scanf("%f", &value);
      presets = (Preset **)realloc(presets, sizeof(Preset *) * (count + 1));
      presets[count - 1] = init_preset(value, cmd_index);
    }
    else
    {
      printf("Unknown command.\n");
      continue;
    }
  }
}
