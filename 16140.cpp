#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long int lld;
typedef pair<lld, lld> gau;

struct lexico{
	bool operator()(gau g1, gau g2){
		if(g1.first==g2.first) return g1.second<g2.second;
		return g1.first<g2.first;
	}
}lexico;

vector<gau> gcdcom(gau g1, gau g2);
lld norm(gau g);
lld round(lld t, lld over);

int main()
{
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		lld a, b, c, d;
		gau g1, g2;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		g1=make_pair(a, b), g2=make_pair(c, d);
		
		vector<gau> res=gcdcom(g1, g2);
		if(!res.empty()) sort(res.begin(), res.end(), lexico);
		printf("%d\n", res.size());
		for(int j=0;j<res.size();j++)
			printf("%lld %lld ", res[j].first, res[j].second);
		printf("\n");
	}
	return 0;
}

vector<gau> gcdcom(gau g1, gau g2){
	vector<gau> res;
	gau n, m=g1, r=g2;
	while(norm(r)!=0){
		n=m;
		m=r;
		lld x, y, div;
		gau q;
		x=n.first*m.first+n.second*m.second;
		y=n.second*m.first-n.first*m.second;
		div=norm(m);
		q=make_pair(round(x, div), round(y, div));
		x=n.first-m.first*q.first+m.second*q.second;
		y=n.second-m.first*q.second-m.second*q.first;
		r=make_pair(x, y);
	}
	res.push_back(m);
	res.push_back(make_pair(-1*m.second, m.first));
	res.push_back(make_pair(-1*m.first, -1*m.second));
	res.push_back(make_pair(m.second, -1*m.first));
	return res;
}

lld norm(gau g){
	lld x=g.first*g.first;
	lld y=g.second*g.second;
	return x+y;
}

lld round(lld t, lld over){
	lld r=t%over, q=t/over;
	if(over<=2*r) q++;
	return q;
}