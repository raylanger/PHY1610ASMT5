#include "iterate.h"

rarray<double,2> iterate(rarray<double,2> V){

    int N = V.extent(1);
    rarray<double,2> newV(N,N);

    double dx = 2/(N-1);

    int bot_n, left_n, top_n, right_n;
    bot_n = left_n = std::ceil(0.9/dx);
    top_n = right_n = std::floor(1.1/dx);

    for (int n = 1; n < N-1; n++){
        for (int m = 1; m < N-1; m ++){
            if ((n < bot_n || n > top_n) && (m < left_n || m > right_n)){
                newV[n][m] = (V[n-1][m]+V[n+1][m]+V[n][m-1]+V[n][m+1])/4;
            }
        }
    }

    return newV;
}