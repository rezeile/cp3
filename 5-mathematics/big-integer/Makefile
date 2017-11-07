JFLAGS = -g

JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
        VeryEasy.java \
				Emirp.java \
				ReverseAdd.java \
				MultOf17.java
default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
