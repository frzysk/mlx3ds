#!/bin/sh

# Use the norminette but without all these rules that make coding harder.

norminette | grep -v \
"INVALID_HEADER
VAR_DECL_START_FUNC
EMPTY_LINE_FUNCTION
TOO_MANY_ARGS
TOO_MANY_FUNCS
TOO_MANY_LINES
PREPROC_CONSTANT
MACRO_FUNC_FORBIDDEN
GLOBAL_VAR_DETECTED
WRONG_SCOPE_COMMENT
MULT_DECL_LINE
GOTO_FBIDDEN
LABEL_FBIDDEN
TERNARY_FBIDDEN"
