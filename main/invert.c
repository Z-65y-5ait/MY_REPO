#include <libc.h>

unsigned invert(unsigned x, int p, int n)
{
	unsigned s;

	s = ((1 << n) - 1) << (p + 1 - n);
	return (x ^ s);
}

int main()
{
	unsigned x = 0b10101010;
	int p = 4;
	int n = 3;
	unsigned y = 0b11110000;
	printf("%u", invert(x, p, n));
}