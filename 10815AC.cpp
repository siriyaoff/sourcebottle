#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef struct coord{
	double x;
	double y;
} Coord;
Coord A, B, C, D;

double d(double t){
	double ax=D.x-C.x-B.x+A.x, ay=D.y-C.y-B.y+A.y;
	return pow(ax*t+C.x-A.x, 2)+pow(ay*t+C.y-A.y, 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed;
	cout.precision(10);
	cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;
	double lo=0.0, hi=1.0, p=(lo*2.0+hi)/3.0, q=(lo+hi*2.0)/3.0;
	while(fabs(p-q)>1e-8){
		p=(lo*2.0+hi)/3.0;
		q=(lo+hi*2.0)/3.0;
		if(d(p)<d(q)) hi=q;
		else lo=p;
	}
	cout<<sqrt(d(q));
}