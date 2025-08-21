#include <iostream>
#include <vector>
#include "matrix.h"







    // initialize varibles
    matrix::matrix(int rows, int cols, float initial_value) : rows(rows), cols(cols), initial_value(initial_value), mat(rows, std::vector<float>(cols, initial_value)){};


    //change and modify of matrix
    //change requires input of whole matrix by inputing vector in vector of same size
    void matrix::change(const std::vector<std::vector<float>>& new_elements) {
    if (new_elements.size() != rows || new_elements[0].size() != cols) {
        throw std::invalid_argument("New elements must have the same size as the original matrix");
    }

        mat = new_elements;
    }

    //modify requires user to input a  row and col, then the number to be changes to modify one number only
    void matrix::modify(int row, int col, float new_value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Row or column index out of range");
    }

        mat[row][col] = new_value;
    }


    // Function to rotate a matrix 180 degrees
    //which is equivalent to transpose 2 times of the matrix
    void matrix::rotate180() {
        for (auto& row : mat) {
            std::reverse(row.begin(), row.end());
        }

        std::reverse(mat.begin(), mat.end());

    };



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

    // mutiply two matrix together, a.mutiply(b) = a*b
    matrix matrix::multiply(const matrix& other) const {
        if ( cols != other.rows ){
            throw std::invalid_argument("Matrices cols and rows does not match, matrices cannot be mutiplied");
        }

        matrix result(rows, other.cols, 0);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < other.cols; col++){
                for(int i = 0; i < cols; i++){
                    result.mat[row][col] += mat[row][i] * other.mat[i][col];
                }
            }
        };

        return result;
    }

    matrix matrix::addPadding(const matrix & other, int padding_size, bool odd) const{ 
        int originalRows = other.rows;
        int originalCols = other.cols;
        int paddedRows = originalRows + 2 * padding_size;
        int paddedCols = originalCols + 2 * padding_size;
        
        if (odd){
            paddedRows += 1;
            paddedCols += 1;
            padding_size += 1;
        };

        matrix paddedMat(paddedRows, paddedCols, 0);

        std::cout << "padding size: " << padding_size << std::endl;

        for (int i = 0; i < originalRows; i++) {
            for (int j = 0; j < originalCols; j++) {
                paddedMat.mat[i + padding_size][j + padding_size] = other.mat[i][j];
            };
        };

        std::cout << "padded matrix: " << std::endl;

        return paddedMat;
    };


    // the dot product process of convolution
    matrix matrix::convolution_process(const matrix & other, int stride) const{
        int row = ((other.rows-rows) / stride) + 1;
        int col = ((other.cols-cols) / stride) + 1;
        matrix result(row, col, 0);
        for (int i = 0; i < row; i+=stride) {
            for (int j = 0; j < col; j+=stride) {
                for(int k = 0; k < rows; k++){
                    for(int l = 0; l < cols; l++){
                        result.mat[i][j] += mat[k][l] * other.mat[i+k][j+l];
                    }
                }
            }
        }
        return result;
    }


    // the matrix which call the function is the filter that slide over
    // the matrix "other" passed in function as parameter is the matrix not moving
    // padding = "full" to use full convolution, "valid" to be normal
    matrix matrix::convolution(const matrix& other, std::string padding, int stride) {
        
        if( ( other.rows - rows )%stride != 0){
            throw std::invalid_argument("stride number cant be used");
        };
       
        int enlargement_size = 0;
        int padding_size = 0;
        bool odd = false;

        if( padding == "valid"){
            padding_size = 0;
        }else if( padding == "same"){
            enlargement_size = other.rows*stride + rows - 1 - other.rows;

            std::cout<<"enlargement size: "<<enlargement_size/2<<std::endl;
            
            if (enlargement_size%2 != 0){
                odd = true;
            };

            padding_size = enlargement_size/2;

            
        }else if( padding == "correlation"){
            padding_size = rows-1;
            stride = 1;  // correlation convolution fix stride = 1
        }else if( padding == "full"){
            rotate180(); //rotate 180 degree of mat
            padding_size = rows-1;
            stride = 1;  // correlation convolution fix stride = 1
        }// else{ use padding number directly}
        ;

        std::cout<<"padding: "<<padding<<std::endl;

        matrix paddedMat = addPadding(other, padding_size, odd);

        std::cout<<"padding size: "<<padding_size<<std::endl;

        return convolution_process(paddedMat, stride);

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




