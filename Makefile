CXX=g++
CFLAGS=-I./include


default: drafter

run: drafter
	./drafter

gdb: drafter
	gdb --args drafter

drafter: src/main.cpp
	$(CXX) -g -O0 -o drafter -I/home/lbell/Drafter/include src/main.cpp -lyaml-cpp

clean: 
	rm -f drafter
