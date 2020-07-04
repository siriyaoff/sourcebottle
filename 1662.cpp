#include<iostream>
#include<cstdio>
#include<utility>
#include<stack>
#include<string>
using namespace std;

pair<int, int> solve(string s, int indx);//(len, indx)

int main()
{
	string s;
	getline(cin, s);
	printf("%d", solve(s, 0).first);
	return 0;
}

pair<int, int> solve(string s, int indx){
	int curlen=0, curmulti;
	for(int i=indx;i<s.length();i++){
		if(i==0){
			if(s.length()==0)
				return make_pair(0, 0);
			curlen++;
		}
		else if(s[i]=='('){
			curlen--;
			curmulti=s[i-1]-'0';
			pair<int, int> p=solve(s, i+1);
			curlen+=curmulti*p.first;
			i=p.second;
		}
		else if(s[i]==')')
			return make_pair(curlen, i);
		else{
			if(i==s.length()-1)
				return make_pair(curlen+1, i);
			curlen++;
		}
	}
	return make_pair(curlen, s.length()-1);
}