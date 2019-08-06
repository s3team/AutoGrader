input.cmo: typecheck.cmi parser.cmo grammar_private_scope.cmo \
    big_int_convenience.cmo /home/bambool/loop/ocaml/../zarith/big_int_Z.cmi \
    BatListFull.cmo asmir_rdisasm.cmi asmir.cmi input.cmi
input.cmx: typecheck.cmx parser.cmx grammar_private_scope.cmx \
    big_int_convenience.cmx /home/bambool/loop/ocaml/../zarith/big_int_Z.cmx \
    BatListFull.cmx asmir_rdisasm.cmx asmir.cmx input.cmi
