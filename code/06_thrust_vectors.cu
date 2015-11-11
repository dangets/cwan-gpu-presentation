#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

int main(int argc, char *argv[]) {
    // thrust provides host_vector & device_vector containers
    thrust::host_vector<float> h_vec(1024);
    thrust::device_vector<float> d_vec;

    // copy from host to device (overridden equals operator)
    d_vec = h_vec;

    // copy from device to host
    h_vec = d_vec;


    // other....
    thrust::host_vector<float> h1(1024);
    thrust::device_vector<float> d1;
    thrust::device_vector<float> d2(h1);    // instantiate and copy in one step
    thrust::device_vector<float> d3(h1.begin(), h1.begin()+5);

    // remember vector memory will resize on demand
    d1 = h1;
    h1 = d1;
    d1 = d2;

    // access individial elements from device vector
    std::cout << d1[4] << std::endl;

    return 0;
}

