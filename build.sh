#!/bin/sh

###############
# quick build #
###############

set -e

case "${1}" in
	"build"|"b")
		(
			{ 
				[ -d "build" ] || mkdir -p "build"
			} && {
				cd "build"
				cmake ..
				make
				[ -f "pearl" ] && echo "debug is ready at \"${PWD##*/}/pearl\"."
			}
		) || exit 1
	;;
	"clean"|"c")
		rm -vrf "build"
	;;
	"release"|"r")
		(
			{ 
				[ -d "build" ] || mkdir -p "build"
			} && {
				cd "build"
				cmake -DCMAKE_BUILD_TYPE="Release" ..
				make
				[ -f "pearl" ] && echo "release is ready at \"${PWD##*/}/pearl\"."
			}
		) || exit 1		
	;;
	*)
		echo "${0##*/}: unknown parameter, you can type \"build\", \"clean\" or \"release\" and it's a quick build script for pearl language."
		exit 1
	;;
esac