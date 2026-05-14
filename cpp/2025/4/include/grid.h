#ifndef GRID_H
#define GRID_H

/**
 * 2D Grid (flat storage, row-major)
 */
struct Grid {
    char *data = nullptr;
    int height = 0;
    int width = 0;

    // Enable 2D array access: grid[row][col]
    char* operator[](int row) { return data + (row * width); }
    const char* operator[](int row) const { return data + (row * width); }
};

Grid read_grid(char* filename);

#endif
