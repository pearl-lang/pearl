#!/bin/sh

###############
# quick build #
###############

set -e

case "${1}" in
	"build"|"b")
		(
			{ 
				[ -d "build" ] || mkdir "build"
			} && {
				cd "build"
				cmake ..
			}
		) || exit 1
	;;
	"clean"|"c")
		rm -vrf "build"
	;;
	*)
		echo "${0##*/}: unknown parameter, you can type \"build\" or \"clean\" and it's a quick build script for pearl language."
		exit 1
	;;
esac
