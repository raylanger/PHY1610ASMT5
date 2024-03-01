#include "iterate.h"

// Function for updating matrix
rarray<double,2> iterate(rarray<double,2> V){

    // Get matrix size
    int N = V.extent(1);

    // Initialize new matrix, fill with zeros
    rarray<double,2> newV(N,N);
    newV.fill(0.0);

    // Determine discretization length
    double dx = 2.0/(N-1);

    // Calculate indices corresponding to inner boundary
    int bot_n, left_n, top_n, right_n;
    bot_n = left_n = std::ceil(0.9/dx);
    top_n = right_n = std::floor(1.1/dx);

    // Iterate through each point, except points on outer boundary
    for (int n = 1; n < N-1; n++){
        for (int m = 1; m < N-1; m ++){
            if ((n < bot_n || n > top_n) || (m < left_n || m > right_n)){ // If point outside inner boundary, take average of neighbouring points
                double sum = V[n-1][m]+V[n+1][m]+V[n][m-1]+V[n][m+1];
                newV[n][m] = sum/4.0;
            }
            else{ //Otherwise, set equivalent to old matrix
                newV[n][m] = V[n][m];
            }
        }
    }

    // Return new matrix
    return newV;
}