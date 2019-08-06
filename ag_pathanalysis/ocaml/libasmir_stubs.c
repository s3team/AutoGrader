/* File generated from libasmir.idl */

#include <stddef.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>
#ifdef Custom_tag
#include <caml/custom.h>
#include <caml/bigarray.h>
#endif
#include <caml/camlidlruntime.h>


#include "libasmir.h"

extern void camlidl_ml2c_libbfd_address_t(value, address_t *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_address_t(address_t *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_bfd_size_type(value, bfd_size_type *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_bfd_size_type(bfd_size_type *, camlidl_ctx _ctx);

extern int camlidl_ml2c_libbfd_enum_bfd_architecture(value);
extern value camlidl_c2ml_libbfd_enum_bfd_architecture(int);

extern int camlidl_transl_table_libbfd_enum_bfd_architecture[];

extern void camlidl_ml2c_libbfd_machine_t(value, machine_t *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_machine_t(machine_t *, camlidl_ctx _ctx);

extern int camlidl_ml2c_libbfd_enum_bfd_flavour(value);
extern value camlidl_c2ml_libbfd_enum_bfd_flavour(int);

extern int camlidl_transl_table_libbfd_enum_bfd_flavour[];

extern void camlidl_ml2c_libbfd_struct_bfd(value, struct bfd *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_struct_bfd(struct bfd *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_bfdp(value, bfdp *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_bfdp(bfdp *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_struct_bfd_section(value, struct bfd_section *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_struct_bfd_section(struct bfd_section *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_section_ptr(value, section_ptr *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_section_ptr(section_ptr *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_struct_notreally(value, struct notreally *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_struct_notreally(struct notreally *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_struct_bfd_symbol(value, struct bfd_symbol *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_struct_bfd_symbol(struct bfd_symbol *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_asymbol(value, asymbol *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_asymbol(asymbol *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_bfd_boolean(value, bfd_boolean *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_bfd_boolean(bfd_boolean *, camlidl_ctx _ctx);

extern void camlidl_ml2c_libbfd_file_ptr(value, file_ptr *, camlidl_ctx _ctx);
extern value camlidl_c2ml_libbfd_file_ptr(file_ptr *, camlidl_ctx _ctx);

void camlidl_ml2c_libasmir_asm_program_t(value _v1, asm_program_t * _c2, camlidl_ctx _ctx)
{
  *_c2 = *((asm_program_t *) Bp_val(_v1));
}

value camlidl_c2ml_libasmir_asm_program_t(asm_program_t * _c2, camlidl_ctx _ctx)
{
value _v1;
  _v1 = camlidl_alloc((sizeof(asm_program_t) + sizeof(value) - 1) / sizeof(value), Abstract_tag);
  *((asm_program_t *) Bp_val(_v1)) = *_c2;
  return _v1;
}

void camlidl_ml2c_libasmir_trace_frames_t(value _v1, trace_frames_t * _c2, camlidl_ctx _ctx)
{
  *_c2 = *((trace_frames_t *) Bp_val(_v1));
}

value camlidl_c2ml_libasmir_trace_frames_t(trace_frames_t * _c2, camlidl_ctx _ctx)
{
value _v1;
  _v1 = camlidl_alloc((sizeof(trace_frames_t) + sizeof(value) - 1) / sizeof(value), Abstract_tag);
  *((trace_frames_t *) Bp_val(_v1)) = *_c2;
  return _v1;
}

void camlidl_ml2c_libasmir_trace_frame_t(value _v1, trace_frame_t * _c2, camlidl_ctx _ctx)
{
  *_c2 = *((trace_frame_t *) Bp_val(_v1));
}

value camlidl_c2ml_libasmir_trace_frame_t(trace_frame_t * _c2, camlidl_ctx _ctx)
{
value _v1;
  _v1 = camlidl_alloc((sizeof(trace_frame_t) + sizeof(value) - 1) / sizeof(value), Abstract_tag);
  *((trace_frame_t *) Bp_val(_v1)) = *_c2;
  return _v1;
}

void camlidl_ml2c_libasmir_threadid_t(value _v1, threadid_t * _c2, camlidl_ctx _ctx)
{
  (*_c2) = Int_val(_v1);
}

value camlidl_c2ml_libasmir_threadid_t(threadid_t * _c2, camlidl_ctx _ctx)
{
value _v1;
  _v1 = Val_int((*_c2));
  return _v1;
}

     void null_check(void *ptr) {         if (ptr == NULL) {             caml_failwith("Unexpected NULL encountered.");         }     } 
value camlidl_libasmir_asmir_get_symbols(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  long *num; /*out*/
  asymbol *_res;
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  long _c1;
  mlsize_t _c2;
  value _v3;
  value _vresult;
  value _vres[2] = { 0, 0, };

  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  num = &_c1;
  _res = asmir_get_symbols(prog, num);
  Begin_roots_block(_vres, 2)
    _vres[0] = camlidl_alloc(*num, 0);
    Begin_root(_vres[0])
      for (_c2 = 0; _c2 < *num; _c2++) {
        _v3 = camlidl_c2ml_libbfd_asymbol(&_res[_c2], _ctx);
        modify(&Field(_vres[0], _c2), _v3);
      }
    End_roots()
    _vres[1] = Val_long(*num);
    _vresult = camlidl_alloc_small(2, 0);
    Field(_vresult, 0) = _vres[0];
    Field(_vresult, 1) = _vres[1];
  End_roots()
  camlidl_free(_ctx);
  return _vresult;
}

value camlidl_libasmir_asmir_get_all_symbols(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  long *num; /*out*/
  asymbol *_res;
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  long _c1;
  mlsize_t _c2;
  value _v3;
  value _vresult;
  value _vres[2] = { 0, 0, };

  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  num = &_c1;
  _res = asmir_get_all_symbols(prog, num);
  Begin_roots_block(_vres, 2)
    _vres[0] = camlidl_alloc(*num, 0);
    Begin_root(_vres[0])
      for (_c2 = 0; _c2 < *num; _c2++) {
        _v3 = camlidl_c2ml_libbfd_asymbol(&_res[_c2], _ctx);
        modify(&Field(_vres[0], _c2), _v3);
      }
    End_roots()
    _vres[1] = Val_long(*num);
    _vresult = camlidl_alloc_small(2, 0);
    Field(_vresult, 0) = _vres[0];
    Field(_vresult, 1) = _vres[1];
  End_roots()
  camlidl_free(_ctx);
  return _vresult;
}

value camlidl_libasmir_asmir_get_dynsymbols(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  long *num; /*out*/
  asymbol *_res;
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  long _c1;
  mlsize_t _c2;
  value _v3;
  value _vresult;
  value _vres[2] = { 0, 0, };

  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  num = &_c1;
  _res = asmir_get_dynsymbols(prog, num);
  Begin_roots_block(_vres, 2)
    _vres[0] = camlidl_alloc(*num, 0);
    Begin_root(_vres[0])
      for (_c2 = 0; _c2 < *num; _c2++) {
        _v3 = camlidl_c2ml_libbfd_asymbol(&_res[_c2], _ctx);
        modify(&Field(_vres[0], _c2), _v3);
      }
    End_roots()
    _vres[1] = Val_long(*num);
    _vresult = camlidl_alloc_small(2, 0);
    Field(_vresult, 0) = _vres[0];
    Field(_vresult, 1) = _vres[1];
  End_roots()
  camlidl_free(_ctx);
  return _vresult;
}

value camlidl_libasmir_asmir_get_all_sections(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  long *num; /*out*/
  section_ptr *_res;
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  long _c1;
  mlsize_t _c2;
  value _v3;
  value _vresult;
  value _vres[2] = { 0, 0, };

  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  num = &_c1;
  _res = asmir_get_all_sections(prog, num);
  Begin_roots_block(_vres, 2)
    _vres[0] = camlidl_alloc(*num, 0);
    Begin_root(_vres[0])
      for (_c2 = 0; _c2 < *num; _c2++) {
        _v3 = camlidl_c2ml_libbfd_section_ptr(&_res[_c2], _ctx);
        modify(&Field(_vres[0], _c2), _v3);
      }
    End_roots()
    _vres[1] = Val_long(*num);
    _vresult = camlidl_alloc_small(2, 0);
    Field(_vresult, 0) = _vres[0];
    Field(_vresult, 1) = _vres[1];
  End_roots()
  camlidl_free(_ctx);
  return _vresult;
}

value camlidl_libasmir_asmir_open_file(
	value _v_filename,
	value _v_base,
	value _v_target)
{
  char *filename; /*in*/
  address_t base; /*in*/
  char *target; /*in*/
  asm_program_t _res;
  value _v1;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  filename = String_val(_v_filename);
  camlidl_ml2c_libbfd_address_t(_v_base, &base, _ctx);
  if (_v_target == Val_int(0)) {
    target = NULL;
  } else {
    _v1 = Field(_v_target, 0);
    target = String_val(_v1);
  }
  _res = asmir_open_file(filename, base, target);
  null_check(_res);
  _vres = camlidl_c2ml_libasmir_asm_program_t(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_close(
	value _v_p)
{
  asm_program_t p; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_p, &p, _ctx);
  asmir_close(p);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_libasmir_asmir_string_of_insn(
	value _v_prog,
	value _v_inst)
{
  asm_program_t prog; /*in*/
  address_t inst; /*in*/
  char *_res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  camlidl_ml2c_libbfd_address_t(_v_inst, &inst, _ctx);
  _res = asmir_string_of_insn(prog, inst);
  _vres = copy_string(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_asmp_arch(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  _res = asmir_get_asmp_arch(prog);
  _vres = camlidl_c2ml_libbfd_enum_bfd_architecture(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_asmp_mach(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  _res = asmir_get_asmp_mach(prog);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_base_address(
	value _v_prog)
{
  asm_program_t prog; /*in*/
  address_t _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_prog, &prog, _ctx);
  _res = asmir_get_base_address(prog);
  _vres = camlidl_c2ml_libbfd_address_t(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_sec_startaddr(
	value _v_p,
	value _v_sectionname)
{
  asm_program_t p; /*in*/
  char const *sectionname; /*in*/
  address_t _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_p, &p, _ctx);
  sectionname = String_val(_v_sectionname);
  _res = asmir_get_sec_startaddr(p, sectionname);
  _vres = camlidl_c2ml_libbfd_address_t(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_sec_endaddr(
	value _v_p,
	value _v_sectionname)
{
  asm_program_t p; /*in*/
  char const *sectionname; /*in*/
  address_t _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_p, &p, _ctx);
  sectionname = String_val(_v_sectionname);
  _res = asmir_get_sec_endaddr(p, sectionname);
  _vres = camlidl_c2ml_libbfd_address_t(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_start_addr(
	value _v_p)
{
  asm_program_t p; /*in*/
  address_t _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_p, &p, _ctx);
  _res = asmir_get_start_addr(p);
  _vres = camlidl_c2ml_libbfd_address_t(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_instr_length(
	value _v_p,
	value _v_addr)
{
  asm_program_t p; /*in*/
  address_t addr; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_p, &p, _ctx);
  camlidl_ml2c_libbfd_address_t(_v_addr, &addr, _ctx);
  _res = asmir_get_instr_length(p, addr);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_asmir_get_bfd(
	value _v_p)
{
  asm_program_t p; /*in*/
  bfdp _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_libasmir_asm_program_t(_v_p, &p, _ctx);
  _res = asmir_get_bfd(p);
  _vres = camlidl_c2ml_libbfd_bfdp(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_byte_insn_to_asmp(
	value _v_arch,
	value _v_mach,
	value _v_addr,
	value _v_bb_bytes)
{
  int arch; /*in*/
  unsigned long mach; /*in*/
  address_t addr; /*in*/
  char *bb_bytes; /*in*/
  int len; /*in*/
  asm_program_t _res;
  mlsize_t _c1;
  mlsize_t _c2;
  value _v3;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  arch = camlidl_ml2c_libbfd_enum_bfd_architecture(_v_arch);
  mach = Long_val(_v_mach);
  camlidl_ml2c_libbfd_address_t(_v_addr, &addr, _ctx);
  _c1 = Wosize_val(_v_bb_bytes);
  bb_bytes = camlidl_malloc(_c1 * sizeof(char ), _ctx);
  for (_c2 = 0; _c2 < _c1; _c2++) {
    _v3 = Field(_v_bb_bytes, _c2);
    bb_bytes[_c2] = Int_val(_v3);
  }
  len = _c1;
  _res = byte_insn_to_asmp(arch, mach, addr, bb_bytes, len);
  null_check(_res);
  _vres = camlidl_c2ml_libasmir_asm_program_t(&_res, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_libasmir_fake_assert(value _unit)
{
  fake_assert();
  return Val_unit;
}

