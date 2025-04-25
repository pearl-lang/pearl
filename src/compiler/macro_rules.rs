#[macro_export]
macro_rules! err {
    ($msg:expr) => {
        return Err($msg.into());
    };
}
