#include<iostream>
#include<vector>
#include<string>
#include<stack>
#define IN '1'
#define OUT '0'

using namespace std;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	lld cnt=0;
	string ss;
	cin>>n;
	cin>>ss;
	vi ovis(n, 0);
	vector<vi> adj(n, vi(0));
	for(int i=0;i<n-1;i++){
		int s, e;
		cin>>s>>e;
		adj[--s].push_back(--e);
		adj[e].push_back(s);
	}
	for(int i=0;i<n;i++){
		if(ss[i]==IN) continue;
		if(ovis[i]) continue;
		int tcnt=0;
		vi vis(n, 0);
		stack<int> st;
		ovis[i]=1;
		st.push(i);
		while(!st.empty()){
			int cur=st.top(), f=0;
			vis[cur]=1;
			for(int i=0;i<adj[cur].size();i++){
				int adjv=adj[cur][i];
				if(vis[adjv]==0){
					if(ss[adjv]==IN){
						tcnt++;
						vis[adjv]=1;
					}
					else{
						st.push(adjv);
						ovis[adjv]=1;
						f=1;
						break;
					}
				}
			}
			if(f) continue;
			else st.pop();
		}
		cnt+=tcnt*(tcnt-1);
	}
	for(int i=0;i<n;i++){
		if(ss[i]==OUT) continue;
		for(int j=0;j<adj[i].size();j++){
			if(ss[adj[i][j]]==IN) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}