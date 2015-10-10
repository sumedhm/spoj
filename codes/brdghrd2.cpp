#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct node {
	int val;
	node *next;
};

struct list{
	node *head;
	node *tail;
	int size;
	list(node *x, node *y, int n) : head(x), tail(y), size(n) {}
};

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

int getIndex(vector<list> lists, int val){
	int mid;
	int left = 0, right = lists.size()-1;
	while(right-left>1){
		mid = left + (right-left)/2;
		(val >= lists[mid].tail->val ? right : left) = mid;
	}
	return right;
}

void display(vector<list> lists){
	node *tmp;
	for(int i=0;i<lists.size();i++){
		tmp =  lists[i].head;
		while(tmp!=NULL){
			cout << tmp->val << "->";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}
}

int lis(int *b, int size){
	if(size<=1) return size;
	vector<list> lists;
	node *tmp = (node *) malloc (sizeof(node));
	tmp->val = b[0];
	tmp->next = NULL;
	list *tmpList = new list(tmp, tmp, 1);
	lists.push_back(*tmpList);
	for(int i=1;i<size;i++){
		if(b[i]<lists[0].tail->val){
			tmp = (node *) malloc (sizeof(node));
			tmp->val = b[i];
			tmp->next = NULL;
			tmpList = new list(tmp,tmp,1);
			lists.insert(lists.begin(), *tmpList);
			if(lists[0].size==lists[1].size) lists.erase(lists.begin()+1);
		} else if(b[i]>lists[lists.size()-1].tail->val){
			*tmpList = lists[lists.size()-1]; /* Doesn't work. Instead have to copy list */
			tmpList->tail->next = (node *) malloc (sizeof(node));
			tmpList->tail = tmpList->tail->next;
			tmpList->tail->val = b[i];
			tmpList->tail->next = NULL;
			tmpList->size++;
			lists.push_back(*tmpList);
			int index = lists.size()-1;
			if(lists[index].size==lists[index+1].size) lists.erase(lists.begin()+index+1);
		} else {
			int index = getIndex(lists, b[i]);
			*tmpList = lists[index];  /* Doesn't work. Instead have to copy list */
			tmpList->tail->next = (node *) malloc (sizeof(node));
			tmpList->tail = tmpList->tail->next;
			tmpList->tail->val = b[i];
			tmpList->tail->next = NULL;
			tmpList->size++;
			lists.insert(lists.begin()+index, *tmpList);
			if(lists[index].size==lists[index+1].size) lists.erase(lists.begin()+index+1);
		}
		cout << "-----------" << endl;
		display(lists);
		cout << "-----------" << endl;
	}
	return lists[lists.size()-1].size;
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


