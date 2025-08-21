#include "preprocessing.h"
#include "matrix.h"
#include "run.h"




void just_preprocess(){
    read_and_process(300);
}

void just_build_matrix() {
    matrix a(5, 5, 0.0);
    matrix b(2, 2, 0.0);

    std::vector<std::vector<float>> a_data = {
        {2, -1, 43,12, -9},
        {23, 5, 6,3,4},
        {7, 8, 9,0,1},
        {14, 34, 90,0,1},
        {-2, -5, 3,0,1}
    };
    std::vector<std::vector<float>> b_data = {
        {9, 2},
        {9, 2}
    };

    a.change(a_data);
    b.change(b_data);

    std::cout << "matrix a" << std::endl;
    a.print();
    std::cout << "matrix b" << std::endl;
    b.print();
    matrix c = b.convolution(a, "correlation", 1);
    c.print();
}

void rotate_matrix(){

    matrix a(5, 5, 0.0);
    matrix b(2, 2, 0.0);

    std::vector<std::vector<float>> a_data = {
        {2, -1, 43,12, -9},
        {23, 5, 6,3,4},
        {7, 8, 9,0,1},
        {14, 34, 90,0,1},
        {-2, -5, 3,0,1}
    };
    std::vector<std::vector<float>> b_data = {
        {3, 2},
        {9, -1}
    };

    a.change(a_data);
    b.change(b_data);

    matrix  c = b.convolution(a, "full", 1);
    b.print();
    c.print();

    

}










