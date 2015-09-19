#include <iostream>
#include <stdlib.h>

using namespace std;

int maximum(int a, int b){
	return ((a>b)?a:b);
}

int maxStones(int **grid, int m, int n){
	if(m<=0 || n<=0) return 0;
	int stones[m][n];
	int max = 0;
	if(n==1){
		for(int i=0;i<m;i++){
			max += grid[i][0];
		}
		return max;
	}
	for(int i=0;i<n;i++){
		stones[m-1][i] = grid[m-1][i];
	}
	for(int i=m-2;i>=0;i--){
		for(int j=0;j<n;j++){
			if(j==0){
				stones[i][j] = maximum(stones[i+1][j], stones[i+1][j+1]) + grid[i][j];
			} else if(j==n-1){
				stones[i][j] = maximum(stones[i+1][j], stones[i+1][j-1]) + grid[i][j];
			} else {
				stones[i][j] = maximum(stones[i+1][j], maximum(stones[i+1][j-1],stones[i+1][j+1])) + grid[i][j];
			}
		}
	}
	max = stones[0][0];
	for(int i=1;i<n;i++){
		if(stones[0][i]>max) max = stones[0][i];
	}
	// for(int i=0;i<m;i++){
	// 		for(int j=0;j<n;j++)
	// 		{
	// 			cout << stones[i][j] << " ";
	// 		}
	// 		cout << endl;
	// }
		
	return max;
}

int main(){
	int T;
	cin >> T;
	int m, n;
	int **grid;
	while(T--){
		cin >> m >> n;
		grid = (int **) malloc (m * sizeof(int *));
		for(int i=0;i<m;i++) grid[i] = (int *) malloc (n * sizeof(int));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin >> grid[i][j];
		cout << maxStones(grid, m, n) << endl;
		for(int i=0;i<m;i++) free(grid[i]);
	}
	return 0;
}