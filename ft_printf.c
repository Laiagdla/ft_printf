#include <stdarg.h>
#include <unistd.h>

ssize_t print_char(char c)
{
  return (write(1, &c, 1));
}

void my_printf(const char *str, ...) {
  va_list args;
  va_start(args, str);
  ssize_t len;

  len = 0;
  while (*str != 0) {
    if (*str == '%') {
        str++;
        // TODO
    }
    else
        len += print_char(*str);
    str++;
  }
  va_end(args);
}

int main() {
    my_printf("Hello, %s! You have new messages.\n", "Alice");
    return 0;
}
