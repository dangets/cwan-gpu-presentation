#include <algorithm>
#include <cstdlib>
#include <vector>

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/transform.h>


#include "utils.hpp"


struct SaxpyFunctor {
    SaxpyFunctor(float a) : _a(a) { }

    __host__ __device__
    float operator()(const float &x, const float &y) const {
        return _a * x + y;
    }

    const float _a;
};


int main(int argc, char *argv[]) {
    float a = 10.5;

    // ---- DECLARE / INITIALIZE HOST VECTORS -----------
    thrust::host_vector<float> host_x(100, 1.0);
    thrust::host_vector<float> host_y(100, 2.0);
    thrust::host_vector<float> host_r;

    // ---- DECLARE / INITIALIZE DEVICE VECTORS ---------
    thrust::device_vector<float> device_x(host_x);
    thrust::device_vector<float> device_y(host_y);
    thrust::device_vector<float> device_r;

    // ---- PERFORM COMPUTATION -------------------------
    SaxpyFunctor saxpy(a);
    thrust::transform(
            device_x.begin(), device_x.end(),   // src1_begin, src1_end
            device_y.begin(),                   // src2_begin
            device_r.begin(),                   // dst_begin
            saxpy);                             // binaryFn

    // ---- COPY RESULT DATA BACK TO HOST -----------
    host_r = device_r;

    // ---- DO SOMETHING WITH THE DATA --------------
    print_vector(host_r);

    return 0;
}

