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
	int n;
	cin>>n;
	vi s(n, 0), usd(n+1, 0), res(n, 0);
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		if(usd[s[i]]!=0){
			res[i]=usd[s[i]];
		}
		else if(s[i]==1){
			res[i]=1;
		}
		else{
			if(usd[s[i]-1])	res[i]=s[i];
			else res[i]=s[i]-1;
		}
		usd[res[i]]=s[i];
		usd[s[i]]=res[i];
	}
	for(int i=0;i<n;i++) cout<<res[i]<<'\n';
	return 0;
}