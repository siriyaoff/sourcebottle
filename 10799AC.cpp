#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int cnt=0;
	string s;
	stack<int> st;
	getline(cin, s);
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			cnt++;
			st.push(1);
		}
		else{
			st.pop();
			if(s[i-1]=='(') cnt+=st.size()-1;
		}
	}
	cout<<cnt;
}