#include <iostream>
#include <vector>
#include <string>

int64_t factorial(int64_t fac)
{
    int64_t result = 1;
    for (int64_t i = 1; i <= fac; ++i)
        result *= i;
    return result;
}
int main(int argc, char const *argv[])
{
    int64_t pos = 1;
    int64_t limit = 1000000;
    std::vector<unsigned int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // std::string solution = "";
    int64_t solution = 0;
    for (int i = 9; i >= 0; --i)
    {
        int64_t incr = factorial(i);
        int64_t t = (limit - pos) / incr;
        pos += incr * t;
        unsigned int digit = nums[t];
        nums.erase(nums.begin() + t);
        //solution += std::to_string(digit);
        solution *= 10;
        solution += digit;
    }
    std::cout << " Solution to PE 24: " << solution << std::endl;
}
