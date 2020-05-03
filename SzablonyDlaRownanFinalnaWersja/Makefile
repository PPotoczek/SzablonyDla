CFLAGS=-Wall -pedantic -std=c++17
LFLAGS=-lm
OBJS=main.o LZespolona.o
EXEC=open

all: $(EXEC)

$(EXEC): $(OBJS)
			g++ $(LFLAGS) $+ -o $@

%.o: %.cpp
			g++ -c $(CFLAGS) $<

main.o: UkladRownanLiniowych.hh Macierz.hh Wektor.hh LZespolona.hh
LZespolona.o: LZespolona.hh


clean:
			rm -f *~
			rm -f *.bak
			rm -f $(EXEC) $(OBJS)

.PHONY: clean