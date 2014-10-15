CFLAGS = -I/usr/X11R6/include
LDLIBS = -L/usr/X11R6/lib -lglut -lGLU -lGL -lXmu -lXi -lXext -lX11 -lm -lpthread
a.out: graph.c
	$(CC) $(CFLAGS) graph.c $(LDLIBS)
