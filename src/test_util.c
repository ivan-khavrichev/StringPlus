#include "test_util.h"

#include <string.h>

#include "s21_string.h"

const int MAX_LENGTH = 20;
const int OUTPUT_TESTS = 1;

char *randstr(int length, const char allowed[]) {
  if (length < 0) length = rand() % MAX_LENGTH + 1;
  char *random = malloc((length + 1) * sizeof(char));
  int c = 0;
  int nbAllowed = strlen(allowed) - 1;
  for (int j = 0; j < length; j++) {
    c = rand() % nbAllowed;
    random[j] = allowed[c];
  }
  random[length] = '\0';

  return random;
}

void s21_strlen_test_gen(const char allowed[], int length) {
  srand((unsigned)time(S21_NULL) * getpid());
  char *random = randstr(length, allowed);
  if (OUTPUT_TESTS) printf("Testing now: [%s]\n", random);
  ck_assert_int_eq(strlen(random), s21_strlen(random));
  free(random);
}

void s21_strcspn_test_gen(const char allowed_str1[], int length_str1,
                          const char allowed_str2[], int length_str2) {
  srand((unsigned)time(S21_NULL) * getpid());
  char *random_str1 = randstr(length_str1, allowed_str1);
  srand((unsigned)time(S21_NULL) * getpid());
  char *random_str2 = randstr(length_str2, allowed_str2);
  if (OUTPUT_TESTS)
    printf("Testing now: [%s] [%s]\n", random_str1, random_str2);
  ck_assert_int_eq(strcspn(random_str1, random_str2),
                   s21_strcspn(random_str1, random_str2));
  free(random_str1);
  free(random_str2);
}

void s21_strspn_test_gen(const char allowed_str1[], int length_str1,
                         const char allowed_str2[], int length_str2) {
  srand((unsigned)time(S21_NULL) * getpid());
  char *random_str1 = randstr(length_str1, allowed_str1);
  srand((unsigned)time(S21_NULL) * getpid());
  char *random_str2 = randstr(length_str2, allowed_str2);
  if (OUTPUT_TESTS)
    printf("Testing now: [%s] [%s]\n", random_str1, random_str2);
  ck_assert_int_eq(strspn(random_str1, random_str2),
                   s21_strspn(random_str1, random_str2));
  free(random_str1);
  free(random_str2);
}
