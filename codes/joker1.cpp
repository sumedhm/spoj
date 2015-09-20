#include <iostream>
#include <stdlib.h>

using namespace std;

void quickSort(int *arr, int left, int right){
	int temp, i = left, j = right, pivot = arr[(left+right)/2];
	while(i<=j){
		while(arr[i]<pivot) i++;
		while(arr[j]>pivot) j--;
		if(i<=j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	}
	if(j>left) quickSort(arr, left, j);
	if(right>i) quickSort(arr, i, right);
	return;
}

int main(){
	int T;
	cin >> T;
	int *arr;
	int n;
	long long int ans = 1;
	while(T--){
		cin >> n;
		ans = 1;
		arr = (int *) malloc (n*sizeof(int));
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		quickSort(arr, 0, n-1);
		for(int i=0;i<n;i++){
			ans *= (arr[i]-i);
			if(ans>=1000000007) ans %= 1000000007;
		}
		cout << ans << endl;
		free(arr);
	}
	cout <<  "KILL BATMAN\n";
	return 0;
}