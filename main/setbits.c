#include <libc.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask;
	unsigned shifted_bits;
	
	mask = ~(((1 << n) - 1) << (p + 1 - n));
    x = x & mask;
	shifted_bits = (y & ((1 << n) - 1)) << (p + 1 - n);
    return (x | shifted_bits);
}
int main()
{
	unsigned x = 0b10101010;
	int p = 4;
	int n = 3;
	unsigned y = 0b11110000;
	printf("%u", setbits(x, p, n, y));
}