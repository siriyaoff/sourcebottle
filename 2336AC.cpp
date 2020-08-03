#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int, int> > abc;

bool cmp(abc s1, abc s2){
	return s1.first<s2.first;
}
int min(int a, int b){return (a<b)?a:b;}
int mid(int a, int b){return (a+b)>>1;}
int findmin(vector<int>& st, int tidx, int s, int e, int fl, int fr);
void update(vector<int>& st, int tidx, int s, int e, int nidx, int v);

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> a(N), b(N), c(N);
	vector<abc> s;
	for(int i=0, j;i<N;i++) scanf("%d", &j), a[--j]=i;
	for(int i=0, j;i<N;i++) scanf("%d", &j), b[--j]=i;
	for(int i=0, j;i<N;i++) scanf("%d", &j), c[--j]=i;
	for(int i=0;i<N;i++) s.push_back(make_pair(a[i], make_pair(b[i], c[i])));
	sort(s.begin(), s.end(), cmp);
	int sz=1;
	for(sz;sz<N;sz*=2);
	vector<int> st(sz*2);
	for(int i=0;i<sz*2;i++) st[i]=987654321;
	
	int cnt=0;
	for(int i=0;i<N;i++){
		if(findmin(st, 1, 0, N-1, 0, s[i].second.first-1)>s[i].second.second) cnt++;
		update(st, 1, 0, N-1, s[i].second.first, s[i].second.second);
	}
	printf("%d", cnt);
	return 0;
}

int findmin(vector<int>& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return 987654321;
	if(s>=fl && e<=fr) return st[tidx];
	return min(findmin(st, tidx*2, s, mid(s, e), fl, fr), findmin(st, tidx*2+1, mid(s, e)+1, e, fl, fr));
}

void update(vector<int>& st, int tidx, int s, int e, int nidx, int v){
	if(nidx<s || nidx>e) return ;
	st[tidx]=min(st[tidx], v);
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, v);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, v);
	}
}