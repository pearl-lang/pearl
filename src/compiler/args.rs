// argument parsing.
pub enum Operation {
	Codegen, // Just drop .asm file.
	Compile, // Compile (just drop .o file).
	Build // Compile and link.
}

pub struct Options {
	operation: Operation,
	source: String,
	output: String,
	warnlvl: u8,
	// optimization: u8 // disable for now.
}

impl Options {
	pub fn new(ctx: Vec<String>) -> Self {
		Self {
			operation: Operation::Codegen,
			source: String::from(""),
			output: String::from(""),
			warnlvl: 0
		}
	}
}
