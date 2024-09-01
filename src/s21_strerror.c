#include "s21_string.h"

#ifdef __APPLE__
char *s21_strerror(int errnum) {
  char *out[108];
  out[0] = "Undefined error: 0";
  out[1] = "Operation not permitted";
  out[2] = "No such file or directory";
  out[3] = "No such process";
  out[4] = "Interrupted system call";
  out[5] = "Input/output error";
  out[6] = "Device not configured";
  out[7] = "Argument list too long";
  out[8] = "Exec format error";
  out[9] = "Bad file descriptor";
  out[10] = "No child processes";
  out[11] = "Resource deadlock avoided";
  out[12] = "Cannot allocate memory";
  out[13] = "Permission denied";
  out[14] = "Bad address";
  out[15] = "Block device required";
  out[16] = "Resource busy";
  out[17] = "File exists";
  out[18] = "Cross-device link";
  out[19] = "Operation not supported by device";
  out[20] = "Not a directory";
  out[21] = "Is a directory";
  out[22] = "Invalid argument";
  out[23] = "Too many open files in system";
  out[24] = "Too many open files";
  out[25] = "Inappropriate ioctl for device";
  out[26] = "Text file busy";
  out[27] = "File too large";
  out[28] = "No space left on device";
  out[29] = "Illegal seek";
  out[30] = "Read-only file system";
  out[31] = "Too many links";
  out[32] = "Broken pipe";
  out[33] = "Numerical argument out of domain";
  out[34] = "Result too large";
  out[35] = "Resource temporarily unavailable";
  out[36] = "Operation now in progress";
  out[37] = "Operation already in progress";
  out[38] = "Socket operation on non-socket";
  out[39] = "Destination address required";
  out[40] = "Message too long";
  out[41] = "Protocol wrong type for socket";
  out[42] = "Protocol not available";
  out[43] = "Protocol not supported";
  out[44] = "Socket type not supported";
  out[45] = "Operation not supported";
  out[46] = "Protocol family not supported";
  out[47] = "Address family not supported by protocol family";
  out[48] = "Address already in use";
  out[49] = "Can't assign requested address";
  out[50] = "Network is down";
  out[51] = "Network is unreachable";
  out[52] = "Network dropped connection on reset";
  out[53] = "Software caused connection abort";
  out[54] = "Connection reset by peer";
  out[55] = "No buffer space available";
  out[56] = "Socket is already connected";
  out[57] = "Socket is not connected";
  out[58] = "Can't send after socket shutdown";
  out[59] = "Too many references: can't splice";
  out[60] = "Operation timed out";
  out[61] = "Connection refused";
  out[62] = "Too many levels of symbolic links";
  out[63] = "File name too long";
  out[64] = "Host is down";
  out[65] = "No route to host";
  out[66] = "Directory not empty";
  out[67] = "Too many processes";
  out[68] = "Too many users";
  out[69] = "Disc quota exceeded";
  out[70] = "Stale NFS file handle";
  out[71] = "Too many levels of remote in path";
  out[72] = "RPC struct is bad";
  out[73] = "RPC version wrong";
  out[74] = "RPC prog. not avail";
  out[75] = "Program version wrong";
  out[76] = "Bad procedure for program";
  out[77] = "No locks available";
  out[78] = "Function not implemented";
  out[79] = "Inappropriate file type or format";
  out[80] = "Authentication error";
  out[81] = "Need authenticator";
  out[82] = "Device power is off";
  out[83] = "Device error";
  out[84] = "Value too large to be stored in data type";
  out[85] = "Bad executable (or shared library)";
  out[86] = "Bad CPU type in executable";
  out[87] = "Shared library version mismatch";
  out[88] = "Malformed Mach-o file";
  out[89] = "Operation canceled";
  out[90] = "Identifier removed";
  out[91] = "No message of desired type";
  out[92] = "Illegal byte sequence";
  out[93] = "Attribute not found";
  out[94] = "Bad message";
  out[95] = "EMULTIHOP (Reserved)";
  out[96] = "No message available on STREAM";
  out[97] = "ENOLINK (Reserved)";
  out[98] = "No STREAM resources";
  out[99] = "Not a STREAM";
  out[100] = "Protocol error";
  out[101] = "STREAM ioctl timeout";
  out[102] = "Operation not supported on socket";
  out[103] = "Policy not found";
  out[104] = "State not recoverable";
  out[105] = "Previous owner died";
  out[106] = "Interface output queue is full";

  // Unknown error
  if ((errnum > 106) || (errnum < 0)) {
    char num[20] = {0};
    simple_itoa(errnum, num);
    static char str_out[36];
    s21_memset(str_out, 0, 36);
    s21_strcat(str_out, "Unknown error: ");
    errnum = 107;
    out[107] = S21_NULL;
    out[107] = s21_strcat(str_out, num);
  }
  return out[errnum];
}
#endif

