#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> d(n, vector<int>(10, 1));
	d[0][0]=0;
	for(int i=1;i<n;i++){
		d[i][0]=d[i-1][1];
		d[i][9]=d[i-1][8];
		for(int j=1;j<9;j++) d[i][j]=(d[i-1][j-1]+d[i-1][j+1])%(int)1e9;
	}
	int s=0;
	for(int i=0;i<10;i++) s=(s+d[n-1][i])%(int)1e9;
	printf("%d", s);
	return 0;
}