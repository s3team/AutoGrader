.NOTPARALLEL:
# Work around buggy Debian ocaml patch
# See http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=678577
export OCAML_COMPAT='c'

export BAP_DIR=$(CURDIR)/..

# Ignore warning about duplicate arch files.
# The arch file in libtrace is part of the trace pack.
export OCAMLFIND_IGNORE_DUPS_IN=$(CURDIR)

# We can't use $(CPP) here because the default (cc -E) won't work on
# .idl files.
export CAMLIDLFLAGS = -prepro cpp

export OCAMLMAKEFILE=OCamlMakefile
export LIBASMIR=../libasmir
export BIGINT=$(BAP_DIR)/zarith
export BATT=$(BAP_DIR)/batteries/_build/src
export OUNIT=$(BAP_DIR)/ounit/_build/src/
export PCRE=$(BAP_DIR)/pcre-ocaml/lib
export OCAMLGRAPH=$(BAP_DIR)/ocamlgraph
export LIBTRACE=$(BAP_DIR)/libtracewrap/libtrace/src/ocaml
export PIQIBUILDDIR=$(BAP_DIR)/libtracewrap/libtrace/piqi/piqi/build/lib/ocaml

include $(LIBASMIR)/makefile.inc
export SOLVER=$(BAP_DIR)/solvers
include $(SOLVER)/makefile.inc
-include ../../ocaml-proj/Makefile

ifeq (no,yes)
export LLVM_SRC = llvm_codegen.mli llvm_codegen.ml
export LLVM_PACKS =  .analysis .executionengine .target .scalar_opts .bitwriter
endif

#export LIB_PACK_NAME = bap

# common sources
export SOURCES = \
	debug.mli debug.ml \
	BatListFull.ml \
	worklist.mli worklist.ml \
	util.mli util.ml \
	big_int_convenience.ml \
	dominator.ml \
	djgraph.mli djgraph.ml \
	graphDataflow.mli graphDataflow.ml \
	type.mli type.ml \
	var.mli var.ml \
	arithmetic.ml \
	ast.ml \
	ssa.ml \
	var_temp.mli var_temp.ml \
	pp.ml \
	typecheck.mli typecheck.ml \
	piqi/stmt_piqi.ml piqi/stmt_piqi_ext.ml \
	piqi/ast_piqi.mli piqi/ast_piqi.ml \
	ast_convenience.ml \
	ssa_convenience.ml \
	cfg.mli cfg.ml \
	cfgDataflow.mli cfgDataflow.ml \
	ast_visitor.mli ast_visitor.ml \
	ssa_visitor.mli ssa_visitor.ml \
	ast_mapper.mli ast_mapper.ml \
	grammar_scope.ml \
	memory2array.mli memory2array.ml \
	flatten_mem.mli flatten_mem.ml \
	reachable.mli reachable.ml \
	prune_unreachable.mli prune_unreachable.ml \
	cfg_pp.ml \
	cfg_ast.mli cfg_ast.ml \
	checks.mli checks.ml \
	depgraphs.mli depgraphs.ml \
	cfg_ssa.mli cfg_ssa.ml \
	debug_snippets.ml \
	sccvn.mli sccvn.ml \
	deadcode.mli deadcode.ml \
	copy_prop.mli copy_prop.ml \
	ast_cond_simplify.mli ast_cond_simplify.ml \
	ssa_cond_simplify.mli ssa_cond_simplify.ml \
	ssa_simp_misc.ml \
	ssa_simp.ml \
	formulap.ml \
	stp.ml \
	smtlib1.ml \
	smtlib2.ml \
	libbfd.idl \
	libasmir.idl \
	disasm_i386.mli disasm_i386.ml \
	arch.mli arch.ml \
	disasm.ml \
	$(LLVM_SRC) \
	gcl.mli gcl.ml \
	wp.mli wp.ml \
	stp_grammar.mly stp_lexer.mll \
	cvc3_grammar.mly cvc3_lexer.mll \
	yices_grammar.mly yices_lexer.mll \
	smtexec.mli smtexec.ml \
	solver.mli solver.ml \
	asmir_vars.ml \
	asmir_consts.ml \
	asmir.mli asmir.ml \
	syscall_models.ml \
	hacks.ml \
	coalesce.mli coalesce.ml \
	vsa.ml \
	vsa_ssa.mli vsa_ssa.ml \
	vsa_ast.mli vsa_ast.ml \
	asmir_disasm.mli asmir_disasm.ml \
	func_boundary.mli func_boundary.ml \
	asmir_rdisasm.mli asmir_rdisasm.ml \
	switch_condition.mli switch_condition.ml \
	grammar_private_scope.ml \
	grammar.mly lexer.mll \
	parser.ml \
	tunegc.mli tunegc.ml \
	input.mli input.ml \
	to_c.ml \
	symbeval.ml symbeval_search.ml \
	structural_analysis.ml \
	steensgard.mli steensgard.ml \
	lnf.mli lnf.ml \
	lnf_ramalingam.mli lnf_ramalingam.ml \
	lnf_steensgard.mli lnf_steensgard.ml \
	lnf_havlak.mli lnf_havlak.ml \
	lnf_reduced_havlak.mli lnf_reduced_havlak.ml \
	lnf_sreedhar.mli lnf_sreedhar.ml \
	lnf_interface.mli lnf_interface.ml \
	unroll.mli unroll.ml \
	fwp.mli fwp.ml \
	ast_slice.ml \
	ssa_slice.ml \
	traces.ml \
	traces_surgical.ml \
	traces_backtaint.mli traces_backtaint.ml \
	traces_stream.mli traces_stream.ml \
	utils_common.ml \
	test_common.ml \
	template.ml \
	syscall_id.mli syscall_id.ml \
	vc.mli vc.ml \
	$(SOLVER_SOURCES) \
	$(PROJSOURCES) \

