CC = cc
CFLAGS= -w -c -g -I.
LDFLAGS= -L/usr/X11/lib
LIBS= -lglut -lGLU -lGL -lX11 -lm
OBJS= main.o datafiles.o build.o ui.o missile.o kaboom.o

main: $(OBJS)
	$(CC) -g $(LDFLAGS) $(OBJS) $(LIBS) -o $@
main.o: main.c main.h
	$(CC) $(CFLAGS) main.c
datafiles.o: datafiles.c main.h
	$(CC) $(CFLAGS) datafiles.c
build.o: build.c main.h
	$(CC) $(CFLAGS) build.c
ui.o: ui.c main.h
	$(CC) $(CFLAGS) ui.c
missile.o: missile.c main.h
	$(CC) $(CFLAGS) missile.c
kaboom.o: kaboom.c main.h
	$(CC) $(CFLAGS) kaboom.c
clean:
	rm -f *.o main
