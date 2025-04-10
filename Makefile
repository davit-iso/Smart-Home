# Компилятор
CXX = g++

# Флаги компилятора
CXXFLAGS = -Wall -Wextra -I./headers

# Путь к исходникам
SRC_DIR = src

# Получаем все .cpp файлы из src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Имя итогового исполняемого файла
TARGET = out
# Правило по умолчанию
all: $(TARGET)

# Компиляция
$(TARGET): $(SRCS)
        $(CXX) $(CXXFLAGS) $^ -o $@

# Очистка
clean:
        rm -f $(TARGET)

.PHONY: all clean
