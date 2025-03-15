use clap::Parser;

#[derive(Parser, Debug)]
#[command(version, about = "pearlc", long_about = "Pearl language bootstrap compiler.")]
pub struct Args {
    pub file: String,
}
