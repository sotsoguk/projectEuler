#include <iostream>
#include <vector>
// project euler sum of 2^100
using namespace std;
int main(int argc, char *argv[]) {
	vector<char> digits(302,0);
	int power = 1000;
	digits.at(0) = 1;
	for (int i=1;i<=1000;i++){
		bool carry = false;
		for (int j=0;j<digits.size();j++){
			char tmp = digits.at(j) * 2;
			if (carry){
				tmp += 1;
				carry = false;
			}
			if (tmp >9){
				tmp %= 10;
				carry = true;
			}
			digits.at(j) = tmp;
		}
	}
	long sum = 0;
	for (int i=digits.size()-1;i>=0;i--){
		cout << int(digits.at(i));
		sum += int(digits.at(i));
		
	}
	cout <<endl<<sum<<endl;
}