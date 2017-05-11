CC = g++
CXXFLAGS = -std=c++14 -m64 -Wall -c -fno-use-cxa-atexit -fPIC
LDFLAGS = -nostartfiles -nostdlib -m64 -shared

SOURCES=./src/chameleon.cc ./src/hooks/FrameStageNotify.cc ./src/hooks/FireEventClientSide.cc
OBJECTS=$(SOURCES:.cc=.o)

OUT := libchameleon-csgo.so

all: clean build

clean:
	rm -vf $(OBJECTS) $(OUT)

%.o: ../%.cc
	$(CC) $(CFLAGS) $(CFLAGS) -o "$@" "$<"

build: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUT) $(LDFLAGS)
