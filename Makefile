#
# Makefile k 3. projektu do predmetu IVS - Kalkulacka
#
# Autori: Pavel Slaby, xslaby00@stud.fit.vutbr.cz
#         Peter Slosar, xslosa00@stud.fit.vutbr.cz
#         Martin Slezacek, xsleza18@stud.fit.vutbr.cz
# Datum:  26. 4. 2012

.PHONY: doc

all: kalkulacka

kalkulacka:
	qmake -project -o ./src/kalkulacka.pro
	qmake -o ./src/Makefile ./src/kalkulacka.pro
	make -C src

clean: 
	rm -f *~
	rm -rf doc/*
	rm -f src/*.o
	rm -f src/ui_*
	rm -f src/moc_*
	rm -f src/Makefile

#test: matlib.o test.o
#	$(CC) $(CFLAGS) -o $(BIN) test.o matlib.o -lm

doc:
	doxygen Doxyfile
