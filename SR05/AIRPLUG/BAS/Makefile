# license type: free of charge license for academic and research purpose
# see license.txt
# author: Bertrand Ducourthial
# revision: 18/12/2013

# Layer 2 makefile of the Airplug Software Distribution.
# See the file Makefile-var for application-dependent configuration.

### GENERAL PARAMETERS #########################################################
# To avoid any problem from the inheritage of SHELL variable from the
# environment
SHELL = /bin/bash

# Language (if the LANGUAGE env variable contains fr, then french, else english)
TEXT = $(shell if [ x`env | grep LANGUAGE | grep fr` = x ] ; then echo "english" ; else echo "french" ; fi )

# Target architecture (for application requiring compilation)
# NB: the output program, the libraries and the object files directories are
#     named according to the ARCH variable used as suffixe (see layer 3
#     Makefile). The tgz-bin archive is named according to the ARCH variable.
# NB: only if not already defined during a cross-compilation process.
ARCH ?= $(shell uname -m)

# Step for the version number incrementation
#  (the version number will be increased by VERSION_STEP when using make
#   new_version or make incr)
VERSION_STEP="0.01"


### DIRECTORIES NAMES ##########################################################
# NB: It is assumed that the Airplug convention related to directories
#     organisation is satisfied.

# Exporting the DIR variable for sub-makefiles
export DIR=$(shell pwd | rev | cut -d'/' -f 1 | rev)

VERSION=$(shell ls -ld $(DIR)* | grep -e "->" | cut -d'>' -f 2 | rev | cut -d '-' -f 1 | rev | cut -d'/' -f1)

# Install directory of the whole distribution
DIR_INSTALL = ..


### COMMANDS TO USE ############################################################
# NB: other commands are defined in layer 3 Makefile.

# Make program used for calling sub-makefiles
MAKE = make

# Make options:
#   -s : silent
#   -e : variables which are exported here predominates those initialized in
#        sub-makefiles
#MFLAGS = -e -s
# TODO check -e with APG compilation
MFLAGS = -s

###  APPLICATION DEPENDENT VARIABLES ###########################################
# NB: any specificity is defined in Makefile-var to keep a generic Makefile.
# NB: any previously defined variable could be overwritten in Makefile-var
#     preserving the genericity of the Makefile.
include Makefile-var


### SPECIFIC RULES #############################################################
# To avoid any problem in case a file has the name of a rule
.PHONY: build clean depend \
	files-tgz-bin files-tgz-dev files-tgz-skl files-tgz-pub \
	help icon incr install list mod-version new-version print-tgz-dev \
	reset show-version tgz-bin tgz-pub tgz-dev tgz-skl

# Help rule
# NB: first rule => default rule
help:
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : aide pour le Makefile de la Suite logicielle Airplug" ; \
		echo "     make build        : compilation" ; \
		echo "     make clean        : suppression des fichiers temporaires" ; \
		echo "     make depend       : calcul des dependances (avant compilation)" ; \
		echo "     make help         : affiche cette aide"; \
		echo "     make icon         : creation de l'icone de l'application" ; \
		echo "     make incr         : similaire a make new-version" ; \
		echo "     make install      : installation du programme (apres compilation)" ; \
		echo "     make list         : liste des fichiers" ; \
		echo "     make mod-version  : modifie la version courante de l'application" ; \
		echo "     make new-version  : cree une nouvelle version de l'application" ; \
		echo "     make reset        : clean + suppression des executables compiles" ; \
		echo "     make show-version : affichage de la version, du type de license et des auteurs" ; \
		echo "     make tgz-bin      : archivage des sources pour distribution binaire" ; \
		echo "     make tgz-pub      : archivage des sources pour distribution publique" ; \
		echo "     make tgz-dev      : archivage des sources pour distribution de developpement" ; \
		echo "     make tgz-skl      : archivage des sources pour embryon de distribution" ; \
	else \
		echo " +++ $(DIR) : help for Makefile of the Airplug Software Distribution" ; \
		echo "     make build        : compilation" ; \
		echo "     make clean        : delete temporary files" ; \
		echo "     make depend       : compute the dependencies (before compilation)" ; \
		echo "     make help         : display this help"; \
		echo "     make icon         : create the application icon" ; \
		echo "     make incr         : same as make new-version" ; \
		echo "     make install      : install the program (after compilation)" ; \
		echo "     make list         : list the files" ; \
		echo "     make mod-version  : modify the current version of the application" ; \
		echo "     make new-version  : create a new version of the application" ; \
		echo "     make reset        : clean + delete the compiled executables" ; \
		echo "     make show-version : display the version, the license type and the authors" ; \
		echo "     make tgz-bin      : archive sources for the binary distribution" ; \
		echo "     make tgz-pub      : archive sources for the public distribution" ; \
		echo "     make tgz-dev      : archive sources for the devel distribution" ; \
		echo "     make tgz-skl      : archive sources for the skeleton distribution" ; \
	fi ;

