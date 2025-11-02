#ifndef IO_H
#define IO_H

#include <unistd.h>

int io_put_char(char c);
int io_put_str(char *str);
int io_put_nchar(char *str, int n);
int io_put_nb(int nb);
int io_put_nb_base(int nb, char *base);

#endif // IO_H
