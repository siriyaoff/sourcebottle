#include<bits/stdc++.h>
using namespace std;

int n, p[2188][2188], ncnt[3];

void d(int ai, int aj, int bi, int bj){
	if(bi==ai){
		ncnt[p[ai][aj]+1]++;
		return;
	}
	int t=p[ai][aj], dif=(bi-ai+1)/3;
	for(int i=ai;i<=bi;i++){
		for(int j=aj;j<=bj;j++){
			if(p[i][j]!=t){
				t=p[i][j];
				for(int k=0;k<3;k++) for(int l=0;l<3;l++)
					d(ai+k*dif, aj+l*dif, ai+(k+1)*dif-1, aj+(l+1)*dif-1);
				break;
			}
		}
		if(t!=p[ai][aj]) break;
	}
	if(t==p[ai][aj]) ncnt[t+1]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>p[i][j];
	d(1, 1, n, n);
	cout<<ncnt[0]<<"\n"<<ncnt[1]<<"\n"<<ncnt[2];
}