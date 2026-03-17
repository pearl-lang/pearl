use std::process::exit;
use std::time::{SystemTime, UNIX_EPOCH};

static MAJOR: u8 = 0;
static MINOR: u8 = 1;
static PATCH: u8 = 0;

pub enum Operation {
    Error,
    Version,
    Compile,
    Unknown,
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
