#include <iostream>

using namespace std;

int main(){
	int num[10];
	int i=0;
	while(i<10){
		num[i++] = i-1;
	}
	i=0;
	while(i<10){
		cout << i++ << endl;
		// num[i++] = num[i-1];
	}
	return 0;
}