# The following rules are applied to subdirectories.
build depend icon install list reset:
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ;	\
	else \
		echo " +++ $(DIR) : $@ rule" ;	\
	fi ; \
	if [ -e $(DIR)/Makefile ]; then \
		$(MAKE) $@ $(MFLAGS) -C $(DIR) || \
			if [ $(TEXT) = "french" ]; then \
				echo "-    Probleme avec le repertoire $(DIR)" ; \
			else \
				echo "-    Problem with directory $(DIR)" ; \
			fi ; \
	else \
		if [ $(TEXT) = "french" ]; then \
			echo "*     $(DIR) : absence de Makefile dans $(DIR)/$(DIR)" ; \
		else \
			echo "*     $(DIR) : no Makefile in $(DIR)/$(DIR)" ; \
		fi ; \
	fi ;


### CLEANING RULES #############################################################
# NB: other cleaning rules are in layer 3 Makefile

# Rule for deleting all useless files
# NB: objects files of any architectures will be deleted
clean:
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "     suppression des *~ *bak *tgz files-tgz-*.txt (s'ils existent)" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     deleting *~ *bak *tgz files-tgz-*.txt (if any)" ; \
	fi ; \
	rm -f *~ *bak *tgz files-tgz-*.txt ; \
	if [ -e $(DIR)/Makefile ]; then \
		$(MAKE) $@ $(MFLAGS) -C $(DIR) ; \
	else \
		if [ $(TEXT) = "french" ]; then \
			echo "*    $(DIR) : absence de Makefile dans $(DIR)/$(DIR)" ; \
		else \
			echo "*    $(DIR) : no Makefile in $(DIR)/$(DIR)" ; \
		fi ; \
	fi ;


