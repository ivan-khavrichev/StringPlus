#include "../s21_string.h"
#include "s21_sprintf.h"

void char_processing(Format_specifier *format_spec, va_list specifier,
                     char *str) {
  if (format_spec->width != 0) {
    if (format_spec->minus == 0) {
      for (int i = 0; i < format_spec->width - 1; i++) {
        charcat(str, format_spec->wid_c);
      }
      charcat(str, va_arg(specifier, int));
    } else if (format_spec->minus == 1) {
      charcat(str, va_arg(specifier, int));
      for (int i = 0; i < format_spec->width - 1; i++) {
        charcat(str, format_spec->wid_c);
      }
    }
  } else {
    charcat(str, va_arg(specifier, int));
  }
}

void string_processing(Format_specifier *format_spec, va_list specifier,
                       char *str) {
  char *s = va_arg(specifier, char *);
  int length = s21_strlen(s);
  if (length > format_spec->precision && format_spec->prec_flag) {
    length -= length - format_spec->precision;
  }
  if (format_spec->width != 0) {
    if (format_spec->minus == 0) {
      for (int i = 0; i < format_spec->width - (int)length; i++) {
        charcat(str, format_spec->wid_c);
      }
      if (format_spec->prec_flag == 0) {
        s21_strcat(str, s);
      } else {
        s21_strncat(str, s, format_spec->precision);
      }
    } else if (format_spec->minus == 1) {
      if (format_spec->prec_flag == 0) {
        s21_strcat(str, s);
      } else {
        s21_strncat(str, s, format_spec->precision);
      }
      for (int i = 0; i < format_spec->width - (int)length; i++) {
        charcat(str, format_spec->wid_c);
      }
    }
  } else {
    if (format_spec->prec_flag == 0) {
      s21_strcat(str, s);
    } else {
      s21_strncat(str, s, format_spec->precision);
    }
  }
}
