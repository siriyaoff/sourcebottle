// // closest, 88ms
// #include<bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int, int> pii;

// int mid(int s, int e){return (s+e)>>1;}
// int dist(pii a, pii b){
// 	return pow(a.first-b.first, 2)+pow(a.second-b.second, 2);
// 	// return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
// }
// bool comparey(pii a, pii b);
// int paramsearch(vector<pii>& p, int l, int r, int piv, int d, int ord);
// int closest(vector<pii>& p, int s, int e);

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	int n;
// 	cin>>n;
// 	vector<pii> p(n);
// 	for(auto& i:p){
// 		int x, y;
// 		cin>>x>>y;
// 		i={x, y};
// 	}
// 	sort(p.begin(), p.end());
// 	cout<<closest(p, 0, n-1);
// }

// bool comparey(pii a, pii b){
// 	if(a.second==b.second) return a.first<b.first;
// 	return a.second<b.second;
// }

// int paramsearch(vector<pii>& p, int l, int r, int piv, int d, int ord){//1:left, 0:right
// 	while(l<=r){
// 		int m=mid(l, r), md;
// 		md=p[m].first-p[piv].first;
// 		md*=md;
// 		if(md>d){
// 			if(ord) l=m+1;
// 			else r=m-1;
// 		}
// 		else{
// 			if(ord) r=m-1;
// 			else l=m+1;
// 		}
// 	}
// 	return l-1;
// }

// int closest(vector<pii>& p, int s, int e){
// 	if(s==e) return 800000001;
// 	if(e-s==1) return dist(p[s], p[e]);
	
// 	int d1, d2, d=800000001;
// 	d1=closest(p, s, mid(s, e));
// 	d2=closest(p, mid(s, e)+1, e);
// 	if(d1<d2) d=d1;
// 	else d=d2;
	
// 	d1=paramsearch(p, s, mid(s, e)-1, mid(s, e), d, 1);
// 	d2=paramsearch(p, mid(s, e)+1, e, mid(s, e), d, 0);
// 	if(d1==s-1) d1++;
// 	vector<pii> ind;
// 	for(int i=d1;i<=d2;i++) ind.push_back(p[i]);
// 	sort(ind.begin(), ind.end(), comparey);
	
// 	for(int i=0;i<ind.size()-1;i++) for(int j=i+1;j<ind.size();j++){
// 		int ydiff=ind[j].second-ind[i].second;
// 		ydiff*=ydiff;
// 		if(ydiff>=d) break;
// 		ydiff=dist(ind[i], ind[j]);
// 		if(ydiff<d) d=ydiff;
// 	}
// 	return d;
// }

// closesty, 108ms
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

int mid(int s, int e){return (s+e)>>1;}
int dist(pii a, pii b){return pow(a.first-b.first, 2)+pow(a.second-b.second, 2);}
bool comparey(pii a, pii b);
int paramsearch(vector<pii>& p, int l, int r, int piv, int d, int ord);
int closest(vector<pii>& p, int s, int e);
int closesty(vector<pii>& ind, int s, int e);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pii> p(n);
	for(auto& i:p){
		int x, y;
		cin>>x>>y;
		i={x, y};
	}
	sort(p.begin(), p.end());
	cout<<closest(p, 0, n-1);
}

bool comparey(pii a, pii b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

int paramsearch(vector<pii>& p, int l, int r, int piv, int d, int ord, int xy){//1:left, 0:right
	while(l<=r){
		int m=mid(l, r), md;
		if(xy) md=p[m].first-p[piv].first;
		else md=p[m].second-p[piv].second;
		md*=md;
		if(md>d){
			if(ord) l=m+1;
			else r=m-1;
		}
		else{
			if(ord) r=m-1;
			else l=m+1;
		}
	}
	return l-1;
}

int closest(vector<pii>& p, int s, int e){
	if(s==e) return 800000001;
	if(e-s==1) return dist(p[s], p[e]);
	
	int d1, d2, d;
	d1=closest(p, s, mid(s, e));
	d2=closest(p, mid(s, e)+1, e);
	if(d1<d2) d=d1;
	else d=d2;
	
	d1=paramsearch(p, s, mid(s, e)-1, mid(s, e), d, 1, 1);
	d2=paramsearch(p, mid(s, e)+1, e, mid(s, e), d, 0, 1);
	if(d1==s-1) d1++;
	vector<pii> ind;
	for(int i=d1;i<=d2;i++) ind.push_back(p[i]);
	sort(ind.begin(), ind.end(), comparey);
	if(ind.size()<4){
		for(int i=0;i<ind.size()-1;i++) for(int j=i+1;j<ind.size();j++){
			int ydiff=ind[j].second-ind[i].second;
			ydiff*=ydiff;
			if(ydiff>=d) break;
			ydiff=dist(ind[i], ind[j]);
			if(ydiff<d) d=ydiff;
		}
		return d;
	}
	else{
		int yd=closesty(ind, 0, ind.size()-1);
		if(yd<d) return yd;
		else return d;
	}
}

int closesty(vector<pii>& ind, int s, int e){
	if(s==e) return 800000001;
	if(e-s==1) return dist(ind[s], ind[e]);
	
	int d1, d2, d;
	d1=closesty(ind, s, mid(s, e));
	d2=closesty(ind, mid(s, e)+1, e);
	if(d1<d2) d=d1;
	else d=d2;
	if(d==0) return 0;
	d1=paramsearch(ind, s, mid(s, e)-1, mid(s, e), d, 1, 0);
	d2=paramsearch(ind, mid(s, e)+1, e, mid(s, e), d, 0, 0);
	if(d1==s-1) d1++;
	for(int i=d1;i<d2;i++) for(int j=i+1;j<=d2;j++){
		if(d<(ind[j].first-ind[i].first)*(ind[j].first-ind[i].first)) break;
		int xd=dist(ind[i], ind[j]);
		if(xd<d) d=xd;
	}
	return d;
}