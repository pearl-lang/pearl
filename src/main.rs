mod compiler;
mod codegen;
mod parser;
mod lexer;

use clap::Parser;
use logos::Logos;
use compiler::args::Args;
use lexer::lexer::Token;
use std::fs::read_to_string;

fn main() {
	let args = Args::parse();

	let ctx = read_to_string(args.file).expect("Should have been able to read the file");
	for res in Token::lexer(&ctx) {
		match res {
			Ok(token) => println!("{:#?}", token),
			// Err(e) => eprintln!("some error occurred {:?}", e)
			Err(e) => panic!("some error occurred {:?}", e)
		}
	}		
}
