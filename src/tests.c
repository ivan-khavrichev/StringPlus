#include <check.h>
#include <string.h>

#include "s21_sprintf/s21_sprintf.h"
#include "s21_string.h"
#include "test_util.h"

#if defined(__linux__)
#define PLATFORM_NAME "LINUX"
#elif defined(__APPLE__)
#define PLATFORM_NAME "MAC"
#endif
#define BUFF_SIZE 512
START_TEST(s21_memchr_tests_case) {
  char *str = "string";
  char *str1 = "0123456789";
  char *str2 = "Hello world";
  ck_assert_str_eq(memchr(str, 's', 6), s21_memchr(str, 's', 6));
  ck_assert_str_eq(memchr(str, 'g', 100), s21_memchr(str, 'g', 100));
  ck_assert_str_eq(memchr(str1, '6', 10), s21_memchr(str1, '6', 10));
  ck_assert_str_eq(memchr(str2, 101, 10), s21_memchr(str2, 101, 10));
}
END_TEST

START_TEST(s21_memcmp_tests_case_1) {
  char *str = "Hello world";
  char *str1 = "Hello world";
  ck_assert_int_eq(memcmp(str, str1, 2), s21_memcmp(str, str1, 2));
}
END_TEST

START_TEST(s21_memcmp_tests_case_2) {
  char *str = "Hellaworld";
  char *str1 = "Helloworld";
  ck_assert_int_eq(memcmp(str, str1, 120), s21_memcmp(str, str1, 120));
}
END_TEST

START_TEST(s21_memcmp_tests_case_3) {
  char *str = "Hello\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 6), s21_memcmp(str, str1, 6));
}
END_TEST

START_TEST(s21_memcmp_tests_case_4) {
  char *str = "Helo\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 8), s21_memcmp(str, str1, 8));
}
END_TEST

START_TEST(s21_memcmp_tests_case_5) {
  char *str = "Hello\0w2\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 8), s21_memcmp(str, str1, 8));
}
END_TEST

START_TEST(s21_memcmp_tests_case_6) {
  char *str = "\0Hallo\0w2\0ld";
  char *str1 = "\0Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 15), s21_memcmp(str, str1, 15));
}
END_TEST

START_TEST(s21_memcmp_tests_case_7) {
  char *str = "\0\0\0";
  char *str1 = "\0\0\0";
  ck_assert_int_eq(memcmp(str, str1, 2), s21_memcmp(str, str1, 2));
}
END_TEST

START_TEST(s21_memcmp_tests_case_8) {
  char *str = "\0";
  char *str1 = "\0";
  ck_assert_int_eq(memcmp(str, str1, 0), s21_memcmp(str, str1, 0));
}
END_TEST

START_TEST(s21_memcmp_tests_case_9) {
  char *str = "";
  char *str1 = "";
  ck_assert_int_eq(memcmp(str, str1, 1), s21_memcmp(str, str1, 1));
}
END_TEST

START_TEST(s21_memcmp_tests_case_10) {
  char *str = "\0";
  char *str1 = " ";
  ck_assert_int_eq(memcmp(str, str1, 6), s21_memcmp(str, str1, 6));
}
END_TEST

