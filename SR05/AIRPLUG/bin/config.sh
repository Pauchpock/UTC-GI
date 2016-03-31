# This shell script is part of the Airplug Software Distribution.

# license type: free of charge license for academic and research purpose
# see license.txt
# author: Bertrand Ducourthial
# revision : 13/02/2012

# Aim: this shell script allows to configure the Airplug Software Distribution
#  
#  Usage: source config.sh in the bin directory of the distribution
#
#  This script should work for several shell including this $@$#! tcsh shell,
#  which seems still in used by some unlucky users...
#  It has been tested with tcsh and bash.
#  For any problem or remark, please contact ducourth@utc.fr.


# Determining the shell family of the user -----------------------------------#
#  Detecting bash-like syntax (bash)
( [ `echo $0 | grep bash | wc -l` = 1 ] ; ) && SHELLFAMILY="bash"

#  Detecting tcsh-like syntax (csh, tcsh, ksh)
#  True for csh and tcsh :
( [ `echo $0 | grep csh | wc -l` = 1 ] ; ) && set SHELLFAMILY="tcsh"
#  True for ksh :
( [ `echo $0 | grep ksh | wc -l` = 1 ] ; ) && set SHELLFAMILY="tcsh"

# ----------------------------------------------------------------------------#

# Determining the language of the user ---------------------------------------#
#  Default language is French
( [ $SHELLFAMILY = "bash" ] ; ) && \
		export APG_LANG="french"
( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		setenv APG_LANG "french"

# However, if there is no fr in the LANGUAGE env variable, language is english
( [ $SHELLFAMILY = "bash" ] ; ) && \
		( [ x`env | grep LANGUAGE | grep fr` = x ] ; ) && \
		export APG_LANG="english"

( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		( [ x`setenv | grep LANGUAGE | grep fr` = x ] ; ) && \
		setenv APG_LANG "english"

# ----------------------------------------------------------------------------#

# Testing the directory ------------------------------------------------------#

# By default, we suppose that this is not the bin directory
( [ $SHELLFAMILY = "bash" ] ; ) && \
		VALID_DIR=0

( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		set VALID_DIR=0

# Then, if the directory contains "config.sh"
# and the current path ends with bin, we admit that this is the good directory.
( [ $SHELLFAMILY = "bash" ] ; ) && \
		( [ `pwd | rev | cut -d'/' -f 1 | rev` = bin ] ; ) && \
		( [ -e "config.sh" ] ) && \
		VALID_DIR=1

( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		( [ `pwd | rev | cut -d'/' -f 1 | rev` = bin ] ; ) && \
		( [ -e "config.sh" ] ) && \
		set VALID_DIR=1

# ----------------------------------------------------------------------------#

# Configuring the paths ------------------------------------------------------#
( [ $SHELLFAMILY = "bash" ] ; ) && \
		export APG_PATH=`pwd | rev | cut -d / -f2- | rev` ;

( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		setenv APG_PATH `pwd | rev | cut -d / -f2- | rev` ;

# ":" required by tcsh even here...
( [ $SHELLFAMILY = "bash" ] ; ) && \
		export LD_LIBRARY_PATH=$APG_PATH/LIBAPGC/LIBAPGC/lib":"$LD_LIBRARY_PATH ;

# tcsh does not like undefined variable
( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		( [ "$?LD_LIBRARY_PATH" = 1 ] ; ) && \
		setenv LD_LIBRARY_PATH $APG_PATH/LIBAPGC/LIBAPGC/lib":"$LD_LIBRARY_PATH ;

( [ $SHELLFAMILY = "tcsh" ] ; ) && \
		( [ "$?LD_LIBRARY_PATH" = 0 ] ; ) && \
		setenv LD_LIBRARY_PATH $APG_PATH/LIBAPGC/LIBAPGC/lib ;
# ----------------------------------------------------------------------------#


# Displaying text for the user (french or english) ---------------------------#

# Note: ; \ at the end of the line is required by tcsh.
# Note: the previous comment cannot be placed in the brackets with tcsh.
( [ $APG_LANG = "french" ] ; ) && ( \
		echo ; \
		echo "+ Configuration de la Suite Logiciell Airplug" ; \
		echo "  (c) Laboratoire Heudiasyc UMR CNRS-UTC 7259" ; \
		echo "      Universite de Technologie de Compiegne" ; \
		echo "      ducourth@utc.fr" ; \
		echo "+ Attention : pour une configuration correcte, lancer" ; \
		echo "  ce script depuis le repertoire bin de la distribution." ; \
		echo ; \
		( [ $VALID_DIR == 1 ]; ) || echo "- Mauvais repertoire" ; \
		( [ $VALID_DIR == 1 ]; ) && echo "+ Repertoire : tests ok" ; \
		echo "+ Shell utilise : `echo $0`" ; \
		echo "+ Langage utilise : $APG_LANG" ; \
		echo "+ Repertoire de la distribution (APG_PATH) :" ; \
		echo "   $APG_PATH" ; \
		echo "+ Repertoires des bibliotheques (LD_LIBRARY_PATH) :" ; \
		echo "   $LD_LIBRARY_PATH" ; \
		echo ; \
)

( [ $APG_LANG = "english" ] ; ) && ( \
		echo ; \
		echo "+ Configuring the Airplug Software Distribution" ; \
		echo "  (c) Laboratoire Heudiasyc UMR CNRS-UTC 7253" ; \
		echo "      Universite de Technologie de Compiegne" ; \
		echo "      ducourth@utc.fr" ; \
		echo "+ Warning: for a correct configuration, you should" ; \
		echo "  source this script from the bin directory of the distribution." ; \
		echo ; \
		( [ $VALID_DIR = 1 ]; ) || echo "- Bad directory" ; \
		( [ $VALID_DIR = 1 ]; ) && echo "+ Directory: tests ok" ; \
		echo "+ Current shell: `echo $0`" ; \
		echo "+ Current language: $APG_LANG" ; \
		echo "+ Directory of the distribution (APG_PATH):" ; \
		echo "   $APG_PATH" ; \
		echo "+ Directory for libraries (LD_LIBRARY_PATH):" ; \
		echo "   $LD_LIBRARY_PATH" ; \
		echo ; \
)
# ----------------------------------------------------------------------------#

