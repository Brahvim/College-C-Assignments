CC = gcc
CFLAGS = # -Wall -Wextra

# Write the name of your source file here!:
NAME = B5
SRCS = $(NAME).c scan-api-impls/IoUtilsByBrahvim.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE = $(NAME).out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(OBJS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)

remake: clean all

.PHONY: all clean remake
