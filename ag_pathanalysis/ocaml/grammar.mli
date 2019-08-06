type token =
  | ID of (string)
  | INT of (Big_int_Z.big_int)
  | STRING of (string)
  | COMMENT of (string)
  | LPAREN
  | RPAREN
  | LSQUARE
  | RSQUARE
  | COMMA
  | SEMI
  | EOF
  | COLON
  | CJMP
  | JMP
  | LABEL
  | ADDR
  | ASSERT
  | ASSUME
  | HALT
  | SPECIAL
  | LET
  | IN
  | UNKNOWN
  | WITH
  | TRUE
  | FALSE
  | EBIG
  | ELITTLE
  | IF
  | THEN
  | ELSE
  | DEFS
  | USES
  | PLUS
  | MINUS
  | DIVIDE
  | MOD
  | SMOD
  | TIMES
  | SDIVIDE
  | LSHIFT
  | RSHIFT
  | ARSHIFT
  | XOR
  | NEQ
  | SLT
  | SLE
  | AND
  | OR
  | CONCAT
  | EXTRACT
  | EQUAL
  | EQUALEQUAL
  | LT
  | LE
  | NOT
  | ASSIGN
  | GT
  | GE
  | SGT
  | SGE
  | AT
  | QUESTION
  | EXCLAMATION
  | LCURLY
  | RCURLY

val program :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.program
val expr :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.exp 
