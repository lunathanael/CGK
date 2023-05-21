SRCS=$(wildcard *.cpp)
NAME=CGK

all :
	g++ -Og $(SRCS) -o $(NAME)
release :
	g++ -Ofast $(SRCS) -static -o $(NAME)

