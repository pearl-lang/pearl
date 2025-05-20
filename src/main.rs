mod compiler;
mod codegen;
mod parser;
mod lexer;

use std::env;
use std::path::Path;
use std::error::Error;
use compiler::args::Options;
use lexer::lexer::Token;

fn main() -> Result<(), Box<dyn Error>> {
	let opt: Options = Options::new(env::args().collect());

	if Path::new(&opt.source).exists() {
		// TODO: add tests for lexer/lexer.rs, check controls like is file end's with..?
		let tokens: Vec<Token> = Token::tokenize(&opt.source);
	} else {
		let ferr = if opt.source.is_empty() {
			format!("None")
		} else {
			opt.source
		};

		err!(format!("File: {}, doesn't exists.", ferr));
	}

	Ok(())
}
