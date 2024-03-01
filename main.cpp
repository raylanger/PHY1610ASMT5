#include "init.h"
#include "iterate.h"
#include "output.h"

int main(int argc, char* argv[]){

    // Set default parameters
    double epsilon = 1e-6;
    int N = 500;
    std::string filename = "Laplace.csv";

    //Update parameters if specified
    try {
        if (argc > 1) N = std::stoi(argv[1]);
        if (argc > 2) epsilon = std::stod(argv[2]);
        if (argc > 3) filename = argv[3];
    }
    catch(...){

        return 1;
    }

    // Initialize matrix
    rarray<double,2> old_V = init_matrix(N);

    // Set converged boolean
    bool converged = false;

    while(!converged){

        // Get new matrix
        rarray<double,2> new_V = iterate(old_V);

        //Determine maximum difference compared to old matrix
        double maxDiff = 0.0;
        for (int n = 0; n < N; n++){
            for (int m = 0; m < N; m++){
                double diff = std::abs(old_V[n][m] - new_V[n][m]);
                if (diff > maxDiff){
                    maxDiff = diff;
                }

            }
        }

        // If maxDiff less than threshold, set converged to true.
        if (maxDiff < epsilon){
            converged = true;
        }

        // Copy new_V to old_V
        old_V = new_V.copy();
    }

    // Output old_v to filename
    output(old_V, filename);
    return 0;
}