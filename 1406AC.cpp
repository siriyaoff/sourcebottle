#include<iostream>
#include<cstdio>
#include<string>
#include<list>
using namespace std;
typedef list<char>::iterator iter;
int main()
{
	int n;
	string org;
	getline(cin, org);
	list<char> s;
	for(int i=0;i<org.length();i++) s.push_back(org[i]);
	iter idx=s.end();
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		char c;
		scanf("\n%c", &c);
		if(c=='L'){
			if(idx!=s.begin()) --idx;
		}
		else if(c=='D'){
			if(idx!=s.end()) ++idx;
		}
		else if(c=='B'){
			if(idx!=s.begin()) idx=s.erase(--idx);
		}
		else{
			char p;
			scanf(" %c", &p);
			s.insert(idx, p);
		}
	}
	for(idx=s.begin();idx!=s.end();++idx) printf("%c", *idx);
}
