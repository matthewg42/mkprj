
BUILD_DIR = build
CFLAGS += -DDEBUG -g
LFLAGS += 
SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .c,.o,$(SRC)))
CC = gcc
TARGET = test

.PHONY: clean run format unformat

run: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(LFLAGS) $^

$(BUILD_DIR)/%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<

format:
	astyle --project=.astylerc $(SRC) $(HDR)

unformat:
	rename '.orig' '' *.orig

clean:
	rm -f $(OBJ) $(TARGET) *.orig

