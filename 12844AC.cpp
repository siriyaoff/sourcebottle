#include<cstdio>
#include<vector>
using namespace std;

int mid(int s, int e){return (s+e)>>1;}
int init(vector<int>& leaf, vector<int>& st, int tidx, int s, int e);
int query(vector<int>& lazy, vector<int>& st, int tidx, int s, int e, int fl, int fr);
void update(vector<int>& lazy, vector<int>& st, int tidx, int s, int e, int ul, int ur, int k);
void propagate(vector<int>& lazy, vector<int>& st, int tidx, int s, int e);

int main()
{
	int n, sz, m, c, a, b, k;
	scanf("%d", &n);
	for(sz=1;sz<n;sz*=2);
	vector<int> st(sz*2), leaf(n), lazy(sz*2, 0), sol;
	for(int i=0;i<n;i++) scanf("%d", &leaf[i]);
	init(leaf, st, 1, 0, n-1);
	scanf("%d", &m);
	while(m--){
		scanf("%d", &c);
		if(c>>1){
			scanf("%d %d", &a, &b);
			sol.push_back(query(lazy, st, 1, 0, n-1, a, b));
		}
		else{
			scanf("%d %d %d", &a, &b, &k);
			update(lazy, st, 1, 0, n-1, a, b, k);
		}
	}
	for(int i=0;i<sol.size();i++) printf("%d\n", sol[i]);
	return 0;
}

int init(vector<int>& leaf, vector<int>& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=leaf[s];
	return st[tidx]=init(leaf, st, tidx*2, s, mid(s, e))^init(leaf, st, tidx*2+1, mid(s, e)+1, e);
}

int query(vector<int>& lazy, vector<int>& st, int tidx, int s, int e, int fl, int fr){
	propagate(lazy, st, tidx, s, e);
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return st[tidx];
	return query(lazy, st, tidx*2, s, mid(s, e), fl, fr)^query(lazy, st, tidx*2+1, mid(s, e)+1, e, fl, fr);
}

void update(vector<int>& lazy, vector<int>& st, int tidx, int s, int e, int ul, int ur, int k){
	propagate(lazy, st, tidx, s, e);
	if(e<ul || s>ur) return;
	if(s>=ul && e<=ur){
		st[tidx]=st[tidx]^(k*((e-s+1)%2));
		if(s!=e){
			lazy[tidx*2]=lazy[tidx*2]^k;
			lazy[tidx*2+1]=lazy[tidx*2+1]^k;
		}
		return;
	}
	update(lazy, st, tidx*2, s, mid(s, e), ul, ur, k);
	update(lazy, st, tidx*2+1, mid(s, e)+1, e, ul, ur, k);
	st[tidx]=st[tidx*2]^st[tidx*2+1];
}

void propagate(vector<int>& lazy, vector<int>& st, int tidx, int s, int e){
	if(lazy[tidx]){
		st[tidx]=st[tidx]^(lazy[tidx]*((e-s+1)%2));
		if(s!=e){
			lazy[tidx*2]=lazy[tidx*2]^lazy[tidx];
			lazy[tidx*2+1]=lazy[tidx*2+1]^lazy[tidx];
		}
		lazy[tidx]=0;
	}
}