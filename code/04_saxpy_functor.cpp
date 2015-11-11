#include <cstdlib>
#include <vector>

#include "utils.hpp"


struct SaxpyFunctor {
    SaxpyFunctor(float a) : _a(a) { }

    float operator()(const float &x, const float &y) const {
        return _a * x + y;
    }

    const float _a;
};


int main(int argc, char *argv[])
{
    // ---- DECLARE / INITIALIZE VECTORS ----------------
    float a = 10.5;
    std::vector<float> vec_x(100, 1.0);
    std::vector<float> vec_y(100, 2.0);
    std::vector<float> vec_r(100);

    // ---- PERFORM COMPUTATION -------------------------
    SaxpyFunctor saxpy(a);
    for (size_t i = 0; i < vec_x.size(); i++) {
        vec_r[i] = saxpy(vec_x[i], vec_y[i]);
    }

    // ---- DO SOMETHING WITH THE DATA -----
    print_vector(vec_r);

    return 0;
}

