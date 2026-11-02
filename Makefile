CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra
LDLIBS ?= -lm

BINS := $(patsubst src/%.c,build/%,$(wildcard src/*.c))

.PHONY: all test clean

all: $(BINS)

test:
	uv run pytest

build/%: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

clean:
	rm -rf build
