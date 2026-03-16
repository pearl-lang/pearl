use crate::common::get_time;

enum Level {
	INFO,
	WARN,
	ERROR,
	DEBUG
}

fn log(level: Level, msg: &str) -> String {
	let level_str: &str = match level {
		Level::INFO  => "info",
		Level::WARN  => "warning",
		Level::ERROR => "error",
		Level::DEBUG => "debug",
	};


	format!("[{} {}] {}", level_str, get_time(), msg).to_string()
}

pub fn info(msg: &str) {
	println!("{}", log(Level::INFO, msg));		
}

pub fn warn(msg: &str) {
	println!("{}", log(Level::WARN, msg));		
}

pub fn error(msg: &str) {
	println!("{}", log(Level::ERROR, msg));		
}

pub fn debug(msg: &str) {
	println!("{}", log(Level::DEBUG, msg));		
}
