#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>
#define INF 10000000
using namespace std;

struct compare{
	bool operator()(pair<int,int>& p1, pair<int,int>& p2){
		return (p2.first>p1.first);
	}
};

int distance(int src, int dest, int n, int m, int **neighbors){
		int distance[n];
		for(int i=0;i<n;i++){
			distance[i] = INF;
		}
		distance[src] = 0;
		pair<int,int> p(src,0);
		pair<int,int> tmp;
		priority_queue<pair<int,int>, vector<pair<int,int> >, compare> q;
		q.push(p);
		while(!q.empty()){
			p = q.top();
			q.pop();
			// cout << p.first << " " << p.second << endl;
			for(int i=0;i<n;i++){
				if(neighbors[p.first][i]!=-1 && distance[i]==-1){
					tmp.first = i;
					distance[i] = distance[p.first] + neighbors[p.first][i];
					tmp.second = distance[i];
					q.push(tmp);
				}
			}
		}
		return distance[dest];
}

int main(){
	int t;
	cin >> t;
	int n,m,s,d;
	int a,b;
	int duration;
	while(t--){
		cin >> n >> m >> s >> d;
		int **neighbors;
		neighbors = (int **) malloc (sizeof(int *)*n);
		for(int i=0;i<n;i++) neighbors[i] = (int *) malloc (n*sizeof(int));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				neighbors[i][j]=INF;
		for(int i=0;i<m;i++){
			cin >> a >> b >> duration;
			neighbors[a-1][b-1] = neighbors[b-1][a-1] = duration;
		}
		a = distance(s-1,d-1,n,m,neighbors);
		if(a==-1) cout << "NONE" << endl;
		else cout << a << endl;
	}
	return 0;
}