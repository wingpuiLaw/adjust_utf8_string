#include <cstdio>

typedef __uint8_t U8;

//only for big endian string
U8 *cutTailofUnicodeinUtf8(U8 *source, U8 lenth)
{
	U8 *p = source, *pEnd = p + lenth;

	while (p != pEnd) {
		if (*p == 0) //nothing need to be changed
			return source;

		if (*p >= 0xF0) { //four charaters
			if (p += 4 < pEnd)
				continue;
			else {
				*(p-4) = 0;
				break;
			}
		}
		else if (*p >= 0xE0) { //three charaters
			if (p += 3 < pEnd)
				continue;
			else {
				*(p-3) = 0;
				break;
			}
		}
		else if (*p >= 0xC0) { //two charaters
			if (p += 2 < pEnd)
				continue;
			else {
				*(p-2) = 0;
				break;
			}
		}
		else if (*p < 0x80) { //one charater
			if (++p < pEnd)
				continue;
			else {
				*(--p) = 0;
				break;
			}
		} else { //error charater
			*p = 0;
			break;
		}
	}
	return source;
}
