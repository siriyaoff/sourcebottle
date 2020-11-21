#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin>>t;
	vector<int> a(11);
	a[0]=1,	a[1]=2,	a[2]=4;
	for(int i=3;i<11;i++) a[i]=a[i-1]+a[i-2]+a[i-3];
	while(t--){
		cin>>n;
		cout<<a[n-1]<<"\n";
	}
}
// #include<cstdio>
// #include<vector>
// using namespace std;

// int main()
// {
// 	int T, n;
// 	scanf("%d", &T);
// 	while(T--){
// 		scanf("%d", &n);
// 		vector<int> d(n+1);
// 		d[0]=0, d[1]=1, d[2]=2, d[3]=4;
// 		for(int i=4;i<=n;i++) d[i]=d[i-1]+d[i-2]+d[i-3];
// 		printf("%d\n", d[n]);
// 	}
// 	return 0;
// }