#include <iostream>
#include <vector>

using namespace std;
int64_t numZeros(int64_t num)
{
	return num / 5;
}

int numPrimes(int64_t num, int prime){
	int numP = 0;
	if (num<2)
		return 0;
	while (num % prime == 0)
	{
		num /= prime;
		numP++;
	}
	return numP;
}
int main(int argc, char *argv[]) {
	// compute
	
	int64_t minZeros = 12;
	int64_t n = 2000;
	int64_t numSolutions = 0;
	int64_t nZeros = numZeros(n);
	//cout << numPrimes(17, 2);
	vector<int> num2(n+1,0);
	vector<int> num5(n+1,0);
	vector<int> num2f(n+1,0);
	vector<int> num5f(n+1,0);
	for (int64_t i=0; i<=n;++i){
		num2[i] = numPrimes(i, 2);
		num5[i] = numPrimes(i, 5);
	}
	for (int64_t i=1;i<= n;++i){
		num2f[i] = num2f[i-1]+ num2[i];
		num5f[i] = num5f[i-1]+ num5[i];
	}
	
	//int64_t numSolutions = 0;
	int divs = 6;
	int n2 = num2f[n];
	int n5 = num5f[n];
	cout <<n2<<","<<n5<<endl;
	for (int64_t i=0;i<=n; i++){
		for (int64_t j=0;j<=n-i;++j){
			int64_t k = n-i-j;
			int twos = n2 - num2f[i] -num2f[j] - num2f[k];
			int fives = n5 - num5f[i] -num5f[j] - num5f[k]; 
			if (twos >= divs && fives >= divs)
				numSolutions++;
		}
	}
	cout << "Compare 763959"<<endl;
	cout << numSolutions <<endl;
//	for (int i=0;i<=n;i++){
//		cout <<i <<":"<<num2[i]<<","<<num2f[i]<<"    "<<num5[i]<<","<<num5f[i]<<endl;
//	}
//	cout << nZeros<<endl;
//	
//	for (int64_t i = 1; i <= n; i += 1)
//	{
//		for (int64_t j = 1; j <= n-i; j += 1){
//			int64_t k = n-j-i;
//			int64_t tmp = nZeros - numZeros(i) - numZeros(j) - numZeros(k);
//			if (tmp >= minZeros){
//				cout << i <<","<<j<<","<<k<<endl;
//			
//				numSolutions ++;
//			}
//		}
//	}
//	cout << "Number of Solutions: " << numSolutions <<endl;
}