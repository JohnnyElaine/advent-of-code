#ifndef ID_VALIDATOR_H
#define ID_VALIDATOR_H

#include <fstream>

#define DELIMITER_PUZZLE_INPUT ','

class IdValidator
{
public:
    virtual ~IdValidator() = default;
    /**
     * @brief Reads product ID ranges from a file stream and sums all invalid IDs found within them.
     * @param filestream A reference to an opened std::ifstream. The stream must be in a good state
     *                   and positioned at the beginning of the data. The function reads until EOF
     *                   and modifies the stream's read position.
     *
     * @return The sum of all invalid IDs found across all ranges in the input.
     *
     * @note use long for ids and id sums to avoid overflow
     */
    long solve(std::ifstream& filestream) const;

protected:
    virtual bool is_valid(long id) const = 0;

private:
    long sum_invalid_ids(long start, long end) const;
};

// Sub-Classes of IdValidator (1 for each part)
class IdValidatorPart1 : public IdValidator
{
protected:
    bool is_valid(long id) const override;
};

class IdValidatorPart2 : public IdValidator
{
protected:
    bool is_valid(long id) const override;
};

#endif
