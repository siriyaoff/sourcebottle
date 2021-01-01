#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int sd[9][9];
vi vl;

int check(int ci, int cj, int v);
int make_pq(){
	for(int i=0;i<9;i++) for(int j=0;j<9;j++){
		if(sd[i][j]) continue;
		vl.push_back(i*10+j);
	}
	if(vl.empty()) return 0;
	return 1;
}
int f(int idx);

int main()
{
	string s;
	for(int i=0;i<9;i++){
		int jidx=0;
		getline(cin, s, '\n');
		while(s=="") getline(cin, s, '\n');
		for(int j=0;j<s.length();j++) if(s[j]!=' ') sd[i][jidx++]=s[j]-48;
	}
	if(make_pq()) f(0);
	s.clear();
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			s.push_back(sd[i][j]+'0');
			s.push_back(' ');
		}
		s.push_back('\n');
	}
	cout<<s;
}

int check(int ci, int cj, int v){
	for(int i=0;i<9;i++){
		if(sd[ci][i]==v) return 0;
		if(sd[i][cj]==v) return 0;
	}
	for(int i=ci/3*3;i<(ci/3+1)*3;i++) for(int j=cj/3*3;j<(cj/3+1)*3;j++)
		if(sd[i][j]==v) return 0;
	return 1;
}

int f(int idx){
	int ci=vl[idx]/10, cj=vl[idx]%10;
	for(int i=1;i<10;i++){
		if(check(ci, cj, i)){
			sd[ci][cj]=i;
			if(idx+1==vl.size()) return 1;
			if(f(idx+1)) return 1;
		}
		sd[ci][cj]=0;
	}
	return 0;
}