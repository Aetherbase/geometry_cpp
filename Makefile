COMPILER     = -c++
#COMPILER    = -clang
OPTIONS      =  -Wall -Wextra -O3 -std=c++14 -o 
OPTIONS_LIBS =  -Wall -Wextra -O3 -std=c++14 -c 
LINKER_OPT   = -L/usr/lib -lstdc++ -lm

CPP_SRC =

OBJECTS = $(CPP_SRC:.cpp=.o)
.PHONY: geometry_cpp_build
%.o: %.hpp %.cpp
	$(COMPILER) $(OPTIONS_LIBS) $*.cpp -o $@

all: $(OBJECTS) geometry_cpp_build 

build/geometry_cpp_build : geometry_cpp_build.cpp geometry_cpp.hpp geometry_cpp_math.hpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) geometry_cpp_build geometry_cpp_build.cpp $(OBJECTS) $(LINKER_OPT)

geometry_cpp_build: build/geometry_cpp_build

clean:
	rm -f core *.o *.bak *stackdump


#
# The End !
#
