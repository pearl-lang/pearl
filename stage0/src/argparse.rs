pub enum Operation {
	None,
	Error,
	Version,
	Compile,
	Unknown
}

pub struct Args {
	pub operation: Operation,
	pub base: String,
	pub options: Option<Vec<Opt>>
}

pub enum Opts {
	Unknown, // an unknown parameter, it gonna be error
	Output,  // --output, -o: last parameter
} 

pub struct Opt {
	pub opt:          Opts, // option type like '--output' is Output
	pub long:         bool, // false is short
	pub iterable:     bool, // when is short and iterable like -abc..
	pub is_param_req: bool, // is any parameter required?
	pub params:       Option<Vec<String>>
}

trait OptArg {
	fn parse(ctx: &str, args: Vec<String>) -> Self;
	fn identify(_par: &str, _is_long: bool) -> Opts;
	fn is_iterable(_opt: &Opts) -> bool;
	fn is_param_req(_opt: &Opts) -> bool;
	fn is_long(_par: &str) -> bool;
	fn get_params_for(_opt: &Opts, _args: Vec<String>) -> Option<Vec<String>>;
}

impl OptArg for Opt {
	fn parse(ctx: &str, args: Vec<String>) -> Self {
		let long: bool = Self::is_long(ctx);
		let opt: Opts = Self::identify(ctx, long);
		let iterable: bool = Self::is_iterable(&opt); 
		let is_param_req: bool = Self::is_param_req(&opt);
		let params: Option<Vec<String>> = Self::get_params_for(&opt, args);

		Self {
			opt,
			long,
			iterable,
			is_param_req,
			params
		}
	}

	fn identify(_par: &str, _is_long: bool) -> Opts {
		Opts::Unknown
	}

	fn is_iterable(_opt: &Opts) -> bool {
		true
	}

	fn is_param_req(_opt: &Opts) -> bool {
		true
	}

	fn is_long(_par: &str) -> bool {
		true
	}

	fn get_params_for(_opt: &Opts, _args: Vec<String>) -> Option<Vec<String>> {
		let params: Option<Vec<String>> = None;

		params
	}
}

pub fn argp(args: Vec<String>) -> Args {
	let mut operation: Operation = Operation::Unknown;
	let base: String = args[0].clone();
	let options = None;

	if args.len() > 1 {
		
	} else {
		operation = Operation::None;
	}

	Args {
		operation,
		base,
		options
	}
}
