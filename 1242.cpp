#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int N, K, M, cnt, t, orgn;
	scanf("%d %d %d", &N, &K, &M);
	orgn=N;
	t=(K%N==0)?N:K%N;
	for(cnt=0;cnt<orgn;cnt++){
		if(t==M) break;
		M=(M>t)?M-t:M-t+N;
		N--;
		t=(K%N==0)?N:K%N;
	}
	printf("%d", cnt+1);
	return 0;
}