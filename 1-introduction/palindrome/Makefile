CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -g -Wall
SRCFILES= palindromes.cc magic-square.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(PROGFILES) $(SYMFILES)
