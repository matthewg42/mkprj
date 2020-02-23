
BUILD_DIR = build
CFLAGS += -DDEBUG -g
LFLAGS += 
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.hpp) $(wildcard *.h)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .cpp,.o,$(SRC)))
CXX = g++
TARGET = test

.PHONY: clean run format unformat

run: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $(LFLAGS) $^

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) -c -o $@ $(CFLAGS) $<

format:
	astyle --project=.astylerc $(SRC) $(HDR)

unformat:
	rename '.orig' '' *.orig

clean:
	rm -f $(OBJ) $(TARGET) *.orig

