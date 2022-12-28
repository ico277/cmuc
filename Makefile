PREFIX = /usr/local
CC = gcc
CFILES = $(wildcard src/*.c)
EXECUTABLE = cmuc
CFLAGS = -O2

.PHONY: build install uninstall clean run debug

build: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFILES) -o $(EXECUTABLE) $(CFLAGS)

install: ./$(EXECUTABLE)
	cp ./$(EXECUTABLE) $(PREFIX)/bin/

uninstall: $(PREFIX)/bin/$(EXECUTABLE)
	rm $(PREFIX)/bin/$(EXECUTABLE)

clean:
	rm ./$(EXECUTABLE) 2> /dev/null || true
	rm ./$(EXECUTABLE)_debug 2> /dev/null || true
	rm ./vgcore* 2> /dev/null || true

run: build
	./$(EXECUTABLE)

debug: clean
	$(CC) $(CFILES) -o $(EXECUTABLE)_debug $(CFLAGS) -g
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)_debug

