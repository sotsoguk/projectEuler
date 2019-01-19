#include <iostream>
#include "bigInt.hpp"

using namespace std;
BigInt computeSqrt(int num, int acc = 101){
	BigInt a = 5*num;
	BigInt b = 5;
	while(b.to_string().length()<=acc){
		if (a >= b){
			a = a - b;
			b = b + 10;
		}
		else {
			a = 100 * a;
			b = 10*b - 45;
		}
	}
	return b;
}
int computeSumOfDigits(BigInt num, int len = 100){
	string numString = num.to_string();
	//cout <<"String:"<<numString<<endl;
	int sum = 0;
	for (int i=0;i < len;i++){
		sum += int(numString.at(i))-48;
		//cout <<i<<": "<< int(numString.at(i))-48<<endl;
	}
	return sum;
}
int main(int argc, char *argv[]) {
	int num = 2;
	long sumOfAll = 0;
	for (int i=2;i<100;i++){
		if (num*num == i){
			num ++;
			continue;
		}
		sumOfAll += computeSumOfDigits(computeSqrt(i,102));
		
	}
	cout <<sumOfAll<<endl;
//	int t = computeSumOfDigits(computeSqrt(2));
//	cout <<t<<endl;
}