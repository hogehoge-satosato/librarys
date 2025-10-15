CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -std=c11 -g -MMD -MP

LIB_NAME = libgetchr.a
TARGET = get_unget_test

LIB_SRCS = getchr.c ungetchr.c
LIB_OBJS = $(LIB_SRCS:.c=.o)
LIB_DEPS = $(LIB_OBJS:.o=.d)

TEST_SRCS = get_unget_test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_DEPS = $(TEST_OBJS:.o=.d)

all: $(TARGET)

$(LIB_NAME): $(LIB_OBJS)
	$(AR) rcs $@ $^

$(TARGET): $(TEST_OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) -L. -lgetchr

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJS) $(TEST_OBJS) $(LIB_NAME) $(TARGET) $(LIB_DEPS) $(TEST_DEPS)
finish:
	rm -f $(LIB_OBJS) $(TEST_OBJS) $(LIB_NAME) $(LIB_DEPS) $(TEST_DEPS)

-include $(LIB_DEPS) $(TEST_DEPS)