// ., +, ",", -, \0, ;, :, (, ), {, }, 
typedef enum {
	DOT,
	PLUS,
	COMMA,
	MOINS,
	NULLBYTE,
	SEMICOLON,
	DOUBLEDOT,
	LPARENTHESES,
	RPARENTHESES,
	LBRACKET,
	RBRACKET,
} Tokens;

struct lexinfo {
	Tokens,
	char element,
};

