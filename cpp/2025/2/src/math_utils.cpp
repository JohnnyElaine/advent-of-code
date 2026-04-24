#include <set>
#include <cmath>
#include "math_utils.h"

std::set<int> get_all_divisors_exclusive(int n)
{
    std::set<int> s = {1};
    int limit = static_cast<int>(std::sqrt(n));
    for(int i = 2; i <= limit; i++)
    {
        if (n % i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
    }
    return s;
}
