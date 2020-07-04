#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> point;

int n;
vector<point> points;

bool compare(point a, point b){
	return a.first<=b.first;
}
int dist(int a, int b){
	if(a==b)
		return 987654321;
	else
		return (points[a].first-points[b].first)*(points[a].first-points[b].first)+(points[a].second-points[b].second)*(points[a].second-points[b].second);
}
int closest(int s, int e);

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		points.push_back(make_pair(x, y));
	}
	sort(points.begin(), points.end(), compare);
	
	printf("%d", closest(0, n-1));
	return 0;
}

int closest(int s, int e){
	if(s>e)
		return 987654321;
	if(s+1==e)
		return dist(s, e);
	int mid=(s+e)/2, l, r, d;//l, r : mindist from l, r
	l=closest(s, mid);
	r=closest(mid, e);
	d=(l<r)?l:r;
	l=s;
	r=e;
	for(int i=mid-1;i>=0;i--)
		if(dist(i, mid)>d)
			break;
	if(--l<0) l=0;
	for(int i=mid+1;i<n;i++)
		if(dist(mid, i)>d)
			break;
	if(++r==n) r=n-1;
	for(int i=l;i<r;i++){
		for(int j=i+1;j<r+1;j++){
			if(dist(i, j)<d)
				d=dist(i, j);
		}
	}
	return d;
}