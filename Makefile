
CFLAGS=`pkg-config --cflags --libs gio-2.0`
LIBS=`pkg-config --libs gio-2.0`

all:
	gcc -Wall $(CFLAGS) main.c $(LIBS) -o main
