#include <queue>
#include <memory>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "grid.h"
#include "pos.h"

#define PAPER_ROLL '@'
#define PAPER_ROLL_REMOVED 'x'

void printGrid(const Grid& grid) {
    // Allocate temporary buffer: grid.width * grid.height + grid.height (newlines '\n')
    size_t total = (size_t)grid.width * grid.height + grid.height;
    std::unique_ptr<char[]> buffer = std::make_unique<char[]>(total);
    if (!buffer) return;

    char* p = buffer.get(); // pointer to the memcpy destination
    for (int row = 0; row < grid.height; ++row) {
        memcpy(p, grid[row], grid.width);
        p += grid.width;
        *p++ = '\n';
    }
    fwrite(buffer.get(), 1, total, stdout);
}

bool is_roll_accessible(int row, int col, const Grid& g) {
    int adjacent_rolls = 0;

    for (int i = 0; i < NEIGHBORS.NUM_ELEM; ++i) {
        int row_neighbor = row + NEIGHBORS.x[i];
        if (row_neighbor < 0 || row_neighbor >= g.height) continue;

        int col_neighbor = col + NEIGHBORS.y[i];
        if (col_neighbor < 0 || col_neighbor >= g.width) continue;

        if (g[row_neighbor][col_neighbor] == PAPER_ROLL) ++adjacent_rolls;
    }

    return adjacent_rolls < 4;
}

int solve1(const Grid& g) {
    int accessible = 0;
    for (int row = 0; row < g.height; ++row) {
        for (int col = 0; col < g.width; ++col) {
            if (g[row][col] != PAPER_ROLL) continue;
            if (is_roll_accessible(row, col, g)) ++accessible;
        }
    }

    return accessible;
}

void add_accessible_rolls_to_queue(Grid& g, std::queue<Pos>& q) {
    for (int row = 0; row < g.height; ++row) {
        for (int col = 0; col < g.width; ++col) {
            if (g[row][col] != PAPER_ROLL) continue;
            if (is_roll_accessible(row, col, g)) {
                q.push({row, col});
            }
        }
    }
}

void add_accessible_neighbors_to_queue(int row, int col, Grid& g, std::queue<Pos>& q) {
    for (int i = 0; i < NEIGHBORS.NUM_ELEM; ++i) {
        int neighbor_row = row + NEIGHBORS.y[i];
        if (neighbor_row < 0 || neighbor_row >= g.height) continue;

        int neighbor_col = col + NEIGHBORS.x[i];
        if (neighbor_col < 0 || neighbor_col >= g.width) continue;

        if (is_roll_accessible(neighbor_row, neighbor_col, g)) {
            q.push({neighbor_row, neighbor_col});
        }
    }
}

/**
 * BFS style removal
 *
 * 1. Find all accessable rolls
 * 2. Store them in queue q
 *
 * Until queue is not empty:
 * 1. Take roll (position) from queue
 * 2. Check if roll at this positon has already been removed
 * 3. Remove roll from grid
 * 4. Check if surrounding rolls are now accessible. If yes -> add them to the queue
 */
int solve2(Grid& g) {
    int removed_rolls = 0;
    std::queue<Pos> q;
    // Find all accessible queues
    add_accessible_rolls_to_queue(g, q);

    while (!q.empty()) {
        Pos pos = q.front();
        q.pop(); // only removes and does not return??? Thank you C++

        if (g[pos.row][pos.col] != PAPER_ROLL) continue; // roll has already been removed
        g[pos.row][pos.col] = PAPER_ROLL_REMOVED;
        ++removed_rolls;
        add_accessible_neighbors_to_queue(pos.row, pos.col, g, q);

    }
    return removed_rolls;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("error: usage: executable <input-file>. e.g. main input.txt\n");
        return EXIT_FAILURE;
    }

    Grid grid = read_grid(argv[1]);

    int part1_solution = solve1(grid);
    printf("Part 1 Solution: %d\n", part1_solution);
    int part2_solution = solve2(grid);
    printf("Part 1 Solution: %d\n", part2_solution);

    free(grid.data);

    return EXIT_SUCCESS;
}
