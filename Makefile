CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SOURCES = $(wildcard *.c)

TARGETS = $(patsubst %.c,%,$(SOURCES))

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) *.o

RUN_ARG := $(firstword $(filter-out run,$(MAKECMDGOALS)))

run:
	@if [ -z "$(RUN_ARG)" ]; then \
		echo "Usage: make run <name_or_number>"; \
		echo "Example: make run 1"; \
		echo "Example: make run extra"; \
		exit 1; \
	fi
	@$(eval SOURCE_FILE := $(firstword $(wildcard $(RUN_ARG).*.c $(RUN_ARG).c)))
	@if [ -z "$(SOURCE_FILE)" ]; then \
		echo "Error: No source file found for '$(RUN_ARG)'"; \
		exit 1; \
	fi
	@$(eval TARGET_NAME := $(patsubst %.c,%,$(SOURCE_FILE)))
	@echo "--- Compiling and running $(SOURCE_FILE) ---"
	@$(CC) $(CFLAGS) -o $(TARGET_NAME) $(SOURCE_FILE) -lm
	@./$(TARGET_NAME)
	@echo "--- Done ---"


.PHONY: all clean run