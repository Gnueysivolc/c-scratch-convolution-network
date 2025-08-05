#include <iostream>
#include <vector>
#include "matrix.h"







    // initialize varibles
    matrix::matrix(int rows, int cols, float initial_value) : rows(rows), cols(cols), initial_value(initial_value), mat(rows, std::vector<float>(cols, initial_value)){};



    // add function of same size matrix
    matrix matrix::add(const matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices are not the same size");
    }

    matrix result(rows, cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
        }
     }
     return result;
    };



    // print matrix
    void matrix::print() const{

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
;

