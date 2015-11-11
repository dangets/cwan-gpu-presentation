#ifndef UTILS_HPP_CLUVP3EQ
#define UTILS_HPP_CLUVP3EQ

#include <iostream>
#include <vector>

template<typename T>
void print_vector(const std::vector<T> & vec) {
    auto it = vec.begin();
    if (it != vec.end()) {
        std::cout << *it;
        it++;
    }
    while (it != vec.end()) {
        std::cout << ", " << *it;
        it++;
    }
    std::cout << std::endl;
}


#endif /* end of include guard: UTILS_HPP_CLUVP3EQ */
