#include <iostream>
#include <stdlib.h>

using namespace std;

void getDescription(long long int len, int *terms){
	long long int cur = 2;
	long long int i = 0, j = 1, nums = 0;
	terms[0] = 1;
	long long int length = 1;
	while(j<len){
		//cur++;
		if(nums>=length){
			cur++;
			nums = 0;
			i++;
			length = terms[i];
		} else {
			terms[j] = cur;
			nums++;
			j++;
		}
	}
	return;
}

int main(){
	long long int t,max=0;
	cin >> t;
	int cases[t];
	for(int i=0;i<t;i++){
		cin >> cases[i];
		if(cases[i]>max) max = cases[i];
	}
	int *terms = (int *) malloc (max*sizeof(int));
	getDescription(max, terms);
	// cout << str << endl;
	for(int i=0;i<t;i++){
		cout << "Case #" << i+1 << ": " << terms[cases[i]-1] << endl;
	}
	return 0;
}