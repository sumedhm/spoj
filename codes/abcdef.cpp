#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int *arr, int left, int right){
	int tmp, pivot = arr[(left+right)/2], i = left, j = right;
	while(i<=j){
		while(arr[i]<pivot) i++;
		while(arr[j]>pivot) j--;
		if(i<=j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++; j--;
		}
	}
	if(j>left) quickSort(arr, left, j);
	if(i<right) quickSort(arr, i, right);
	return;
}

 int search(int *arr, int n, int left, int right, int key){
	if(left>right) return 0;
	int count = 0;
	if(arr[left]==key){
		while(left<n && arr[left]==key){
			left++; count++;
		}
		return count;
	}
	else if(right>=0 && arr[right]==key){
		while(arr[right]==key){
			right--; count++;
		}
		return count;
	}
	int mid = (left+right)/2;
	if(arr[mid]==key){
		left = mid-1;
		while(left>=0 && arr[left]==key){
			left--; count++;
		}
		while(mid<n && arr[mid]==key){
			mid++; count++;
		}
		return count;
	}
	if(key<arr[mid]) return search(arr, n, left+1, mid-1, key);
	else return search(arr, n, mid+1, right-1, key);
}

int main(){
	int N;
	int N3;
	cin >> N;
	int arr[N];
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	/*
	(a*b+c)/d - e = f
	(a*b+c) = (f + e)*d
	j = k
	*/
	N3 = N*N*N;
	int count = 0;
	int lhs[N3], rhs;
	int l = 0;
	for(int a=0;a<N;a++){
		for(int b=0;b<N;b++){
			for(int c=0;c<N;c++){
				lhs[l] = arr[a] * arr[b] + arr[c];
				l++;
			}
		}
	}
	sort(lhs, lhs+N3);
	l = 0;
	for(int d=0;d<N;d++){
		if(arr[d]==0){
			continue;
		}
		for(int e=0;e<N;e++){
			for(int f=0;f<N;f++){
				rhs = (arr[f] + arr[e]) * arr[d];
				count += search(lhs,N3,0,N3-1,rhs);
				l++;
			}
		}
	}
	cout << count << endl;
	return 0;
}