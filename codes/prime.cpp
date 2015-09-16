#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int minimum(int a, int b){
	return ((a>b)?b:a);
}

int maximum(int a, int b){
	return ((a<b)?b:a);
}

bool is_prime(int num){
	if(num<2) return false;
	for(int i=2;i*i<=num;i++){
		if(num%i==0) return false;
	}
	return true;
}

int main(){

	vector<int> primes;
	vector<int> tests;
	int min,max,abs_min,abs_max;
	int temp;
	int cases;
	cin >> cases;
	while(cases > 0){
		cin >> temp;
		tests.push_back(temp);		
		cin >> temp;
		tests.push_back(temp);
		cases--;
	}
	abs_min = tests[0];
	abs_max = tests[1];
	int j=0;
	while(j<tests.size()){
		min = tests[j]; j++;
		max = tests[j]; j++;
		abs_min = minimum(min, abs_min);
		abs_max = maximum(max, abs_max);
	}
	j = abs_min;
	while(j<= abs_max){
		if(is_prime(j)) primes.push_back(j);
		j++;
	}
	j=0;
	while(j<tests.size()){
		int i;
		for(i=0;i<primes.size();i++){
			if(primes[i]>=tests[j]) break;
		}
		j++;
		while(primes[i]<=tests[j] && i<primes.size()){
			cout << primes[i] << endl;
			i++;
		}
		j++;
		cout << endl;
	}


	return 0;
}