### PACKAGING RULES ############################################################
# Building the list of files to include in the binary package
# or binary distribution when called by layer 1 Makefile.
# Depend on the local configuration in Makefile-var.
files-tgz-bin:
ifeq ($(strip $(TGZ_BIN)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	fi ; \
	if [ -e ./files-tgz-bin.txt ] ; then \
		rm ./files-tgz-bin.txt ; \
	fi ; \
	for F in $(TGZ_BIN) ; do \
		if [ -e $$F ]; then \
			echo $$F >> ./files-tgz-bin.txt ; \
		else \
			if [ $(TEXT) = "french" ]; then \
				echo "*    $(DIR) : $$F manquant" ; \
			else \
				echo "*    $(DIR) : $$F not found" ; \
			fi ; \
		fi ; \
	done ; \
	echo "$(DIR)" >> ./files-tgz-bin.txt ; \
	echo "$(DIR)-$(VERSION)" >> ./files-tgz-bin.txt ; \
	if [ -e $(DIR)/Makefile ]; then \
		$(MAKE) $@ $(MFLAGS) -C $(DIR) ; \
		for F in `cat $(DIR)/files-tgz-bin.txt 2> /dev/null` ; do \
			echo "$(DIR)-$(VERSION)/$$F" >> ./files-tgz-bin.txt ; \
		done ; \
	else \
		if [ $(TEXT) = "french" ]; then \
			echo "*    $(DIR) : absence de Makefile dans $(DIR)/$(DIR)" ; \
		else \
			echo "*    $(DIR) : no Makefile in $(DIR)/$(DIR)" ; \
		fi ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     $(DIR)/files-tgz-bin.txt pret" ; \
	else \
		echo "     $(DIR)/files-tgz-bin.txt generated" ; \
	fi ;
endif

# Building the list of files to include in the devel package
# or devel distribution when called by layer 1 Makefile.
# Depend on the local configuration in Makefile-var.
files-tgz-dev:
ifeq ($(strip $(TGZ_DEV)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	fi ; \
	if [ -e ./files-tgz-dev.txt ] ; then \
		rm ./files-tgz-dev.txt ; \
	fi ; \
	for F in $(TGZ_DEV) ; do \
		if [ -e $$F ]; then \
			echo $$F >> ./files-tgz-dev.txt ; \
		else \
			if [ $(TEXT) = "french" ]; then \
				echo "*    $(DIR) : $$F manquant" ; \
			else \
				echo "*    $(DIR) : $$F not found" ; \
			fi ; \
		fi ; \
	done ; \
	echo "$(DIR)" >> ./files-tgz-dev.txt ; \
	echo "$(DIR)-$(VERSION)" >> ./files-tgz-dev.txt ; \
	if [ -e $(DIR)/Makefile ]; then \
		$(MAKE) $@ $(MFLAGS) -C $(DIR) ; \
		for F in `cat $(DIR)/files-tgz-dev.txt 2> /dev/null` ; do \
			echo "$(DIR)-$(VERSION)/$$F" >> ./files-tgz-dev.txt ; \
		done ; \
	else \
		if [ $(TEXT) = "french" ]; then \
			echo "*    $(DIR) : absence de Makefile dans $(DIR)/$(DIR)" ; \
		else \
			echo "*    $(DIR) : no Makefile in $(DIR)/$(DIR)" ; \
		fi ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     $(DIR)/files-tgz-dev.txt pret" ; \
	else \
		echo "     $(DIR)/files-tgz-dev.txt generated" ; \
	fi ;
endif

# Building the list of files to include in the public package
# or public distribution when called by layer 1 Makefile.
# Depend on the local configuration in Makefile-var.
# NB: cannot use 		for F in $(shell cat $(DIR)/files-tgz-pub.txt 2> /dev/null) ; do
#     because shell expansion is done during the first reading and then the file
#     generated during sub-makefile call is not taken into account. Instead use
#     for F in `cat $(DIR)/files-tgz-pub.txt 2> /dev/null` : do

files-tgz-pub:
ifeq ($(strip $(TGZ_PUB)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	fi ; \
	if [ -e ./files-tgz-pub.txt ] ; then \
		rm ./files-tgz-pub.txt ; \
	fi ; \
	for F in $(TGZ_PUB) ; do \
		if [ -e $$F ]; then \
			echo $$F >> ./files-tgz-pub.txt ; \
		else \
			if [ $(TEXT) = "french" ]; then \
				echo "*    $(DIR) : $$F manquant" ; \
			else \
				echo "*    $(DIR) : $$F not found" ; \
			fi ; \
		fi ; \
	done ; \
	echo "$(DIR)" >> ./files-tgz-pub.txt ; \
	echo "$(DIR)-$(VERSION)" >> ./files-tgz-pub.txt ; \
	if [ -e $(DIR)/Makefile ]; then \
		$(MAKE) $@ $(MFLAGS) -C $(DIR) ; \
		for F in `cat $(DIR)/files-tgz-pub.txt 2> /dev/null` ; do \
			echo "$(DIR)/$$F" >> ./files-tgz-pub.txt ; \
		done ; \
	else \
		if [ $(TEXT) = "french" ]; then \
			echo "*    $(DIR) : absence de Makefile dans $(DIR)/$(DIR)" ; \
		else \
			echo "*    $(DIR) : no Makefile in $(DIR)/$(DIR)" ; \
		fi ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     $(DIR)/files-tgz-pub.txt pret" ; \
	else \
		echo "     $(DIR)/files-tgz-pub.txt generated" ; \
	fi ;
endif

# Building the list of files to include in the skeleton package
# or skeleton distribution when called by layer 1 Makefile.
# Depend on the local configuration in Makefile-var.
files-tgz-skl:
ifeq ($(strip $(TGZ_SKL)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	fi ; \
	if [ -e ./files-tgz-skl.txt ] ; then \
		rm ./files-tgz-skl.txt ; \
	fi ; \
	for F in $(TGZ_SKL) ; do \
		if [ -e $$F ]; then \
			echo $$F >> ./files-tgz-skl.txt ; \
		else \
			if [ $(TEXT) = "french" ]; then \
				echo "*    $(DIR) : $$F manquant" ; \
			else \
				echo "*    $(DIR) : $$F not found" ; \
			fi ; \
		fi ; \
	done ; \
	echo "$(DIR)" >> ./files-tgz-skl.txt ; \
	echo "$(DIR)-$(VERSION)" >> ./files-tgz-skl.txt ; \
	if [ -e $(DIR)/Makefile ]; then \
		$(MAKE) $@ $(MFLAGS) -C $(DIR) ; \
		for F in `cat $(DIR)/files-tgz-skl.txt 2> /dev/null` ; do \
			echo "$(DIR)-$(VERSION)/$$F" >> ./files-tgz-skl.txt ; \
		done ; \
	else \
		if [ $(TEXT) = "french" ]; then \
			echo "*    $(DIR) : absence de Makefile dans $(DIR)/$(DIR)" ; \
		else \
			echo "*    $(DIR) : no Makefile in $(DIR)/$(DIR)" ; \
		fi ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     $(DIR)/files-tgz-skl.txt pret" ; \
	else \
		echo "     $(DIR)/files-tgz-skl.txt generated" ; \
	fi ;
endif

# Building the binary package.
# Depend on the local configuration in Makefile-var.
tgz-bin: files-tgz-bin
ifeq ($(strip $(TGZ_BIN)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	  echo "     fabrication de l'archive airplug-$(DIR)-$(VERSION)-bin-$(ARCH)-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	  echo "     building archive airplug-$(DIR)-$(VERSION)-bin-$(ARCH)-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	fi ; \
	if  ! [ -e tgz-history.txt ] ; then \
		touch tgz-history.txt ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "$@ dans `pwd` sur `hostname` le `date +%A" "%d" "%B" "%Y" a "%k"h"%M":"%S`" >> tgz-history.txt ; \
	else	\
		echo "$@ in `pwd` on `hostname`, `date +%A" "%d" "%B" "%Y" at "%k"h"%M":"%S`" >> tgz-history.txt ; \
	fi ; \
	tar --hard-dereference -C .. --no-recursion -czf airplug-$(DIR)-$(VERSION)-bin-$(ARCH)-`hostname`-`date +%Y"-"%m"-"%d`.tgz `cat files-tgz-bin.txt | sed s%^%$(DIR)/%` ;
endif

# Building the public package.
# Depend on the local configuration in Makefile-var.
tgz-pub: files-tgz-pub
ifeq ($(strip $(TGZ_PUB)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	  echo "     fabrication de l'archive airplug-$(DIR)-$(VERSION)-pub-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	  echo "     building archive airplug-$(DIR)-$(VERSION)-pub-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	fi ; \
	if  ! [ -e tgz-history.txt ] ; then \
		touch tgz-history.txt ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "$@ dans `pwd` sur `hostname` le `date +%A" "%d" "%B" "%Y" a "%k"h"%M":"%S`" >> tgz-history.txt ; \
	else	\
		echo "$@ in `pwd` on `hostname`, `date +%A" "%d" "%B" "%Y" at "%k"h"%M":"%S`" >> tgz-history.txt ; \
	fi ; \
	tar --hard-dereference -C .. --no-recursion -czf airplug-$(DIR)-$(VERSION)-pub-`hostname`-`date +%Y"-"%m"-"%d`.tgz `cat files-tgz-pub.txt | sed s%^%$(DIR)/%` ;
endif

# Building the devel package. 
# Depend on the local configuration in Makefile-var.
tgz-dev: files-tgz-dev
ifeq ($(strip $(TGZ_DEV)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "     fabrication de l'archive airplug-$(DIR)-$(VERSION)-dev-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     building archive airplug-$(DIR)-$(VERSION)-dev-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	fi ; \
	if  ! [ -e tgz-history.txt ] ; then \
		touch tgz-history.txt ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "$@ dans `pwd` sur `hostname` le `date +%A" "%d" "%B" "%Y" a "%k"h"%M":"%S`" >> tgz-history.txt ; \
	else \
		echo "$@ in `pwd` on `hostname`, `date +%A" "%d" "%B" "%Y" at "%k"h"%M":"%S`" >> tgz-history.txt ; \
	fi ; \
	tar --hard-dereference -C .. --no-recursion -czf airplug-$(DIR)-$(VERSION)-dev-`hostname`-`date +%Y"-"%m"-"%d`.tgz `cat files-tgz-dev.txt | sed s%^%$(DIR)/%` ;
endif

# Building the skeleton package.
# Depend on the local configuration in Makefile-var.
tgz-skl: files-tgz-skl
ifeq ($(strip $(TGZ_SKL)),)
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "	   sans effet ici" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     no effect here" ; \
	fi ;
else
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	 	echo "     fabrication de l'archive airplug-$(DIR)-$(VERSION)-skl-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	 	echo "     building archive airplug-$(DIR)-$(VERSION)-skl-`hostname`-`date +%Y"-"%m"-"%d`.tgz" ; \
	fi ; \
	if  ! [ -e tgz-history.txt ] ; then \
		touch tgz-history.txt ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "$@ dans `pwd` sur `hostname` le `date +%A" "%d" "%B" "%Y" a "%k"h"%M":"%S`" >> tgz-history.txt ; \
	else \
		echo "$@ in `pwd` on `hostname`, `date +%A" "%d" "%B" "%Y" at "%k"h"%M":"%S`" >> tgz-history.txt ; \
	fi ; \
	tar --hard-dereference -C .. --no-recursion -czf airplug-$(DIR)-$(VERSION)-skl-`hostname`-`date +%Y"-"%m"-"%d`.tgz `cat files-tgz-skl.txt | sed s%^%$(DIR)/%` ;
endif


### DISTRIB MANAGEMENT RULES ###################################################
# Modify the current version of the application.
mod-version:
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@"; \
		echo "     version actuelle : $(VERSION)" ; \
		echo -n "     versions disponibles : " ; \
	else \
		echo " +++ $(DIR) : $@ rule"; \
		echo "     current version: $(VERSION)" ; \
		echo -n "     available versions: " ; \
	fi ; \
	for F in $(shell ls -d $(DIR)-* 2> /dev/null) ; do \
		echo -n `echo $$F | cut -d'-' -f 2 `" "; \
	done ; \
	echo ; \
	if [ $(TEXT) = "french" ]; then \
		echo -n "     nouvelle version : " ; \
	else \
		echo -n "     new version: " ; \
	fi ; \
	read new_version ; \
  if ! [ -e $(DIR)-$$new_version ]; then \
		if [ $(TEXT) = "french" ]; then \
			echo "-    $(DIR) : la version $$new_version n'existe pas ($(DIR)-$$new_version non trouve) ;" ; \
			echo "     vous pourrier creer une nouvelle version avec make new-version" ; \
		else \
			echo "-    $(DIR) : the version $$new_version does not exist ($(DIR)-$$new_version not found);" ; \
			echo "     you may create a new version by using make new-version" ; \
		fi ; \
		exit ; \
	fi ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     test d'existence de $(DIR)-$$new_version : ok" ; \
	else \
		echo "     testing the existence of $(DIR)-$$new_version: ok" ; \
	fi ; \
	if ! [ -e $(DIR) ]; then \
		if [ $(TEXT) = "french" ]; then \
			echo "*    pas de version valide trouvee (aucun lien WHA --> WHA-vX.YZ valide)" ; \
		else \
			echo "*    no current valid version (no valid link WHA --> WHA-vX.YZ)" ; \
		fi ; \
		if [ $(TEXT) = "french" ]; then \
			echo "     positionnement de la version courante sur $$new_version" ; \
		else \
			echo "     setting the current version to $$new_version" ; \
		fi ; \
	else \
		if [ `readlink $(DIR)` = $(DIR)-$$new_version ]; then \
			if [ $(TEXT) = "french" ]; then \
				echo "*    $$new_version est deja la version actuelle" ; \
			else \
				echo "*    $$new_version is already the current version" ; \
			fi ; \
			exit ; \
		fi ; \
		if [ $(TEXT) = "french" ]; then \
			echo "     test de modification : $(VERSION) != $$new_version : ok" ; \
		else \
			echo "     testing the modification: $(VERSION) != $$new_version: ok" ; \
		fi ; \
		if [ $(TEXT) = "french" ]; then \
			echo "     passage de la version $(VERSION) a $$new_version" ; \
		else \
			echo "     jump from version $(VERSION) to $$new_version" ; \
		fi ; \
	fi ; \
	\rm -f $(DIR) 2> /dev/null ; \
	ln -s $(DIR)-$$new_version $(DIR) ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     lien $(DIR) --> $(DIR)-$$new_version cree" ; \
		echo "     la version courrante est maintenant : $(DIR)-$$new_version" ; \
	else \
		echo "     link $(DIR) --> $(DIR)-$$new_version created" ; \
		echo "     current version is now: $(DIR)-$$new_version" ; \
	fi ;

# Add a new version of the application.
incr new-version:
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
	fi ; \
	if ! [ -e $(DIR)-$(VERSION) ] ; then \
		if [ $(TEXT) = "french" ]; then \
			echo "-    $(DIR) : la version actuelle n'est pas valide (pas de lien valide $(DIR)-vX.YZ)" ; \
			echo "     vous pouvez reparer cela avec make mod-version" ; \
		else \
			echo "-    $(DIR) : current version is not valid (no valid link $(DIR)-vX.YZ)" ; \
			echo "     you may repair this using make mod-version" ; \
		fi ; \
		exit ; \
	fi ; \
	current_version_nb=`echo $(VERSION) | cut -d 'v' -f 2 ` ; \
	new_version_nb=`echo "$(VERSION_STEP) + $$current_version_nb" | bc` ; \
	if [ `echo "$$new_version_nb < 1.0" | bc` ] ; then \
		new_version_nb="0$$new_version_nb" ; \
	fi ; \
	new_version_nb=$${new_version_nb/%0/} ; \
	new_version_nb=$${new_version_nb/%.0/} ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     passage de la version $(VERSION) a v$$new_version_nb" ; \
	else \
		echo "     jump from version $(VERSION) to v$$new_version_nb" ; \
	fi ; \
	if [ -e $(DIR)-v$$new_version_nb ]; then \
		if [ $(TEXT) = "french" ]; then \
			echo "-    $(DIR) : $(DIR)-v$$new_version_nb existe deja ;" ; \
			echo "     vous pourrier modifier le numero de version actuel avec make mod-version" ; \
		else \
			echo "-    $(DIR) : $(DIR)-v$$new_version_nb already exists;" ; \
			echo "     you may modify the current version number using make mod-version" ; \
		fi ; \
		exit ; \
	fi ; \
	cp -r $(DIR)-$(VERSION) $(DIR)-v$$new_version_nb ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     repertoire $(DIR)-v$$new_version_nb cree a partir de $(DIR)-$(VERSION)" ; \
	else \
		echo "     directory $(DIR)-v$$new_version_nb created from $(DIR)-$(VERSION)" ; \
	fi ; \
	rm $(DIR) ; \
	ln -s $(DIR)-v$$new_version_nb $(DIR) ; \
	if [ $(TEXT) = "french" ]; then \
		echo "     lien $(DIR) --> $(DIR)-v$$new_version_nb cree" ; \
		echo "     la version courrante est maintenant : $(DIR)-v$$new_version_nb" ; \
	else \
		echo "     link $(DIR) --> $(DIR)-v$$new_version_nb created" ; \
		echo "     current version is now: $(DIR)-v$$new_version_nb" ; \
	fi ;

# Display information on the current version of the application.
show-version:
	@if [ $(TEXT) = "french" ]; then \
		echo " +++ $(DIR) : regle $@" ; \
		echo "     repertoire d'installation = $(DIR_INSTALL)" ; \
		echo "     version utilisee = $(VERSION)" ; \
		echo "     license   =`cat license.txt | grep "license type:" | cut -d':' -f2`" ; \
		echo "     auteur(s) =`cat license.txt | grep "software author(s):" | cut -d':' -f2`" ; \
	else \
		echo " +++ $(DIR) : $@ rule" ; \
		echo "     install directory = $(DIR_INSTALL)" ; \
		echo "     current version = $(VERSION)" ; \
	  echo "     license   =`cat license.txt | grep "license type:" | cut -d':' -f2`" ; \
	  echo "     author(s) =`cat license.txt | grep "software author(s):" | cut -d':' -f2`" ; \
	fi ;

# Used by the newapp.sh shell script.
print-tgz-dev:
	@echo "$(TGZ_DEV)"



