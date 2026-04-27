#include <fstream>
#include <iostream>

#include "id_validator.h"

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cout << "error: usage: executable <input-file>" << std::endl;
        return -1;
    }

	char *filename = argv[1];
	std::ifstream filestream(filename);

	IdValidatorPart1 part1Validator;
	IdValidatorPart2 part2Validator;

	long solution1 = part1Validator.solve(filestream);
	std::cout << "Part 1: " << solution1 << "\n";

	// reset filestream to start of file
	filestream.clear();
	filestream.seekg(0, std::ios::beg);

	long solution2 = part2Validator.solve(filestream);
	std::cout << "Part 2: " << solution2 << std::endl;

	return 0;
}
