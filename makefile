CXX = g++
CXXFLAGS = -std=c++11
LIBS = `pkg-config --cflags --libs gtk+-3.0` -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
TARGET = ChuuPlayer
CPP_FILES = main.cpp audio.cpp
H_FILES = audio.h
default:
	$(CXX) $(CXXFLAGS) $(CPP_FILES) $(H_FILES) -o $(TARGET) $(LIBS)
	./$(TARGET)

clean:
	rm -f $(TARGET)
