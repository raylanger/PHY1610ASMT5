#include "init.h"
int main(int argc, char* argv[]){


    int N = 500;

    try {
        if (argc > 1) N = std::stoi(argv[1]);
    }
    catch(...){

        return 1;
    }
    init_matrix(N);
    return 0;
}