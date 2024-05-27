COMPILER     = -c++
#COMPILER    = -clang
OPTIONS      =  -Wall -Wextra -O3 -std=c++14 -I./inc -o 
OPTIONS_LIBS =  -Wall -Wextra -O3 -std=c++14 -I./inc -c 
LINKER_OPT   = -L/usr/lib -lstdc++ -lm

CPP_SRC =

OBJECTS = $(CPP_SRC:.cpp=.o)
.PHONY: geometry_cpp_build
%.o: inc/%.hpp src/%.cpp
	$(COMPILER) $(OPTIONS_LIBS) $*.cpp -o $@

all: $(OBJECTS) geometry_cpp_build 

build/geometry_cpp_build : src/geometry_cpp_build.cpp inc/geometry_cpp.hpp inc/geometry_cpp_math.hpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) build/geometry_cpp_build src/geometry_cpp_build.cpp $(OBJECTS) $(LINKER_OPT)

geometry_cpp_build: build/geometry_cpp_build

clean:
	rm -f core *.o *.bak *stackdump
	rm -f build/*
