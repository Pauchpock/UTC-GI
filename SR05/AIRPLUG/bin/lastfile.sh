#!/bin/bash

# This shell script is part of the Airplug Software Distribution.

# license type: free of charge license for academic and research purpose
# see license.txt
# author: Bertrand Ducourthial
# revision : 16/03/2012

# Aim: return the last created file in a given directory
#  
#  Usage: lastfile.sh
#         lastfile.sh <directory>
#
# In case no argument is given, the current directory is used.
# In case the directory does not exist, nothing is returned.
# If several arguments are given, the first one is used and the others are ignored
#
# Exemple of use: gnumeric `lastfile.sh ../data`

if [ "$1x" == "x" ]; then
		# No argument -> directory = current directory
		echo `ls -ltr $1 | sed s/' '/'\n'/g | tail -1`
else
		# Argument present -> considered directory

		# Checking whether this is a directory or not
		if [ -d $1 ]; then
				# The directory name is prefixed to the file name returned
				echo $1/`ls -ltr $1 | sed s/' '/'\n'/g | tail -1`
		fi;
fi;

