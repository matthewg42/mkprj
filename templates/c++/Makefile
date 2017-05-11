
CFLAGS += -DDEBUG
LFLAGS += 
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.hpp) $(wildcard *.h)
OBJ = $(subst .cpp,.o,$(SRC))
GCC = g++
TARGET = test

.PHONY: clean run

$(TARGET) : $(OBJ)
	$(GCC) -o $@ $(LFLAGS) $<

run: $(TARGET)
	./$(TARGET)

%.o : %.cpp
	$(GCC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)


