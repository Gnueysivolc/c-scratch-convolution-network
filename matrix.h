#pragma once

#include <vector>

class matrix {
private:
    int rows;
    int cols;
    float initial_value;
    std::vector<std::vector<float>> mat;

public:
    // Constructor
    matrix(int rows, int cols, float initial_value = 0.0);

    // Method to add two matrices
    matrix add(const matrix& other) const;

    void print() const;

    // Other methods you want to add (e.g. multiply, transpose, etc.)
};