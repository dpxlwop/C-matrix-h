CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Werror 
LDFLAGS = -fprofile-arcs -ftest-coverage $(shell pkg-config --cflags --libs check)
CLANG_FORMAT_CONFIG = ../materials/linters/.clang-format

TARGET = s21_matrix.a

CORE = s21_calc_complements.c s21_create_matrix.c s21_determinant.c s21_eq_matrix.c \
	   s21_inverse_matrix.c s21_mult_matrix.c s21_mult_number.c s21_remove_matrix.c \
	   s21_sub_matrix.c s21_sum_matrix.c s21_transpose.c


SRCS = $(CORE)
OBJS = $(SRCS:.c=.o)

MAIN_TEST = test/test.c

$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: $(TARGET)


test: clean
	$(CC) $(CFLAGS) $(MAIN_TEST) $(SRCS) -o test_runner $(LDFLAGS)
	./test_runner

UNAME_S := $(shell uname)
ifeq ($(UNAME_S),Darwin)
    OPEN_CMD = open
else ifeq ($(UNAME_S),Linux)
    OPEN_CMD = xdg-open
else
    OPEN_CMD =
endif

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '*/tests/*' '/usr/*' --output-file coverage.info || true
	genhtml coverage.info --output-directory coverage_report
	$(OPEN_CMD) coverage_report/index.html

valgrind: clean test
	valgrind --leak-check=full --track-origins=yes ./test_runner

asan:
	$(CC) -g -fsanitize=address -fno-omit-frame-pointer \
	$(MAIN_TEST) $(SRCS) \
	-o test_asan \
	$(shell pkg-config --cflags --libs check) -lm
	./test_asan

clang:
	@if [ -f "$(CLANG_FORMAT_CONFIG)" ]; then \
		clang-format -style=file:$(CLANG_FORMAT_CONFIG) -n $(SRCS) $(HDRS); \
		clang-format -style=file:$(CLANG_FORMAT_CONFIG) -i $(SRCS) $(HDRS); \
		echo "SUCCES $(CLANG_FORMAT_CONFIG): $(SRCS) $(HDRS)"; \
	else \
		echo "ERROR: clang-format not found in $(CLANG_FORMAT_CONFIG)"; \
		exit 1; \
	fi

clang-check:
	@if [ -f "$(CLANG_FORMAT_CONFIG)" ]; then \
		clang-format -style=file:$(CLANG_FORMAT_CONFIG) -n $(SRCS) $(HDRS);\
		echo "SUCCES $(CLANG_FORMAT_CONFIG): $(SRCS) $(HDRS)"; \
	else \
		echo "ERROR: clang-format not found in $(CLANG_FORMAT_CONFIG)"; \
		exit 1; \
	fi


rebuild: clean all

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f test_runner
	rm -rf *.gcno *.gcda *.c.gcov coverage.info out test_runner
	rm -rf */*.gcno */*.gcda */*.c.gcov coverage_report
	rm -rf *.gcno *.gcda *.c.gcov coverage.info coverage_report out
	rm -rf test_asan test_asan.dSYM

.PHONY: all test gcov_report valgrind clang clang-check rebuild clean