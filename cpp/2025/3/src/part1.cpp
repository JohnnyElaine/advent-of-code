#include <stdint.h>
#include "part1.h"
#include "conversion.h"
#include "ioconstants.h"

static int8_t get_max_joltage(char *bank, int num_jolts) {
    int8_t max_left = 0;
    int8_t max_right = 0;

    //int index_max_left = 0;
    //int index_max_right = 0;
    for (int i = 0; i < num_jolts; i++) {
        if (max_left == 9 && max_right == 9) break;

        int8_t cur = char_to_digit(bank[i]);

        // max_left cannot be at the end of the string
        if (i < num_jolts - 1 && cur > max_left) {
            max_left = cur;
            max_right = 0;
            continue; // we cannot update both maxima in the same iteration
        }

        if (cur > max_right) {
            max_right = cur;
        }
    }
    return max_left * 10 + max_right;
}

int solve1(FILE *fptr, int num_digits_line) {
    int sum = 0;
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fptr)) {
        sum += get_max_joltage(line, num_digits_line);
    }
    return sum;
}
