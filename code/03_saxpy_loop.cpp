#include <iostream>
#include <vector>

#include "utils.hpp"


int main(int argc, char *argv[]) {
    // ---- DECLARE / INITIALIZE VECTORS ----------------
    float a = 10.5;
    std::vector<float> vec_x(100, 1.0);
    std::vector<float> vec_y(100, 2.0);
    std::vector<float> vec_r(100);

    // ---- PERFORM COMPUTATION -------------------------
    for (size_t i = 0; i < vec_x.size(); i++) {
        vec_r[i] = a * vec_x[i] + vec_y[i];
    }

    // ---- DO SOMETHING WITH THE DATA -----
    print_vector(vec_r);

    return 0;
}


