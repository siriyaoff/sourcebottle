//Merge sort tree, Parametric search solution, TC=O(NlgN + Mlg^3N)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;

int mid(int s, int e){return (s+e)>>1;}
vi& init(vi& leaf, vector<vi>& st, int tidx, int s, int e);
int query(vector<vi>& st, int tidx, int s, int e, int fl, int fr, int val);

int main()
{
	int n, m, sz=1;
	scanf("%d %d", &n, &m);
	for(;sz<n;sz*=2);
	vector<vi> st(2*sz);
	vi a(n), sol;
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	init(a, st, 1, 0, n-1);
	int s, e, k;
	for(int i=0;i<m;i++){
		scanf("%d %d %d", &s, &e, &k);
		s--, e--;
		int ts=-1e9, te=1e9;
		while(ts<=te){
			int tm=mid(ts, te), midi;
			midi=query(st, 1, 0, n-1, s, e, tm);
			if(midi>=k) te=tm-1;
			else ts=tm+1;
		}
		sol.push_back(ts);
	}
	for(int i=0;i<sol.size();i++) printf("%d\n", sol[i]);
	return 0;
}

vi& init(vi& leaf, vector<vi>& st, int tidx, int s, int e){
	if(s==e){
		st[tidx].push_back(leaf[s]);
		return st[tidx];
	}
	else{
		vi& l=init(leaf, st, tidx*2, s, mid(s, e));
		vi& r=init(leaf, st, tidx*2+1, mid(s, e)+1, e);
		int i, j, llen=st[tidx*2].size(), rlen=st[tidx*2+1].size();
		for(i=0, j=0;1;){
			if(l[i]>r[j]){
				st[tidx].push_back(r[j]);
				j++;
				if(j==rlen){
					for(int k=i;k<llen;k++) st[tidx].push_back(l[k]);
					break;
				}
			}
			else{
				st[tidx].push_back(l[i]);
				i++;
				if(i==llen){
					for(int k=j;k<rlen;k++) st[tidx].push_back(r[k]);
					break;
				}
			}
		}
		return st[tidx];
	}
}

int query(vector<vi>& st, int tidx, int s, int e, int fl, int fr, int val){
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return upper_bound(st[tidx].begin(), st[tidx].end(), val)-st[tidx].begin();
	return query(st, tidx*2, s, mid(s, e), fl, fr, val)+query(st, tidx*2+1, mid(s, e)+1, e, fl, fr, val);
}

//Segment tree solution, TC=O(MNlgN)
// #include<cstdio>
// #include<vector>
// #include<utility>
// #include<algorithm>
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int, int> pii;

// int mid(int s, int e){return (s+e)>>1;}
// int init(vi& leaf, vi& st, int tidx, int s, int e);
// void update(vi& st, int tidx, int s, int e, int nidx, int diff);
// int query(vi& st, int tidx, int s, int e, int k);

// int main()
// {
// 	int n, m, sz=1;
// 	scanf("%d %d", &n, &m);
// 	for(;sz<n;sz*=2);
// 	vi st(sz*2, 0), leaf(n, 0), a(n), sol;
// 	for(int i=0;i<n;i++) scanf("%d", &a[i]);
// 	vector<pii> l2a(n), a2l(n);
// 	for(int i=0;i<n;i++) l2a[i]=make_pair(a[i], i);
// 	sort(l2a.begin(), l2a.end());
// 	for(int i=0;i<n;i++) a2l[i]=make_pair(l2a[i].second, i);
// 	sort(a2l.begin(), a2l.end());
	
// 	int s, e, k;
// 	for(int i=0;i<m;i++){//O(m)
// 		scanf("%d %d %d", &s, &e, &k);
// 		s--, e--;
// 		for(int j=s;j<=e;j++) leaf[a2l[j].second]=1;
// 		init(leaf, st, 1, 0, n-1);
// 		int idx=query(st, 1, 0, n-1, k);
// 		sol.push_back(l2a[idx].first);
// 		for(int j=s;j<=e;j++) leaf[a2l[j].second]=0;
// 		init(leaf, st, 1, 0, n-1);
// 	}
// 	for(int i=0;i<sol.size();i++) printf("%d\n", sol[i]);
// }

// int init(vi& leaf, vi& st, int tidx, int s, int e){
// 	if(s==e) return st[tidx]=leaf[s];
// 	return st[tidx]=init(leaf, st, tidx*2, s, mid(s, e))+init(leaf, st, tidx*2+1, mid(s, e)+1, e);
// }

// void update(vi& st, int tidx, int s, int e, int nidx, int diff){
// 	if(s>nidx || e<nidx) return;
// 	st[tidx]+=diff;
// 	if(s!=e){
// 		update(st, tidx*2, s, mid(s, e), nidx, diff);
// 		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
// 	}
// }

// int query(vi& st, int tidx, int s, int e, int k){
// 	if(s==e) return s;
// 	if(k>st[tidx*2]) return query(st, tidx*2+1, mid(s, e)+1, e, k-st[tidx*2]);
// 	else return query(st, tidx*2, s, mid(s, e), k);
// }

//https://jaimemin.tistory.com/744
//이거 되냐?