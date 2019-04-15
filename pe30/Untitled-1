#include <iostream>
#include <vector>
#include <cmath>

int lengthOfCycle(int denom)
{
    int rem = 1;
    std::vector<bool> rems(denom, false);
    rems[0] = true;
    int length = 0;
    while (true)
    {
        rem %= denom;
        if (rems[rem])
            break;
        rems[rem] = true;
        rem *= 10;
        length++;
    }
    return length;
}
int main(int argc, char const *argv[])
{
    int maxLen = 0;
    int maxPos = 0;
    int limit = 1000;
    int tmpLen = 0;
    for (int i = 1; i < limit; ++i)
    {
        tmpLen = lengthOfCycle(i);
        if (tmpLen > maxLen)
        {
            maxPos = i;
            maxLen = tmpLen;
        }
    }

    std::cout << "Solution to PE 26: " << maxPos << std::endl;
    return 0;
}
