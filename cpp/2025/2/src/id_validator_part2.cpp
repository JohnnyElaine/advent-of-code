#include <cmath>
#include "id_utils.h"
#include "id_validator.h"
#include "math_utils.h"

long create_repeating_id(long section, int length, int reps)
{
    long sum = 0;
    for (int i = 0; i < reps; i++)
    {
        sum *= static_cast<int>(std::pow(10, length));
        sum += section;
    }
    return sum;
}

bool IdValidatorPart2::is_valid(long id) const
{
    if (id < 10) return true;

    int n = num_of_digits(id);
    std::set<int> section_lengths = get_all_divisors_exclusive(n);

    for (int section_length : section_lengths)
    {
        int section = id % static_cast<int>(std::pow(10, section_length));
        int reps = n / section_length;
        long repeating_id = create_repeating_id(section, section_length, reps);

        if (repeating_id == id)return false;
    }

    return true;
}
