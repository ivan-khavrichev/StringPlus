all: s21_string.a

CC = gcc
STD = -std=c11
WFLAGS = -Wall -Wextra -g
TEST_FLAGS = -lcheck -lm
SP_PATH = s21_sprintf/


s21_string.a: s21_string.o s21_strerror.o s21_sprintf.o s21_csharp.o
	ar rc s21_string.a s21_string.o s21_strerror.o s21_sprintf.o s21_sprintf_char_str_processing.o s21_sprintf_format_spec_processing.o s21_sprintf_float_processing.o s21_sprintf_int_processing.o s21_csharp.o
	ranlib s21_string.a

s21_string.o: s21_string.c s21_string.h
	$(CC) $(STD) $(WFLAGS) -c s21_string.c

s21_strerror.o: s21_strerror.c s21_string.h
	$(CC) $(STD) $(WFLAGS) -c s21_strerror.c

s21_sprintf.o: $(SP_PATH)s21_sprintf.c s21_string.h $(SP_PATH)s21_sprintf.h
	$(CC) $(STD) $(WFLAGS) -c $(SP_PATH)s21_sprintf.c $(SP_PATH)s21_sprintf_char_str_processing.c
	$(CC) $(STD) $(WFLAGS) -c $(SP_PATH)s21_sprintf_int_processing.c
	$(CC) $(STD) $(WFLAGS) -c $(SP_PATH)s21_sprintf_float_processing.c
	$(CC) $(STD) $(WFLAGS) -c $(SP_PATH)s21_sprintf_format_spec_processing.c

s21_csharp.o: s21_csharp.c s21_string.h
	$(CC) $(STD) $(WFLAGS) -c s21_csharp.c

test: s21_string.a
	$(CC) $(WFLAGS) -c tests.c test_util.c $(TEST_FLAGS)
	$(CC) $(WFLAGS) tests.o test_util.o s21_string.a -o tests $(TEST_FLAGS) 
	./tests

gcov_report: s21_string.a
	$(CC) $(STD) --coverage tests.c s21_string.c s21_strerror.c $(SP_PATH)s21_sprintf_int_processing.c $(SP_PATH)s21_sprintf_char_str_processing.c $(SP_PATH)s21_sprintf_format_spec_processing.c $(SP_PATH)s21_sprintf_float_processing.c $(SP_PATH)s21_sprintf.c s21_csharp.c test_util.c $(WFLAGS) $(TEST_FLAGS) -o test
	./test
	lcov -t "test" --no-external -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check_style:
	cp ../materials/linters/.clang-format ../src
	clang-format -n -style=google *.c *.h $(SP_PATH)*.c $(SP_PATH)*.h

correct_style:
	cp ../materials/linters/.clang-format ../src
	clang-format -i -style=google *.c *.h $(SP_PATH)*.c $(SP_PATH)*.h

clean:
	rm -rf *.o *.g* *.a *.out s21_string test.info tests test unit_tests report .clang-format

rebuild: clean all
