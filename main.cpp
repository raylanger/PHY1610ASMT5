#include "init.h"
#include "iterate.h"
#include "output.h"

int main(int argc, char* argv[]){

    double epsilon = 1e-6;
    int N = 500;
    std::string filename = "Laplace.csv";
    try {
        if (argc > 1) N = std::stoi(argv[1]);
        if (argc > 2) epsilon = std::stod(argv[2]);
    }
    catch(...){

        return 1;
    }

    rarray<double,2> old_V = init_matrix(N);

    bool converged = false;
    int iter = 0;

    while(!converged){
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
            std::cout<<"Convergence!"<<"\n";
            converged = true;
        }

        old_V = new_V.copy();
        iter += 1;
    }

    output(old_V, filename);
    return 0;
    // if (converged){
    //     std::cout << "Method converged" << "\n";
    //     output(old_V, filename);
    //     return 0;
    // }
    // else{

    //     std::cout << "Method did not converge" << "\n";
    //     return 1;
    // }
}