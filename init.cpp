#include "init.h"

rarray<double,2> init_matrix(int N){
    rarray<double, 2> space(N,N);

    space.fill(0.0);

    double dx = 2.0/(N-1);

    int bot_n, left_n, top_n, right_n;
    bot_n = left_n = std::ceil(0.9/dx);
    top_n = right_n = std::floor(1.1/dx);

    for (int n = bot_n; n <= top_n; n ++){
        for (int m = left_n; m <= right_n; m ++){
            space[n][m] = 1.0;
        }
    }

    return space;
}