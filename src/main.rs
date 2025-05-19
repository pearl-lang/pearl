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
		// kontroller yapılmalı, dosya uzantısı, dosya boyutu vb..
		let tokens: Vec<Token> = Token::tokenize_file(&opt.source);
	} else {
		err!(format!("File: {}, doesn't exists.", &opt.source));
	}

	Ok(())
}
