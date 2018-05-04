CC = cc
CFLAGS= -w -c -g -I. -I/u1/junk/Game/cs67302/include
LDFLAGS= -L/usr/X11/lib -L/u1/junk/Game/cs67302/lib
LIBS= -lmug02 -lglut -lGLU -lGL -lX11 -lm

main: main.o datafiles.o build.o ui.o monsters.o
	$(CC) -g $(LDFLAGS) main.o datafiles.o build.o ui.o monsters.o $(LIBS) -o $@
main.o: main.c main.h
	$(CC) $(CFLAGS) main.c
datafiles.o: datafiles.c main.h
	$(CC) $(CFLAGS) datafiles.c
build.o: build.c main.h
	$(CC) $(CFLAGS) build.c
monsters.o: monsters.c main.h
	$(CC) $(CFLAGS) monsters.c
ui.o: ui.c main.h
	$(CC) $(CFLAGS) ui.c
clean:
	rm -f *.o main