#ifdef __linux__
char *s21_strerror(int errnum) {
  char *out[135];
  out[0] = "Success";
  out[1] = "Operation not permitted";
  out[2] = "No such file or directory";
  out[3] = "No such process";
  out[4] = "Interrupted system call";
  out[5] = "Input/output error";
  out[6] = "No such device or address";
  out[7] = "Argument list too long";
  out[8] = "Exec format error";
  out[9] = "Bad file descriptor";
  out[10] = "No child processes";
  out[11] = "Resource temporarily unavailable";
  out[12] = "Cannot allocate memory";
  out[13] = "Permission denied";
  out[14] = "Bad address";
  out[15] = "Block device required";
  out[16] = "Device or resource busy";
  out[17] = "File exists";
  out[18] = "Invalid cross-device link";
  out[19] = "No such device";
  out[20] = "Not a directory";
  out[21] = "Is a directory";
  out[22] = "Invalid argument";
  out[23] = "Too many open files in system";
  out[24] = "Too many open files";
  out[25] = "Inappropriate ioctl for device";
  out[26] = "Text file busy";
  out[27] = "File too large";
  out[28] = "No space left on device";
  out[29] = "Illegal seek";
  out[30] = "Read-only file system";
  out[31] = "Too many links";
  out[32] = "Broken pipe";
  out[33] = "Numerical argument out of domain";
  out[34] = "Numerical result out of range";
  out[35] = "Resource deadlock avoided";
  out[36] = "File name too long";
  out[37] = "No locks available";
  out[38] = "Function not implemented";
  out[39] = "Directory not empty";
  out[40] = "Too many levels of symbolic links";
  out[41] = "Unknown error 41";
  out[42] = "No message of desired type";
  out[43] = "Identifier removed";
  out[44] = "Channel number out of range";
  out[45] = "Level 2 not synchronized";
  out[46] = "Level 3 halted";
  out[47] = "Level 3 reset";
  out[48] = "Link number out of range";
  out[49] = "Protocol driver not attached";
  out[50] = "No CSI structure available";
  out[51] = "Level 2 halted";
  out[52] = "Invalid exchange";
  out[53] = "Invalid request descriptor";
  out[54] = "Exchange full";
  out[55] = "No anode";
  out[56] = "Invalid request code";
  out[57] = "Invalid slot";
  out[58] = "Unknown error 58";
  out[59] = "Bad font file format";
  out[60] = "Device not a stream";
  out[61] = "No data available";
  out[62] = "Timer expired";
  out[63] = "Out of streams resources";
  out[64] = "Machine is not on the network";
  out[65] = "Package not installed";
  out[66] = "Object is remote";
  out[67] = "Link has been severed";
  out[68] = "Advertise error";
  out[69] = "Srmount error";
  out[70] = "Communication error on send";
  out[71] = "Protocol error";
  out[72] = "Multihop attempted";
  out[73] = "RFS specific error";
  out[74] = "Bad message";
  out[75] = "Value too large for defined data type";
  out[76] = "Name not unique on network";
  out[77] = "File descriptor in bad state";
  out[78] = "Remote address changed";
  out[79] = "Can not access a needed shared library";
  out[80] = "Accessing a corrupted shared library";
  out[81] = ".lib section in a.out corrupted";
  out[82] = "Attempting to link in too many shared libraries";
  out[83] = "Cannot exec a shared library directly";
  out[84] = "Invalid or incomplete multibyte or wide character";
  out[85] = "Interrupted system call should be restarted";
  out[86] = "Streams pipe error";
  out[87] = "Too many users";
  out[88] = "Socket operation on non-socket";
  out[89] = "Destination address required";
  out[90] = "Message too long";
  out[91] = "Protocol wrong type for socket";
  out[92] = "Protocol not available";
  out[93] = "Protocol not supported";
  out[94] = "Socket type not supported";
  out[95] = "Operation not supported";
  out[96] = "Protocol family not supported";
  out[97] = "Address family not supported by protocol";
  out[98] = "Address already in use";
  out[99] = "Cannot assign requested address";
  out[100] = "Network is down";
  out[101] = "Network is unreachable";
  out[102] = "Network dropped connection on reset";
  out[103] = "Software caused connection abort";
  out[104] = "Connection reset by peer";
  out[105] = "No buffer space available";
  out[106] = "Transport endpoint is already connected";
  out[107] = "Transport endpoint is not connected";
  out[108] = "Cannot send after transport endpoint shutdown";
  out[109] = "Too many references: cannot splice";
  out[110] = "Connection timed out";
  out[111] = "Connection refused";
  out[112] = "Host is down";
  out[113] = "No route to host";
  out[114] = "Operation already in progress";
  out[115] = "Operation now in progress";
  out[116] = "Stale file handle";
  out[117] = "Structure needs cleaning";
  out[118] = "Not a XENIX named type file";
  out[119] = "No XENIX semaphores available";
  out[120] = "Is a named type file";
  out[121] = "Remote I/O error";
  out[122] = "Disk quota exceeded";
  out[123] = "No medium found";
  out[124] = "Wrong medium type";
  out[125] = "Operation canceled";
  out[126] = "Required key not available";
  out[127] = "Key has expired";
  out[128] = "Key has been revoked";
  out[129] = "Key was rejected by service";
  out[130] = "Owner died";
  out[131] = "State not recoverable";
  out[132] = "Operation not possible due to RF-kill";
  out[133] = "Memory page has hardware error";

  // Unknown error
  if ((errnum > 134) || (errnum < 0)) {
    char num[20] = {0};
    simple_itoa(errnum, num);
    static char str_out[36];
    s21_memset(str_out, 0, 36);
    s21_strcat(str_out, "Unknown error: ");
    errnum = 134;
    out[134] = S21_NULL;
    out[134] = s21_strcat(str_out, num);
  }
  return out[errnum];
}
#endif

int simple_itoa(int n, char *s) {
  int len = 0;
  int sign = n;
  if ((sign) < 0) n = -1 * n;

  do {
    s[len] = n % 10 + '0';
    len += 1;
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[len] = '-';
    len += 1;
  }

  reverse_str(s);
  return len;
}

void reverse_str(char *s) {
  char c = 0;

  for (int i = 0, j = (int)s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}