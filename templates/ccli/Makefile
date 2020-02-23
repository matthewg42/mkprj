
BUILD_DIR = build
CFLAGS += -DDEBUG -g
LFLAGS += 
SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .c,.o,$(SRC)))
CC = gcc
TARGET = __PROGNAME__

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(LFLAGS) $^

$(BUILD_DIR)/%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)

