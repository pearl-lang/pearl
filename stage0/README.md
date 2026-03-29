# pearl stage0

Minimal `nostdlib` compiler/runtime bootstrap.

Current focus:
- Simple build flow
- C runtime entry (`_start`) calling `main(argc, argv)`
- Platform layer for argument/environment access

## Current Status

Implemented paths:
- Linux x86_64: `_start` -> stack decode (`argc/argv/envp`) -> `main` -> `exit` syscall
- macOS x86_64: similar startup path, Darwin `exit` syscall
- Windows: `mainCRTStartup`, command-line parsing, environment block import, `ExitProcess`

Notes:
- `main` can stay 2-argument: `int main(int argc, char **argv)`
- Environment access is optional via `platform_get_envp` and `platform_getenv`

## Build

### Linux/macOS (shell script)

Default build:
```sh
sh ./build.sh
```

Help:
```sh
sh ./build.sh -h
```

Release-like flags:
```sh
sh ./build.sh -r
```

Custom compiler/flags/output example:
```sh
sh ./build.sh -c clang -f "-g" -o pearlc
```

Script defaults:
- Compiler: `gcc` (fallback: `clang`, `tcc`, `pcc`)
- Flags: `-Wall -Wextra -Werror -nostdlib -O2`
- Include path: `-Iinclude`
- Output binary: `pearlc`

### Windows

`build.ps1` is currently empty. Windows build script can be added later.

## Runtime Flow

Startup sequence:
1. Process enters at `_start` (or `mainCRTStartup` on Windows)
2. Runtime calls platform initialization
3. Platform fills startup data (`argc`, `argv`, `envp`)
4. Runtime calls `main(argc, argv)`
5. Return value is used as process exit code

Minimal `main` example:
```c
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    return 0;
}
```

## Optional Environment Access

You can read environment values without changing `main` signature:

```c
#include "platform.h"

int main(int argc, char **argv) {
    char **envp = platform_get_envp();
    char *home = platform_getenv("HOME");

    (void)argc;
    (void)argv;
    (void)envp;
    (void)home;
    return 0;
}
```

On Windows, use keys such as `USERPROFILE`.

## File Reference

- Runtime entry: `runtime.c`
- Platform implementation: `platform.c`
- Platform API: `include/platform.h`
- Example app entry: `main.c`
- Shell build script: `build.sh`
- PowerShell build script: `build.ps1`

## Known Limitations

- Verified in Linux environment.
- macOS/Windows paths are implemented but not CI-tested in this repository.
- Runtime is intentionally minimal and does not emulate full libc init/fini behavior.
