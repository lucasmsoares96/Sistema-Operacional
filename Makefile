all: build
	g++ -std=c++11 -Wall -Wextra -Werror ./src/hardware/*.cpp ./src/*.cpp -o ./bin/MiShell
run: 
	clear && ./bin/MiShell 
debug:
	clear && clang++ -fstandalone-debug -g -O0 ./src/*.c && lldb ./bin/MiShell 
clean:
	rm -rf ./bin/*
build:
	@mkdir -p ./bin/