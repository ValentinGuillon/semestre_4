
CC= c++
CFLAGS= -Wall -Wextra -g -std=c++17
PROGS= namespace #heritage #notes array vector deque map

all: clean $(PROGS) soft_clean

note:
	$(CC) $(CFLAGS) $@.cpp -o $@

namespace:
	$(CC) $(CFLAGS) $@.cpp -o $@

array:
	$(CC) $(CFLAGS) $@.cpp -o $@

vector:
	$(CC) $(CFLAGS) $@.cpp -o $@

deque:
	$(CC) $(CFLAGS) $@.cpp -o $@

map:
	$(CC) $(CFLAGS) $@.cpp -o $@

heritage:
	$(CC) $(CFLAGS) $@.cpp -o $@




soft_clean:
	@find . -name "*.o" -delete

clean:
	@rm -f $(PROGS)
	@find . -name "*.o" -delete
