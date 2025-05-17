// Mod.
mod compiler;
mod codegen;
mod parser;
mod lexer;

// Require.
use std::error::Error;

fn main() -> Result<(), Box<dyn Error>> {
	/*
		HERE:
			argument parsing starts here.
			program [OPTIONS] <file..>	
	*/
	Ok(())
}

