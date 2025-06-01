CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -I /usr/include/eigen3
LDFLAGS = -lgtest -lgtest_main -pthread

SRC = main.cpp solver.cpp generator.cpp work_csv.cpp
TEST_SRC = tests.cpp solver.cpp generator.cpp

.PHONY: all run test clean

all: solver

solver: $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: test_gauss
	./test_gauss

test_gauss: $(TEST_SRC) tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

run: solver
	./solver

clean:
	rm -f solver test_gauss
