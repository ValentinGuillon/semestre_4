
CC= c++
CFLAGS= -Wall -Wextra -g -std=c++17
PROGS= namespace array vector deque map lvalue_rvalue heritage

all: clean $(PROGS) soft_clean

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

lvalue_rvalue:
	$(CC) $(CFLAGS) $@.cpp -o $@

heritage:
	$(CC) $(CFLAGS) $@.cpp -o $@




soft_clean:
	@find . -name "*.o" -delete

clean:
	@rm -f $(PROGS)
	@find . -name "*.o" -delete
