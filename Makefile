all: sim

sim: shell.cpp sim.cpp
	g++ -g -O2 -DDEBUG_FLAG $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o *~ sim
