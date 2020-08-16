#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> d(n, vector<int>(10, 0));
	for(int i=0;i<10;i++) d[0][i]=1;
	for(int i=1;i<n;i++){
		d[i][0]=d[i-1][0];
		for(int j=1;j<10;j++) for(int k=0;k<=j;k++) d[i][j]=(d[i][j]+d[i-1][k])%10007;
	}
	int s=0;
	for(int i=0;i<10;i++) s=(s+d[n-1][i])%10007;
	printf("%d", s);
	return 0;
}