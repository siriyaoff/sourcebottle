#include<cstdio>
int main()
{
	long long p[100];
	int t, n;
	p[0]=p[1]=p[2]=1, p[3]=p[4]=2;
	for(int i=5;i<100;i++) p[i]=p[i-1]+p[i-5];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", p[n-1]);
	}
}