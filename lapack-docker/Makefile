TOPSRCDIR = ../..
include $(TOPSRCDIR)/make.inc
.SUFFIXES: .c .o
.c.o:
        $(CC) $(CFLAGS) -I. -I../include -c -o $@ $<
.PHONY: all
all: lp_ex1
LIBRARIES = $(LAPACKELIB) $(LAPACKLIB) $(BLASLIB)
# Double Precision Examples
lp_ex1: lp_ex1.o $(LIBRARIES)
        $(FC) $(FFLAGS) $(LDFLAGS) -o $@ $^
        ./$@
.PHONY: clean cleanobj cleanexe
clean: cleanobj cleanexe
cleanobj:
        rm -f *.o
cleanexe:
        rm -f x*