BINARY_NAME := kit 
COMPILE_FLAGS := -Os -O3 -Wall -Wextra -Werror -std=c99 -pedantic
SRCS := main.c
LINKS :=

all: $(SRCS) 
	gcc $(COMPILE_FLAGS) $(SRCS) $(LINKS) -o $(BINARY_NAME)

clean:
	rm -rf $(BINARY_NAME)
