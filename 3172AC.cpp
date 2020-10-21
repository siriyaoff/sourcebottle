#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#include<cstring>
using namespace std;

typedef vector<int> vi;

int mid(int s, int e){return (s+e)>>1;}
bool fl1(pair<string, int> e1, pair<string, int> e2);
bool fl2(pair<string, int> e1, pair<string, int> e2);

void update(vi& st, int tidx, int s, int e, int nidx, int diff);
int query(vi& st, int tidx, int s, int e, int fl, int fr);

int main()
{
	int N;
	vector<pair<string, int>> w, l1, l2;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		char tc[20];
		scanf("%s", tc);
		string s1(tc, tc+strlen(tc));
		w.push_back(make_pair(s1, i));
	}
	l1=w;
	l2=w;
	for(int i=0;i<N;i++) reverse(l2[i].first.begin(), l2[i].first.end());
	sort(l1.begin(), l1.end(), fl1);
	sort(l2.begin(), l2.end(), fl2);
	vector<pair<int, int>> newl2(N);
	for(int i=0;i<N;i++) newl2[i]=make_pair(l2[i].second, i);
	sort(newl2.begin(), newl2.end());
	
	int sz=1;
	long long int cnt=0;
	for(;sz<N;sz*=2);
	vi st(sz*2, 0);
	
	for(int i=0;i<N;i++){
		int t=newl2[l1[i].second].second;
		cnt+=query(st, 1, 0, N-1, 0, t);
		update(st, 1, 0, N-1, t, 1);
	}
	printf("%lld", cnt);
	return 0;
}

bool fl1(pair<string, int> e1, pair<string, int> e2){
	return (e1.first.compare(e2.first))<0?0:1;
}
bool fl2(pair<string, int> e1, pair<string, int> e2){
	return (e1.first.compare(e2.first))<0?1:0;
}

void update(vi& st, int tidx, int s, int e, int nidx, int diff){
	if(s>nidx || e<nidx) return;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, diff);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
	}
}

int query(vi& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return st[tidx];
	return query(st, tidx*2, s, mid(s, e), fl, fr) + query(st, tidx*2+1, mid(s, e)+1, e, fl, fr);
}