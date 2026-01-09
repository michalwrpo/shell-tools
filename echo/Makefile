CC := gcc
CC_STANDARD := -std=gnu23
CC_OPT := -m64 -O3
CC_WARN := -Wall -Wextra -Werror -Wno-format-truncation 

CFLAGS := $(CC_STANDARD) $(CC_OPT) $(CC_WARN)

.PHONY: all
all: mecho.c numbases.c strnum.c
	$(CC) $(CFLAGS) $^ -o mecho


.PHONY: clean
clean:
	rm -rf *.o mls