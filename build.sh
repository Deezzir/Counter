#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra `pkg-config --cflags raylib`"
LIBS="`pkg-config --libs raylib` `pkg-config --libs glfw3` -lm -ldl -lpthread"

g++ $CFLAGS -o counter counter.cpp $LIBS