use clap::Parser;

#[derive(Parser, Debug)]
#[command(version, about = "pearlc", long_about = "Pearl language bootstrap compiler.")]
pub struct Args {
    /// Name of the person to greet
    pub file: String,
}
