use crate::common::Operation;
use std::path::PathBuf;
use std::vec::Vec;

pub struct Args {
    pub operation: Operation,
    pub base: String,
    pub options: Option<Vec<Opt>>
}

#[derive(Debug)]
pub enum Opts {
    Output(PathBuf),     // --output, -o: last parameter is output file
    EbpfOutput(PathBuf), // --ebpf-output, -bo: last parameter is bpf output file
    Vmlinux(PathBuf),    // --vmlinux, -vml: last parameter is vmlinux file
    Ntoskrnl(PathBuf),   // --ntoskrnl, -nt: last parameter is ntoskrnl file
    Ntkrnlmp(PathBuf),   // --ntkrnlmp, -ntm: last parameter is ntkrnlmp file
    Verbose(usize),      // --verbose, -V: no parameter
    Version,             // --version, -v: no parameter
    Help,                // --help, -h: no parameter
    Parameter(String),   // a parameter without an option
    Unknown(String),     // an unknown parameter, it gonna be error
}

#[derive(Debug)]
pub struct Opt {
    pub opt: Opts,          // option type like '--output' is Output
    pub long: Option<bool>, // false is short
    pub iterable: bool,     // when is short and iterable like -abc..
    pub is_param_req: bool, // is any parameter required?
    pub params: Option<Vec<String>>,
}

trait OptArg {
    fn parse(ctx: &str, args: &[String]) -> Self;
    fn identify(par: &str, is_long: Option<bool>) -> Opts;
    fn is_iterable(opt: &Opts) -> bool;
    fn is_param_req(opt: &Opts) -> bool;
    fn is_long(par: &str) -> Option<bool>;
    fn get_params_for(opt: &Opts, args: &[String]) -> Option<Vec<String>>;
}

impl OptArg for Opt {
    fn parse(ctx: &str, args: &[String]) -> Self {
        let long: Option<bool> = Self::is_long(ctx);
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

    // TODO: add iterable check here.
    fn identify(par: &str, is_long: Option<bool>) -> Opts {
        // Is the given parameter starting with "-" or "--"?
        let is_arg: bool = match is_long {
            Some(true) | Some(false) => true,
            None => false
        };

        // If it's an argument, is it long or short?
        let is_long: bool = match is_long {
            Some(true) => true,
            Some(false) => false,
            None => false
        };

        let opt: Opts = match (par, is_arg, is_long) {
            ("--output", true, true) | ("-o", true, false) => Opts::Output(PathBuf::new()),
            ("--ebpf-output", true, true) | ("-bo", true, false) => Opts::EbpfOutput(PathBuf::new()),
            ("--vmlinux", true, true) | ("-vml", true, false) => Opts::Vmlinux(PathBuf::new()),
            ("--ntoskrnl", true, true) | ("-nt", true, false) => Opts::Ntoskrnl(PathBuf::new()),
            ("--ntkrnlmp", true, true) | ("-ntm", true, false) => Opts::Ntkrnlmp(PathBuf::new()),
            ("--verbose", true, true) => Opts::Verbose(0), // -V is iterable, so it will be handled in the iterable check.
            ("--version", true, true) | ("-v", true, false) => Opts::Version,
            ("--help", true, true) | ("-h", true, false) => Opts::Help,
            (par, _, _) if !is_arg => Opts::Parameter(par.to_string()),
            _ => {
                println!("Unknown parameter: {}", par); // Debugging output for unknown parameters, TODO: add here to verbose mode.
                Opts::Unknown(par.to_string())
            }
        };

        opt
    }

    fn is_iterable(opt: &Opts) -> bool {
        matches!(opt, Opts::Verbose(_))
    }

    fn is_param_req(opt: &Opts) -> bool {
        matches!(opt, 
        Opts::Output(_)     |
        Opts::EbpfOutput(_) |
        Opts::Vmlinux(_)    |
        Opts::Ntoskrnl(_)   |
        Opts::Ntkrnlmp(_))
    }

    fn is_long(par: &str) -> Option<bool> {
        if par.starts_with("--") && par.len() > 2 && !par.contains(' ') {
            return Some(true);
        } else if par.starts_with("-") {
            return Some(false);
        }

        None
    }

    fn get_params_for(_opt: &Opts, mut args: &[String]) -> Option<Vec<String>> {
        let mut params: Option<Vec<String>> = None;

        while !args.is_empty() {
            let next_arg = &args[0];
            if next_arg.starts_with("-") {
                break; // Stop if the next argument is another option
            }
            params.get_or_insert(Vec::new()).push(next_arg.clone());
            args = &args[1..]; // Move to the next argument
        }

        params
    }
}

pub fn argp(mut args: Vec<String>) -> Args {
    let mut operation: Operation = Operation::Unknown;
    let base: String = args[0].clone();
    let mut options = None;

    if args.len() > 1 {
        let mut iter = args[1..].iter_mut();
        while let Some(arg) = iter.next() {
            // Debugging output
            // println!("{} {:?}", iter.len(), iter_clone);

            let opt: Opt = Opt::parse(arg, iter.as_slice());

            operation = match opt.opt {
                Opts::Help => Operation::Help,
                Opts::Version => Operation::Version,
                Opts::Unknown(_) => Operation::Error,
                _ => {
                    if operation == Operation::Unknown {
                        Operation::Compile
                    } else {
                        operation
                    }
                }
            };

            options.get_or_insert(Vec::new()).push(opt);
        }
    } else {
        operation = Operation::None;
    }

    Args {
        operation,
        base,
        options,
    }
}
