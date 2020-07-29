#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<long long> vtl;

long long init(vtl& num, vtl& st, int cur, int s, int e);
long long findsum(vtl& st, int cur, int s, int e, int fl, int fr);
void update(vtl& st, int cur, int s, int e, int cindx, long long diff);

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<long long> num;
	for(int i=0;i<N;i++){
		long long t;
		scanf("%lld", &t);
		num.push_back(t);
	}
	
	int h=0, size;
	for(int i=1;i<N;i*=2, h++);
	vector<long long> st(size=pow(2, h+1)-1, 0);
	init(num, st, 0, 0, size-1);
	
	int cnt=M+K;
	while(cnt>0){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a==1) update(st, 0, 0, size-1, b, c-num[b-1]);
		else printf("%lld\n", findsum(st, 0, 0, size-1, b, c));
		cnt--;
	}
	return 0;
}

long long init(vtl& num, vtl& st, int cur, int s, int e){
	if(s==e)
		return st[cur]=num[s];
	else
		return st[cur]=init(num, st, cur*2, s, (s+e)/2)+init(num, st, cur*2+1, (s+e)/2+1, e);
}

long long findsum(vtl& st, int cur, int s, int e, int fl, int fr){
	if(fl>e || fr<s) return 0;
	if(fl<=s && e<=fr) return st[cur];
	return findsum(st, cur*2, s, (s+e)/2, fl, fr)+findsum(st, cur*2+1, (s+e)/2+1, e, fl, fr);
}

void update(vtl& st, int cur, int s, int e, int cindx, long long diff){
	if(cindx<s || cindx>e) return ;
	st[cur]+=diff;
	if(s!=e){
		update(st, cur*2, s, (s+e)/2, cindx, diff);
		update(st, cur*2+1, (s+e)/2+1, e, cindx, diff);
	}
}