# Компилятор
CXX = g++

# Флаги компилятора
CXXFLAGS = -Wall -Wextra -I./headers

# Путь к исходникам
SRC_DIR = src
TEST_DIR = tests

# Файлы исходников и тестов
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

# Целевые исполняемые файлы
TARGET = home
TEST_TARGET = test_home

# Цвета для вывода
GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m # Без цвета

# Правило по умолчанию
all: $(TARGET)

# Компиляция основного приложения
$(TARGET): $(SRCS)
	@echo "🔧 Компиляция основного приложения..."
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)✅ Собрано: $(TARGET)$(NC)"

# Компиляция и запуск тестов
test: $(TEST_TARGET)
	@echo "🔍 Запуск тестов..."
	@./$(TEST_TARGET) && \
	echo "$(GREEN)✅ Все тесты пройдены успешно!$(NC)" || \
	(echo "$(RED)❌ Некоторые тесты не прошли!$(NC)"; exit 1)

# Компиляция тестов
$(TEST_TARGET): $(SRCS) $(TEST_SRCS)
	@echo "🧪 Компиляция тестов..."
	$(CXX) $(CXXFLAGS) $^ -lgtest -lgtest_main -pthread -o $@
	@echo "$(GREEN)✅ Собрано: $(TEST_TARGET)$(NC)"

# Очистка
clean:
	@echo "🧹 Очистка..."
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "$(GREEN)✅ Очистка завершена$(NC)"

.PHONY: all clean test