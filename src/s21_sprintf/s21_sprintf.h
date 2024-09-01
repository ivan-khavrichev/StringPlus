#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include "../s21_string.h"

typedef struct format_spec {
  char wid_c;
  char sign_c;
  int long_1;
  int long_long;
  int short_1;
  int minus;
  int plus;
  int sign;
  int space;
  int width;
  int precision;
  int prec_flag;
  int flags;
} Format_specifier;

void init_format(Format_specifier *for_spec);
int flags_processing(int index, const char *format_str,
                     Format_specifier *format_spec);
int length_processing(int index, const char *format_str,
                      Format_specifier *format_spec);
int width_processing(int index, const char *format_str, char *wid,
                     Format_specifier *format_spec, va_list spec);
int accuracy_processing(int index, const char *format_str,
                        Format_specifier *format_spec, va_list spec);
void int_processing(Format_specifier *format_spec, va_list specifier,
                    char *str);
void uint_processing(Format_specifier *format_spec, va_list specifier,
                     char *str);
void char_processing(Format_specifier *format_spec, va_list specifier,
                     char *str);
void string_processing(Format_specifier *format_spec, va_list specifier,
                       char *str);
void float_processing(Format_specifier *format_spec, va_list specifier,
                      char *str);
char *itoa(long long i);
void charcat(char *dest, char cat);

#endif  // SRC_S21_SSCANF_H_