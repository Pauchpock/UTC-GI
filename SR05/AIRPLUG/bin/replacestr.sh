#!/bin/bash

# This shell script is part of the Airplug Software Distribution.

# license type: free of charge license for academic and research purpose
# see license.txt
# author: Bertrand Ducourthial
# revision : 16/03/2012

# Aim: this shell script allows to easily replace a string by another one
#      in a collection of files. Moreover, it saves the old version of the
#      files.
#  
#  Usage: replacestr.sh -v -s -i=oldstring -o=newstring file1 file2


VERSION=0.2
INPUT=""
OUTPUT=""
FILE=""
VERBOSE=0
EXE=`basename $0`

# Decoding arguments
while [ x"$1" != x ]; do
		case "$1" in
				-v)
						VERBOSE=`echo 1 + $VERBOSE | bc`
						;;

				-vv)
						VERBOSE=2
						;;
	
				-i=*)
						INPUT=`echo $1 | sed s/-i=//`
						;;

				-s)
						SAVE=1
						;;

				-o=*)
						OUTPUT=`echo $1 | sed s/-o=//`
						;;
				
				-h|--help)
						echo "+ $EXE: help. The Airplug Software Distribution."
						echo "    usage: $EXE -i=s1 -o=s2 file1 file2 file3..."
						echo "    replace any string s1 in files file1 file2 file3... with string s2"
						echo "    -v: verbose mode"
						echo "    --version : version number"
						echo "    -i: input string"
						echo "    -o: output string"
						echo "    -s: save original file in file.old"
						echo "    -h or --help: this help"
						exit
						;;
				
				--version)
						echo "+ $EXE: version $VERSION"
						exit
						;;
				*)
						FILES="$FILES $1"
						;;
    esac
    shift
done

if [ $VERBOSE -ge 2 ] ; then
		echo "+ $EXE: input string: $INPUT"
		echo "+ $EXE: output string: $OUTPUT"
		echo "+ $EXE: files to be checked: $FILES"
fi

if [ "$INPUT" = "" ] || [ "$OUTPUT" = "" ] || [ "$FILES" = "" ] ; then
		echo "- $EXE: missing arguments" ;
		echo "  $EXE: try $EXE --help" ;
		exit 1
fi

for F in $FILES; do
		if [ $VERBOSE -ge 2 ]; then echo "+ $EXE: checking $F"; fi;

		# saving file
		cp --preserve=all $F $F.bak

		# modifying file (if any)
    #	/bin/rm -f $F not useful and do not conserve properties of $F else
		sed "s/$INPUT/$OUTPUT/g" $F.bak > $F

		# check whether some modifications have been done or not
		if [ "x`\diff -q $F $F.bak`" = "x" ] ; then
				if [ $VERBOSE -ge 1 ]; then echo "+ $EXE:   done $F (not modified)"; fi;
		else
				if [ $VERBOSE -ge 2 ]; then echo "+ $EXE:   $F has been modified"; fi;

				if [ $SAVE ] ; then
						if [ -e $F.old ] ; then
								S=$F.old.`date +"%Y-%m-%d-%H:%M:%S"`
						else
								S=$F.old
						fi;
						if [ $VERBOSE -ge 1 ] ; then echo "+ $EXE:   saving $F in $S"; fi;
						cp --preserve=all $F.bak $S;
				fi;
				
				if [ $VERBOSE -ge 1 ] ; then echo "+ $EXE:   done $F (modified)"; fi;
		fi;

		# deleting temporary file
		\rm -f $F.bak
done
