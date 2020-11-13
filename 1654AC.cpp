/*
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lld;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	lld n, k, p=0;
	cin>>k>>n;
	vi l(k);
	for(int i=0;i<k;i++){
		cin>>l[i];
		p+=l[i];
	}
	p/=n;
	lld cnt=0, delta=p/2;
	if(p!=1 && p&1) delta++;
	while(delta>0){
		for(lld i:l) cnt+=i/p;
		if(n>cnt) p-=delta;
		else p+=delta;
		if(delta!=1 && delta&1) delta++;
		delta/=2;
		cnt=0;
	}
	for(lld i:l) cnt+=i/p;
	if(cnt<n) p--;
	cout<<p;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lld;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	lld n, k, cnt=0;
	cin>>k>>n;
	vi li(k);
	for(int i=0;i<k;i++) cin>>li[i];
	lld l=1, r=1<<31-1, m;
	while(l<=r){
		m=(l+r)/2;
		for(lld i:li) cnt+=i/m;
		if(n>cnt) r=m-1;
		else l=m+1;
		cnt=0;
	}
	printf("%d", l-1);
	return 0;
}