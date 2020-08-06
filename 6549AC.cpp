#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int min(int a, int b){return (a>b)?b:a;}
int mid(int s, int e){return (s+e)>>1;}
int init(vi& h, vi& st, int tidx, int s, int e);
int query(vi& h, vi& st, int tidx, int s, int e, int fl, int fr);
ll measure(vi& h, vi& st, int s, int e);

int n;

int main()
{
	vector<ll> sol;
	while(1){
		int sz=1;
		scanf("%d", &n);
		if(n==0) break;
		for(;sz<n;sz*=2);
		vi h(n), st(sz*2);
		for(int i=0;i<n;i++) scanf("%d", &h[i]);
		init(h, st, 1, 0, n-1);
		sol.push_back(measure(h, st, 0, n-1));
	}
	for(auto it=sol.begin();it!=sol.end();it++) printf("%lld\n", *it);
	return 0;
}

int init(vi& h, vi& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=s;
	int l=init(h, st, tidx*2, s, mid(s, e));
	int r=init(h, st, tidx*2+1, mid(s, e)+1, e);
	return st[tidx]=(h[l]>h[r])?r:l;
}

int query(vi& h, vi& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return -1;
	if(s>=fl && e<=fr) return st[tidx];
	int l=query(h, st, tidx*2, s, mid(s, e), fl, fr);
	int r=query(h, st, tidx*2+1, mid(s, e)+1, e, fl, fr);
	if(l==-1) return r;
	if(r==-1) return l;
	return (h[l]>h[r])?r:l;
}

ll measure(vi& h, vi& st, int s, int e){
	if(s==e) return h[s];
	int piv=query(h, st, 1, 0, n-1, s, e);
	if(piv==-1) return 0;
	ll max=(ll)h[piv]*(e-s+1);
	ll l, r;
	if(piv==0) l=-1;
	else l=measure(h, st, s, piv-1);
	if(piv==n-1) r=-1;
	else r=measure(h, st, piv+1, e);
	l=(l>r)?l:r;
	return (max>l)?max:l;
}