#include <fstream>
#include <iostream>
#include <string>
#include <charconv>
#include <utility>
#include <cmath>
#include <cstdlib>

#define DELIMITER_PUZZLE_INPUT ','

std::string *read_input_as_whole_file(char *filename)
{
	std::ifstream is(filename);
	if (!is) throw std::runtime_error("Failed to open puzzle input file");

	std::string *whole_file = new std::string;
	is.seekg(0, std::ios::end);
	whole_file->reserve(is.tellg());
	is.seekg(0, std::ios::beg);
	whole_file->assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());

	return whole_file;
}

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

bool is_id_valid(long id)
{
	int length = num_of_digits(id);
	if (length % 2 != 0) return true;

	int half_length_powers_of_ten = static_cast<int>(std::pow(10, (length/2)));

	// split number into two parts
	long left = id / half_length_powers_of_ten;
	long right = id % half_length_powers_of_ten;

	if (left != right) return true;

	return false;
}

long sum_invalid_ids(long start, long end)
{
	long sum = 0;
	for (long id = start; id <= end; id++)
	{
		if (is_id_valid(id)) continue;
		sum += id;
	}
	return sum;
}


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
long solve_part_1(std::ifstream& filestream)
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

long solve_part_2(char *filename) { return 0; }

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	std::ifstream filestream(filename);

	long solution1 = solve_part_1(filestream);

	// reset filestream to start of file
	filestream.clear();
	filestream.seekg(0, std::ios::beg);

	long solution2 = solve_part_2(filename);
	std::cout << "Part 1: " << solution1 << "\n";
	std::cout << "Part 2: " << solution2 << std::endl;

  return 0;
}
