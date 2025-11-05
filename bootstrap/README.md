# stage0
Bootstrapped compiler for pearl language.

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

2 directories, 7 files
```
# Toolchain
If you're using an windows system(ms-nt, msvc) you need to edit the rust-toolchains file like remove the `x86_64-unknown-linux-gnu` from toolchain's target also you can make samething in linux distributions.

```
File navigation:
└── bootstrap
    └── rust-toolchain.toml

# For Linux distributions.
...
targets = ["x86_64-unknown-linux-gnu"]
...

# For windows systems.
...
targets = ["x86_64-pc-windows-msvc"]
...
```

# Requirements
- rustup

# Installation
```sh
rustup show
cargo build --release
```
