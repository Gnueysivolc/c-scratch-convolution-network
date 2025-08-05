#include "preprocessing.h"
#include "matrix.h"
#include "run.h"




void just_preprocess(){
    read_and_process(300);
}

void just_build_matrix(){
    matrix a(2, 2, 1.0);
    matrix b(2, 2, 2.0);
    matrix c = a.add(b);
    c.print();
    
}