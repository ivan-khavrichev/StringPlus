#include "s21_sprintf.h"

#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...) {
  *str = '\0';
  Format_specifier for_specifier = {0};
  va_list specifier = {0};
  va_start(specifier, format);

  for (int i = 0; i < (int)s21_strlen(format); i++) {
    if (format[i] == '%') {
      i++;
      init_format(&for_specifier);
      char wid[5] = "\0";

      i += flags_processing(i, format, &for_specifier);
      i += width_processing(i, format, wid, &for_specifier, specifier);
      i += accuracy_processing(i, format, &for_specifier, specifier);
      i += length_processing(i, format, &for_specifier);

      if (format[i] == '%') {
        charcat(str, '%');
      }
      if (format[i] == 'd' || format[i] == 'i') {
        int_processing(&for_specifier, specifier, str);
      }
      if (format[i] == 'c') {
        char_processing(&for_specifier, specifier, str);
      }
      if (format[i] == 's') {
        string_processing(&for_specifier, specifier, str);
      }
      if (format[i] == 'u') {
        uint_processing(&for_specifier, specifier, str);
      }
      if (format[i] == 'f' || format[i] == 'F') {
        float_processing(&for_specifier, specifier, str);
      }
    } else {
      charcat(str, format[i]);
    }
  }
  va_end(specifier);
  return s21_strlen(str);
}

void init_format(Format_specifier *for_spec) {
  for_spec->wid_c = ' ';
  for_spec->sign_c = '+';
  for_spec->long_1 = 0;
  for_spec->long_long = 0;
  for_spec->short_1 = 0;
  for_spec->minus = 0;
  for_spec->plus = 0;
  for_spec->sign = 0;
  for_spec->space = 0;
  for_spec->width = 0;
  for_spec->precision = 0;
  for_spec->prec_flag = 0;
  for_spec->flags = 0;
}
