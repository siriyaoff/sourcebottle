#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	printf("%d", a[k-1]);
}