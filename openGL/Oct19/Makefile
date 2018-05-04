CC = cc
CFLAGS= -c -O
LDFLAGS= -L/usr/X11/lib
LIBS= -lglut -lGLU -lGL -lX11 -lm

main: main.o ppm.o build.o ui.o maze.o
	$(CC) -g $(LDFLAGS) main.o ppm.o build.o ui.o maze.o $(LIBS) -o $@
main.o: main.c main.h
	$(CC) $(CFLAGS) main.c
ppm.o: ppm.c main.h
	$(CC) $(CFLAGS) ppm.c
build.o: build.c main.h
	$(CC) $(CFLAGS) build.c
maze.o: maze.c main.h
	$(CC) $(CFLAGS) maze.c
ui.o: ui.c main.h
	$(CC) $(CFLAGS) ui.c
clean:
	rm -f *.o main
