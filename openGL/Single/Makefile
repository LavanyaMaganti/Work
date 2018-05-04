CC = cc
CFLAGS= -w -c -pg -I. -I/u1/junk/Game/cs67301/include
LDFLAGS= -L/usr/X11/lib -L/u1/junk/Game/cs67301/lib
LIBS= -lmug01 -lglut -lGLU -lGL -lX11 -lm

main: main.o ppm.o build.o ui.o
	$(CC) -g $(LDFLAGS) main.o ppm.o build.o ui.o $(LIBS) -o $@
main.o: main.c main.h
	$(CC) $(CFLAGS) main.c
ppm.o: ppm.c main.h
	$(CC) $(CFLAGS) ppm.c
build.o: build.c main.h
	$(CC) $(CFLAGS) build.c
ui.o: ui.c main.h
	$(CC) $(CFLAGS) ui.c
clean:
	rm -f *.o main
