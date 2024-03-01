#include "output.h"

// Function for outputting matrix as file (csv formatting)
void output(rarray<double,2> V, const std::string filename){

    // Initialize output file under filename
    std::ofstream out(filename);

    // If the file is open, raise error
    if (!out.is_open()) {
        std::cerr << "Error: " << filename << "is already open, and cannot be used for writing." << std::endl;
        return;
    }

    // Get matrix size
    int N = V.extent(1);

    //Iterate through all points, export to out separated by commas
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < N; m++) {

            out << V[n][m];

            if (m < N - 1) {
                out << ",";
            }
        }
        out << "\n"; // Start a new line after each row
    }

    // Close file
    out.close();
}