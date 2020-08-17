#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	vector<vector<int>> s(3, vector<int>(n, 0));
	for(int i=0;i<n;i++) scanf("%d", &v[i]);
	s[0][0]=s[2][0]=v[0];
	for(int i=1;i<n;i++){
		s[0][i]=s[1][i-1]+v[i];
		s[1][i]=max(s[0][i-1], s[2][i-1]);
		s[2][i]=s[0][i-1]+v[i];
	}
	printf("%d", max(s[0][n-1], s[2][n-1]));
	return 0;
}