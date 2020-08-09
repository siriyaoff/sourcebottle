//Segment tree solution, TC=O(NlgN+M(lgN)^2)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;

int mid(int s, int e){return (s+e)>>1;}
int init(vi& h, vector<vi>& color, vi& st, int tidx, int s, int e);
int query(vector<vi>& color, vi& st, int tidx, int s, int e, int fl, int fr);

int main()
{
	int N, C, M, s, e, sz=1;
	scanf("%d %d", &N, &C);
	for(;sz<N;sz*=2);
	vi h(N), st(2*sz);
	vector<vi> color(C+1);
	for(int i=0;i<N;i++){
		scanf("%d", &h[i]);
		color[h[i]].push_back(i);
	}
	init(h, color, st, 1, 0, N-1);
	scanf("%d", &M);
	vi sol(M);
	for(int i=0;i<M;i++){
		scanf("%d %d", &s, &e);
		sol[i]=query(color, st, 1, 0, N-1, s-1, e-1);
	}
	for(int i=0;i<M;i++)
		if(sol[i]==-1) printf("no\n");
		else printf("yes %d\n", sol[i]);
	return 0;
}

int init(vi& h, vector<vi>& color, vi& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=h[s];
	init(h, color, st, tidx*2, s, mid(s, e));
	init(h, color, st, tidx*2+1, mid(s, e)+1, e);
	int curc=st[tidx*2], cnt=0;
	if(curc!=-1) cnt=upper_bound(color[curc].begin(), color[curc].end(), e)-lower_bound(color[curc].begin(), color[curc].end(), s);
	if(cnt>(e-s+1)/2) return st[tidx]=curc;
	curc=st[tidx*2+1];
	if(curc!=-1) cnt=upper_bound(color[curc].begin(), color[curc].end(), e)-lower_bound(color[curc].begin(), color[curc].end(), s);
	if(cnt>(e-s+1)/2) return st[tidx]=curc;
	return st[tidx]=-1;
}

int query(vector<vi>& color, vi& st, int tidx, int s, int e, int fl, int fr){
	if(s>fr || e<fl) return -1;
	if(s>=fl && e<=fr){
		int cc=st[tidx], cnt;
		if(cc==-1) return -1;
		cnt=upper_bound(color[cc].begin(), color[cc].end(), fr)-lower_bound(color[cc].begin(), color[cc].end(), fl);
		if(cnt>(fr-fl+1)/2) return st[tidx];
		else return -1;
	}
	int cur=query(color, st, tidx*2, s, mid(s, e), fl, fr);
	if(cur!=-1) return cur;
	cur=query(color, st, tidx*2+1, mid(s, e)+1, e, fl, fr);
	if(cur!=-1) return cur;
	return -1;
}
//Randomization solution, TC=O(16MlgN)
// #include<cstdio>
// #include<cstdlib>
// #include<vector>
// #include<utility>
// #include<time.h>
// #include<algorithm>
// using namespace std;
// typedef vector<int> vi;

// int main()
// {
// 	srand(time(NULL));
// 	int N, C, M, s, e;
// 	scanf("%d %d", &N, &C);
// 	vi h(N);
// 	vector<vi> colors(C+1);
// 	for(int i=0;i<N;i++){
// 		scanf("%d", &h[i]);
// 		colors[h[i]].push_back(i);
// 	}
// 	scanf("%d", &M);
// 	vi sol(M, -1);
// 	for(int i=0;i<M;i++){
// 		int pc=16;
// 		scanf("%d %d", &s, &e);
// 		while(pc-->0){
// 			int ran=s+(rand()%(e-s+1))-1, cnt, a, b;
// 			ran=h[ran];
// 			cnt=upper_bound(colors[ran].begin(), colors[ran].end(), e-1)-lower_bound(colors[ran].begin(), colors[ran].end(), s-1);
// 			if(cnt>(e-s+1)/2){
// 				sol[i]=ran;
// 				break;
// 			}
// 		}
// 	}
// 	for(int i=0;i<M;i++){
// 		if(sol[i]!=-1) printf("yes %d\n", sol[i]);
// 		else printf("no\n");
// 	}
// 	return 0;
// }