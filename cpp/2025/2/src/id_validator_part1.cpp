#include <cmath>
#include "id_utils.h"
#include "id_validator.h"

bool IdValidatorPart1::is_valid(long id) const
{
    int length = num_of_digits(id);
    if (length % 2 != 0) return true;

    int section_divisor = static_cast<int>(std::pow(10, (length/2)));

    // split number into two parts
    long left = id / section_divisor;
    long right = id % section_divisor;

    if (left != right) return true;

    return false;
}
