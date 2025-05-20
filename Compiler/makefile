# Компилятор и флаги
CC = g++
CFLAGS = -Iinclude -std=c++17
LDFLAGS =

# Директории
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = .

# Генерируемые файлы парсера (все в include/)
PARSER_SRC = $(INC_DIR)/parser.tab.cc
PARSER_HEADER = $(INC_DIR)/parser.tab.hh
LEXER_SRC = $(BUILD_DIR)/lex.yy.c

# Основные исходники (исключаем parser.yy, lexer.l и parser.tab.cc)
MAIN_SRCS = $(filter-out $(SRC_DIR)/lexer.l $(SRC_DIR)/parser.yy $(INC_DIR)/parser.tab.cc, \
              $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(INC_DIR)/*.cc))
MAIN_OBJS = $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(filter %.cc,$(wildcard $(SRC_DIR)/*.cc))) \
            $(patsubst $(INC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(filter %.cc,$(wildcard $(INC_DIR)/*.cc)))

# Итоговый бинарник
TARGET = $(BIN_DIR)/marasm

.PHONY: all clean

all: $(TARGET)

# Правило сборки итогового бинарника
$(TARGET): $(PARSER_SRC) $(LEXER_SRC) $(MAIN_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Генерация парсера
$(PARSER_SRC) $(PARSER_HEADER): $(SRC_DIR)/parser.yy
	bison --defines=$(PARSER_HEADER) --output=$(PARSER_SRC) $<

# Генерация лексера
$(LEXER_SRC): $(SRC_DIR)/lexer.l $(PARSER_HEADER)
	flex -o $@ $<

# Компиляция лексера
$(BUILD_DIR)/lex.yy.o: $(LEXER_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция .cc исходников
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(INC_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Создание директорий (один раз при первом запуске)
$(shell mkdir -p $(BUILD_DIR) $(INC_DIR))

clean:
	rm -rf $(BUILD_DIR)/* $(INC_DIR)/parser.tab.* $(INC_DIR)/location.hh $(LEXER_SRC) $(TARGET) *.bin
