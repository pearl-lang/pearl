pub enum Operation {
	None,
	Error,
	Version,
	Compile,
	Unknown
}

pub struct Args {
	pub operation: Operation,
}

pub fn argp(args: Vec<String>) -> Args {
	let mut operation: Operation = Operation::Unknown;

	if args.len() <= 1 {
		operation = Operation::None;
	}

	Args {
		operation
	}
}
