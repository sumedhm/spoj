#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long int maximum(long long int a, long long int b){
	return ((a<b) ? b : a);
}

void getDollars(map<long long int, long long int>& coins, long long int n){
	if(!(coins.find(n)==coins.end())) return;
	getDollars(coins, n/2);
	getDollars(coins, n/3);
	getDollars(coins, n/4);
	coins[n] = maximum(n, coins[n/2]+coins[n/3]+coins[n/4]);
	return;
}

int main(){
	long long int k;
	vector<long long int> test;
	while(cin >> k){
		test.push_back(k);
	}
	map<long long int, long long int> coins;
	coins[0] = 0, coins[1] = 1, coins[2] = 2;
	for(int i=0;i<test.size();i++){
		getDollars(coins, test[i]);
		cout << coins[test[i]] << endl;
	}
	return 0;
}