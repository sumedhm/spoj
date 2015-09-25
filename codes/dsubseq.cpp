#include <iostream>
#include <string>

using namespace std;

long long int distinctSubsequence(string str){
	long long int rem = 1000000007;
	int len = str.length();
	long long int dp[len+1];
	int pos[26];
	for(int i=0;i<26;i++) pos[i]=0;
	int i = len-1;
	dp[0] = 1;
	for(int j=1;j<=len;j++){
		dp[j] = 2 * dp[j-1];
		if(dp[j]>rem) dp[j] -= rem;
		if(pos[str[i]-'A'] > 0){
			dp[j] -= dp[pos[str[i]-'A']-1];
			if(dp[j]<0) dp[j] += rem;
		}
		pos[str[i]-'A'] = j;
		i--;
	}
	return dp[len];
}

int main(){
	int T;
	cin >> T;
	while(T--){
		string str;
		cin >> str;
		cout << distinctSubsequence(str) << endl;
	}
	return 0;
}