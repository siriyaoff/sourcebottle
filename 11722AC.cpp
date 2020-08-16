#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, idx=0;
	scanf("%d", &n);
	vector<int> a(n), lis(n, 9999);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	reverse(a.begin(), a.end());
	lis[idx++]=a[0];
	for(int i=1;i<n;i++){
		int cidx=lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
		if(a[i]<lis[cidx]){
			if(lis[cidx]==9999) idx++;
			lis[cidx]=a[i];
		}
	}
	printf("%d", idx);
	return 0;
}