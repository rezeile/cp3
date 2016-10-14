CC= g++
RM= rm -vf
CPPFLAGS= -std=c++11 -Wall -g
SRCFILES= cost-cutting.cc nlogonia.cc \
          car-buyer.cc horse-dash.cc \
          snail.cc
OBJFILES= $(patsubst %.cc, %.o, $(SRCFILES))
PROGFILES= $(patsubst %.cc, %, $(SRCFILES))
SYMFILES=$(patsubst %.cc, %.dSYM, $(SRCFILES))

.PHONY: all clean

all: $(PROGFILES)
clean:
	rm -rf $(PROGFILES) $(SYMFILES)
