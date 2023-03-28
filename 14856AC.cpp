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
	lld n, curtop=1;
	cin>>n;
	vector<lld> fi, ans;
	fi.push_back(1);
	fi.push_back(2);
	while(fi[curtop]<1000000000000000000){
		fi.push_back(fi[curtop]+fi[curtop-1]);
		curtop++;
	}
	if(fi[lower_bound(fi.begin(), fi.end(), n)-fi.begin()]==n){
		cout<<1<<'\n'<<n;
		return 0;
	}
	while(n>0){
		curtop=upper_bound(fi.begin(), fi.end(), n)-fi.begin();
		ans.push_back(fi[curtop-1]);
		n-=fi[curtop-1];
	}
	vector<lld> cpy(ans.begin(), ans.end());
	cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());
	if(cpy.size()!=ans.size()){
		cout<<-1;
		return 0;
	}
	cout<<ans.size()<<'\n';
	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<' ';
	return 0;
}