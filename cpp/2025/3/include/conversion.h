#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdint.h>

/**
 * Convert a character digit to its integer value
 * @param c Character digit ('0' through '9')
 * @return Integer value (0-9), or negative value if out of range
 * @note No validation is performed - ensure c is a digit before calling
 */
int8_t char_to_digit(char c);

#endif
