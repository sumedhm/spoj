#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void isPossible(float *radius, int n){
	sort(radius, radius+n);
	float sum = radius[0];
	for(int i=1;i<n;i++){
		if(sum>=radius[i]){
			cout << "YES" << endl;
			return;
		}
		sum += radius[i];
	}
	cout << "NO" << endl;
	return;
}

int main(){
	int t;
	float *radii;
	while(true){
		cin >> t;
		if(t==0) break;
		radii = (float *) malloc (t*sizeof(float));
		for(int i=0;i<t;i++){
			cin >> radii[i];
		}
		isPossible(radii, t);
		free(radii);
	}
	return 0;
}