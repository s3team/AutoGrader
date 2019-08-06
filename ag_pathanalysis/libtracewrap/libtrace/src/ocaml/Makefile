OCAMLMAKEFILE = ./OCamlMakefile

ROOTDIR = /home/bambool/loop/libtracewrap/libtrace
PIQIBUILDDIR = $(ROOTDIR)/piqi/piqi/build/lib/ocaml
BATT = /home/bambool/loop/batteries/_build/src
#BATT = $(ROOTDIR)/batteries/_build/src

export OCAMLPATH = $(PIQIBUILDDIR)

# We can't use $(CPP) here because the default (cc -E) won't work on
# .idl files.
export CAMLIDLFLAGS = -prepro cpp

export LIB_PACK_NAME = trace

INCDIRS += 

PACKS = piqi.lib

SOURCES = piqi/frame_piqi.ml \
	  piqi/frame_piqi_ext.ml \
	  arch.idl \
	  trace_container.mli \
	  trace_container.ml
RESULT  = libtrace

INCDIRS += $(BATT)
LIBS += batteries

all:
	$(MAKE) ncl
	$(MAKE) dcl

tags:
	-

include $(OCAMLMAKEFILE)
