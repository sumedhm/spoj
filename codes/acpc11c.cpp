#include <iostream>
#include <stdlib.h>

using namespace std;

long long int minimum(long long int a, long long int b){
	return ((a<b)? a:b);
}

long long int minTotalDistance(long long int arr[], long long int n, long long int length){
	long long int sum1 = 0, sum2 = length - arr[0], min = length;
	for(long long int i=0;i<n-2;i++){
		sum1 += arr[i];
		sum2 -= arr[i+1];
		min = minimum(min, 2*sum1+sum2);
	}
	sum1 += arr[n-2];
	min = minimum(min, sum1);
	sum1 = 0; sum2 = length - arr[n-1];
	for(long long int i = n-1;i>1;i--){
		sum1 += arr[i];
		sum2 -= arr[i-1];
		min = minimum(min, 2*sum1+sum2);
	}
	sum1 += arr[1];
	min = minimum(min, sum1);
	return min;
}

int main(){
	int t;
	cin >> t;
	long long int n, i, sum;
	while(t--){
		long long int *arr;
		cin >> n;
		arr = (long long int *) malloc (n*sizeof(long long int));
		i = 0;
		sum = 0;
		while(i<n){
			cin >> arr[i];
			sum += arr[i];
			i++;
		}
		cout << minTotalDistance(arr, n, sum) << endl;
		free(arr);
	}
	return 0;	
}