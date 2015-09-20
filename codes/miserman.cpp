#include <iostream>
#include <stdlib.h>

using namespace std;

int minimum(int a, int b){
	return (a<b ? a:b);
}

int minimumFare(int **fares, int m, int n){
	if(m<=0 || n<=0) return 0;
	int min;
	if(n==1){
		for(int i=0;i<m;i++) min += fares[i][0];
		return min;
	}
	int fare[m][n];
	for(int i=0;i<n;i++){
		fare[0][i] = fares[0][i];
	}
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			if(j==0){
				fare[i][j] = minimum(fare[i-1][j], fare[i-1][j+1]) + fares[i][j];
			} else if(j==n-1){
				fare[i][j] = minimum(fare[i-1][j], fare[i-1][j-1]) + fares[i][j];
			} else {
				fare[i][j] = minimum(fare[i-1][j], minimum(fare[i-1][j-1], fare[i-1][j+1])) + fares[i][j];
			}
		}
	}
	min = fare[n-1][0];
	for(int i=0;i<n;i++){
		if(fare[n-1][i] < min) min = fare[n-1][i];
	}
	return min;
}

int main(){
	int m,n;
	int **arr;
	cin >> m >> n;
	arr = (int **) malloc (m * sizeof(int*));
	for(int i=0;i<n;i++) arr[i] = (int *) malloc (sizeof(int)*n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	cout << minimumFare(arr, m, n) << endl;
	return 0;
}