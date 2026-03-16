use crate::common::get_time;

enum Level {
	Info,
	Warn,
	Error,
	Debug
}

fn log(level: Level, msg: &str) -> String {
	let level_str: &str = match level {
		Level::Info  => "info",
		Level::Warn  => "warning",
		Level::Error => "error",
		Level::Debug => "debug",
	};


	format!("[{} {}] {}", level_str, get_time(), msg).to_string()
}

pub fn info(msg: &str) {
	println!("{}", log(Level::Info, msg));		
}

pub fn warn(msg: &str) {
	println!("{}", log(Level::Warn, msg));		
}

pub fn error(msg: &str) {
	println!("{}", log(Level::Error, msg));		
}

pub fn debug(msg: &str) {
	println!("{}", log(Level::Debug, msg));		
}
