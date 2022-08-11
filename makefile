CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3
TARGET = fun_with_func_ptrs

all: $(TARGET)

$(TARGET) : main.o 
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET)