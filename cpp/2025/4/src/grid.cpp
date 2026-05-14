#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "grid.h"

// puzzle input line = 135 characters
#define BUFFER_SIZE 256

Grid read_grid(char* filename) {
    Grid grid = {0};

    FILE *fptr = fopen(filename, "r");
    if (!fptr) return grid;
    char line[BUFFER_SIZE];

    // read first row to get the length (dimensions of grid, height = width)
    if (!fgets(line, BUFFER_SIZE, fptr)) {
        fclose(fptr);
        return grid;
    }

    size_t line_len = strlen(line);
    // remove \r\n from line
    if (line_len > 0 && line[line_len-1] == '\n') {
            line[--line_len] = '\0';
    }
    if (line_len > 0 && line[line_len-1] == '\r') {
            line[--line_len] = '\0';
    }

    grid.height = line_len;
    grid.width = line_len;
    grid.data = (char*) malloc(grid.width * grid.height * sizeof(char));
    if (!grid.data) {
        fclose(fptr);
        return grid;
    }

    size_t line_cpy_size = grid.width * sizeof(char);
    memcpy(grid.data, line, line_cpy_size);

    for (int row = 1; fgets(line, BUFFER_SIZE, fptr); ++row) {
        memcpy(grid.data + row * grid.width , line, line_cpy_size); // do not copy \r\n
    }

    fclose(fptr);

    return grid;
}

void free_grid(Grid& grid) {
    free(grid.data);
    grid.data = nullptr;
    grid.height = grid.width = 0;
}
