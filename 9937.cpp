#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#include<map>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> p;
typedef long long int lld;

lld ct[300000][4];
lld h[300001];

p euclidean(int b, int c);
lld ncr(int n, int r){
	if(n<r) return 0;
	if(n==0 || r==0) return 1;
	if(ct[n][r]!=0) return ct[n][r];
	return ct[n][r]=(ncr(n-1, r-1) + ncr(n-1, r))%MOD;
}

int main()
{
	int n, pointflag=0;
	map<p, int> para;
	scanf("%d", &n);
	for(int i=0, a, b, c;i<n;i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a==0 && b==0){
			pointflag++;
			continue;
		}
		p anb=euclidean(a, b);
		if(para.find(anb)!=para.end())
			para[anb]++;
		else para[anb]=1;
	}
	n-=pointflag;
	for(int i=0;i<=n;i++) ct[i][0]=0, ct[i][1]=0, ct[i][2]=0, ct[i][3]=0;
	ct[0][0]=1, ct[1][1]=1, ct[2][2]=1, ct[3][3]=1;
	
	lld m=0;//m : # of all parallel lines
	vector<p> dell;
	for(auto it=para.begin();it!=para.end();it++)
		if(it->second==1) dell.push_back(it->first);
	for(int i=0;i<dell.size();i++)
		para.erase(dell[i]);
	for(auto it=para.begin();it!=para.end();it++)
		m+=it->second;

	lld ans=ncr(n-m, 3);
	ans=(ans+ncr(n-m, 2)*m)%MOD;
	lld pipj=0, curm=m, totalh=0;
	int hindx=1;
	for(auto it=para.begin();it!=para.end();it++){//pi*pj
		curm-=it->second;
		pipj=(pipj+it->second*curm)%MOD;
		h[hindx]=(it->second*curm)%MOD;//h[i]=p[i]*p[i+1-n]
		if(hindx!=1) totalh=(totalh+h[hindx])%MOD;
		hindx++;
	}
	ans=(ans+(n-m)*pipj)%MOD;
	for(int i=2;i<hindx-1;i++){//pi*pj*pk
		lld curh=h[i];
		h[i]=totalh;
		totalh-=curh;
		if(totalh<0) totalh+=MOD;
	}
	hindx=2;
	for(auto it=para.begin();it!=para.end();it++){
		if(hindx==para.size()) break;
		ans=(ans+it->second*h[hindx++])%MOD;
	}
	printf("%d\n", (int)ans);
	return 0;
}

p euclidean(int b, int c){
	int nb=b, nc=c;
	if(b==0) return make_pair(0, 1);
	if(c==0) return make_pair(1, 0);
	
	if(nb<0) nb*=-1;
	if(nc<0) nc*=-1;
	if(nb<nc) swap(nb, nc);
	while(nc!=0){
		int a=nb;
		nb=nc;
		nc=a%nb;
	}
	return make_pair(b/nb, c/nb);
}