#include<cstdio>
using namespace std;
typedef long long int lld;
lld div(lld n, lld d);

int main()
{
	lld m, n, res2, res5;
	scanf("%lld %lld", &n, &m);
	res2=div(n, 2)-div(n-m, 2)-div(m, 2);
	res5=div(n, 5)-div(n-m, 5)-div(m, 5);
	printf("%lld", (res2>res5)?res5:res2);
}

lld div(lld n, lld d){
	lld r=0;
	for(lld i=d;i<=n;i*=d) r+=n/i;
	return r;
}