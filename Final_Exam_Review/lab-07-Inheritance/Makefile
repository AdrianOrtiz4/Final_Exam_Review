########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = lab-07-multiple-inheritance-and-abstract-classes
EXT = .cpp
LIBEXT = .hpp
SRCDIR = src
BINDIR = bin
OBJDIR = $(BINDIR)/obj

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(BINDIR)/etc/%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(BINDIR)/$(APPNAME)

# Make directories if not present.
$(shell mkdir -p bin/obj)
$(shell mkdir -p bin/etc)
#$(shell mkdir -p out)

# Builds the app
$(BINDIR)/$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
$(BINDIR)/etc/%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:$(BINDIR)/etc/%.d=$(OBJDIR)/%.o) >$@

# Includes all .h and .hpp files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

# FOR LAB03-git-github

# Clear
clearscr: 
	clear

#Run the app
.PHONY: run
run: all clearscr mkrun
mkrun: 
	./$(BINDIR)/$(APPNAME)

.PHONY: runw
runw: all clearscr mkrunw
mkrunw:
	./$(BINDIR)/$(APPNAME)$(EXE)

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(BINDIR)/$(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(BINDIR)/$(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)