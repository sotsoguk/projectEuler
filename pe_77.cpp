#include <iostream>
#include <vector>
#include <math.h>
//pe 77

using namespace std;

int getNextPrime(vector<bool> &sieve, int prime) {
	if (prime <2 or prime >= sieve.size())
		return -1;
	int nextPrime = prime + 1;
	while (nextPrime < sieve.size() && !sieve.at(nextPrime))
		nextPrime++;
	//cout << "NP"<<nextPrime;
	return nextPrime;
}
void printPrimes(vector<bool> &sieve){
	for (int i=0;i<sieve.size();i++){
		if (sieve.at(i))
			cout << i<<"\t";
	}
	cout<<endl;
}

void generateSieve (vector<bool> &sieve){
	sieve.at(0) = false;
	sieve.at(1) = false;
	int maxPrime = sieve.size() - 1;
	int upToPrime = sqrt(maxPrime);
	int prime = 2;
	while (prime <= upToPrime){
		int curr = prime*prime;
		while (curr <= maxPrime) {
			sieve.at(curr) = false;
			curr += prime;
		}
//		cout <<prime<<": ";
//		printPrimes(sieve);
//		cout <<endl;
		prime = getNextPrime(sieve,prime);
	}
}

void genPrimeNumbers(vector<int> &primes, int maxNum){
	vector<bool> sieve(maxNum,true);
	generateSieve(sieve);
	for (int i=0;i<maxNum;i++){
		if (sieve.at(i))
			primes.push_back(i);
	}
}


int main(int argc, char *argv[]) {
	int limit = 100;
	vector<int> primes;
	genPrimeNumbers(primes,limit);
	
	vector<int> ways(limit,0);
	ways.at(0) = 1;
	for (int i=0; i < primes.size(); i++){
		cout <<"i:"<<i<<" ";
		for (int j=primes.at(i); j<limit ;j++){
			//cout <<"jj";
			ways.at(j) += ( ways.at(j-primes.at(i)));
			//cout<<"j:"<<j<<" ";
		}
		//cout <<i<<": " <<ways[i]<<endl;
	}
	for (int i=0;i<limit;i++)
		cout <<i<<": " <<ways.at(i)<<endl;
}