#include <iostream>
#include <stdlib.h>
using namespace std;

struct Interval
{
	long long int start;
	long long int end;
	Interval(long long int x, long long int y) : start(x), end(y) {}
};

void quickSortJobs(Interval *intervals, long long int left, long long int right){
	long long int pivot = intervals[(left+right)/2].end, i = left, j = right;
	Interval tmp = Interval(0,0);
	while(i<=j){
		while(intervals[i].end<pivot) i++;
		while(intervals[j].end>pivot) j--;
		if(i<=j){
			tmp = intervals[i];
			intervals[i] = intervals[j];
			intervals[j] = tmp;
			i++; j--;
		}
	}
	if(j>left) quickSortJobs(intervals, left, j);
	if(i<right) quickSortJobs(intervals, i, right);
	return;
}

bool overlap(Interval i1, Interval i2){
	if(i1.start<=i2.start && i1.end<=i2.start) return false;
	else if(i2.start<=i1.start && i2.end<=i1.start) return false;
	return true;
}

long long int maximumJobs(Interval *intervals, long long int n){
	if(n<=1) return n;
	long long int count = 1;
	quickSortJobs(intervals, 0, n-1);
	long long int current = 0;
	for(long long int i=1;i<n;i++){
		if(!overlap(intervals[i], intervals[current])){
			count++;
			current = i;
		}
	}
	return count;
}

int main(){
	int t;
	cin >> t;
	long long int n, x, y;
	Interval *intervals;
	while(t--){
		cin >> n;
		intervals = (Interval *) malloc (n*sizeof(Interval));
		for(long long int i=0;i<n;i++){
			cin >> x >> y;
			intervals[i] = Interval(x,y);
		}
		cout << maximumJobs(intervals, n) << endl;
		free(intervals);
	}
	return 0;
}