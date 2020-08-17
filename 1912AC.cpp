#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n), p(n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	p[0]=a[0];
	for(int i=1;i<n;i++){
		if(p[i-1]<0) p[i]=a[i];
		else p[i]=p[i-1]+a[i];
	}
	sort(p.begin(), p.end());
	printf("%d", p[p.size()-1]);
	return 0;
}