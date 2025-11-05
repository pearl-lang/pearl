# stage0
Bootstrapped compiler for [pearl](https://github.com/pearl-lang/pearl) language.

## Navigator
```
.
├── bootstrap
│   ├── Cargo.lock
│   ├── Cargo.toml
│   ├── README.md  < You're here.
│   ├── rust-toolchain.toml
│   └── src
│       └── main.rs
├── LICENSE
└── README.md
```

# Toolchain
For the target list in bootstrap/rust-toolchain.toml set only the platform you need.

- For Windows (MSVC):
```toml
[toolchain]
# ...
targets = ["x86_64-pc-windows-msvc"]
```

- For Linux:
```toml
[toolchain]
# ...
targets = ["x86_64-unknown-linux-gnu"]
```

Remove the other target(s) from the array so the file contains only the appropriate target for your OS. After editing, run:

```sh
rustup update
cargo build --release
```
