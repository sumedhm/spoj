#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int minimum(int a, int b){
	return ((a<b)?a:b);
}

int getMinInsertions(string str){
	int l = str.length();
	int **arr;
	arr = (int **) malloc (l * sizeof(int *));
	for(int i=0;i<l;i++) arr[i] = (int *) malloc (l*sizeof(int));
	for(int i=0;i<l;i++)
		for(int j=0;j<l;j++)
			arr[i][j] = 0;

	for(int j=0;j<l;j++){
		for(int i=j-1;i>=0;i--){
			if(str[i]==str[j]) arr[i][j] = arr[i+1][j-1];
			else arr[i][j] = minimum(arr[i+1][j], arr[i][j-1]) + 1;
		}
	}
	return arr[0][l-1];
}

int main(){
	int k;
	cin >> k;
	string str;
	while(k--){
		cin >> str;
		cout << getMinInsertions(str) << endl;
	}
	return 0;
}