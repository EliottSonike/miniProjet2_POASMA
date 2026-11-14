CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = $(wildcard src/*.cpp src/strategies/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
HDR = $(wildcard src/*.hpp src/strategies/*.hpp)

tournoi: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp $(HDR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build tournoi

.PHONY: clean
