CC := gcc
CC_STANDARD := -std=gnu23
CC_OPT := -m64 -O3
CC_WARN := -Wall -Wextra -Werror -Wpedantic -Wno-format-truncation 

CFLAGS := $(CC_STANDARD) $(CC_OPT) $(CC_WARN)

.PHONY: all
all: *.c 
	$(CC) $(CFLAGS) $^ -o mmkdir

.PHONY: clean
clean:
	rm -rf *.o mkdir