# Wren's C Makefile :)
TARGET := tcb
CC := clang++
CFLAGS := -O1 -g3 -Isrc
LDFLAGS := -O1 -g3
SOURCE := src
BUILD := target

EXT := cpp
HEXT := hpp

SOURCES := $(wildcard $(SOURCE)/**.$(EXT))
HEADERS := $(wildcard $(SOURCE)/**.$(HEXT))
OBJFILES := $(patsubst $(SOURCE)/%,$(BUILD)/%,$(SOURCES:.$(EXT)=.o))

WARNINGS := -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wcast-qual -Wcast-align
FULLCFLAGS := $(CFLAGS) $(WARNINGS)
FULLLDFLAGS := $(LDFLAGS) $(WARNINGS)

.PHONY: run all fmt clean bear

run: $(TARGET)
	@echo -e "\x1b[1m ⇒ \x1b[31mRunning '$(TARGET)'\x1b[0m"
	@./$(TARGET)

all: $(TARGET)

fmt:
	@echo -e "\x1b[1m ⇒ \x1b[35mAuto formatting\x1b[0m"
	@clang-format -i $(SOURCES) $(HEADERS)

lint:
	@echo -e "\x1b[1m ⇒ \x1b[35mLinting\x1b[0m"
	@clang-tidy $(SOURCES) $(HEADERS) -- $(FULLCFLAGS)

clean:
	@echo -e "\x1b[1m ⇒ \x1b[33mRemoving build files\x1b[0m"
	@rm -rf $(TARGET) $(BUILD) compile_commands.json

bear:
	@$(MAKE) clean
	@echo -e "\x1b[1m ⇒ \x1b[34mExecuting bear to save compile commands...\x1b[0m"
	@bear -- $(MAKE) all

$(TARGET): $(OBJFILES)
	@echo -e "\x1b[1m ⇒ \x1b[32mLinking '$(OBJFILES)'\x1b[0m"
	@$(CC) $(FULLLDFLAGS) $(OBJFILES) -o $(TARGET)

$(BUILD)/%.o: $(SOURCE)/%.$(EXT) $(BUILD) $(HEADERS)
	@echo -e "\x1b[1m ⇒ \x1b[36mCompiling '$<'\x1b[0m"
	@$(CC) $(FULLCFLAGS) -c $< -o $@

$(BUILD):
	@mkdir $(BUILD)

