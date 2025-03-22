CXX = g++
CXXFLAGS = -std=c++11 -I include
SRCS = game/pilgrimage.cc src/system.cpp src/component.cpp src/iocomponent.cpp
OBJS = $(SRCS:.cc=.o)
TARGET = pilgrimage

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
PHONY: clean exec

clean:
	rm -f $(OBJS) $(TARGET)
	
exec: $(TARGET)
	./$(TARGET)
	make clean
