#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		vector<int> d(n+1);
		d[0]=0, d[1]=1, d[2]=2, d[3]=4;
		for(int i=4;i<=n;i++) d[i]=d[i-1]+d[i-2]+d[i-3];
		printf("%d\n", d[n]);
	}
	return 0;
}