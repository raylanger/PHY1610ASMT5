#include "init.h"
#include "iterate.h"

int main(int argc, char* argv[]){

    double epsilon = 1e-6;
    int N = 500;

    try {
        if (argc > 1) N = std::stoi(argv[1]);
        if (argc > 2) epsilon = std::stod(argv[2]);
    }
    catch(...){

        return 1;
    }
    rarray<double,2> old_V = init_matrix(N);
    
    int iter = 0;

    bool converged = false;
    while (iter < 10000){
        rarray<double,2> new_V = iterate(old_V);

        double maxDiff = 0.0;
        for (int n = 0; n < N; n++){
            for (int m = 0; m < N; m++){
                double diff = std::abs(old_V[n][m] - new_V[n][m]);
                if (diff > maxDiff){
                    maxDiff = diff;
                }
            }
        }

        if (maxDiff < epsilon){
            converged = true;
            break;
        }

        old_V = new_V;
    }

    if (converged){
        std::cout << "Method converged" << "\n";
    }
    return 0;
}