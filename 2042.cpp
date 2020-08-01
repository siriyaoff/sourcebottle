#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<long long> vtl;

long long init(vtl& num, vtl& st, int tidx, int s, int e);
long long findsum(vtl& st, int tidx, int s, int e, int fl, int fr);
void update(vtl& st, int tidx, int s, int e, int nidx, long long diff);

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<long long> num(N);
	for(int i=0;i<N;i++) scanf("%lld", &num[i]);
	
	int h=0;
	for(int i=1;i<N;i*=2, h++);
	vector<long long> st(pow(2, h+1), 0);
	init(num, st, 1, 0, N-1);
	
	int cnt=M+K;
	while(cnt>0){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		b--;
		if(a==1){
			long long diff=c-num[b];
			num[b]=c;
			update(st, 1, 0, N-1, b, diff);
		}
		else printf("%lld\n", findsum(st, 1, 0, N-1, b, c-1));
		cnt--;
	}
	return 0;
}

long long init(vtl& num, vtl& st, int tidx, int s, int e){
	if(s==e) return st[tidx]=num[s];
	else
		return st[tidx]=init(num, st, tidx*2, s, (s+e)/2)+init(num, st, tidx*2+1, (s+e)/2+1, e);
}

long long findsum(vtl& st, int tidx, int s, int e, int fl, int fr){
	if(fl>e || fr<s) return 0;
	if(fl<=s && e<=fr) return st[tidx];
	return findsum(st, tidx*2, s, (s+e)/2, fl, fr)+findsum(st, tidx*2+1, (s+e)/2+1, e, fl, fr);
}

void update(vtl& st, int tidx, int s, int e, int nidx, long long diff){
	if(nidx<s || nidx>e) return ;
	st[tidx]+=diff;
	if(s!=e){
		update(st, tidx*2, s, (s+e)/2, nidx, diff);
		update(st, tidx*2+1, (s+e)/2+1, e, nidx, diff);
	}
}