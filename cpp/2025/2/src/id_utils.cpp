#include <cstdlib>
#include <cmath>
#include <charconv>
#include <string>

int num_of_digits(long num)
{
    if (num == 0) return 1;
    num = std::labs(num);

    return static_cast<int>(std::log10(num)) + 1;
}

std::pair<long, long> parse_pair(const std::string& str)
{
    long a, b;
    const char* end = str.data() + str.size();

    std::from_chars_result result = std::from_chars(str.data(), end, a);
    std::from_chars(result.ptr + 1, end, b);

    return {a, b};
}
