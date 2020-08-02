#include<cstdio>
#include<vector>
#define mid(s, e) ((s+e)/2)
using namespace std;
typedef vector<int> vi;

int init(vi& num, vi& st, int tidx, int s, int e);
int findsum(vi& st, vi& lazy, int tidx, int s, int e, int fl, int fr);
void update(vi& st, vi& lazy, int tidx, int s, int e, int fl, int fr);
void propagate(vi& st, vi& lazy, int tidx, int s, int e);

int main()
{
	int N, M, sz;
	scanf("%d %d", &N, &M);
	for(sz=1;sz<N;sz*=2) ;
	vi num(N, 0), st(sz*2), lazy(sz*2, 0), sol;
	init(num, st, 1, 0, N-1);
	for(int i=0;i<M;i++){
		int O, S, T;
		scanf("%d %d %d", &O, &S, &T);
		S--, T--;
		if(O) sol.push_back(findsum(st, lazy, 1, 0, N-1, S, T));
		else update(st, lazy, 1, 0, N-1, S, T);
	}
	for(int i=0;i<sol.size();i++) printf("%d\n", sol[i]);
	return 0;
}

int init(vi& num, vi& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=num[s];
	return st[tidx]=init(num, st, tidx*2, s, mid(s, e))+init(num, st, tidx*2+1, mid(s, e)+1, e);
}

int findsum(vi& st, vi& lazy, int tidx, int s, int e, int fl, int fr){
	propagate(st, lazy, tidx, s, e);
	if(s>fr || e<fl) return 0;
	if(fl<=s && e<=fr) return st[tidx];
	return findsum(st, lazy, tidx*2, s, mid(s, e), fl, fr)+findsum(st, lazy, tidx*2+1, mid(s, e)+1, e, fl, fr);
}

void update(vi& st, vi& lazy, int tidx, int s, int e, int fl, int fr){
	propagate(st, lazy, tidx, s, e);
	if(fl>e || fr<s) return;
	if(fl<=s && fr>=e){
		st[tidx]=e-s+1-st[tidx];
		if(s!=e){
			lazy[tidx*2]=1-lazy[tidx*2];
			lazy[tidx*2+1]=1-lazy[tidx*2+1];
		}
		return;
	}
	update(st, lazy, tidx*2, s, mid(s, e), fl, fr);
	update(st, lazy, tidx*2+1, mid(s, e)+1, e, fl, fr);
	st[tidx]=st[tidx*2]+st[tidx*2+1];
}

void propagate(vi& st, vi& lazy, int tidx, int s, int e){
	if(lazy[tidx]){
		st[tidx]=e-s+1-st[tidx];
		if(s!=e){
			lazy[tidx*2]=1-lazy[tidx*2];
			lazy[tidx*2+1]=1-lazy[tidx*2+1];
		}
		lazy[tidx]=0;
	}
}
		
// 		printf("\nst\n");
// 		for(int i=1, h=2;i<sz*2;i++){
// 			printf("%d ", st[i]);
// 			if(i==h-1){
// 				printf("\n");
// 				h*=2;
// 			}
// 		}
// 		printf("\n");
// 		printf("lazy\n");
// 		for(int i=1, h=2;i<sz*2;i++){
// 			printf("%d ", lazy[i]);
// 			if(i==h-1){
// 				printf("\n");
// 				h*=2;
// 			}
// 		}
		// printf("\n");