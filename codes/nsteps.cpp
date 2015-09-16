#include <iostream>

using namespace std;

int main(){
	int k, x, y, n;
	cin >> k;
	while(k--){
		cin >> x >> y;
		n = x*2;
		if(x%2!=0) n--;
		if(x==y){
			cout << n << endl;
		} else if(x==y+2){
			cout << n-2 << endl;
		} else {
			cout << "No Number" << endl;
		}
	}
	return 0;
}