#include <iostream>
#include <stdlib.h>

using namespace std;


void quickSort(int *a, int left, int right){
	if(left==right) return;
	int i = left, j = right, tmp, pivot = a[(left+right)/2];
	while(i<=j){
		while(a[i]<pivot) i++;
		while(a[j]>pivot) j--;
		if(i<=j){
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}
	if(j>left) quickSort(a,left,j);
	if(i<right) quickSort(a,i,right);
	return;
}

void quickSort(int *a, int *b, int left, int right){
	int i = left, j = right, tmp, pivot = a[(left+right)/2];
	while(i<=j){
		while(a[i]<pivot) i++;
		while(a[j]>pivot) j--;
		if(i<=j){
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			tmp = b[i];
			b[i] = b[j];
			b[j] = tmp;
			i++; j--;
		}
	}
	if(j>left) quickSort(a,b,left,j);
	if(i<right) quickSort(a,b,i,right);
	return;
}

int lis(int *arr, int size){
	int dp[size], max = 0;
	for(int i=0;i<size;i++) dp[i] = 1;
	for(int i=1;i<size;i++){
		for(int j=0;j<i;j++){
			if((arr[i] >= arr[j]) && (dp[i]<dp[j]+1)){
				dp[i] = dp[j]+1;
			}
		}
	}
	for(int i=0;i<size;i++){
		if(max<dp[i]) max = dp[i];
	}
	return max;
}

void sort(int *a, int *b, int size){
	int i=0, j=0;
	while(i<size){
		while(j<size && a[j]==a[i]) j++;
		j--;
		if(i != j) quickSort(b,i,j);
		i = j+1;
		j = i;
	}
	return;
}

int main(){
	int t;
	cin >> t;
	int n;
	int *a, *b;
	while(t--){
		cin >> n;
		a = (int *) malloc (n*sizeof(int));
		b = (int *) malloc (n*sizeof(int));
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<n;i++) cin >> b[i];
		quickSort(a,b,0,n-1);
		sort(a,b,n);
		cout << lis(b, n) << endl;
		free(a);
		free(b);
	}
	return 0;
}