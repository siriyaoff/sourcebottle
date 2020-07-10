#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;

int n;
vector<p> ps;

int closest(int s, int e);

bool comparex(p a, p b){
	return a.first<b.first;
}

bool comparey(p a, p b){
	return a.second<b.second;
}

int dist(p a, p b){
	int x=a.first-b.first, y=a.second-b.second;
	return x*x+y*y;
}

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		ps.push_back(make_pair(x, y));
	}
	sort(ps.begin(), ps.end(), comparex);
	
	printf("%d", closest(0, n-1));
	return 0;
}

int closest(int s, int e){
	if(s+1==e)
		return dist(ps[s], ps[e]);
	int mid=(s+e)/2, ldist=987654321, rdist=987654321, curd;
	if(s<mid) ldist=closest(s, mid);
	if(mid+1<e) rdist=closest(mid+1, e);
	curd=(ldist<rdist)?ldist:rdist;
	
	vector<p> indAsx;
	for(int i=s;i<=e;i++){
		if(mid==i)
			continue;
		int xdist=ps[mid].first-ps[i].first;
		xdist*=xdist;
		if(xdist<curd) indAsx.push_back(ps[i]);
	}
	indAsx.push_back(ps[mid]);
	if(indAsx.empty())
		return curd;
	
	sort(indAsx.begin(), indAsx.end(), comparey);
	vector<p> ind;
	for(int i=0;i<indAsx.size()-1;i++){
		for(int j=i+1;j<indAsx.size();j++){
			int ydist=indAsx[i].second-indAsx[j].second;
			ydist*=ydist;
			if(ydist>=curd)
				break;
			if(dist(indAsx[i], indAsx[j])<curd)
				curd=dist(indAsx[i], indAsx[j]);
		}
	}
	return curd;
}