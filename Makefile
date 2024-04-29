CC=gcc++
FLAGS=-Wall -Wextra -Werror --std=c++17
ASAN= -fsanitize=address
TEST_FLAGS=-lgtest
GCOV=--coverage
HTML=-lcov -t test -o rep.info -c -d ./

OPS=		./srcs/arithmetic.cpp \
				./srcs/complement.cpp \
				./srcs/determinant.cpp \
				./srcs/inverse.cpp \
				./srcs/transpose.cpp 

TOOLS=	./tools/print_matrix.cpp \
				./tools/GaussElimination.cpp \
				./tools/ResizeMatrix.cpp

TESTS=	./tests/test.cpp

SRCS=		$(OPS) $(TOOLS)

OBJS=		$(SRCS:.c=.o)

rwildcard = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard,$d,$2) $(filter $(subst *,%,$2), $d))

.PHONY: clean s21_matrix_oop.a gcov_report test
all: clean gcov_report

test: s21_matrix_oop.a
	#@$(CC) -o $@ $(TEST_FLAGS) $(FLAGS) 'pkg-config --cflags --libs check' $(SRC) $(TESTS)
	@rm -rf build
	@mkdir build
	@cd build && cmake ../ && make && ./main

s21_matrix_oop.a: $(OBJS)
	@ar rcs s21_matrix_oop.a $^
	@ranlib s21_matrix_oop.a

gcov_report: test
	$(HTML)
	genhtml -o report rep.info
	open report/index.html

clean:
	@rm -rf s21_matrix_oop.a *.o *.gcno *.gcda *.gcov *.gch \
		test ./test.DSYM *.png *.html *.css *.info \
		$(call rwildcard,.,*.o) \
		$(call rwildcard,.,*.html)


