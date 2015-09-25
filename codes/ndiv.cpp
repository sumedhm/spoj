#include <iostream>

using namespace std;

long long int num_divisors(long long int a){
	if(a<=2) return a;
	long long int count = 2, b = a;
	long long int k=2;
	while(k<a){
		if(a%k == 0){
			count+=2;
			a = b/k;
			if(a==k) count--;
		}
		k++;
		if(k*k>b && count==2) return 2;
	}
	return count;
}

int main(){
	long long int a, b, n, count = 0;
	cin >> a >> b >> n;
	if(b<=1) return b;
	for(long long int i=a;i<=b;i++){
		cout << num_divisors(i) << endl;
		if(num_divisors(i)==n){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}