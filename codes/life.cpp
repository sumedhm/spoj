#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

	int temp=0;
	while(1){
		cin >> temp;
		if(temp==42) break;
		cout << temp << endl;
	}
	return 0;
}