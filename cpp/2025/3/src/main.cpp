#include "part1.h"
#include "part2.h"
#include <cstdio>

#define NUM_DIGITS_PER_LINE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("error: usage: executable <input-file>. e.g. main input.txt\n");
        return -1;
    }

    FILE *input_fileptr = fopen(argv[1], "r");
    int solution1 = solve1(input_fileptr, NUM_DIGITS_PER_LINE);
    printf("part 1 solution: %d\n", solution1);

    // reset file ptr to start of file
    rewind(input_fileptr);

    long long solution2 = solve2(input_fileptr, NUM_DIGITS_PER_LINE);
    printf("part 2 solution: %lld\n", solution2);

    fclose(input_fileptr);
    return 0;
}
