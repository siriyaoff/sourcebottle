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
	lld n, l, c, s, r;
	cin>>n>>l>>c;
	if(c==l){
		cout<<n;
		return 0;
	}
	s=c/(l+1);
	if(c==((l+1)*s+l)) s++;
	if(s%13==0) s--;// song per cd
	if(n<s){
		if(n%13) cout<<1;
		else cout<<2;
		return 0;
	}
	r=n%s;
	if(r==0) cout<<n/s;
	else{
		if(r%13==0){
			if(s==r+1) cout<<n/s+2;
			else{// r에 1개 이상 추가 가능
				if(s==r+2 && s%13==1) cout<<n/s+2;
				else cout<<n/s+1;
			}
		}
		else cout<<n/s+1;
	}
	return 0;
}