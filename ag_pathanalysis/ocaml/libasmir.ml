(* File generated from libasmir.idl *)

type asm_program_t
and trace_frames_t
and trace_frame_t
and threadid_t = int

external asmir_get_symbols : asm_program_t -> Libbfd.asymbol array * int
	= "camlidl_libasmir_asmir_get_symbols"

external asmir_get_all_symbols : asm_program_t -> Libbfd.asymbol array * int
	= "camlidl_libasmir_asmir_get_all_symbols"

external asmir_get_dynsymbols : asm_program_t -> Libbfd.asymbol array * int
	= "camlidl_libasmir_asmir_get_dynsymbols"

external asmir_get_all_sections : asm_program_t -> Libbfd.section_ptr array * int
	= "camlidl_libasmir_asmir_get_all_sections"

external asmir_open_file : string -> Libbfd.address_t -> string option -> asm_program_t
	= "camlidl_libasmir_asmir_open_file"

external asmir_close : asm_program_t -> unit
	= "camlidl_libasmir_asmir_close"

external asmir_string_of_insn : asm_program_t -> Libbfd.address_t -> string
	= "camlidl_libasmir_asmir_string_of_insn"

external asmir_get_asmp_arch : asm_program_t -> Libbfd.bfd_architecture
	= "camlidl_libasmir_asmir_get_asmp_arch"

external asmir_get_asmp_mach : asm_program_t -> int
	= "camlidl_libasmir_asmir_get_asmp_mach"

external asmir_get_base_address : asm_program_t -> Libbfd.address_t
	= "camlidl_libasmir_asmir_get_base_address"

external asmir_get_sec_startaddr : asm_program_t -> string -> Libbfd.address_t
	= "camlidl_libasmir_asmir_get_sec_startaddr"

external asmir_get_sec_endaddr : asm_program_t -> string -> Libbfd.address_t
	= "camlidl_libasmir_asmir_get_sec_endaddr"

external asmir_get_start_addr : asm_program_t -> Libbfd.address_t
	= "camlidl_libasmir_asmir_get_start_addr"

external asmir_get_instr_length : asm_program_t -> Libbfd.address_t -> int
	= "camlidl_libasmir_asmir_get_instr_length"

external asmir_get_bfd : asm_program_t -> Libbfd.bfdp
	= "camlidl_libasmir_asmir_get_bfd"

external byte_insn_to_asmp : Libbfd.bfd_architecture -> int -> Libbfd.address_t -> char array -> asm_program_t
	= "camlidl_libasmir_byte_insn_to_asmp"

external fake_assert : unit -> unit
	= "camlidl_libasmir_fake_assert"

