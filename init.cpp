#include "init.h"

// Function for creating initial matrix of size n
rarray<double,2> init_matrix(int N){
    
    // Initialize N x N matrix
    rarray<double, 2> V(N,N);

    // Fill matrix with zeros
    V.fill(0.0);

    //Determine spatial discretization length
    double dx = 2.0/(N-1);

    // Determine indices corresponding to inner boundary (e.g. -0.1 and 0.1)
    int bot_n, left_n, top_n, right_n;
    bot_n = left_n = std::ceil(0.9/dx);
    top_n = right_n = std::floor(1.1/dx);

    // Iterate through indices within inner boundary - set to 1
    for (int n = bot_n; n <= top_n; n ++){
        for (int m = left_n; m <= right_n; m ++){
            V[n][m] = 1.0;
        }
    }

    // Return result
    return V;
}