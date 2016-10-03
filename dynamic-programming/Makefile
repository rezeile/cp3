CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= max-sum.cc the-jackpot.cc 
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(PROGFILES) $(SYMFILES)
