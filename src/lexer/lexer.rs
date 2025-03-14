use logos::Logos;

/*
	Tokens:
		require
		fun

		if
		elif // bir olayı yok düz else if ama yengenin adı elifse diye.
		else

		while
		case
		for
		in

		my
		our
		static

		#
		$
		{
		}
		(
		)
		[
		]
		//
		'
		"
		->
		<-
		>
		<
		>=
		=<
		==
		=
		;
		+
		-
		*
		,
*/

#[derive(Logos, Debug, PartialEq)]
#[logos(skip r"[ \t\n\f]+")]
pub enum Token {
	#[token("require")]
	Require,
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
	#[token("static")] // unmutable
	ReadOnly,

	#[token("#")]
	Sharp,
	#[token("$")] // <- 🤑
	Money,
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
	Multiplication,
	#[token(",")]
	Comma
}
