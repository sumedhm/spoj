#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<char> ostack;
	char exp[100];
	int i=0;
	cout << "Enter an expression:\n";
	cin >> exp;
	cout << "\n\nHere is the RNP:\n";
	char next = exp[i++];
	ostack.push('#');
	while(next!='\0'){
		if(next=='+' || next=='-' || next=='*' 
				|| next=='/' || next=='^' || next=='(') {
			ostack.push(next);
		} else if(next==')'){  //Till the matching (
			while(ostack.top()!='('){
				cout << ostack.top();ostack.pop();
			}
			ostack.pop();	//Pop the matching (
		} else cout << next;
		next = exp[i++];
	}
	while(ostack.top()!='#'){
		cout << ostack.top(); ostack.pop();
	}
	cout << '\n';
	return 0;
}
