#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> bigNum;

bigNum bigFactorial(int maxNum)
{
	// bigNum result = {1};
	// result.reserve(3000);
	bigNum result = bigNum(200,0);
	result[0] = 1;
	for (int i = 2; i <= maxNum; i++)
	{
		int carry = 0;
		for (auto &d : result)
		{
			d = d * i + carry;
			if (d >= 10)
			{
				carry = d / 10;
				d %= 10;
			}
			else
			{
				carry = 0;
			}
		}
		while (carry > 0)
		{
			result.push_back(carry % 10);
			carry /= 10;
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	bigNum test = bigFactorial(1000);
	//for (auto i=test.rbegin();i != test.rend();i++)
	//	std::cout << *i;
	int64_t sum = 0;
	for (auto &d : test)
		sum += d;
	std::cout << sum << endl;
}