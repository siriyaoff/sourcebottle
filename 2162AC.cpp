#include<iostream>
#include<vector>
#include<utility>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;
typedef vector<int> vi;

int getp(vi& g, int a) {
	if(g[a]==a) return a;
	return g[a]=getp(g, g[a]);
}

int setp(vi& g, int a, int b) {
	a=getp(g, a);
	b=getp(g, b);
	if(a>b) {
		g[a]=b;
		return b;
	}
	else {
		g[b]=a;
		return a;
	}
}

int chkp(vi& g, int a, int b) {
	return getp(g, a) == getp(g, b);
}

int apart(int a, int b, int c, int d) {
	int min1, min2, max1, max2;
	if(a>b) min1=b,max1=a;
	else min1=a,max1=b;
	if(c>d) min2=d,max2=c;
	else min2=c,max2=d;
	
	return max1<min2 || max2<min1;
}

long long ccw(pii a, pii b, pii c) {
	return a.x*b.y+b.x*c.y+c.x*a.y-(a.y*b.x+b.y*c.x+c.y*a.x);
}

int inter(line a1, line a2) {
	long long c1=ccw(a1.x, a1.y, a2.x)*ccw(a1.x, a1.y, a2.y), c2=ccw(a2.x, a2.y, a1.x)*ccw(a2.x, a2.y, a1.y);
	if(c1>0 || c2>0) return 0;
	if(c1==0 && c2==0) {
		if(a1.x.x==a1.y.x) return !apart(a1.x.y, a1.y.y, a2.x.y, a2.y.y);
		else return !apart(a1.x.x, a1.y.x, a2.x.x, a2.y.x);
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vi g(n);
	vector<line> va(n);
	for(int i=0;i<n;i++) {
		g[i]=i;
		cin>>va[i].x.x>>va[i].x.y>>va[i].y.x>>va[i].y.y;
		for(int j=0;j<i;j++) {
			if(inter(va[i], va[j])) {
				if(!chkp(g, i, j)) setp(g, i, j);
			}
		}
	}
	
	int m=0, cnt=0;
	vi dset(n, 0);
	for(int i=0;i<n;i++) dset[getp(g, i)]++;
	for(int i=0;i<n;i++) {
		if(dset[i]) cnt++;
		if(m<dset[i]) m=dset[i];
	}
	cout<<cnt<<'\n'<<m;
	return 0;
}