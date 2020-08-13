#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	int N, len=0;
	scanf("%d", &N);
	vector<pii> pts(N);
	for(int i=0;i<N;i++){
		scanf("%d %d", &pts[i].first, &pts[i].second);
		if(pts[i].first>pts[i].second) swap(pts[i].first, pts[i].second);
	}
	sort(pts.begin(), pts.end());
	int s=pts[0].first, e, cur, nexts, max;
	cur=upper_bound(pts.begin(), pts.end(), make_pair(s, (int)1e9))-pts.begin();
	max=pts[cur-1].second;
	while(1){
		e=pts[cur-1].second;
		if(max<e) max=e;
		if(cur==N){
			len+=max-s;
			break;
		}
		
		nexts=pts[cur].first;
		if(nexts>max){
			len+=max-s;
			s=nexts;
		}
		cur=upper_bound(pts.begin(), pts.end(), make_pair(nexts, (int)1e9))-pts.begin();
	}
	printf("%d", len);
	return 0;
}