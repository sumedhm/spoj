#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

struct node{
	int val;
	int max;
	int min;
	bool leaf;
	node *left;
	node *right;
	node(int x, int a, int b, node *l, node *r) : val(x),min(a),max(b),left(l),right(r){}
};

int minimum(int a, int b, long long int *arr){
	if(a==INT_MAX) return b;
	else if(b==INT_MAX) return a;
	return ((arr[a]<arr[b])?a:b);
}

long long int maximum(long long int a, long long int b){
	return ((a>b)?a:b);
}

node *construct_tree(long long int *arr, int size, int min, int max){
	node *root = new node(-1, min, max, NULL, NULL);
	if(min==max){
		root->leaf = true;
		root->val = min;
	} else {
		root->leaf = false;
		int mid = (min+max)/2;
		root->left = construct_tree(arr, size, min, mid);
		root->right = construct_tree(arr, size, mid+1, max);
		root->val = minimum(root->left->val, root->right->val, arr);
	}
	return root;
}

int getMinimum(node *root, int left, int right, long long int *arr){
	if(left<=root->min && right>=root->max) return root->val;
	else if((left > root->max) || (right < root->min)) return INT_MAX;
	else return minimum(getMinimum(root->left, left, right, arr), getMinimum(root->right, left, right, arr), arr);
}

long long int maxArea(long long int *heights, int left, int right, node *root){
	if(left>right) return 0;
	if(left==right) return heights[left];
	int min = getMinimum(root,left,right,heights);
	return maximum(heights[min]*(right-left+1), maximum(maxArea(heights,left,min-1,root),maxArea(heights,min+1,right,root)));
}

long long int getArea(long long int *heights, int size, node *root){
	if(size==0) return 0;
	if(size==1) return heights[0];
	else return maxArea(heights, 0, size-1, root);
}

int main(){
	int size;
	long long int *heights;
	node *root;
	while(true){
		cin >> size;
		if(size==0) break;
		heights = (long long int *) malloc (size*sizeof(long long int));
		for(int i=0;i<size;i++) cin >> heights[i];
		root = construct_tree(heights,size,0,size-1);
		cout << getArea(heights,size,root) << endl;
		free(heights);
		free(root);
	}
}