compiler = g++


cppFiles = main.cpp
headers = 
SFML = -lsfml-audio -lsfml-window -lsfml-system
GTK = `pkg-config --cflags --libs gtk+-3.0`


libs = $(GTK) $(SFML)

object = chuuPlayer

default:
	$(compiler) $(cppFiles) $(headers) $(libs) -o $(object)
	./$(object)

