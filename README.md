# Pearl Language

![image](https://github.com/user-attachments/assets/8ac122bf-9724-4633-9b88-88559706a3b3)

# Getting started with pearl language.

## Build from source

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
Requires:
- any C compiler
- make

```sh
[ ! -d "build" ] && mkdir "build"
cd "build"
cmake ..
make
```

#### For Windows
Requires:
- ninja build
- msvc(Visual Studio Build Tools)

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