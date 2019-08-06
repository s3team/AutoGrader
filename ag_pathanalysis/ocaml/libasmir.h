/* File generated from libasmir.idl */

#ifndef _CAMLIDL_LIBASMIR_H
#define _CAMLIDL_LIBASMIR_H

#ifdef __cplusplus
#define _CAMLIDL_EXTERN_C extern "C"
#else
#define _CAMLIDL_EXTERN_C extern
#endif

#ifdef _WIN32
#pragma pack(push,8) /* necessary for COM interfaces */
#endif

#include "libbfd.h"
typedef void *asm_program_t;

typedef void *trace_frames_t;

typedef void *trace_frame_t;

typedef int threadid_t;

_CAMLIDL_EXTERN_C asymbol *asmir_get_symbols(/*in*/ asm_program_t prog, /*out*/ long *num);

_CAMLIDL_EXTERN_C asymbol *asmir_get_all_symbols(/*in*/ asm_program_t prog, /*out*/ long *num);

_CAMLIDL_EXTERN_C asymbol *asmir_get_dynsymbols(/*in*/ asm_program_t prog, /*out*/ long *num);

_CAMLIDL_EXTERN_C section_ptr *asmir_get_all_sections(/*in*/ asm_program_t prog, /*out*/ long *num);

_CAMLIDL_EXTERN_C asm_program_t asmir_open_file(/*in*/ char *filename, /*in*/ address_t base, /*in*/ char *target);

_CAMLIDL_EXTERN_C void asmir_close(/*in*/ asm_program_t p);

_CAMLIDL_EXTERN_C char *asmir_string_of_insn(/*in*/ asm_program_t prog, /*in*/ address_t inst);

_CAMLIDL_EXTERN_C int asmir_get_asmp_arch(/*in*/ asm_program_t prog);

_CAMLIDL_EXTERN_C unsigned long asmir_get_asmp_mach(/*in*/ asm_program_t prog);

_CAMLIDL_EXTERN_C address_t asmir_get_base_address(/*in*/ asm_program_t prog);

_CAMLIDL_EXTERN_C address_t asmir_get_sec_startaddr(/*in*/ asm_program_t p, /*in*/ char const *sectionname);

_CAMLIDL_EXTERN_C address_t asmir_get_sec_endaddr(/*in*/ asm_program_t p, /*in*/ char const *sectionname);

_CAMLIDL_EXTERN_C address_t asmir_get_start_addr(/*in*/ asm_program_t p);

_CAMLIDL_EXTERN_C int asmir_get_instr_length(/*in*/ asm_program_t p, /*in*/ address_t addr);

_CAMLIDL_EXTERN_C bfdp asmir_get_bfd(/*in*/ asm_program_t p);

_CAMLIDL_EXTERN_C asm_program_t byte_insn_to_asmp(/*in*/ int arch, /*in*/ unsigned long mach, /*in*/ address_t addr, /*in*/ char *bb_bytes, /*in*/ int len);

_CAMLIDL_EXTERN_C void fake_assert(void);

#ifdef _WIN32
#pragma pack(pop)
#endif


#endif /* !_CAMLIDL_LIBASMIR_H */
