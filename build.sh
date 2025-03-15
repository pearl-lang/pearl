#!/bin/sh

# Runtime build.

set -e

export CWD="${PWD}" BUILDD="build"

case "${1:-help}" in
	"help")
		echo "${0##*/}: you can try this: sh ${0##*/} help/clean/build, default parameter is help."
	;;
	"clean")
		command -vV rm
		[ -d "${BUILDD}" ] && rm -vr "${BUILDD}"
	;;
	"build")
		command -vV mkdir
		command -vV gcc
		[ -d "${BUILDD}" ] || mkdir -p "${BUILDD}"

		# shared object olacak ve rust'a da parametre olarak ekleyecez.
		gcc "runtime/main.c" -o "build/pearlrt"
	;;
	*)
		echo "${0##*/}: ${1}: sorry i don't get what do you mean."
		exit 1
	;;
esac
[ "${1:-help}" != "help" ] && echo "${0##*/}: ${1}: complete."
