#ifndef POS_H
#define POS_H

struct Pos {
    int row;
    int col;

    bool operator==(const Pos& other) const {
        return row == other.row && col == other.col;
    }
};

struct AdjacentPos {
    int x[8];
    int y[8];
    int NUM_ELEM = 8;   // or use `static constexpr int SIZE = 8;`
};


constexpr AdjacentPos NEIGHBORS = {
    .x = { 1, -1, 0, 0, 1, 1, -1, -1 },
    .y = { 0, 0, 1, -1, 1, -1, 1, -1 }
};

#endif
