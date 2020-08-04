#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef pair<int, int> pii;

bool cmp(pii p1, pii p2){return (p1.first==p2.first)?p1.second<p2.second:p1.first>p2.first;}
int mid(int s, int e){return (s+e)/2;}
int getidx(vector<int>& v, int val){return lower_bound(v.begin(), v.end(), val)-v.begin();}
int query(vector<int>& st, int tidx, int s, int e, int fl, int fr);
void update(vector<int>& st, int tidx, int s, int e, int nidx, int diff);

int main()
{
	int T;
	vector<long long> sol;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		vector<pii> p(n);
		vector<int> yidx;
		for(int i=0;i<n;i++){
			scanf("%d %d", &p[i].first, &p[i].second);
			yidx.push_back(p[i].second);
		}
		sort(yidx.begin(), yidx.end(), less<int>());
		yidx.erase(unique(yidx.begin(), yidx.end()), yidx.end());

		int sz=1, m=yidx.size();
		for(;sz<m;sz*=2);
		vector<int> st(sz*2, 0), num(m, 0);

		long long cnt=0;
		sort(p.begin(), p.end(), cmp);
		for(int i=0;i<p.size();i++){
			int cur=getidx(yidx, p[i].second);
			cnt+=(long long)query(st, 1, 0, m-1, 0, cur);
			num[cur]++;
			update(st, 1, 0, m-1, cur, 1);
		}
		sol.push_back(cnt);
	}
	for(int i=0;i<sol.size();i++) printf("%lld\n", sol[i]);
	return 0;
}

int query(vector<int>& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return st[tidx];
	return query(st, tidx*2, s, mid(s, e), fl, fr)+query(st, tidx*2+1, mid(s, e)+1, e, fl, fr);
}

void update(vector<int>& st, int tidx, int s, int e, int nidx, int diff){
	if(s>nidx || e<nidx) return;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, diff);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
	}
}