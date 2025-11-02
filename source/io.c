#include "io.h"

int io_put_char(char c) {
	int count;

	count = write(STDOUT_FILENO, &c, 1);
	return count;
}

int io_put_str(char *str) {
	int index;

	index = 0;
	while (str[index]) {
		io_put_char(str[index]);
		index++;
	}
	return index;
}

int io_put_nchar(char *str, int n) {
	int index;

	index = 0;
	while (str[index] && index < n) {
		io_put_char(str[index]);
		index++;
	}
	return index;
}

int _put_nb_rec(int nb) {
	int count;

	count = 1;
	if (nb >= 10)
		count += _put_nb_rec(nb / 10);
	io_put_char((nb % 10) + '0');
	return count;
}

int io_put_nb(int nb) {
	int count;
	long lnb;

	lnb = nb;
	count = 1;
	if (lnb < 0) {
		io_put_char('-');
		lnb = -lnb;
		count++;
	}
	if (lnb >= 10)
		count += _put_nb_rec(lnb / 10);
	io_put_char((lnb % 10) + '0');
	return count;
}

int _str_len(char *str) {
	int index;

	index = 0;
	while (str[index])
		index++;
	return index;
}

int _put_nb_base_rec(int nb, char *base, int b_val) {
	int count;

	count = 1;
	if (nb >= 10)
		count += _put_nb_base_rec(nb / b_val, base, b_val);
	io_put_char(base[nb % b_val]);
	return count;
}

int io_put_nb_base(int nb, char *base) {
	int count;
	long lnb;
	int b_val;

	lnb = nb;
	count = 1;
	b_val = _str_len(base);
	if (lnb < 0) {
		io_put_char('-');
		lnb = -lnb;
		count++;
	}
	if (lnb >= b_val)
		count += _put_nb_base_rec(lnb / b_val, base, b_val);
	io_put_char(base[lnb % b_val]);
	return count;
}
