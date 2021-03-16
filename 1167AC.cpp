#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long lld;
typedef pair<int, int> pii;

int fmax(int s);

int v, sol=0;
vi tr;
vector<vector<pii>> adj;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>v;
	tr=vi(v, 0);
	adj=vector<vector<pii>>(v);
	for(int i=0;i<v;i++){
		int c, e, w;
		cin>>c>>e;
		c--;
		while(e!=-1){
			cin>>w;
			adj[c].push_back({e-1, w});
			cin>>e;
		}
	}
	fmax(0);
	cout<<sol;
	return 0;
}

int fmax(int s){
	if(tr[s]) return 0;
	tr[s]=1;
	int gt=0, st=0, se=adj[s].size();
	for(int i=0;i<se;i++){
		int nc=adj[s][i].first, nw=adj[s][i].second, t=0;
		if(!tr[nc]) t=fmax(nc)+nw;
		if(t>st){
			if(t>gt){
				st=gt;
				gt=t;
			}
			else st=t;
		}
	}
	if(st+gt>sol) sol=st+gt;
	return gt;
}