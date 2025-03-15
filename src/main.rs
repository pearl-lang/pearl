mod compiler;
mod codegen;
mod parser;
mod lexer;

use clap::Parser;
use logos::Logos;
use compiler::{ args::Args, read_lines::read_lines };
use lexer::lexer::Token;

fn main() {
	let args = Args::parse();

	if let Ok(lines) = read_lines(args.file) {
		for line in lines.map_while(Result::ok) {
			for result in Token::lexer(&line) {
			    match result {
			        Ok(token) => println!("{:#?}", token),
			        Err(e) => panic!("some error occurred: {:?}", e),
			    }
			}
		}
	}
}
