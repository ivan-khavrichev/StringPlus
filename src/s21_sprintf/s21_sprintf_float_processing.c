#include "../s21_string.h"
#include "s21_sprintf.h"

void float_processing(Format_specifier *format_spec, va_list specifier,
                      char *str) {
  s21_size_t len = 1;
  int _sign = 0;
  if (format_spec->prec_flag == 0) {
    format_spec->precision = 6;
  }
  char *float_part_str = S21_NULL;
  long double arg;
  if (format_spec->long_1) {
    arg = va_arg(specifier, double);
  } else if (format_spec->long_long) {
    arg = va_arg(specifier, long double);
  } else {
    arg = va_arg(specifier, double);
  }
  if (arg < 0) {
    _sign = -1;
    arg = -1 * arg;
  }
  char *res = S21_NULL;
  long int_part = (long)arg;
  long double float_part_pow =
      (arg - int_part) * pow(10, format_spec->precision);
  long long float_part = (long long)float_part_pow;
  long double diff = float_part_pow - float_part;
  if (diff > 0.5) {
    float_part++;
    if (float_part >= pow(10, format_spec->precision)) {
      float_part = 0;
      int_part++;
    }
  }
  if (format_spec->precision == 0) {
    diff = arg - (long double)int_part;
    // Если дробная часть 0.5 или более И число нечётное
    if (diff >= 0.5 && (int_part & 1)) {
      // округляем в большую сторону
      int_part++;
    }
  } else {
    float_part_str = itoa(float_part);
  }
  char *int_part_str = itoa(int_part);

  len = s21_strlen(int_part_str) +
        ((float_part_str) ? s21_strlen(float_part_str) : 0);
  res = (char *)malloc(sizeof(char) * (len + 13 + format_spec->precision));

  if (res) {
    *res = '\0';
    if (_sign == -1) {
      s21_strcat(res, "-");
    } else if (format_spec->sign) {
      charcat(res, format_spec->sign_c);
    }

    s21_strcat(res, int_part_str);

    if (float_part_str) {
      s21_strcat(res, ".");
      s21_size_t fp_len = s21_strlen(float_part_str);
      while ((int)fp_len < format_spec->precision) {
        s21_strcat(res, "0");
        fp_len++;
      }
      s21_strcat(res, float_part_str);
    }

    free(float_part_str);
    if (int_part_str) free(int_part_str);
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