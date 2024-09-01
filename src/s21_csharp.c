#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *p = (char *)str;
  int len = s21_strlen(str);
  char *arr = (char *)malloc((len + 1) * sizeof(char));
  int i = 0;
  while (*p != '\0') {
    if (*p > 96 && *p < 123) {
      arr[i] = *p - 32;
    } else {
      arr[i] = *p;
    }
    i++;
    p++;
  }
  arr[i] = '\0';
  p = arr;
  return p;
}

void *s21_to_lower(const char *str) {
  char *p = (char *)str;
  int len = s21_strlen(str);
  char *arr = (char *)malloc((len + 1) * sizeof(char));
  int i = 0;
  while (*p != '\0') {
    if (*p > 64 && *p < 91) {
      arr[i] = *p + 32;
    } else {
      arr[i] = *p;
    }
    i++;
    p++;
  }
  arr[i] = '\0';
  p = arr;
  return p;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *out = S21_NULL;
  s21_size_t srclen = 0;
  s21_size_t strlen = 0;
  if (src != S21_NULL) {
    srclen = s21_strlen(src);
  }
  if (str != S21_NULL) {
    strlen = s21_strlen(str);
  }
  if (start_index <= srclen) {
    char *str_new = calloc(srclen + strlen + 1, sizeof(char));
    if (str_new != S21_NULL) {
      for (s21_size_t i = 0; i < srclen + strlen; i++) {
        if (i < start_index) {
          str_new[i] = src[i];
        } else if (i < strlen + start_index) {
          str_new[i] = str[i - start_index];
        } else {
          str_new[i] = src[i - strlen];
        }
      }
      out = str_new;
    }
  }
  return (void *)out;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *out = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL) {
    s21_size_t srclen = s21_strlen(src);
    s21_size_t trim_chars_len = s21_strlen(trim_chars);
    if (trim_chars_len == 0) {
      trim_chars_len = 4;
      trim_chars = " \n\t\r";
    }
    int delete_char = 0;
    s21_size_t start = 0;
    s21_size_t end = srclen;
    int all_deleted = 0;
    if (srclen > 0) {
      for (s21_size_t i = 0; i < srclen; i++) {
        for (s21_size_t j = 0; j < trim_chars_len; j++) {
          if (*(src + i) == *(trim_chars + j)) {
            delete_char = 1;
            break;
          } else {
            delete_char = 0;
          }
        }
        if (delete_char != 1) {
          start = i;
          break;
        }
        if (i == srclen - 1) {
          all_deleted = 1;
        }
      }
      delete_char = 0;
      for (s21_size_t i = srclen - 1; i > 0; i--) {
        for (s21_size_t j = 0; j < trim_chars_len; j++) {
          if (*(src + i) == *(trim_chars + j)) {
            delete_char = 1;
            break;
          } else {
            delete_char = 0;
          }
        }
        if (delete_char != 1) {
          end = i;
          break;
        }
      }

      if (all_deleted == 0) {
        char *str_new = calloc((end - start + 3), sizeof(char));
        if (str_new != S21_NULL) {
          s21_size_t j = 0;
          for (s21_size_t i = start; i <= end; i++, j++) {
            str_new[j] = src[i];
          }
          str_new[j + 1] = '\0';
          out = str_new;
        }
      } else {
        char *str_new = calloc(1, sizeof(char));
        out = str_new;
      }

    } else if (srclen == 0) {
      char *str_new = calloc(1, sizeof(char));
      out = str_new;
    }
  }

  return out;
}
