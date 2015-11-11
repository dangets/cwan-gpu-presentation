#include <algorithm>
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


int main(int argc, char *argv[]) {
    // ---- DECLARE / INITIALIZE VECTORS ----------------
    float a = 10.5;
    std::vector<float> vec_x(100, 1.0);
    std::vector<float> vec_y(100, 2.0);
    std::vector<float> vec_r(100);

    // ---- PERFORM COMPUTATION -------------------------
    SaxpyFunctor saxpy(a);
    std::transform(
            vec_x.begin(), vec_x.end(),     // src1_begin, src1_end
            vec_y.begin(),                  // src2_begin
            vec_r.begin(),                  // dst_begin
            saxpy);                         // binaryFn

    print_vector(vec_r);

    return 0;
}

