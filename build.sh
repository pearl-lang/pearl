#!/bin/sh

# Pearl build script for unix* posix compliant systems written in posix shell.
# no args or parameters required you can execute the script and at the end,
# you'll get the pearl compiler(if you're lucky).

set -e

export CWD="$(pwd)"

# The classic, fatal func.
die() {
	echo "\033[0;31m${0##*/}: ERR: ${1}\033[0m"
	exit 1
}

# Check required commands.
(
must_fail=false
for cmd in "rustup" "cargo" "rustc" ; do
	if ! command -v "${cmd}" ; then
		printf "missing: i can't find \"%s\", please get it." "${cmd}"
		must_fail=true
	fi
done

if "${must_fail}" ; then die "there are missing commands we require please install that packages before run this script!" ; fi
)

# Check the base.
(
must_fail=false
for ent in	"stage0:req" \
			"stage0/src:req" \
			"stage0/Cargo.toml:req" \
			"stage0/src/main.rs:req" \
			"stage0/tests:opt" ; do
	printf "${ent%%:*}"
	if [ -e "${ent%%:*}" ] ; then
		printf " -> exists.\n"
	else
		printf " -> not found"
		if [ "${ent##*:}" = "req" ] ; then
			printf ", but it's required!"
			must_fail=true
		else 
			printf ", skipping.."
		fi
		printf "\n"
	fi
done
if "${must_fail}" ; then die "required files or directories missing, please check your source code!\nNOTE: you can try re-download the source." ; fi
)

# Stage 0
# let's compile the bootstrap compiler.
(
	cd "${CWD}"
	echo "build: Stage0, bootstrap compiler.."
	cd "stage0"
	cargo build --release
	if [ -f "target/release/pearlc" ] ; then
		if ! command "target/release/pearlc" --version ; then
			die "bootstrap compiler runtime error."
		fi
	else
		die "i can't find the bootstrap compiler, is that compiled correctly?"
	fi
	echo "bootstrap compiler is compiled successfully."
)
