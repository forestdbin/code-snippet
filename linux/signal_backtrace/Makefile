CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g -rdynamic -O0
LDFLAGS = -pthread
TARGET = signal_demo
SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

clean:
	rm -f $(TARGET)

help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Show this help message"

.PHONY: all clean help
