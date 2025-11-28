# Pearl Language

![image](https://raw.githubusercontent.com/pearl-lang/logo/refs/heads/main/pearl_logo.png)

# Getting started with pearl language

## Manage pearl versions with [gece](https://github.com/pearl-lang/gece)
Let's use gece to compile and run pearl programs easily, manage dependencies and pearl versions.

## Build from source

### Requirements
- Git
- CMake 3.15+
- A C/C++ compiler (GCC, Clang, MSVC, etc.)
- Make (for Linux/macOS) or Ninja (for Windows)
- Visual Studio 18 (for Windows)

Get the source.
```sh
git clone "https://github.com/pearl-lang/pearl.git"
cd "pearl"
```

### Let's compile the compiler

#### For Linux systems
```sh
cmake -B build
cmake --build build
```

#### For Windows
```ps1
& "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\Launch-VsDevShell.ps1" # Enable VS Development Environment
cmake -B build -G "Visual Studio 18 2022" # or you can prefer whatever you use, for exp: -G "Ninja"
cmake --build build
```

# Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

# [License](./LICENSE)
[MIT](https://choosealicense.com/licenses/mit/)