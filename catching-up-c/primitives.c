#include "primitives.h"
#include <stdlib.h>

int rand_int(int from, int to)
{
	return rand() % (to - from) + from;
}

float rand_float(float from, float to)
{
	float rand_element = ((float)rand() / RAND_MAX); // This is from [0,1)
	return rand_element * (to - from) + from;
}

unsigned char rand_byte()
{
	return (unsigned char)(rand() % 256);
}

char rand_character()
{
	const readable_begin = 0x20;
	const readable_end = 0x7e;
	return (char)(rand() % (readable_end - readable_begin + 1) + readable_begin);
}
