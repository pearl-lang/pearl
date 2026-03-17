use std::env::args;

use stage0::argparse::{Args, argp};
use stage0::common::{Info, Operation, die, pearl_info};
use stage0::log::error;

fn main() {
    let args: Vec<String> = args().collect();
    let opt: Args = argp(args);

    let pearl_i: Info = pearl_info();

    // println!("{:?}", opt.options.as_ref().unwrap_or(&Vec::new()));

    match opt.operation {
        Operation::None => println!(
            "You need to give parameters for compile something, if you're looking for some help just try \"pearlc --help\""
        ),
        Operation::Error => error("an error occured, please do not or do something."),
        Operation::Version => println!("{} v{}", pearl_i.name, pearl_i.version),
        Operation::Compile => (),
        _ => die(
            "an unknown error occured, please open an issue via following the link: https://github.com/pearl-lang/pearl/issues/new.",
        ),
    }
}
