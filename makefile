all:
	g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o basicHash basic_passwordHash.cpp -lcryptopp

clean:
	rm basicHash
