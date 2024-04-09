enum AdjustmentType {
  BRIGHTNESS,
  SHADOW,
  GREY_SCALE,
  NEGATE,
  FLATTEN,
  HIGH_CONTRAST,
  BLACK_AND_WHITE,
  NOISE
};
typedef struct {
  enum AdjustmentType type;
  float adjustment_value;
  int pixel_value;
  int min_brightness;
  int max_brightness;
  int pixel_index;
} AdjustmentParms;

AdjustmentParms *initParam(enum AdjustmentType type, float adjustment_value,
                           int min_brightness, int max_brightness);
int shadow_func(AdjustmentParms *params);
int brightness_func(AdjustmentParms *params);
int grey_scale_func(AdjustmentParms *params);
int negate_func(AdjustmentParms *params);
int flatten_func(AdjustmentParms *params);
int high_contrast_adjustment(AdjustmentParms *params);
int black_and_white_func(AdjustmentParms *params);
int noise_adjustment(AdjustmentParms *params);
