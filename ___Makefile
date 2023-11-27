all: test

test: main.cpp
	g++ -g -O2 -std=c++11 -DDEBUG_FLAG $^ -o $@ -I SDL2/include -I imgui -I imgui/backends -L SDL2/lib -l SDL2-2.0.0 -L SDL2_ttf/lib -l SDL2_ttf-2.0.0  -L SDL2_image/lib -l SDL2_image-2.0.0

.PHONY: clean
clean:
	rm -rf *.o *~ test
