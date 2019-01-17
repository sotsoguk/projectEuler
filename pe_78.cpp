#include <iostream>
#include <vector>
//pe 78
using namespace std;
int main(int argc, char *argv[]) {
	// create pentagonal numbers
	int penNums = 1001;
	long long modNum = 1000000;
	vector<long long> gpens(penNums,0);
	gpens.at(0) = 0;
	for (unsigned int i = 1;i<=penNums /2;i++){
		gpens.at(2*i-1) = (3*i-1)*i/2;
		gpens.at(2*i) = (3*(-i)-1)*(-i) / 2;
	}
	int maxNum = 1000000;
	vector<long long > p(maxNum,0);
	p.at(0) = 1;
	
	for (int i=1;i<maxNum;i++){
		for (int k=1; k<penNums && (i-gpens.at(k)) >=0;k++){
			int mult = (((k-1)/2))%2 ? -1: 1;
			//cout <<"i:"<<i<<":"<<i-gpens.at(k)<<endl;
			p.at(i) += ((mult * p.at(i-gpens.at(k))));// % modNum);
			p.at(i) %= modNum;
		}
		if (p.at(i)==0){
			cout <<"HELLO: "<<i<<endl;
			break;
		}
	}
//	cout<<p.at(55374);
//	for (int i=0;i<maxNum;i++)
//		cout <<p.at(i)<<" ";	
//	cout <<endl;
//	for (int k=1;k<10;k++){
//		int tmp = (((k-1)/2))%2;
//		int mult = (((k-1)/2))%2 ? -1: 1;
//		cout <<k<<","<<mult<<"\t";
//	}
}