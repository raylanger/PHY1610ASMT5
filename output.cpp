#include "output.h"

void output(rarray<double,2> V, const std::string filename){

    std::ofstream out(filename);

    if (!out.is_open()) {
        std::cerr << "Error: " << filename << "is already open, and cannot be used for writing." << std::endl;
        return;
    }

    int N = V.extent(1);
    
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < N; m++) {

            out << V[n][m];

            if (m < N - 1) {
                out << ",";
            }
        }
        out << "\n"; // Start a new line after each row
    }

    out.close();
}