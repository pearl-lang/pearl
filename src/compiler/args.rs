// argument parsing.
pub enum Current {
	Operation,
	Source,
	Output,
	WarnLevel
}

pub enum Operation {
	Codegen, // Just drop .asm file.
	Compile, // Compile (just drop .o file).
	Build // Compile and link.
}

pub struct Options {
	pub operation: Operation,
	pub source: String,
	pub output: String,
	pub warnlvl: u8,
	// optimization: u8 // disable for now.
}

#[allow(non_snake_case, unreachable_patterns, unused_variables)] // damn clippy.
impl Options {
	pub fn new(ctx: Vec<String>) -> Self {
		let mut current: Current = Current::Source;

		let mut operation: Operation = Operation::Codegen;
		let mut source: String = String::new();
		let mut output: String = String::new();
		let mut warnlvl: u8 = 0;

		for i in ctx.iter().skip(1) {
			match i {
				sub if sub.starts_with("--") => {
					println!("Long: {}", i)	
				},
				sub if sub.starts_with("-") => {
					println!("Short: {}", i);
				},
				_ => {
					match current {
						ref Source => {
							source = i.clone();
						},
						ref Operation => {
							match i.to_ascii_lowercase().as_str() {
								"compile" => {
									operation = Operation::Compile;
								},
								"build" => {
									operation = Operation::Build;	
								},
								_ => {
									operation = Operation::Codegen;	
								}
							}
						},
						ref Output => {
							output = i.clone();							
						},
						ref WarnLevel => {
							if let Ok(n) = i.parse::<u8>() { 
								if n <= 9 { warnlvl = n };
							}	
						},
					}
				} 
			}
		}

		Self {
			operation: operation,
			source: source,
			output: output,
			warnlvl: warnlvl
		}
	}
}
