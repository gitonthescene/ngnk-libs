#include "cairoffi.h"

K des_(C* x, I n);
K Fcairo_version(K x) {
 int r = cairo_version();
 unref(x);
 return Ki(r);
 }

K Fcairo_version_string(K x) {
 char const * r = cairo_version_string();
 unref(x);
 return KC((char*)r,SL(r));
 }

K Fcairo_create(K x) {
 L r[2]; r[1] = KFFI_CAIRO_T;
 ((cairo_t**)r)[0] = cairo_create((cairo_surface_t*)((L*)x)[0]);
 unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_reference_sig* in = chk_cairo_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_T;
 ((cairo_t**)r)[0] = cairo_reference((cairo_t*)in->cr.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_destroy(K x) {
 cairo_destroy((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_get_reference_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_reference_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_reference_count_sig* in = chk_cairo_get_reference_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int r = cairo_get_reference_count((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_user_data_sig* in = chk_cairo_get_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 void* r = cairo_get_user_data((cairo_t*)((L*)in->cr.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_set_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_user_data_sig* in = chk_cairo_set_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_set_user_data((cairo_t*)((L*)in->cr.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0], &user_data, f1);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_save(K x) {
 cairo_save((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_restore(K x) {
 cairo_restore((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_push_group(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_push_group_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_push_group_sig* in = chk_cairo_push_group_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_push_group((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_push_group_with_content(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_push_group_with_content_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_push_group_with_content_sig* in = chk_cairo_push_group_with_content_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_push_group_with_content((cairo_t*)((L*)in->cr.arr)[0], (cairo_content_t)in->content);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pop_group(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pop_group_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pop_group_sig* in = chk_cairo_pop_group_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1]=KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pop_group((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pop_group_to_source(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pop_group_to_source_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pop_group_to_source_sig* in = chk_cairo_pop_group_to_source_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pop_group_to_source((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_operator(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_operator_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_operator_sig* in = chk_cairo_set_operator_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_operator((cairo_t*)((L*)in->cr.arr)[0], (cairo_operator_t)in->op);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_source(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_source_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_source_sig* in = chk_cairo_set_source_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_source((cairo_t*)((L*)in->cr.arr)[0], (cairo_pattern_t*)((L*)in->source.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_source_rgb(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_source_rgb_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_source_rgb_sig* in = chk_cairo_set_source_rgb_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_source_rgb((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_source_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_source_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_source_rgba_sig* in = chk_cairo_set_source_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_source_rgba((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr, *(double*)in->alpha.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_source_surface(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_source_surface_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_source_surface_sig* in = chk_cairo_set_source_surface_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_source_surface((cairo_t*)((L*)in->cr.arr)[0], (cairo_surface_t*)((L*)in->surface.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_tolerance(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_tolerance_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_tolerance_sig* in = chk_cairo_set_tolerance_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_tolerance((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->tolerance.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_antialias(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_antialias_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_antialias_sig* in = chk_cairo_set_antialias_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_antialias((cairo_t*)((L*)in->cr.arr)[0], (cairo_antialias_t)in->antialias);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_fill_rule(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_fill_rule_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_fill_rule_sig* in = chk_cairo_set_fill_rule_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_fill_rule((cairo_t*)((L*)in->cr.arr)[0], (cairo_fill_rule_t)in->fill_rule);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_line_width(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_line_width_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_line_width_sig* in = chk_cairo_set_line_width_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_line_width((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->width.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_hairline(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_hairline_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_hairline_sig* in = chk_cairo_set_hairline_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_hairline((cairo_t*)((L*)in->cr.arr)[0], (cairo_bool_t)in->set_hairline);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_line_cap(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_line_cap_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_line_cap_sig* in = chk_cairo_set_line_cap_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_line_cap((cairo_t*)((L*)in->cr.arr)[0], (cairo_line_cap_t)in->line_cap);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_line_join(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_line_join_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_line_join_sig* in = chk_cairo_set_line_join_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_line_join((cairo_t*)((L*)in->cr.arr)[0], (cairo_line_join_t)in->line_join);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_dash(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_dash_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_dash_sig* in = chk_cairo_set_dash_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_dash((cairo_t*)((L*)in->cr.arr)[0], (double*)in->dashes.arr, (int)in->num_dashes, *(double*)in->offset.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_miter_limit(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_miter_limit_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_miter_limit_sig* in = chk_cairo_set_miter_limit_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_miter_limit((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->limit.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_translate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_translate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_translate_sig* in = chk_cairo_translate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_translate((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->tx.arr, *(double*)in->ty.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scale(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scale_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scale_sig* in = chk_cairo_scale_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scale((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->sx.arr, *(double*)in->sy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_rotate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_rotate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_rotate_sig* in = chk_cairo_rotate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_rotate((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->angle.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_transform(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_transform_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_transform_sig* in = chk_cairo_transform_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_transform((cairo_t*)((L*)in->cr.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_matrix_sig* in = chk_cairo_set_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_matrix((cairo_t*)((L*)in->cr.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_identity_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_identity_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_identity_matrix_sig* in = chk_cairo_identity_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_identity_matrix((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_to_device(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_to_device_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_to_device_sig* in = chk_cairo_user_to_device_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_to_device((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x.arr, (double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_to_device_distance(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_to_device_distance_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_to_device_distance_sig* in = chk_cairo_user_to_device_distance_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_to_device_distance((cairo_t*)((L*)in->cr.arr)[0], (double*)in->dx.arr, (double*)in->dy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_device_to_user(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_to_user_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_to_user_sig* in = chk_cairo_device_to_user_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_to_user((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x.arr, (double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_device_to_user_distance(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_to_user_distance_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_to_user_distance_sig* in = chk_cairo_device_to_user_distance_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_to_user_distance((cairo_t*)((L*)in->cr.arr)[0], (double*)in->dx.arr, (double*)in->dy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_new_path(K x) {
 cairo_new_path((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_move_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_move_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_move_to_sig* in = chk_cairo_move_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_move_to((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_new_sub_path(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_new_sub_path_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_new_sub_path_sig* in = chk_cairo_new_sub_path_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_new_sub_path((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_line_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_line_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_line_to_sig* in = chk_cairo_line_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_line_to((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_curve_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_curve_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_curve_to_sig* in = chk_cairo_curve_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_curve_to((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x1.arr, *(double*)in->y1.arr, *(double*)in->x2.arr, *(double*)in->y2.arr, *(double*)in->x3.arr, *(double*)in->y3.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_arc(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_arc_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_arc_sig* in = chk_cairo_arc_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_arc((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->xc.arr, *(double*)in->yc.arr, *(double*)in->radius.arr, *(double*)in->angle1.arr, *(double*)in->angle2.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_arc_negative(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_arc_negative_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_arc_negative_sig* in = chk_cairo_arc_negative_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_arc_negative((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->xc.arr, *(double*)in->yc.arr, *(double*)in->radius.arr, *(double*)in->angle1.arr, *(double*)in->angle2.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_rel_move_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_rel_move_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_rel_move_to_sig* in = chk_cairo_rel_move_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_rel_move_to((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->dx.arr, *(double*)in->dy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_rel_line_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_rel_line_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_rel_line_to_sig* in = chk_cairo_rel_line_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_rel_line_to((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->dx.arr, *(double*)in->dy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_rel_curve_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_rel_curve_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_rel_curve_to_sig* in = chk_cairo_rel_curve_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_rel_curve_to((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->dx1.arr, *(double*)in->dy1.arr, *(double*)in->dx2.arr, *(double*)in->dy2.arr, *(double*)in->dx3.arr, *(double*)in->dy3.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_rectangle_sig* in = chk_cairo_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_rectangle((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr, *(double*)in->width.arr, *(double*)in->height.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_close_path(K x) {
 cairo_close_path((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_path_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_path_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_path_extents_sig* in = chk_cairo_path_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_path_extents((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x1.arr, (double*)in->y1.arr, (double*)in->x2.arr, (double*)in->y2.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_paint(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_paint_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_paint_sig* in = chk_cairo_paint_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_paint((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_paint_with_alpha(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_paint_with_alpha_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_paint_with_alpha_sig* in = chk_cairo_paint_with_alpha_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_paint_with_alpha((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->alpha.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mask(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mask_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mask_sig* in = chk_cairo_mask_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mask((cairo_t*)((L*)in->cr.arr)[0], (cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mask_surface(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mask_surface_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mask_surface_sig* in = chk_cairo_mask_surface_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mask_surface((cairo_t*)((L*)in->cr.arr)[0], (cairo_surface_t*)((L*)in->surface.arr)[0], *(double*)in->surface_x.arr, *(double*)in->surface_y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_stroke(K x) {
 cairo_stroke((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_stroke_preserve(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_stroke_preserve_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_stroke_preserve_sig* in = chk_cairo_stroke_preserve_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_stroke_preserve((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_fill(K x) {
 cairo_fill((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_fill_preserve(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_fill_preserve_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_fill_preserve_sig* in = chk_cairo_fill_preserve_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_fill_preserve((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_copy_page(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_copy_page_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_copy_page_sig* in = chk_cairo_copy_page_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_copy_page((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_show_page(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_show_page_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_show_page_sig* in = chk_cairo_show_page_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_show_page((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_in_stroke(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_in_stroke_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_in_stroke_sig* in = chk_cairo_in_stroke_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_in_stroke((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_in_fill(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_in_fill_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_in_fill_sig* in = chk_cairo_in_fill_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_in_fill((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_in_clip(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_in_clip_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_in_clip_sig* in = chk_cairo_in_clip_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_in_clip((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_stroke_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_stroke_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_stroke_extents_sig* in = chk_cairo_stroke_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_stroke_extents((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x1.arr, (double*)in->y1.arr, (double*)in->x2.arr, (double*)in->y2.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_fill_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_fill_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_fill_extents_sig* in = chk_cairo_fill_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_fill_extents((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x1.arr, (double*)in->y1.arr, (double*)in->x2.arr, (double*)in->y2.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_reset_clip(K x) {
 cairo_reset_clip((cairo_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_clip(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_clip_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_clip_sig* in = chk_cairo_clip_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_clip((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_clip_preserve(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_clip_preserve_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_clip_preserve_sig* in = chk_cairo_clip_preserve_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_clip_preserve((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_clip_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_clip_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_clip_extents_sig* in = chk_cairo_clip_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_clip_extents((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x1.arr, (double*)in->y1.arr, (double*)in->x2.arr, (double*)in->y2.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_copy_clip_rectangle_list(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_copy_clip_rectangle_list_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_copy_clip_rectangle_list_sig* in = chk_cairo_copy_clip_rectangle_list_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_RECTANGLE_LIST_T;
 ((cairo_rectangle_list_t**)r)[0] = cairo_copy_clip_rectangle_list((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_rectangle_list_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_rectangle_list_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_rectangle_list_destroy_sig* in = chk_cairo_rectangle_list_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_rectangle_list_destroy((cairo_rectangle_list_t*)((L*)in->rectangle_list.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_tag_begin(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_tag_begin_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_tag_begin_sig* in = chk_cairo_tag_begin_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_tag_begin((cairo_t*)((L*)in->cr.arr)[0], (char*)in->tag_name.arr, (char*)in->attributes.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_tag_end(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_tag_end_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_tag_end_sig* in = chk_cairo_tag_end_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_tag_end((cairo_t*)in->cr.arr, (char*)in->tag_name.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_glyph_allocate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_glyph_allocate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_glyph_allocate_sig* in = chk_cairo_glyph_allocate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_GLYPH_T;
 ((cairo_glyph_t**)r)[0] = cairo_glyph_allocate((int)in->num_glyphs);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_glyph_free(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_glyph_free_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_glyph_free_sig* in = chk_cairo_glyph_free_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_glyph_free((cairo_glyph_t*)((L*)in->glyphs.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_text_cluster_allocate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_text_cluster_allocate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_text_cluster_allocate_sig* in = chk_cairo_text_cluster_allocate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_TEXT_CLUSTER_T;
 ((cairo_text_cluster_t**)r)[0] = cairo_text_cluster_allocate((int)in->num_clusters);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_text_cluster_free(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_text_cluster_free_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_text_cluster_free_sig* in = chk_cairo_text_cluster_free_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_text_cluster_free((cairo_text_cluster_t*)((L*)in->clusters.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_create(K x) {
 L r[2]; r[1] = KFFI_CAIRO_FONT_OPTIONS_T;
 ((cairo_font_options_t**)r)[0] = cairo_font_options_create();
 unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_font_options_copy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_copy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_copy_sig* in = chk_cairo_font_options_copy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_FONT_OPTIONS_T;
 ((cairo_font_options_t**)r)[0] = cairo_font_options_copy((cairo_font_options_t*)((L*)in->original.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_font_options_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_destroy_sig* in = chk_cairo_font_options_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_destroy((cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_status(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_status_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_status_sig* in = chk_cairo_font_options_status_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_font_options_status((cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_options_merge(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_merge_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_merge_sig* in = chk_cairo_font_options_merge_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_merge((cairo_font_options_t*)((L*)in->options.arr)[0], (cairo_font_options_t*)((L*)in->other.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_equal(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_equal_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_equal_sig* in = chk_cairo_font_options_equal_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_font_options_equal((cairo_font_options_t*)((L*)in->options.arr)[0], (cairo_font_options_t*)((L*)in->other.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_options_hash(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_hash_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_hash_sig* in = chk_cairo_font_options_hash_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 long unsigned int r = cairo_font_options_hash((cairo_font_options_t*)in->options.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=&r};
 return des_(ret,SZ(ret));
 }

K Fcairo_font_options_set_antialias(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_set_antialias_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_antialias_sig* in = chk_cairo_font_options_set_antialias_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_antialias((cairo_font_options_t*)((L*)in->options.arr)[0], (cairo_antialias_t)in->antialias);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_get_antialias(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_get_antialias_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_get_antialias_sig* in = chk_cairo_font_options_get_antialias_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_antialias_t r = cairo_font_options_get_antialias((cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_options_set_subpixel_order(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_set_subpixel_order_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_subpixel_order_sig* in = chk_cairo_font_options_set_subpixel_order_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_subpixel_order((cairo_font_options_t*)((L*)in->options.arr)[0], (cairo_subpixel_order_t)in->subpixel_order);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_get_subpixel_order(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_get_subpixel_order_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_get_subpixel_order_sig* in = chk_cairo_font_options_get_subpixel_order_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_subpixel_order_t r = cairo_font_options_get_subpixel_order((cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_options_set_hint_style(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_set_hint_style_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_hint_style_sig* in = chk_cairo_font_options_set_hint_style_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_hint_style((cairo_font_options_t*)((L*)in->options.arr)[0], (cairo_hint_style_t)in->hint_style);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_get_hint_style(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_get_hint_style_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_get_hint_style_sig* in = chk_cairo_font_options_get_hint_style_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_hint_style_t r = cairo_font_options_get_hint_style((cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_options_set_hint_metrics(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_set_hint_metrics_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_hint_metrics_sig* in = chk_cairo_font_options_set_hint_metrics_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_hint_metrics((cairo_font_options_t*)((L*)in->options.arr)[0], (cairo_hint_metrics_t)in->hint_metrics);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_options_get_hint_metrics(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_get_hint_metrics_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_get_hint_metrics_sig* in = chk_cairo_font_options_get_hint_metrics_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_hint_metrics_t r = cairo_font_options_get_hint_metrics((cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_options_get_variations(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_get_variations_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_get_variations_sig* in = chk_cairo_font_options_get_variations_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 char const* r = cairo_font_options_get_variations((cairo_font_options_t*)in->options.arr);
 unref(xs); unref(x);
 return KC((char*)r,SL(r));
 }

K Fcairo_font_options_set_variations(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_options_set_variations_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_variations_sig* in = chk_cairo_font_options_set_variations_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_options_set_variations((cairo_font_options_t*)((L*)in->options.arr)[0], (char*)in->variations.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_select_font_face(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_select_font_face_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_select_font_face_sig* in = chk_cairo_select_font_face_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_select_font_face((cairo_t*)((L*)in->cr.arr)[0], (char*)in->family.arr, (cairo_font_slant_t)in->slant, (cairo_font_weight_t)in->weight);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_font_size(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_font_size_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_font_size_sig* in = chk_cairo_set_font_size_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_font_size((cairo_t*)((L*)in->cr.arr)[0], *(double*)in->size.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_font_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_font_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_font_matrix_sig* in = chk_cairo_set_font_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_font_matrix((cairo_t*)((L*)in->cr.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_font_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_font_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_font_matrix_sig* in = chk_cairo_get_font_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_get_font_matrix((cairo_t*)((L*)in->cr.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_font_options(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_font_options_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_font_options_sig* in = chk_cairo_set_font_options_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_font_options((cairo_t*)((L*)in->cr.arr)[0], (cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_font_options(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_font_options_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_font_options_sig* in = chk_cairo_get_font_options_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_get_font_options((cairo_t*)((L*)in->cr.arr)[0], (cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_set_font_face(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_font_face_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_font_face_sig* in = chk_cairo_set_font_face_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_font_face((cairo_t*)((L*)in->cr.arr)[0], (cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_font_face(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_font_face_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_font_face_sig* in = chk_cairo_get_font_face_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_FONT_FACE_T;
 ((cairo_font_face_t**)r)[0] = cairo_get_font_face((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_set_scaled_font(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_set_scaled_font_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_set_scaled_font_sig* in = chk_cairo_set_scaled_font_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_set_scaled_font((cairo_t*)((L*)in->cr.arr)[0], (cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_scaled_font(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_scaled_font_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_scaled_font_sig* in = chk_cairo_get_scaled_font_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SCALED_FONT_T;
 ((cairo_scaled_font_t**)r)[0] = cairo_get_scaled_font((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
}

K Fcairo_show_text(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_show_text_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_show_text_sig* in = chk_cairo_show_text_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_show_text((cairo_t*)((L*)in->cr.arr)[0], (char*)in->utf8.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_show_glyphs(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_show_glyphs_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_show_glyphs_sig* in = chk_cairo_show_glyphs_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_show_glyphs((cairo_t*)((L*)in->cr.arr)[0], (cairo_glyph_t*)((L*)in->glyphs.arr)[0], (int)in->num_glyphs);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_show_text_glyphs(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_show_text_glyphs_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_show_text_glyphs_sig* in = chk_cairo_show_text_glyphs_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_show_text_glyphs((cairo_t*)((L*)in->cr.arr)[0], (char*)in->utf8.arr, (int)in->utf8_len, (cairo_glyph_t*)((L*)in->glyphs.arr)[0], (int)in->num_glyphs, (cairo_text_cluster_t*)((L*)in->clusters.arr)[0], (int)in->num_clusters, (cairo_text_cluster_flags_t)in->cluster_flags);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_text_path(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_text_path_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_text_path_sig* in = chk_cairo_text_path_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_text_path((cairo_t*)((L*)in->cr.arr)[0], (char*)in->utf8.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_glyph_path(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_glyph_path_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_glyph_path_sig* in = chk_cairo_glyph_path_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_glyph_path((cairo_t*)((L*)in->cr.arr)[0], (cairo_glyph_t*)((L*)in->glyphs.arr)[0], (int)in->num_glyphs);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_text_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_text_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_text_extents_sig* in = chk_cairo_text_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 K r = KC(0,SZ(cairo_text_extents_t));
 
 cairo_text_extents((cairo_t*)((L*)in->cr.arr)[0], (char*)in->utf8.arr, (cairo_text_extents_t*)r);
 unref(xs); unref(x);
 return r;
 }

K Fcairo_glyph_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_glyph_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_glyph_extents_sig* in = chk_cairo_glyph_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_glyph_extents((cairo_t*)((L*)in->cr.arr)[0], (cairo_glyph_t*)((L*)in->glyphs.arr)[0], (int)in->num_glyphs, (cairo_text_extents_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_extents_sig* in = chk_cairo_font_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_extents((cairo_t*)((L*)in->cr.arr)[0], (cairo_font_extents_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_face_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_reference_sig* in = chk_cairo_font_face_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_FONT_FACE_T;
 ((cairo_font_face_t**)r)[0] = cairo_font_face_reference((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_font_face_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_destroy_sig* in = chk_cairo_font_face_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_face_destroy((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_font_face_get_reference_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_get_reference_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_get_reference_count_sig* in = chk_cairo_font_face_get_reference_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int r = cairo_font_face_get_reference_count((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_face_status(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_status_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_status_sig* in = chk_cairo_font_face_status_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_font_face_status((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_face_get_type(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_get_type_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_get_type_sig* in = chk_cairo_font_face_get_type_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_type_t r = cairo_font_face_get_type((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_font_face_get_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_get_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_get_user_data_sig* in = chk_cairo_font_face_get_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_VOID_T;
 ((void**)r)[0] = cairo_font_face_get_user_data((cairo_font_face_t*)in->font_face.arr, (cairo_user_data_key_t*)((L*)in->key.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_font_face_set_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_font_face_set_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_font_face_set_user_data_sig* in = chk_cairo_font_face_set_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_font_face_set_user_data((cairo_font_face_t*)((L*)in->font_face.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0], &user_data, f1);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_scaled_font_create(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_create_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_create_sig* in = chk_cairo_scaled_font_create_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SCALED_FONT_T;
 ((cairo_scaled_font_t**)r)[0] = cairo_scaled_font_create((cairo_font_face_t*)((L*)in->font_face.arr)[0], (cairo_matrix_t*)((L*)in->font_matrix.arr)[0], (cairo_matrix_t*)((L*)in->ctm.arr)[0], (cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_scaled_font_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_reference_sig* in = chk_cairo_scaled_font_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SCALED_FONT_T;
 ((cairo_scaled_font_t**)r)[0] = cairo_scaled_font_reference((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_scaled_font_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_destroy_sig* in = chk_cairo_scaled_font_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_destroy((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_get_reference_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_reference_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_reference_count_sig* in = chk_cairo_scaled_font_get_reference_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int r = cairo_scaled_font_get_reference_count((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_scaled_font_status(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_status_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_status_sig* in = chk_cairo_scaled_font_status_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_scaled_font_status((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_scaled_font_get_type(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_type_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_type_sig* in = chk_cairo_scaled_font_get_type_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_type_t r = cairo_scaled_font_get_type((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_scaled_font_get_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_user_data_sig* in = chk_cairo_scaled_font_get_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_VOID_T;
 ((void**)r)[0] = cairo_scaled_font_get_user_data((cairo_scaled_font_t*)in->scaled_font.arr, (cairo_user_data_key_t*)in->key.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_scaled_font_set_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_set_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_set_user_data_sig* in = chk_cairo_scaled_font_set_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_scaled_font_set_user_data((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0], &user_data, f1);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_scaled_font_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_extents_sig* in = chk_cairo_scaled_font_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_extents((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_font_extents_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_text_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_text_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_text_extents_sig* in = chk_cairo_scaled_font_text_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_text_extents((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (char*)in->utf8.arr, (cairo_text_extents_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_glyph_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_glyph_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_glyph_extents_sig* in = chk_cairo_scaled_font_glyph_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_glyph_extents((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_glyph_t*)((L*)in->glyphs.arr)[0], (int)in->num_glyphs, (cairo_text_extents_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_text_to_glyphs(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_text_to_glyphs_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_text_to_glyphs_sig* in = chk_cairo_scaled_font_text_to_glyphs_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_glyph_t* glyphs;
 int num_glyphs;
 cairo_text_cluster_t* clusters;
 int num_clusters;
 cairo_text_cluster_flags_t cluster_flags;
 cairo_status_t r = cairo_scaled_font_text_to_glyphs((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr, (char*)in->utf8.arr, (int)in->utf8_len, &glyphs, &num_glyphs, &clusters, &num_clusters, &cluster_flags);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_scaled_font_get_font_face(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_font_face_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_font_face_sig* in = chk_cairo_scaled_font_get_font_face_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_FONT_FACE_T;
 ((cairo_font_face_t**)r)[0] = cairo_scaled_font_get_font_face((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_scaled_font_get_font_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_font_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_font_matrix_sig* in = chk_cairo_scaled_font_get_font_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_font_matrix((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_matrix_t*)((L*)in->font_matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_get_ctm(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_ctm_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_ctm_sig* in = chk_cairo_scaled_font_get_ctm_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_ctm((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_matrix_t*)((L*)in->ctm.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_get_scale_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_scale_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_scale_matrix_sig* in = chk_cairo_scaled_font_get_scale_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_scale_matrix((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_matrix_t*)((L*)in->scale_matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_scaled_font_get_font_options(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_scaled_font_get_font_options_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_font_options_sig* in = chk_cairo_scaled_font_get_font_options_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_scaled_font_get_font_options((cairo_scaled_font_t*)((L*)in->scaled_font.arr)[0], (cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_toy_font_face_create(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_toy_font_face_create_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_toy_font_face_create_sig* in = chk_cairo_toy_font_face_create_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_FONT_FACE_T;
 ((cairo_font_face_t**)r)[0] = cairo_toy_font_face_create((char*)in->family.arr, (cairo_font_slant_t)in->slant, (cairo_font_weight_t)in->weight);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_toy_font_face_get_family(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_toy_font_face_get_family_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_toy_font_face_get_family_sig* in = chk_cairo_toy_font_face_get_family_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 char const* r = cairo_toy_font_face_get_family((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return KC((char*)r,SL(r));
 }

K Fcairo_toy_font_face_get_slant(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_toy_font_face_get_slant_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_toy_font_face_get_slant_sig* in = chk_cairo_toy_font_face_get_slant_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_slant_t r = cairo_toy_font_face_get_slant((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_toy_font_face_get_weight(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_toy_font_face_get_weight_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_toy_font_face_get_weight_sig* in = chk_cairo_toy_font_face_get_weight_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_font_weight_t r = cairo_toy_font_face_get_weight((cairo_font_face_t*)((L*)in->font_face.arr));
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_user_font_face_create(K x) {
 L r[2]; r[1] = KFFI_CAIRO_FONT_FACE_T;
 ((cairo_font_face_t**)r)[0] = cairo_user_font_face_create();
 unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_user_font_face_set_init_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_set_init_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_init_func_sig* in = chk_cairo_user_font_face_set_init_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_init_func((cairo_font_face_t*)((L*)in->font_face.arr)[0], f2);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_font_face_set_render_glyph_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_set_render_glyph_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_render_glyph_func_sig* in = chk_cairo_user_font_face_set_render_glyph_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_render_glyph_func((cairo_font_face_t*)((L*)in->font_face.arr)[0], f3);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_font_face_set_render_color_glyph_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_set_render_color_glyph_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_render_color_glyph_func_sig* in = chk_cairo_user_font_face_set_render_color_glyph_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_render_color_glyph_func((cairo_font_face_t*)((L*)in->font_face.arr)[0], f3);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_font_face_set_text_to_glyphs_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_set_text_to_glyphs_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_text_to_glyphs_func_sig* in = chk_cairo_user_font_face_set_text_to_glyphs_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_text_to_glyphs_func((cairo_font_face_t*)((L*)in->font_face.arr)[0], f4);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_font_face_set_unicode_to_glyph_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_set_unicode_to_glyph_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_unicode_to_glyph_func_sig* in = chk_cairo_user_font_face_set_unicode_to_glyph_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_set_unicode_to_glyph_func((cairo_font_face_t*)((L*)in->font_face.arr)[0], f5);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_user_font_face_get_init_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_get_init_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_get_init_func_sig* in = chk_cairo_user_font_face_get_init_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_USER_SCALED_FONT_INIT_FUNC_T;
 ((cairo_user_scaled_font_init_func_t*)r)[0] = cairo_user_font_face_get_init_func((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_user_font_face_get_render_glyph_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_get_render_glyph_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_get_render_glyph_func_sig* in = chk_cairo_user_font_face_get_render_glyph_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_USER_SCALED_FONT_RENDER_GLYPH_FUNC_T;
 ((cairo_user_scaled_font_render_glyph_func_t*)r)[0] = cairo_user_font_face_get_render_glyph_func((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_user_font_face_get_render_color_glyph_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_get_render_color_glyph_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_get_render_color_glyph_func_sig* in = chk_cairo_user_font_face_get_render_color_glyph_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_USER_SCALED_FONT_RENDER_GLYPH_FUNC_T;
 ((cairo_user_scaled_font_render_glyph_func_t*)r)[0] = cairo_user_font_face_get_render_color_glyph_func((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_user_font_face_get_text_to_glyphs_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_get_text_to_glyphs_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_get_text_to_glyphs_func_sig* in = chk_cairo_user_font_face_get_text_to_glyphs_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_USER_SCALED_FONT_TEXT_TO_GLYPHS_FUNC_T;
 ((cairo_user_scaled_font_text_to_glyphs_func_t*)r)[0] = cairo_user_font_face_get_text_to_glyphs_func((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_user_font_face_get_unicode_to_glyph_func(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_user_font_face_get_unicode_to_glyph_func_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_user_font_face_get_unicode_to_glyph_func_sig* in = chk_cairo_user_font_face_get_unicode_to_glyph_func_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_USER_SCALED_FONT_UNICODE_TO_GLYPH_FUNC_T;
 ((cairo_user_scaled_font_unicode_to_glyph_func_t*)r)[0] = cairo_user_font_face_get_unicode_to_glyph_func((cairo_font_face_t*)((L*)in->font_face.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_get_operator(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_operator_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_operator_sig* in = chk_cairo_get_operator_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_operator_t r = cairo_get_operator((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_source(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_source_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_source_sig* in = chk_cairo_get_source_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_get_source((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_get_tolerance(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_tolerance_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_tolerance_sig* in = chk_cairo_get_tolerance_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_get_tolerance((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_get_antialias(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_antialias_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_antialias_sig* in = chk_cairo_get_antialias_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_antialias_t r = cairo_get_antialias((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_has_current_point(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_has_current_point_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_has_current_point_sig* in = chk_cairo_has_current_point_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_has_current_point((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_current_point(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_current_point_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_current_point_sig* in = chk_cairo_get_current_point_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_get_current_point((cairo_t*)((L*)in->cr.arr)[0], (double*)in->x.arr, (double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_fill_rule(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_fill_rule_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_fill_rule_sig* in = chk_cairo_get_fill_rule_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_fill_rule_t r = cairo_get_fill_rule((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_line_width(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_line_width_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_line_width_sig* in = chk_cairo_get_line_width_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_get_line_width((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_get_hairline(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_hairline_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_hairline_sig* in = chk_cairo_get_hairline_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_get_hairline((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_line_cap(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_line_cap_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_line_cap_sig* in = chk_cairo_get_line_cap_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_line_cap_t r = cairo_get_line_cap((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_line_join(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_line_join_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_line_join_sig* in = chk_cairo_get_line_join_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_line_join_t r = cairo_get_line_join((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_miter_limit(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_miter_limit_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_miter_limit_sig* in = chk_cairo_get_miter_limit_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_get_miter_limit((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_get_dash_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_dash_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_dash_count_sig* in = chk_cairo_get_dash_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r = cairo_get_dash_count((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_get_dash(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_dash_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_dash_sig* in = chk_cairo_get_dash_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_get_dash((cairo_t*)((L*)in->cr.arr)[0], (double*)in->dashes.arr, (double*)in->offset.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_matrix_sig* in = chk_cairo_get_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_get_matrix((cairo_t*)((L*)in->cr.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_get_target(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_target_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_target_sig* in = chk_cairo_get_target_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_get_target((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_get_group_target(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_get_group_target_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_get_group_target_sig* in = chk_cairo_get_group_target_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_get_group_target((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_copy_path(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_copy_path_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_copy_path_sig* in = chk_cairo_copy_path_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATH_T;
 ((cairo_path_t**)r)[0] = cairo_copy_path((cairo_t*)((L*)in->cr.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_copy_path_flat(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_copy_path_flat_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_copy_path_flat_sig* in = chk_cairo_copy_path_flat_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATH_T;
 ((cairo_path_t**)r)[0] = cairo_copy_path_flat((cairo_t*)in->cr.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_append_path(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_append_path_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_append_path_sig* in = chk_cairo_append_path_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_append_path((cairo_t*)((L*)in->cr.arr)[0], (cairo_path_t*)((L*)in->path.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_path_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_path_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_path_destroy_sig* in = chk_cairo_path_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_path_destroy((cairo_path_t*)((L*)in->path.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_status(K x) {
 cairo_status_t r = cairo_status((cairo_t*)((L*)x)[0]);
 unref(x);
 return Ki(r);
 }

K Fcairo_status_to_string(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_status_to_string_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_status_to_string_sig* in = chk_cairo_status_to_string_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 char const* r = cairo_status_to_string((cairo_status_t)in->status);
 unref(xs); unref(x);
 return KC((char*)r,SL(r));
 }

K Fcairo_device_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_reference_sig* in = chk_cairo_device_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_DEVICE_T;
 ((cairo_device_t**)r)[0] = cairo_device_reference((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_device_get_type(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_get_type_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_get_type_sig* in = chk_cairo_device_get_type_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_type_t r = cairo_device_get_type((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_device_status(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_status_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_status_sig* in = chk_cairo_device_status_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_device_status((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_device_acquire(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_acquire_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_acquire_sig* in = chk_cairo_device_acquire_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_device_acquire((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_device_release(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_release_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_release_sig* in = chk_cairo_device_release_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_release((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_device_flush(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_flush_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_flush_sig* in = chk_cairo_device_flush_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_flush((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_device_finish(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_finish_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_finish_sig* in = chk_cairo_device_finish_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_finish((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_device_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_destroy_sig* in = chk_cairo_device_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_device_destroy((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_device_get_reference_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_get_reference_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_get_reference_count_sig* in = chk_cairo_device_get_reference_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int r = cairo_device_get_reference_count((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_device_get_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_get_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_get_user_data_sig* in = chk_cairo_device_get_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_VOID_T;
 ((void**)r)[0] = cairo_device_get_user_data((cairo_device_t*)((L*)in->device.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_device_set_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_set_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_set_user_data_sig* in = chk_cairo_device_set_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_device_set_user_data((cairo_device_t*)((L*)in->device.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0], &user_data, f1);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_create_similar(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_create_similar_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_create_similar_sig* in = chk_cairo_surface_create_similar_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_surface_create_similar((cairo_surface_t*)((L*)in->other.arr)[0], (cairo_content_t)in->content, (int)in->width, (int)in->height);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_create_similar_image(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_create_similar_image_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_create_similar_image_sig* in = chk_cairo_surface_create_similar_image_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_surface_create_similar_image((cairo_surface_t*)((L*)in->other.arr)[0], (cairo_format_t)in->format, (int)in->width, (int)in->height);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_map_to_image(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_map_to_image_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_map_to_image_sig* in = chk_cairo_surface_map_to_image_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_surface_map_to_image((cairo_surface_t*)((L*)in->surface.arr)[0], (cairo_rectangle_int_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_unmap_image(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_unmap_image_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_unmap_image_sig* in = chk_cairo_surface_unmap_image_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_unmap_image((cairo_surface_t*)((L*)in->surface.arr)[0], (cairo_surface_t*)((L*)in->image.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_create_for_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_create_for_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_create_for_rectangle_sig* in = chk_cairo_surface_create_for_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_surface_create_for_rectangle((cairo_surface_t*)((L*)in->target.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr, *(double*)in->width.arr, *(double*)in->height.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_create_observer(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_create_observer_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_create_observer_sig* in = chk_cairo_surface_create_observer_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_surface_create_observer((cairo_surface_t*)((L*)in->target.arr)[0], (cairo_surface_observer_mode_t)in->mode);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_observer_add_paint_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_paint_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_paint_callback_sig* in = chk_cairo_surface_observer_add_paint_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_paint_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_add_mask_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_mask_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_mask_callback_sig* in = chk_cairo_surface_observer_add_mask_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_mask_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_add_fill_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_fill_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_fill_callback_sig* in = chk_cairo_surface_observer_add_fill_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_fill_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_add_stroke_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_stroke_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_stroke_callback_sig* in = chk_cairo_surface_observer_add_stroke_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_stroke_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_add_glyphs_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_glyphs_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_glyphs_callback_sig* in = chk_cairo_surface_observer_add_glyphs_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_glyphs_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_add_flush_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_flush_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_flush_callback_sig* in = chk_cairo_surface_observer_add_flush_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_flush_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_add_finish_callback(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_add_finish_callback_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_add_finish_callback_sig* in = chk_cairo_surface_observer_add_finish_callback_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_add_finish_callback((cairo_surface_t*)((L*)in->abstract_surface.arr)[0], f6, &data);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_print(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_print_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_print_sig* in = chk_cairo_surface_observer_print_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I closure; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_observer_print((cairo_surface_t*)((L*)in->surface.arr)[0], f7, &closure);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_observer_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_observer_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_observer_elapsed_sig* in = chk_cairo_surface_observer_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_surface_observer_elapsed((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_device_observer_print(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_print_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_print_sig* in = chk_cairo_device_observer_print_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I closure; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_device_observer_print((cairo_device_t*)((L*)in->device.arr)[0], f7, &closure);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_device_observer_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_elapsed_sig* in = chk_cairo_device_observer_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_device_observer_elapsed((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_device_observer_paint_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_paint_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_paint_elapsed_sig* in = chk_cairo_device_observer_paint_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_device_observer_paint_elapsed((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_device_observer_mask_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_mask_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_mask_elapsed_sig* in = chk_cairo_device_observer_mask_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_device_observer_mask_elapsed((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_device_observer_fill_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_fill_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_fill_elapsed_sig* in = chk_cairo_device_observer_fill_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_device_observer_fill_elapsed((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_device_observer_stroke_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_stroke_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_stroke_elapsed_sig* in = chk_cairo_device_observer_stroke_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_device_observer_stroke_elapsed((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_device_observer_glyphs_elapsed(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_device_observer_glyphs_elapsed_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_device_observer_glyphs_elapsed_sig* in = chk_cairo_device_observer_glyphs_elapsed_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 double r = cairo_device_observer_glyphs_elapsed((cairo_device_t*)((L*)in->device.arr)[0]);
 unref(xs); unref(x);
 return Kf(r);
 }

K Fcairo_surface_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_reference_sig* in = chk_cairo_surface_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_surface_reference((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_finish(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_finish_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_finish_sig* in = chk_cairo_surface_finish_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_finish((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_destroy(K x) {
 cairo_surface_destroy((cairo_surface_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_surface_get_device(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_device_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_device_sig* in = chk_cairo_surface_get_device_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_DEVICE_T;
 ((cairo_device_t**)r)[0] = cairo_surface_get_device((cairo_surface_t*)in->surface.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_get_reference_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_reference_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_reference_count_sig* in = chk_cairo_surface_get_reference_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int r = cairo_surface_get_reference_count((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_status(K x) {ref(x);
 cairo_status_t r = cairo_surface_status((cairo_surface_t*)((L*)x)[0]);
 unref(x);
 return Ki(r);
 }

K Fcairo_surface_get_type(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_type_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_type_sig* in = chk_cairo_surface_get_type_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_type_t r = cairo_surface_get_type((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_get_content(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_content_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_content_sig* in = chk_cairo_surface_get_content_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_content_t r = cairo_surface_get_content((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_write_to_png(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_write_to_png_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_write_to_png_sig* in = chk_cairo_surface_write_to_png_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_surface_write_to_png((cairo_surface_t*)((L*)in->surface.arr)[0], (char*)in->filename.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_write_to_png_stream(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_write_to_png_stream_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_write_to_png_stream_sig* in = chk_cairo_surface_write_to_png_stream_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I closure; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_write_to_png_stream((cairo_surface_t*)((L*)in->surface.arr)[0], f7, &closure);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_get_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_user_data_sig* in = chk_cairo_surface_get_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_VOID_T;
 ((void**)r)[0] = cairo_surface_get_user_data((cairo_surface_t*)((L*)in->surface.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_surface_set_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_set_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_set_user_data_sig* in = chk_cairo_surface_set_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_set_user_data((cairo_surface_t*)((L*)in->surface.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0], &user_data, f1);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_get_mime_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_mime_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_mime_data_sig* in = chk_cairo_surface_get_mime_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 const unsigned char* data;
 unsigned long length;
 cairo_surface_get_mime_data((cairo_surface_t*)((L*)in->surface.arr)[0], (char*)in->mime_type.arr, &data, &length);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_set_mime_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_set_mime_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_set_mime_data_sig* in = chk_cairo_surface_set_mime_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I closure; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_surface_set_mime_data((cairo_surface_t*)in->surface.arr, (char*)in->mime_type.arr, (unsigned char*)in->data.arr, *(unsigned long*)in->length.arr, f1, &closure);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_supports_mime_type(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_supports_mime_type_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_supports_mime_type_sig* in = chk_cairo_surface_supports_mime_type_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_surface_supports_mime_type((cairo_surface_t*)((L*)in->surface.arr)[0], (char*)in->mime_type.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_surface_get_font_options(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_font_options_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_font_options_sig* in = chk_cairo_surface_get_font_options_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_get_font_options((cairo_surface_t*)((L*)in->surface.arr)[0], (cairo_font_options_t*)((L*)in->options.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_flush(K x) {
 cairo_surface_flush((cairo_surface_t*)((L*)x)[0]);
 unref(x);
 return Kv();
 }

K Fcairo_surface_mark_dirty(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_mark_dirty_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_mark_dirty_sig* in = chk_cairo_surface_mark_dirty_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_mark_dirty((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_mark_dirty_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_mark_dirty_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_mark_dirty_rectangle_sig* in = chk_cairo_surface_mark_dirty_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_mark_dirty_rectangle((cairo_surface_t*)((L*)in->surface.arr)[0], (int)in->x, (int)in->y, (int)in->width, (int)in->height);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_set_device_scale(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_set_device_scale_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_set_device_scale_sig* in = chk_cairo_surface_set_device_scale_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_set_device_scale((cairo_surface_t*)((L*)in->surface.arr)[0], *(double*)in->x_scale.arr, *(double*)in->y_scale.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_get_device_scale(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_device_scale_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_device_scale_sig* in = chk_cairo_surface_get_device_scale_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_get_device_scale((cairo_surface_t*)((L*)in->surface.arr)[0], (double*)in->x_scale.arr, (double*)in->y_scale.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_set_device_offset(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_set_device_offset_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_set_device_offset_sig* in = chk_cairo_surface_set_device_offset_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_set_device_offset((cairo_surface_t*)((L*)in->surface.arr)[0], *(double*)in->x_offset.arr, *(double*)in->y_offset.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_get_device_offset(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_device_offset_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_device_offset_sig* in = chk_cairo_surface_get_device_offset_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_get_device_offset((cairo_surface_t*)((L*)in->surface.arr)[0], (double*)in->x_offset.arr, (double*)in->y_offset.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_set_fallback_resolution(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_set_fallback_resolution_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_set_fallback_resolution_sig* in = chk_cairo_surface_set_fallback_resolution_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_set_fallback_resolution((cairo_surface_t*)((L*)in->surface.arr)[0], *(double*)in->x_pixels_per_inch.arr, *(double*)in->y_pixels_per_inch.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_get_fallback_resolution(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_get_fallback_resolution_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_get_fallback_resolution_sig* in = chk_cairo_surface_get_fallback_resolution_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_get_fallback_resolution((cairo_surface_t*)((L*)in->surface.arr)[0], (double*)in->x_pixels_per_inch.arr, (double*)in->y_pixels_per_inch.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_copy_page(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_copy_page_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_copy_page_sig* in = chk_cairo_surface_copy_page_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_copy_page((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_show_page(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_show_page_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_show_page_sig* in = chk_cairo_surface_show_page_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_surface_show_page((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_surface_has_show_text_glyphs(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_surface_has_show_text_glyphs_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_surface_has_show_text_glyphs_sig* in = chk_cairo_surface_has_show_text_glyphs_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_surface_has_show_text_glyphs((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_image_surface_create(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_create_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_create_sig* in = chk_cairo_image_surface_create_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_image_surface_create((cairo_format_t)in->format, (int)in->width, (int)in->height);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_format_stride_for_width(K f,K w) {
 int r = cairo_format_stride_for_width((cairo_format_t)f, (int)w);
 return Ki(r);
 }

K Fcairo_image_surface_create_for_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_create_for_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_create_for_data_sig* in = chk_cairo_image_surface_create_for_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }

 ref((K)in->data.arr);
 
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_image_surface_create_for_data((unsigned char*)in->data.arr, (cairo_format_t)in->format, (int)in->width, (int)in->height, (int)in->stride);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_image_surface_get_data(K x) {
 unsigned char* r = cairo_image_surface_get_data((cairo_surface_t*)((L*)x)[0]);
 unref(x);
 return KC((char*)r,SL((char*)r));
 }

K Fcairo_image_surface_get_format(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_get_format_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_get_format_sig* in = chk_cairo_image_surface_get_format_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_format_t r = cairo_image_surface_get_format((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_image_surface_get_width(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_get_width_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_get_width_sig* in = chk_cairo_image_surface_get_width_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r = cairo_image_surface_get_width((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_image_surface_get_height(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_get_height_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_get_height_sig* in = chk_cairo_image_surface_get_height_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r = cairo_image_surface_get_height((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_image_surface_get_stride(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_get_stride_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_get_stride_sig* in = chk_cairo_image_surface_get_stride_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r = cairo_image_surface_get_stride((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_image_surface_create_from_png(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_create_from_png_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_create_from_png_sig* in = chk_cairo_image_surface_create_from_png_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_image_surface_create_from_png((char*)in->filename.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_image_surface_create_from_png_stream(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_image_surface_create_from_png_stream_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_image_surface_create_from_png_stream_sig* in = chk_cairo_image_surface_create_from_png_stream_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I closure; // Not sure what to do.  Should this be a K object??
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_image_surface_create_from_png_stream(f8, &closure);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_recording_surface_create(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_recording_surface_create_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_recording_surface_create_sig* in = chk_cairo_recording_surface_create_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_SURFACE_T;
 ((cairo_surface_t**)r)[0] = cairo_recording_surface_create((cairo_content_t)in->content, (cairo_rectangle_t*)in->extents.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_recording_surface_ink_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_recording_surface_ink_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_recording_surface_ink_extents_sig* in = chk_cairo_recording_surface_ink_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_recording_surface_ink_extents((cairo_surface_t*)((L*)in->surface.arr)[0], (double*)in->x0.arr, (double*)in->y0.arr, (double*)in->width.arr, (double*)in->height.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_recording_surface_get_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_recording_surface_get_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_recording_surface_get_extents_sig* in = chk_cairo_recording_surface_get_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_recording_surface_get_extents((cairo_surface_t*)((L*)in->surface.arr)[0], (cairo_rectangle_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_create_raster_source(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_create_raster_source_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_create_raster_source_sig* in = chk_cairo_pattern_create_raster_source_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_raster_source(&user_data, (cairo_content_t)in->content, (int)in->width, (int)in->height);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_raster_source_pattern_set_callback_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_set_callback_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_callback_data_sig* in = chk_cairo_raster_source_pattern_set_callback_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I data; // Not sure what to do.  Should this be a K object??
 cairo_raster_source_pattern_set_callback_data((cairo_pattern_t*)((L*)in->pattern.arr)[0], &data);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_raster_source_pattern_get_callback_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_get_callback_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_get_callback_data_sig* in = chk_cairo_raster_source_pattern_get_callback_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_VOID_T;
 ((void**)r)[0] = cairo_raster_source_pattern_get_callback_data((cairo_pattern_t*)in->pattern.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_raster_source_pattern_set_acquire(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_set_acquire_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_acquire_sig* in = chk_cairo_raster_source_pattern_set_acquire_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_acquire((cairo_pattern_t*)((L*)in->pattern.arr)[0], f9, f11);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_raster_source_pattern_get_acquire(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_get_acquire_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_get_acquire_sig* in = chk_cairo_raster_source_pattern_get_acquire_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_get_acquire((cairo_pattern_t*)((L*)in->pattern.arr)[0], &f10, &f12);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_raster_source_pattern_set_snapshot(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_set_snapshot_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_snapshot_sig* in = chk_cairo_raster_source_pattern_set_snapshot_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_snapshot((cairo_pattern_t*)((L*)in->pattern.arr)[0], f13);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_raster_source_pattern_get_snapshot(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_get_snapshot_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_get_snapshot_sig* in = chk_cairo_raster_source_pattern_get_snapshot_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2];
 r[1] = KFFI_CAIRO_RASTER_SOURCE_SNAPSHOT_FUNC_T;
 ((cairo_raster_source_snapshot_func_t*)r)[0] = cairo_raster_source_pattern_get_snapshot((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_raster_source_pattern_set_copy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_set_copy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_copy_sig* in = chk_cairo_raster_source_pattern_set_copy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_copy((cairo_pattern_t*)((L*)in->pattern.arr)[0], f14);
 unref(xs); unref(x);
 return Kv();;
 }

K Fcairo_raster_source_pattern_get_copy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_get_copy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_get_copy_sig* in = chk_cairo_raster_source_pattern_get_copy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2];
 r[1] = KFFI_CAIRO_RASTER_SOURCE_COPY_FUNC_T;
 ((cairo_raster_source_copy_func_t*)r)[0] = cairo_raster_source_pattern_get_copy((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_raster_source_pattern_set_finish(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_set_finish_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_finish_sig* in = chk_cairo_raster_source_pattern_set_finish_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_set_finish((cairo_pattern_t*)((L*)in->pattern.arr)[0], f15);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_raster_source_pattern_get_finish(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_raster_source_pattern_get_finish_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_raster_source_pattern_get_finish_sig* in = chk_cairo_raster_source_pattern_get_finish_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2];
 r[1] = KFFI_CAIRO_RASTER_SOURCE_FINISH_FUNC_T;
 ((cairo_raster_source_finish_func_t*)r)[0] = cairo_raster_source_pattern_get_finish((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_create_rgb(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_create_rgb_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_create_rgb_sig* in = chk_cairo_pattern_create_rgb_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_rgb(*(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_create_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_create_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_create_rgba_sig* in = chk_cairo_pattern_create_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_rgba(*(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr, *(double*)in->alpha.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_create_for_surface(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_create_for_surface_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_create_for_surface_sig* in = chk_cairo_pattern_create_for_surface_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_for_surface((cairo_surface_t*)((L*)in->surface.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_create_linear(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_create_linear_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_create_linear_sig* in = chk_cairo_pattern_create_linear_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_linear(*(double*)in->x0.arr, *(double*)in->y0.arr, *(double*)in->x1.arr, *(double*)in->y1.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_create_radial(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_create_radial_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_create_radial_sig* in = chk_cairo_pattern_create_radial_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_radial(*(double*)in->cx0.arr, *(double*)in->cy0.arr, *(double*)in->radius0.arr, *(double*)in->cx1.arr, *(double*)in->cy1.arr, *(double*)in->radius1.arr);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_create_mesh(K x) {
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_create_mesh();
 unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_reference_sig* in = chk_cairo_pattern_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATTERN_T;
 ((cairo_pattern_t**)r)[0] = cairo_pattern_reference((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_destroy_sig* in = chk_cairo_pattern_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_destroy((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_get_reference_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_reference_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_reference_count_sig* in = chk_cairo_pattern_get_reference_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int r = cairo_pattern_get_reference_count((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_status(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_status_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_status_sig* in = chk_cairo_pattern_status_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_pattern_status((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_user_data_sig* in = chk_cairo_pattern_get_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_VOID_T;
 ((void**)r)[0] = cairo_pattern_get_user_data((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_pattern_set_user_data(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_set_user_data_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_user_data_sig* in = chk_cairo_pattern_set_user_data_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 Z I user_data; // Not sure what to do.  Should this be a K object??
 cairo_status_t r = cairo_pattern_set_user_data((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_user_data_key_t*)((L*)in->key.arr)[0], &user_data, f1);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_type(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_type_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_type_sig* in = chk_cairo_pattern_get_type_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_type_t r = cairo_pattern_get_type((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_add_color_stop_rgb(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_add_color_stop_rgb_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_add_color_stop_rgb_sig* in = chk_cairo_pattern_add_color_stop_rgb_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_add_color_stop_rgb((cairo_pattern_t*)((L*)in->pattern.arr)[0], *(double*)in->offset.arr, *(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_add_color_stop_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_add_color_stop_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_add_color_stop_rgba_sig* in = chk_cairo_pattern_add_color_stop_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_add_color_stop_rgba((cairo_pattern_t*)((L*)in->pattern.arr)[0], *(double*)in->offset.arr, *(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr, *(double*)in->alpha.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_begin_patch(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_begin_patch_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_begin_patch_sig* in = chk_cairo_mesh_pattern_begin_patch_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_begin_patch((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_end_patch(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_end_patch_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_end_patch_sig* in = chk_cairo_mesh_pattern_end_patch_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_end_patch((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_curve_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_curve_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_curve_to_sig* in = chk_cairo_mesh_pattern_curve_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_curve_to((cairo_pattern_t*)((L*)in->pattern.arr)[0], *(double*)in->x1.arr, *(double*)in->y1.arr, *(double*)in->x2.arr, *(double*)in->y2.arr, *(double*)in->x3.arr, *(double*)in->y3.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_line_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_line_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_line_to_sig* in = chk_cairo_mesh_pattern_line_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_line_to((cairo_pattern_t*)((L*)in->pattern.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_move_to(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_move_to_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_move_to_sig* in = chk_cairo_mesh_pattern_move_to_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_move_to((cairo_pattern_t*)((L*)in->pattern.arr)[0], *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_set_control_point(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_set_control_point_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_set_control_point_sig* in = chk_cairo_mesh_pattern_set_control_point_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_set_control_point((cairo_pattern_t*)((L*)in->pattern.arr)[0], (unsigned int)in->point_num, *(double*)in->x.arr, *(double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_set_corner_color_rgb(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_set_corner_color_rgb_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_set_corner_color_rgb_sig* in = chk_cairo_mesh_pattern_set_corner_color_rgb_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_set_corner_color_rgb((cairo_pattern_t*)((L*)in->pattern.arr)[0], (unsigned int)in->corner_num, *(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_mesh_pattern_set_corner_color_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_set_corner_color_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_set_corner_color_rgba_sig* in = chk_cairo_mesh_pattern_set_corner_color_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_set_corner_color_rgba((cairo_pattern_t*)((L*)in->pattern.arr)[0], (unsigned int)in->corner_num, *(double*)in->red.arr, *(double*)in->green.arr, *(double*)in->blue.arr, *(double*)in->alpha.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_set_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_set_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_matrix_sig* in = chk_cairo_pattern_set_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_matrix((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_get_matrix(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_matrix_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_matrix_sig* in = chk_cairo_pattern_get_matrix_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_matrix((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_set_extend(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_set_extend_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_extend_sig* in = chk_cairo_pattern_set_extend_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_extend((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_extend_t)in->extend);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_get_extend(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_extend_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_extend_sig* in = chk_cairo_pattern_get_extend_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_extend_t r = cairo_pattern_get_extend((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_set_filter(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_set_filter_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_filter_sig* in = chk_cairo_pattern_set_filter_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_pattern_set_filter((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_filter_t)in->filter);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_pattern_get_filter(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_filter_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_filter_sig* in = chk_cairo_pattern_get_filter_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_filter_t r = cairo_pattern_get_filter((cairo_pattern_t*)((L*)in->pattern.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_rgba_sig* in = chk_cairo_pattern_get_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_pattern_get_rgba((cairo_pattern_t*)((L*)in->pattern.arr)[0], (double*)in->red.arr, (double*)in->green.arr, (double*)in->blue.arr, (double*)in->alpha.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_surface(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_surface_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_surface_sig* in = chk_cairo_pattern_get_surface_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_pattern_get_surface((cairo_pattern_t*)((L*)in->pattern.arr)[0], (cairo_surface_t**)in->surface.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_color_stop_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_color_stop_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_color_stop_rgba_sig* in = chk_cairo_pattern_get_color_stop_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_pattern_get_color_stop_rgba((cairo_pattern_t*)((L*)in->pattern.arr)[0], (int)in->index, (double*)in->offset.arr, (double*)in->red.arr, (double*)in->green.arr, (double*)in->blue.arr, (double*)in->alpha.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_color_stop_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_color_stop_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_color_stop_count_sig* in = chk_cairo_pattern_get_color_stop_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int count;
 cairo_status_t r = cairo_pattern_get_color_stop_count((cairo_pattern_t*)((L*)in->pattern.arr)[0], &count);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_linear_points(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_linear_points_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_linear_points_sig* in = chk_cairo_pattern_get_linear_points_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_pattern_get_linear_points((cairo_pattern_t*)((L*)in->pattern.arr)[0], (double*)in->x0.arr, (double*)in->y0.arr, (double*)in->x1.arr, (double*)in->y1.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_pattern_get_radial_circles(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_pattern_get_radial_circles_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_pattern_get_radial_circles_sig* in = chk_cairo_pattern_get_radial_circles_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_pattern_get_radial_circles((cairo_pattern_t*)((L*)in->pattern.arr)[0], (double*)in->x0.arr, (double*)in->y0.arr, (double*)in->r0.arr, (double*)in->x1.arr, (double*)in->y1.arr, (double*)in->r1.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_mesh_pattern_get_patch_count(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_get_patch_count_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_get_patch_count_sig* in = chk_cairo_mesh_pattern_get_patch_count_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 unsigned int count;
 cairo_status_t r = cairo_mesh_pattern_get_patch_count((cairo_pattern_t*)((L*)in->pattern.arr)[0], &count);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_mesh_pattern_get_path(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_get_path_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_get_path_sig* in = chk_cairo_mesh_pattern_get_path_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_PATH_T;
 ((cairo_path_t**)r)[0] = cairo_mesh_pattern_get_path((cairo_pattern_t*)in->pattern.arr, (unsigned int)in->patch_num);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_mesh_pattern_get_corner_color_rgba(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_get_corner_color_rgba_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_get_corner_color_rgba_sig* in = chk_cairo_mesh_pattern_get_corner_color_rgba_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_mesh_pattern_get_corner_color_rgba((cairo_pattern_t*)((L*)in->pattern.arr)[0], (unsigned int)in->patch_num, (unsigned int)in->corner_num, (double*)in->red.arr, (double*)in->green.arr, (double*)in->blue.arr, (double*)in->alpha.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_mesh_pattern_get_control_point(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_mesh_pattern_get_control_point_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_mesh_pattern_get_control_point_sig* in = chk_cairo_mesh_pattern_get_control_point_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_mesh_pattern_get_control_point((cairo_pattern_t*)((L*)in->pattern.arr)[0], (unsigned int)in->patch_num, (unsigned int)in->point_num, (double*)in->x.arr, (double*)in->y.arr);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_matrix_init(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_init_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_sig* in = chk_cairo_matrix_init_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_init((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->xx.arr, *(double*)in->yx.arr, *(double*)in->xy.arr, *(double*)in->yy.arr, *(double*)in->x0.arr, *(double*)in->y0.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_init_identity(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_init_identity_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_identity_sig* in = chk_cairo_matrix_init_identity_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_identity((cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_init_translate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_init_translate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_translate_sig* in = chk_cairo_matrix_init_translate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_translate((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->tx.arr, *(double*)in->ty.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_init_scale(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_init_scale_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_scale_sig* in = chk_cairo_matrix_init_scale_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_scale((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->sx.arr, *(double*)in->sy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_init_rotate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_init_rotate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_rotate_sig* in = chk_cairo_matrix_init_rotate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_init_rotate((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->radians.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_translate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_translate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_translate_sig* in = chk_cairo_matrix_translate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_translate((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->tx.arr, *(double*)in->ty.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_scale(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_scale_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_scale_sig* in = chk_cairo_matrix_scale_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_scale((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->sx.arr, *(double*)in->sy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_rotate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_rotate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_rotate_sig* in = chk_cairo_matrix_rotate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_rotate((cairo_matrix_t*)((L*)in->matrix.arr)[0], *(double*)in->radians.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_invert(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_invert_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_invert_sig* in = chk_cairo_matrix_invert_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_matrix_invert((cairo_matrix_t*)((L*)in->matrix.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_matrix_multiply(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_multiply_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_multiply_sig* in = chk_cairo_matrix_multiply_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_multiply((cairo_matrix_t*)((L*)in->result.arr)[0], (cairo_matrix_t*)in->a.arr, (cairo_matrix_t*)in->b.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_transform_distance(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_transform_distance_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_transform_distance_sig* in = chk_cairo_matrix_transform_distance_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_transform_distance((cairo_matrix_t*)((L*)in->matrix.arr)[0], (double*)in->dx.arr, (double*)in->dy.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_matrix_transform_point(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_matrix_transform_point_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_matrix_transform_point_sig* in = chk_cairo_matrix_transform_point_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_matrix_transform_point((cairo_matrix_t*)((L*)in->matrix.arr)[0], (double*)in->x.arr, (double*)in->y.arr);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_region_create(K x) {
 L r[2]; r[1] = KFFI_CAIRO_REGION_T;
 ((cairo_region_t**)r)[0] = cairo_region_create();
 unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_region_create_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_create_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_create_rectangle_sig* in = chk_cairo_region_create_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_REGION_T;
 ((cairo_region_t**)r)[0] = cairo_region_create_rectangle((cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_region_create_rectangles(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_create_rectangles_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_create_rectangles_sig* in = chk_cairo_region_create_rectangles_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_REGION_T;
 ((cairo_region_t**)r)[0] = cairo_region_create_rectangles((cairo_rectangle_int_t*)((L*)in->rects.arr)[0], (int)in->count);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_region_copy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_copy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_copy_sig* in = chk_cairo_region_copy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_REGION_T;
 ((cairo_region_t**)r)[0] = cairo_region_copy((cairo_region_t*)((L*)in->original.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_region_reference(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_reference_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_reference_sig* in = chk_cairo_region_reference_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 L r[2]; r[1] = KFFI_CAIRO_REGION_T;
 ((cairo_region_t**)r)[0] = cairo_region_reference((cairo_region_t*)((L*)in->region.arr)[0]);
 unref(xs); unref(x);
 char ret[SZ(arr)+1];ret[0]=1;
 *(arr*)(ret+1) = (arr){.hdr={.type=REF|7, .len=2}, .arr=r};
 return des_(ret,SZ(ret));
 }

K Fcairo_region_destroy(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_destroy_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_destroy_sig* in = chk_cairo_region_destroy_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_region_destroy((cairo_region_t*)((L*)in->region.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_region_equal(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_equal_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_equal_sig* in = chk_cairo_region_equal_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_region_equal((cairo_region_t*)((L*)in->a.arr)[0], (cairo_region_t*)((L*)in->b.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_status(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_status_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_status_sig* in = chk_cairo_region_status_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_status((cairo_region_t*)((L*)in->region.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_get_extents(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_get_extents_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_get_extents_sig* in = chk_cairo_region_get_extents_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_region_get_extents((cairo_region_t*)((L*)in->region.arr)[0], (cairo_rectangle_int_t*)((L*)in->extents.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_region_num_rectangles(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_num_rectangles_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_num_rectangles_sig* in = chk_cairo_region_num_rectangles_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 int r = cairo_region_num_rectangles((cairo_region_t*)((L*)in->region.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_get_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_get_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_get_rectangle_sig* in = chk_cairo_region_get_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_region_get_rectangle((cairo_region_t*)((L*)in->region.arr)[0], (int)in->nth, (cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_region_is_empty(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_is_empty_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_is_empty_sig* in = chk_cairo_region_is_empty_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_region_is_empty((cairo_region_t*)((L*)in->region.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_contains_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_contains_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_contains_rectangle_sig* in = chk_cairo_region_contains_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_region_overlap_t r = cairo_region_contains_rectangle((cairo_region_t*)((L*)in->region.arr)[0], (cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_contains_point(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_contains_point_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_contains_point_sig* in = chk_cairo_region_contains_point_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_bool_t r = cairo_region_contains_point((cairo_region_t*)((L*)in->region.arr)[0], (int)in->x, (int)in->y);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_translate(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_translate_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_translate_sig* in = chk_cairo_region_translate_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_region_translate((cairo_region_t*)((L*)in->region.arr)[0], (int)in->dx, (int)in->dy);
 unref(xs); unref(x);
 return Kv();
 }

K Fcairo_region_subtract(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_subtract_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_subtract_sig* in = chk_cairo_region_subtract_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_subtract((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_region_t*)((L*)in->other.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_subtract_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_subtract_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_subtract_rectangle_sig* in = chk_cairo_region_subtract_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_subtract_rectangle((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_intersect(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_intersect_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_intersect_sig* in = chk_cairo_region_intersect_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_intersect((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_region_t*)((L*)in->other.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_intersect_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_intersect_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_intersect_rectangle_sig* in = chk_cairo_region_intersect_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_intersect_rectangle((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_union(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_union_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_union_sig* in = chk_cairo_region_union_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_union((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_region_t*)((L*)in->other.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_union_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_union_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_union_rectangle_sig* in = chk_cairo_region_union_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_union_rectangle((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_xor(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_xor_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_xor_sig* in = chk_cairo_region_xor_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_xor((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_region_t*)((L*)in->other.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_region_xor_rectangle(K x) {ref(x);
 K xs = ser2(Ki(1),x);
 if( TK(xs)!=9 || NK(xs) != SZ(cairo_region_xor_rectangle_sig) + 1 ) { unref(xs); unref(x); return 0; }
 cairo_region_xor_rectangle_sig* in = chk_cairo_region_xor_rectangle_sig((char*)xs);
 if (!in) { unref(xs); unref(x); return 0; }
 cairo_status_t r = cairo_region_xor_rectangle((cairo_region_t*)((L*)in->dst.arr)[0], (cairo_rectangle_int_t*)((L*)in->rectangle.arr)[0]);
 unref(xs); unref(x);
 return Ki(r);
 }

K Fcairo_debug_reset_static_data(K x) {
 cairo_debug_reset_static_data();
 unref(x);
 return Kv();
 }

