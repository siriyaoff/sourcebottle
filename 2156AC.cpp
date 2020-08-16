#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	vector<vector<int>> w(4, vector<int>(n, 0));
	for(int i=0;i<n;i++) scanf("%d", &v[i]);
	if(n<3){
		int s=0;
		for(int i=0;i<n;i++) s+=v[i];
		printf("%d", s);
		return 0;
	}
	w[1][0]=w[3][0]=v[0];
	for(int i=1;i<n;i++){
		w[0][i]=max(w[0][i-1], w[2][i-1]);
		w[1][i]=max(w[0][i-1], w[2][i-1])+v[i];
		w[2][i]=max(w[1][i-1], w[3][i-1]);
		w[3][i]=w[1][i-1]+v[i];
	}
	int s=-1;
	for(int i=0;i<4;i++) s=(s<w[i][n-1])?w[i][n-1]:s;
	printf("%d", s);
	return 0;
}