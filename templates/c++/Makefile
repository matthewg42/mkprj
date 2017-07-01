
CFLAGS += -DDEBUG
LFLAGS += 
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.hpp) $(wildcard *.h)
OBJ = $(subst .cpp,.o,$(SRC))
GCC = g++
TARGET = test

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(GCC) -o $@ $(LFLAGS) $^

%.o : %.cpp
	$(GCC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)


