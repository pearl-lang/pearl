#ifndef TOKENS_H
#define TOKENS_H

/* Pearl specs */
#define TKN_OBJECT  "object"
#define TKN_REQUIRE "require"
#define TKN_EBPF    "ebpf"
#define TKN_FUNC    "fun"
// variable assignments
#define TKN_DEFINE  "define"
#define TKN_DECLARE "declare"
#define TKN_SET     "set"
// Built-in routines(will call when runtime)
#define TKN_ECHO    "echo"
#define TKN_TYPE    "type"   // Return data type.

/* Auto data types */
#define TKN_BOOL    "bool"   // Bool type
#define TKN_INT     "int"    // Auto int
#define TKN_UINT    "uint"   // Auto uint
#define TKN_FLOAT   "float"  // Auto float
#define TKN_STRING  "String" // String literal declaration

/* Separated data types */
#define TKN_I8		"i8"
#define TKN_I16     "i16"
#define TKN_I32     "i32"
#define TKN_U8      "u8"
#define TKN_U16     "u16"
#define TKN_U32     "u32"

/* Logic operations */
#define TKN_IF      "if"
#define TKN_ELSE    "else"
#define TKN_WHILE   "while"
#define TKN_FOR     "for"
#define TKN_CASE    "case"

/* Value declarations */
#define TKN_TRUE    "true"   // zero
#define TKN_FALSE   "false"  // non-zero(1)

/* Special characters */
#define TKN_DOT        "."
#define TKN_COMM       ","
#define TKN_SEMICOL    ";"
#define TKN_ASTRX      "*"
#define TKN_SINGLE_AND "&"
#define TKN_POURCENT   "%"
#define TKN_MOINS      "-"
#define TKN_PLUS       "+"
#define TKN_QMARK      "?"
#define TKN_EQUAL      "="
#define TKN_GREATER    ">"
#define TKN_SMALLER    "<"
#define TKN_HASH       "#"
#define TKN_LEFT_PAR   "(" // Left parenthese
#define TKN_RIGHT_PAR  ")" // Right paranthese
#define TKN_LEFT_BRC   "{" // Left bracket
#define TKN_RIGHT_BRC  "}" // Right bracket
#define TKN_LEFT_SBRC  "[" // Left square bracket
#define TKN_RIGHT_SBRC "]" // Right square bracket
#define TKN_SLASH      "/"
#define TKN_BACK_SLASH "\\"

/* Data types */
#define IS_NIL      0 // null
#define IS_NUM      1 // numbre(int,uint,float)
#define IS_STR      2 // "hello, this is pearl!"
#define IS_BOOL     3 // true
#define IS_WORD     4 // any word with out whitespaces.

// File status
#define FILE_EOF    0
#define FILE_EOL    1
#define FILE_RERR   3 // File Read Error

#endif // TOKENS_H
