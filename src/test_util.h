#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void s21_strlen_test_gen(const char allowed[], int length);
char *randstr(int length, const char allowed[]);
void s21_strtok_test_gen(const char allowed_str1[], int length_str1,
                         const char allowed_str2[], int length_str2);
void s21_strcspn_test_gen(const char allowed_str1[], int length_str1,
                          const char allowed_str2[], int length_str2);
void s21_strspn_test_gen(const char allowed_str1[], int length_str1,
                         const char allowed_str2[], int length_str2);
