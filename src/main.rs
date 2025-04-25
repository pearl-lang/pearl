// Sub files.
mod compiler;
mod codegen;
mod parser;
mod lexer;

// Required things.
use clap::{CommandFactory,  Parser };
use std::error::Error;

// Args.
#[derive(Parser, Debug)]
#[command(version, about = "pearlc", long_about = "Pearl language bootstrap compiler.")]
struct Args {
    file: Vec<String>,
}

fn main() -> Result<(), Box<dyn Error>> {
	let args = Args::parse();

	if args.file.len() <= 0 {
		err!(format!("Need's file(s) as argument FILE.. please type '{} --help' for more information.", Args::command()));
	}

	Ok(())
}

