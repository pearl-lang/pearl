/*
	Tokens:
		require(7) ebpf(4) fun(3)
		if(2) elif(4) else(4)
		while(5) case(4) for(3) in(2)
		my(2) our(3) static(6)
		int(3) str(3) double(6) bool(4) uint(4)
		# :: { } ( ) [ ] // -> <- > < >= =< == = ; + - * / \ , .
*/
use crate::compiler::read_lines::read_lines;

// Reserved words that we use.
pub enum Word {
	If,
	In,
	My,
	Fun,
	For,
	Our,
	Int, // type
	Str, // type
	Ebpf,
	Elif,
	Else,
	Case,
	Bool, // type
	Uint, // type
	While,
	Static,
	Double, // type
	Require,
	Word(String)
}

// Reserved characters that we need to use.
pub enum Chars {
	HashTag,			// #
	DoubleTwoDot,		// ::
	LeftCurlyBracket,	// {
	RightCurlyBracket,	// }
	LeftSquareBracket,	// [
	RightSquareBracket,	// ]
	LeftBracket,		// (
	RightBracket,		// )
	Comment,			// //...EndOfline
	MultiCommentOpen,	// /*
	MultiCommentClose,	// */
	LeftArrow,			// <-
	RightArrow,			// ->
	Greater,			// >
	Smaller,			// <
	GreaterOrEqual,		// >=
	SmallerOrEqual,		// =<
	Equal,				// ==
	Assign,				// =
	Semicolon,			// ;
	Plus,				// +
	Minus,				// -
	Asterix,			// *
	Slash,				// /
	Comma,				// ,
	Dot,				// .
	Unknown(String)
}

pub enum CharType {
	Expression,
	Statement,
	Operation,	
}

pub struct Char {
	chartype: CharType,
	char: Chars	
}

pub enum Tokens {
	Word(Word),
	Number(String),	// it could be BigInt or something.
	String(String),
	Char(Char),
	EndOfLine		// \n
}

// Nesting.
pub enum NestingType {
	CurlyBracket,	// used for scope.
	SquareBracket,	// used for arrays.
	MultiComment	// used for multi commenting.
}

pub struct Nesting {
	ntype: NestingType,
	level: i64,	
}

// Token structure.
pub struct Token {
	token: Tokens,
	length: u16,
	reserved: bool,
	nesting: Option<Nesting>
}

// TODO: this should be next_token and position will be included.
pub fn tokenize(ctx: &str) -> Vec<Token> {
	let mut tokens: Vec<Token> = vec![];

	for ch in ctx.chars() {
		println!("{} == {}", ch, ch as u8);	// DEBUG
	}

	tokens
}

// Tokenizing.
impl Token {
	pub fn tokenize_file(filename: &str) -> Vec<Self> {
		let mut tokens: Vec<Self> = vec![];

		if let Ok(lines) = read_lines(&filename) {
		    for line in lines {
		        if let Ok(l) = line {
		            tokens.extend(tokenize(&l));
		        }
		    }
		}

		tokens.extend(vec![
		    Self {
		        token: Tokens::Number(String::from("1")),
		        length: 1,
		        reserved: false,
		        nesting: None,
		    }
		]);

		// println!("{}", tokens.len()); // size of the tokens vector.

		tokens
	}
}

