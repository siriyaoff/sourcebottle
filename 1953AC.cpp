#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s=0;
	cin>>n;
	vi un(n, -1), b, w;
	vector<vi> ar(n, vi(0));
	for(int i=0;i<n;i++){
		int c, t;
		vi a;
		cin>>c;
		for(int j=0;j<c;j++){
			cin>>t;
			ar[i].push_back(t-1);
			ar[t-1].push_back(i);
		}
	}

	un[0]=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=0;i<ar[cur].size();i++){
			int adj=ar[cur][i];
			if(un[adj]==-1){
				un[adj]=!(un[cur]);
				q.push(adj);
			}
		}
		if(q.empty()){
			for(int i=0;i<n;i++){
				if(un[i]==-1 && ar[i].size()){
					q.push(i);
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(un[i]==0) b.push_back(i);
		else w.push_back(i);
	}
	if(w.size()==0){
		w.push_back(b.back());
		b.pop_back();
	}
	cout<<b.size()<<'\n';
	for(int i=0;i<b.size();i++) cout<<b[i]+1<<' ';
	if(b.size()) cout<<'\n';
	cout<<w.size()<<'\n';
	for(int i=0;i<w.size();i++) cout<<w[i]+1<<' ';
	return 0;
}