#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lld;

lld cnt;

int mid(int s, int e){return (s+e)>>1;}
void mergesort(vi& p, int s, int e);
void merge(vi& p, int s, int mid, int e);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vi p(n);
	for(auto& i:p) cin>>i;
	mergesort(p, 0, n-1);
	cout<<cnt;
}

void mergesort(vi& p, int s, int e){
	if(s==e) return;
	mergesort(p, s, mid(s, e));
	mergesort(p, mid(s, e)+1, e);
	merge(p, s, mid(s, e), e);
}

void merge(vi& p, int s, int mid, int e){
	int aidx=s, bidx=mid+1, idx=0;
	vi t(e-s+1);
	while(aidx!=mid+1 && bidx!=e+1){
		if(p[aidx]<=p[bidx]){
			t[idx++]=p[aidx++];
			cnt+=bidx-mid-1;
		}
		else{
			t[idx++]=p[bidx++];
			//cnt+=mid-aidx+1;
		}
	}
	if(aidx!=mid+1){
		cnt+=(lld)(e-mid)*(mid-aidx+1);
		for(;aidx!=mid+1;) t[idx++]=p[aidx++];
	}
	else for(;bidx!=e+1;) t[idx++]=p[bidx++];
	for(int i=0;i<idx;i++) p[i+s]=t[i];
}

// #include<bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;
// typedef long long int lld;
// typedef pair<int, int> pii;

// bool compare(pii p1, pii p2){return p1.first<p2.first;}
// int mid(int s, int e){return (s+e)>>1;}
// void update(vi& st, int tidx, int s, int e, int nidx, int diff);
// int query(vi& st, int tidx, int s, int e, int fl, int fr);

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	int n, sz=1;
// 	cin>>n;
// 	for(;sz<n;sz*=2);
// 	vi st(2*sz, 0);
// 	vector<pii> pairs;
// 	for(int i=0;i<n;i++){
// 		int t;
// 		cin>>t;
// 		pairs.push_back({t, i});
// 	}
// 	stable_sort(pairs.begin(), pairs.end(), compare);
// 	lld cnt=0;
// 	for(int i=0;i<n;i++){
// 		cnt+=query(st, 1, 0, n-1, pairs[i].second, n-1);
// 		update(st, 1, 0, n-1, pairs[i].second, 1);
// 	}
// 	cout<<cnt;
// }

// void update(vi& st, int tidx, int s, int e, int nidx, int diff){
// 	if(s>nidx || e<nidx) return;
// 	st[tidx]+=diff;
// 	if(s!=e){
// 		update(st, tidx*2, s, mid(s, e), nidx, diff);
// 		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
// 	}
// }

// int query(vi& st, int tidx, int s, int e, int fl, int fr){
// 	if(s>fr || e<fl) return 0;
// 	if(s>=fl && e<=fr) return st[tidx];
// 	return query(st, tidx*2, s, mid(s, e), fl, fr)+query(st, tidx*2+1, mid(s, e)+1, e, fl, fr);
// }
