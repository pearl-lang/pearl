use std::process::exit;
use std::time::{SystemTime, UNIX_EPOCH};

static MAJOR: u8 = 0;
static MINOR: u8 = 1;
static PATCH: u8 = 0;

#[derive(PartialEq)]
pub enum Operation {
    Help,
    Version,
    Compile,
    Unknown,
    Error,
    None,
}

pub struct Info {
    pub name: String,    // "Pearl"
    pub version: String, // "0.1.0"
    pub base: String,    // "https://github.com/pearl-lang/pearl"
}

pub fn pearl_info() -> Info {
    let name: String = String::from("Pearl");

    let version: String = format!("{}.{}.{}", MAJOR, MINOR, PATCH);
    let base: String = String::from("https://github.com/pearl-lang/pearl");

    Info {
        name,
        version,
        base,
    }
}

pub fn get_time() -> String {
    let now = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap()
        .as_secs();

    let h = (now / 3600) % 24;
    let m = (now / 60) % 60;
    let s = now % 60;

    format!("{}:{}:{}", h, m, s)
}

pub fn die(msg: &str) -> ! {
    eprintln!("[{}:{} {}] {}", file!(), "die", get_time(), msg);
    exit(1);
}

fn basename(path: &str) -> &str {
    let bytes = path.as_bytes();
    let mut i = bytes.len();

    while i > 0 {
        i -= 1;
        if bytes[i] == b'/' || bytes[i] == b'\\' {
            return &path[i + 1..];
        }
    }

    path
}

pub fn help(base: &str) {
    println!("{}\n    --help\t\tShow this help message\n    --version\t\tShow version information\n\nFiles:\tFILES\t\tThe files to compile",
    format_args!("Usage: {} [OPTIONS] [FILES]\n\nOptions:", basename(base)));
}