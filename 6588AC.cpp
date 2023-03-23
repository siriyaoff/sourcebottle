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
	int n, p, plen;
	vi era(1000001, 1), primes;
	for(int i=2;i<1001;i++){
		if(era[i]){
			for(int j=i+i;j<1000001;j+=i){
				era[j]=0;
			}
		}
	}
	for(int i=2;i<1000001;i++){
		if(era[i]) primes.push_back(i);
	}
	plen=primes.size()/2+1;
	cin>>n;
	while(n){
		int f=1;
		for(int i=0;i<plen;i++){
			p=primes[lower_bound(primes.begin(), primes.end(), n-primes[i])-primes.begin()];
			if(p==n-primes[i]){
				cout<<n<<" = "<<primes[i]<<" + "<<p<<"\n";
				f=0;
				break;
			}
		}
		if(f) cout<<"Goldbach's conjecture is wrong.\n";
		cin>>n;
	}
	return 0;
}