all: sim

sim: shell.c sim.c
	gcc -g -O2 -DDEBUG_FLAG $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o *~ sim
