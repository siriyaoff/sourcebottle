// #include<bits/stdc++.h>
// #define F first
// #define S second
// using namespace std;
// typedef vector<int> vi;

// int n, s, aidx, bidx, ar[40];
// long long int cnt;
// vi a, b, ra, rb;

// void f(vi& cv, vi& sv, int ci, int cs){
// 	if(ci==cv.size()){
// 		sv.push_back(cs);
// 		return;
// 	}
// 	f(cv, sv, ci+1, cs+cv[ci]);
// 	f(cv, sv, ci+1, cs);
// }

// int main()
// {
// 	cin>>n>>s;
// 	for(int i=0;i<n;i++) cin>>ar[i];
// 	for(int i=0;i<n/2;i++) a.push_back(ar[i]);
// 	for(int i=n/2;i<n;i++) b.push_back(ar[i]);
// 	f(a, ra, 0, 0);
// 	f(b, rb, 0, 0);
// 	sort(rb.begin(), rb.end());
// 	for(int i=0;i<ra.size();i++){
// 		vi::iterator iter=lower_bound(rb.begin(), rb.end(), s-ra[i]);
// 		int sz=upper_bound(rb.begin(), rb.end(), s-ra[i])-iter;
// 		if(iter==rb.end()) continue;
// 		if(*iter==s-ra[i]) cnt+=sz;
// 	}
// 	cout<<cnt-(s==0);
// }

#include<bits/stdc++.h>
using namespace std;

int n, s, ar[40], ps[4000001];
long long cnt;

void f(int ci, int cs, bool chose){
	if(ci==n/2){
		if(chose==0) return;
		if(s==cs) cnt++;
		ps[cs+2000000]++;
		return;
	}
	f(ci+1, cs+ar[ci], 1);
	f(ci+1, cs, chose);
}
void g(int ci, int cs, bool chose){
	if(ci==n){
		if(chose==0) return;
		if(s==cs) cnt++;
		if(s-cs>2000000 || s-cs<-2000000) return;
		cnt+=ps[s-cs+2000000];
		return;
	}
	g(ci+1, cs+ar[ci], 1);
	g(ci+1, cs, chose);
}

int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>ar[i];
	
	f(0, 0, 0);
	g(n/2, 0, 0);
	cout<<cnt;
}