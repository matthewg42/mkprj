
BUILD_DIR = build
CFLAGS += -DDEBUG -g
LFLAGS += 
SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .c,.o,$(SRC)))
GCC = gcc
TARGET = test

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(GCC) -o $@ $(LFLAGS) $^

$(BUILD_DIR)/%.o : %.c
	$(GCC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)

