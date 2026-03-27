#include "cairoffi.h"

__attribute__((constructor)) void loadcairo(K);
void loadcairo(K k) {
  kinit();
  KR("kairo.version",     (void*)Fcairo_version,     1);
  KR("kairo.versionString",     (void*)Fcairo_version_string,     1);
  KR("kairo.formatStrideForWidth", (void*)Fcairo_format_stride_for_width, 2);
  KR("kairo.imageSurfaceCreateForData", (void*)Fcairo_image_surface_create_for_data, 1);
  KR("kairo.imageSurfaceCreate", (void*)Fcairo_image_surface_create,1);
  KR("kairo.surfaceDestroy",     (void*)Fcairo_surface_destroy,     1);
  KR("kairo.create",     (void*)Fcairo_create,     1);
  KR("kairo.destroy",     (void*)Fcairo_destroy,     1);
}
