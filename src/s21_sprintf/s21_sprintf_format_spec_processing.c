#include "../s21_string.h"
#include "s21_sprintf.h"

int flags_processing(int index, const char *format_str,
                     Format_specifier *format_spec) {
  int out = 0;
  while (format_spec->flags != 1) {
    switch (*(format_str + index)) {
      case '-': {
        format_spec->minus = 1;
        out++;
        index++;
        break;
      }
      case ' ': {
        format_spec->sign = 1;
        out++;
        index++;
        if (format_spec->plus == 0) {
          format_spec->space = 1;
          format_spec->sign_c = ' ';
        }
        break;
      }
      case '+': {
        format_spec->sign = 1;
        format_spec->plus = 1;
        if (format_spec->space == 1) {
          format_spec->space = 0;
          format_spec->sign_c = '+';
        }
        out++;
        index++;
        break;
      }
      default: {
        format_spec->flags = 1;
      }
    }
  }
  return out;
}

int width_processing(int index, const char *format_str, char *wid,
                     Format_specifier *format_spec, va_list spec) {
  int out = 0;
  if (*(format_str + index) == '*') {
    format_spec->width = va_arg(spec, int);
    if (format_spec->width < 0) {
      format_spec->width *= -1;
    }
    // format_str++;
    out++;
    index++;
  } else if (*(format_str + index) >= '0' && *(format_str + index) <= '9') {
    int width_counter = 0;
    while (*(format_str + index) >= '0' && *(format_str + index) <= '9') {
      charcat(wid, *(format_str + index));
      // format_str++;
      index++;
      out++;
      width_counter++;
      if (width_counter == 4 && *(format_str + index) >= '0' &&
          *(format_str + index) <= '9') {
        return -1;
      }
    }
    format_spec->width = atoi(wid);
  }
  return out;
}

int accuracy_processing(int index, const char *format_str,
                        Format_specifier *format_spec, va_list spec) {
  int out = 0;
  if (*(format_str + index) == '.') {
    index++;
    out++;
    format_spec->prec_flag = 1;
    if (*(format_str + index) == '*') {
      format_spec->precision = va_arg(spec, int);
      if (format_spec->precision <= 0) {
        format_spec->precision = 0;
      }
      index++;
      out++;
    } else {
      char prec[5] = "\0";
      int prec_counter = 0;
      while (*(format_str + index) >= '0' && *(format_str + index) <= '9') {
        charcat(prec, *(format_str + index));
        index++;
        out++;
        prec_counter++;
        if (prec_counter == 4 && *(format_str + index) >= '0' &&
            *(format_str + index) <= '9') {
          return -1;
        }
      }
      format_spec->precision = atoi(prec);
    }
  }
  return out;
}

int length_processing(int index, const char *format_str,
                      Format_specifier *format_spec) {
  int out = 0;
  if (*(format_str + index) == 'l') {
    index++;
    out++;
    format_spec->long_1 = 1;
  }
  if (*(format_str + index) == 'L') {
    index++;
    out++;
    format_spec->long_long = 1;
  }
  if (*(format_str + index) == 'h') {
    index++;
    out++;
    format_spec->short_1 = 1;
  }
  return out;
}