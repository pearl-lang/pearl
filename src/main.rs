mod codegen;
mod parser;
mod lexer;
mod utils;

use clap::Parser;
use utils::{ args::Args, read_lines::read_lines };

fn main() {
	let args = Args::parse();

	if let Ok(lines) = read_lines(args.file) {
		for l in lines.map_while(Result::ok) {
			println!("{l}");
		}
	}
    // println!("{}", args.file);
}
