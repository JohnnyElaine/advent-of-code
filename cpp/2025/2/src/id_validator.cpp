#include <fstream>
#include "id_utils.h"
#include "id_validator.h"

long IdValidator::sum_invalid_ids(long start, long end) const
{
    long sum = 0;
    for (long id = start; id <= end; id++)
    {
        if (is_valid(id)) continue;
        sum += id;
    }
    return sum;
}

long IdValidator::solve(std::ifstream& filestream) const
{
    long sum = 0;
    std::string token;
    while (std::getline(filestream, token, DELIMITER_PUZZLE_INPUT))
    {
        std::pair<long, long> product_id_range = parse_pair(token);
        sum += sum_invalid_ids(product_id_range.first, product_id_range.second);
    }
    return sum;
}
