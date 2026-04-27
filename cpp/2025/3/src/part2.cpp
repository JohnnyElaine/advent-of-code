#include <utility>
#include <stdint.h>
#include "part2.h"
#include "conversion.h"
#include "ioconstants.h"

#define NUM_BATTERIES_TO_SELECT 12

static std::pair<int8_t, int> get_first_occur_of_max_jolt(char *bank, int n) {
    int8_t max = 0;
    int index_max = 0;
    for (int i = 0; i < n; i++) {
        int8_t curr = char_to_digit(bank[i]);

        if (curr > max) {
            max = curr;
            index_max = i;
        }

        if (max == 9) break;
    }
    return {max, index_max};
}

static long long get_max_joltage(char *bank, int num_jolts) {
    int start_index = 0;
    long long max_joltage = 0;
    for (int i = 0; i < NUM_BATTERIES_TO_SELECT; i++) {
        int must_leave = NUM_BATTERIES_TO_SELECT - 1 - i; // num of jolts at the end of s that are skipped, becaue we need to read NUM_BATTERIES_TO_SELECT total jolts
        int jolts_to_read = num_jolts - start_index - must_leave;
        auto [jolt, jolt_index] = get_first_occur_of_max_jolt(bank + start_index, jolts_to_read);
        jolt_index += start_index;

        max_joltage = max_joltage * 10 + jolt;

        start_index = jolt_index + 1;
    }
    return max_joltage;
}

long long solve2(FILE *fptr, int num_jolts_per_line) {
    long long sum = 0;
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fptr)) {
        sum +=get_max_joltage(line, num_jolts_per_line);
    }
    return sum;
}
