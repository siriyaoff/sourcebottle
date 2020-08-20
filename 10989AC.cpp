#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> a(10000, 0);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		a[--t]++;
	}
	for(int i=0;i<10000;i++) for(int j=0;j<a[i];j++) printf("%d\n", i+1);
}