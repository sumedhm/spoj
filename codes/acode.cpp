#include <iostream>
#include <string>

using namespace std;

int isValid(int a, int b){
	if(a==0) return 0;
	if(a == -1) a = 0;
	int val = a*10 + b;
	if(val>=1 && val<=26) return 1;
	return 0;
}

long long int getDecodings(string str){
	int n = str.length();
	long long int decodings[n+1];
	int i = n-1, j = 0;
	decodings[0] = 1;
	if(str[i]=='0') decodings[1] = 0;
	else decodings[1] = 1;
	i--;
	for(int j=2;j<=n;j++){
		decodings[j] = isValid(-1, str[i]-'0') * decodings[j-1] + isValid(str[i]-'0', str[i+1]-'0') * decodings[j-2];
		i--;
	}
	return decodings[n];
}

int main(){
	string str;
	while(true){
		cin >> str;
		if(str[0]=='0') break;
		cout << getDecodings(str) << endl;
	}
	return 0;
}