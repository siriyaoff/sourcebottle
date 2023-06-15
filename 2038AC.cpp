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
	int n, filled, i;
	vi a(4000000, 0);
	cin>>n;
	i=1;
	a[1]=1;
	filled=1;
	while(filled<n){
		i++;
		a[i]=1+a[i-a[a[i-1]]];
		filled+=a[i];
	}
	cout<<i;
	return 0;
}