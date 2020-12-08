all: main

main: main.cpp candy.cpp inventory.cpp
	g++ main.cpp candy.cpp inventory.cpp -o main -lm

clean:
	rm main