START_TEST(s21_memcpy_tests_case) {
  char dest1[15] = "1234567890";
  char dest2[15] = "1234567890";
  char src[10] = "asdfdads";
  memcpy(dest1, src, 10);
  s21_memcpy(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);

  char dest12[15] = "1234567890";
  char dest22[15] = "1234567890";
  memcpy(dest12, src, 1);
  s21_memcpy(dest22, src, 1);
  ck_assert_str_eq(dest1, dest2);

  memcpy(S21_NULL, S21_NULL, 1);
  s21_memcpy(S21_NULL, S21_NULL, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memmove_tests_case_1) {
#ifdef __APPLE__
  char dest1[15] = "sfdsf";
  char dest2[15] = "sdfsdf";
  char src[15] = "kjshnfljk";
  size_t chek_dest = 0;
  memmove(dest1, src, 15);
  s21_memmove(dest2, src, 15);
  ck_assert_mem_eq(dest1, dest2, chek_dest);
#else
  char dest1[15] = "sfdsf";
  char dest2[15] = "sdfsdf";
  char src[15] = "kjshnfljk";
  memmove(dest1, src, 15);
  s21_memmove(dest2, src, 15);
  ck_assert_str_eq(dest1, dest2);
#endif
}
END_TEST

START_TEST(s21_memmove_tests_case_2) {
  char src[200] = "";
  char src2[200] = "";
  size_t copy_kByte = 0;
  char *res = src;
  char *expected = src2;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memmove_tests_case_3) {
  char src[200] = "";
  char src2[200] = "";
  size_t copy_kByte = 0;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memmove_S21_NULLdest_tests) {
  char src[200] = "";
  char src2[200] = "";
  size_t copy_kByte = 0;
  char *res = S21_NULL;
  char *expected = S21_NULL;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(s21_memmove_S21_NULLsrc_tests) {
  char *src = S21_NULL;
  char *src2 = S21_NULL;
  size_t copy_kByte = 0;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(s21_memmove_dest_lower_src_tests) {
  char str1[] = "Banana", str3[] = "Banana";
  char str2[] = "Apple", str4[] = "Apple";
  ck_assert_pstr_eq(s21_memmove(str3, str4, sizeof(str4)),
                    memmove(str1, str2, sizeof(str2)));
}
END_TEST

START_TEST(s21_memmove_tests_case_4) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  size_t copy_kByte = 4;
  char res[200] = "i hate verter";
  char expected[200] = "i hate verter";
  s21_memmove(res + 5, src, copy_kByte);
  memmove(expected + 5, src2, copy_kByte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(s21_memset_tests_case) {
  char dest1[15] = "1234567890";
  char dest2[15] = "1234567890";
  memset(dest1, '1', 10);
  s21_memset(dest2, '1', 10);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strchr_tests_case_1) {
  char *str = "Hello world";
  ck_assert_str_eq(strchr(str, 'e'), s21_strchr(str, 'e'));
  ck_assert_str_eq(strchr(str, 'H'), s21_strchr(str, 'H'));
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_tests_case_2) {
  char *str = "01234";
  ck_assert_str_eq(strchr(str, '0'), s21_strchr(str, '0'));
  ck_assert_str_eq(strchr(str, '4'), s21_strchr(str, '4'));
}
END_TEST

START_TEST(s21_strlen_tests_case_1) {
  s21_strlen_test_gen("abcdefghijklmnopqrstuvwxyz", -1);
}
END_TEST

START_TEST(s21_strlen_tests_case_2) {
  char str1[] = "abc.defghij.kl";
  char str2[] = "./i";
  char str3[] = "abc.defghij.kl  addsa adsasd";
  char str4[] =
      "dajskljasd asd isadlj j dasdouisadousd ioas d,jads lkjaklsdj aei a ";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
  ck_assert_int_eq(strlen(str4), s21_strlen(str4));
}
END_TEST

START_TEST(s21_strcpy_tests_case) {
  char dest1[15] = "1234567890";
  char dest2[15] = "1234567890";
  char src[10] = "abcdsfsda";
  strcpy(dest1, src);
  s21_strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strncpy_tests_case) {
  char dest1[15] = "";
  char dest2[15] = "";
  char src[15] = "ljkamfdng";
  s21_strncpy(dest2, src, 3);
  strncpy(dest1, src, 15);
  s21_strncpy(dest2, src, 15);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strcmp_tests_case_1) {
  char *str = "Hello world";
  char *str1 = "Hello world";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_2) {
  char *str = "Hellaworld";
  char *str1 = "Helloworld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_3) {
  char *str = "Hello\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_4) {
  char *str = "Helo\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_5) {
  char *str = "Hello\0w2\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_6) {
  char *str = "\0Hello\0w2\0ld";
  char *str1 = "\0Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_7) {
  char *str = "\0\0\0";
  char *str1 = "\0\0\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_8) {
  char *str = "\0";
  char *str1 = "\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_9) {
  char *str = "";
  char *str1 = "";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_10) {
  char *str = "\0";
  char *str1 = " ";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strncmp_tests_case_1) {
  char *str = "Hello world";
  char *str1 = "Hello world";
  ck_assert_int_eq(strncmp(str, str1, 2), s21_strncmp(str, str1, 2));
}
END_TEST

START_TEST(s21_strncmp_tests_case_2) {
  char *str = "Hellaworld";
  char *str1 = "Helloworld";
  ck_assert_int_eq(strncmp(str, str1, 120), s21_strncmp(str, str1, 120));
}
END_TEST

START_TEST(s21_strncmp_tests_case_3) {
  char *str = "Hello\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 6), s21_strncmp(str, str1, 6));
}
END_TEST

START_TEST(s21_strncmp_tests_case_4) {
  char *str = "Helo\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 8), s21_strncmp(str, str1, 8));
}
END_TEST

START_TEST(s21_strncmp_tests_case_5) {
  char *str = "Hello\0w2\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 8), s21_strncmp(str, str1, 8));
}
END_TEST

START_TEST(s21_strncmp_tests_case_6) {
  char *str = "\0Hallo\0w2\0ld";
  char *str1 = "\0Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 15), s21_strncmp(str, str1, 15));
}
END_TEST

START_TEST(s21_strncmp_tests_case_7) {
  char *str = "\0\0\0";
  char *str1 = "\0\0\0";
  ck_assert_int_eq(strncmp(str, str1, 2), s21_strncmp(str, str1, 2));
}
END_TEST

START_TEST(s21_strncmp_tests_case_8) {
  char *str = "\0";
  char *str1 = "\0";
  ck_assert_int_eq(strncmp(str, str1, 0), s21_strncmp(str, str1, 0));
}
END_TEST

START_TEST(s21_strncmp_tests_case_9) {
  char *str = "";
  char *str1 = "";
  ck_assert_int_eq(strncmp(str, str1, 1), s21_strncmp(str, str1, 1));
}
END_TEST

START_TEST(s21_strncmp_tests_case_10) {
  char *str = "\0";
  char *str1 = " ";
  ck_assert_int_eq(strncmp(str, str1, 6), s21_strncmp(str, str1, 6));
}
END_TEST

START_TEST(s21_strstr_tests_case_1) {
  char *str = "Hello world";
  char *find = "el";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_2) {
  char *str = "Hello world";
  char *find = "\0";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_3) {
  char *str = "Hello world";
  char *find = "d";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_4) {
  char *str = "Hello world";
  char *find = "Hello world";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_5) {
  char *str = "012345678";
  char *find = "56";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_6) {
  char *str = "!@#$%^&*(";
  char *find = "$%";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strcat_tests_case_1) {
  char str_des1[30] = "Hello world";
  char str_des2[30] = "Hello world";
  char str1[] = "Hello world";
  ck_assert_str_eq(strcat(str_des1, str1), s21_strcat(str_des2, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_2) {
  char str_des1[30] = "Hello world";
  char str_des2[30] = "Hello world";
  char str1[] = "Helloworld";
  ck_assert_str_eq(strcat(str_des1, str1), s21_strcat(str_des2, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_3) {
  char str[30] = "Hello\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_4) {
  char str[30] = "Helo\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_5) {
  char str[30] = "Hello\0w2\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_6) {
  char str[30] = "\0Hello\0w2\0ld";
  char str1[] = "\0Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_7) {
  char str[30] = "\0\0\0";
  char str1[] = "\0\0\0";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_8) {
  char str[30] = "\0";
  char str1[] = "\0";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_9) {
  char str[30] = "";
  char str1[] = "";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_10) {
  char str[30] = "\0";
  char str1[] = " ";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strncat_tests_case_1) {
  char str[30] = "Hello world";
  char str1[] = "Hello world";
  ck_assert_str_eq(strncat(str, str1, 5), s21_strncat(str, str1, 5));
}
END_TEST

START_TEST(s21_strncat_tests_case_2) {
  char str[100] = "Hellaworld";
  char str1[] = "Helloworld";
  ck_assert_str_eq(strncat(str, str1, 29), s21_strncat(str, str1, 29));
}
END_TEST

START_TEST(s21_strncat_tests_case_3) {
  char str[30] = "Hello\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 0), s21_strncat(str, str1, 0));
}
END_TEST

START_TEST(s21_strncat_tests_case_4) {
  char str[30] = "Helo\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 20), s21_strncat(str, str1, 20));
}
END_TEST

START_TEST(s21_strncat_tests_case_5) {
  char str[30] = "Hello\0w2\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_tests_case_6) {
  char str[30] = "\0Hello\0w2\0ld";
  char str1[] = "\0Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_tests_case_7) {
  char str[30] = "\0\0\0";
  char str1[] = "\0\0\0";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_tests_case_8) {
  char str[30] = "\0";
  char str1[] = "\0";
  ck_assert_str_eq(strncat(str, str1, 3), s21_strncat(str, str1, 3));
}
END_TEST

START_TEST(s21_strncat_tests_case_9) {
  char str[30] = "";
  char str1[] = "";
  ck_assert_str_eq(strncat(str, str1, 2), s21_strncat(str, str1, 2));
}
END_TEST

START_TEST(s21_strncat_tests_case_10) {
  char str[30] = "\0";
  char str1[] = " ";
  ck_assert_str_eq(strncat(str, str1, 1), s21_strncat(str, str1, 1));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_1) {
  char *str = "Hello world";
  char *find = "world";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_2) {
  char *str = "Hello world";
  char *find = "H";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_3) {
  char *str = "Hello world";
  char *find = "he";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_4) {
  char *str = "Hello world";
  char *find = "d\n";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_5) {
  char *str = "School21";
  char *find = "21";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strrchr_tests_case_1) {
  char *str = "Hello world";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_2) {
  char *str = "Hello world";
  ck_assert_str_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_3) {
  char *str = "Hello world";
  ck_assert_str_eq(strrchr(str, 'H'), s21_strrchr(str, 'H'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_4) {
  char *str = "School21";
  ck_assert_str_eq(strrchr(str, '2'), strrchr(str, '2'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_5) {
  char *str = "9990009";
  ck_assert_str_eq(strrchr(str, '9'), s21_strrchr(str, '9'));
}
END_TEST

START_TEST(s21_strcspn_random_tests_case) {
  s21_strcspn_test_gen("abcdefghijklmnopqrstuvwxyz", -1,
                       "abcdefghijklmnopqrstuvwxyz", 20);
}
END_TEST

START_TEST(s21_strcspn_tests_case) {
  char str1[] = "abc.defghij.kl";
  char str2[] = "./i";
  char str3[] = "..abc.defghij.kl  addsa adsasd";
  char str4[] =
      "dajskljasd asd isadlj j dasdouisadousd ioas d,jads lkjaklsdj aei a ";
  char str5[] = ".////iiii/.....////iiiiiid///";
  char str6[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
  ck_assert_int_eq(strcspn(str2, str2), s21_strcspn(str2, str2));
  ck_assert_int_eq(strcspn(str3, str2), s21_strcspn(str3, str2));
  ck_assert_int_eq(strcspn(str4, str2), s21_strcspn(str4, str2));
  ck_assert_int_eq(strcspn(str5, str2), s21_strcspn(str5, str2));
  ck_assert_int_eq(strcspn(str1, str6), s21_strcspn(str1, str6));
}
END_TEST

START_TEST(s21_strtok_tests_case) {
  char str1[] = "abc.defghij.kl.aasddsaasd";
  char str2[] = "./i";
  char str3[] = "abc.defghij.kl.aasddsaasd";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str3, str2));
  ck_assert_pstr_eq(strtok(S21_NULL, str2), s21_strtok(S21_NULL, str2));
  ck_assert_pstr_eq(strtok(S21_NULL, str2), s21_strtok(S21_NULL, str2));
  ck_assert_pstr_eq(strtok(S21_NULL, ""), s21_strtok(S21_NULL, ""));
}
END_TEST

START_TEST(s21_strspn_random_tests_case) {
  s21_strspn_test_gen("abcdefghijklmnopqrstuvwxyz", -1,
                      "abcdefghijklmnopqrstuvwxyz", 5);
}
END_TEST

START_TEST(s21_strspn_tests_case) {
  char str1[] = "abc.defghij.kl";
  char str2[] = "./i";
  char str3[] = "..abc.defghij.kl  addsa adsasd";
  char str4[] =
      "dajskljasd asd isadlj j dasdouisadousd ioas d,jads lkjaklsdj aei a ";
  char str5[] = ".////iiii/.....////iiiiiid///";
  char str6[] = "";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
  ck_assert_int_eq(strspn(str2, str2), s21_strspn(str2, str2));
  ck_assert_int_eq(strspn(str3, str2), s21_strspn(str3, str2));
  ck_assert_int_eq(strspn(str4, str2), s21_strspn(str4, str2));
  ck_assert_int_eq(strspn(str5, str2), s21_strspn(str5, str2));
  ck_assert_int_eq(strspn(str1, str6), s21_strspn(str1, str6));
}
END_TEST

START_TEST(s21_str_insert_tests_case) {
  char str1[] = "1234890";
  char str2[] = "567";
  char *str = S21_NULL;
  str = (char *)s21_insert(str1, str2, 4);
  ck_assert_pstr_eq(str, "1234567890");
  free(str);
  str = s21_insert(str1, str2, 100500);
  ck_assert_pstr_eq(str, S21_NULL);
  free(str);
  str = s21_insert(str1, str2, -2);
  ck_assert_pstr_eq(str, S21_NULL);
  free(str);
  str = s21_insert("", str2, 0);
  ck_assert_pstr_eq(str, "567");
  free(str);
  str = s21_insert("", "", 0);
  ck_assert_pstr_eq(str, "");
  // free(str);
  str = s21_insert(str1, "", 4);
  ck_assert_pstr_eq(str, "1234890");
  free(str);
}
END_TEST

START_TEST(s21_str_strerror_tests_case) {
  if (s21_strcmp(PLATFORM_NAME, "MAC") == 0) {
    for (int i = -10; i < 150; ++i) {
      ck_assert_pstr_eq(s21_strerror(i), strerror(i));
    }
  }
}
END_TEST

START_TEST(s21_str_to_lower_tests_case) {
  char str1[] = "ONCHLJBaYV";
  char str2[] = "KvCfcdgBBb";
  char str3[] = "czhEwtIGDI";
  char str4[] = "12345678";
  char str5[] = "\0abc";
  void *str;
  str = s21_to_lower(str1);
  ck_assert_pstr_eq(str, "onchljbayv");
  free(str);
  str = s21_to_lower(str2);
  ck_assert_pstr_eq(str, "kvcfcdgbbb");
  free(str);
  str = s21_to_lower(str3);
  ck_assert_pstr_eq(str, "czhewtigdi");
  free(str);
  str = s21_to_lower(str4);
  ck_assert_pstr_eq(str, "12345678");
  free(str);
  str = s21_to_lower(str5);
  ck_assert_pstr_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_str_to_upper_tests_case) {
  char str1[] = "ONCHLJBaYV";
  char str2[] = "KvCfcdgBBb";
  char str3[] = "czhEwtIGDI";
  char str4[] = "12345678";
  char str5[] = "\0abc";
  void *str;
  str = s21_to_upper(str1);
  ck_assert_pstr_eq(str, "ONCHLJBAYV");
  free(str);
  str = s21_to_upper(str2);
  ck_assert_pstr_eq(str, "KVCFCDGBBB");
  free(str);
  str = s21_to_upper(str3);
  ck_assert_pstr_eq(str, "CZHEWTIGDI");
  free(str);
  str = s21_to_upper(str4);
  ck_assert_pstr_eq(str, "12345678");
  free(str);
  str = s21_to_upper(str5);
  ck_assert_pstr_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_str_trim_tests_case) {
  void *str;
  str = s21_trim("12345678", "127");
  ck_assert_pstr_eq(str, "345678");
  free(str);
  str = s21_trim("abracadabra", "ab");
  ck_assert_pstr_eq(str, "racadabr");
  free(str);
  str = s21_trim("", "456");
  ck_assert_pstr_eq(str, "");
  // free(str);
  str = s21_trim("AAAAAAAAAA", "A");
  ck_assert_pstr_eq(str, "");
  // free(str);
  str = s21_trim("keep trying", "12345678");
  ck_assert_pstr_eq(str, "keep trying");
  free(str);
  str = s21_trim("            remove spaces        ", " ");
  ck_assert_pstr_eq(str, "remove spaces");
  free(str);
  str = s21_trim("u dare change me?", "");
  ck_assert_pstr_eq(str, "u dare change me?");
  free(str);
}
END_TEST

START_TEST(s21_sprintf_tests_case_1) {
  char *str = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  int dlina = 15;
  char ed[] = "Amp";
  char ch = 'p';
  sprintf(str_et, "I = %d %s %c", dlina, ed, ch);
  s21_sprintf(str, "I = %d %s %c", dlina, ed, ch);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);

  str = (char *)calloc(999, sizeof(char));
  str_et = (char *)calloc(999, sizeof(char));
  sprintf(str_et, "I = %i %s", dlina, ed);
  s21_sprintf(str, "I = %i %s", dlina, ed);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);

  str = (char *)calloc(999, sizeof(char));
  str_et = (char *)calloc(999, sizeof(char));
  sprintf(str_et, "I = %lu %s", (long unsigned)dlina, ed);
  s21_sprintf(str, "I = %lu %s", (long unsigned)dlina, ed);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_2) {
  char *str = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  float dlina = 15.64;
  char ed[] = "Amp";

  sprintf(str_et, "I = %.2f %s", dlina, ed);
  s21_sprintf(str, "I = %.2f %s", dlina, ed);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);

  str = (char *)calloc(999, sizeof(char));
  str_et = (char *)calloc(999, sizeof(char));
  sprintf(str_et, "test = %s %%", ed);
  s21_sprintf(str, "test = %s %%", ed);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);

  str = (char *)calloc(999, sizeof(char));
  str_et = (char *)calloc(999, sizeof(char));
  char ch = 'D';
  sprintf(str_et, "I = %c", ch);
  s21_sprintf(str, "I = %c", ch);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_3) {
  char *str = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  float dlina = 1.564;
  char ed[] = "Amp";
  sprintf(str_et, "I = %-7.2f %s", dlina, ed);
  s21_sprintf(str, "I = %-7.2f %s", dlina, ed);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_4) {
  char *str = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  int int_var = -15;
  long int long_var = 11200004043;
  sprintf(str_et, "I = %-6.2hd %+.5ld", int_var, long_var);
  s21_sprintf(str, "I = %-6.2hd %+.5ld", int_var, long_var);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);

  str = (char *)calloc(999, sizeof(char));
  str_et = (char *)calloc(999, sizeof(char));
  unsigned int uint_var = 15;
  unsigned int zero = 0;
  long unsigned int long_u_var = 11200004043;
  sprintf(str_et, "test = %-6.2hu %4.5lu aaa %40u", uint_var, long_u_var, zero);
  s21_sprintf(str, "test = %-6.2hu %4.5lu aaa %40u", uint_var, long_u_var,
              zero);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);

  str = (char *)calloc(999, sizeof(char));
  str_et = (char *)calloc(999, sizeof(char));
  sprintf(str_et, "test = %-*.*hu %*.*lu aaa %*u", 5, 4, uint_var, 10, 5,
          long_u_var, 8, zero);
  s21_sprintf(str, "test = %-*.*hu %*.*lu aaa %*u", 5, 4, uint_var, 10, 5,
              long_u_var, 8, zero);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_5) {
  char *str = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  double float_num1 = 0.995;
  long double float_num2 = 9.975E8;
  sprintf(str_et, "test = %5.7f %*.*Lf", float_num1, 10, 0, float_num2);
  s21_sprintf(str, "test = %5.7f %*.*Lf", float_num1, 10, 0, float_num2);
  ck_assert_pstr_eq(str_et, str);
  free(str);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_6) {
  char *str1 = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  char *str = "I just want to finish this already";
  s21_sprintf(str1, "%50s", str);
  sprintf(str_et, "%50s", str);
  ck_assert_str_eq(str_et, str1);
  free(str1);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_7) {
  char *str1 = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  char *str = "I just want to finish this already";
  s21_sprintf(str1, "%50s", str);
  sprintf(str_et, "%50s", str);
  ck_assert_str_eq(str_et, str1);
  free(str1);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_8) {
  char *str1 = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  char ch = 'd';
  s21_sprintf(str1, "%-10c", ch);
  sprintf(str_et, "%-10c", ch);
  ck_assert_str_eq(str_et, str1);
  free(str1);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_9) {
  char *str1 = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  char ch = 'd';
  s21_sprintf(str1, "%c", ch);
  sprintf(str_et, "%c", ch);
  ck_assert_str_eq(str_et, str1);
  free(str1);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_10) {
  char *str1 = (char *)calloc(999, sizeof(char));
  char *str_et = (char *)calloc(999, sizeof(char));
  char ch = 'd';
  s21_sprintf(str1, "%5c", ch);
  sprintf(str_et, "%5c", ch);
  ck_assert_str_eq(str_et, str1);
  free(str1);
  free(str_et);
}
END_TEST

START_TEST(s21_sprintf_tests_case_11) {
  char *dest1 = calloc(200, sizeof(char));
  char *dest2 = calloc(200, sizeof(char));
  char *str = "sssssssssssssssss";
  sprintf(dest1, "%.0s", str);
  s21_sprintf(dest2, "%.0s", str);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(s21_sprintf_tests_case_12) {
  char *dest1 = calloc(200, sizeof(char));
  char *dest2 = calloc(200, sizeof(char));
  char *str = "sssssssssssssssss";
  sprintf(dest1, "%7.5s", str);
  s21_sprintf(dest2, "%7.5s", str);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_memchr_tests_case);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_1);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_2);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_3);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_4);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_5);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_6);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_7);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_8);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_9);
  tcase_add_test(tc1_1, s21_memcmp_tests_case_10);
  tcase_add_test(tc1_1, s21_memcpy_tests_case);
  tcase_add_test(tc1_1, s21_memmove_tests_case_1);
  tcase_add_test(tc1_1, s21_memmove_tests_case_2);
  tcase_add_test(tc1_1, s21_memmove_tests_case_3);
  tcase_add_test(tc1_1, s21_memmove_tests_case_4);
  tcase_add_test(tc1_1, s21_memmove_S21_NULLdest_tests);
  tcase_add_test(tc1_1, s21_memmove_S21_NULLsrc_tests);
  tcase_add_test(tc1_1, s21_memmove_dest_lower_src_tests);
  tcase_add_test(tc1_1, s21_memset_tests_case);
  tcase_add_test(tc1_1, s21_strchr_tests_case_1);
  tcase_add_test(tc1_1, s21_strchr_tests_case_2);
  tcase_add_test(tc1_1, s21_strlen_tests_case_1);
  tcase_add_test(tc1_1, s21_strlen_tests_case_2);
  tcase_add_test(tc1_1, s21_strcpy_tests_case);
  tcase_add_test(tc1_1, s21_strncpy_tests_case);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_1);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_2);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_3);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_4);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_5);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_6);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_7);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_8);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_9);
  tcase_add_test(tc1_1, s21_strcmp_tests_case_10);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_1);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_2);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_3);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_4);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_5);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_6);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_7);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_8);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_9);
  tcase_add_test(tc1_1, s21_strncmp_tests_case_10);
  tcase_add_test(tc1_1, s21_strstr_tests_case_1);
  tcase_add_test(tc1_1, s21_strstr_tests_case_2);
  tcase_add_test(tc1_1, s21_strstr_tests_case_3);
  tcase_add_test(tc1_1, s21_strstr_tests_case_4);
  tcase_add_test(tc1_1, s21_strstr_tests_case_5);
  tcase_add_test(tc1_1, s21_strstr_tests_case_6);
  tcase_add_test(tc1_1, s21_strcat_tests_case_1);
  tcase_add_test(tc1_1, s21_strcat_tests_case_2);
  tcase_add_test(tc1_1, s21_strcat_tests_case_3);
  tcase_add_test(tc1_1, s21_strcat_tests_case_4);
  tcase_add_test(tc1_1, s21_strcat_tests_case_5);
  tcase_add_test(tc1_1, s21_strcat_tests_case_6);
  tcase_add_test(tc1_1, s21_strcat_tests_case_7);
  tcase_add_test(tc1_1, s21_strcat_tests_case_8);
  tcase_add_test(tc1_1, s21_strcat_tests_case_9);
  tcase_add_test(tc1_1, s21_strcat_tests_case_10);
  tcase_add_test(tc1_1, s21_strncat_tests_case_1);
  tcase_add_test(tc1_1, s21_strncat_tests_case_2);
  tcase_add_test(tc1_1, s21_strncat_tests_case_3);
  tcase_add_test(tc1_1, s21_strncat_tests_case_4);
  tcase_add_test(tc1_1, s21_strncat_tests_case_5);
  tcase_add_test(tc1_1, s21_strncat_tests_case_6);
  tcase_add_test(tc1_1, s21_strncat_tests_case_7);
  tcase_add_test(tc1_1, s21_strncat_tests_case_8);
  tcase_add_test(tc1_1, s21_strncat_tests_case_9);
  tcase_add_test(tc1_1, s21_strncat_tests_case_10);
  tcase_add_test(tc1_1, s21_strpbrk_tests_case_1);
  tcase_add_test(tc1_1, s21_strpbrk_tests_case_2);
  tcase_add_test(tc1_1, s21_strpbrk_tests_case_3);
  tcase_add_test(tc1_1, s21_strpbrk_tests_case_4);
  tcase_add_test(tc1_1, s21_strpbrk_tests_case_5);
  tcase_add_test(tc1_1, s21_strrchr_tests_case_1);
  tcase_add_test(tc1_1, s21_strrchr_tests_case_2);
  tcase_add_test(tc1_1, s21_strrchr_tests_case_3);
  tcase_add_test(tc1_1, s21_strrchr_tests_case_4);
  tcase_add_test(tc1_1, s21_strrchr_tests_case_5);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_1);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_2);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_3);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_4);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_5);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_6);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_7);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_8);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_9);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_10);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_11);
  tcase_add_test(tc1_1, s21_sprintf_tests_case_12);
  tcase_add_test(tc1_1, s21_strcspn_tests_case);
  tcase_add_loop_test(tc1_1, s21_strcspn_random_tests_case, 0, 10);
  tcase_add_test(tc1_1, s21_strtok_tests_case);
  tcase_add_loop_test(tc1_1, s21_strspn_random_tests_case, 0, 10);
  tcase_add_test(tc1_1, s21_str_insert_tests_case);
  tcase_add_test(tc1_1, s21_strtok_tests_case);
  tcase_add_test(tc1_1, s21_strspn_tests_case);
#ifndef __linux__
  tcase_add_test(tc1_1, s21_str_strerror_tests_case);
#endif
  tcase_add_test(tc1_1, s21_str_to_lower_tests_case);
  tcase_add_test(tc1_1, s21_str_to_upper_tests_case);
  tcase_add_test(tc1_1, s21_str_trim_tests_case);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
