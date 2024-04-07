#include "adjustment_func.h"
#include <stdio.h>
#include <stdlib.h>

AdjustmentParms *initParam(enum AdjustmentType type, float adjustment_value,
                           int min_brightness, int max_brightness) {

  AdjustmentParms *params = (AdjustmentParms *)malloc(sizeof(AdjustmentParms));
  params->type = type;
  params->adjustment_value = adjustment_value;
  params->min_brightness = min_brightness;
  params->max_brightness = max_brightness;
  return params;
}

int shadow_func(AdjustmentParms *params) {
  int result;
  if (params->type != SHADOW) {
    printf("Error: shadow function called with wrong parameters\n");
    return -1;
  }
  if (params->adjustment_value > 1) {

    result = params->pixel_value +
             (params->adjustment_value - 1) * (255 - params->pixel_value);
    printf("Shadow: %d\n", result);

  } else {
    result = params->pixel_value * params->adjustment_value;
  }
  return result;
}

int brightness_func(AdjustmentParms *params) {
  int result;
  if (params->type != BRIGHTNESS) {
    printf("Error: brightness function called with wrong parameters\n");
    return -1;
  }
  result = params->pixel_value + params->adjustment_value;

  return result;
}
int grey_scale_func(AdjustmentParms *params) {
  int result;
  if (params->type != GREY_SCALE) {
    printf("Error: greyscale function called with wrong parameters\n");
    return -1;
  }
  float r_weight = 0.21, g_weight = 0.72, b_weight = 0.07;
  int greyscale_value =
      params->pixel_value *
      (params->pixel_index == 0
           ? r_weight
           : (params->pixel_index == 1 ? g_weight : b_weight));
  return greyscale_value;
  return result;
}
int negate_func(AdjustmentParms *params) {
  int result;
  if (params->type != NEGATE) {
    printf("Error: negate function called with wrong parameters\n");
    return -1;
  }
  if (params->adjustment_value != params->pixel_index) {
    return params->pixel_value;
  }
  result = 255 - params->pixel_value;
  return result;
}
int flatten_func(AdjustmentParms *params) {
  int result;
  if (params->type != FLATTEN) {
    printf("Error: flatten function called with wrong parameters\n");
    return -1;
  }
  return 0;
}
int high_contrast_adjustment(AdjustmentParms *parms) {
  if (parms->type != HIGH_CONTRAST) {
    printf("Error: high contrast function called with wrong parameters\n");
    return -1;
  }
  return parms->pixel_value > 128 ? 255 : 0;
}

int noise_adjustment(AdjustmentParms *parms) {
  if (parms->type != NOISE) {
    printf("Error: noise function called with wrong parameters\n");
    return -1;
  }
  float noise_level =
      parms->adjustment_value; // Use adjustment_value to control noise level
  float noise = ((rand() % 100) / 100.0f * 2 * noise_level) - noise_level;
  int new_value = parms->pixel_value + noise * parms->pixel_value;
  return new_value;
}
