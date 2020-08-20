#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	long long maxc=0, maxn=0, curc, curn;
	scanf("%d", &n);
	vector<long long> a(n);
	for(int i=0;i<n;i++) scanf("%lld", &a[i]);
	sort(a.begin(), a.end());
	curc=0, curn=a[0];
	for(int i=0;i<n;i++){
		if(curn!=a[i]){
			if(maxc<curc){
				maxc=curc;
				maxn=curn;
			}
			curn=a[i];
			curc=1;
		}
		else curc++;
	}
	if(maxc<curc) maxn=curn;
	printf("%lld", maxn);
}