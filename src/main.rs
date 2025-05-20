mod compiler;
mod codegen;
mod parser;
mod lexer;

use std::{env, fs};
use std::path::Path;
use std::error::Error;
use compiler::args::Options;
use lexer::lexer::Token;

// TODO: Read file, chunk as chunk, 1024byte is good for starting.
fn main() -> Result<(), Box<dyn Error>> {
	let opt: Options = Options::new(env::args().collect());

	if Path::new(&opt.source).exists() {
		// MAX 1024mb of text(UTF-8) file. Please don't write war and peace as text here.
		if fs::metadata(&opt.source)?.len() as f64 / 1024.0 / 1024.0 <= 1024.0  {
			// if opt.source.ends_with(".pearl") {
				let tokens: Vec<Token> = Token::tokenize(&fs::read_to_string(&opt.source)?);
			// } else {
				// err!("Not a Pearl file. Pearl files must be ended with '.prl'");
			// }
		} else {
			err!("Max file size(1024mb) limit exceeded.");
		}
	} else {
		let ferr = if opt.source.is_empty() {
			format!("None")
		} else {
			opt.source
		};

		err!(format!("File: '{}', doesn't exists.", ferr));
	}

	Ok(())
}
