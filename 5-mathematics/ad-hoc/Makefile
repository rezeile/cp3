CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= skew-binary.cc perfection.cc peters-smokes.cc \
  	  cantor.cc digit-counting.cc \
	  numbering-roads.cc humble.cc \
	  brick.cc smith.cc parity.c \
	  back2intermediate.cc ant.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(PROGFILES) $(SYMFILES)
