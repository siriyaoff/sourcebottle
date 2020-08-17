#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	int n;
	scanf("%d", &n);
	vector<pii> p(n);
	for(int i=0;i<n;i++) scanf("%d %d", &p[i].second, &p[i].first);
	sort(p.begin(), p.end());
	for(int i=0;i<n;i++) printf("%d %d\n", p[i].second, p[i].first);
}