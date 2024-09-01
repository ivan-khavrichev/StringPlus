#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *p = str;
  const char *end = str + n;
  int flag = 0;
  for (; p < end; p++) {
    if (*p == c) {
      flag = 1;
      break;
    }
  }
  return flag ? (void *)p : S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *p1 = str1;
  const char *p2 = str2;
  const char *end = str1 + n;
  int flag = 0;
  for (; p1 < end; p1++, p2++) {
    if (*p1 > *p2 || *p1 < *p2) {
      flag = *p1 - *p2;
      break;
    }
  }
  return flag;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
    }
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *p = dest;
  unsigned char *p_copy = (unsigned char *)src;
  unsigned char *p_copy_end = (unsigned char *)src + n;
  unsigned char *tmp_arr;
  tmp_arr = (unsigned char *)malloc(n * sizeof(unsigned char));
  for (int i = 0; p_copy < p_copy_end; i++, p_copy++) {
    tmp_arr[i] = *p_copy;
  }
  p_copy -= n;
  for (int i = 0; p_copy < p_copy_end; i++, p++, p_copy++) {
    *p = tmp_arr[i];
  }
  free(tmp_arr);
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *p = str;
  char *end = str + n;
  for (; p < end; p++) {
    *p = c;
  }
  return (void *)str;
}

char *s21_strcat(char *dest, const char *src) {
  int count = s21_strlen(dest);
  while (*src != '\0') {
    *(dest + count) = *src++;
    count++;
  }
  *(dest + count) = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  const char *p_copy = src;
  const char *p_copy_end = src + n;
  while (*p != '\0') {
    p++;
  }
  for (; p_copy < p_copy_end; p++, p_copy++) {
    *p = *p_copy;
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *out = S21_NULL;
  s21_size_t strlen = s21_strlen(str);
  for (s21_size_t i = 0; i < strlen + 1; i++) {
    if (*(str + i) == c) {
      out = (char *)(str + i);
      break;
    }
  }
  return out;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1) {
    if (*str1 != *str2) {
      break;
    }
    str1++;
    str2++;
  }
  return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *p1 = str1;
  const char *p2 = str2;
  int res = 0;
  s21_size_t step = 0;
  while ((*p1 != '\0' || *p2 != '\0') && step != n) {
    if ((*p1 - *p2) != 0) {
      res = *p1 - *p2;
      break;
    }
    p1++;
    p2++;
    step++;
  }
  return res;
}

char *s21_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  while (*src != '\0' && dest) {
    *dest = *src;
    dest++;
    src++;
  }
  if (dest) {
    *dest = '\0';
  }
  return ptr;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  int flag = 0;
  while (i != n) {
    if (*(src + i) != '\0' && flag == 0) {
      *(dest + i) = *(src + i);
    } else {
      flag = 1;
    }
    if (flag != 0) {
      *(dest + i) = '\0';
    }
    i++;
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p = str2;
  int flag = 0;
  s21_size_t len = 0;
  while (*str1 != '\0' && flag != 1) {
    p = str2;
    while (*p != '\0') {
      if (*p == *str1) {
        flag = 1;
        break;
      }
      p++;
    }
    len++;
    str1++;
  }
  if (flag == 1) {
    len--;
  }
  return len;
}

s21_size_t s21_strlen(const char *str) {
  const char *end = str;
  for (end = str; *end != '\0'; ++end) {
    ;
  }
  return (end - str);
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *out = S21_NULL;
  int quit_cycle = 0;
  s21_size_t str1len = s21_strlen(str1);
  s21_size_t str2len = s21_strlen(str2);
  for (s21_size_t i = 0; i < str1len; i++) {
    for (s21_size_t j = 0; j < str2len; j++) {
      if (*(str1 + i) == *(str2 + j)) {
        out = (char *)(str1 + i);
        quit_cycle = 1;
        break;
      }
    }
    if (quit_cycle == 1) {
      break;
    }
  }
  return out;
}

char *s21_strrchr(const char *str, int c) {
  const char *p = S21_NULL;
  if (c != '\0') {
    while (*str != '\0') {
      if (*str == c) {
        p = str;
      }
      str++;
    }
  } else {
    p = str + s21_strlen(str);
  }
  return (char *)p;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t out = 0;
  int in_str = 0;
  s21_size_t str1len = s21_strlen(str1);
  s21_size_t str2len = s21_strlen(str2);
  for (s21_size_t i = 0; i < str1len; i++) {
    in_str = 0;
    for (s21_size_t j = 0; j < str2len; j++) {
      if (*(str1 + i) == *(str2 + j)) {
        in_str = 1;
        break;
      }
    }
    if (in_str == 1) {
      out++;
    } else {
      break;
    }
  }
  return out;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *p = (char *)haystack;
  char *p_needle = (char *)needle;
  if (s21_strlen(needle) != 0) {
    p = s21_strchr(haystack, *needle);
    if (p != S21_NULL) {
      int flag = 0;
      while (*p_needle != '\0' && flag != 1) {
        if (*p != *p_needle) {
          flag = 1;
          p = S21_NULL;
          break;
        } else {
          p++;
          p_needle++;
        }
      }
      if (flag == 0) {
        p = s21_strchr(haystack, *needle);
      }
    }
  }
  return p;
}

char *s21_strtok(char *str, const char *delim) {
  char *p = str;
  const char *p_delim = delim;
  static char *next_p = 0;
  if (p != S21_NULL) {
    str = s21_strtok_delim(p, p_delim, delim);
    next_p = s21_strtok_leksem(str, p_delim, delim);
  } else {
    p = next_p;
    str = s21_strtok_delim(p, p_delim, delim);
    next_p = s21_strtok_leksem(str, p_delim, delim);
  }
  return str;
}

char *s21_strtok_leksem(char *p, const char *p_delim, const char *delim) {
  int flag_delim = 0;
  if (p != S21_NULL) {
    while (*p != '\0' && flag_delim != 1) {
      p_delim = delim;
      while (*p_delim != '\0') {
        if (*p == *p_delim) {
          *p = '\0';
          flag_delim = 1;
          break;
        }
        p_delim++;
      }
      p++;
    }
  }
  return p;
}

char *s21_strtok_delim(char *p, const char *p_delim, const char *delim) {
  int flag_delim = 0;
  while (*p != '\0' && flag_delim != 1) {
    p_delim = delim;
    while (*p_delim != '\0') {
      if (*p == *p_delim) {
        *p = '\0';
        break;
      }
      p_delim++;
    }
    if (*p_delim == '\0') {
      flag_delim = 1;
    } else {
      p++;
    }
  }
  if (*p == '\0') {
    p = S21_NULL;
  }
  return p;
}
