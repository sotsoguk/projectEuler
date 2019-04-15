#include <iostream>
#include <vector>
#include <cmath>



int main(int argc, char const *argv[])
{
    int64_t limit = 354294;
    std::vector<int64_t> pows(10,0);
    for (int i=1;i<=9;++i)
        pows[i] = pow(i,5);
    // for (auto &i:pows)
    //     std::cout<<i<<std::endl;
    int64_t sum = 0;

    for (int64_t i=10;i<=limit;++i){
        int64_t powsum = 0;
        int64_t num = i;
        while (num){
            int digit = num % 10;
            powsum += pows[digit];
            // powsum += pow(digit,5);
            num /= 10; 
        }
        if (powsum == i)
            sum+=i;

    }

    std::cout << "Solution to PE 30: " << sum << std::endl;
    return 0;
}
