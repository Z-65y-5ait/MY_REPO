#include <libc.h>

unsigned rightrot(unsigned x, int n)
{
	int total_bits;
	unsigned right_part;
	unsigned left_part;

	total_bits = sizeof(x) * 8;
    n %= total_bits;
	right_part = x >> n;
	left_part = x << (total_bits - n);
    return right_part | left_part;
}

int main()
{
	unsigned x = 0b10101010;
	int n = 3;
	printf("%u\n", rightrot(x, n));
	printf("%zu", sizeof(unsigned));
}