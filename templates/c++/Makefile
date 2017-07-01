
BUILD_DIR = build
CFLAGS += -DDEBUG
LFLAGS += 
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.hpp) $(wildcard *.h)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .cpp,.o,$(SRC)))
GCC = g++
TARGET = test

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(GCC) -o $@ $(LFLAGS) $^

$(BUILD_DIR)/%.o : %.cpp
	$(GCC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)
	rmdir $(BUILD_DIR)


