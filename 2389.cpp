#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>

using namespace std;
typedef pair<double, double> p;
int n;
vector<p> points;

double dist(p p1, p p2);
p farthest(p p1);
bool error(p p1, p p2);
p update(p p1, p m, double pow);

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		double x, y;
		scanf("%lf %lf", &x, &y);
		points.push_back(make_pair(x, y));
	}
	
	p p0;
	double px=0, py=0;
	for(int i=0;i<n;i++){
		px+=points[i].first;
		py+=points[i].second;
	}
	p0=make_pair(px/(double)n, py/(double)n);
	
	p m=farthest(p0);
	double exp=1, e=5, Err=0.1;
	while(fabs(exp-e)>Err){
		printf("p : (%lf, %lf), m : (%lf, %lf)\n", p0.first, p0.second, m.first, m.second);
		p newp=update(p0, m, exp);
		p newm=farthest(newp);
		if(newm!=m) exp+=1.0;
		else p0=newp;
	}
	double rad=sqrt(dist(p0, m));
	// if(p.first-(int)p.first<0.001){
	// 	if(fabs(p.second, 0.0)<0.001){
	// 		if(fabs(rad, 0.))
	// 		printf("%d %d %lf", )
	// }
	printf("%lf %lf %lf", p0.first, p0.second, rad);
	return 0;
}

p update(p p1, p m, double exp){
	double dx=(m.first-p1.first)/pow((double)10, exp);
	double dy=(m.second-p1.second)/pow((double)10, exp);
	return make_pair(p1.first+dx, p1.second+dy);
}

double dist(p p1, p p2){
	double dx=p1.first-p2.first, dy=p1.second-p2.second;
	return dx*dx+dy*dy;
}

p farthest(p p1){
	double d0=-1;
	p ret;
	for(int i=0;i<n;i++){
		double curd=dist(p1, points[i]);
		if(curd>d0) ret=points[i];
	}
	return ret;
}

bool error(p p1, p p2){
	double dx=p1.first-p2.first, dy=p1.second-p2.second;
	dx=fabs(dx), dy=fabs(dy);
	if(dx<0.001 && dy<0.001) return false;
	return true;
}