RESULT = bap

# Filter out the automatic piqi files
DOC_FILES := $(filter-out piqi/stmt_piqi%, $(filter %.mli, $(SOURCES)) $(filter %.ml, $(SOURCES)))


# ocamlfind packages required
export PACKS = bigarray str num unix camomile threads piqi.lib $(LLVM_PACKS)
export DOCPACKS = $(PACKS)
export YFLAGS = -v

export USE_CAMLP4 = yes

export CLIBS += $(SOLVER_CLIBS)
export OCAMLPATH = $(PIQIBUILDDIR)
export CFLAGS = -g
export CPPFLAGS = 
export LDFLAGS = $(LIBASMIR_LDFLAGS) $(SOLVER_LDFLAGS) 
export OCAMLMKLIB_FLAGS = $(LDFLAGS)
export PPFLAGS = $(SOLVER_PPFLAGS) 
export INCDIRS = $(BIGINT) $(BATT) $(OUNIT) $(PCRE) $(OCAMLGRAPH) $(LIBTRACE) $(LIBTRACE)/piqi $(PROJINCDIRS)
export LIBS = zarith batteries oUnit graph pcre libtrace $(PROJLIBS)
export RESULTDEPS = $(LIBASMIR)/src/libasmir.a $(LIBTRACE)/libtrace.cmxa
export LIBDIRS = $(LIBASMIR)/src
export LIBDIRS += $(SOLVER_LIBDIRS) $(LIBTRACE)

export OCAMLLDFLAGS = -thread # just for make top
export OCAMLFLAGS = -thread -warn-error Aelz -annot $(PROJOCAMLFLAGS) # -for-pack Bap #-w A
# merge everything but descriptions.
export OCAMLDOCFLAGS = -m avlsoper -sort

all: dcl dncl

bap_lib_doc: all htdoc

docall: all htdoc ladoc psdoc pdfdoc

tags: TAGS

TAGS: $(SOURCES)
	-otags $^

runtop:	top
	./bap.top -I $(BIGINT) -I $(BATT)

.PHONY: debug
debug:
	@echo ocamldebug -I $(BIGINT) -I $(BATT) -I $(BAP_DIR)/ocaml -I $(BAP_DIR)/utils

libbfd.idl : bfdarch.idl

bfdarch.idl:
	echo '#include "config.h"' > /tmp/f.c
	echo '#include <bfd.h>' >> /tmp/f.c
	echo 'typedef unsigned long machine_t;' >> /tmp/f.c
	echo 'const machine_t MACH_i386_i386 = bfd_mach_i386_i386;' >> /tmp/f.c
	echo 'const machine_t MACH_i386_x86_64 = bfd_mach_x86_64;' >> /tmp/f.c
	$(CPP) $(CPPFLAGS) -I$(LIBASMIR) /tmp/f.c | awk 'BEGIN { go=0; } /^enum bfd_architecture$$/ { go=1; } \
		go && $$0 != "" { print; } \
		/machine_t/ { print; } \
		/};$$/ { go=0; }' > $@

# You may also tell "make" at the command-line what kind of target to
# produce (e.g. "make nc").  Here all the possibilities with shortcuts
# between parenthesis:
# 
#    * byte-code                     (bc)
#    * byte-code-nolink              (bcnl)   - no linking stage
#    * byte-code-library             (bcl)
#    * native-code                   (nc)
#    * native-code-nolink            (ncnl)   - no linking stage
#    * native-code-library           (ncl)
#    * debug-code                    (dc)
#    * debug-code-nolink             (dcnl)   - no linking stage
#    * debug-code-library            (dcl)
#    * profiling-byte-code           (pbc)
#    * profiling-byte-code-library   (pbcl)
#    * profiling-native-code         (pnc)
#    * profiling-native-code-library (pncl)
#    * byte-code-dll                 (bcd)
#    * native-code-dll               (ncd)
#    * pack-byte-code              (pabc)
#    * pack-native-code            (panc)
#    * toplevel interpreter          (top)
#    * subprjs



include $(OCAMLMAKEFILE)

bap.dot: $(DOC_FILES)
	 ocamlfind ocamldoc -package str,ocamlgraph,unix -dot -o bap.dot -m avlsoper $(DOC_FILES)
