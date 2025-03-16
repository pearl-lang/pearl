use logos::Logos;

/*
	Tokens:
		require ebpf fun
		if elif else
		while case for in
		my our static
		# :: { } ( ) [ ] // ' " -> <- > < >= =< == = ; + - * / , .
*/

#[derive(Logos, Debug, PartialEq)]
#[logos(skip r"[ \t\n\f]+")]
pub enum Token<'a> {
	#[token("require")]
	Require,
	#[token("ebpf")]
	Ebpf,
	#[token("fun")]
	Function,

	#[token("if")]
	If,
	#[token("elif")]
	Elif,
	#[token("else")]
	Else,

	#[token("while")]
	While,
	#[token("case")]
	Case,
	#[token("for")]
	For,
	#[token("in")]
	In,

	#[token("my")]
	LocalVariable,
	#[token("our")]
	GlobalVariable,
	#[token("static")] // immutable
	ReadOnly,

	#[token("#")]
	Sharp,
	#[token("::")]
	Separate,
	#[token("{")]
	LeftCurlyBracet,
	#[token("}")]
	RightCurlyBracet,
	#[token("(")]
	LeftBracet,
	#[token(")")]
	RightBracet,
	#[token("[")]
	LeftSquareBracet,
	#[token("]")]
	RightSquareBracet,
	#[token("//")]
	Comment,
	#[token("'")]
	Quote,
	#[token("\"")]
	DoubleQuote,
	#[token("<-")]
	LeftArrow,
	#[token("->")]
	RightArrow,
	#[token(">")]
	GreaterThan,
	#[token("<")]
	SmallerThan,
	#[token(">=")]
	EqualOrGreaterThan,
	#[token("=<")]
	EqualOrSmallerThan,
	#[token("==")]
	Equal,
	#[token("=")]
	Assign,
	#[token(";")]
	Semicolon,
	#[token("+")]
	Plus,
	#[token("-")]
	Moins,
	#[token("*")]
	Asterix,
	#[token("/")]
	Slash,
	#[token("&")]
	And,
	#[token(",")]
	Comma,
	#[token(".")]
	Dot,

	#[regex(r"[0-9]+")]
	Int,
	#[regex(r"[0-9]+\.[0-9]+")]
	Float,
	#[regex(r"[a-zA-Z][a-zA-Z0-9]*")]
	Text(&'a str),
	#[regex(r#""([^"\\]|\\.)*""#, priority = 1)]
	String(&'a str),
}
