#include<cstdio>
#include<cstdlib>
#include<vector>
#include<utility>
#include<time.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;

int main()
{
	srand(time(NULL));
	int N, C, M, s, e;
	scanf("%d %d", &N, &C);
	vi h(N);
	vector<vi> colors(C+1);
	for(int i=0;i<N;i++){
		scanf("%d", &h[i]);
		colors[h[i]].push_back(i);
	}
	scanf("%d", &M);
	vi sol(M, -1);
	for(int i=0;i<M;i++){
		int pc=30;
		scanf("%d %d", &s, &e);
		while(pc-->0){
			int ran=s+(rand()%(e-s+1))-1, cnt, a, b;
			ran=h[ran];
			cnt=upper_bound(colors[ran].begin(), colors[ran].end(), e-1)-lower_bound(colors[ran].begin(), colors[ran].end(), s-1);
			if(cnt>(e-s+1)/2){
				sol[i]=ran;
				break;
			}
		}
	}
	for(int i=0;i<M;i++){
		if(sol[i]!=-1) printf("yes %d\n", sol[i]);
		else printf("no\n");
	}
	return 0;
}