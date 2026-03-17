use crate::common::Operation;
use std::path::PathBuf;
use std::vec::Vec;

pub struct Args {
    pub operation: Operation,
    pub base: String,
    pub options: Option<Vec<Opt>>,
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
    fn identify(_par: &str, _is_long: Option<bool>) -> Opts;
    fn is_iterable(_opt: &Opts) -> bool;
    fn is_param_req(_opt: &Opts) -> bool;
    fn is_long(par: &str) -> Option<bool>;
    fn get_params_for(_opt: &Opts, _args: &[String]) -> Option<Vec<String>>;
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
            params,
        }
    }

    fn identify(_par: &str, _is_long: Option<bool>) -> Opts {
        println!("{} {:?}", _par, _is_long);
        Opts::Unknown(String::from(_par))
    }

    fn is_iterable(_opt: &Opts) -> bool {
        true
    }

    fn is_param_req(_opt: &Opts) -> bool {
        true
    }

    fn is_long(par: &str) -> Option<bool> {
        if par.starts_with("--") && par.len() > 2 && !par.contains(' ') {
            return Some(true);
        } else if par.starts_with("-") {
            return Some(false);
        }

        None
    }

    fn get_params_for(_opt: &Opts, _args: &[String]) -> Option<Vec<String>> {
        let params: Option<Vec<String>> = None;

        params
    }
}

pub fn argp(args: Vec<String>) -> Args {
    let mut operation: Operation = Operation::Unknown;
    let base: String = args[0].clone();
    let mut options = None;

    if args.len() > 1 {
        let mut iter = args.iter().skip(1);
        while let Some(arg) = iter.next() {
            let iter_clone = iter.clone().cloned().collect::<Vec<String>>();

            // Debugging output
            // println!("{} {:?}", iter.len(), iter_clone);

            let opt: Opt = Opt::parse(arg, &iter_clone);

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
