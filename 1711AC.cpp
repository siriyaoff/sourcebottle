#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long int lld;
typedef pair<lld, lld> p;
int solve(p a, p b, p c);
int ortho(p v1, p v2){
	if(v1.first*v2.first+v1.second*v2.second==0)
		return 1;
	else return 0;
}
int main()
{
	int n;
	vector<p> points;
	scanf("%d", &n);
	for(int i=0, x, y;i<n;i++){
		scanf("%d %d", &x, &y);
		points.push_back(make_pair(x, y));
	}
	
	int cnt=0;
	for(int i=0;i<n-2;i++) for(int j=i+1;j<n-1;j++) for(int k=j+1;k<n;k++)
		cnt+=solve(points[i], points[j], points[k]);
	printf("%d", cnt);
	return 0;
}

int solve(p a, p b, p c){
	p ab, ac, bc;
	ab=make_pair(b.first-a.first, b.second-a.second);
	ac=make_pair(c.first-a.first, c.second-a.second);
	bc=make_pair(b.first-c.first, b.second-c.second);
	if(ortho(ab, ac) || ortho(ab, bc) || ortho(ac, bc)) 
		return 1;
	else return 0;
}