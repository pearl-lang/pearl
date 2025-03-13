use logos::Logos;

/*
	Tokens:
		require
		fonk

		if
		elif // bir olayı yok düz else if ama yengenin adı elifse diye.
		else

		while
		case
		for
		in

		my
		our

		#
		$
		{
		}
		(
		)
		[
		]
		//
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
enum Token {
	#[token("require")]
	Require,
	#[token("fonk")]
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
	My,
	#[token("our")]
	Our,

	
}
