#pragma once

#include <vector>

class matrix {
protected:
    int rows;
    int cols;
    float initial_value;
    std::vector<std::vector<float>> mat;

public:
    // Constructor
    matrix(int rows, int cols, float initial_value = 0.0);

    // modify and change matrix
    void change(const std::vector<std::vector<float>>& new_elements);
    
    void modify(int row, int col, float new_value);

    void rotate180(); 

    // Method to add two matrices
    matrix add(const matrix& other) const;

    matrix addPadding(const matrix & other, int padding_size = 0, bool odd = false) const; 

    matrix convolution_process(const matrix & other, int stride = 1) const;

    matrix convolution(const matrix& other, std::string padding = "valid", int stride = 1); //const, need to nodify the mat, rotate 180 degree

    //making activation function (pooling layer), which should not really exist in the matrix class, but anyway

    void relu() ;

    matrix pooling(int output_size, std::string type) const; //type can be "max" or "average", output_size have to be factor of original size

    void print() const;

    matrix multiply(const matrix& other) const;

    // Other methods you want to add (e.g. multiply, transpose, etc.)
};