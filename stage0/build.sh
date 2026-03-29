#!/bin/sh

# hey i just met u, and this is crazy,
# but here's my build script, so compile me maybe? <-- ahahaha burayı copilot tamamladı :D

set -e

export CC="gcc" OPTS="-Wall -Wextra -Werror -nostdlib -O2" SRC="*.c" OUT="pearlc"

die() {
	printf "\033[0;31m%s: ERR: ${1}\033[0m\n" "${0##*/}"
	exit 1
}

while getopts ":c:f:o:Crh" opts ; do
	case "${opts}" in
		"c")
			if [ -n "${OPTARG}" ] ; then
				CC="${OPTARG}"
			fi
		;;
		"f")
			if [ -n "${OPTARG}" ] ; then
				OPTS="${OPTS} ${OPTARG}"
			fi
		;;
		"o")
			if [ -n "${OPTARG}" ] ; then
				OUT="${OPTARG}"
			fi
		;;
		"C")
			rm -r "${OUT}" ./*.o
			exit 0
		;;
		"r")
			OPTS="${OPTS} -static -s -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-ident"
		;;
		"h")
			printf "Usage: %s [options] [source files]\n\n" "${0##*/}"
			printf "Options:\n"
			printf "  -c <compiler>   Specify the C compiler to use (default: gcc)\n"
			printf "  -f <flags>     Additional flags to pass to the C compiler\n"
			printf "  -o <output>    Specify the output executable name (default: pearlc)\n"
			printf "  -C             Clean build artifacts (remove output and object files)\n"
			printf "  -r             Build with release flags\n"
			printf "  -h             Show this help message and exit\n"
			exit 0
		;;
		?)  
			printf "Usage: %s: [-c value] [-f value] [-o value] [-C] args\n" "${0##*/}"
			exit 2
		;;
	esac
done

shift $(( OPTIND - 1 ))

if [ "$#" -gt 0 ] ; then
	SRC="$SRC $*"
fi

# Select C compiler or get angry.
echo "---- Select C compiler ----"
if command -v "${CC}" > /dev/null ; then
	echo "selected c compiler as \"${CC}\""
else
	echo "INFO: \"${CC}\" not found, i'm trying to search another one."
	for lookup in "gcc" "clang" "tcc" "pcc"; do
		if command -v "${lookup}" > /dev/null ; then
			CC="${lookup}"
			break
		fi
	done
	if command -v "${CC}" > /dev/null ; then
		echo "Found \"${CC}\", using as default..."
	else
		die "sorry, i can't find any available C compiler on your system."
	fi
fi

echo "---- Building the compiler ----"
echo "using \"${CC}\" as the c compiler, with flags: ${OPTS}"
# shellcheck disable=SC2086
${CC} ${OPTS} -Iinclude -o "${OUT}" ${SRC}

if [ -f "${OUT}" ] ; then
	echo "---- Build successful! ----"
	echo "the compiler is available at ./${OUT}"
else
	die "failed to build the compiler, check the error messages above for more details."
fi