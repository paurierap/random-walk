# Makefile structure:
# target: prerequisites
#	commands

# DO NOT COMPILE HEADER FILES!

# Variables to control Makefile operation
LIB_DIR = lib

# Find all the C++ files we want to compile
SRCS := $(shell find $(LIB_DIR) -name '*.cpp')

# Prepends MAIN_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./your_dir/hello.cpp.o
OBJS := $(SRCS:$(LIB_DIR)/%=%.o)

# Compilation flags
CXX = g++
CXXFLAGS = -Wall -O2 #-I /$(INC_DIR)

# $^ references all prerequisites, and $@ references the target name
main: main.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $^

# Build step for C++ source
%.cpp.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

debug: CXXFLAGS += -O0 -g
debug: main

profile: CXXFLAGS += -O0 -pg
profile: main

# "$ make clean" to remove all object files
clean:
	rm *.o