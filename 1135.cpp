#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
using pii=pair<int, int>;
using vi=vector<int>;
using lld=long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin>>n;
	vi dp(n, 0), per(n, 0);
	vector<vector<pii> > al(n, vector<pii>(0));
	for(int i=0;i<n;i++){
		cin>>t;
		if(t==-1) continue;
		al[t].push_back({0, i});
	}
	for(int i=n-1;i>-1;i--){
		if(al[i].size()==0){
			dp[i]=0;
			continue;
		}
		int m=0, cnt=0;
		for(int j=0;j<al[i].size();j++){
			if(m<dp[al[i][j].second]){
				m=dp[al[i][j].second];
				cnt=1;
			}
			else if(m==dp[al[i][j].second]) cnt++;
		}
		if(m+cnt>al[i].size()) dp[i]=m+cnt;
		else dp[i]=al[i].size();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<al[i].size();j++){
			al[i][j].first=dp[al[i][j].second];
		}
		sort(al[i].begin(), al[i].end());
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<al[i].size();j++){
			per[al[i][j].second]=al[i].size()-j;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<al[i].size();j++){
			per[al[i][j].second]+=per[i];
		}
	}
	/*
	for(int i=0;i<n;i++) cout<<per[i]<<' ';
	cout<<endl;
	*/
	t=0;
	for(int i=0;i<n;i++) if(t<per[i]) t=per[i];
	if(n==1) cout<<0;
	else cout<<t;
	return 0;
}