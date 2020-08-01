#include<cstdio>
#include<vector>
#define mid(s, e) ((s+e)/2)
using namespace std;
typedef vector<int> vi;

int init(vi& num, vi& st, int tidx, int s, int e);
int findsum(vi& st, int tidx, int s, int e, int fl, int fr);
void update(vi& st, int tidx, int s, int e, int nidx, int diff);

int main()
{
	int T;
	scanf("%d", &T);
	while(T-->0){
		int n, m, sz;
		scanf("%d %d", &n, &m);
		for(sz=1;sz<n+m;sz*=2) ;
		vi st(sz*2), num(n+m), pos(n+1);
		for(int i=0;i<n+m;i++) num[i]=(i<n);
		init(num, st, 1, 0, n+m-1);
		for(int i=1;i<n+1;i++) pos[i]=n-i;
		int top=n-1;

		vi watch(m), sol(m);
		for(int i=0;i<m;i++) scanf("%d", &watch[i]);
		for(int i=0;i<m;i++){
			int cur=watch[i];
			sol[i]=findsum(st, 1, 0, n+m-1, pos[cur]+1, n+m-1);
			update(st, 1, 0, n+m-1, pos[cur], -1);
			update(st, 1, 0, n+m-1, ++top, 1);
			pos[cur]=top;
		}
		for(int i=0;i<m;i++) printf("%d ", sol[i]);
		printf("\n");
	}
	return 0;
}

int init(vi& num, vi& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=num[s];
	else
		return st[tidx]=init(num, st, tidx*2, s, mid(s, e))+init(num, st, tidx*2+1, mid(s, e)+1, e);
}

int findsum(vi& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return 0;
	if(s>=fl && e<=fr) return st[tidx];
	return findsum(st, tidx*2, s, mid(s, e), fl, fr)+findsum(st, tidx*2+1, mid(s, e)+1, e, fl, fr);
}

void update(vi& st, int tidx, int s, int e, int nidx, int diff){
	if(nidx<s || nidx>e) return ;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, mid(s, e), nidx, diff);
		update(st, tidx*2+1, mid(s, e)+1, e, nidx, diff);
	}
}