CC = g++
CFLAGS = -Wall
PROG = crabpong

SRCS = main.cpp game.cpp gamedrawer.cpp imageloader.cpp md2model.cpp text3d.cpp vec3f.cpp

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lGL -lGLU -lglut 
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
