# 
# Makefile k 2. projektu do predmetu IVS - Stahni a spocti paritu
# Author:	Pavel Slaby, xslaby00@stud.fit.vutbr.cz
# 29.2.2012
#

BIN=xslaby00

CC=gcc
CFLAGS=-std=gnu99 -Wall -pedantic -g
SOURCES=test.c matlib.c matlib.h
#OBJECTS=$(SOURCES:.c=.o)
CURL_LOCATION=#-I../curl/include/ -L ../curl/lib/.libs/

all:  

clean: 
	rm $(BIN) *.o 

test: matlib.o test.o
	$(CC) $(CFLAGS) -o $(BIN) test.o matlib.o -lm

doc: main.h main.c download.c parity.c 
	doxygen Doxyfile
	
$(PART).o: $(PART).c matlib.h
	$(CC) $(CFLAGS) -c -o $(PART).o $(PART).c
