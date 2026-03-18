#!/bin/sh

# Pearl build script for unix* posix compliant systems written in posix shell.
# no args or parameters required you can execute the script and at the end,
# you'll get the pearl compiler(if you're lucky).

set -e

# shellcheck disable=SC2155
export CWD="$(pwd)"

# The classic, fatal func.
die() {
	printf "\033[0;31m %s: ERR: ${1}\033[0m" "${0##*/}"
	exit 1
}

section() {
	msg="sectioner"
	i="0"
	p="5"

	[ -n "${1}" ] && msg="${1}"
	[ -n "${2}" ] && p="${2}"

	while [ "${i}" -lt "${p}" ] ; do
		line="${line}="
		i="$(( i + 1 ))"		
	done

	printf "%s %s %s\n" "${line}" "${msg}" "${line}"
}

# Check required commands.
(
section "Requirement check"
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
section "File integrity check(without checksum)"
must_fail=false
for ent in	"stage0:req" \
			"stage0/src:req" \
			"stage0/Cargo.toml:req" \
			"stage0/src/main.rs:req" \
			"stage0/tests:opt" ; do
	printf "%s" "${ent%%:*}"
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
	section "The bootstrap compiler"
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
