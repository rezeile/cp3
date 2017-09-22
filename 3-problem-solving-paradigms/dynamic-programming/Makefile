CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= the-jackpot.cc count-ways.cc luggage.cc \
          divisible-group.cc lis.cc max-sum.cc  \
          how-do-you-add.cc history-grading.cc\
          catcher.cc babylon.cc getting-in-line.cc \
					max-tortoise.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(PROGFILES) $(SYMFILES)
