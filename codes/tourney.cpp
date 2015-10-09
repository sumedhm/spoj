#include <iostream>
#include <vector>
#include <stdlib.h>
#include <utility>

using namespace std;

long long int size;

long long int getPowerOfTwo(int n){
	if(n==0) return 1;
	int i = 1;
	long long int ans = 2;
	while(i<n){
		ans *= 2;
		i++;
	}
	return ans;
}

void heapify(pair<long long int,long long int> *heap, long long int size, long long int n2){
	long long int i = size;
	while(i>0){
		if(heap[i].second>heap[i-1].second){
			heap[(i-1)/2] = heap[i];
		} else {
			heap[(i-1)/2] = heap[i-1];
		}
		i -= 2;
	}
	return;
}

void updateHeap(pair<long long int,long long int> *heap, long long int i, long long int skill){
	heap[i].second = skill;
	while(i>0){
		if(i%2==0){
			if(heap[i].second > heap[i-1].second){
				heap[(i-1)/2] = heap[i];
			} else {
				heap[(i-1)/2] = heap[i-1];
			}
			i = (i-1)/2;
		} else {
			if(heap[i].second > heap[i+1].second){
				heap[i/2] = heap[i];
			} else {
				heap[i/2] = heap[i+1];
			}
			i = i/2;
		}
	}	
	return;
}

int main(){
	int n,m;
	long long int n2;
	cin >> n >> m;
	n2 = getPowerOfTwo(n);
	pair<long long int,long long int> *heap;
	size = (2*n2)-2;
	heap = (pair<long long int,long long int> *) malloc (size*sizeof(pair<long long int,long long int>));
	long long int index = 1;
	for(long long int i=n2-1;i<=size;i++){
		cin >> heap[i].second;
		heap[i].first = index++;
	}
	heapify(heap, size, n2);
	char query;
	long long int i, s, rounds;
	while(m--){
		cin >> query;
		if(query=='R'){
			cin >> i >> s;
			i = n2-2+i;
			updateHeap(heap, i, s);
		} else if(query=='S'){
			cin >> i;
			i = n2-2+i;
			rounds = 0;
			while(i>0){
				if(heap[(i-1)/2].second==heap[i].second) rounds++;
				else break;
				i = (i-1)/2;
			}
			cout << rounds << endl;
		} else if(query=='W'){
			cout << heap[0].first << endl;
		} else {
			cout << "Invalid query" << endl;
		}
	}
	return 0;
}