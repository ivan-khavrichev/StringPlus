#include "../s21_string.h"
#include "s21_sprintf.h"

void int_processing(Format_specifier *format_spec, va_list specifier,
                    char *str) {
  long long arg;
  char *res = S21_NULL;
  if (format_spec->prec_flag == 0) {
    format_spec->precision = 1;
  }
  if (format_spec->long_1) {
    arg = va_arg(specifier, long long);
  } else if (format_spec->short_1) {
    int tmp = va_arg(specifier, int);
    short int tmp2 = (short int)tmp;
    arg = tmp2;
  } else {
    arg = va_arg(specifier, int);
  }
  if (arg == 0 && format_spec->precision == 0) {
    res = malloc(sizeof(char));
    if (res) free(res);
  } else {
    char *chislo = itoa(arg);
    long long len = (long long)s21_strlen(chislo);
    if (format_spec->precision > len) {
      len = len + (format_spec->precision - len);
    }
    if ((arg >= 0 && (format_spec->sign)) || arg < 0) {
      len++;
    }
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (res) {
      *res = '\0';
      if (arg < 0) {
        s21_strcat(res, "-");
      } else {
        if (format_spec->sign) {
          charcat(res, format_spec->sign_c);
        }
      }
      if (format_spec->precision > (long long)s21_strlen(chislo)) {
        for (long unsigned int i = 0;
             i < format_spec->precision - s21_strlen(chislo); i++)
          s21_strcat(res, "0");
      }
      s21_strcat(res, chislo);
    }
    free(chislo);
    if (format_spec->width != 0 &&
        (s21_size_t)format_spec->width > s21_strlen(res)) {
      s21_size_t to_append_len = s21_strlen(res);
      int spaces_len = (s21_size_t)format_spec->width - to_append_len;
      char *to_append_ext =
          (char *)realloc(res, sizeof(char) * (spaces_len + 1 + to_append_len));
      s21_memset(to_append_ext + to_append_len, '\0', spaces_len + 1);
      if (to_append_ext) {
        res = to_append_ext;
        if (format_spec->minus) {
          s21_memset(res + to_append_len, ' ', spaces_len);
          *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
        } else {
          s21_memmove(res + spaces_len, res, to_append_len);
          s21_memset(res, ' ', spaces_len);
          *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
        }
        s21_strcat(str, res);
        free(res);
      }
    } else {
      s21_strcat(str, res);
      free(res);
    }
  }
}

void uint_processing(Format_specifier *format_spec, va_list specifier,
                     char *str) {
  char *res = S21_NULL;
  unsigned long long arg;
  if (format_spec->long_1) {
    arg = va_arg(specifier, unsigned long long);
  } else if (format_spec->short_1) {
    unsigned int tmp = va_arg(specifier, unsigned int);
    unsigned short tmp2 = (unsigned short)tmp;
    arg = tmp2;
  } else {
    arg = va_arg(specifier, unsigned int);
  }
  char *chislo = (char *)malloc(sizeof(char) * 2);
  s21_memset(chislo, '\0', 2);
  if (chislo) {
    int l = 1;
    s21_size_t k = 0;
    do {
      char *str_tmp = realloc(chislo, sizeof(char) * (l + 1));
      if (str_tmp) {
        chislo = str_tmp;
      }
      l++;
      int dig = arg % 10;
      if (dig < 0) dig *= -1;
      chislo[k] = dig + '0';
      k++;
      arg /= 10;
    } while (arg != 0);

    chislo[k] = '\0';

    for (k = 0; k < s21_strlen(chislo) / 2; k++) {
      char tmp = chislo[k];
      chislo[k] = chislo[s21_strlen(chislo) - k - 1];
      chislo[s21_strlen(chislo) - k - 1] = tmp;
    }
    s21_size_t len = s21_strlen(chislo);
    if (format_spec->precision > (int)len) {
      len = len + (format_spec->precision - len);
    }
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (res) {
      s21_memset(res, '\0', len + 1);
      if (format_spec->precision > (int)s21_strlen(chislo)) {
        for (long unsigned int i = 0;
             i < format_spec->precision - s21_strlen(chislo); i++)
          s21_strcat(res, "0");
      }
      s21_strcat(res, chislo);
    }
    free(chislo);
  }
  if (format_spec->width != 0 &&
      (s21_size_t)format_spec->width > s21_strlen(res)) {
    s21_size_t to_append_len = s21_strlen(res);
    int spaces_len = (s21_size_t)format_spec->width - to_append_len;
    char *to_append_ext =
        (char *)realloc(res, sizeof(char) * (spaces_len + 1 + to_append_len));
    s21_memset(to_append_ext + to_append_len, '\0', spaces_len + 1);
    if (to_append_ext) {
      res = to_append_ext;
      if (format_spec->minus) {
        s21_memset(res + to_append_len, ' ', spaces_len);
        *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
      } else {
        s21_memmove(res + spaces_len, res, to_append_len);
        s21_memset(res, ' ', spaces_len);
        *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
      }
      s21_strcat(str, res);
      free(res);
    }
  } else {
    s21_strcat(str, res);
    free(res);
  }
}

void charcat(char *dest, char cat) {
  s21_size_t len = s21_strlen(dest);
  dest[len] = cat;
  dest[len + 1] = '\0';
}

char *itoa(long long i) {
  long long arg = i;
  // int dig;
  char *res = (char *)malloc(sizeof(char) * 2);
  if (res && i != 0) {
    int len = 1;
    s21_size_t k = 0;
    do {
      char *res_tmp = realloc(res, sizeof(char) * (len + 1));
      if (res_tmp) {
        res = res_tmp;
      }
      len++;
      int dig = arg % 10;
      if (dig < 0) dig *= -1;
      res[k] = dig + '0';
      k++;
      arg /= 10;
    } while (arg != 0);

    res[k] = '\0';

    for (k = 0; k < s21_strlen(res) / 2; k++) {
      char tmp = res[k];
      res[k] = res[s21_strlen(res) - k - 1];
      res[s21_strlen(res) - k - 1] = tmp;
    }

  } else if (res && i == 0) {
    s21_strcpy(res, "0\0");
  }
  return res;
}