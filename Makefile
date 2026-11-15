CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Sous Windows l'executable s'appelle tournoi.exe, sous Linux ou macOS tournoi
ifeq ($(OS),Windows_NT)
    EXE = tournoi.exe
else
    EXE = tournoi
endif

SRC = $(wildcard src/*.cpp src/strategies/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
HDR = $(wildcard src/*.hpp src/strategies/*.hpp)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp $(HDR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build tournoi tournoi.exe

.PHONY: clean
