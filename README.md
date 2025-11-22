# Pearl language.

![image](https://github.com/user-attachments/assets/8ac122bf-9724-4633-9b88-88559706a3b3)

# Getting started with the pearl.

## Build from source.

Get the source.
```sh
git clone "https://github.com/pearl-lang/pearl.git"
cd "pearl"
```

### Let's compile the compiler with build automation.

```sh
chmod u+x "scripts/cmake.sh"
./scripts/cmake.sh . && cd "build"
make
```

or if you want to make it manually like a man.

```
[! -d "build" ] && mkdir "build"
cd "build"
cmake ..
make
```

# Contributing.
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

# [License](./LICENSE).
[MIT](https://choosealicense.com/licenses/mit/)
