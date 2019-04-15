#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    int limit = 1000;
    double_t phi = 0.5 + 0.5 * sqrt(5);
    int sol = int(ceil((limit - 1 + 0.5 * log10(5)) / log10(phi)));
    std::cout << "Solution to PE 25: " <<sol << std::endl;
    return 0;
}
