#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int r, c, a[27], m[22][22], maxd=-1, di[4]={-1, 0, 1, 0}, dj[4]={0, 1, 0, -1};

void f(int ci, int cj, int d);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		getline(cin, s, '\n');
		while(s=="") getline(cin, s, '\n');
		for(int j=1;j<=c;j++) m[i][j]=s[j-1]-'A'+1;
	}
	a[0]=1;
	f(1, 1, 1);
	cout<<maxd;
	return 0;
}

void f(int ci, int cj, int d){
	if(d>maxd) maxd=d;
	a[m[ci][cj]]=1;
	if(a[m[ci-1][cj]]==0) f(ci-1, cj, d+1);
	if(a[m[ci][cj+1]]==0) f(ci, cj+1, d+1);
	if(a[m[ci+1][cj]]==0) f(ci+1, cj, d+1);
	if(a[m[ci][cj-1]]==0) f(ci, cj-1, d+1);
	a[m[ci][cj]]=0;
}