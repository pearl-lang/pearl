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
```sh
chmod u+x "scripts/cmake.sh"
./scripts/cmake.sh . && cd "build"
make
```

or if you want to make it manually like a man.

#### For Linux systems
```sh
[ ! -d "build" ] && mkdir "build"
cd "build"
cmake ..
make
```

#### For Windows
```ps1
if (-Not (Test-Path "build")) { New-Item -ItemType Directory -Name "build" }
Set-Location "build"
& "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\Launch-VsDevShell.ps1"
cmake -G "Ninja" ..
ninja
```

# Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

# [License](./LICENSE)
[MIT](https://choosealicense.com/licenses/mit/)