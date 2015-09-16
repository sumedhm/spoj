#include <iostream>
#include <vector>

using namespace std;

long long int maximum(long long int a, long long int b){
	return (if(a<b) ? b : a);
}

int main(){
	long long int k, max = 0;
	vector<long long int> test;
	while(cin >> k){
		test.push(k);
		if(max < k) max = k;
	}
	vector<long long int> coins;
	coins.push(0);
	for(long long int i=1;i<=max;i++){
		coins.push(maximum(i, coins[i/2]+coins[i/3]+coins[i/4]));
	}
	for(int i=0;i<test.size();i++){
		cout << coins[test[i]] << endl;
	}
	return 0;
}