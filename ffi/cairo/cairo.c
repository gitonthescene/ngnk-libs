#include "cairoffi.h"

__attribute__((constructor)) void loadcairo(K);
void loadcairo(K k) {
  kinit();
  KR("kairo.arc", (void*)Fcairo_arc, 1);
  KR("kairo.clip", (void*)Fcairo_clip, 1);
  KR("kairo.closePath", (void*)Fcairo_close_path, 1);
  KR("kairo.create", (void*)Fcairo_create, 1);
  KR("kairo.destroy", (void*)Fcairo_destroy, 1);
  KR("kairo.fill", (void*)Fcairo_fill, 1);
  KR("kairo.formatStrideForWidth", (void*)Fcairo_format_stride_for_width, 2);
  KR("kairo.imageSurfaceCreate", (void*)Fcairo_image_surface_create, 1);
  KR("kairo.imageSurfaceCreateForData", (void*)Fcairo_image_surface_create_for_data, 1);
  KR("kairo.imageSurfaceGetData", (void*)Fcairo_image_surface_get_data, 1);
  KR("kairo.lineTo", (void*)Fcairo_line_to, 1);
  KR("kairo.moveTo", (void*)Fcairo_move_to, 1);
  KR("kairo.newPath", (void*)Fcairo_new_path, 1);
  KR("kairo.rectangle", (void*)Fcairo_rectangle, 1);
  KR("kairo.resetClip", (void*)Fcairo_reset_clip, 1);
  KR("kairo.restore", (void*)Fcairo_restore, 1);
  KR("kairo.rotate", (void*)Fcairo_rotate, 1);
  KR("kairo.save", (void*)Fcairo_save, 1);
  KR("kairo.selectFontFace", (void*)Fcairo_select_font_face, 1);
  KR("kairo.setFontSize", (void*)Fcairo_set_font_size, 1);
  KR("kairo.setLineWidth", (void*)Fcairo_set_line_width, 1);
  KR("kairo.setSourceRGB", (void*)Fcairo_set_source_rgb, 1);
  KR("kairo.showText", (void*)Fcairo_show_text, 1);
  KR("kairo.status", (void*)Fcairo_status, 1);
  KR("kairo.stroke", (void*)Fcairo_stroke, 1);
  KR("kairo.surfaceDestroy", (void*)Fcairo_surface_destroy, 1);
  KR("kairo.surfaceFlush", (void*)Fcairo_surface_flush, 1);
  KR("kairo.surfaceStatus", Fcairo_surface_status, 1);
  KR("kairo.surfaceWriteToPngStream", (void*)Fcairo_surface_write_to_png_stream, 1);
  KR("kairo.textExtents", (void*)Fcairo_text_extents, 1);
  KR("kairo.version", (void*)Fcairo_version, 1);
  KR("kairo.versionString", (void*)Fcairo_version_string, 1);
}
