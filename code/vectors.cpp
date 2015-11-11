#include <vector>

int main(int argc, char *argv[])
{
    std::vector<float> v1;      // dynamically sized
    v1.push_back(1.0);
    v1.size();                  // stores size internally

    std::vector<float> v2(100, 1.0);

    std::vector<float> v3(v2);  // initialize from another vector (copy)

    std::vector<float> v4;
    v4 = v3;                    // overloaded equal for copy

    float f1 = v4[10];          // overloaded index operator (no bounds check)
    float f2 = v4.at(10);       // bounds checked indexing

    // contiguous memory allocation
    // *very* fast operations on the vector because of this
    // unlike Java does not store references to items

    return 0;
}
