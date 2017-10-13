CC= g++
RM= rm -vf
CPPFLAGS= -lm  -O2 -std=c++11 -pipe 
SRCFILES= bicoloring.cc ordertasks.cc \
					connectivity.cc network.cc \
					oil.cc 
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(PROGFILES) $(SYMFILES)
