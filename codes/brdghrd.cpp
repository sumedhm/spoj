#include <iostream>
#include <vector>
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


void display(vector<vector<int> > lists){
	for(int i=0;i<lists.size();i++){
		for(int j=0;j<lists[i].size();j++){
			cout << lists[i][j] << "->";
		}
		cout << "NULL" << endl;
	}
}

int getIndex(vector<vector<int> > lists, int val){
	int mid;
	int left = 0, right = lists.size()-1;
	while(right-left>1){
		mid = left + (right-left)/2;
		(val >= lists[mid][lists[mid].size()-1] ? right : left) = mid;
	}
	return right;
}

int lis(int *b, int size){
	if(size<=1) return size;
	vector<vector<int> > lists;
	vector<int> temp;
	temp.push_back(b[0]);
	lists.push_back(temp);
	for(int i=1;i<size;i++){
		if(b[i]<lists[0][lists[0].size()-1]){
			temp.clear();
			temp.push_back(b[i]);
			lists.insert(lists.begin(), temp);
			if(lists[0].size()==lists[1].size()) lists.erase(lists.begin()+1);
		} else if(b[i]>=lists[lists.size()-1][lists[lists.size()-1].size()-1]){
			int index = lists.size()-1;
			temp = lists[index];
			temp.push_back(b[i]);
			lists.push_back(temp);
		} else {
			int index = getIndex(lists, b[i]);
			// cout << index << endl;
			temp = lists[index-1];
			temp.push_back(b[i]);
			lists.insert(lists.begin()+index, temp);
			if(lists[index].size()==lists[index+1].size()) lists.erase(lists.begin()+index+1);
		}
		// cout << "-----------" << endl;
		// display(lists);
		// cout << "-----------" << endl;
	}
	return lists[lists.size()-1].size();
}

int main(){
	int t;
	cin >> t;
	int *a, *b;
	int size;
	while(t--){
		cin >> size;
		a = (int *) malloc (size*sizeof(int));
		b = (int *) malloc (size*sizeof(int));
		for(int i=0;i<size;i++) cin >> a[i];
		for(int i=0;i<size;i++) cin >> b[i];
		quickSort(a,b,0,size-1);
		sort(a,b,size);
		cout << lis(b, size) << endl;
		free(a);
		free(b);
	}
	return 0;
}


