#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lld;

int m[1000][1000];
string s;
void lieul(int r, int c);
void v(int c);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, c;
	cin>>r>>c;
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>m[i][j];
	if(r&1){
		lieul(r, c);
		s.erase(s.length()-1, 1);
	}
	else if(c&1){
		//w한번 하고 ㄹ로 전부 탐색
		v(c);
		s.append(2, 'D');
		s.append(c-1, 'L');
		s.push_back('D');
		lieul(r-3, c);
		s.erase(s.length()-1, 1);
	}
	else{//r|2 && c|2
		int minv=1001, mi=0, mj=0;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++)
			if((i+j)&1 && minv>m[i][j]){
				minv=m[i][j];
				mi=i;
				mj=j;
			}
		if(mi>1){
			if(mi&1) lieul(mi-1, c);
			else lieul(mi, c);
		}
		if(mj>1){
			if(mj&1) v(mj-1);
			else v(mj);
		}
		//NW finished
		if(mi&1) s.append("RD");
		else s.append("DR");
		//mimj block finished
		if(mj<c-2)
			for(int i=0;i<(c-1-mj)/2;i++) s.append("RURD");
		if(mi<r-2){
			for(int i=0;i<(r-1-mi)/2;i++){
				s.push_back('D');
				s.append(c-1, 'L');
				s.push_back('D');
				s.append(c-1, 'R');
			}
		}
	}
	cout<<s;
}

void lieul(int r, int c){
	int f=0;
	char rl[2]={'R', 'L'};
	for(int i=0;i<r;i++){
		s.append(c-1, rl[f]);
		s.push_back('D');
		f^=1;
	}
}

void v(int c){ //c&1일때만 사용
	for(int i=0;i<c/2;i++) s.append("DRUR");
}