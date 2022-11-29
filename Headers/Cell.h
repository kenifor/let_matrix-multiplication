#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <ostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

struct Cell {
    int x; // index of column
    int y; // index of row

public:
    Cell(int x = -1, int y = -1):
        x(x), y(y)
    { }

    friend std::ostream& operator<<(std::ostream& stream, const Cell& cell)
    {
        stream << "(" << cell.y << ", " << cell.x << ")";
        return stream;
    }
};


Cell getCell(const Matrix& matrix, int index)
{
    Cell cell;

    // empty matrix
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return cell;

    int width = matrix[0].size();
    int height = matrix.size();

    // index is out of range
    if (index >= width * height)
        return cell;

    cell.y = index / width; // row
    cell.x = index % width; // column

    return cell;
}

#endif // CELL_H
