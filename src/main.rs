mod compiler;
mod codegen;
mod parser;
mod lexer;

use std::env;
use std::error::Error;
use compiler::args::Options;

fn main() -> Result<(), Box<dyn Error>> {
	let opt: Options = Options::new(env::args().collect());

	Ok(())
}
