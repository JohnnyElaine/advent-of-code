#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <set>

/**
 * @brief Returns all proper divisors of n (excluding n itself).
 *
 * A proper divisor d of n satisfies: d < n and n % d == 0.
 * Always includes 1, even if n = 1. Returns {1} for prime numbers.
 *
 * @param n The positive integer to factorize (n >= 1)
 * @return std::set<int> Sorted set of proper divisors in ascending order
 *
 * @note Time complexity: O(√n)
 * @note For n=1, returns empty set (1 has no proper divisors)
 *
 * @example
 * get_all_divisors_exclusive(12) → {1, 2, 3, 4, 6}
 * get_all_divisors_exclusive(11) → {1}
 * get_all_divisors_exclusive(1)  → {1}
 */
std::set<int> get_all_divisors_exclusive(int n);

#endif
