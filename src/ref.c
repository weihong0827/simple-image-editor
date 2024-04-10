#include <stdio.h>

#include "ppm.h"
#include "sdl_engine.h"

SDLEngine engine;

int preview(char* title) {
  // if (argc != 2) {
  //   printf("Usage: <ppm-viewer> <image.extension>\n");
  //   return -1;
  // }

  // int is_file_valid = read_ppm_file(argv[1]);



  int init_succeeded = initialize_engine(&engine, title);

  if (init_succeeded) {
    run(&engine);
  }

  terminate_engine(&engine);

  return 0;
}